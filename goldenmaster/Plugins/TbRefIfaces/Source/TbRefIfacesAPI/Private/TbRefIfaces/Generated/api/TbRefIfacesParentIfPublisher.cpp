
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

	auto BroadcastAll = [WeakPtr = TWeakObjectPtr<UTbRefIfacesParentIfPublisher>(this), SubscribersCopy, BPSubscribersCopy, Param]()
	{
		if (!WeakPtr.IsValid())
		{
			return;
		}

		WeakPtr.Get()->OnLocalIfSignalSignal.Broadcast(Param);
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

		WeakPtr.Get()->OnLocalIfSignalSignalBP.Broadcast(Param);
		for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnLocalIfSignalSignal(Obj, Param);
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

	auto BroadcastAll = [WeakPtr = TWeakObjectPtr<UTbRefIfacesParentIfPublisher>(this), SubscribersCopy, BPSubscribersCopy, Param]()
	{
		if (!WeakPtr.IsValid())
		{
			return;
		}

		WeakPtr.Get()->OnLocalIfSignalListSignal.Broadcast(Param);
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

		WeakPtr.Get()->OnLocalIfSignalListSignalBP.Broadcast(Param);
		for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnLocalIfSignalListSignal(Obj, Param);
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

	auto BroadcastAll = [WeakPtr = TWeakObjectPtr<UTbRefIfacesParentIfPublisher>(this), SubscribersCopy, BPSubscribersCopy, Param]()
	{
		if (!WeakPtr.IsValid())
		{
			return;
		}

		WeakPtr.Get()->OnImportedIfSignalSignal.Broadcast(Param);
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

		WeakPtr.Get()->OnImportedIfSignalSignalBP.Broadcast(Param);
		for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnImportedIfSignalSignal(Obj, Param);
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

	auto BroadcastAll = [WeakPtr = TWeakObjectPtr<UTbRefIfacesParentIfPublisher>(this), SubscribersCopy, BPSubscribersCopy, Param]()
	{
		if (!WeakPtr.IsValid())
		{
			return;
		}

		WeakPtr.Get()->OnImportedIfSignalListSignal.Broadcast(Param);
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

		WeakPtr.Get()->OnImportedIfSignalListSignalBP.Broadcast(Param);
		for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnImportedIfSignalListSignal(Obj, Param);
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

	auto BroadcastAll = [WeakPtr = TWeakObjectPtr<UTbRefIfacesParentIfPublisher>(this), SubscribersCopy, BPSubscribersCopy, InLocalIf]()
	{
		if (!WeakPtr.IsValid())
		{
			return;
		}

		WeakPtr.Get()->OnLocalIfChanged.Broadcast(InLocalIf);
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

		WeakPtr.Get()->OnLocalIfChangedBP.Broadcast(InLocalIf);
		for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnLocalIfChanged(Obj, InLocalIf);
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

	auto BroadcastAll = [WeakPtr = TWeakObjectPtr<UTbRefIfacesParentIfPublisher>(this), SubscribersCopy, BPSubscribersCopy, InLocalIfList]()
	{
		if (!WeakPtr.IsValid())
		{
			return;
		}

		WeakPtr.Get()->OnLocalIfListChanged.Broadcast(InLocalIfList);
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

		WeakPtr.Get()->OnLocalIfListChangedBP.Broadcast(InLocalIfList);
		for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnLocalIfListChanged(Obj, InLocalIfList);
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

	auto BroadcastAll = [WeakPtr = TWeakObjectPtr<UTbRefIfacesParentIfPublisher>(this), SubscribersCopy, BPSubscribersCopy, InImportedIf]()
	{
		if (!WeakPtr.IsValid())
		{
			return;
		}

		WeakPtr.Get()->OnImportedIfChanged.Broadcast(InImportedIf);
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

		WeakPtr.Get()->OnImportedIfChangedBP.Broadcast(InImportedIf);
		for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnImportedIfChanged(Obj, InImportedIf);
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

	auto BroadcastAll = [WeakPtr = TWeakObjectPtr<UTbRefIfacesParentIfPublisher>(this), SubscribersCopy, BPSubscribersCopy, InImportedIfList]()
	{
		if (!WeakPtr.IsValid())
		{
			return;
		}

		WeakPtr.Get()->OnImportedIfListChanged.Broadcast(InImportedIfList);
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

		WeakPtr.Get()->OnImportedIfListChangedBP.Broadcast(InImportedIfList);
		for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnImportedIfListChanged(Obj, InImportedIfList);
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
