#include "UnrealOLinkHost.h"
#include "ApiGearSettings.h"
#include "OLinkHostPrivate.h"

TSharedPtr<ApiGear::ObjectLink::RemoteRegistry> UUnrealOLinkHost::GetOLinkRegistry()
{
	return PrivateImplementation ? PrivateImplementation->GetOLinkRegistry() : nullptr;
}

void UUnrealOLinkHost::Initialize(FSubsystemCollectionBase& Collection)
{
	UApiGearSettings* settings = GetMutableDefault<UApiGearSettings>();
	PrivateImplementation = MakePimpl<OLinkHostPrivate>(settings->OLINK_Port);
}

void UUnrealOLinkHost::Deinitialize()
{
	if (!PrivateImplementation)
	{
		return;
	}

	PrivateImplementation->Stop();
	PrivateImplementation.Reset();
}

bool UUnrealOLinkHost::Start(int32 Port)
{
	if (!PrivateImplementation || Port <= 0)
	{
		return false;
	}

	return PrivateImplementation->Start(Port);
}

void UUnrealOLinkHost::Stop()
{
	if (!PrivateImplementation)
	{
		return;
	}

	return PrivateImplementation->Stop();
}
