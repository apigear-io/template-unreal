#pragma once

#include "olink/core/types.h"
#include "olink/clientnode.h"
#include "WebSocketsModule.h"
#include "IWebSocket.h"
#include <queue>
#include <mutex>

DECLARE_LOG_CATEGORY_EXTERN(LogApiGearOLink, Log, All);


using namespace ApiGear;

class APIGEAR_API UnrealOLink
{
    DECLARE_MULTICAST_DELEGATE_OneParam(FApiGearConnectionIsConnectedDelegate, bool);

public:
    explicit UnrealOLink();
    UnrealOLink(UnrealOLink const&) = delete;
    void operator=(UnrealOLink const&) = delete;
    virtual ~UnrealOLink();

    void connect();
    void disconnect();
    bool isConnected();
    FApiGearConnectionIsConnectedDelegate IsConnectedChanged;

    void log(const FString &logMessage);
    void onConnected();
    void onDisconnected();
    void handleTextMessage(const FString& message);

    void linkObjectSource(std::string name);

private:
    void open(const FString& url);
    void processMessages();

    TSharedPtr<IWebSocket> m_socket;
    bool m_loggingDisabled;
    FString m_serverURL;
    ObjectLink::ClientNode m_node;
    std::queue<std::string> m_queue;
    std::mutex m_queue_mutex;
};
