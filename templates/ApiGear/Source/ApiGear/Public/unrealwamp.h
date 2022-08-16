// Copyright Epic Games, Inc. All Rights Reserved
#pragma once

#include "wamp/types.h"
#include "WebSocketsModule.h"
#include "IWebSocket.h"

DECLARE_LOG_CATEGORY_EXTERN(LogApiGearWamp, Log, All);

using namespace ApiGear;

namespace ApiGear { namespace WAMP {
class Session;
} }

class APIGEAR_API UnrealWamp : public WAMP::IMessageWriter, public WAMP::ISessionListener, public WAMP::ILogger
{
public:
    static UnrealWamp* instance();
    UnrealWamp(UnrealWamp const&) = delete;
    void operator=(UnrealWamp const&) = delete;
    virtual ~UnrealWamp() override;

    void log(const FString &logMessage);
    void onConnected();
    void onDisconnected();
    void handleTextMessage(const FString& message);
    
    void doCall(std::string procedure, WAMP::Arguments arguments, WAMP::ArgumentsKw argumentsKw, WAMP::ResponseFunc& func);
    void doCall(std::string procedure, WAMP::Arguments arguments, WAMP::ArgumentsKw argumentsKw);
    void doSubscribe(std::string topic, WAMP::EventFunc &func);
    void doUnSubscribe(std::string topic);

    void info(std::string message) override;
    void debug(std::string message) override;
    void warning(std::string message) override;
    void error(std::string message) override;
    // IMessageWriter interface
public:
    virtual void writeMessage(std::string message) override;
private:
    explicit UnrealWamp();
    void open(const FString& url);

    static UnrealWamp* s_instance;
    TSharedPtr<IWebSocket> m_socket;
    ApiGear::WAMP::Session *m_session;
    bool m_loggingDisabled;
    FString m_serverURL;
    FString m_realm;

    // ISessionListener interface
public:
    void onError(std::string error) override;
    void onEvent(std::string topic, WAMP::Arguments args, WAMP::ArgumentsKw kwargs) override;

    // ISessionListener interface
public:
    void onJoin() override;
};
