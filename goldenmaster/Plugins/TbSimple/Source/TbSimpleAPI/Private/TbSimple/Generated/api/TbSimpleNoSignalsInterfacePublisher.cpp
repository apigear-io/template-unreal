
#include "TbSimple/Generated/api/TbSimpleNoSignalsInterfaceInterface.h"
void UTbSimpleNoSignalsInterfacePublisher::BroadcastPropBoolChanged(UPARAM(DisplayName = "bPropBool") bool bInPropBool)
{
	OnPropBoolChanged.Broadcast(bInPropBool);
	OnPropBoolChangedBP.Broadcast(bInPropBool);

	TArray<TScriptInterface<ITbSimpleNoSignalsInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbSimpleNoSignalsInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbSimpleNoSignalsInterfaceBPSubscriberInterface::Execute_OnPropBoolChanged(Obj, bInPropBool);
		}
	}
}

void UTbSimpleNoSignalsInterfacePublisher::BroadcastPropIntChanged(UPARAM(DisplayName = "PropInt") int32 InPropInt)
{
	OnPropIntChanged.Broadcast(InPropInt);
	OnPropIntChangedBP.Broadcast(InPropInt);

	TArray<TScriptInterface<ITbSimpleNoSignalsInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbSimpleNoSignalsInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbSimpleNoSignalsInterfaceBPSubscriberInterface::Execute_OnPropIntChanged(Obj, InPropInt);
		}
	}
}

void UTbSimpleNoSignalsInterfacePublisher::Subscribe(const TScriptInterface<ITbSimpleNoSignalsInterfaceBPSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	Subscribers.Remove(Subscriber);
	Subscribers.Add(Subscriber);
}

void UTbSimpleNoSignalsInterfacePublisher::Unsubscribe(const TScriptInterface<ITbSimpleNoSignalsInterfaceBPSubscriberInterface>& Subscriber)
{
	Subscribers.Remove(Subscriber);
}
