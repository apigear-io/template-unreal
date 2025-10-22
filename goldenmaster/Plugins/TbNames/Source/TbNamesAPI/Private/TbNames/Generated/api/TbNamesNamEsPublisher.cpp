
#include "TbNames/Generated/api/TbNamesNamEsInterface.h"
#include "Async/Async.h"
#include "Async/TaskGraphInterfaces.h"
#include "Runtime/Launch/Resources/Version.h"

void UTbNamesNamEsPublisher::BroadcastSomeSignalSignal(bool bSomeParam)
{
	TArray<TWeakInterfacePtr<ITbNamesNamEsSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}

	TArray<TScriptInterface<ITbNamesNamEsBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnSomeSignalSignal.Broadcast(bSomeParam);
	for (const TWeakInterfacePtr<ITbNamesNamEsSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbNamesNamEsSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSomeSignalSignal(bSomeParam);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTbNamesNamEsPublisher>(this), BPSubscribersCopy, bSomeParam]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnSomeSignalSignalBP.Broadcast(bSomeParam);
		}

		for (const TScriptInterface<ITbNamesNamEsBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbNamesNamEsBPSubscriberInterface::Execute_OnSomeSignalSignal(Obj, bSomeParam);
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

void UTbNamesNamEsPublisher::BroadcastSomeSignal2Signal(bool bSomeParam)
{
	TArray<TWeakInterfacePtr<ITbNamesNamEsSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}

	TArray<TScriptInterface<ITbNamesNamEsBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnSomeSignal2Signal.Broadcast(bSomeParam);
	for (const TWeakInterfacePtr<ITbNamesNamEsSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbNamesNamEsSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSomeSignal2Signal(bSomeParam);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTbNamesNamEsPublisher>(this), BPSubscribersCopy, bSomeParam]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnSomeSignal2SignalBP.Broadcast(bSomeParam);
		}

		for (const TScriptInterface<ITbNamesNamEsBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbNamesNamEsBPSubscriberInterface::Execute_OnSomeSignal2Signal(Obj, bSomeParam);
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

void UTbNamesNamEsPublisher::BroadcastSwitchChanged(UPARAM(DisplayName = "bSwitch") bool bInSwitch)
{
	TArray<TWeakInterfacePtr<ITbNamesNamEsSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITbNamesNamEsBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnSwitchChanged.Broadcast(bInSwitch);
	for (const TWeakInterfacePtr<ITbNamesNamEsSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbNamesNamEsSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSwitchChanged(bInSwitch);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTbNamesNamEsPublisher>(this), BPSubscribersCopy, bInSwitch]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnSwitchChangedBP.Broadcast(bInSwitch);
		}

		for (const TScriptInterface<ITbNamesNamEsBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbNamesNamEsBPSubscriberInterface::Execute_OnSwitchChanged(Obj, bInSwitch);
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

void UTbNamesNamEsPublisher::BroadcastSomePropertyChanged(UPARAM(DisplayName = "SomeProperty") int32 InSomeProperty)
{
	TArray<TWeakInterfacePtr<ITbNamesNamEsSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITbNamesNamEsBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnSomePropertyChanged.Broadcast(InSomeProperty);
	for (const TWeakInterfacePtr<ITbNamesNamEsSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbNamesNamEsSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSomePropertyChanged(InSomeProperty);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTbNamesNamEsPublisher>(this), BPSubscribersCopy, InSomeProperty]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnSomePropertyChangedBP.Broadcast(InSomeProperty);
		}

		for (const TScriptInterface<ITbNamesNamEsBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbNamesNamEsBPSubscriberInterface::Execute_OnSomePropertyChanged(Obj, InSomeProperty);
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

void UTbNamesNamEsPublisher::BroadcastSomePoperty2Changed(UPARAM(DisplayName = "SomePoperty2") int32 InSomePoperty2)
{
	TArray<TWeakInterfacePtr<ITbNamesNamEsSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITbNamesNamEsBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnSomePoperty2Changed.Broadcast(InSomePoperty2);
	for (const TWeakInterfacePtr<ITbNamesNamEsSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbNamesNamEsSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSomePoperty2Changed(InSomePoperty2);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTbNamesNamEsPublisher>(this), BPSubscribersCopy, InSomePoperty2]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnSomePoperty2ChangedBP.Broadcast(InSomePoperty2);
		}

		for (const TScriptInterface<ITbNamesNamEsBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbNamesNamEsBPSubscriberInterface::Execute_OnSomePoperty2Changed(Obj, InSomePoperty2);
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

void UTbNamesNamEsPublisher::BroadcastEnumPropertyChanged(UPARAM(DisplayName = "EnumProperty") ETbNamesEnum_With_Under_scores InEnumProperty)
{
	TArray<TWeakInterfacePtr<ITbNamesNamEsSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITbNamesNamEsBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnEnumPropertyChanged.Broadcast(InEnumProperty);
	for (const TWeakInterfacePtr<ITbNamesNamEsSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbNamesNamEsSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnEnumPropertyChanged(InEnumProperty);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTbNamesNamEsPublisher>(this), BPSubscribersCopy, InEnumProperty]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnEnumPropertyChangedBP.Broadcast(InEnumProperty);
		}

		for (const TScriptInterface<ITbNamesNamEsBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbNamesNamEsBPSubscriberInterface::Execute_OnEnumPropertyChanged(Obj, InEnumProperty);
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

void UTbNamesNamEsPublisher::Subscribe(const TScriptInterface<ITbNamesNamEsBPSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	FWriteScopeLock WriteLock(BPSubscribersLock);
	BPSubscribers.Remove(Subscriber);
	BPSubscribers.Add(Subscriber);
}

void UTbNamesNamEsPublisher::Subscribe(const TWeakInterfacePtr<ITbNamesNamEsSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
	Subscribers.Add(Subscriber);
}

void UTbNamesNamEsPublisher::Unsubscribe(const TScriptInterface<ITbNamesNamEsBPSubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(BPSubscribersLock);
	BPSubscribers.Remove(Subscriber);
}

void UTbNamesNamEsPublisher::Unsubscribe(const TWeakInterfacePtr<ITbNamesNamEsSubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
}

void UTbNamesNamEsPublisher::CleanUpSubscribers()
{
#if (ENGINE_MAJOR_VERSION >= 5)
	EAllowShrinking AllowShrinking = EAllowShrinking::No;
#else
	bool AllowShrinking = false;
#endif

	{
		FWriteScopeLock WriteLock(SubscribersLock);
		Subscribers.RemoveAllSwap([](const TWeakInterfacePtr<ITbNamesNamEsSubscriberInterface>& Subscriber)
			{
			return !Subscriber.IsValid();
		},
			AllowShrinking);
	}
	{
		FWriteScopeLock WriteLock(BPSubscribersLock);
		BPSubscribers.RemoveAllSwap([](const TScriptInterface<ITbNamesNamEsBPSubscriberInterface>& Subscriber)
			{
			UObject* Obj = Subscriber.GetObject();
			return !((Obj != nullptr) && IsValid(Obj));
		},
			AllowShrinking);
	}
}
