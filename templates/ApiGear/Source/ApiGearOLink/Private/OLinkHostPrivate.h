#pragma once

#include "UnrealOLinkHost.h"
#include "ApiGearSettings.h"
#include "Containers/Ticker.h"
#include "Templates/UniquePtr.h"
#include "Runtime/Launch/Resources/Version.h"
THIRD_PARTY_INCLUDES_START
#include "olink/remoteregistry.h"
#include "olink/remotenode.h"
THIRD_PARTY_INCLUDES_END
#include "OLinkHostConnection.h"
#include "IWebSocketServer.h"

class INetworkingWebSocket;

/// @brief the private implementation of the OLink server
class APIGEAROLINK_API OLinkHostPrivate
{
public:
	explicit OLinkHostPrivate(uint32 InPort);
	virtual ~OLinkHostPrivate();

	/// @brief returns number of currently active connections
	/// @return number of currently active connections
	uint32 NumConnections() const;

	/// @brief starts the OLink server on the mentioned port
	/// @param Port which port the OLink server listen
	/// @return true if started successfully
	bool Start(uint32 Port);
	/// @brief stops the OLink server
	void Stop();

	/// @brief returns the sharedptr to the remote registry
	/// @return sharedptr to the remote registry
	TSharedPtr<ApiGear::ObjectLink::RemoteRegistry> GetOLinkRegistry()
	{
		return Registry;
	};

private:
	/// @brief callback for when server established a new connection
	/// @param Socket pointer to unique socket for each connection
	void OnWebSocketClientConnected(INetworkingWebSocket* Socket);

	/// @brief callback for when the connection was closed
	/// removes the connection from the list of currently active connections
	/// @param Socket pointer to unique socket for each connection
	void OnConnectionClose(FOLinkHostConnection* Connection);

	/// @brief function is called internally by the Coreticker and interacts with the libwebsocket
	/// @param DeltaTime not used
	/// @return always true
	bool Tick(float /** DeltaTime */);

	/// @brief pointer to the websocket wrapper
	TUniquePtr<IWebSocketServer> Server;
	bool m_loggingDisabled;

	// olink registry stored here to hand it olink adapter classes
	TSharedPtr<ApiGear::ObjectLink::RemoteRegistry> Registry;

#if (ENGINE_MAJOR_VERSION >= 5)
	/// @brief delegate which is connected to the tick function
	FTSTicker::FDelegateHandle TickerHandle;
#else
	/// @brief delegate which is connected to the tick function
	FDelegateHandle TickerHandle;
#endif

	/// @brief the port OLink server listen on
	uint32 Port;

	/// @brief holds all currently active connections
	TArray<TUniquePtr<FOLinkHostConnection>> ClientConnections;
};
