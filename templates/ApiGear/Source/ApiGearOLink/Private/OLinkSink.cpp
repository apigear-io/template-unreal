#include "OLinkSink.h"
#include "Misc/ScopeLock.h"
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
	FSignalEmittedFunc LocalFunc;
	{
		FScopeLock Lock(&CallbackMutex);
		LocalFunc = SignalEmittedFunc;
	}
	if (LocalFunc)
	{
		LocalFunc(MemberName, args);
	}
}

void FOLinkSink::olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value)
{
	const std::string MemberName = ApiGear::ObjectLink::Name::getMemberName(propertyId);
	FPropertyChangedFunc LocalFunc;
	{
		FScopeLock Lock(&CallbackMutex);
		LocalFunc = PropertyChangedFunc;
	}
	if (LocalFunc)
	{
		LocalFunc({{MemberName, value}});
	}
}

void FOLinkSink::olinkOnInit(const std::string& objectId, const nlohmann::json& props, ApiGear::ObjectLink::IClientNode* node)
{
	m_node = node;
	FInitializedFromSourceCallback LocalInitFunc;
	FPropertyChangedFunc LocalPropFunc;
	{
		FScopeLock Lock(&CallbackMutex);
		LocalInitFunc = OnInitCallback;
		LocalPropFunc = PropertyChangedFunc;
	}
	if (LocalInitFunc)
	{
		LocalInitFunc();
	}
	if (LocalPropFunc)
	{
		LocalPropFunc(props);
	}
}

void FOLinkSink::olinkOnRelease()
{
	FSourceConnectionReleasedCallback LocalFunc;
	{
		FScopeLock Lock(&CallbackMutex);
		LocalFunc = OnReleaseCallback;
	}
	if (LocalFunc)
	{
		LocalFunc();
	}
	m_node = nullptr;
}

void FOLinkSink::setOnPropertyChangedCallback(FPropertyChangedFunc func)
{
	FScopeLock Lock(&CallbackMutex);
	PropertyChangedFunc = func;
}

void FOLinkSink::setOnSignalEmittedCallback(FSignalEmittedFunc func)
{
	FScopeLock Lock(&CallbackMutex);
	SignalEmittedFunc = func;
}

void FOLinkSink::setOnInitCallback(FInitializedFromSourceCallback func)
{
	FScopeLock Lock(&CallbackMutex);
	OnInitCallback = func;
}

void FOLinkSink::setOnReleaseCallback(FSourceConnectionReleasedCallback func)
{
	FScopeLock Lock(&CallbackMutex);
	OnReleaseCallback = func;
}

// reset callbacks
void FOLinkSink::resetOnInitCallback()
{
	FScopeLock Lock(&CallbackMutex);
	OnInitCallback = nullptr;
}

void FOLinkSink::resetOnReleaseCallback()
{
	FScopeLock Lock(&CallbackMutex);
	OnReleaseCallback = nullptr;
}

void FOLinkSink::resetOnPropertyChangedCallback()
{
	FScopeLock Lock(&CallbackMutex);
	PropertyChangedFunc = nullptr;
}

void FOLinkSink::resetOnSignalEmittedCallback()
{
	FScopeLock Lock(&CallbackMutex);
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
