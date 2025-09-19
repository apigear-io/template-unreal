
#include "TbRefIfaces/Generated/api/TbRefIfacesSimpleLocalIfInterface.h"
void UTbRefIfacesSimpleLocalIfPublisher::BroadcastIntSignalSignal(int32 Param)
{
	OnIntSignalSignal.Broadcast(Param);
	OnIntSignalSignalBP.Broadcast(Param);

	TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbRefIfacesSimpleLocalIfBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbRefIfacesSimpleLocalIfBPSubscriberInterface::Execute_OnIntSignalSignal(Obj, Param);
		}
	}
}

void UTbRefIfacesSimpleLocalIfPublisher::BroadcastIntPropertyChanged(UPARAM(DisplayName = "IntProperty") int32 InIntProperty)
{
	OnIntPropertyChanged.Broadcast(InIntProperty);
	OnIntPropertyChangedBP.Broadcast(InIntProperty);

	TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbRefIfacesSimpleLocalIfBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbRefIfacesSimpleLocalIfBPSubscriberInterface::Execute_OnIntPropertyChanged(Obj, InIntProperty);
		}
	}
}

void UTbRefIfacesSimpleLocalIfPublisher::Subscribe(const TScriptInterface<ITbRefIfacesSimpleLocalIfBPSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	Subscribers.Remove(Subscriber);
	Subscribers.Add(Subscriber);
}

void UTbRefIfacesSimpleLocalIfPublisher::Unsubscribe(const TScriptInterface<ITbRefIfacesSimpleLocalIfBPSubscriberInterface>& Subscriber)
{
	Subscribers.Remove(Subscriber);
}
