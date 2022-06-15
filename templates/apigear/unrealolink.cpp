#include "unrealolink.h"
#include "ApiGearSettings.h"
#include "olink/core/types.h"
#include <functional>
#include <chrono>
#include <future>

DEFINE_LOG_CATEGORY(LogApiGearOLink);

void writeLog(ApiGear::ObjectLink::LogLevel level, std::string msg)
{
    switch(level) {
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
    return [](ApiGear::ObjectLink::LogLevel level, std::string msg) {
        writeLog(level, msg);
    };
}

UnrealOLink::UnrealOLink()
    : m_socket(nullptr)
    , m_loggingDisabled(false)
{
    UApiGearSettings* settings = GetMutableDefault<UApiGearSettings>();
    m_node.onLog(logFunc());
    ApiGear::ObjectLink::ClientRegistry::get().onLog(logFunc());
    
    m_loggingDisabled = !settings->OLINK_EnableDebugLog;
    log(m_serverURL);

    ApiGear::ObjectLink::WriteMessageFunc func = [this](std::string msg) {
        {
            const std::lock_guard<std::mutex> lock(m_queue_mutex);
            m_queue.push(msg);
        }
        processMessages();
    };
    m_node.onWrite(func);

    log("OLink instantiated");
	// processMessages();
}

UnrealOLink::~UnrealOLink()
{
    // delete m_session;
}

void UnrealOLink::log(const FString &logMessage)
{
    if(!m_loggingDisabled)
    {
        UE_LOG(LogApiGearOLink, Display, TEXT("%s"), *logMessage);
    }
}

void UnrealOLink::connect()
{
    UApiGearSettings* settings = GetMutableDefault<UApiGearSettings>();
    m_serverURL = settings->OLINK_URL;
    m_loggingDisabled = !settings->OLINK_EnableDebugLog;
    log(m_serverURL);
    
    open(m_serverURL);
}

void UnrealOLink::disconnect()
{
    m_socket->Close();
}

bool UnrealOLink::isConnected()
{
    return m_socket->IsConnected();
}

void UnrealOLink::open(const FString& url)
{
    if(!m_socket) {
        if(!FModuleManager::Get().IsModuleLoaded("WebSockets"))
        {
            FModuleManager::Get().LoadModule("WebSockets");
        }
        m_socket = FWebSocketsModule::Get().CreateWebSocket(url);

        m_socket->OnConnected().AddLambda([this]() -> void {
            onConnected();
        });

        m_socket->OnConnectionError().AddLambda([this](const FString & Error) -> void {
            // This code will run if the connection failed. Check Error to see what happened.
            log("connection error:");
			log(Error);
        });

        m_socket->OnClosed().AddLambda([this](int32 StatusCode, const FString& Reason, bool bWasClean) -> void {
            (void) StatusCode;
            (void) Reason;
            (void) bWasClean;

            onDisconnected();
        });

        m_socket->OnMessage().AddLambda([this](const FString & Message) -> void {
            // This code will run when we receive a string message from the server.
            handleTextMessage(Message);
        });

        // m_socket->OnRawMessage().AddLambda([](const void* Data, SIZE_T Size, SIZE_T BytesRemaining) -> void {
        //     // This code will run when we receive a raw (binary) message from the server.
        // });

        // m_socket->OnMessageSent().AddLambda([](const FString& MessageString) -> void {
        //     // This code is called after we sent a message to the server.
        // });
    }

    if(!m_socket->IsConnected())
    {
        // TODO check whether already in "connecting" state - otherwise websocket will log a warning message
        m_socket->Connect();
    }
}

void UnrealOLink::onConnected()
{
    log("socket connected");
    IsConnectedChanged.Broadcast(true);
    // m_session->init(TCHAR_TO_UTF8(*m_realm));
    processMessages();
}

void UnrealOLink::onDisconnected()
{
    log("socket disconnected");
    IsConnectedChanged.Broadcast(false);
}

void UnrealOLink::handleTextMessage(const FString &message)
{
    m_node.handleMessage(TCHAR_TO_UTF8(*message));
}

// void UnrealOLink::onError(std::string error)
// {
//     log("onError"); //  << error;
// }

// void UnrealOLink::onEvent(std::string topic, Arguments args, ArgumentsKw kwargs)
// {
//     log("onEvent"); // << topic; // json(args).dump() << json(kwargs).dump();
// }

void UnrealOLink::linkObjectSource(std::string name)
{
    m_node.registry().linkClientNode(name, &m_node);
    m_node.linkRemote(name);
}

void UnrealOLink::processMessages()
{
	if (!m_socket) {
        log("no socket -> creating");
        // open(m_serverURL);
        return;
	}

    if (!m_socket->IsConnected()) {
        log("not connected -> connecting");
        open(m_serverURL);
        return;
    }

    if (m_socket->IsConnected()) {
        const std::lock_guard<std::mutex> lock(m_queue_mutex);
        while(!m_queue.empty()) {
            // if we are using JSON we need to use txt message
            // otherwise binary messages
            //    m_socket->sendBinaryMessage(QByteArray::fromStdString(message));
            const std::string& msg = m_queue.back();
            m_socket->Send(UTF8_TO_TCHAR(msg.c_str()));
            m_queue.pop();
        }
    }
}

