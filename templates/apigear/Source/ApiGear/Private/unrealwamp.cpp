// Copyright Epic Games, Inc. All Rights Reserved
#include "unrealwamp.h"
#include "wamp/session.h"

DEFINE_LOG_CATEGORY(LogApiGearWamp);
using namespace ApiGear::WAMP;
UnrealWamp* UnrealWamp::s_instance(nullptr);

UnrealWamp::UnrealWamp()
    : m_socket(nullptr)
    , m_session(new ApiGear::WAMP::Session(this, this, this, WAMP::MessageFormat::JSON))
    , m_loggingDisabled(false)
{
    if(s_instance) {
        log("WAMP service can only be instantiated once");
    }
    
    UApiGearSettings* settings = GetMutableDefault<UApiGearSettings>();
    m_serverURL = settings->WAMP_URL;
    m_realm = settings->WAMP_realm;
    m_loggingDisabled = !settings->WAMP_EnableDebugLog;

    open(m_serverURL);

    log("WAMP instantiated");
}

UnrealWamp *UnrealWamp::instance()
{
    if(!s_instance) {
        s_instance = new UnrealWamp();
    }
    return s_instance;
}

UnrealWamp::~UnrealWamp()
{
    delete m_session;
}

void UnrealWamp::log(const FString &logMessage)
{
    if(!m_loggingDisabled)
    {
        UE_LOG(LogApiGearWamp, Display, TEXT("%s"), *logMessage);
    }
}

void UnrealWamp::info(std::string message)
{
    if(!m_loggingDisabled)
    {
        UE_LOG(LogApiGearWamp, Verbose, TEXT("%s"), UTF8_TO_TCHAR(message.c_str()));
    }
}

void UnrealWamp::debug(std::string message)
{
    if(!m_loggingDisabled)
    {
        UE_LOG(LogApiGearWamp, Display, TEXT("%s"), UTF8_TO_TCHAR(message.c_str()));
    }
}

void UnrealWamp::warning(std::string message)
{
    if(!m_loggingDisabled)
    {
        UE_LOG(LogApiGearWamp, Warning, TEXT("%s"), UTF8_TO_TCHAR(message.c_str()));
    }
}

void UnrealWamp::error(std::string message)
{
    if(!m_loggingDisabled)
    {
        UE_LOG(LogApiGearWamp, Error, TEXT("%s"), UTF8_TO_TCHAR(message.c_str()));
    }
}

void UnrealWamp::open(const FString& url)
{
    const FString ServerProtocol = TEXT("wamp.2.json"); 
    if(!m_socket) {
        if(!FModuleManager::Get().IsModuleLoaded("WebSockets"))
        {
            FModuleManager::Get().LoadModule("WebSockets");
        }
        m_socket = FWebSocketsModule::Get().CreateWebSocket(url, ServerProtocol);

    // connect(m_socket, &QWebSocket::textMessageReceived, this, &UnrealWamp::handleTextMessage);

        m_socket->OnConnected().AddLambda([this]() -> void {
            onConnected();
        });

        // m_socket->OnConnectionError().AddLambda([](const FString & Error) -> void {
        //     // This code will run if the connection failed. Check Error to see what happened.
        // });

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

void UnrealWamp::onConnected()
{
    log("socket connected");
    m_session->init(TCHAR_TO_UTF8(*m_realm));
}

void UnrealWamp::onDisconnected()
{
    log("socket disconnected");
}

void UnrealWamp::handleTextMessage(const FString &message)
{
    m_session->handleMessage(TCHAR_TO_UTF8(*message));
}

void UnrealWamp::doCall(std::string procedure, Arguments arguments, ArgumentsKw argumentsKw, ResponseFunc& func)
{
    m_session->doCall(procedure, arguments, argumentsKw, func);
}

void UnrealWamp::doCall(std::string procedure, Arguments arguments, ArgumentsKw argumentsKw)
{
    ResponseFunc func = [](ResponseArg arg) {};
    m_session->doCall(procedure, arguments, argumentsKw, func);
}

void UnrealWamp::doSubscribe(std::string topic, EventFunc &func)
{
    m_session->doSubscribe(topic, func);
}

void UnrealWamp::doUnSubscribe(std::string topic)
{
    m_session->doUnsubscribe(topic);
}


void UnrealWamp::writeMessage(std::string message)
{
    // if we are using JSON we need to use txt message
    // otherwise binary messages
    if(m_socket->IsConnected())
    {
        m_socket->Send(UTF8_TO_TCHAR(message.c_str()));
    }
    else
    {
        log("Error: Cannot write message, socket not established: ");
        log(message.c_str());
    }
}


void UnrealWamp::onError(std::string error)
{
    log("onError"); //  << error;
}

void UnrealWamp::onEvent(std::string topic, Arguments args, ArgumentsKw kwargs)
{
    log("onEvent"); // << topic; // json(args).dump() << json(kwargs).dump();
}


void UnrealWamp::onJoin()
{
    log("on join");
}
