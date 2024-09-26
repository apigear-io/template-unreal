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
	{
		writeLogHost(level, msg);
		};
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
		static const std::string ErrorMsg = "Cannot start new OLink server";
		writeLogHost(ApiGear::ObjectLink::LogLevel::Error, ErrorMsg);
		Server.Reset();
		return false;
	}

	TickerHandle = ApiGearTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateRaw(this, &OLinkHostPrivate::Tick));
	return true;
}

void OLinkHostPrivate::Stop()
{
	if (TickerHandle.IsValid())
	{
		ApiGearTicker::GetCoreTicker().RemoveTicker(TickerHandle);
		TickerHandle.Reset();
	}
	if (Server)
	{
		Server.Reset();
	}
}

bool OLinkHostPrivate::Tick(float DeltaTime)
{
	if (Server)
		Server->Tick();
	return true;
}

void OLinkHostPrivate::OnWebSocketClientConnected(INetworkingWebSocket* Socket)
{
	checkf(Socket, TEXT("Socket was null while creating a new websocket connection."));

	static const std::string Msg = "remote: new connection ";
	writeLogHost(ApiGear::ObjectLink::LogLevel::Info, Msg + TCHAR_TO_UTF8(*Socket->RemoteEndPoint(true)));
	TUniquePtr<FOLinkHostConnection> Connection = MakeUnique<FOLinkHostConnection>(Socket, *Registry, logHostFunc());

	Connection->ConnectionClosedCallBack.BindRaw(this, &OLinkHostPrivate::OnConnectionClose);

	ClientConnections.Add(MoveTemp(Connection));
}

void OLinkHostPrivate::OnConnectionClose(FOLinkHostConnection* Connection)
{
	ClientConnections.RemoveAllSwap([Connection](const TUniquePtr<FOLinkHostConnection>& InConnection)
		{
		return InConnection->IsConnection(Connection);
	});
}

uint32 OLinkHostPrivate::NumberOfConnections() const
{
	return ClientConnections.Num();
}
