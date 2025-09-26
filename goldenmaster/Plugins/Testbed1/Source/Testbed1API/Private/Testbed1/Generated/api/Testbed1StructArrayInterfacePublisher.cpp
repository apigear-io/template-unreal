
#include "Testbed1/Generated/api/Testbed1StructArrayInterfaceInterface.h"
#include "Async/Async.h"
#include "Async/TaskGraphInterfaces.h"
#include "Runtime/Launch/Resources/Version.h"

void UTestbed1StructArrayInterfacePublisher::BroadcastSigBoolSignal(const TArray<FTestbed1StructBool>& ParamBool)
{
	TArray<TWeakInterfacePtr<ITestbed1StructArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}

	TArray<TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnSigBoolSignal.Broadcast(ParamBool);
	for (const TWeakInterfacePtr<ITestbed1StructArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed1StructArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSigBoolSignal(ParamBool);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTestbed1StructArrayInterfacePublisher>(this), BPSubscribersCopy, ParamBool]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnSigBoolSignalBP.Broadcast(ParamBool);
		}

		for (const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArrayInterfaceBPSubscriberInterface::Execute_OnSigBoolSignal(Obj, ParamBool);
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

void UTestbed1StructArrayInterfacePublisher::BroadcastSigIntSignal(const TArray<FTestbed1StructInt>& ParamInt)
{
	TArray<TWeakInterfacePtr<ITestbed1StructArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}

	TArray<TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnSigIntSignal.Broadcast(ParamInt);
	for (const TWeakInterfacePtr<ITestbed1StructArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed1StructArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSigIntSignal(ParamInt);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTestbed1StructArrayInterfacePublisher>(this), BPSubscribersCopy, ParamInt]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnSigIntSignalBP.Broadcast(ParamInt);
		}

		for (const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArrayInterfaceBPSubscriberInterface::Execute_OnSigIntSignal(Obj, ParamInt);
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

void UTestbed1StructArrayInterfacePublisher::BroadcastSigFloatSignal(const TArray<FTestbed1StructFloat>& ParamFloat)
{
	TArray<TWeakInterfacePtr<ITestbed1StructArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}

	TArray<TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnSigFloatSignal.Broadcast(ParamFloat);
	for (const TWeakInterfacePtr<ITestbed1StructArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed1StructArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSigFloatSignal(ParamFloat);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTestbed1StructArrayInterfacePublisher>(this), BPSubscribersCopy, ParamFloat]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnSigFloatSignalBP.Broadcast(ParamFloat);
		}

		for (const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArrayInterfaceBPSubscriberInterface::Execute_OnSigFloatSignal(Obj, ParamFloat);
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

void UTestbed1StructArrayInterfacePublisher::BroadcastSigStringSignal(const TArray<FTestbed1StructString>& ParamString)
{
	TArray<TWeakInterfacePtr<ITestbed1StructArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}

	TArray<TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnSigStringSignal.Broadcast(ParamString);
	for (const TWeakInterfacePtr<ITestbed1StructArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed1StructArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSigStringSignal(ParamString);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTestbed1StructArrayInterfacePublisher>(this), BPSubscribersCopy, ParamString]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnSigStringSignalBP.Broadcast(ParamString);
		}

		for (const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArrayInterfaceBPSubscriberInterface::Execute_OnSigStringSignal(Obj, ParamString);
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

void UTestbed1StructArrayInterfacePublisher::BroadcastSigEnumSignal(const TArray<ETestbed1Enum0>& ParamEnum)
{
	TArray<TWeakInterfacePtr<ITestbed1StructArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}

	TArray<TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnSigEnumSignal.Broadcast(ParamEnum);
	for (const TWeakInterfacePtr<ITestbed1StructArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed1StructArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSigEnumSignal(ParamEnum);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTestbed1StructArrayInterfacePublisher>(this), BPSubscribersCopy, ParamEnum]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnSigEnumSignalBP.Broadcast(ParamEnum);
		}

		for (const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArrayInterfaceBPSubscriberInterface::Execute_OnSigEnumSignal(Obj, ParamEnum);
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

void UTestbed1StructArrayInterfacePublisher::BroadcastPropBoolChanged(UPARAM(DisplayName = "PropBool") const TArray<FTestbed1StructBool>& InPropBool)
{
	TArray<TWeakInterfacePtr<ITestbed1StructArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnPropBoolChanged.Broadcast(InPropBool);
	for (const TWeakInterfacePtr<ITestbed1StructArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed1StructArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnPropBoolChanged(InPropBool);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTestbed1StructArrayInterfacePublisher>(this), BPSubscribersCopy, InPropBool]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnPropBoolChangedBP.Broadcast(InPropBool);
		}

		for (const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArrayInterfaceBPSubscriberInterface::Execute_OnPropBoolChanged(Obj, InPropBool);
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

void UTestbed1StructArrayInterfacePublisher::BroadcastPropIntChanged(UPARAM(DisplayName = "PropInt") const TArray<FTestbed1StructInt>& InPropInt)
{
	TArray<TWeakInterfacePtr<ITestbed1StructArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnPropIntChanged.Broadcast(InPropInt);
	for (const TWeakInterfacePtr<ITestbed1StructArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed1StructArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnPropIntChanged(InPropInt);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTestbed1StructArrayInterfacePublisher>(this), BPSubscribersCopy, InPropInt]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnPropIntChangedBP.Broadcast(InPropInt);
		}

		for (const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArrayInterfaceBPSubscriberInterface::Execute_OnPropIntChanged(Obj, InPropInt);
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

void UTestbed1StructArrayInterfacePublisher::BroadcastPropFloatChanged(UPARAM(DisplayName = "PropFloat") const TArray<FTestbed1StructFloat>& InPropFloat)
{
	TArray<TWeakInterfacePtr<ITestbed1StructArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnPropFloatChanged.Broadcast(InPropFloat);
	for (const TWeakInterfacePtr<ITestbed1StructArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed1StructArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnPropFloatChanged(InPropFloat);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTestbed1StructArrayInterfacePublisher>(this), BPSubscribersCopy, InPropFloat]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnPropFloatChangedBP.Broadcast(InPropFloat);
		}

		for (const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArrayInterfaceBPSubscriberInterface::Execute_OnPropFloatChanged(Obj, InPropFloat);
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

void UTestbed1StructArrayInterfacePublisher::BroadcastPropStringChanged(UPARAM(DisplayName = "PropString") const TArray<FTestbed1StructString>& InPropString)
{
	TArray<TWeakInterfacePtr<ITestbed1StructArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnPropStringChanged.Broadcast(InPropString);
	for (const TWeakInterfacePtr<ITestbed1StructArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed1StructArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnPropStringChanged(InPropString);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTestbed1StructArrayInterfacePublisher>(this), BPSubscribersCopy, InPropString]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnPropStringChangedBP.Broadcast(InPropString);
		}

		for (const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArrayInterfaceBPSubscriberInterface::Execute_OnPropStringChanged(Obj, InPropString);
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

void UTestbed1StructArrayInterfacePublisher::BroadcastPropEnumChanged(UPARAM(DisplayName = "PropEnum") const TArray<ETestbed1Enum0>& InPropEnum)
{
	TArray<TWeakInterfacePtr<ITestbed1StructArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnPropEnumChanged.Broadcast(InPropEnum);
	for (const TWeakInterfacePtr<ITestbed1StructArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed1StructArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnPropEnumChanged(InPropEnum);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTestbed1StructArrayInterfacePublisher>(this), BPSubscribersCopy, InPropEnum]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnPropEnumChangedBP.Broadcast(InPropEnum);
		}

		for (const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArrayInterfaceBPSubscriberInterface::Execute_OnPropEnumChanged(Obj, InPropEnum);
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

void UTestbed1StructArrayInterfacePublisher::Subscribe(const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	FWriteScopeLock WriteLock(BPSubscribersLock);
	BPSubscribers.Remove(Subscriber);
	BPSubscribers.Add(Subscriber);
}

void UTestbed1StructArrayInterfacePublisher::Subscribe(const TWeakInterfacePtr<ITestbed1StructArrayInterfaceSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
	Subscribers.Add(Subscriber);
}

void UTestbed1StructArrayInterfacePublisher::Unsubscribe(const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(BPSubscribersLock);
	BPSubscribers.Remove(Subscriber);
}

void UTestbed1StructArrayInterfacePublisher::Unsubscribe(const TWeakInterfacePtr<ITestbed1StructArrayInterfaceSubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
}

void UTestbed1StructArrayInterfacePublisher::CleanUpSubscribers()
{
#if (ENGINE_MAJOR_VERSION >= 5)
	EAllowShrinking AllowShrinking = EAllowShrinking::No;
#else
	bool AllowShrinking = false;
#endif

	{
		FWriteScopeLock WriteLock(SubscribersLock);
		Subscribers.RemoveAllSwap([](const TWeakInterfacePtr<ITestbed1StructArrayInterfaceSubscriberInterface>& Subscriber)
			{
			return !Subscriber.IsValid();
		},
			AllowShrinking);
	}
	{
		FWriteScopeLock WriteLock(BPSubscribersLock);
		BPSubscribers.RemoveAllSwap([](const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber)
			{
			return Subscriber.GetObject() == nullptr;
		},
			AllowShrinking);
	}
}
