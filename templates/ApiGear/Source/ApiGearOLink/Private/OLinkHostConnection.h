#pragma once

THIRD_PARTY_INCLUDES_START
#include "olink/remoteregistry.h"
#include "olink/remotenode.h"
THIRD_PARTY_INCLUDES_END
#include <UObject/Object.h>
#include "ApiGearLogCategories.h"
#include "INetworkingWebSocket.h"

class FOLinkHostConnection;

DECLARE_DELEGATE_OneParam(FOLinkHostConnectionClosedCallBack, FOLinkHostConnection* /*Connection*/);

/// @brief an instance of this class is held by the OLink server worker for each existing connection
class APIGEAROLINK_API FOLinkHostConnection
{

public:
	FOLinkHostConnectionClosedCallBack ConnectionClosedCallBack;

	FOLinkHostConnection(INetworkingWebSocket* InSocket, ApiGear::ObjectLink::RemoteRegistry& InRegistry, ApiGear::ObjectLink::WriteLogFunc logFunc)
		: Socket(InSocket)
		, Registry(InRegistry)
		, Node(ApiGear::ObjectLink::RemoteNode::createRemoteNode(InRegistry))
	{
		FWebSocketPacketReceivedCallBack ReceiveCallBack;
		ReceiveCallBack.BindRaw(this, &FOLinkHostConnection::ReceivedRawPacket);
		Socket->SetReceiveCallBack(ReceiveCallBack);

		FWebSocketInfoCallBack CloseCallback;
		CloseCallback.BindRaw(this, &FOLinkHostConnection::OnSocketClose, Socket);
		Socket->SetSocketClosedCallBack(CloseCallback);

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

	bool IsConnection(FOLinkHostConnection* InConnection) const
	{
		return this == InConnection;
	}

private:
	/// @brief callback for received data packets - for now we assume it is text data
	/// @param Data pointer to the incoming data
	/// @param Size size of the incoming data
	void ReceivedRawPacket(void* Data, int32 Size)
	{
		this->handleTextMessage(std::string((uint8*)Data, (uint8*)Data + Size));
	}

	/// @brief function to handle incoming messages
	/// @param msg incoming message
	void handleTextMessage(const std::string& msg)
	{
		Node->handleMessage(msg);
	}

	/// @brief callback for when the connection was closed
	/// @param Socket pointer to unique socket for each connection
	void OnSocketClose(INetworkingWebSocket* InSocket)
	{
		if (Socket == InSocket)
		{
			UE_LOG(LogApiGearOLinkHost, Log, TEXT("%s %s"), "remote: closed connection ", *Socket->RemoteEndPoint(true));
			ConnectionClosedCallBack.Execute(this);

			delete Socket;
			Socket = nullptr;
		}
	}

	/// @brief pointer to unique socket for each connection
	INetworkingWebSocket* Socket = nullptr;
	/**A global registry to which network endpoints are added for olink objects. */
	ApiGear::ObjectLink::RemoteRegistry& Registry;
	std::shared_ptr<ApiGear::ObjectLink::RemoteNode> Node;
};
