#include "OLinkClientConnection.h"
THIRD_PARTY_INCLUDES_START
#include "olink/clientregistry.h"
#include "olink/iobjectsink.h"
THIRD_PARTY_INCLUDES_END
#include <UObject/Object.h>
#include "Runtime/Launch/Resources/Version.h"
#include <functional>
#include <chrono>
#include <future>
#include "ProfilingDebugging/CountersTrace.h"
#include "ProfilingDebugging/CpuProfilerTrace.h"

DEFINE_LOG_CATEGORY(LogApiGearOLink);
TRACE_DECLARE_INT_COUNTER(ApiGearOLinkClientMessagesSent, TEXT("Amount of messages sent by the OLink client"));
TRACE_DECLARE_INT_COUNTER(ApiGearOLinkClientMessagesReceived, TEXT("Amount of messages received by the OLink client"));

namespace
{
static const float processMessageDelay = 0; // [time in s, 0 is Next Frame]
static FString processMessageFunctionName = "ProcessMessageFunction";
} // namespace

void writeLog(ApiGear::ObjectLink::LogLevel level, const std::string& msg)
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
	TScriptInterface<IApiGearConnection> OLinkConnection = NewObject<UOLinkClientConnection>(Outer, *UniqueConnectionIdentifier);
	return OLinkConnection;
}

ApiGear::ObjectLink::WriteLogFunc logFunc()
{
	return [](ApiGear::ObjectLink::LogLevel level, const std::string& msg)
	{
		writeLog(level, msg);
		};
}

UOLinkClientConnection::UOLinkClientConnection(const FObjectInitializer& ObjectInitializer)
	: UAbstractApiGearConnection(ObjectInitializer)
	, m_socket(nullptr)
{
	m_node = ApiGear::ObjectLink::ClientNode::create(m_registry);

	ApiGear::ObjectLink::WriteMessageFunc func = [this](const std::string& msg)
	{
		m_queue.Enqueue(msg);
	};
	m_node->onWrite(func);
}

void UOLinkClientConnection::Configure(FString InServerURL, bool bInAutoReconnectEnabled)
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

UOLinkClientConnection::~UOLinkClientConnection()
{
	ApiGearTicker::GetCoreTicker().RemoveTicker(m_processMessageTaskTimerHandle);
	m_processMessageTaskTimerHandle.Reset();
}

void UOLinkClientConnection::log(const FString& logMessage)
{
	UE_LOG(LogApiGearOLink, Display, TEXT("%s"), *logMessage);
}

void UOLinkClientConnection::Connect_Implementation()
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.OLink.Connect");
	log(m_serverURL);

	open(m_serverURL);
}

void UOLinkClientConnection::Disconnect_Implementation()
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.OLink.Disconnect");
	for (std::string objectName : ListLinkedObjects)
	{
		m_node->unlinkRemote(objectName);
	}

	cleanupSocket();
}

bool UOLinkClientConnection::IsConnected()
{
	FScopeLock Lock(&SocketMutex);
	return m_socket && m_socket->IsConnected() && !bIsClosing;
}

void UOLinkClientConnection::cleanupSocket()
{
	FScopeLock Lock(&SocketMutex);

	if (!m_socket)
	{
		return;
	}

	bIsClosing = true;

	m_socket->OnConnected().Clear();
	m_socket->OnConnectionError().Clear();
	m_socket->OnClosed().Clear();

#if (ENGINE_MAJOR_VERSION >= 5 && ENGINE_MINOR_VERSION > 1)
	m_socket->OnMessage().Clear();
	m_socket->OnBinaryMessage().Clear();
#else
	m_socket->OnRawMessage().Clear();
#endif

	if (m_socket->IsConnected())
	{
		m_socket->Close(1000, TEXT("Intentional disconnect"));
	}

	m_socket.Reset();
	bIsClosing = false;
}

void UOLinkClientConnection::handleSocketClosed(int32 StatusCode, const FString& Reason, bool bWasClean)
{
	UE_LOG(LogApiGearOLink, Display, TEXT("status: %d, reason: %s, clean: %d"), StatusCode, *Reason, bWasClean);

	bool bReconnect = IsAutoReconnectEnabled();

	// 1000 == we closed the connection -> do not reconnect
	if (StatusCode == 1000)
	{
		bReconnect = false;
	}

	OnDisconnected(bReconnect);
}

void UOLinkClientConnection::open(const FString& url)
{
	cleanupSocket();

	if (!FModuleManager::Get().IsModuleLoaded("WebSockets"))
	{
		FModuleManager::Get().LoadModule("WebSockets");
	}

	FScopeLock Lock(&SocketMutex);
	m_socket = FWebSocketsModule::Get().CreateWebSocket(url);

	TWeakObjectPtr<UOLinkClientConnection> WeakThis(this);

	m_socket->OnConnected().AddLambda([WeakThis]() -> void
		{
		if (UOLinkClientConnection* StrongThis = WeakThis.Get())
		{
			StrongThis->OnConnected();
		}
	});

	m_socket->OnConnectionError().AddLambda([WeakThis](const FString& Error) -> void
		{
		if (UOLinkClientConnection* StrongThis = WeakThis.Get())
		{
			StrongThis->log(FString::Printf(TEXT("connection error: %s -> %s"), *StrongThis->GetServerURL(), *Error));
			StrongThis->OnDisconnected(StrongThis->IsAutoReconnectEnabled());
		}
	});

	TWeakPtr<IWebSocket> CurrentSocket(m_socket);
	m_socket->OnClosed().AddLambda([WeakThis, CurrentSocket](int32 StatusCode, const FString& Reason, bool bWasClean) -> void
		{
		if (UOLinkClientConnection* StrongThis = WeakThis.Get())
		{
			// Need to check whether we are called by the correct socket and not an old one
			TSharedPtr<IWebSocket> ActiveSocket = StrongThis->m_socket;
			TSharedPtr<IWebSocket> ClosedSocket = CurrentSocket.Pin();
			if (!ClosedSocket || ActiveSocket != ClosedSocket)
			{
				return;
			}

			StrongThis->handleSocketClosed(StatusCode, Reason, bWasClean);
		}
	});

#if (ENGINE_MAJOR_VERSION >= 5 && ENGINE_MINOR_VERSION > 1)
	m_socket->OnMessage().AddLambda([WeakThis](const FString& Message) -> void
		{
		if (UOLinkClientConnection* StrongThis = WeakThis.Get())
		{
			StrongThis->handleTextMessage(TCHAR_TO_UTF8(*Message));
		}
	});

	m_socket->OnBinaryMessage().AddLambda([WeakThis](const void* Data, SIZE_T Size, bool) -> void
		{
		if (UOLinkClientConnection* StrongThis = WeakThis.Get())
		{
			StrongThis->handleTextMessage(std::string((uint8*)Data, (uint8*)Data + Size));
		}
	});
#else
	m_socket->OnRawMessage().AddLambda([WeakThis](const void* Data, SIZE_T Size, SIZE_T) -> void
		{
		if (UOLinkClientConnection* StrongThis = WeakThis.Get())
		{
			StrongThis->handleTextMessage(std::string((uint8*)Data, (uint8*)Data + Size));
		}
	});
#endif

	m_socket->Connect();
}

void UOLinkClientConnection::OnConnected_Implementation()
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.OLink.OnConnected");
	log("socket connected");

	for (std::string objectName : ListLinkedObjects)
	{
		m_node->linkRemote(objectName);
	}
	// Schedule calling process message so they are sent from main thread. Throttling also improve sending during high load.
	if (!m_processMessageTaskTimerHandle.IsValid())
	{
		TWeakPtr<IWebSocket> socket(m_socket);
		m_processMessageTaskTimerHandle = ApiGearTicker::GetCoreTicker().AddTicker(*processMessageFunctionName, processMessageDelay,
			[this, socket](float /*param*/)
			{
			processMessages(socket);
			return true;
		});
	}
}

void UOLinkClientConnection::OnDisconnected_Implementation(bool bReconnect)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.OLink.OnDisconnected");
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
	if (m_processMessageTaskTimerHandle.IsValid())
	{
		ApiGearTicker::GetCoreTicker().RemoveTicker(m_processMessageTaskTimerHandle);
		m_processMessageTaskTimerHandle.Reset();
	}
}

FString UOLinkClientConnection::GetUniqueEndpointIdentifier() const
{
	return GetName();
}

void UOLinkClientConnection::handleTextMessage(const std::string& message)
{
	TRACE_COUNTER_INCREMENT(ApiGearOLinkClientMessagesReceived);
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.OLink.Client.HandleIncoming");
	m_node->handleMessage(message);
}

void UOLinkClientConnection::linkObjectSource(const std::string& name)
{
	ListLinkedObjects.AddUnique(name);

	if (IsConnected())
	{
		m_node->linkRemote(name);
	}
}

void UOLinkClientConnection::unlinkObjectSource(const std::string& name)
{
	if (IsConnected())
	{
		m_node->unlinkRemote(name);
	}
	ListLinkedObjects.Remove(name);
}

void UOLinkClientConnection::processMessages(TWeakPtr<IWebSocket> socket)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.OLink.Client.ProcessOutgoing");
	if (m_queue.IsEmpty())
	{
		// no data to be sent
		return;
	}
	if (TSharedPtr<IWebSocket> LockedSocket = socket.Pin())
	{
		if (!LockedSocket->IsConnected())
		{
			log("not connected -> connecting");
			Connect();
			return;
		}

		std::string msg;
		while (!m_queue.IsEmpty())
		{
			TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.OLink.Client.SendMessage");
			// if we are using JSON we need to use txt message
			m_queue.Dequeue(msg);
			LockedSocket->Send(UTF8_TO_TCHAR(msg.c_str()));
			TRACE_COUNTER_INCREMENT(ApiGearOLinkClientMessagesSent);
		}
	}
	else
	{
		log("no socket -> creating");
		return;
	}
}
