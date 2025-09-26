
#include "TbIfaceimport/Generated/api/TbIfaceimportEmptyIfInterface.h"
#include "TbRefIfaces/Generated/api/TbRefIfacesSimpleLocalIfInterface.h"
#include "TbRefIfaces/Generated/api/TbRefIfacesParentIfInterface.h"
#include "Async/Async.h"
#include "Async/TaskGraphInterfaces.h"
#include "Runtime/Launch/Resources/Version.h"

void UTbRefIfacesParentIfPublisher::BroadcastLocalIfSignalSignal(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Param)
{
	OnLocalIfSignalSignal.Broadcast(Param);
	TArray<TWeakInterfacePtr<ITbRefIfacesParentIfSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbRefIfacesParentIfSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbRefIfacesParentIfSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnLocalIfSignalSignal(Param);
			}
		}
	}

	TArray<TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnLocalIfSignalSignalBP.Broadcast(Param);

		for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnLocalIfSignalSignal(Obj, Param);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbRefIfacesParentIfPublisher>(this), BPSubscribersCopy, Param]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnLocalIfSignalSignalBP.Broadcast(Param);
			}

			for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnLocalIfSignalSignal(Obj, Param);
				}
			}
		});
	}

	CleanUpSubscribers();
}

void UTbRefIfacesParentIfPublisher::BroadcastLocalIfSignalListSignal(const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& Param)
{
	OnLocalIfSignalListSignal.Broadcast(Param);
	TArray<TWeakInterfacePtr<ITbRefIfacesParentIfSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbRefIfacesParentIfSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbRefIfacesParentIfSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnLocalIfSignalListSignal(Param);
			}
		}
	}

	TArray<TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnLocalIfSignalListSignalBP.Broadcast(Param);

		for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnLocalIfSignalListSignal(Obj, Param);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbRefIfacesParentIfPublisher>(this), BPSubscribersCopy, Param]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnLocalIfSignalListSignalBP.Broadcast(Param);
			}

			for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnLocalIfSignalListSignal(Obj, Param);
				}
			}
		});
	}

	CleanUpSubscribers();
}

void UTbRefIfacesParentIfPublisher::BroadcastImportedIfSignalSignal(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& Param)
{
	OnImportedIfSignalSignal.Broadcast(Param);
	TArray<TWeakInterfacePtr<ITbRefIfacesParentIfSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbRefIfacesParentIfSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbRefIfacesParentIfSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnImportedIfSignalSignal(Param);
			}
		}
	}

	TArray<TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnImportedIfSignalSignalBP.Broadcast(Param);

		for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnImportedIfSignalSignal(Obj, Param);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbRefIfacesParentIfPublisher>(this), BPSubscribersCopy, Param]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnImportedIfSignalSignalBP.Broadcast(Param);
			}

			for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnImportedIfSignalSignal(Obj, Param);
				}
			}
		});
	}

	CleanUpSubscribers();
}

void UTbRefIfacesParentIfPublisher::BroadcastImportedIfSignalListSignal(const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& Param)
{
	OnImportedIfSignalListSignal.Broadcast(Param);
	TArray<TWeakInterfacePtr<ITbRefIfacesParentIfSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbRefIfacesParentIfSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbRefIfacesParentIfSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnImportedIfSignalListSignal(Param);
			}
		}
	}

	TArray<TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnImportedIfSignalListSignalBP.Broadcast(Param);

		for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnImportedIfSignalListSignal(Obj, Param);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbRefIfacesParentIfPublisher>(this), BPSubscribersCopy, Param]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnImportedIfSignalListSignalBP.Broadcast(Param);
			}

			for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnImportedIfSignalListSignal(Obj, Param);
				}
			}
		});
	}

	CleanUpSubscribers();
}

void UTbRefIfacesParentIfPublisher::BroadcastLocalIfChanged(UPARAM(DisplayName = "LocalIf") const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& InLocalIf)
{
	OnLocalIfChanged.Broadcast(InLocalIf);
	TArray<TWeakInterfacePtr<ITbRefIfacesParentIfSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbRefIfacesParentIfSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbRefIfacesParentIfSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnLocalIfChanged(InLocalIf);
			}
		}
	}

	TArray<TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnLocalIfChangedBP.Broadcast(InLocalIf);

		for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnLocalIfChanged(Obj, InLocalIf);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbRefIfacesParentIfPublisher>(this), BPSubscribersCopy, InLocalIf]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnLocalIfChangedBP.Broadcast(InLocalIf);
			}

			for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnLocalIfChanged(Obj, InLocalIf);
				}
			}
		});
	}

	CleanUpSubscribers();
}

void UTbRefIfacesParentIfPublisher::BroadcastLocalIfListChanged(UPARAM(DisplayName = "LocalIfList") const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& InLocalIfList)
{
	OnLocalIfListChanged.Broadcast(InLocalIfList);
	TArray<TWeakInterfacePtr<ITbRefIfacesParentIfSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbRefIfacesParentIfSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbRefIfacesParentIfSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnLocalIfListChanged(InLocalIfList);
			}
		}
	}

	TArray<TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnLocalIfListChangedBP.Broadcast(InLocalIfList);

		for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnLocalIfListChanged(Obj, InLocalIfList);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbRefIfacesParentIfPublisher>(this), BPSubscribersCopy, InLocalIfList]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnLocalIfListChangedBP.Broadcast(InLocalIfList);
			}

			for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnLocalIfListChanged(Obj, InLocalIfList);
				}
			}
		});
	}

	CleanUpSubscribers();
}

void UTbRefIfacesParentIfPublisher::BroadcastImportedIfChanged(UPARAM(DisplayName = "ImportedIf") const TScriptInterface<ITbIfaceimportEmptyIfInterface>& InImportedIf)
{
	OnImportedIfChanged.Broadcast(InImportedIf);
	TArray<TWeakInterfacePtr<ITbRefIfacesParentIfSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbRefIfacesParentIfSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbRefIfacesParentIfSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnImportedIfChanged(InImportedIf);
			}
		}
	}

	TArray<TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnImportedIfChangedBP.Broadcast(InImportedIf);

		for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnImportedIfChanged(Obj, InImportedIf);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbRefIfacesParentIfPublisher>(this), BPSubscribersCopy, InImportedIf]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnImportedIfChangedBP.Broadcast(InImportedIf);
			}

			for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnImportedIfChanged(Obj, InImportedIf);
				}
			}
		});
	}

	CleanUpSubscribers();
}

void UTbRefIfacesParentIfPublisher::BroadcastImportedIfListChanged(UPARAM(DisplayName = "ImportedIfList") const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& InImportedIfList)
{
	OnImportedIfListChanged.Broadcast(InImportedIfList);
	TArray<TWeakInterfacePtr<ITbRefIfacesParentIfSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbRefIfacesParentIfSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbRefIfacesParentIfSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnImportedIfListChanged(InImportedIfList);
			}
		}
	}

	TArray<TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnImportedIfListChangedBP.Broadcast(InImportedIfList);

		for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnImportedIfListChanged(Obj, InImportedIfList);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbRefIfacesParentIfPublisher>(this), BPSubscribersCopy, InImportedIfList]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnImportedIfListChangedBP.Broadcast(InImportedIfList);
			}

			for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnImportedIfListChanged(Obj, InImportedIfList);
				}
			}
		});
	}

	CleanUpSubscribers();
}

void UTbRefIfacesParentIfPublisher::Subscribe(const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	FWriteScopeLock WriteLock(BPSubscribersLock);
	BPSubscribers.Remove(Subscriber);
	BPSubscribers.Add(Subscriber);
}

void UTbRefIfacesParentIfPublisher::Subscribe(const TWeakInterfacePtr<ITbRefIfacesParentIfSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
	Subscribers.Add(Subscriber);
}

void UTbRefIfacesParentIfPublisher::Unsubscribe(const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(BPSubscribersLock);
	BPSubscribers.Remove(Subscriber);
}

void UTbRefIfacesParentIfPublisher::Unsubscribe(const TWeakInterfacePtr<ITbRefIfacesParentIfSubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
}

void UTbRefIfacesParentIfPublisher::CleanUpSubscribers()
{
#if (ENGINE_MAJOR_VERSION >= 5)
	EAllowShrinking AllowShrinking = EAllowShrinking::No;
#else
	bool AllowShrinking = false;
#endif

	{
		FWriteScopeLock WriteLock(SubscribersLock);
		Subscribers.RemoveAllSwap([](const TWeakInterfacePtr<ITbRefIfacesParentIfSubscriberInterface>& Subscriber)
			{
			return !Subscriber.IsValid();
		},
			AllowShrinking);
	}
	{
		FWriteScopeLock WriteLock(BPSubscribersLock);
		BPSubscribers.RemoveAllSwap([](const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber)
			{
			return Subscriber.GetObject() == nullptr;
		},
			AllowShrinking);
	}
}
