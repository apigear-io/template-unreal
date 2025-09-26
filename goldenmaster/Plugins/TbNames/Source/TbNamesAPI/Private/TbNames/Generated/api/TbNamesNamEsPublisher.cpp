
#include "TbNames/Generated/api/TbNamesNamEsInterface.h"
#include "Async/Async.h"
#include "Async/TaskGraphInterfaces.h"
#include "Runtime/Launch/Resources/Version.h"

void UTbNamesNamEsPublisher::BroadcastSomeSignalSignal(bool bSomeParam)
{
	OnSomeSignalSignal.Broadcast(bSomeParam);
	TArray<TWeakInterfacePtr<ITbNamesNamEsSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
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

	TArray<TScriptInterface<ITbNamesNamEsBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnSomeSignalSignalBP.Broadcast(bSomeParam);

		for (const TScriptInterface<ITbNamesNamEsBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbNamesNamEsBPSubscriberInterface::Execute_OnSomeSignalSignal(Obj, bSomeParam);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbNamesNamEsPublisher>(this), BPSubscribersCopy, bSomeParam]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSomeSignalSignalBP.Broadcast(bSomeParam);
			}

			for (const TScriptInterface<ITbNamesNamEsBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbNamesNamEsBPSubscriberInterface::Execute_OnSomeSignalSignal(Obj, bSomeParam);
				}
			}
		});
	}

	CleanUpSubscribers();
}

void UTbNamesNamEsPublisher::BroadcastSomeSignal2Signal(bool bSomeParam)
{
	OnSomeSignal2Signal.Broadcast(bSomeParam);
	TArray<TWeakInterfacePtr<ITbNamesNamEsSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
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

	TArray<TScriptInterface<ITbNamesNamEsBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnSomeSignal2SignalBP.Broadcast(bSomeParam);

		for (const TScriptInterface<ITbNamesNamEsBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbNamesNamEsBPSubscriberInterface::Execute_OnSomeSignal2Signal(Obj, bSomeParam);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbNamesNamEsPublisher>(this), BPSubscribersCopy, bSomeParam]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSomeSignal2SignalBP.Broadcast(bSomeParam);
			}

			for (const TScriptInterface<ITbNamesNamEsBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbNamesNamEsBPSubscriberInterface::Execute_OnSomeSignal2Signal(Obj, bSomeParam);
				}
			}
		});
	}

	CleanUpSubscribers();
}

void UTbNamesNamEsPublisher::BroadcastSwitchChanged(UPARAM(DisplayName = "bSwitch") bool bInSwitch)
{
	OnSwitchChanged.Broadcast(bInSwitch);
	TArray<TWeakInterfacePtr<ITbNamesNamEsSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
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

	TArray<TScriptInterface<ITbNamesNamEsBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnSwitchChangedBP.Broadcast(bInSwitch);

		for (const TScriptInterface<ITbNamesNamEsBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbNamesNamEsBPSubscriberInterface::Execute_OnSwitchChanged(Obj, bInSwitch);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbNamesNamEsPublisher>(this), BPSubscribersCopy, bInSwitch]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSwitchChangedBP.Broadcast(bInSwitch);
			}

			for (const TScriptInterface<ITbNamesNamEsBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbNamesNamEsBPSubscriberInterface::Execute_OnSwitchChanged(Obj, bInSwitch);
				}
			}
		});
	}

	CleanUpSubscribers();
}

void UTbNamesNamEsPublisher::BroadcastSomePropertyChanged(UPARAM(DisplayName = "SomeProperty") int32 InSomeProperty)
{
	OnSomePropertyChanged.Broadcast(InSomeProperty);
	TArray<TWeakInterfacePtr<ITbNamesNamEsSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
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

	TArray<TScriptInterface<ITbNamesNamEsBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnSomePropertyChangedBP.Broadcast(InSomeProperty);

		for (const TScriptInterface<ITbNamesNamEsBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbNamesNamEsBPSubscriberInterface::Execute_OnSomePropertyChanged(Obj, InSomeProperty);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbNamesNamEsPublisher>(this), BPSubscribersCopy, InSomeProperty]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSomePropertyChangedBP.Broadcast(InSomeProperty);
			}

			for (const TScriptInterface<ITbNamesNamEsBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbNamesNamEsBPSubscriberInterface::Execute_OnSomePropertyChanged(Obj, InSomeProperty);
				}
			}
		});
	}

	CleanUpSubscribers();
}

void UTbNamesNamEsPublisher::BroadcastSomePoperty2Changed(UPARAM(DisplayName = "SomePoperty2") int32 InSomePoperty2)
{
	OnSomePoperty2Changed.Broadcast(InSomePoperty2);
	TArray<TWeakInterfacePtr<ITbNamesNamEsSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
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

	TArray<TScriptInterface<ITbNamesNamEsBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnSomePoperty2ChangedBP.Broadcast(InSomePoperty2);

		for (const TScriptInterface<ITbNamesNamEsBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbNamesNamEsBPSubscriberInterface::Execute_OnSomePoperty2Changed(Obj, InSomePoperty2);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbNamesNamEsPublisher>(this), BPSubscribersCopy, InSomePoperty2]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSomePoperty2ChangedBP.Broadcast(InSomePoperty2);
			}

			for (const TScriptInterface<ITbNamesNamEsBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbNamesNamEsBPSubscriberInterface::Execute_OnSomePoperty2Changed(Obj, InSomePoperty2);
				}
			}
		});
	}

	CleanUpSubscribers();
}

void UTbNamesNamEsPublisher::BroadcastEnumPropertyChanged(UPARAM(DisplayName = "EnumProperty") ETbNamesEnum_With_Under_scores InEnumProperty)
{
	OnEnumPropertyChanged.Broadcast(InEnumProperty);
	TArray<TWeakInterfacePtr<ITbNamesNamEsSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
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

	TArray<TScriptInterface<ITbNamesNamEsBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnEnumPropertyChangedBP.Broadcast(InEnumProperty);

		for (const TScriptInterface<ITbNamesNamEsBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbNamesNamEsBPSubscriberInterface::Execute_OnEnumPropertyChanged(Obj, InEnumProperty);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbNamesNamEsPublisher>(this), BPSubscribersCopy, InEnumProperty]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnEnumPropertyChangedBP.Broadcast(InEnumProperty);
			}

			for (const TScriptInterface<ITbNamesNamEsBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbNamesNamEsBPSubscriberInterface::Execute_OnEnumPropertyChanged(Obj, InEnumProperty);
				}
			}
		});
	}

	CleanUpSubscribers();
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
			return Subscriber.GetObject() == nullptr;
		},
			AllowShrinking);
	}
}
