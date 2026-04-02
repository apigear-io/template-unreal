
#include "TbRefIfaces/Generated/api/TbRefIfacesSimpleLocalIfInterface.h"
#include "Async/Async.h"
#include "Async/TaskGraphInterfaces.h"
#include "Runtime/Launch/Resources/Version.h"

void UTbRefIfacesSimpleLocalIfPublisher::BroadcastIntSignalSignal(int32 Param)
{
	TArray<TWeakInterfacePtr<ITbRefIfacesSimpleLocalIfSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}

	TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	auto BroadcastAll = [WeakPtr = TWeakObjectPtr<UTbRefIfacesSimpleLocalIfPublisher>(this), SubscribersCopy, BPSubscribersCopy, Param]()
	{
		if (!WeakPtr.IsValid())
		{
			return;
		}

		WeakPtr.Get()->OnIntSignalSignal.Broadcast(Param);
		for (const TWeakInterfacePtr<ITbRefIfacesSimpleLocalIfSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (Subscriber.IsValid())
			{
				if (ITbRefIfacesSimpleLocalIfSubscriberInterface* Iface = Subscriber.Get())
				{
					Iface->OnIntSignalSignal(Param);
				}
			}
		}

		WeakPtr.Get()->OnIntSignalSignalBP.Broadcast(Param);
		for (const TScriptInterface<ITbRefIfacesSimpleLocalIfBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbRefIfacesSimpleLocalIfBPSubscriberInterface::Execute_OnIntSignalSignal(Obj, Param);
			}
		}

		WeakPtr.Get()->CleanUpSubscribers();
	};

	if (IsInGameThread())
	{
		BroadcastAll();
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, MoveTemp(BroadcastAll));
	}
}

void UTbRefIfacesSimpleLocalIfPublisher::BroadcastIntPropertyChanged(UPARAM(DisplayName = "IntProperty") int32 InIntProperty)
{
	TArray<TWeakInterfacePtr<ITbRefIfacesSimpleLocalIfSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	auto BroadcastAll = [WeakPtr = TWeakObjectPtr<UTbRefIfacesSimpleLocalIfPublisher>(this), SubscribersCopy, BPSubscribersCopy, InIntProperty]()
	{
		if (!WeakPtr.IsValid())
		{
			return;
		}

		WeakPtr.Get()->OnIntPropertyChanged.Broadcast(InIntProperty);
		for (const TWeakInterfacePtr<ITbRefIfacesSimpleLocalIfSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (Subscriber.IsValid())
			{
				if (ITbRefIfacesSimpleLocalIfSubscriberInterface* Iface = Subscriber.Get())
				{
					Iface->OnIntPropertyChanged(InIntProperty);
				}
			}
		}

		WeakPtr.Get()->OnIntPropertyChangedBP.Broadcast(InIntProperty);
		for (const TScriptInterface<ITbRefIfacesSimpleLocalIfBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbRefIfacesSimpleLocalIfBPSubscriberInterface::Execute_OnIntPropertyChanged(Obj, InIntProperty);
			}
		}

		WeakPtr.Get()->CleanUpSubscribers();
	};

	if (IsInGameThread())
	{
		BroadcastAll();
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, MoveTemp(BroadcastAll));
	}
}

void UTbRefIfacesSimpleLocalIfPublisher::Subscribe(const TScriptInterface<ITbRefIfacesSimpleLocalIfBPSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	FWriteScopeLock WriteLock(BPSubscribersLock);
	BPSubscribers.Remove(Subscriber);
	BPSubscribers.Add(Subscriber);
}

void UTbRefIfacesSimpleLocalIfPublisher::Subscribe(const TWeakInterfacePtr<ITbRefIfacesSimpleLocalIfSubscriberInterface>& Subscriber)
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
	FWriteScopeLock WriteLock(BPSubscribersLock);
	BPSubscribers.Remove(Subscriber);
}

void UTbRefIfacesSimpleLocalIfPublisher::Unsubscribe(const TWeakInterfacePtr<ITbRefIfacesSimpleLocalIfSubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
}

void UTbRefIfacesSimpleLocalIfPublisher::CleanUpSubscribers()
{
#if (ENGINE_MAJOR_VERSION >= 5)
	EAllowShrinking AllowShrinking = EAllowShrinking::No;
#else
	bool AllowShrinking = false;
#endif

	{
		FWriteScopeLock WriteLock(SubscribersLock);
		Subscribers.RemoveAllSwap([](const TWeakInterfacePtr<ITbRefIfacesSimpleLocalIfSubscriberInterface>& Subscriber)
			{
			return !Subscriber.IsValid();
		},
			AllowShrinking);
	}
	{
		FWriteScopeLock WriteLock(BPSubscribersLock);
		BPSubscribers.RemoveAllSwap([](const TScriptInterface<ITbRefIfacesSimpleLocalIfBPSubscriberInterface>& Subscriber)
			{
			UObject* Obj = Subscriber.GetObject();
			return !((Obj != nullptr) && IsValid(Obj));
		},
			AllowShrinking);
	}
}
