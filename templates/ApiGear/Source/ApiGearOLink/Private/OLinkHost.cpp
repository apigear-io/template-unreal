#include "OLinkHost.h"
#include "ApiGearSettings.h"
#include "OLinkHostPrivate.h"

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
