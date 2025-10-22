
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

	OnIntSignalSignal.Broadcast(Param);
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

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTbRefIfacesSimpleLocalIfPublisher>(this), BPSubscribersCopy, Param]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnIntSignalSignalBP.Broadcast(Param);
		}

		for (const TScriptInterface<ITbRefIfacesSimpleLocalIfBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbRefIfacesSimpleLocalIfBPSubscriberInterface::Execute_OnIntSignalSignal(Obj, Param);
			}
		}

		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->CleanUpSubscribers();
		}
	};

	if (IsInGameThread())
	{
		BroadCastOnGameThread();
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, MoveTemp(BroadCastOnGameThread));
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

	OnIntPropertyChanged.Broadcast(InIntProperty);
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

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTbRefIfacesSimpleLocalIfPublisher>(this), BPSubscribersCopy, InIntProperty]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnIntPropertyChangedBP.Broadcast(InIntProperty);
		}

		for (const TScriptInterface<ITbRefIfacesSimpleLocalIfBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbRefIfacesSimpleLocalIfBPSubscriberInterface::Execute_OnIntPropertyChanged(Obj, InIntProperty);
			}
		}

		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->CleanUpSubscribers();
		}
	};
	if (IsInGameThread())
	{
		BroadCastOnGameThread();
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, MoveTemp(BroadCastOnGameThread));
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
