
#include "TbSimple/Generated/api/TbSimpleNoPropertiesInterfaceInterface.h"
void UTbSimpleNoPropertiesInterfacePublisher::BroadcastSigVoidSignal()
{
	OnSigVoidSignal.Broadcast();
	OnSigVoidSignalBP.Broadcast();

	TArray<TScriptInterface<ITbSimpleNoPropertiesInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbSimpleNoPropertiesInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbSimpleNoPropertiesInterfaceBPSubscriberInterface::Execute_OnSigVoidSignal(Obj);
		}
	}
}

void UTbSimpleNoPropertiesInterfacePublisher::BroadcastSigBoolSignal(bool bParamBool)
{
	OnSigBoolSignal.Broadcast(bParamBool);
	OnSigBoolSignalBP.Broadcast(bParamBool);

	TArray<TScriptInterface<ITbSimpleNoPropertiesInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbSimpleNoPropertiesInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbSimpleNoPropertiesInterfaceBPSubscriberInterface::Execute_OnSigBoolSignal(Obj, bParamBool);
		}
	}
}

void UTbSimpleNoPropertiesInterfacePublisher::Subscribe(const TScriptInterface<ITbSimpleNoPropertiesInterfaceBPSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	Subscribers.Remove(Subscriber);
	Subscribers.Add(Subscriber);
}

void UTbSimpleNoPropertiesInterfacePublisher::Unsubscribe(const TScriptInterface<ITbSimpleNoPropertiesInterfaceBPSubscriberInterface>& Subscriber)
{
	Subscribers.Remove(Subscriber);
}
