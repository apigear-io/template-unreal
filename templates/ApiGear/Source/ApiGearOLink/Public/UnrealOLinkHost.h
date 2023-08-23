#pragma once

#include "Subsystems/GameInstanceSubsystem.h"
#include "Templates/PimplPtr.h"
THIRD_PARTY_INCLUDES_START
#include "olink/remotenode.h"
#include "olink/remoteregistry.h"
THIRD_PARTY_INCLUDES_END
#include "UnrealOLinkHost.generated.h"

class OLinkHostPrivate;

/// @brief Hosts a server for OLink services.
/// Stores connections requested by clients and provides connection endpoints (nodes) through the RemoteRegistry
/// May hold multiple connections.
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

	/// @brief starts the OLink server on the given port
	/// @param Port which port the OLink server listen
	/// @return true if started successfully
	UFUNCTION(BlueprintCallable, Category = "ApiGear")
	bool Start(int32 Port);

	/// @brief stops the OLink server
	UFUNCTION(BlueprintCallable, Category = "ApiGear")
	void Stop();

	/// @brief Get RemoteRegistry to add or remove your sources or get nodes that are using your sources
	/// @return RemoteRegistry used by this UUnrealOLinkHost and nodes
	TSharedPtr<ApiGear::ObjectLink::RemoteRegistry> GetOLinkRegistry();

private:
	/// @brief the private implementation of the OLink server
	TPimplPtr<OLinkHostPrivate> PrivateImplementation;
};
