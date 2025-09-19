
#include "TbSame1/Generated/api/TbSame1SameEnum2InterfaceInterface.h"
void UTbSame1SameEnum2InterfacePublisher::BroadcastSig1Signal(ETbSame1Enum1 Param1)
{
	OnSig1Signal.Broadcast(Param1);
	OnSig1SignalBP.Broadcast(Param1);

	TArray<TScriptInterface<ITbSame1SameEnum2InterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbSame1SameEnum2InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbSame1SameEnum2InterfaceBPSubscriberInterface::Execute_OnSig1Signal(Obj, Param1);
		}
	}
}

void UTbSame1SameEnum2InterfacePublisher::BroadcastSig2Signal(ETbSame1Enum1 Param1, ETbSame1Enum2 Param2)
{
	OnSig2Signal.Broadcast(Param1, Param2);
	OnSig2SignalBP.Broadcast(Param1, Param2);

	TArray<TScriptInterface<ITbSame1SameEnum2InterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbSame1SameEnum2InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbSame1SameEnum2InterfaceBPSubscriberInterface::Execute_OnSig2Signal(Obj, Param1, Param2);
		}
	}
}

void UTbSame1SameEnum2InterfacePublisher::BroadcastProp1Changed(UPARAM(DisplayName = "Prop1") ETbSame1Enum1 InProp1)
{
	OnProp1Changed.Broadcast(InProp1);
	OnProp1ChangedBP.Broadcast(InProp1);

	TArray<TScriptInterface<ITbSame1SameEnum2InterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbSame1SameEnum2InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbSame1SameEnum2InterfaceBPSubscriberInterface::Execute_OnProp1Changed(Obj, InProp1);
		}
	}
}

void UTbSame1SameEnum2InterfacePublisher::BroadcastProp2Changed(UPARAM(DisplayName = "Prop2") ETbSame1Enum2 InProp2)
{
	OnProp2Changed.Broadcast(InProp2);
	OnProp2ChangedBP.Broadcast(InProp2);

	TArray<TScriptInterface<ITbSame1SameEnum2InterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbSame1SameEnum2InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbSame1SameEnum2InterfaceBPSubscriberInterface::Execute_OnProp2Changed(Obj, InProp2);
		}
	}
}

void UTbSame1SameEnum2InterfacePublisher::Subscribe(const TScriptInterface<ITbSame1SameEnum2InterfaceBPSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	Subscribers.Remove(Subscriber);
	Subscribers.Add(Subscriber);
}

void UTbSame1SameEnum2InterfacePublisher::Unsubscribe(const TScriptInterface<ITbSame1SameEnum2InterfaceBPSubscriberInterface>& Subscriber)
{
	Subscribers.Remove(Subscriber);
}
