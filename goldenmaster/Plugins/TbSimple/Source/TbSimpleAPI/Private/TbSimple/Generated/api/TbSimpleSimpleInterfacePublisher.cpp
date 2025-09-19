
#include "TbSimple/Generated/api/TbSimpleSimpleInterfaceInterface.h"
void UTbSimpleSimpleInterfacePublisher::BroadcastSigBoolSignal(bool bParamBool)
{
	OnSigBoolSignal.Broadcast(bParamBool);
	OnSigBoolSignalBP.Broadcast(bParamBool);

	TArray<TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnSigBoolSignal(Obj, bParamBool);
		}
	}
}

void UTbSimpleSimpleInterfacePublisher::BroadcastSigIntSignal(int32 ParamInt)
{
	OnSigIntSignal.Broadcast(ParamInt);
	OnSigIntSignalBP.Broadcast(ParamInt);

	TArray<TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnSigIntSignal(Obj, ParamInt);
		}
	}
}

void UTbSimpleSimpleInterfacePublisher::BroadcastSigInt32Signal(int32 ParamInt32)
{
	OnSigInt32Signal.Broadcast(ParamInt32);
	OnSigInt32SignalBP.Broadcast(ParamInt32);

	TArray<TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnSigInt32Signal(Obj, ParamInt32);
		}
	}
}

void UTbSimpleSimpleInterfacePublisher::BroadcastSigInt64Signal(int64 ParamInt64)
{
	OnSigInt64Signal.Broadcast(ParamInt64);
	OnSigInt64SignalBP.Broadcast(ParamInt64);

	TArray<TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnSigInt64Signal(Obj, ParamInt64);
		}
	}
}

void UTbSimpleSimpleInterfacePublisher::BroadcastSigFloatSignal(float ParamFloat)
{
	OnSigFloatSignal.Broadcast(ParamFloat);
	OnSigFloatSignalBP.Broadcast(ParamFloat);

	TArray<TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnSigFloatSignal(Obj, ParamFloat);
		}
	}
}

void UTbSimpleSimpleInterfacePublisher::BroadcastSigFloat32Signal(float ParamFloat32)
{
	OnSigFloat32Signal.Broadcast(ParamFloat32);
	OnSigFloat32SignalBP.Broadcast(ParamFloat32);

	TArray<TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnSigFloat32Signal(Obj, ParamFloat32);
		}
	}
}

void UTbSimpleSimpleInterfacePublisher::BroadcastSigFloat64Signal(double ParamFloat64)
{
	OnSigFloat64Signal.Broadcast(ParamFloat64);
	OnSigFloat64SignalBP.Broadcast(ParamFloat64);

	TArray<TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnSigFloat64Signal(Obj, ParamFloat64);
		}
	}
}

void UTbSimpleSimpleInterfacePublisher::BroadcastSigStringSignal(const FString& ParamString)
{
	OnSigStringSignal.Broadcast(ParamString);
	OnSigStringSignalBP.Broadcast(ParamString);

	TArray<TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnSigStringSignal(Obj, ParamString);
		}
	}
}

void UTbSimpleSimpleInterfacePublisher::BroadcastPropBoolChanged(UPARAM(DisplayName = "bPropBool") bool bInPropBool)
{
	OnPropBoolChanged.Broadcast(bInPropBool);
	OnPropBoolChangedBP.Broadcast(bInPropBool);

	TArray<TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnPropBoolChanged(Obj, bInPropBool);
		}
	}
}

void UTbSimpleSimpleInterfacePublisher::BroadcastPropIntChanged(UPARAM(DisplayName = "PropInt") int32 InPropInt)
{
	OnPropIntChanged.Broadcast(InPropInt);
	OnPropIntChangedBP.Broadcast(InPropInt);

	TArray<TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnPropIntChanged(Obj, InPropInt);
		}
	}
}

void UTbSimpleSimpleInterfacePublisher::BroadcastPropInt32Changed(UPARAM(DisplayName = "PropInt32") int32 InPropInt32)
{
	OnPropInt32Changed.Broadcast(InPropInt32);
	OnPropInt32ChangedBP.Broadcast(InPropInt32);

	TArray<TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnPropInt32Changed(Obj, InPropInt32);
		}
	}
}

void UTbSimpleSimpleInterfacePublisher::BroadcastPropInt64Changed(UPARAM(DisplayName = "PropInt64") int64 InPropInt64)
{
	OnPropInt64Changed.Broadcast(InPropInt64);
	OnPropInt64ChangedBP.Broadcast(InPropInt64);

	TArray<TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnPropInt64Changed(Obj, InPropInt64);
		}
	}
}

void UTbSimpleSimpleInterfacePublisher::BroadcastPropFloatChanged(UPARAM(DisplayName = "PropFloat") float InPropFloat)
{
	OnPropFloatChanged.Broadcast(InPropFloat);
	OnPropFloatChangedBP.Broadcast(InPropFloat);

	TArray<TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnPropFloatChanged(Obj, InPropFloat);
		}
	}
}

void UTbSimpleSimpleInterfacePublisher::BroadcastPropFloat32Changed(UPARAM(DisplayName = "PropFloat32") float InPropFloat32)
{
	OnPropFloat32Changed.Broadcast(InPropFloat32);
	OnPropFloat32ChangedBP.Broadcast(InPropFloat32);

	TArray<TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnPropFloat32Changed(Obj, InPropFloat32);
		}
	}
}

void UTbSimpleSimpleInterfacePublisher::BroadcastPropFloat64Changed(UPARAM(DisplayName = "PropFloat64") double InPropFloat64)
{
	OnPropFloat64Changed.Broadcast(InPropFloat64);
	OnPropFloat64ChangedBP.Broadcast(InPropFloat64);

	TArray<TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnPropFloat64Changed(Obj, InPropFloat64);
		}
	}
}

void UTbSimpleSimpleInterfacePublisher::BroadcastPropStringChanged(UPARAM(DisplayName = "PropString") const FString& InPropString)
{
	OnPropStringChanged.Broadcast(InPropString);
	OnPropStringChangedBP.Broadcast(InPropString);

	TArray<TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnPropStringChanged(Obj, InPropString);
		}
	}
}

void UTbSimpleSimpleInterfacePublisher::Subscribe(const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	Subscribers.Remove(Subscriber);
	Subscribers.Add(Subscriber);
}

void UTbSimpleSimpleInterfacePublisher::Unsubscribe(const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber)
{
	Subscribers.Remove(Subscriber);
}
