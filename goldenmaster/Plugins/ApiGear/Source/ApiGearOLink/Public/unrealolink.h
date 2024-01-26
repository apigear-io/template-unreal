#pragma once

#include "AbstractApiGearConnection.h"
#include "apigearolink.h"
THIRD_PARTY_INCLUDES_START
#include "olink/clientnode.h"
#include "olink/clientregistry.h"
THIRD_PARTY_INCLUDES_END
#include "WebSocketsModule.h"
#include "IWebSocket.h"
#include "Containers/Queue.h"
#include "HAL/CriticalSection.h"
#include "ApiGearTicker.h"
#include "unrealolink.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogApiGearOLink, Log, All);

class APIGEAROLINK_API OLinkFactory
{
public:
	static TScriptInterface<IApiGearConnection> Create(UObject* Outer, FString UniqueConnectionIdentifier);
};

UCLASS(BlueprintType, Displayname = "ApiGear ObjectLink Connection", Category = "ApiGear|Connection")
class APIGEAROLINK_API UUnrealOLink final : public UAbstractApiGearConnection
{
	GENERATED_BODY()
public:
	explicit UUnrealOLink(const FObjectInitializer& ObjectInitializer);
	virtual ~UUnrealOLink();

	void Configure(FString InServerURL, bool bInAutoReconnectEnabled) override;

	void log(const FString& logMessage);
	void handleTextMessage(const std::string& message);

	void linkObjectSource(const std::string& name);
	void unlinkObjectSource(const std::string& name);

	// UAbstractApiGearConnection
	void Connect_Implementation() final;
	void Disconnect_Implementation() final;
	void OnConnected_Implementation() final;
	void OnDisconnected_Implementation(bool bReconnect) final;
	bool IsConnected() override;

	/** Returns the endpoint identifier for this connection, e.g. ip:port or #connID */
	FString GetUniqueEndpointIdentifier() const override;
	FString GetConnectionProtocolIdentifier() const override
	{
		return ApiGearOLinkProtocolIdentifier;
	};

	std::shared_ptr<ApiGear::ObjectLink::ClientNode> node()
	{
		return m_node;
	};

	FString GetServerURL() const override
	{
		return m_serverURL;
	};

private:
	bool bInitialized = false;
	void open(const FString& url);
	/*
	* Helper method for sending messages, should be used from one thread, here achieved with scheduling task to main thread.
	* see m_processMessageTaskTimerHandle
	*/
	void processMessages();
	/*
	* Sends queued messages
	* Uses m_flushMessagesMutex, to ensure it called only once at one time.
	* It is not thread safe function - uses a m_socket and m_queue which are not guarded separately across the UUnrealOLink
	*/
	void flushMessages();

	TArray<std::string> ListLinkedObjects;

	DEFINE_LOG_CATEGORY(LogApiGearOLink);
	
	/// @brief delegate handle for scheduled process message task
	ApiGear::FDelegateHandle m_processMessageTaskTimerHandle;

	TSharedPtr<IWebSocket> m_socket;
	FString m_serverURL;
	ApiGear::ObjectLink::ClientRegistry m_registry;
	std::shared_ptr<ApiGear::ObjectLink::ClientNode> m_node;
	TQueue<std::string, EQueueMode::Mpsc> m_queue;
	// Mutex for flushMessages().
	FCriticalSection m_flushMessagesMutex;
};
