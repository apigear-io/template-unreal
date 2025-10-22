
#include "Testbed2/Generated/api/Testbed2NestedStruct3InterfaceInterface.h"
#include "Async/Async.h"
#include "Async/TaskGraphInterfaces.h"
#include "Runtime/Launch/Resources/Version.h"

void UTestbed2NestedStruct3InterfacePublisher::BroadcastSig1Signal(const FTestbed2NestedStruct1& Param1)
{
	TArray<TWeakInterfacePtr<ITestbed2NestedStruct3InterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}

	TArray<TScriptInterface<ITestbed2NestedStruct3InterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnSig1Signal.Broadcast(Param1);
	for (const TWeakInterfacePtr<ITestbed2NestedStruct3InterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed2NestedStruct3InterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSig1Signal(Param1);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTestbed2NestedStruct3InterfacePublisher>(this), BPSubscribersCopy, Param1]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnSig1SignalBP.Broadcast(Param1);
		}

		for (const TScriptInterface<ITestbed2NestedStruct3InterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITestbed2NestedStruct3InterfaceBPSubscriberInterface::Execute_OnSig1Signal(Obj, Param1);
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

void UTestbed2NestedStruct3InterfacePublisher::BroadcastSig2Signal(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	TArray<TWeakInterfacePtr<ITestbed2NestedStruct3InterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}

	TArray<TScriptInterface<ITestbed2NestedStruct3InterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnSig2Signal.Broadcast(Param1, Param2);
	for (const TWeakInterfacePtr<ITestbed2NestedStruct3InterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed2NestedStruct3InterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSig2Signal(Param1, Param2);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTestbed2NestedStruct3InterfacePublisher>(this), BPSubscribersCopy, Param1, Param2]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnSig2SignalBP.Broadcast(Param1, Param2);
		}

		for (const TScriptInterface<ITestbed2NestedStruct3InterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITestbed2NestedStruct3InterfaceBPSubscriberInterface::Execute_OnSig2Signal(Obj, Param1, Param2);
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

void UTestbed2NestedStruct3InterfacePublisher::BroadcastSig3Signal(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3)
{
	TArray<TWeakInterfacePtr<ITestbed2NestedStruct3InterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}

	TArray<TScriptInterface<ITestbed2NestedStruct3InterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnSig3Signal.Broadcast(Param1, Param2, Param3);
	for (const TWeakInterfacePtr<ITestbed2NestedStruct3InterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed2NestedStruct3InterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSig3Signal(Param1, Param2, Param3);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTestbed2NestedStruct3InterfacePublisher>(this), BPSubscribersCopy, Param1, Param2, Param3]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnSig3SignalBP.Broadcast(Param1, Param2, Param3);
		}

		for (const TScriptInterface<ITestbed2NestedStruct3InterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITestbed2NestedStruct3InterfaceBPSubscriberInterface::Execute_OnSig3Signal(Obj, Param1, Param2, Param3);
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

void UTestbed2NestedStruct3InterfacePublisher::BroadcastProp1Changed(UPARAM(DisplayName = "Prop1") const FTestbed2NestedStruct1& InProp1)
{
	TArray<TWeakInterfacePtr<ITestbed2NestedStruct3InterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITestbed2NestedStruct3InterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnProp1Changed.Broadcast(InProp1);
	for (const TWeakInterfacePtr<ITestbed2NestedStruct3InterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed2NestedStruct3InterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnProp1Changed(InProp1);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTestbed2NestedStruct3InterfacePublisher>(this), BPSubscribersCopy, InProp1]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnProp1ChangedBP.Broadcast(InProp1);
		}

		for (const TScriptInterface<ITestbed2NestedStruct3InterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITestbed2NestedStruct3InterfaceBPSubscriberInterface::Execute_OnProp1Changed(Obj, InProp1);
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

void UTestbed2NestedStruct3InterfacePublisher::BroadcastProp2Changed(UPARAM(DisplayName = "Prop2") const FTestbed2NestedStruct2& InProp2)
{
	TArray<TWeakInterfacePtr<ITestbed2NestedStruct3InterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITestbed2NestedStruct3InterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnProp2Changed.Broadcast(InProp2);
	for (const TWeakInterfacePtr<ITestbed2NestedStruct3InterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed2NestedStruct3InterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnProp2Changed(InProp2);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTestbed2NestedStruct3InterfacePublisher>(this), BPSubscribersCopy, InProp2]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnProp2ChangedBP.Broadcast(InProp2);
		}

		for (const TScriptInterface<ITestbed2NestedStruct3InterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITestbed2NestedStruct3InterfaceBPSubscriberInterface::Execute_OnProp2Changed(Obj, InProp2);
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

void UTestbed2NestedStruct3InterfacePublisher::BroadcastProp3Changed(UPARAM(DisplayName = "Prop3") const FTestbed2NestedStruct3& InProp3)
{
	TArray<TWeakInterfacePtr<ITestbed2NestedStruct3InterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITestbed2NestedStruct3InterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnProp3Changed.Broadcast(InProp3);
	for (const TWeakInterfacePtr<ITestbed2NestedStruct3InterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed2NestedStruct3InterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnProp3Changed(InProp3);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTestbed2NestedStruct3InterfacePublisher>(this), BPSubscribersCopy, InProp3]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnProp3ChangedBP.Broadcast(InProp3);
		}

		for (const TScriptInterface<ITestbed2NestedStruct3InterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITestbed2NestedStruct3InterfaceBPSubscriberInterface::Execute_OnProp3Changed(Obj, InProp3);
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

void UTestbed2NestedStruct3InterfacePublisher::Subscribe(const TScriptInterface<ITestbed2NestedStruct3InterfaceBPSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	FWriteScopeLock WriteLock(BPSubscribersLock);
	BPSubscribers.Remove(Subscriber);
	BPSubscribers.Add(Subscriber);
}

void UTestbed2NestedStruct3InterfacePublisher::Subscribe(const TWeakInterfacePtr<ITestbed2NestedStruct3InterfaceSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
	Subscribers.Add(Subscriber);
}

void UTestbed2NestedStruct3InterfacePublisher::Unsubscribe(const TScriptInterface<ITestbed2NestedStruct3InterfaceBPSubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(BPSubscribersLock);
	BPSubscribers.Remove(Subscriber);
}

void UTestbed2NestedStruct3InterfacePublisher::Unsubscribe(const TWeakInterfacePtr<ITestbed2NestedStruct3InterfaceSubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
}

void UTestbed2NestedStruct3InterfacePublisher::CleanUpSubscribers()
{
#if (ENGINE_MAJOR_VERSION >= 5)
	EAllowShrinking AllowShrinking = EAllowShrinking::No;
#else
	bool AllowShrinking = false;
#endif

	{
		FWriteScopeLock WriteLock(SubscribersLock);
		Subscribers.RemoveAllSwap([](const TWeakInterfacePtr<ITestbed2NestedStruct3InterfaceSubscriberInterface>& Subscriber)
			{
			return !Subscriber.IsValid();
		},
			AllowShrinking);
	}
	{
		FWriteScopeLock WriteLock(BPSubscribersLock);
		BPSubscribers.RemoveAllSwap([](const TScriptInterface<ITestbed2NestedStruct3InterfaceBPSubscriberInterface>& Subscriber)
			{
			UObject* Obj = Subscriber.GetObject();
			return !((Obj != nullptr) && IsValid(Obj));
		},
			AllowShrinking);
	}
}
