
#include "TbRefIfaces/Generated/api/TbRefIfacesSimpleLocalIfInterface.h"
#include "Async/Async.h"
#include "Async/TaskGraphInterfaces.h"

void UTbRefIfacesSimpleLocalIfPublisher::BroadcastIntSignalSignal(int32 Param)
{
	OnIntSignalSignal.Broadcast(Param);

	TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfBPSubscriberInterface>> SubscribersCopy = Subscribers;
	if (IsInGameThread())
	{
		OnIntSignalSignalBP.Broadcast(Param);

		for (const TScriptInterface<ITbRefIfacesSimpleLocalIfBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbRefIfacesSimpleLocalIfBPSubscriberInterface::Execute_OnIntSignalSignal(Obj, Param);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbRefIfacesSimpleLocalIfPublisher>(this), SubscribersCopy, Param]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnIntSignalSignalBP.Broadcast(Param);
			}

			for (const TScriptInterface<ITbRefIfacesSimpleLocalIfBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbRefIfacesSimpleLocalIfBPSubscriberInterface::Execute_OnIntSignalSignal(Obj, Param);
				}
			}
		});
	}
}

void UTbRefIfacesSimpleLocalIfPublisher::BroadcastIntPropertyChanged(UPARAM(DisplayName = "IntProperty") int32 InIntProperty)
{
	OnIntPropertyChanged.Broadcast(InIntProperty);

	TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfBPSubscriberInterface>> SubscribersCopy = Subscribers;
	if (IsInGameThread())
	{
		OnIntPropertyChangedBP.Broadcast(InIntProperty);

		for (const TScriptInterface<ITbRefIfacesSimpleLocalIfBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbRefIfacesSimpleLocalIfBPSubscriberInterface::Execute_OnIntPropertyChanged(Obj, InIntProperty);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbRefIfacesSimpleLocalIfPublisher>(this), SubscribersCopy, InIntProperty]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnIntPropertyChangedBP.Broadcast(InIntProperty);
			}

			for (const TScriptInterface<ITbRefIfacesSimpleLocalIfBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbRefIfacesSimpleLocalIfBPSubscriberInterface::Execute_OnIntPropertyChanged(Obj, InIntProperty);
				}
			}
		});
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
