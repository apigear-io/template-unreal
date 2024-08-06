#include "OLinkSink.h"
THIRD_PARTY_INCLUDES_START
#include "olink/clientregistry.h"
THIRD_PARTY_INCLUDES_END

std::string FOLinkSink::olinkObjectName()
{
	return m_olinkObjectName;
}

FOLinkSink::FOLinkSink(const std::string& olinkObjectName)
	: m_olinkObjectName(olinkObjectName)
{
}

void FOLinkSink::olinkOnSignal(const std::string& signalId, const nlohmann::json& args)
{
	const std::string MemberName = ApiGear::ObjectLink::Name::getMemberName(signalId);
	if (SignalEmittedFunc)
	{
		SignalEmittedFunc(MemberName, args);
	}
}

void FOLinkSink::olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value)
{
	const std::string MemberName = ApiGear::ObjectLink::Name::getMemberName(propertyId);
	if (PropertyChangedFunc)
	{
		PropertyChangedFunc({{MemberName, value}});
	}
}

void FOLinkSink::olinkOnInit(const std::string& objectId, const nlohmann::json& props, ApiGear::ObjectLink::IClientNode* node)
{
	m_node = node;
	if (OnInitCallback)
	{
		OnInitCallback();
	}

	if (PropertyChangedFunc)
	{
		PropertyChangedFunc(props);
	}
}

void FOLinkSink::olinkOnRelease()
{
	if (OnReleaseCallback)
	{
		OnReleaseCallback();
	}
	m_node = nullptr;
}

void FOLinkSink::setOnPropertyChangedCallback(FPropertyChangedFunc func)
{
	PropertyChangedFunc = func;
}

void FOLinkSink::setOnSignalEmittedCallback(FSignalEmittedFunc func)
{
	SignalEmittedFunc = func;
}

void FOLinkSink::setOnInitCallback(FInitializedFromSourceCallback func)
{
	OnInitCallback = func;
}

void FOLinkSink::setOnReleaseCallback(FSourceConnectionReleasedCallback func)
{
	OnReleaseCallback = func;
}

// reset callbacks
void FOLinkSink::resetOnInitCallback()
{
	OnInitCallback = nullptr;
}

void FOLinkSink::resetOnReleaseCallback()
{
	OnReleaseCallback = nullptr;
}

void FOLinkSink::resetOnPropertyChangedCallback()
{
	PropertyChangedFunc = nullptr;
}

void FOLinkSink::resetOnSignalEmittedCallback()
{
	SignalEmittedFunc = nullptr;
}

ApiGear::ObjectLink::IClientNode* FOLinkSink::GetNode() const
{
	return m_node;
}

bool FOLinkSink::IsReady() const
{
	return m_node != nullptr;
}
