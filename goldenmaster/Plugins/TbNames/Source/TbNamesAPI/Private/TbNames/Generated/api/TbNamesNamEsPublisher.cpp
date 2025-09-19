
#include "TbNames/Generated/api/TbNamesNamEsInterface.h"
void UTbNamesNamEsPublisher::BroadcastSomeSignalSignal(bool bSomeParam)
{
	OnSomeSignalSignal.Broadcast(bSomeParam);
	OnSomeSignalSignalBP.Broadcast(bSomeParam);

	TArray<TScriptInterface<ITbNamesNamEsBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbNamesNamEsBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbNamesNamEsBPSubscriberInterface::Execute_OnSomeSignalSignal(Obj, bSomeParam);
		}
	}
}

void UTbNamesNamEsPublisher::BroadcastSomeSignal2Signal(bool bSomeParam)
{
	OnSomeSignal2Signal.Broadcast(bSomeParam);
	OnSomeSignal2SignalBP.Broadcast(bSomeParam);

	TArray<TScriptInterface<ITbNamesNamEsBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbNamesNamEsBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbNamesNamEsBPSubscriberInterface::Execute_OnSomeSignal2Signal(Obj, bSomeParam);
		}
	}
}

void UTbNamesNamEsPublisher::BroadcastSwitchChanged(UPARAM(DisplayName = "bSwitch") bool bInSwitch)
{
	OnSwitchChanged.Broadcast(bInSwitch);
	OnSwitchChangedBP.Broadcast(bInSwitch);

	TArray<TScriptInterface<ITbNamesNamEsBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbNamesNamEsBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbNamesNamEsBPSubscriberInterface::Execute_OnSwitchChanged(Obj, bInSwitch);
		}
	}
}

void UTbNamesNamEsPublisher::BroadcastSomePropertyChanged(UPARAM(DisplayName = "SomeProperty") int32 InSomeProperty)
{
	OnSomePropertyChanged.Broadcast(InSomeProperty);
	OnSomePropertyChangedBP.Broadcast(InSomeProperty);

	TArray<TScriptInterface<ITbNamesNamEsBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbNamesNamEsBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbNamesNamEsBPSubscriberInterface::Execute_OnSomePropertyChanged(Obj, InSomeProperty);
		}
	}
}

void UTbNamesNamEsPublisher::BroadcastSomePoperty2Changed(UPARAM(DisplayName = "SomePoperty2") int32 InSomePoperty2)
{
	OnSomePoperty2Changed.Broadcast(InSomePoperty2);
	OnSomePoperty2ChangedBP.Broadcast(InSomePoperty2);

	TArray<TScriptInterface<ITbNamesNamEsBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbNamesNamEsBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbNamesNamEsBPSubscriberInterface::Execute_OnSomePoperty2Changed(Obj, InSomePoperty2);
		}
	}
}

void UTbNamesNamEsPublisher::BroadcastEnumPropertyChanged(UPARAM(DisplayName = "EnumProperty") ETbNamesEnum_With_Under_scores InEnumProperty)
{
	OnEnumPropertyChanged.Broadcast(InEnumProperty);
	OnEnumPropertyChangedBP.Broadcast(InEnumProperty);

	TArray<TScriptInterface<ITbNamesNamEsBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbNamesNamEsBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbNamesNamEsBPSubscriberInterface::Execute_OnEnumPropertyChanged(Obj, InEnumProperty);
		}
	}
}

void UTbNamesNamEsPublisher::Subscribe(const TScriptInterface<ITbNamesNamEsBPSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	Subscribers.Remove(Subscriber);
	Subscribers.Add(Subscriber);
}

void UTbNamesNamEsPublisher::Unsubscribe(const TScriptInterface<ITbNamesNamEsBPSubscriberInterface>& Subscriber)
{
	Subscribers.Remove(Subscriber);
}
