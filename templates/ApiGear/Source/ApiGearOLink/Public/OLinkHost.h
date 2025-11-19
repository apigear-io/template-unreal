#pragma once

#include "Subsystems/GameInstanceSubsystem.h"
#include "Templates/SharedPointer.h"
THIRD_PARTY_INCLUDES_START
#include "olink/remotenode.h"
#include "olink/remoteregistry.h"
THIRD_PARTY_INCLUDES_END
#include "OLinkHost.generated.h"

class OLinkHostPrivate;

/// @brief Hosts a server for OLink services.
/// Stores connections requested by clients and provides connection endpoints (nodes) through the RemoteRegistry
/// May hold multiple connections.
UCLASS(BlueprintType)
class APIGEAROLINK_API UOLinkHost
	: public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	explicit UOLinkHost() = default;
	virtual ~UOLinkHost() = default;

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
	/// @return RemoteRegistry used by this UOLinkHost and nodes
	TSharedPtr<ApiGear::ObjectLink::RemoteRegistry> GetOLinkRegistry();

private:
	/// @brief the private implementation of the OLink server
	TSharedPtr<OLinkHostPrivate> PrivateImplementation;
};
