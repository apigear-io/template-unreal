#pragma once

#include "Templates/Function.h"
THIRD_PARTY_INCLUDES_START
#include "olink/iclientnode.h"
#include "olink/iobjectsink.h"
THIRD_PARTY_INCLUDES_END

class APIGEAROLINK_API FUnrealOLinkSink : public ApiGear::ObjectLink::IObjectSink
{
public:
	FUnrealOLinkSink(const std::string& olinkObjectName);

	// olink sink interface
	std::string olinkObjectName() override;
	void olinkOnSignal(const std::string& signalId, const nlohmann::json& args) override;
	void olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value) override;
	void olinkOnInit(const std::string& objectId, const nlohmann::json& props, ApiGear::ObjectLink::IClientNode* node) override;
	void olinkOnRelease() override;

	/** A type of function for handling property message*/
	using FPropertyChangedFunc = TFunction<void(const nlohmann::json& props)>;

	/** A type of function for handling signal message*/
	using FSignalEmittedFunc = TFunction<void(const std::string& signalName, const nlohmann::json& args)>;

	// set callbacks
	void setOnPropertyChangedCallback(FPropertyChangedFunc func);
	void setOnSignalEmittedCallback(FSignalEmittedFunc func);

	// reset callbacks
	void resetOnPropertyChangedCallback();
	void resetOnSignalEmittedCallback();

	ApiGear::ObjectLink::IClientNode* GetNode() const;
	bool IsReady() const;

private:
	ApiGear::ObjectLink::IClientNode* m_node{nullptr};
	const std::string m_olinkObjectName;

	// holds function which will be called on changed properties
	FPropertyChangedFunc PropertyChangedFunc;

	// holds function which will be called on emitted signals
	FSignalEmittedFunc SignalEmittedFunc;
};
