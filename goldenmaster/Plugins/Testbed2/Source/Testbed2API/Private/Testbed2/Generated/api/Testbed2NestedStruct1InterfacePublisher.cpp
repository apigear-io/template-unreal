
#include "Testbed2/Generated/api/Testbed2NestedStruct1InterfaceInterface.h"
void UTestbed2NestedStruct1InterfacePublisher::BroadcastSig1Signal(const FTestbed2NestedStruct1& Param1)
{
	OnSig1Signal.Broadcast(Param1);
	OnSig1SignalBP.Broadcast(Param1);

	TArray<TScriptInterface<ITestbed2NestedStruct1InterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITestbed2NestedStruct1InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITestbed2NestedStruct1InterfaceBPSubscriberInterface::Execute_OnSig1Signal(Obj, Param1);
		}
	}
}

void UTestbed2NestedStruct1InterfacePublisher::BroadcastProp1Changed(UPARAM(DisplayName = "Prop1") const FTestbed2NestedStruct1& InProp1)
{
	OnProp1Changed.Broadcast(InProp1);
	OnProp1ChangedBP.Broadcast(InProp1);

	TArray<TScriptInterface<ITestbed2NestedStruct1InterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITestbed2NestedStruct1InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITestbed2NestedStruct1InterfaceBPSubscriberInterface::Execute_OnProp1Changed(Obj, InProp1);
		}
	}
}

void UTestbed2NestedStruct1InterfacePublisher::Subscribe(const TScriptInterface<ITestbed2NestedStruct1InterfaceBPSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	Subscribers.Remove(Subscriber);
	Subscribers.Add(Subscriber);
}

void UTestbed2NestedStruct1InterfacePublisher::Unsubscribe(const TScriptInterface<ITestbed2NestedStruct1InterfaceBPSubscriberInterface>& Subscriber)
{
	Subscribers.Remove(Subscriber);
}
