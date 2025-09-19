
#include "Testbed1/Generated/api/Testbed1StructArrayInterfaceInterface.h"
void UTestbed1StructArrayInterfacePublisher::BroadcastSigBoolSignal(const TArray<FTestbed1StructBool>& ParamBool)
{
	OnSigBoolSignal.Broadcast(ParamBool);
	OnSigBoolSignalBP.Broadcast(ParamBool);

	TArray<TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITestbed1StructArrayInterfaceBPSubscriberInterface::Execute_OnSigBoolSignal(Obj, ParamBool);
		}
	}
}

void UTestbed1StructArrayInterfacePublisher::BroadcastSigIntSignal(const TArray<FTestbed1StructInt>& ParamInt)
{
	OnSigIntSignal.Broadcast(ParamInt);
	OnSigIntSignalBP.Broadcast(ParamInt);

	TArray<TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITestbed1StructArrayInterfaceBPSubscriberInterface::Execute_OnSigIntSignal(Obj, ParamInt);
		}
	}
}

void UTestbed1StructArrayInterfacePublisher::BroadcastSigFloatSignal(const TArray<FTestbed1StructFloat>& ParamFloat)
{
	OnSigFloatSignal.Broadcast(ParamFloat);
	OnSigFloatSignalBP.Broadcast(ParamFloat);

	TArray<TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITestbed1StructArrayInterfaceBPSubscriberInterface::Execute_OnSigFloatSignal(Obj, ParamFloat);
		}
	}
}

void UTestbed1StructArrayInterfacePublisher::BroadcastSigStringSignal(const TArray<FTestbed1StructString>& ParamString)
{
	OnSigStringSignal.Broadcast(ParamString);
	OnSigStringSignalBP.Broadcast(ParamString);

	TArray<TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITestbed1StructArrayInterfaceBPSubscriberInterface::Execute_OnSigStringSignal(Obj, ParamString);
		}
	}
}

void UTestbed1StructArrayInterfacePublisher::BroadcastSigEnumSignal(const TArray<ETestbed1Enum0>& ParamEnum)
{
	OnSigEnumSignal.Broadcast(ParamEnum);
	OnSigEnumSignalBP.Broadcast(ParamEnum);

	TArray<TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITestbed1StructArrayInterfaceBPSubscriberInterface::Execute_OnSigEnumSignal(Obj, ParamEnum);
		}
	}
}

void UTestbed1StructArrayInterfacePublisher::BroadcastPropBoolChanged(UPARAM(DisplayName = "PropBool") const TArray<FTestbed1StructBool>& InPropBool)
{
	OnPropBoolChanged.Broadcast(InPropBool);
	OnPropBoolChangedBP.Broadcast(InPropBool);

	TArray<TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITestbed1StructArrayInterfaceBPSubscriberInterface::Execute_OnPropBoolChanged(Obj, InPropBool);
		}
	}
}

void UTestbed1StructArrayInterfacePublisher::BroadcastPropIntChanged(UPARAM(DisplayName = "PropInt") const TArray<FTestbed1StructInt>& InPropInt)
{
	OnPropIntChanged.Broadcast(InPropInt);
	OnPropIntChangedBP.Broadcast(InPropInt);

	TArray<TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITestbed1StructArrayInterfaceBPSubscriberInterface::Execute_OnPropIntChanged(Obj, InPropInt);
		}
	}
}

void UTestbed1StructArrayInterfacePublisher::BroadcastPropFloatChanged(UPARAM(DisplayName = "PropFloat") const TArray<FTestbed1StructFloat>& InPropFloat)
{
	OnPropFloatChanged.Broadcast(InPropFloat);
	OnPropFloatChangedBP.Broadcast(InPropFloat);

	TArray<TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITestbed1StructArrayInterfaceBPSubscriberInterface::Execute_OnPropFloatChanged(Obj, InPropFloat);
		}
	}
}

void UTestbed1StructArrayInterfacePublisher::BroadcastPropStringChanged(UPARAM(DisplayName = "PropString") const TArray<FTestbed1StructString>& InPropString)
{
	OnPropStringChanged.Broadcast(InPropString);
	OnPropStringChangedBP.Broadcast(InPropString);

	TArray<TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITestbed1StructArrayInterfaceBPSubscriberInterface::Execute_OnPropStringChanged(Obj, InPropString);
		}
	}
}

void UTestbed1StructArrayInterfacePublisher::BroadcastPropEnumChanged(UPARAM(DisplayName = "PropEnum") const TArray<ETestbed1Enum0>& InPropEnum)
{
	OnPropEnumChanged.Broadcast(InPropEnum);
	OnPropEnumChangedBP.Broadcast(InPropEnum);

	TArray<TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITestbed1StructArrayInterfaceBPSubscriberInterface::Execute_OnPropEnumChanged(Obj, InPropEnum);
		}
	}
}

void UTestbed1StructArrayInterfacePublisher::Subscribe(const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	Subscribers.Remove(Subscriber);
	Subscribers.Add(Subscriber);
}

void UTestbed1StructArrayInterfacePublisher::Unsubscribe(const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber)
{
	Subscribers.Remove(Subscriber);
}
