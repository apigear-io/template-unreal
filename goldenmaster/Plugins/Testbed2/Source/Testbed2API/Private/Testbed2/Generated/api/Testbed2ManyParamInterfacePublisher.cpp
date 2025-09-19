
#include "Testbed2/Generated/api/Testbed2ManyParamInterfaceInterface.h"
void UTestbed2ManyParamInterfacePublisher::BroadcastSig1Signal(int32 Param1)
{
	OnSig1Signal.Broadcast(Param1);
	OnSig1SignalBP.Broadcast(Param1);

	TArray<TScriptInterface<ITestbed2ManyParamInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITestbed2ManyParamInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITestbed2ManyParamInterfaceBPSubscriberInterface::Execute_OnSig1Signal(Obj, Param1);
		}
	}
}

void UTestbed2ManyParamInterfacePublisher::BroadcastSig2Signal(int32 Param1, int32 Param2)
{
	OnSig2Signal.Broadcast(Param1, Param2);
	OnSig2SignalBP.Broadcast(Param1, Param2);

	TArray<TScriptInterface<ITestbed2ManyParamInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITestbed2ManyParamInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITestbed2ManyParamInterfaceBPSubscriberInterface::Execute_OnSig2Signal(Obj, Param1, Param2);
		}
	}
}

void UTestbed2ManyParamInterfacePublisher::BroadcastSig3Signal(int32 Param1, int32 Param2, int32 Param3)
{
	OnSig3Signal.Broadcast(Param1, Param2, Param3);
	OnSig3SignalBP.Broadcast(Param1, Param2, Param3);

	TArray<TScriptInterface<ITestbed2ManyParamInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITestbed2ManyParamInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITestbed2ManyParamInterfaceBPSubscriberInterface::Execute_OnSig3Signal(Obj, Param1, Param2, Param3);
		}
	}
}

void UTestbed2ManyParamInterfacePublisher::BroadcastSig4Signal(int32 Param1, int32 Param2, int32 Param3, int32 Param4)
{
	OnSig4Signal.Broadcast(Param1, Param2, Param3, Param4);
	OnSig4SignalBP.Broadcast(Param1, Param2, Param3, Param4);

	TArray<TScriptInterface<ITestbed2ManyParamInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITestbed2ManyParamInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITestbed2ManyParamInterfaceBPSubscriberInterface::Execute_OnSig4Signal(Obj, Param1, Param2, Param3, Param4);
		}
	}
}

void UTestbed2ManyParamInterfacePublisher::BroadcastProp1Changed(UPARAM(DisplayName = "Prop1") int32 InProp1)
{
	OnProp1Changed.Broadcast(InProp1);
	OnProp1ChangedBP.Broadcast(InProp1);

	TArray<TScriptInterface<ITestbed2ManyParamInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITestbed2ManyParamInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITestbed2ManyParamInterfaceBPSubscriberInterface::Execute_OnProp1Changed(Obj, InProp1);
		}
	}
}

void UTestbed2ManyParamInterfacePublisher::BroadcastProp2Changed(UPARAM(DisplayName = "Prop2") int32 InProp2)
{
	OnProp2Changed.Broadcast(InProp2);
	OnProp2ChangedBP.Broadcast(InProp2);

	TArray<TScriptInterface<ITestbed2ManyParamInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITestbed2ManyParamInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITestbed2ManyParamInterfaceBPSubscriberInterface::Execute_OnProp2Changed(Obj, InProp2);
		}
	}
}

void UTestbed2ManyParamInterfacePublisher::BroadcastProp3Changed(UPARAM(DisplayName = "Prop3") int32 InProp3)
{
	OnProp3Changed.Broadcast(InProp3);
	OnProp3ChangedBP.Broadcast(InProp3);

	TArray<TScriptInterface<ITestbed2ManyParamInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITestbed2ManyParamInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITestbed2ManyParamInterfaceBPSubscriberInterface::Execute_OnProp3Changed(Obj, InProp3);
		}
	}
}

void UTestbed2ManyParamInterfacePublisher::BroadcastProp4Changed(UPARAM(DisplayName = "Prop4") int32 InProp4)
{
	OnProp4Changed.Broadcast(InProp4);
	OnProp4ChangedBP.Broadcast(InProp4);

	TArray<TScriptInterface<ITestbed2ManyParamInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITestbed2ManyParamInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITestbed2ManyParamInterfaceBPSubscriberInterface::Execute_OnProp4Changed(Obj, InProp4);
		}
	}
}

void UTestbed2ManyParamInterfacePublisher::Subscribe(const TScriptInterface<ITestbed2ManyParamInterfaceBPSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	Subscribers.Remove(Subscriber);
	Subscribers.Add(Subscriber);
}

void UTestbed2ManyParamInterfacePublisher::Unsubscribe(const TScriptInterface<ITestbed2ManyParamInterfaceBPSubscriberInterface>& Subscriber)
{
	Subscribers.Remove(Subscriber);
}
