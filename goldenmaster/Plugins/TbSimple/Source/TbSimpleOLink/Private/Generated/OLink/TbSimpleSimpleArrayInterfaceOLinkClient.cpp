/**
Copyright 2021 ApiGear UG
Copyright 2021 Epic Games, Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

////////////////////////////////
// WARNING AUTOGENERATED
// DO NOT MODIFY
///////////////////////////////

#include "TbSimple/Generated/OLink/TbSimpleSimpleArrayInterfaceOLinkClient.h"
#include "ApiGearSettings.h"
#include "ApiGearOLink.h"
#include "Async/Async.h"
#include "TbSimple/Generated/api/TbSimple.json.adapter.h"
#include "OLinkClientConnection.h"
#include "OLinkSink.h"
#include "Engine/Engine.h"
#include "ApiGear/Public/ApiGearConnectionsStore.h"
#include "Misc/DateTime.h"
#include "TbSimpleSettings.h"
THIRD_PARTY_INCLUDES_START
#include "olink/clientnode.h"
#include "olink/iobjectsink.h"
THIRD_PARTY_INCLUDES_END
#include "HAL/CriticalSection.h"

/**
   \brief data structure to hold the last sent property values
*/
struct TbSimpleSimpleArrayInterfacePropertiesData
{
	FCriticalSection PropBoolMutex;
	TArray<bool> PropBool{TArray<bool>()};
	FCriticalSection PropIntMutex;
	TArray<int32> PropInt{TArray<int32>()};
	FCriticalSection PropInt32Mutex;
	TArray<int32> PropInt32{TArray<int32>()};
	FCriticalSection PropInt64Mutex;
	TArray<int64> PropInt64{TArray<int64>()};
	FCriticalSection PropFloatMutex;
	TArray<float> PropFloat{TArray<float>()};
	FCriticalSection PropFloat32Mutex;
	TArray<float> PropFloat32{TArray<float>()};
	FCriticalSection PropFloat64Mutex;
	TArray<double> PropFloat64{TArray<double>()};
	FCriticalSection PropStringMutex;
	TArray<FString> PropString{TArray<FString>()};
	FCriticalSection PropReadOnlyStringMutex;
	FString PropReadOnlyString{FString()};
};
DEFINE_LOG_CATEGORY(LogTbSimpleSimpleArrayInterfaceOLinkClient);

UTbSimpleSimpleArrayInterfaceOLinkClient::UTbSimpleSimpleArrayInterfaceOLinkClient()
	: UAbstractTbSimpleSimpleArrayInterface()
	, _SentData(MakePimpl<TbSimpleSimpleArrayInterfacePropertiesData>())
{
	m_sink = std::make_shared<FOLinkSink>("tb.simple.SimpleArrayInterface");
}

UTbSimpleSimpleArrayInterfaceOLinkClient::UTbSimpleSimpleArrayInterfaceOLinkClient(FVTableHelper& Helper)
	: Super(Helper)
{
}
UTbSimpleSimpleArrayInterfaceOLinkClient::~UTbSimpleSimpleArrayInterfaceOLinkClient() = default;

void UTbSimpleSimpleArrayInterfaceOLinkClient::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	m_sink->setOnInitCallback([this]()
		{
		_SubscriptionStatusChanged.Broadcast(true);
		_SubscriptionStatusChangedBP.Broadcast(true);
	});
	m_sink->setOnReleaseCallback([this]()
		{
		_SubscriptionStatusChanged.Broadcast(false);
		_SubscriptionStatusChangedBP.Broadcast(false);
	});

	FOLinkSink::FPropertyChangedFunc PropertyChangedFunc = [this](const nlohmann::json& props)
	{
		this->applyState(props);
	};
	m_sink->setOnPropertyChangedCallback(PropertyChangedFunc);

	FOLinkSink::FSignalEmittedFunc SignalEmittedFunc = [this](const std::string& signalName, const nlohmann::json& args)
	{
		this->emitSignal(signalName, args);
	};
	m_sink->setOnSignalEmittedCallback(SignalEmittedFunc);

	check(GEngine);
	UTbSimpleSettings* settings = GetMutableDefault<UTbSimpleSettings>();

	UApiGearConnectionsStore* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionsStore>();

	TScriptInterface<IApiGearConnection> OLinkConnection = AGCM->GetConnection(settings->OLinkConnectionIdentifier);

	if (!OLinkConnection.GetInterface())
	{
		return;
	}
	UseConnection(OLinkConnection);
	OLinkConnection->Connect();
}

void UTbSimpleSimpleArrayInterfaceOLinkClient::Deinitialize()
{
	// tell the sink that we are gone and should not try to be invoked
	m_sink->resetOnPropertyChangedCallback();
	m_sink->resetOnSignalEmittedCallback();
	m_sink->resetOnInitCallback();
	m_sink->resetOnReleaseCallback();

	if (Connection.GetObject())
	{
		UOLinkClientConnection* UnrealOLinkConnection = Cast<UOLinkClientConnection>(Connection.GetObject());
		UnrealOLinkConnection->unlinkObjectSource(m_sink->olinkObjectName());
		UnrealOLinkConnection->node()->registry().removeSink(m_sink->olinkObjectName());
	}

	Super::Deinitialize();
}

void UTbSimpleSimpleArrayInterfaceOLinkClient::UseConnection(TScriptInterface<IApiGearConnection> InConnection)
{
	if (!InConnection.GetInterface())
	{
		UE_LOG(LogTbSimpleSimpleArrayInterfaceOLinkClient, Error, TEXT("The olink connection for the %s client does not implement the connection interface."), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return;
	}

	// only accept connections of type olink
	checkf(InConnection->GetConnectionProtocolIdentifier() == ApiGearOLinkProtocolIdentifier, TEXT("Cannot use connection - must be of type olink"));

	UOLinkClientConnection* UnrealOLinkConnection = nullptr;
	// remove old connection
	if (Connection.GetObject())
	{
		UnrealOLinkConnection = Cast<UOLinkClientConnection>(Connection.GetObject());
		UnrealOLinkConnection->unlinkObjectSource(m_sink->olinkObjectName());
		UnrealOLinkConnection->node()->registry().removeSink(m_sink->olinkObjectName());
		UnrealOLinkConnection = nullptr;
	}

	// set up new connection
	UnrealOLinkConnection = Cast<UOLinkClientConnection>(InConnection.GetObject());
	UnrealOLinkConnection->node()->registry().addSink(m_sink);
	UnrealOLinkConnection->linkObjectSource(m_sink->olinkObjectName());

	Connection = InConnection;
}

TArray<bool> UTbSimpleSimpleArrayInterfaceOLinkClient::GetPropBool() const
{
	return PropBool;
}

void UTbSimpleSimpleArrayInterfaceOLinkClient::SetPropBool(const TArray<bool>& InPropBool)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTbSimpleSimpleArrayInterfaceOLinkClient, Error, TEXT("%s has no node. Probably no valid connection or service. Are the ApiGear TbSimple plugin settings correct? Service set up correctly?"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetPropBool() == InPropBool)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	{
		FScopeLock Lock(&(_SentData->PropBoolMutex));
		if (_SentData->PropBool == InPropBool)
		{
			return;
		}
	}
	static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "propBool");
	m_sink->GetNode()->setRemoteProperty(memberId, InPropBool);
	FScopeLock Lock(&(_SentData->PropBoolMutex));
	_SentData->PropBool = InPropBool;
}

TArray<int32> UTbSimpleSimpleArrayInterfaceOLinkClient::GetPropInt() const
{
	return PropInt;
}

void UTbSimpleSimpleArrayInterfaceOLinkClient::SetPropInt(const TArray<int32>& InPropInt)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTbSimpleSimpleArrayInterfaceOLinkClient, Error, TEXT("%s has no node. Probably no valid connection or service. Are the ApiGear TbSimple plugin settings correct? Service set up correctly?"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetPropInt() == InPropInt)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	{
		FScopeLock Lock(&(_SentData->PropIntMutex));
		if (_SentData->PropInt == InPropInt)
		{
			return;
		}
	}
	static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "propInt");
	m_sink->GetNode()->setRemoteProperty(memberId, InPropInt);
	FScopeLock Lock(&(_SentData->PropIntMutex));
	_SentData->PropInt = InPropInt;
}

TArray<int32> UTbSimpleSimpleArrayInterfaceOLinkClient::GetPropInt32() const
{
	return PropInt32;
}

void UTbSimpleSimpleArrayInterfaceOLinkClient::SetPropInt32(const TArray<int32>& InPropInt32)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTbSimpleSimpleArrayInterfaceOLinkClient, Error, TEXT("%s has no node. Probably no valid connection or service. Are the ApiGear TbSimple plugin settings correct? Service set up correctly?"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetPropInt32() == InPropInt32)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	{
		FScopeLock Lock(&(_SentData->PropInt32Mutex));
		if (_SentData->PropInt32 == InPropInt32)
		{
			return;
		}
	}
	static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "propInt32");
	m_sink->GetNode()->setRemoteProperty(memberId, InPropInt32);
	FScopeLock Lock(&(_SentData->PropInt32Mutex));
	_SentData->PropInt32 = InPropInt32;
}

TArray<int64> UTbSimpleSimpleArrayInterfaceOLinkClient::GetPropInt64() const
{
	return PropInt64;
}

void UTbSimpleSimpleArrayInterfaceOLinkClient::SetPropInt64(const TArray<int64>& InPropInt64)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTbSimpleSimpleArrayInterfaceOLinkClient, Error, TEXT("%s has no node. Probably no valid connection or service. Are the ApiGear TbSimple plugin settings correct? Service set up correctly?"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetPropInt64() == InPropInt64)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	{
		FScopeLock Lock(&(_SentData->PropInt64Mutex));
		if (_SentData->PropInt64 == InPropInt64)
		{
			return;
		}
	}
	static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "propInt64");
	m_sink->GetNode()->setRemoteProperty(memberId, InPropInt64);
	FScopeLock Lock(&(_SentData->PropInt64Mutex));
	_SentData->PropInt64 = InPropInt64;
}

TArray<float> UTbSimpleSimpleArrayInterfaceOLinkClient::GetPropFloat() const
{
	return PropFloat;
}

void UTbSimpleSimpleArrayInterfaceOLinkClient::SetPropFloat(const TArray<float>& InPropFloat)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTbSimpleSimpleArrayInterfaceOLinkClient, Error, TEXT("%s has no node. Probably no valid connection or service. Are the ApiGear TbSimple plugin settings correct? Service set up correctly?"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetPropFloat() == InPropFloat)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	{
		FScopeLock Lock(&(_SentData->PropFloatMutex));
		if (_SentData->PropFloat == InPropFloat)
		{
			return;
		}
	}
	static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "propFloat");
	m_sink->GetNode()->setRemoteProperty(memberId, InPropFloat);
	FScopeLock Lock(&(_SentData->PropFloatMutex));
	_SentData->PropFloat = InPropFloat;
}

TArray<float> UTbSimpleSimpleArrayInterfaceOLinkClient::GetPropFloat32() const
{
	return PropFloat32;
}

void UTbSimpleSimpleArrayInterfaceOLinkClient::SetPropFloat32(const TArray<float>& InPropFloat32)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTbSimpleSimpleArrayInterfaceOLinkClient, Error, TEXT("%s has no node. Probably no valid connection or service. Are the ApiGear TbSimple plugin settings correct? Service set up correctly?"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetPropFloat32() == InPropFloat32)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	{
		FScopeLock Lock(&(_SentData->PropFloat32Mutex));
		if (_SentData->PropFloat32 == InPropFloat32)
		{
			return;
		}
	}
	static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "propFloat32");
	m_sink->GetNode()->setRemoteProperty(memberId, InPropFloat32);
	FScopeLock Lock(&(_SentData->PropFloat32Mutex));
	_SentData->PropFloat32 = InPropFloat32;
}

TArray<double> UTbSimpleSimpleArrayInterfaceOLinkClient::GetPropFloat64() const
{
	return PropFloat64;
}

void UTbSimpleSimpleArrayInterfaceOLinkClient::SetPropFloat64(const TArray<double>& InPropFloat64)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTbSimpleSimpleArrayInterfaceOLinkClient, Error, TEXT("%s has no node. Probably no valid connection or service. Are the ApiGear TbSimple plugin settings correct? Service set up correctly?"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetPropFloat64() == InPropFloat64)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	{
		FScopeLock Lock(&(_SentData->PropFloat64Mutex));
		if (_SentData->PropFloat64 == InPropFloat64)
		{
			return;
		}
	}
	static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "propFloat64");
	m_sink->GetNode()->setRemoteProperty(memberId, InPropFloat64);
	FScopeLock Lock(&(_SentData->PropFloat64Mutex));
	_SentData->PropFloat64 = InPropFloat64;
}

TArray<FString> UTbSimpleSimpleArrayInterfaceOLinkClient::GetPropString() const
{
	return PropString;
}

void UTbSimpleSimpleArrayInterfaceOLinkClient::SetPropString(const TArray<FString>& InPropString)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTbSimpleSimpleArrayInterfaceOLinkClient, Error, TEXT("%s has no node. Probably no valid connection or service. Are the ApiGear TbSimple plugin settings correct? Service set up correctly?"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetPropString() == InPropString)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	{
		FScopeLock Lock(&(_SentData->PropStringMutex));
		if (_SentData->PropString == InPropString)
		{
			return;
		}
	}
	static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "propString");
	m_sink->GetNode()->setRemoteProperty(memberId, InPropString);
	FScopeLock Lock(&(_SentData->PropStringMutex));
	_SentData->PropString = InPropString;
}

FString UTbSimpleSimpleArrayInterfaceOLinkClient::GetPropReadOnlyString() const
{
	return PropReadOnlyString;
}

TArray<bool> UTbSimpleSimpleArrayInterfaceOLinkClient::FuncBool(const TArray<bool>& ParamBool)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTbSimpleSimpleArrayInterfaceOLinkClient, Error, TEXT("%s has no node. Probably no valid connection or service. Are the ApiGear TbSimple plugin settings correct? Service set up correctly?"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));

		return TArray<bool>();
	}
	TPromise<TArray<bool>> Promise;
	Async(EAsyncExecution::ThreadPool,
		[ParamBool, &Promise, this]()
		{
		ApiGear::ObjectLink::InvokeReplyFunc GetSimpleArrayInterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
		{
			Promise.SetValue(arg.value.get<TArray<bool>>());
		};
		static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "funcBool");
		m_sink->GetNode()->invokeRemote(memberId, {ParamBool}, GetSimpleArrayInterfaceStateFunc);
	});

	return Promise.GetFuture().Get();
}

TArray<int32> UTbSimpleSimpleArrayInterfaceOLinkClient::FuncInt(const TArray<int32>& ParamInt)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTbSimpleSimpleArrayInterfaceOLinkClient, Error, TEXT("%s has no node. Probably no valid connection or service. Are the ApiGear TbSimple plugin settings correct? Service set up correctly?"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));

		return TArray<int32>();
	}
	TPromise<TArray<int32>> Promise;
	Async(EAsyncExecution::ThreadPool,
		[ParamInt, &Promise, this]()
		{
		ApiGear::ObjectLink::InvokeReplyFunc GetSimpleArrayInterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
		{
			Promise.SetValue(arg.value.get<TArray<int32>>());
		};
		static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "funcInt");
		m_sink->GetNode()->invokeRemote(memberId, {ParamInt}, GetSimpleArrayInterfaceStateFunc);
	});

	return Promise.GetFuture().Get();
}

TArray<int32> UTbSimpleSimpleArrayInterfaceOLinkClient::FuncInt32(const TArray<int32>& ParamInt32)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTbSimpleSimpleArrayInterfaceOLinkClient, Error, TEXT("%s has no node. Probably no valid connection or service. Are the ApiGear TbSimple plugin settings correct? Service set up correctly?"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));

		return TArray<int32>();
	}
	TPromise<TArray<int32>> Promise;
	Async(EAsyncExecution::ThreadPool,
		[ParamInt32, &Promise, this]()
		{
		ApiGear::ObjectLink::InvokeReplyFunc GetSimpleArrayInterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
		{
			Promise.SetValue(arg.value.get<TArray<int32>>());
		};
		static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "funcInt32");
		m_sink->GetNode()->invokeRemote(memberId, {ParamInt32}, GetSimpleArrayInterfaceStateFunc);
	});

	return Promise.GetFuture().Get();
}

TArray<int64> UTbSimpleSimpleArrayInterfaceOLinkClient::FuncInt64(const TArray<int64>& ParamInt64)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTbSimpleSimpleArrayInterfaceOLinkClient, Error, TEXT("%s has no node. Probably no valid connection or service. Are the ApiGear TbSimple plugin settings correct? Service set up correctly?"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));

		return TArray<int64>();
	}
	TPromise<TArray<int64>> Promise;
	Async(EAsyncExecution::ThreadPool,
		[ParamInt64, &Promise, this]()
		{
		ApiGear::ObjectLink::InvokeReplyFunc GetSimpleArrayInterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
		{
			Promise.SetValue(arg.value.get<TArray<int64>>());
		};
		static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "funcInt64");
		m_sink->GetNode()->invokeRemote(memberId, {ParamInt64}, GetSimpleArrayInterfaceStateFunc);
	});

	return Promise.GetFuture().Get();
}

TArray<float> UTbSimpleSimpleArrayInterfaceOLinkClient::FuncFloat(const TArray<float>& ParamFloat)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTbSimpleSimpleArrayInterfaceOLinkClient, Error, TEXT("%s has no node. Probably no valid connection or service. Are the ApiGear TbSimple plugin settings correct? Service set up correctly?"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));

		return TArray<float>();
	}
	TPromise<TArray<float>> Promise;
	Async(EAsyncExecution::ThreadPool,
		[ParamFloat, &Promise, this]()
		{
		ApiGear::ObjectLink::InvokeReplyFunc GetSimpleArrayInterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
		{
			Promise.SetValue(arg.value.get<TArray<float>>());
		};
		static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "funcFloat");
		m_sink->GetNode()->invokeRemote(memberId, {ParamFloat}, GetSimpleArrayInterfaceStateFunc);
	});

	return Promise.GetFuture().Get();
}

TArray<float> UTbSimpleSimpleArrayInterfaceOLinkClient::FuncFloat32(const TArray<float>& ParamFloat32)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTbSimpleSimpleArrayInterfaceOLinkClient, Error, TEXT("%s has no node. Probably no valid connection or service. Are the ApiGear TbSimple plugin settings correct? Service set up correctly?"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));

		return TArray<float>();
	}
	TPromise<TArray<float>> Promise;
	Async(EAsyncExecution::ThreadPool,
		[ParamFloat32, &Promise, this]()
		{
		ApiGear::ObjectLink::InvokeReplyFunc GetSimpleArrayInterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
		{
			Promise.SetValue(arg.value.get<TArray<float>>());
		};
		static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "funcFloat32");
		m_sink->GetNode()->invokeRemote(memberId, {ParamFloat32}, GetSimpleArrayInterfaceStateFunc);
	});

	return Promise.GetFuture().Get();
}

TArray<double> UTbSimpleSimpleArrayInterfaceOLinkClient::FuncFloat64(const TArray<double>& ParamFloat)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTbSimpleSimpleArrayInterfaceOLinkClient, Error, TEXT("%s has no node. Probably no valid connection or service. Are the ApiGear TbSimple plugin settings correct? Service set up correctly?"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));

		return TArray<double>();
	}
	TPromise<TArray<double>> Promise;
	Async(EAsyncExecution::ThreadPool,
		[ParamFloat, &Promise, this]()
		{
		ApiGear::ObjectLink::InvokeReplyFunc GetSimpleArrayInterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
		{
			Promise.SetValue(arg.value.get<TArray<double>>());
		};
		static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "funcFloat64");
		m_sink->GetNode()->invokeRemote(memberId, {ParamFloat}, GetSimpleArrayInterfaceStateFunc);
	});

	return Promise.GetFuture().Get();
}

TArray<FString> UTbSimpleSimpleArrayInterfaceOLinkClient::FuncString(const TArray<FString>& ParamString)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTbSimpleSimpleArrayInterfaceOLinkClient, Error, TEXT("%s has no node. Probably no valid connection or service. Are the ApiGear TbSimple plugin settings correct? Service set up correctly?"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));

		return TArray<FString>();
	}
	TPromise<TArray<FString>> Promise;
	Async(EAsyncExecution::ThreadPool,
		[ParamString, &Promise, this]()
		{
		ApiGear::ObjectLink::InvokeReplyFunc GetSimpleArrayInterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
		{
			Promise.SetValue(arg.value.get<TArray<FString>>());
		};
		static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "funcString");
		m_sink->GetNode()->invokeRemote(memberId, {ParamString}, GetSimpleArrayInterfaceStateFunc);
	});

	return Promise.GetFuture().Get();
}

bool UTbSimpleSimpleArrayInterfaceOLinkClient::_IsSubscribed() const
{
	return m_sink->IsReady();
}

void UTbSimpleSimpleArrayInterfaceOLinkClient::applyState(const nlohmann::json& fields)
{
	const bool bPropBoolChanged = fields.contains("propBool") && (PropBool != fields["propBool"].get<TArray<bool>>());
	if (bPropBoolChanged)
	{
		PropBool = fields["propBool"].get<TArray<bool>>();
		// reset sent data to the current state
		{
			FScopeLock Lock(&(_SentData->PropBoolMutex));
			_SentData->PropBool = PropBool;
		}
		_GetSignals()->BroadcastPropBoolChanged(PropBool);
	}

	const bool bPropIntChanged = fields.contains("propInt") && (PropInt != fields["propInt"].get<TArray<int32>>());
	if (bPropIntChanged)
	{
		PropInt = fields["propInt"].get<TArray<int32>>();
		// reset sent data to the current state
		{
			FScopeLock Lock(&(_SentData->PropIntMutex));
			_SentData->PropInt = PropInt;
		}
		_GetSignals()->BroadcastPropIntChanged(PropInt);
	}

	const bool bPropInt32Changed = fields.contains("propInt32") && (PropInt32 != fields["propInt32"].get<TArray<int32>>());
	if (bPropInt32Changed)
	{
		PropInt32 = fields["propInt32"].get<TArray<int32>>();
		// reset sent data to the current state
		{
			FScopeLock Lock(&(_SentData->PropInt32Mutex));
			_SentData->PropInt32 = PropInt32;
		}
		_GetSignals()->BroadcastPropInt32Changed(PropInt32);
	}

	const bool bPropInt64Changed = fields.contains("propInt64") && (PropInt64 != fields["propInt64"].get<TArray<int64>>());
	if (bPropInt64Changed)
	{
		PropInt64 = fields["propInt64"].get<TArray<int64>>();
		// reset sent data to the current state
		{
			FScopeLock Lock(&(_SentData->PropInt64Mutex));
			_SentData->PropInt64 = PropInt64;
		}
		_GetSignals()->BroadcastPropInt64Changed(PropInt64);
	}

	const bool bPropFloatChanged = fields.contains("propFloat") && (PropFloat != fields["propFloat"].get<TArray<float>>());
	if (bPropFloatChanged)
	{
		PropFloat = fields["propFloat"].get<TArray<float>>();
		// reset sent data to the current state
		{
			FScopeLock Lock(&(_SentData->PropFloatMutex));
			_SentData->PropFloat = PropFloat;
		}
		_GetSignals()->BroadcastPropFloatChanged(PropFloat);
	}

	const bool bPropFloat32Changed = fields.contains("propFloat32") && (PropFloat32 != fields["propFloat32"].get<TArray<float>>());
	if (bPropFloat32Changed)
	{
		PropFloat32 = fields["propFloat32"].get<TArray<float>>();
		// reset sent data to the current state
		{
			FScopeLock Lock(&(_SentData->PropFloat32Mutex));
			_SentData->PropFloat32 = PropFloat32;
		}
		_GetSignals()->BroadcastPropFloat32Changed(PropFloat32);
	}

	const bool bPropFloat64Changed = fields.contains("propFloat64") && (PropFloat64 != fields["propFloat64"].get<TArray<double>>());
	if (bPropFloat64Changed)
	{
		PropFloat64 = fields["propFloat64"].get<TArray<double>>();
		// reset sent data to the current state
		{
			FScopeLock Lock(&(_SentData->PropFloat64Mutex));
			_SentData->PropFloat64 = PropFloat64;
		}
		_GetSignals()->BroadcastPropFloat64Changed(PropFloat64);
	}

	const bool bPropStringChanged = fields.contains("propString") && (PropString != fields["propString"].get<TArray<FString>>());
	if (bPropStringChanged)
	{
		PropString = fields["propString"].get<TArray<FString>>();
		// reset sent data to the current state
		{
			FScopeLock Lock(&(_SentData->PropStringMutex));
			_SentData->PropString = PropString;
		}
		_GetSignals()->BroadcastPropStringChanged(PropString);
	}

	const bool bPropReadOnlyStringChanged = fields.contains("propReadOnlyString") && (PropReadOnlyString != fields["propReadOnlyString"].get<FString>());
	if (bPropReadOnlyStringChanged)
	{
		PropReadOnlyString = fields["propReadOnlyString"].get<FString>();
		// reset sent data to the current state
		{
			FScopeLock Lock(&(_SentData->PropReadOnlyStringMutex));
			_SentData->PropReadOnlyString = PropReadOnlyString;
		}
		_GetSignals()->BroadcastPropReadOnlyStringChanged(PropReadOnlyString);
	}
}

void UTbSimpleSimpleArrayInterfaceOLinkClient::emitSignal(const std::string& signalName, const nlohmann::json& args)
{
	if (signalName == "sigBool")
	{
		const TArray<bool>& outParamBool = args[0].get<TArray<bool>>();
		_GetSignals()->BroadcastSigBoolSignal(outParamBool);
		return;
	}

	if (signalName == "sigInt")
	{
		const TArray<int32>& outParamInt = args[0].get<TArray<int32>>();
		_GetSignals()->BroadcastSigIntSignal(outParamInt);
		return;
	}

	if (signalName == "sigInt32")
	{
		const TArray<int32>& outParamInt32 = args[0].get<TArray<int32>>();
		_GetSignals()->BroadcastSigInt32Signal(outParamInt32);
		return;
	}

	if (signalName == "sigInt64")
	{
		const TArray<int64>& outParamInt64 = args[0].get<TArray<int64>>();
		_GetSignals()->BroadcastSigInt64Signal(outParamInt64);
		return;
	}

	if (signalName == "sigFloat")
	{
		const TArray<float>& outParamFloat = args[0].get<TArray<float>>();
		_GetSignals()->BroadcastSigFloatSignal(outParamFloat);
		return;
	}

	if (signalName == "sigFloat32")
	{
		const TArray<float>& outParamFloa32 = args[0].get<TArray<float>>();
		_GetSignals()->BroadcastSigFloat32Signal(outParamFloa32);
		return;
	}

	if (signalName == "sigFloat64")
	{
		const TArray<double>& outParamFloat64 = args[0].get<TArray<double>>();
		_GetSignals()->BroadcastSigFloat64Signal(outParamFloat64);
		return;
	}

	if (signalName == "sigString")
	{
		const TArray<FString>& outParamString = args[0].get<TArray<FString>>();
		_GetSignals()->BroadcastSigStringSignal(outParamString);
		return;
	}
}
