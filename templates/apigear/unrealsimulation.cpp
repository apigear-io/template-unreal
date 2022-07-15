// Copyright Epic Games, Inc. All Rights Reserved
#include "unrealsimulation.h"
#include "jsonrpc/rpcprotocol.h"

using namespace ApiGear::JSONRPC;

DEFINE_LOG_CATEGORY(LogApiGearSimulation);

UUnrealSimulation::UUnrealSimulation(const FObjectInitializer& ObjectInitializer)
    : UAbstractApiGearConnection(ObjectInitializer)
    , m_socket(nullptr)
    , m_session(new RpcProtocol(this, this, this, MessageFormat::JSON))
    , m_loggingDisabled(false)
{
    UApiGearSettings* settings = GetMutableDefault<UApiGearSettings>();
    m_serverURL = settings->Simulation_URL;
    m_loggingDisabled = !settings->Simulation_EnableDebugLog;

    log("Simulation instantiated");
}

UUnrealSimulation::~UUnrealSimulation()
{
    delete m_session;
}

void UUnrealSimulation::log(const FString &logMessage)
{
    if(!m_loggingDisabled)
    {
        UE_LOG(LogApiGearSimulation, Display, TEXT("%s"), *logMessage);
    }
}

void UUnrealSimulation::info(std::string message)
{
    if(!m_loggingDisabled)
    {
        UE_LOG(LogApiGearSimulation, Verbose, TEXT("%s"), UTF8_TO_TCHAR(message.c_str()));
    }
}

void UUnrealSimulation::debug(std::string message)
{
    if(!m_loggingDisabled)
    {
        UE_LOG(LogApiGearSimulation, Display, TEXT("%s"), UTF8_TO_TCHAR(message.c_str()));
    }
}

void UUnrealSimulation::warning(std::string message)
{
    if(!m_loggingDisabled)
    {
        UE_LOG(LogApiGearSimulation, Warning, TEXT("%s"), UTF8_TO_TCHAR(message.c_str()));
    }
}

void UUnrealSimulation::error(std::string message)
{
    if(!m_loggingDisabled)
    {
        UE_LOG(LogApiGearSimulation, Error, TEXT("%s"), UTF8_TO_TCHAR(message.c_str()));
    }
}

void UUnrealSimulation::open(const FString& url)
{
    const FString ServerProtocol = TEXT(""); 
    if(!m_socket) {
        if(!FModuleManager::Get().IsModuleLoaded("WebSockets"))
        {
            FModuleManager::Get().LoadModule("WebSockets");
        }
        m_socket = FWebSocketsModule::Get().CreateWebSocket(url, ServerProtocol);

        m_socket->OnConnected().AddLambda([this]() -> void {
            OnConnected();
        });

        m_socket->OnConnectionError().AddLambda([this](const FString & Error) -> void {
            // This code will run if the connection failed. Check Error to see what happened.
            log(FString::Printf(TEXT("connection error: %s"), *Error));
            UApiGearSettings* settings = GetMutableDefault<UApiGearSettings>();
            UAbstractApiGearConnection::OnDisconnected(settings->Simulation_AutoReconnectEnabled);
        });

        m_socket->OnClosed().AddLambda([this](int32 StatusCode, const FString& Reason, bool bWasClean) -> void {
            (void) StatusCode;
            (void) Reason;
            (void) bWasClean;
            UE_LOG(LogApiGearSimulation, Display, TEXT("status: %d, reason: %s, clean: %d"), StatusCode, *Reason, bWasClean);

            UApiGearSettings* settings = GetMutableDefault<UApiGearSettings>();
            bool bReconnect = settings->Simulation_AutoReconnectEnabled;

            // 1000 == we closed the connection -> do not reconnect
            if (StatusCode == 1000)
            {
                bReconnect = false;
            }
            OnDisconnected(bReconnect);
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

void UUnrealSimulation::Connect()
{
    UAbstractApiGearConnection::Connect();
    
    UApiGearSettings* settings = GetMutableDefault<UApiGearSettings>();
    m_serverURL = settings->Simulation_URL;
    m_loggingDisabled = !settings->Simulation_EnableDebugLog;

    if (!IsConnected()) 
    {
        log(m_serverURL);
        
        open(m_serverURL);
    }
}

void UUnrealSimulation::Disconnect()
{
    if(GetConnectionState() == EApiGearConnectionState::Connecting)
    {
        UAbstractApiGearConnection::StopReconnecting();
    }

    if(!IsConnected() || GetConnectionState() == EApiGearConnectionState::Connecting)
    {
        return;
    }

    m_socket->Close();
}

bool UUnrealSimulation::IsConnected()
{
    if(m_socket && m_socket->IsConnected())
    {
        return true;
    }
    return false;
}

void UUnrealSimulation::OnConnected()
{
    log("socket connected");
    // m_session->init(TCHAR_TO_UTF8(*m_realm));
    UAbstractApiGearConnection::OnConnected();
}

void UUnrealSimulation::OnDisconnected(bool bReconnect)
{
    log("socket disconnected");
    UAbstractApiGearConnection::OnDisconnected(bReconnect);
}

void UUnrealSimulation::handleTextMessage(const FString &message)
{
    m_session->handleMessage(TCHAR_TO_UTF8(*message));
}

void UUnrealSimulation::doFetchState(string service, CallResponseFunc &func)
{
    Params params;
    params["service"] = service;
    m_session->doCall("simu.state", params, func);
}

void UUnrealSimulation::doCall(std::string service, std::string operation, JSONRPC::Params args, JSONRPC::CallResponseFunc& func)
{
    Params params;
    params["service"] = service;
    params["operation"] = operation;
    params["params"] = args;
    m_session->doCall("simu.call", params, func);
}

void UUnrealSimulation::doCall(std::string service, std::string operation, JSONRPC::Params args)
{
    JSONRPC::CallResponseFunc func = [](JSONRPC::CallResponseArg arg) {};
    Params params;
    params["service"] = service;
    params["operation"] = operation;
    params["params"] = args;
    m_session->doCall("simu.call", params, func);
}

void UUnrealSimulation::RegisterSignalCallback(JSONRPC::NotifyRequestArg args)
{
    std::string signal = args.params["service"].get<std::string>() + "#" + args.params["signal"].get<std::string>();
    if(m_notifyRegistry.count(signal) == 1)
    {
        const NotifyRequestFunc& func = m_notifyRegistry[signal];
        NotifyRequestArg arg;
        arg.params = args.params["params"].get<Params>();
        func(arg);
    }
    else
    {
        error("Unreal simulation no notification registered for " + signal);
    }
}

void UUnrealSimulation::onNotify(string method, JSONRPC::NotifyRequestFunc &func)
{
    // in case we haven't registered our simulation signal callback, we do it on first onNotify
    if(m_notifyRegistry.empty())
    {
        NotifyRequestFunc notificationFunction{ std::bind(&UUnrealSimulation::RegisterSignalCallback, this, std::placeholders::_1) };
        m_session->onNotify("simu.signal", notificationFunction);
    }
    m_notifyRegistry[method] = func;
}

void UUnrealSimulation::onNotifyState(std::string service, JSONRPC::NotifyRequestFunc &func)
{
    // in case we haven't registered our simulation state callback, we do it on first onNotify
    if(m_notifyStateRegistry.empty()) {
        NotifyRequestFunc notifyFunc = [this](NotifyRequestArg args) {
            std::string service = args.params["service"].get<std::string>();
            if(m_notifyStateRegistry.count(service) == 1) {
                const NotifyRequestFunc& func = m_notifyStateRegistry[service];
                NotifyRequestArg arg;
                arg.params = args.params["params"].get<Params>();
                func(arg);
            } else {
                error("simulation no notification registered for state of " + service);
            }
        };
        m_session->onNotify("simu.state", notifyFunc);
    }
    m_notifyStateRegistry[service] = func;
}

void UUnrealSimulation::RemoveOnNotify(std::string method)
{
    m_notifyRegistry.erase(method);
}

void UUnrealSimulation::RemoveOnNotifyState(std::string service)
{
    m_notifyStateRegistry.erase(service);
}

void UUnrealSimulation::writeMessage(std::string message)
{
    // if we are using JSON we need to use txt message
    // otherwise binary messages
    if(IsConnected())
    {
        m_socket->Send(UTF8_TO_TCHAR(message.c_str()));
    }
    else
    {
        log("Error: Cannot write message, socket not established: ");
        log(message.c_str());
    }
}

// void UUnrealSimulation::onError(std::string error)
// {
//     log("onError"); //  << error;
// }

// void UUnrealSimulation::onEvent(std::string topic, Arguments args, ArgumentsKw kwargs)
// {
//     log("onEvent"); // << topic; // json(args).dump() << json(kwargs).dump();
// }

// void UUnrealSimulation::onJoin()
// {
//     log("on join");
// }

void UUnrealSimulation::onNotify(string method, Params params)
{
    // if(m_notifyRegistry.count(method) == 1)
    // {
    //     const NotifyRequestFunc& func = m_notifyRegistry[method];
    //     NotifyRequestArg arg;
    //     arg.params = params;
    //     func(arg);
    // }
    // else
    // {
        error("DEADEND - ignore - Unreal simulation no notification registered for " + method);
    // }
}

void UUnrealSimulation::notify(NotifyRequestArg args)
{
}