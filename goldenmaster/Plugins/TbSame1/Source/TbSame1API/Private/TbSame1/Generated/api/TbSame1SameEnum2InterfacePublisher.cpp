
#include "TbSame1/Generated/api/TbSame1SameEnum2InterfaceInterface.h"
#include "Async/Async.h"
#include "Async/TaskGraphInterfaces.h"
#include "Runtime/Launch/Resources/Version.h"

void UTbSame1SameEnum2InterfacePublisher::BroadcastSig1Signal(ETbSame1Enum1 Param1)
{
	TArray<TWeakInterfacePtr<ITbSame1SameEnum2InterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}

	TArray<TScriptInterface<ITbSame1SameEnum2InterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnSig1Signal.Broadcast(Param1);
	for (const TWeakInterfacePtr<ITbSame1SameEnum2InterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSame1SameEnum2InterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSig1Signal(Param1);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTbSame1SameEnum2InterfacePublisher>(this), BPSubscribersCopy, Param1]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnSig1SignalBP.Broadcast(Param1);
		}

		for (const TScriptInterface<ITbSame1SameEnum2InterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSame1SameEnum2InterfaceBPSubscriberInterface::Execute_OnSig1Signal(Obj, Param1);
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

void UTbSame1SameEnum2InterfacePublisher::BroadcastSig2Signal(ETbSame1Enum1 Param1, ETbSame1Enum2 Param2)
{
	TArray<TWeakInterfacePtr<ITbSame1SameEnum2InterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}

	TArray<TScriptInterface<ITbSame1SameEnum2InterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnSig2Signal.Broadcast(Param1, Param2);
	for (const TWeakInterfacePtr<ITbSame1SameEnum2InterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSame1SameEnum2InterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSig2Signal(Param1, Param2);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTbSame1SameEnum2InterfacePublisher>(this), BPSubscribersCopy, Param1, Param2]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnSig2SignalBP.Broadcast(Param1, Param2);
		}

		for (const TScriptInterface<ITbSame1SameEnum2InterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSame1SameEnum2InterfaceBPSubscriberInterface::Execute_OnSig2Signal(Obj, Param1, Param2);
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

void UTbSame1SameEnum2InterfacePublisher::BroadcastProp1Changed(UPARAM(DisplayName = "Prop1") ETbSame1Enum1 InProp1)
{
	TArray<TWeakInterfacePtr<ITbSame1SameEnum2InterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITbSame1SameEnum2InterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnProp1Changed.Broadcast(InProp1);
	for (const TWeakInterfacePtr<ITbSame1SameEnum2InterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSame1SameEnum2InterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnProp1Changed(InProp1);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTbSame1SameEnum2InterfacePublisher>(this), BPSubscribersCopy, InProp1]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnProp1ChangedBP.Broadcast(InProp1);
		}

		for (const TScriptInterface<ITbSame1SameEnum2InterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSame1SameEnum2InterfaceBPSubscriberInterface::Execute_OnProp1Changed(Obj, InProp1);
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

void UTbSame1SameEnum2InterfacePublisher::BroadcastProp2Changed(UPARAM(DisplayName = "Prop2") ETbSame1Enum2 InProp2)
{
	TArray<TWeakInterfacePtr<ITbSame1SameEnum2InterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITbSame1SameEnum2InterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnProp2Changed.Broadcast(InProp2);
	for (const TWeakInterfacePtr<ITbSame1SameEnum2InterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSame1SameEnum2InterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnProp2Changed(InProp2);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTbSame1SameEnum2InterfacePublisher>(this), BPSubscribersCopy, InProp2]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnProp2ChangedBP.Broadcast(InProp2);
		}

		for (const TScriptInterface<ITbSame1SameEnum2InterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSame1SameEnum2InterfaceBPSubscriberInterface::Execute_OnProp2Changed(Obj, InProp2);
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

void UTbSame1SameEnum2InterfacePublisher::Subscribe(const TScriptInterface<ITbSame1SameEnum2InterfaceBPSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	FWriteScopeLock WriteLock(BPSubscribersLock);
	BPSubscribers.Remove(Subscriber);
	BPSubscribers.Add(Subscriber);
}

void UTbSame1SameEnum2InterfacePublisher::Subscribe(const TWeakInterfacePtr<ITbSame1SameEnum2InterfaceSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
	Subscribers.Add(Subscriber);
}

void UTbSame1SameEnum2InterfacePublisher::Unsubscribe(const TScriptInterface<ITbSame1SameEnum2InterfaceBPSubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(BPSubscribersLock);
	BPSubscribers.Remove(Subscriber);
}

void UTbSame1SameEnum2InterfacePublisher::Unsubscribe(const TWeakInterfacePtr<ITbSame1SameEnum2InterfaceSubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
}

void UTbSame1SameEnum2InterfacePublisher::CleanUpSubscribers()
{
#if (ENGINE_MAJOR_VERSION >= 5)
	EAllowShrinking AllowShrinking = EAllowShrinking::No;
#else
	bool AllowShrinking = false;
#endif

	{
		FWriteScopeLock WriteLock(SubscribersLock);
		Subscribers.RemoveAllSwap([](const TWeakInterfacePtr<ITbSame1SameEnum2InterfaceSubscriberInterface>& Subscriber)
			{
			return !Subscriber.IsValid();
		},
			AllowShrinking);
	}
	{
		FWriteScopeLock WriteLock(BPSubscribersLock);
		BPSubscribers.RemoveAllSwap([](const TScriptInterface<ITbSame1SameEnum2InterfaceBPSubscriberInterface>& Subscriber)
			{
			return Subscriber.GetObject() == nullptr;
		},
			AllowShrinking);
	}
}
