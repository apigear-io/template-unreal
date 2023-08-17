#include "OLinkHostPrivate.h"
#include "OLinkHostConnection.h"
#include "ApiGearLogCategories.h"
#include "ApiGearSettings.h"
#include "Modules/ModuleManager.h"
THIRD_PARTY_INCLUDES_START
#include "olink/remoteregistry.h"
#include "olink/remotenode.h"
THIRD_PARTY_INCLUDES_END
#include "SocketSubsystem.h"
#include "INetworkingWebSocket.h"
#include "IWebSocketServer.h"
#include "IWebSocketNetworkingModule.h"

void writeLogHost(ApiGear::ObjectLink::LogLevel level, const std::string& msg)
{
	switch (level)
	{
	case ApiGear::ObjectLink::LogLevel::Info:
		UE_LOG(LogApiGearOLinkHost, Log, TEXT("%s"), UTF8_TO_TCHAR(msg.c_str()));
		break;
	case ApiGear::ObjectLink::LogLevel::Debug:
		UE_LOG(LogApiGearOLinkHost, Display, TEXT("%s"), UTF8_TO_TCHAR(msg.c_str()));
		break;
	case ApiGear::ObjectLink::LogLevel::Warning:
		UE_LOG(LogApiGearOLinkHost, Warning, TEXT("%s"), UTF8_TO_TCHAR(msg.c_str()));
		break;
	case ApiGear::ObjectLink::LogLevel::Error:
		UE_LOG(LogApiGearOLinkHost, Error, TEXT("%s"), UTF8_TO_TCHAR(msg.c_str()));
		break;
	}
}

ApiGear::ObjectLink::WriteLogFunc logHostFunc()
{
	return [](ApiGear::ObjectLink::LogLevel level, const std::string& msg)
	{ writeLogHost(level, msg); };
}

OLinkHostPrivate::OLinkHostPrivate(uint32 InPort)
	: m_loggingDisabled(false)
	, Port(InPort)
{
	UApiGearSettings* settings = GetMutableDefault<UApiGearSettings>();

	Registry = MakeShared<ApiGear::ObjectLink::RemoteRegistry>();
	Registry->onLog(logHostFunc());

	if (settings->OLINK_AutoStart)
	{
		Start(Port);
	}
}

OLinkHostPrivate::~OLinkHostPrivate()
{
	Stop();
}

bool OLinkHostPrivate::Start(uint32 InPort)
{
	writeLogHost(ApiGear::ObjectLink::LogLevel::Debug, "Apigear OLink Server starting up...");
	Port = InPort;

	FWebSocketClientConnectedCallBack CallBack;
	CallBack.BindRaw(this, &OLinkHostPrivate::OnWebSocketClientConnected);

	Server = FModuleManager::Get().LoadModuleChecked<IWebSocketNetworkingModule>(TEXT("WebSocketNetworking")).CreateServer();

	if (!Server || !Server->Init(Port, CallBack))
	{
		Server.Reset();
		return false;
	}

#if (ENGINE_MAJOR_VERSION >= 5)
	TickerHandle = FTSTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateRaw(this, &OLinkHostPrivate::Tick));
#else
	TickerHandle = FTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateRaw(this, &OLinkHostPrivate::Tick));
#endif
	return true;
}

void OLinkHostPrivate::Stop()
{
	if (TickerHandle.IsValid())
	{
#if (ENGINE_MAJOR_VERSION >= 5)
		FTSTicker::GetCoreTicker().RemoveTicker(TickerHandle);
#else
		FTicker::GetCoreTicker().RemoveTicker(TickerHandle);
#endif

		TickerHandle.Reset();
	}
	if (Server)
	{
		Server.Reset();
	}
}

bool OLinkHostPrivate::Tick(float DeltaTime)
{
	Server->Tick();
	return true;
}

void OLinkHostPrivate::OnWebSocketClientConnected(INetworkingWebSocket* Socket)
{
	checkf(Socket, TEXT("Socket was null while creating a new websocket connection."));

	writeLogHost(ApiGear::ObjectLink::LogLevel::Info, std::string("remote: new connection ") + TCHAR_TO_UTF8(*Socket->RemoteEndPoint(true)));
	TUniquePtr<FOLinkHostConnection> Connection = MakeUnique<FOLinkHostConnection>(Socket, *Registry, logHostFunc());

	FWebSocketPacketReceivedCallBack ReceiveCallBack;
	ReceiveCallBack.BindRaw(this, &OLinkHostPrivate::ReceivedRawPacket, Socket);
	Socket->SetReceiveCallBack(ReceiveCallBack);

	FWebSocketInfoCallBack CloseCallback;
	CloseCallback.BindRaw(this, &OLinkHostPrivate::OnSocketClose, Socket);
	Socket->SetSocketClosedCallBack(CloseCallback);

	ClientConnections.Add(Socket, MoveTemp(Connection));
}

void OLinkHostPrivate::ReceivedRawPacket(void* Data, int32 Size, INetworkingWebSocket* Socket)
{
	TUniquePtr<FOLinkHostConnection>* ConnectionHandler = nullptr;

	ConnectionHandler = ClientConnections.Find(Socket);
	if (!ConnectionHandler)
	{
		return;
	}

	ConnectionHandler->Get()->handleTextMessage(std::string((uint8*)Data, (uint8*)Data + Size));
}

void OLinkHostPrivate::OnSocketClose(INetworkingWebSocket* Socket)
{
	writeLogHost(ApiGear::ObjectLink::LogLevel::Info, std::string("remote: closed connection ") + TCHAR_TO_UTF8(*Socket->RemoteEndPoint(true)));
	ClientConnections.FindAndRemoveChecked(Socket);
}

uint32 OLinkHostPrivate::NumConnections() const
{
	return ClientConnections.Num();
}
