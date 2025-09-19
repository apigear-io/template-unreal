
#include "TbSimple/Generated/api/TbSimpleNoOperationsInterfaceInterface.h"
void UTbSimpleNoOperationsInterfacePublisher::BroadcastSigVoidSignal()
{
	OnSigVoidSignal.Broadcast();
	OnSigVoidSignalBP.Broadcast();

	TArray<TScriptInterface<ITbSimpleNoOperationsInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbSimpleNoOperationsInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbSimpleNoOperationsInterfaceBPSubscriberInterface::Execute_OnSigVoidSignal(Obj);
		}
	}
}

void UTbSimpleNoOperationsInterfacePublisher::BroadcastSigBoolSignal(bool bParamBool)
{
	OnSigBoolSignal.Broadcast(bParamBool);
	OnSigBoolSignalBP.Broadcast(bParamBool);

	TArray<TScriptInterface<ITbSimpleNoOperationsInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbSimpleNoOperationsInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbSimpleNoOperationsInterfaceBPSubscriberInterface::Execute_OnSigBoolSignal(Obj, bParamBool);
		}
	}
}

void UTbSimpleNoOperationsInterfacePublisher::BroadcastPropBoolChanged(UPARAM(DisplayName = "bPropBool") bool bInPropBool)
{
	OnPropBoolChanged.Broadcast(bInPropBool);
	OnPropBoolChangedBP.Broadcast(bInPropBool);

	TArray<TScriptInterface<ITbSimpleNoOperationsInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbSimpleNoOperationsInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbSimpleNoOperationsInterfaceBPSubscriberInterface::Execute_OnPropBoolChanged(Obj, bInPropBool);
		}
	}
}

void UTbSimpleNoOperationsInterfacePublisher::BroadcastPropIntChanged(UPARAM(DisplayName = "PropInt") int32 InPropInt)
{
	OnPropIntChanged.Broadcast(InPropInt);
	OnPropIntChangedBP.Broadcast(InPropInt);

	TArray<TScriptInterface<ITbSimpleNoOperationsInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbSimpleNoOperationsInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbSimpleNoOperationsInterfaceBPSubscriberInterface::Execute_OnPropIntChanged(Obj, InPropInt);
		}
	}
}

void UTbSimpleNoOperationsInterfacePublisher::Subscribe(const TScriptInterface<ITbSimpleNoOperationsInterfaceBPSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	Subscribers.Remove(Subscriber);
	Subscribers.Add(Subscriber);
}

void UTbSimpleNoOperationsInterfacePublisher::Unsubscribe(const TScriptInterface<ITbSimpleNoOperationsInterfaceBPSubscriberInterface>& Subscriber)
{
	Subscribers.Remove(Subscriber);
}
