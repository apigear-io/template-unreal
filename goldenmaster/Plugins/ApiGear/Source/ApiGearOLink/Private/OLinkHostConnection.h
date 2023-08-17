#pragma once

THIRD_PARTY_INCLUDES_START
#include "olink/remoteregistry.h"
#include "olink/remotenode.h"
THIRD_PARTY_INCLUDES_END
#include <UObject/Object.h>
#include "ApiGearLogCategories.h"
#include "INetworkingWebSocket.h"

/// @brief an instance of this class is held by the OLink server worker for each existing connection
class APIGEAROLINK_API FOLinkHostConnection
{

public:
	FOLinkHostConnection(INetworkingWebSocket* InSocket, ApiGear::ObjectLink::RemoteRegistry& InRegistry, ApiGear::ObjectLink::WriteLogFunc logFunc)
		: Socket(InSocket)
		, Registry(InRegistry)
		, Node(ApiGear::ObjectLink::RemoteNode::createRemoteNode(InRegistry))
	{
		Node->onLog(logFunc);
		Node->onWrite([InSocket](const std::string& msg)
			{
				check(InSocket);
				InSocket->Send(reinterpret_cast<const uint8*>(msg.c_str()), msg.size(), false);
			});
	}

	FOLinkHostConnection(FOLinkHostConnection&& WebSocketConnection)
		: Registry(WebSocketConnection.Registry)
		, Node(WebSocketConnection.Node)
	{
		Socket = WebSocketConnection.Socket;
		WebSocketConnection.Socket = nullptr;
	}

	~FOLinkHostConnection()
	{
		if (Socket)
		{
			delete Socket;
			Socket = nullptr;
		}
	}

	/// @brief function to handle incoming messages
	/// @param msg incoming message
	void handleTextMessage(const std::string& msg)
	{
		Node->handleMessage(msg);
	}

private:
	/// @brief pointer to unique socket for each connection
	INetworkingWebSocket* Socket = nullptr;
	/**A global registry to which network endpoints are added for olink objects. */
	ApiGear::ObjectLink::RemoteRegistry& Registry;
	std::shared_ptr<ApiGear::ObjectLink::RemoteNode> Node;
};
