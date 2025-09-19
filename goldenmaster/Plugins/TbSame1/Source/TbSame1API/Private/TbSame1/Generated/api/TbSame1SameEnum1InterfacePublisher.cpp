
#include "TbSame1/Generated/api/TbSame1SameEnum1InterfaceInterface.h"
void UTbSame1SameEnum1InterfacePublisher::BroadcastSig1Signal(ETbSame1Enum1 Param1)
{
	OnSig1Signal.Broadcast(Param1);
	OnSig1SignalBP.Broadcast(Param1);

	TArray<TScriptInterface<ITbSame1SameEnum1InterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbSame1SameEnum1InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbSame1SameEnum1InterfaceBPSubscriberInterface::Execute_OnSig1Signal(Obj, Param1);
		}
	}
}

void UTbSame1SameEnum1InterfacePublisher::BroadcastProp1Changed(UPARAM(DisplayName = "Prop1") ETbSame1Enum1 InProp1)
{
	OnProp1Changed.Broadcast(InProp1);
	OnProp1ChangedBP.Broadcast(InProp1);

	TArray<TScriptInterface<ITbSame1SameEnum1InterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbSame1SameEnum1InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbSame1SameEnum1InterfaceBPSubscriberInterface::Execute_OnProp1Changed(Obj, InProp1);
		}
	}
}

void UTbSame1SameEnum1InterfacePublisher::Subscribe(const TScriptInterface<ITbSame1SameEnum1InterfaceBPSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	Subscribers.Remove(Subscriber);
	Subscribers.Add(Subscriber);
}

void UTbSame1SameEnum1InterfacePublisher::Unsubscribe(const TScriptInterface<ITbSame1SameEnum1InterfaceBPSubscriberInterface>& Subscriber)
{
	Subscribers.Remove(Subscriber);
}
