
#include "Testbed1/Generated/api/Testbed1StructInterfaceInterface.h"
void UTestbed1StructInterfacePublisher::BroadcastSigBoolSignal(const FTestbed1StructBool& ParamBool)
{
	OnSigBoolSignal.Broadcast(ParamBool);
	OnSigBoolSignalBP.Broadcast(ParamBool);

	TArray<TScriptInterface<ITestbed1StructInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITestbed1StructInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITestbed1StructInterfaceBPSubscriberInterface::Execute_OnSigBoolSignal(Obj, ParamBool);
		}
	}
}

void UTestbed1StructInterfacePublisher::BroadcastSigIntSignal(const FTestbed1StructInt& ParamInt)
{
	OnSigIntSignal.Broadcast(ParamInt);
	OnSigIntSignalBP.Broadcast(ParamInt);

	TArray<TScriptInterface<ITestbed1StructInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITestbed1StructInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITestbed1StructInterfaceBPSubscriberInterface::Execute_OnSigIntSignal(Obj, ParamInt);
		}
	}
}

void UTestbed1StructInterfacePublisher::BroadcastSigFloatSignal(const FTestbed1StructFloat& ParamFloat)
{
	OnSigFloatSignal.Broadcast(ParamFloat);
	OnSigFloatSignalBP.Broadcast(ParamFloat);

	TArray<TScriptInterface<ITestbed1StructInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITestbed1StructInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITestbed1StructInterfaceBPSubscriberInterface::Execute_OnSigFloatSignal(Obj, ParamFloat);
		}
	}
}

void UTestbed1StructInterfacePublisher::BroadcastSigStringSignal(const FTestbed1StructString& ParamString)
{
	OnSigStringSignal.Broadcast(ParamString);
	OnSigStringSignalBP.Broadcast(ParamString);

	TArray<TScriptInterface<ITestbed1StructInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITestbed1StructInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITestbed1StructInterfaceBPSubscriberInterface::Execute_OnSigStringSignal(Obj, ParamString);
		}
	}
}

void UTestbed1StructInterfacePublisher::BroadcastPropBoolChanged(UPARAM(DisplayName = "PropBool") const FTestbed1StructBool& InPropBool)
{
	OnPropBoolChanged.Broadcast(InPropBool);
	OnPropBoolChangedBP.Broadcast(InPropBool);

	TArray<TScriptInterface<ITestbed1StructInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITestbed1StructInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITestbed1StructInterfaceBPSubscriberInterface::Execute_OnPropBoolChanged(Obj, InPropBool);
		}
	}
}

void UTestbed1StructInterfacePublisher::BroadcastPropIntChanged(UPARAM(DisplayName = "PropInt") const FTestbed1StructInt& InPropInt)
{
	OnPropIntChanged.Broadcast(InPropInt);
	OnPropIntChangedBP.Broadcast(InPropInt);

	TArray<TScriptInterface<ITestbed1StructInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITestbed1StructInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITestbed1StructInterfaceBPSubscriberInterface::Execute_OnPropIntChanged(Obj, InPropInt);
		}
	}
}

void UTestbed1StructInterfacePublisher::BroadcastPropFloatChanged(UPARAM(DisplayName = "PropFloat") const FTestbed1StructFloat& InPropFloat)
{
	OnPropFloatChanged.Broadcast(InPropFloat);
	OnPropFloatChangedBP.Broadcast(InPropFloat);

	TArray<TScriptInterface<ITestbed1StructInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITestbed1StructInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITestbed1StructInterfaceBPSubscriberInterface::Execute_OnPropFloatChanged(Obj, InPropFloat);
		}
	}
}

void UTestbed1StructInterfacePublisher::BroadcastPropStringChanged(UPARAM(DisplayName = "PropString") const FTestbed1StructString& InPropString)
{
	OnPropStringChanged.Broadcast(InPropString);
	OnPropStringChangedBP.Broadcast(InPropString);

	TArray<TScriptInterface<ITestbed1StructInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITestbed1StructInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITestbed1StructInterfaceBPSubscriberInterface::Execute_OnPropStringChanged(Obj, InPropString);
		}
	}
}

void UTestbed1StructInterfacePublisher::Subscribe(const TScriptInterface<ITestbed1StructInterfaceBPSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	Subscribers.Remove(Subscriber);
	Subscribers.Add(Subscriber);
}

void UTestbed1StructInterfacePublisher::Unsubscribe(const TScriptInterface<ITestbed1StructInterfaceBPSubscriberInterface>& Subscriber)
{
	Subscribers.Remove(Subscriber);
}
