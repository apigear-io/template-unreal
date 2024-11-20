#pragma once

#include "CoreTypes.h"
THIRD_PARTY_INCLUDES_START
#include "olink/remoteregistry.h"
#include "olink/remotenode.h"
THIRD_PARTY_INCLUDES_END
#include <UObject/Object.h>
#include "ApiGearLogCategories.h"

class INetworkingWebSocket;
class FOLinkHostConnection;

DECLARE_DELEGATE_OneParam(FOLinkHostConnectionClosedCallBack, FOLinkHostConnection* /*Connection*/);

/// @brief handles exclusively a connection operated by one WebSocket.
/// Binds data from WebSocket to a RemoteNode which is an OLink network endpoint abstraction
class APIGEAROLINK_API FOLinkHostConnection
{

public:
	/// @brief delegate which is notified for every closed connection
	FOLinkHostConnectionClosedCallBack ConnectionClosedCallBack;

	/// @brief takes ownership of the socket and manages all interactions with it
	/// @param InSocket socket with the connection to the client
	/// @param InRegistry reference to the registry, here only forwarded to the node
	/// @param logFunc function for logging protocol
	FOLinkHostConnection(INetworkingWebSocket* InSocket, ApiGear::ObjectLink::RemoteRegistry& InRegistry, ApiGear::ObjectLink::WriteLogFunc logFunc);
	FOLinkHostConnection(FOLinkHostConnection&& Other);

	~FOLinkHostConnection();

	/// @brief helper function to check the InConnection is actually pointing to the same instance
	/// @param InConnection connection to be tested
	/// @return true if identical
	bool IsConnection(FOLinkHostConnection* InConnection) const;

private:
	/// @brief callback for received data packets - for now we assume it is text data
	/// @param Data the incoming data
	/// @param Size size of the incoming data
	void ReceivedRawPacket(void* Data, int32 Size) const;

	/// @brief function to handle incoming messages
	/// @param msg incoming message
	void handleTextMessage(const std::string& msg) const;

	/// @brief callback for when the connection was closed
	/// @param Socket unique socket for this connection
	void OnSocketClose(INetworkingWebSocket* InSocket);

	/// @brief unique socket for this connection
	INetworkingWebSocket* Socket = nullptr;
	/// @brief abstract network endpoint for this connection. Routes traffic to registered target sources in RemoteRegistry
	std::shared_ptr<ApiGear::ObjectLink::RemoteNode> Node;
	/// @brief the function to be used for all logging
	ApiGear::ObjectLink::WriteLogFunc logFunction;

#if WITH_DEV_AUTOMATION_TESTS
	friend class UOLinkHostConnectionSpec;
#endif
};
