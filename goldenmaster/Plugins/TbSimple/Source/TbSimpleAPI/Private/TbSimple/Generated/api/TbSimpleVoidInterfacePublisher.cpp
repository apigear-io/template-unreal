
#include "TbSimple/Generated/api/TbSimpleVoidInterfaceInterface.h"
void UTbSimpleVoidInterfacePublisher::BroadcastSigVoidSignal()
{
	OnSigVoidSignal.Broadcast();
	OnSigVoidSignalBP.Broadcast();

	TArray<TScriptInterface<ITbSimpleVoidInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbSimpleVoidInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbSimpleVoidInterfaceBPSubscriberInterface::Execute_OnSigVoidSignal(Obj);
		}
	}
}

void UTbSimpleVoidInterfacePublisher::Subscribe(const TScriptInterface<ITbSimpleVoidInterfaceBPSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	Subscribers.Remove(Subscriber);
	Subscribers.Add(Subscriber);
}

void UTbSimpleVoidInterfacePublisher::Unsubscribe(const TScriptInterface<ITbSimpleVoidInterfaceBPSubscriberInterface>& Subscriber)
{
	Subscribers.Remove(Subscriber);
}
