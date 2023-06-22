#include "unrealolink.h"
#include "ApiGearSettings.h"
THIRD_PARTY_INCLUDES_START
#include "olink/clientregistry.h"
#include "olink/iobjectsink.h"
THIRD_PARTY_INCLUDES_END
#include <UObject/Object.h>
#include <functional>
#include <chrono>
#include <future>

DEFINE_LOG_CATEGORY(LogApiGearOLink);

void writeLog(ApiGear::ObjectLink::LogLevel level, std::string msg)
{
	UApiGearSettings* settings = GetMutableDefault<UApiGearSettings>();
	if (!settings->OLINK_EnableDebugLog)
	{
		return;
	}

	switch (level)
	{
	case ApiGear::ObjectLink::LogLevel::Info:
		UE_LOG(LogApiGearOLink, Display, TEXT("%s"), UTF8_TO_TCHAR(msg.c_str()));
		break;
	case ApiGear::ObjectLink::LogLevel::Debug:
		UE_LOG(LogApiGearOLink, Display, TEXT("%s"), UTF8_TO_TCHAR(msg.c_str()));
		break;
	case ApiGear::ObjectLink::LogLevel::Warning:
		UE_LOG(LogApiGearOLink, Warning, TEXT("%s"), UTF8_TO_TCHAR(msg.c_str()));
		break;
	case ApiGear::ObjectLink::LogLevel::Error:
		UE_LOG(LogApiGearOLink, Error, TEXT("%s"), UTF8_TO_TCHAR(msg.c_str()));
		break;
	}
}

ApiGear::ObjectLink::WriteLogFunc logFunc()
{
	return [](ApiGear::ObjectLink::LogLevel level, std::string msg)
	{ writeLog(level, msg); };
}

UUnrealOLink::UUnrealOLink(const FObjectInitializer& ObjectInitializer)
	: UAbstractApiGearConnection(ObjectInitializer)
	, m_socket(nullptr)
	, m_loggingDisabled(false)
{
	UApiGearSettings* settings = GetMutableDefault<UApiGearSettings>();
	m_node = ApiGear::ObjectLink::ClientNode::create(m_registry);
	if (settings->OLINK_EnableDebugLog)
	{
		m_node->onLog(logFunc());
		m_registry.onLog(logFunc());
	}

	m_loggingDisabled = !settings->OLINK_EnableDebugLog;
	log(m_serverURL);

	ApiGear::ObjectLink::WriteMessageFunc func = [this](std::string msg)
	{
		m_queue.Enqueue(msg);
		processMessages();
	};
	m_node->onWrite(func);

	log("OLink instantiated");
	// processMessages();
}

UUnrealOLink::~UUnrealOLink()
{
	// delete m_session;
}

void UUnrealOLink::log(const FString& logMessage)
{
	if (!m_loggingDisabled)
	{
		UE_LOG(LogApiGearOLink, Display, TEXT("%s"), *logMessage);
	}
}

void UUnrealOLink::Connect()
{
	UAbstractApiGearConnection::Connect();

	UApiGearSettings* settings = GetMutableDefault<UApiGearSettings>();

	// we need to initiate a new socket to change the server address
	if (m_socket && m_serverURL != settings->OLINK_URL)
	{
		m_socket.Reset();
		m_socket = nullptr;
	}

	m_serverURL = settings->OLINK_URL;
	m_loggingDisabled = !settings->OLINK_EnableDebugLog;

	if (!IsConnected() || GetConnectionState() == EApiGearConnectionState::Connecting)
	{
		log(m_serverURL);

		open(m_serverURL);
	}
}

void UUnrealOLink::Disconnect()
{
	if (!IsConnected() || GetConnectionState() == EApiGearConnectionState::Connecting)
	{
		UAbstractApiGearConnection::StopReconnecting();
		return;
	}

	for (std::string objectName : ListLinkedObjects)
	{
		m_node->unlinkRemote(objectName);
	}
	m_socket->Close();
}

bool UUnrealOLink::IsConnected()
{
	if (m_socket && m_socket->IsConnected())
	{
		return true;
	}
	return false;
}

void UUnrealOLink::open(const FString& url)
{
	if (!m_socket)
	{
		if (!FModuleManager::Get().IsModuleLoaded("WebSockets"))
		{
			FModuleManager::Get().LoadModule("WebSockets");
		}
		m_socket = FWebSocketsModule::Get().CreateWebSocket(url);

		m_socket->OnConnected().AddLambda([this]() -> void
			{ OnConnected(); });

		m_socket->OnConnectionError().AddLambda(
			[this](const FString& Error) -> void
			{
				// This code will run if the connection failed. Check Error to see what happened.
				log(FString::Printf(TEXT("connection error: %s"), *Error));
				UApiGearSettings* settings = GetMutableDefault<UApiGearSettings>();
				UAbstractApiGearConnection::OnDisconnected(settings->OLINK_AutoReconnectEnabled);
			});

		m_socket->OnClosed().AddLambda(
			[this](int32 StatusCode, const FString& Reason, bool bWasClean) -> void
			{
				(void)StatusCode;
				(void)Reason;
				(void)bWasClean;
				UE_LOG(LogApiGearOLink, Display, TEXT("status: %d, reason: %s, clean: %d"), StatusCode, *Reason, bWasClean);

				UApiGearSettings* settings = GetMutableDefault<UApiGearSettings>();
				bool bReconnect = settings->OLINK_AutoReconnectEnabled;

				// 1000 == we closed the connection -> do not reconnect
				if (StatusCode == 1000)
				{
					bReconnect = false;
				}
				OnDisconnected(bReconnect);
			});

		m_socket->OnMessage().AddLambda(
			[this](const FString& Message) -> void
			{
				// This code will run when we receive a string message from the server.
				handleTextMessage(Message);
			});

		m_socket->OnRawMessage().AddLambda(
			[this](const void* Data, SIZE_T Size, SIZE_T /*BytesRemaining*/) -> void
			{
				handleTextMessage(FString(std::string((uint8*)Data, (uint8*)Data + Size).c_str()));
			});

		// m_socket->OnMessageSent().AddLambda([](const FString& MessageString) -> void {
		//     // This code is called after we sent a message to the server.
		// });
	}

	if (!m_socket->IsConnected())
	{
		// TODO check whether already in "connecting" state - otherwise websocket will log a warning message
		m_socket->Connect();
	}
}

void UUnrealOLink::OnConnected()
{
	log("socket connected");
	UAbstractApiGearConnection::OnConnected();

	for (std::string objectName : ListLinkedObjects)
	{
		m_node->linkRemote(objectName);
	}
	// m_session->init(TCHAR_TO_UTF8(*m_realm));
	processMessages();
}

void UUnrealOLink::OnDisconnected(bool bReconnect)
{
	log("socket disconnected");
	for (std::string objectName : ListLinkedObjects)
	{
		auto sink = m_registry.getSink(objectName).lock();
		if (sink)
		{
			sink->olinkOnRelease();
		}
		m_registry.unsetNode(objectName);
	}
	UAbstractApiGearConnection::OnDisconnected(bReconnect);
}

void UUnrealOLink::handleTextMessage(const FString& message)
{
	m_node->handleMessage(TCHAR_TO_UTF8(*message));
}

// void UUnrealOLink::onError(std::string error)
// {
//     log("onError"); //  << error;
// }

// void UUnrealOLink::onEvent(std::string topic, Arguments args, ArgumentsKw kwargs)
// {
//     log("onEvent"); // << topic; // json(args).dump() << json(kwargs).dump();
// }

void UUnrealOLink::linkObjectSource(const std::string& name)
{
	ListLinkedObjects.AddUnique(name);

	if (IsConnected())
	{
		m_node->linkRemote(name);
	}
}

void UUnrealOLink::unlinkObjectSource(const std::string& name)
{
	if (IsConnected())
	{
		m_node->unlinkRemote(name);
	}
	ListLinkedObjects.Remove(name);
}

void UUnrealOLink::processMessages()
{
	if (m_queue.IsEmpty())
	{
		// no data to be sent
		return;
	}

	if (!m_socket)
	{
		log("no socket -> creating");
		// open(m_serverURL);
		return;
	}

	if (!m_socket->IsConnected())
	{
		log("not connected -> connecting");
		Connect();
		return;
	}

	std::string msg;
	while (!m_queue.IsEmpty())
	{
		// if we are using JSON we need to use txt message
		m_queue.Dequeue(msg);
		m_socket->Send(UTF8_TO_TCHAR(msg.c_str()));
	}
}
