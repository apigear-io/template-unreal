#include "unrealolink.h"
THIRD_PARTY_INCLUDES_START
#include "olink/clientregistry.h"
#include "olink/iobjectsink.h"
THIRD_PARTY_INCLUDES_END
#include <UObject/Object.h>
#include "Runtime/Launch/Resources/Version.h"
#include <functional>
#include <chrono>
#include <future>

DEFINE_LOG_CATEGORY(LogApiGearOLink);

void writeLog(ApiGear::ObjectLink::LogLevel level, std::string msg)
{
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

TScriptInterface<IApiGearConnection> OLinkFactory::Create(UObject* Outer, FString UniqueConnectionIdentifier)
{
	TScriptInterface<IApiGearConnection> OLinkConnection = NewObject<UUnrealOLink>(Outer, *UniqueConnectionIdentifier);
	return OLinkConnection;
}

ApiGear::ObjectLink::WriteLogFunc logFunc()
{
	return [](ApiGear::ObjectLink::LogLevel level, std::string msg)
	{ writeLog(level, msg); };
}

UUnrealOLink::UUnrealOLink(const FObjectInitializer& ObjectInitializer)
	: UAbstractApiGearConnection(ObjectInitializer)
	, m_socket(nullptr)
{
	m_node = ApiGear::ObjectLink::ClientNode::create(m_registry);

	ApiGear::ObjectLink::WriteMessageFunc func = [this](std::string msg)
	{
		m_queue.Enqueue(msg);
		processMessages();
	};
	m_node->onWrite(func);
}

void UUnrealOLink::Configure(FString InServerURL, bool bInAutoReconnectEnabled)
{
	check(!bInitialized);
	bInitialized = true;

	m_serverURL = InServerURL;
	SetAutoReconnectEnabled(bInAutoReconnectEnabled);

	m_node->onLog(logFunc());
	m_registry.onLog(logFunc());

	log(m_serverURL);

	log("OLink instantiated");
}

UUnrealOLink::~UUnrealOLink()
{
}

void UUnrealOLink::log(const FString& logMessage)
{
	UE_LOG(LogApiGearOLink, Display, TEXT("%s"), *logMessage);
}

void UUnrealOLink::Connect_Implementation()
{
	log(m_serverURL);

	open(m_serverURL);
}

void UUnrealOLink::Disconnect_Implementation()
{
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
				UAbstractApiGearConnection::OnDisconnected(IsAutoReconnectEnabled());
			});

		m_socket->OnClosed().AddLambda(
			[this](int32 StatusCode, const FString& Reason, bool bWasClean) -> void
			{
				(void)StatusCode;
				(void)Reason;
				(void)bWasClean;
				UE_LOG(LogApiGearOLink, Display, TEXT("status: %d, reason: %s, clean: %d"), StatusCode, *Reason, bWasClean);

				bool bReconnect = IsAutoReconnectEnabled();

				// 1000 == we closed the connection -> do not reconnect
				if (StatusCode == 1000)
				{
					bReconnect = false;
				}
				OnDisconnected(bReconnect);
			});

#if (ENGINE_MAJOR_VERSION >= 5 && ENGINE_MINOR_VERSION > 1)
		m_socket->OnMessage().AddLambda(
			[this](const FString& Message) -> void
			{
				// This code will run when we receive a string message from the server.
				handleTextMessage(Message);
			});

		m_socket->OnBinaryMessage().AddLambda(
			[this](const void* Data, SIZE_T Size, bool /* bIsLastFragment */) -> void
			{
				// we assume the incoming binary message is actually text
				handleTextMessage(FString(std::string((uint8*)Data, (uint8*)Data + Size).c_str()));
			});
#else
		m_socket->OnRawMessage().AddLambda(
			[this](const void* Data, SIZE_T Size, SIZE_T /* BytesRemaining */) -> void
			{
				// we assume the incoming raw message is actually text
				handleTextMessage(FString(std::string((uint8*)Data, (uint8*)Data + Size).c_str()));
			});
#endif
	}

	if (!m_socket->IsConnected())
	{
		// TODO check whether already in "connecting" state - otherwise websocket will log a warning message
		m_socket->Connect();
	}
}

void UUnrealOLink::OnConnected_Implementation()
{
	log("socket connected");

	for (std::string objectName : ListLinkedObjects)
	{
		m_node->linkRemote(objectName);
	}
	processMessages();
}

void UUnrealOLink::OnDisconnected_Implementation(bool bReconnect)
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
}

FString UUnrealOLink::GetUniqueEndpointIdentifier() const
{
	return GetName();
}

void UUnrealOLink::handleTextMessage(const FString& message)
{
	m_node->handleMessage(TCHAR_TO_UTF8(*message));
}

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
