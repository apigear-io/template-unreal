// Copyright Epic Games, Inc. All Rights Reserved
#pragma once

#include "ApiGearConnection.h"
#include "jsonrpc/types.h"
#include "WebSocketsModule.h"
#include "IWebSocket.h"
#include "unrealsimulation.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogApiGearSimulation, Log, All);

using namespace ApiGear;

namespace ApiGear
{
namespace JSONRPC
{
class RpcProtocol;
}
} // namespace ApiGear

UCLASS(NotBlueprintType)
class APIGEAR_API UUnrealSimulation : public UAbstractApiGearConnection, public JSONRPC::IMessageWriter, public JSONRPC::IRpcProtocolListener, public JSONRPC::ILogger
{
	GENERATED_BODY()
public:
	explicit UUnrealSimulation(const FObjectInitializer& ObjectInitializer);
	virtual ~UUnrealSimulation() override;

	void doFetchState(std::string service, JSONRPC::CallResponseFunc& func);
	void doCall(std::string service, std::string operation, JSONRPC::Params args, JSONRPC::CallResponseFunc& func);
	void doCall(std::string service, std::string operation, JSONRPC::Params args);
	void onNotify(std::string method, JSONRPC::NotifyRequestFunc& func);
	void onNotifyState(std::string service, JSONRPC::NotifyRequestFunc& func);
	void notify(JSONRPC::NotifyRequestArg args);

	void log(const FString& logMessage);
	void handleTextMessage(const FString& message);

	void info(std::string message) override;
	void debug(std::string message) override;
	void warning(std::string message) override;
	void error(std::string message) override;
	// IMessageWriter interface

	// UAbstractApiGearConnection
	void Connect() override;
	void Disconnect() override;
	bool IsConnected() override;
	void OnConnected() override;
	void OnDisconnected(bool bReconnect) override;

public:
	virtual void writeMessage(std::string message) override;
	void onNotify(std::string method, JSONRPC::Params params) override;
	void RemoveOnNotify(std::string method);
	void RemoveOnNotifyState(std::string service);
	void RegisterSignalCallback(JSONRPC::NotifyRequestArg args);

private:
	explicit UUnrealSimulation();
	void open(const FString& url);

	TSharedPtr<IWebSocket> m_socket;
	ApiGear::JSONRPC::RpcProtocol* m_session;
	bool m_loggingDisabled;
	FString m_serverURL;
	std::map<std::string, JSONRPC::NotifyRequestFunc> m_notifyRegistry;
	std::map<std::string, JSONRPC::NotifyRequestFunc> m_notifyStateRegistry;
};
