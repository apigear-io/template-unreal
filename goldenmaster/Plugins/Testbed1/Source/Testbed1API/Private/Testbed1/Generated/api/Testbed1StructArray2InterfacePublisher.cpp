
#include "Testbed1/Generated/api/Testbed1StructArray2InterfaceInterface.h"
void UTestbed1StructArray2InterfacePublisher::BroadcastSigBoolSignal(const FTestbed1StructBoolWithArray& ParamBool)
{
	OnSigBoolSignal.Broadcast(ParamBool);
	OnSigBoolSignalBP.Broadcast(ParamBool);

	TArray<TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITestbed1StructArray2InterfaceBPSubscriberInterface::Execute_OnSigBoolSignal(Obj, ParamBool);
		}
	}
}

void UTestbed1StructArray2InterfacePublisher::BroadcastSigIntSignal(const FTestbed1StructIntWithArray& ParamInt)
{
	OnSigIntSignal.Broadcast(ParamInt);
	OnSigIntSignalBP.Broadcast(ParamInt);

	TArray<TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITestbed1StructArray2InterfaceBPSubscriberInterface::Execute_OnSigIntSignal(Obj, ParamInt);
		}
	}
}

void UTestbed1StructArray2InterfacePublisher::BroadcastSigFloatSignal(const FTestbed1StructFloatWithArray& ParamFloat)
{
	OnSigFloatSignal.Broadcast(ParamFloat);
	OnSigFloatSignalBP.Broadcast(ParamFloat);

	TArray<TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITestbed1StructArray2InterfaceBPSubscriberInterface::Execute_OnSigFloatSignal(Obj, ParamFloat);
		}
	}
}

void UTestbed1StructArray2InterfacePublisher::BroadcastSigStringSignal(const FTestbed1StructStringWithArray& ParamString)
{
	OnSigStringSignal.Broadcast(ParamString);
	OnSigStringSignalBP.Broadcast(ParamString);

	TArray<TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITestbed1StructArray2InterfaceBPSubscriberInterface::Execute_OnSigStringSignal(Obj, ParamString);
		}
	}
}

void UTestbed1StructArray2InterfacePublisher::BroadcastPropBoolChanged(UPARAM(DisplayName = "PropBool") const FTestbed1StructBoolWithArray& InPropBool)
{
	OnPropBoolChanged.Broadcast(InPropBool);
	OnPropBoolChangedBP.Broadcast(InPropBool);

	TArray<TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITestbed1StructArray2InterfaceBPSubscriberInterface::Execute_OnPropBoolChanged(Obj, InPropBool);
		}
	}
}

void UTestbed1StructArray2InterfacePublisher::BroadcastPropIntChanged(UPARAM(DisplayName = "PropInt") const FTestbed1StructIntWithArray& InPropInt)
{
	OnPropIntChanged.Broadcast(InPropInt);
	OnPropIntChangedBP.Broadcast(InPropInt);

	TArray<TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITestbed1StructArray2InterfaceBPSubscriberInterface::Execute_OnPropIntChanged(Obj, InPropInt);
		}
	}
}

void UTestbed1StructArray2InterfacePublisher::BroadcastPropFloatChanged(UPARAM(DisplayName = "PropFloat") const FTestbed1StructFloatWithArray& InPropFloat)
{
	OnPropFloatChanged.Broadcast(InPropFloat);
	OnPropFloatChangedBP.Broadcast(InPropFloat);

	TArray<TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITestbed1StructArray2InterfaceBPSubscriberInterface::Execute_OnPropFloatChanged(Obj, InPropFloat);
		}
	}
}

void UTestbed1StructArray2InterfacePublisher::BroadcastPropStringChanged(UPARAM(DisplayName = "PropString") const FTestbed1StructStringWithArray& InPropString)
{
	OnPropStringChanged.Broadcast(InPropString);
	OnPropStringChangedBP.Broadcast(InPropString);

	TArray<TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITestbed1StructArray2InterfaceBPSubscriberInterface::Execute_OnPropStringChanged(Obj, InPropString);
		}
	}
}

void UTestbed1StructArray2InterfacePublisher::BroadcastPropEnumChanged(UPARAM(DisplayName = "PropEnum") const FTestbed1StructEnumWithArray& InPropEnum)
{
	OnPropEnumChanged.Broadcast(InPropEnum);
	OnPropEnumChangedBP.Broadcast(InPropEnum);

	TArray<TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITestbed1StructArray2InterfaceBPSubscriberInterface::Execute_OnPropEnumChanged(Obj, InPropEnum);
		}
	}
}

void UTestbed1StructArray2InterfacePublisher::Subscribe(const TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	Subscribers.Remove(Subscriber);
	Subscribers.Add(Subscriber);
}

void UTestbed1StructArray2InterfacePublisher::Unsubscribe(const TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>& Subscriber)
{
	Subscribers.Remove(Subscriber);
}
