#include "OLinkHostConnection.h"
#include "ApiGearLogCategories.h"
#include "INetworkingWebSocket.h"

namespace
{
std::string ConvertToString(void* Data, int32 Size)
{
	return std::string((uint8*)Data, (uint8*)Data + Size);
}

const uint8* ConvertFromString(const std::string& msg)
{
	return reinterpret_cast<const uint8*>(msg.c_str());
}
} // namespace

FOLinkHostConnection::FOLinkHostConnection(INetworkingWebSocket* InSocket, ApiGear::ObjectLink::RemoteRegistry& InRegistry, ApiGear::ObjectLink::WriteLogFunc logFunc)
	: Socket(InSocket)
	, Node(ApiGear::ObjectLink::RemoteNode::createRemoteNode(InRegistry))
	, logFunction(logFunc)
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
			InSocket->Send(ConvertFromString(msg), msg.size(), false);
		});
}

FOLinkHostConnection::FOLinkHostConnection(FOLinkHostConnection&& Other)
	: Node(Other.Node)
	, logFunction(Other.logFunction)
{
	Socket = Other.Socket;
	Other.Socket = nullptr;
}

FOLinkHostConnection::~FOLinkHostConnection()
{
	// make sure we are not accidentally writing to socket
	Node->onWrite([](const std::string&) {});

	if (Socket)
	{
		delete Socket;
		Socket = nullptr;
	}
}

bool FOLinkHostConnection::IsConnection(FOLinkHostConnection* InConnection) const
{
	return this == InConnection;
}

void FOLinkHostConnection::ReceivedRawPacket(void* Data, int32 Size) const
{
	this->handleTextMessage(ConvertToString(Data, Size));
}

void FOLinkHostConnection::handleTextMessage(const std::string& msg) const
{
	Node->handleMessage(msg);
}

void FOLinkHostConnection::OnSocketClose(INetworkingWebSocket* InSocket)
{
	if (Socket == InSocket)
	{
		logFunction(ApiGear::ObjectLink::LogLevel::Info, std::string("remote client: closed connection ") + TCHAR_TO_UTF8(*Socket->RemoteEndPoint(true)));
		ConnectionClosedCallBack.Execute(this);

		// make sure we are not accidentally writing to socket
		Node->onWrite([](const std::string&) {});

		delete Socket;
		Socket = nullptr;
	}
}
