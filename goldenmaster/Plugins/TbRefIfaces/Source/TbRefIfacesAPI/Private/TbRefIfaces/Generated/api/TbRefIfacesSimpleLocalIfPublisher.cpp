
#include "TbRefIfaces/Generated/api/TbRefIfacesSimpleLocalIfInterface.h"
#include "Async/Async.h"
#include "Async/TaskGraphInterfaces.h"

void UTbRefIfacesSimpleLocalIfPublisher::BroadcastIntSignalSignal(int32 Param)
{
	OnIntSignalSignal.Broadcast(Param);

	TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnIntSignalSignalBP.Broadcast(Param);

		for (const TScriptInterface<ITbRefIfacesSimpleLocalIfBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbRefIfacesSimpleLocalIfBPSubscriberInterface::Execute_OnIntSignalSignal(Obj, Param);
			}
			else
			{
				Unsubscribe(Subscriber);
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
				else
				{
					if (WeakPtr.IsValid())
					{
						WeakPtr.Get()->Unsubscribe(Subscriber);
					}
				}
			}
		});
	}
}

void UTbRefIfacesSimpleLocalIfPublisher::BroadcastIntPropertyChanged(UPARAM(DisplayName = "IntProperty") int32 InIntProperty)
{
	OnIntPropertyChanged.Broadcast(InIntProperty);

	TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnIntPropertyChangedBP.Broadcast(InIntProperty);

		for (const TScriptInterface<ITbRefIfacesSimpleLocalIfBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbRefIfacesSimpleLocalIfBPSubscriberInterface::Execute_OnIntPropertyChanged(Obj, InIntProperty);
			}
			else
			{
				Unsubscribe(Subscriber);
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
				else
				{
					if (WeakPtr.IsValid())
					{
						WeakPtr.Get()->Unsubscribe(Subscriber);
					}
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

	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
	Subscribers.Add(Subscriber);
}

void UTbRefIfacesSimpleLocalIfPublisher::Unsubscribe(const TScriptInterface<ITbRefIfacesSimpleLocalIfBPSubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
}
