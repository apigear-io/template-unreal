#include "OLinkHostConnection.h"
#include "OLinkCommon.h"
#include "ApiGearLogCategories.h"
#include "HAL/Platform.h"
#if !(PLATFORM_IOS || PLATFORM_ANDROID || PLATFORM_QNX)
#include "INetworkingWebSocket.h"
#include "ProfilingDebugging/CountersTrace.h"

TRACE_DECLARE_INT_COUNTER(ApiGearOLinkServerMessagesSent, TEXT("Amount of messages sent by the OLink server"));
TRACE_DECLARE_INT_COUNTER(ApiGearOLinkServerMessagesReceived, TEXT("Amount of messages received by the OLink server"));

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
		TRACE_COUNTER_INCREMENT(ApiGearOLinkServerMessagesSent);
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
	TRACE_COUNTER_INCREMENT(ApiGearOLinkServerMessagesReceived);
	this->handleTextMessage(ConvertToString(Data, Size));
}

void FOLinkHostConnection::handleTextMessage(const std::string& msg) const
{
	TRACE_COUNTER_INCREMENT(ApiGearOLinkServerMessagesReceived);
	Node->handleMessage(msg);
}

void FOLinkHostConnection::OnSocketClose(INetworkingWebSocket* /* InSocket */)
{
	logFunction(ApiGear::ObjectLink::LogLevel::Info, std::string("remote client: closed connection ") + TCHAR_TO_UTF8(*Socket->RemoteEndPoint(true)));
	ConnectionClosedCallBack.Execute(this);

	// make sure we are not accidentally writing to socket
	Node->onWrite([](const std::string&) {});

	delete Socket;
	Socket = nullptr;
}

#endif // !(PLATFORM_IOS || PLATFORM_ANDROID || PLATFORM_QNX)
