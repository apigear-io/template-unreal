#include "UnrealOLinkHost.h"
#include "ApiGearSettings.h"
#include "OLinkHostWorker.h"

TSharedPtr<ApiGear::ObjectLink::RemoteRegistry> UUnrealOLinkHost::GetOLinkRegistry()
{
	return Worker ? Worker->GetOLinkRegistry() : nullptr;
}

void UUnrealOLinkHost::Initialize(FSubsystemCollectionBase& Collection)
{
	UApiGearSettings* settings = GetMutableDefault<UApiGearSettings>();
	Worker = MakePimpl<UnrealOLinkHostWorker>(settings->OLINK_Port);
}

void UUnrealOLinkHost::Deinitialize()
{
	if (!Worker)
	{
		return;
	}

	Worker->Stop();
	Worker.Reset();
}

bool UUnrealOLinkHost::Start(int32 Port)
{
	if (!Worker || Port <= 0)
	{
		return false;
	}

	return Worker->Start(Port);
}

void UUnrealOLinkHost::Stop()
{
	if (!Worker)
	{
		return;
	}

	return Worker->Stop();
}
