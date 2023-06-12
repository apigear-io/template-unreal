#include "unrealolinksink.h"
THIRD_PARTY_INCLUDES_START
#include "olink/clientregistry.h"
THIRD_PARTY_INCLUDES_END

std::string FUnrealOLinkSink::olinkObjectName()
{
	return m_olinkObjectName;
}

FUnrealOLinkSink::FUnrealOLinkSink(const std::string& olinkObjectName)
	: m_olinkObjectName(olinkObjectName)
{
}

void FUnrealOLinkSink::olinkOnSignal(const std::string& signalId, const nlohmann::json& args)
{
	const std::string MemberName = ApiGear::ObjectLink::Name::getMemberName(signalId);
	if (SignalEmittedFunc)
	{
		SignalEmittedFunc(MemberName, args);
	}
}

void FUnrealOLinkSink::olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value)
{
	const std::string MemberName = ApiGear::ObjectLink::Name::getMemberName(propertyId);
	if (PropertyChangedFunc)
	{
		PropertyChangedFunc({{MemberName, value}});
	}
}

void FUnrealOLinkSink::olinkOnInit(const std::string& objectId, const nlohmann::json& props, ApiGear::ObjectLink::IClientNode* node)
{
	m_node = node;
	if (PropertyChangedFunc)
	{
		PropertyChangedFunc(props);
	}
}

void FUnrealOLinkSink::olinkOnRelease()
{
	m_node = nullptr;
}

void FUnrealOLinkSink::setOnPropertyChangedCallback(FPropertyChangedFunc func)
{
	PropertyChangedFunc = func;
}

void FUnrealOLinkSink::setOnSignalEmittedCallback(FSignalEmittedFunc func)
{
	SignalEmittedFunc = func;
}

// reset callbacks
void FUnrealOLinkSink::resetOnPropertyChangedCallback()
{
	PropertyChangedFunc = nullptr;
}

void FUnrealOLinkSink::resetOnSignalEmittedCallback()
{
	SignalEmittedFunc = nullptr;
}

ApiGear::ObjectLink::IClientNode* FUnrealOLinkSink::GetNode() const
{
	return m_node;
}

bool FUnrealOLinkSink::IsReady() const
{
	return m_node != nullptr;
}
