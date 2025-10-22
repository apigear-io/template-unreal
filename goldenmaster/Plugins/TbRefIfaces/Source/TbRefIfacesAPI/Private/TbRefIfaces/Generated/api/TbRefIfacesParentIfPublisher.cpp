
#include "TbIfaceimport/Generated/api/TbIfaceimportEmptyIfInterface.h"
#include "TbRefIfaces/Generated/api/TbRefIfacesSimpleLocalIfInterface.h"
#include "TbRefIfaces/Generated/api/TbRefIfacesParentIfInterface.h"
#include "Async/Async.h"
#include "Async/TaskGraphInterfaces.h"
#include "Runtime/Launch/Resources/Version.h"

void UTbRefIfacesParentIfPublisher::BroadcastLocalIfSignalSignal(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Param)
{
	TArray<TWeakInterfacePtr<ITbRefIfacesParentIfSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}

	TArray<TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnLocalIfSignalSignal.Broadcast(Param);
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

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTbRefIfacesParentIfPublisher>(this), BPSubscribersCopy, Param]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnLocalIfSignalSignalBP.Broadcast(Param);
		}

		for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnLocalIfSignalSignal(Obj, Param);
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

void UTbRefIfacesParentIfPublisher::BroadcastLocalIfSignalListSignal(const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& Param)
{
	TArray<TWeakInterfacePtr<ITbRefIfacesParentIfSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}

	TArray<TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnLocalIfSignalListSignal.Broadcast(Param);
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

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTbRefIfacesParentIfPublisher>(this), BPSubscribersCopy, Param]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnLocalIfSignalListSignalBP.Broadcast(Param);
		}

		for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnLocalIfSignalListSignal(Obj, Param);
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

void UTbRefIfacesParentIfPublisher::BroadcastImportedIfSignalSignal(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& Param)
{
	TArray<TWeakInterfacePtr<ITbRefIfacesParentIfSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}

	TArray<TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnImportedIfSignalSignal.Broadcast(Param);
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

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTbRefIfacesParentIfPublisher>(this), BPSubscribersCopy, Param]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnImportedIfSignalSignalBP.Broadcast(Param);
		}

		for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnImportedIfSignalSignal(Obj, Param);
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

void UTbRefIfacesParentIfPublisher::BroadcastImportedIfSignalListSignal(const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& Param)
{
	TArray<TWeakInterfacePtr<ITbRefIfacesParentIfSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}

	TArray<TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnImportedIfSignalListSignal.Broadcast(Param);
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

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTbRefIfacesParentIfPublisher>(this), BPSubscribersCopy, Param]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnImportedIfSignalListSignalBP.Broadcast(Param);
		}

		for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnImportedIfSignalListSignal(Obj, Param);
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

void UTbRefIfacesParentIfPublisher::BroadcastLocalIfChanged(UPARAM(DisplayName = "LocalIf") const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& InLocalIf)
{
	TArray<TWeakInterfacePtr<ITbRefIfacesParentIfSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnLocalIfChanged.Broadcast(InLocalIf);
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

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTbRefIfacesParentIfPublisher>(this), BPSubscribersCopy, InLocalIf]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnLocalIfChangedBP.Broadcast(InLocalIf);
		}

		for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnLocalIfChanged(Obj, InLocalIf);
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

void UTbRefIfacesParentIfPublisher::BroadcastLocalIfListChanged(UPARAM(DisplayName = "LocalIfList") const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& InLocalIfList)
{
	TArray<TWeakInterfacePtr<ITbRefIfacesParentIfSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnLocalIfListChanged.Broadcast(InLocalIfList);
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

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTbRefIfacesParentIfPublisher>(this), BPSubscribersCopy, InLocalIfList]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnLocalIfListChangedBP.Broadcast(InLocalIfList);
		}

		for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnLocalIfListChanged(Obj, InLocalIfList);
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

void UTbRefIfacesParentIfPublisher::BroadcastImportedIfChanged(UPARAM(DisplayName = "ImportedIf") const TScriptInterface<ITbIfaceimportEmptyIfInterface>& InImportedIf)
{
	TArray<TWeakInterfacePtr<ITbRefIfacesParentIfSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnImportedIfChanged.Broadcast(InImportedIf);
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

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTbRefIfacesParentIfPublisher>(this), BPSubscribersCopy, InImportedIf]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnImportedIfChangedBP.Broadcast(InImportedIf);
		}

		for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnImportedIfChanged(Obj, InImportedIf);
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

void UTbRefIfacesParentIfPublisher::BroadcastImportedIfListChanged(UPARAM(DisplayName = "ImportedIfList") const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& InImportedIfList)
{
	TArray<TWeakInterfacePtr<ITbRefIfacesParentIfSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnImportedIfListChanged.Broadcast(InImportedIfList);
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

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTbRefIfacesParentIfPublisher>(this), BPSubscribersCopy, InImportedIfList]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnImportedIfListChangedBP.Broadcast(InImportedIfList);
		}

		for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnImportedIfListChanged(Obj, InImportedIfList);
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
			UObject* Obj = Subscriber.GetObject();
			return !((Obj != nullptr) && IsValid(Obj));
		},
			AllowShrinking);
	}
}
