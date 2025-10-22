
#include "Testbed2/Generated/api/Testbed2ManyParamInterfaceInterface.h"
#include "Async/Async.h"
#include "Async/TaskGraphInterfaces.h"
#include "Runtime/Launch/Resources/Version.h"

void UTestbed2ManyParamInterfacePublisher::BroadcastSig1Signal(int32 Param1)
{
	TArray<TWeakInterfacePtr<ITestbed2ManyParamInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}

	TArray<TScriptInterface<ITestbed2ManyParamInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnSig1Signal.Broadcast(Param1);
	for (const TWeakInterfacePtr<ITestbed2ManyParamInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed2ManyParamInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSig1Signal(Param1);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTestbed2ManyParamInterfacePublisher>(this), BPSubscribersCopy, Param1]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnSig1SignalBP.Broadcast(Param1);
		}

		for (const TScriptInterface<ITestbed2ManyParamInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITestbed2ManyParamInterfaceBPSubscriberInterface::Execute_OnSig1Signal(Obj, Param1);
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

void UTestbed2ManyParamInterfacePublisher::BroadcastSig2Signal(int32 Param1, int32 Param2)
{
	TArray<TWeakInterfacePtr<ITestbed2ManyParamInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}

	TArray<TScriptInterface<ITestbed2ManyParamInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnSig2Signal.Broadcast(Param1, Param2);
	for (const TWeakInterfacePtr<ITestbed2ManyParamInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed2ManyParamInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSig2Signal(Param1, Param2);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTestbed2ManyParamInterfacePublisher>(this), BPSubscribersCopy, Param1, Param2]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnSig2SignalBP.Broadcast(Param1, Param2);
		}

		for (const TScriptInterface<ITestbed2ManyParamInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITestbed2ManyParamInterfaceBPSubscriberInterface::Execute_OnSig2Signal(Obj, Param1, Param2);
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

void UTestbed2ManyParamInterfacePublisher::BroadcastSig3Signal(int32 Param1, int32 Param2, int32 Param3)
{
	TArray<TWeakInterfacePtr<ITestbed2ManyParamInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}

	TArray<TScriptInterface<ITestbed2ManyParamInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnSig3Signal.Broadcast(Param1, Param2, Param3);
	for (const TWeakInterfacePtr<ITestbed2ManyParamInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed2ManyParamInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSig3Signal(Param1, Param2, Param3);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTestbed2ManyParamInterfacePublisher>(this), BPSubscribersCopy, Param1, Param2, Param3]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnSig3SignalBP.Broadcast(Param1, Param2, Param3);
		}

		for (const TScriptInterface<ITestbed2ManyParamInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITestbed2ManyParamInterfaceBPSubscriberInterface::Execute_OnSig3Signal(Obj, Param1, Param2, Param3);
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

void UTestbed2ManyParamInterfacePublisher::BroadcastSig4Signal(int32 Param1, int32 Param2, int32 Param3, int32 Param4)
{
	TArray<TWeakInterfacePtr<ITestbed2ManyParamInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}

	TArray<TScriptInterface<ITestbed2ManyParamInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnSig4Signal.Broadcast(Param1, Param2, Param3, Param4);
	for (const TWeakInterfacePtr<ITestbed2ManyParamInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed2ManyParamInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSig4Signal(Param1, Param2, Param3, Param4);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTestbed2ManyParamInterfacePublisher>(this), BPSubscribersCopy, Param1, Param2, Param3, Param4]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnSig4SignalBP.Broadcast(Param1, Param2, Param3, Param4);
		}

		for (const TScriptInterface<ITestbed2ManyParamInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITestbed2ManyParamInterfaceBPSubscriberInterface::Execute_OnSig4Signal(Obj, Param1, Param2, Param3, Param4);
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

void UTestbed2ManyParamInterfacePublisher::BroadcastProp1Changed(UPARAM(DisplayName = "Prop1") int32 InProp1)
{
	TArray<TWeakInterfacePtr<ITestbed2ManyParamInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITestbed2ManyParamInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnProp1Changed.Broadcast(InProp1);
	for (const TWeakInterfacePtr<ITestbed2ManyParamInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed2ManyParamInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnProp1Changed(InProp1);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTestbed2ManyParamInterfacePublisher>(this), BPSubscribersCopy, InProp1]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnProp1ChangedBP.Broadcast(InProp1);
		}

		for (const TScriptInterface<ITestbed2ManyParamInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITestbed2ManyParamInterfaceBPSubscriberInterface::Execute_OnProp1Changed(Obj, InProp1);
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

void UTestbed2ManyParamInterfacePublisher::BroadcastProp2Changed(UPARAM(DisplayName = "Prop2") int32 InProp2)
{
	TArray<TWeakInterfacePtr<ITestbed2ManyParamInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITestbed2ManyParamInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnProp2Changed.Broadcast(InProp2);
	for (const TWeakInterfacePtr<ITestbed2ManyParamInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed2ManyParamInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnProp2Changed(InProp2);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTestbed2ManyParamInterfacePublisher>(this), BPSubscribersCopy, InProp2]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnProp2ChangedBP.Broadcast(InProp2);
		}

		for (const TScriptInterface<ITestbed2ManyParamInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITestbed2ManyParamInterfaceBPSubscriberInterface::Execute_OnProp2Changed(Obj, InProp2);
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

void UTestbed2ManyParamInterfacePublisher::BroadcastProp3Changed(UPARAM(DisplayName = "Prop3") int32 InProp3)
{
	TArray<TWeakInterfacePtr<ITestbed2ManyParamInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITestbed2ManyParamInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnProp3Changed.Broadcast(InProp3);
	for (const TWeakInterfacePtr<ITestbed2ManyParamInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed2ManyParamInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnProp3Changed(InProp3);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTestbed2ManyParamInterfacePublisher>(this), BPSubscribersCopy, InProp3]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnProp3ChangedBP.Broadcast(InProp3);
		}

		for (const TScriptInterface<ITestbed2ManyParamInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITestbed2ManyParamInterfaceBPSubscriberInterface::Execute_OnProp3Changed(Obj, InProp3);
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

void UTestbed2ManyParamInterfacePublisher::BroadcastProp4Changed(UPARAM(DisplayName = "Prop4") int32 InProp4)
{
	TArray<TWeakInterfacePtr<ITestbed2ManyParamInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITestbed2ManyParamInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnProp4Changed.Broadcast(InProp4);
	for (const TWeakInterfacePtr<ITestbed2ManyParamInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed2ManyParamInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnProp4Changed(InProp4);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTestbed2ManyParamInterfacePublisher>(this), BPSubscribersCopy, InProp4]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnProp4ChangedBP.Broadcast(InProp4);
		}

		for (const TScriptInterface<ITestbed2ManyParamInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITestbed2ManyParamInterfaceBPSubscriberInterface::Execute_OnProp4Changed(Obj, InProp4);
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

void UTestbed2ManyParamInterfacePublisher::Subscribe(const TScriptInterface<ITestbed2ManyParamInterfaceBPSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	FWriteScopeLock WriteLock(BPSubscribersLock);
	BPSubscribers.Remove(Subscriber);
	BPSubscribers.Add(Subscriber);
}

void UTestbed2ManyParamInterfacePublisher::Subscribe(const TWeakInterfacePtr<ITestbed2ManyParamInterfaceSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
	Subscribers.Add(Subscriber);
}

void UTestbed2ManyParamInterfacePublisher::Unsubscribe(const TScriptInterface<ITestbed2ManyParamInterfaceBPSubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(BPSubscribersLock);
	BPSubscribers.Remove(Subscriber);
}

void UTestbed2ManyParamInterfacePublisher::Unsubscribe(const TWeakInterfacePtr<ITestbed2ManyParamInterfaceSubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
}

void UTestbed2ManyParamInterfacePublisher::CleanUpSubscribers()
{
#if (ENGINE_MAJOR_VERSION >= 5)
	EAllowShrinking AllowShrinking = EAllowShrinking::No;
#else
	bool AllowShrinking = false;
#endif

	{
		FWriteScopeLock WriteLock(SubscribersLock);
		Subscribers.RemoveAllSwap([](const TWeakInterfacePtr<ITestbed2ManyParamInterfaceSubscriberInterface>& Subscriber)
			{
			return !Subscriber.IsValid();
		},
			AllowShrinking);
	}
	{
		FWriteScopeLock WriteLock(BPSubscribersLock);
		BPSubscribers.RemoveAllSwap([](const TScriptInterface<ITestbed2ManyParamInterfaceBPSubscriberInterface>& Subscriber)
			{
			UObject* Obj = Subscriber.GetObject();
			return !((Obj != nullptr) && IsValid(Obj));
		},
			AllowShrinking);
	}
}
