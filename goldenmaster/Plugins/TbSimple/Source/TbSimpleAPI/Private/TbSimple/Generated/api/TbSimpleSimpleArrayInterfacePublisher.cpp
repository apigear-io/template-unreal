
#include "TbSimple/Generated/api/TbSimpleSimpleArrayInterfaceInterface.h"
void UTbSimpleSimpleArrayInterfacePublisher::BroadcastSigBoolSignal(const TArray<bool>& ParamBool)
{
	OnSigBoolSignal.Broadcast(ParamBool);
	OnSigBoolSignalBP.Broadcast(ParamBool);

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnSigBoolSignal(Obj, ParamBool);
		}
	}
}

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastSigIntSignal(const TArray<int32>& ParamInt)
{
	OnSigIntSignal.Broadcast(ParamInt);
	OnSigIntSignalBP.Broadcast(ParamInt);

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnSigIntSignal(Obj, ParamInt);
		}
	}
}

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastSigInt32Signal(const TArray<int32>& ParamInt32)
{
	OnSigInt32Signal.Broadcast(ParamInt32);
	OnSigInt32SignalBP.Broadcast(ParamInt32);

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnSigInt32Signal(Obj, ParamInt32);
		}
	}
}

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastSigInt64Signal(const TArray<int64>& ParamInt64)
{
	OnSigInt64Signal.Broadcast(ParamInt64);
	OnSigInt64SignalBP.Broadcast(ParamInt64);

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnSigInt64Signal(Obj, ParamInt64);
		}
	}
}

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastSigFloatSignal(const TArray<float>& ParamFloat)
{
	OnSigFloatSignal.Broadcast(ParamFloat);
	OnSigFloatSignalBP.Broadcast(ParamFloat);

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnSigFloatSignal(Obj, ParamFloat);
		}
	}
}

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastSigFloat32Signal(const TArray<float>& ParamFloa32)
{
	OnSigFloat32Signal.Broadcast(ParamFloa32);
	OnSigFloat32SignalBP.Broadcast(ParamFloa32);

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnSigFloat32Signal(Obj, ParamFloa32);
		}
	}
}

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastSigFloat64Signal(const TArray<double>& ParamFloat64)
{
	OnSigFloat64Signal.Broadcast(ParamFloat64);
	OnSigFloat64SignalBP.Broadcast(ParamFloat64);

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnSigFloat64Signal(Obj, ParamFloat64);
		}
	}
}

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastSigStringSignal(const TArray<FString>& ParamString)
{
	OnSigStringSignal.Broadcast(ParamString);
	OnSigStringSignalBP.Broadcast(ParamString);

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnSigStringSignal(Obj, ParamString);
		}
	}
}

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastPropBoolChanged(UPARAM(DisplayName = "PropBool") const TArray<bool>& InPropBool)
{
	OnPropBoolChanged.Broadcast(InPropBool);
	OnPropBoolChangedBP.Broadcast(InPropBool);

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropBoolChanged(Obj, InPropBool);
		}
	}
}

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastPropIntChanged(UPARAM(DisplayName = "PropInt") const TArray<int32>& InPropInt)
{
	OnPropIntChanged.Broadcast(InPropInt);
	OnPropIntChangedBP.Broadcast(InPropInt);

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropIntChanged(Obj, InPropInt);
		}
	}
}

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastPropInt32Changed(UPARAM(DisplayName = "PropInt32") const TArray<int32>& InPropInt32)
{
	OnPropInt32Changed.Broadcast(InPropInt32);
	OnPropInt32ChangedBP.Broadcast(InPropInt32);

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropInt32Changed(Obj, InPropInt32);
		}
	}
}

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastPropInt64Changed(UPARAM(DisplayName = "PropInt64") const TArray<int64>& InPropInt64)
{
	OnPropInt64Changed.Broadcast(InPropInt64);
	OnPropInt64ChangedBP.Broadcast(InPropInt64);

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropInt64Changed(Obj, InPropInt64);
		}
	}
}

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastPropFloatChanged(UPARAM(DisplayName = "PropFloat") const TArray<float>& InPropFloat)
{
	OnPropFloatChanged.Broadcast(InPropFloat);
	OnPropFloatChangedBP.Broadcast(InPropFloat);

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropFloatChanged(Obj, InPropFloat);
		}
	}
}

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastPropFloat32Changed(UPARAM(DisplayName = "PropFloat32") const TArray<float>& InPropFloat32)
{
	OnPropFloat32Changed.Broadcast(InPropFloat32);
	OnPropFloat32ChangedBP.Broadcast(InPropFloat32);

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropFloat32Changed(Obj, InPropFloat32);
		}
	}
}

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastPropFloat64Changed(UPARAM(DisplayName = "PropFloat64") const TArray<double>& InPropFloat64)
{
	OnPropFloat64Changed.Broadcast(InPropFloat64);
	OnPropFloat64ChangedBP.Broadcast(InPropFloat64);

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropFloat64Changed(Obj, InPropFloat64);
		}
	}
}

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastPropStringChanged(UPARAM(DisplayName = "PropString") const TArray<FString>& InPropString)
{
	OnPropStringChanged.Broadcast(InPropString);
	OnPropStringChangedBP.Broadcast(InPropString);

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropStringChanged(Obj, InPropString);
		}
	}
}

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastPropReadOnlyStringChanged(UPARAM(DisplayName = "PropReadOnlyString") const FString& InPropReadOnlyString)
{
	OnPropReadOnlyStringChanged.Broadcast(InPropReadOnlyString);
	OnPropReadOnlyStringChangedBP.Broadcast(InPropReadOnlyString);

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropReadOnlyStringChanged(Obj, InPropReadOnlyString);
		}
	}
}

void UTbSimpleSimpleArrayInterfacePublisher::Subscribe(const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	Subscribers.Remove(Subscriber);
	Subscribers.Add(Subscriber);
}

void UTbSimpleSimpleArrayInterfacePublisher::Unsubscribe(const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber)
{
	Subscribers.Remove(Subscriber);
}
