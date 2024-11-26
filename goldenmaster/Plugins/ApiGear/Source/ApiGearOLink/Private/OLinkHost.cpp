#include "OLinkHost.h"
#include "ApiGearSettings.h"
#include "OLinkHostPrivate.h"
#include "HAL/Platform.h"
#if !(PLATFORM_IOS || PLATFORM_ANDROID)

TSharedPtr<ApiGear::ObjectLink::RemoteRegistry> UOLinkHost::GetOLinkRegistry()
{
	return PrivateImplementation ? PrivateImplementation->GetOLinkRegistry() : nullptr;
}

void UOLinkHost::Initialize(FSubsystemCollectionBase& Collection)
{
	UApiGearSettings* settings = GetMutableDefault<UApiGearSettings>();
	PrivateImplementation = MakePimpl<OLinkHostPrivate>(settings->OLINK_Port);
}

void UOLinkHost::Deinitialize()
{
	if (!PrivateImplementation)
	{
		return;
	}

	PrivateImplementation->Stop();
	PrivateImplementation.Reset();
}

bool UOLinkHost::Start(int32 Port)
{
	if (!PrivateImplementation || Port <= 0)
	{
		return false;
	}

	return PrivateImplementation->Start(Port);
}

void UOLinkHost::Stop()
{
	if (!PrivateImplementation)
	{
		return;
	}

	return PrivateImplementation->Stop();
}
#else  // !(PLATFORM_IOS || PLATFORM_ANDROID)

TSharedPtr<ApiGear::ObjectLink::RemoteRegistry> UOLinkHost::GetOLinkRegistry()
{
	return PrivateImplementation ? PrivateImplementation->GetOLinkRegistry() : nullptr;
}

void UOLinkHost::Initialize(FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogApiGearOLinkHost, Warning, TEXT("OLink server is not supported on Android and iOS"));
}

void UOLinkHost::Deinitialize()
{
}

bool UOLinkHost::Start(int32 Port)
{
	return false;
}

void UOLinkHost::Stop()
{
}
#endif // !(PLATFORM_IOS || PLATFORM_ANDROID)
