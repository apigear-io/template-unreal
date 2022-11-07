#pragma once

#include "ApiGearConnection.h"
THIRD_PARTY_INCLUDES_START
#include "olink/clientnode.h"
#include "olink/clientregistry.h"
THIRD_PARTY_INCLUDES_END
#include "WebSocketsModule.h"
#include "IWebSocket.h"
#include <queue>
#include <mutex>
#include "unrealolink.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogApiGearOLink, Log, All);

using namespace ApiGear;

UCLASS(NotBlueprintType)
class APIGEAR_API UUnrealOLink : public UAbstractApiGearConnection
{
	GENERATED_BODY()
public:
	explicit UUnrealOLink(const FObjectInitializer& ObjectInitializer);
	virtual ~UUnrealOLink();

	void log(const FString& logMessage);
	void handleTextMessage(const FString& message);

	void linkObjectSource(const std::string& name);
	void unlinkObjectSource(const std::string& name);

	// UAbstractApiGearConnection
	void Connect() override;
	void Disconnect() override;
	bool IsConnected() override;
	void OnConnected() override;
	void OnDisconnected(bool bReconnect) override;

	std::shared_ptr<ApiGear::ObjectLink::ClientNode> node()
	{
		return m_node;
	};

private:
	void open(const FString& url);
	void processMessages();

	TArray<std::string> ListLinkedObjects;

	TSharedPtr<IWebSocket> m_socket;
	bool m_loggingDisabled;
	FString m_serverURL;
	ApiGear::ObjectLink::ClientRegistry m_registry;
	std::shared_ptr<ApiGear::ObjectLink::ClientNode> m_node;
	std::queue<std::string> m_queue;
	std::mutex m_queue_mutex;
};
