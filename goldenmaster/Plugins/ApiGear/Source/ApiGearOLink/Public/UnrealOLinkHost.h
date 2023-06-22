#pragma once

#include "Subsystems/GameInstanceSubsystem.h"
#include "Templates/PimplPtr.h"
THIRD_PARTY_INCLUDES_START
#include "olink/remotenode.h"
#include "olink/remoteregistry.h"
THIRD_PARTY_INCLUDES_END
#include "UnrealOLinkHost.generated.h"

class UnrealOLinkHostWorker;

/// @brief the public wrapper for the OLink server
UCLASS(BlueprintType)
class APIGEAROLINK_API UUnrealOLinkHost
	: public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	explicit UUnrealOLinkHost() = default;
	virtual ~UUnrealOLinkHost() = default;

	// USubssystem functions
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	/// @brief starts the OLink server on the mentioned port
	/// @param Port which port the OLink server listen
	/// @return true if started successfully
	UFUNCTION(BlueprintCallable, Category = "ApiGear")
	bool Start(int32 Port);

	/// @brief stops the OLink server
	UFUNCTION(BlueprintCallable, Category = "ApiGear")
	void Stop();

	/// @brief returns the sharedptr to the remote registry
	/// @return sharedptr to the remote registry
	TSharedPtr<ApiGear::ObjectLink::RemoteRegistry> GetOLinkRegistry();

private:
	/// @brief pointer to the private implementation of the OLink server
	TPimplPtr<UnrealOLinkHostWorker> Worker;
};
