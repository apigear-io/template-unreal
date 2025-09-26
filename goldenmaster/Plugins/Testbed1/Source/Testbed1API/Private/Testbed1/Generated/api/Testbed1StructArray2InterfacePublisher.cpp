
#include "Testbed1/Generated/api/Testbed1StructArray2InterfaceInterface.h"
#include "Async/Async.h"
#include "Async/TaskGraphInterfaces.h"
#include "Runtime/Launch/Resources/Version.h"

void UTestbed1StructArray2InterfacePublisher::BroadcastSigBoolSignal(const FTestbed1StructBoolWithArray& ParamBool)
{
	TArray<TWeakInterfacePtr<ITestbed1StructArray2InterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}

	TArray<TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnSigBoolSignal.Broadcast(ParamBool);
	for (const TWeakInterfacePtr<ITestbed1StructArray2InterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed1StructArray2InterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSigBoolSignal(ParamBool);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTestbed1StructArray2InterfacePublisher>(this), BPSubscribersCopy, ParamBool]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnSigBoolSignalBP.Broadcast(ParamBool);
		}

		for (const TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArray2InterfaceBPSubscriberInterface::Execute_OnSigBoolSignal(Obj, ParamBool);
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

void UTestbed1StructArray2InterfacePublisher::BroadcastSigIntSignal(const FTestbed1StructIntWithArray& ParamInt)
{
	TArray<TWeakInterfacePtr<ITestbed1StructArray2InterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}

	TArray<TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnSigIntSignal.Broadcast(ParamInt);
	for (const TWeakInterfacePtr<ITestbed1StructArray2InterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed1StructArray2InterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSigIntSignal(ParamInt);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTestbed1StructArray2InterfacePublisher>(this), BPSubscribersCopy, ParamInt]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnSigIntSignalBP.Broadcast(ParamInt);
		}

		for (const TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArray2InterfaceBPSubscriberInterface::Execute_OnSigIntSignal(Obj, ParamInt);
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

void UTestbed1StructArray2InterfacePublisher::BroadcastSigFloatSignal(const FTestbed1StructFloatWithArray& ParamFloat)
{
	TArray<TWeakInterfacePtr<ITestbed1StructArray2InterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}

	TArray<TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnSigFloatSignal.Broadcast(ParamFloat);
	for (const TWeakInterfacePtr<ITestbed1StructArray2InterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed1StructArray2InterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSigFloatSignal(ParamFloat);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTestbed1StructArray2InterfacePublisher>(this), BPSubscribersCopy, ParamFloat]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnSigFloatSignalBP.Broadcast(ParamFloat);
		}

		for (const TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArray2InterfaceBPSubscriberInterface::Execute_OnSigFloatSignal(Obj, ParamFloat);
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

void UTestbed1StructArray2InterfacePublisher::BroadcastSigStringSignal(const FTestbed1StructStringWithArray& ParamString)
{
	TArray<TWeakInterfacePtr<ITestbed1StructArray2InterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}

	TArray<TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnSigStringSignal.Broadcast(ParamString);
	for (const TWeakInterfacePtr<ITestbed1StructArray2InterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed1StructArray2InterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSigStringSignal(ParamString);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTestbed1StructArray2InterfacePublisher>(this), BPSubscribersCopy, ParamString]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnSigStringSignalBP.Broadcast(ParamString);
		}

		for (const TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArray2InterfaceBPSubscriberInterface::Execute_OnSigStringSignal(Obj, ParamString);
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

void UTestbed1StructArray2InterfacePublisher::BroadcastPropBoolChanged(UPARAM(DisplayName = "PropBool") const FTestbed1StructBoolWithArray& InPropBool)
{
	TArray<TWeakInterfacePtr<ITestbed1StructArray2InterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnPropBoolChanged.Broadcast(InPropBool);
	for (const TWeakInterfacePtr<ITestbed1StructArray2InterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed1StructArray2InterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnPropBoolChanged(InPropBool);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTestbed1StructArray2InterfacePublisher>(this), BPSubscribersCopy, InPropBool]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnPropBoolChangedBP.Broadcast(InPropBool);
		}

		for (const TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArray2InterfaceBPSubscriberInterface::Execute_OnPropBoolChanged(Obj, InPropBool);
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

void UTestbed1StructArray2InterfacePublisher::BroadcastPropIntChanged(UPARAM(DisplayName = "PropInt") const FTestbed1StructIntWithArray& InPropInt)
{
	TArray<TWeakInterfacePtr<ITestbed1StructArray2InterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnPropIntChanged.Broadcast(InPropInt);
	for (const TWeakInterfacePtr<ITestbed1StructArray2InterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed1StructArray2InterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnPropIntChanged(InPropInt);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTestbed1StructArray2InterfacePublisher>(this), BPSubscribersCopy, InPropInt]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnPropIntChangedBP.Broadcast(InPropInt);
		}

		for (const TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArray2InterfaceBPSubscriberInterface::Execute_OnPropIntChanged(Obj, InPropInt);
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

void UTestbed1StructArray2InterfacePublisher::BroadcastPropFloatChanged(UPARAM(DisplayName = "PropFloat") const FTestbed1StructFloatWithArray& InPropFloat)
{
	TArray<TWeakInterfacePtr<ITestbed1StructArray2InterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnPropFloatChanged.Broadcast(InPropFloat);
	for (const TWeakInterfacePtr<ITestbed1StructArray2InterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed1StructArray2InterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnPropFloatChanged(InPropFloat);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTestbed1StructArray2InterfacePublisher>(this), BPSubscribersCopy, InPropFloat]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnPropFloatChangedBP.Broadcast(InPropFloat);
		}

		for (const TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArray2InterfaceBPSubscriberInterface::Execute_OnPropFloatChanged(Obj, InPropFloat);
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

void UTestbed1StructArray2InterfacePublisher::BroadcastPropStringChanged(UPARAM(DisplayName = "PropString") const FTestbed1StructStringWithArray& InPropString)
{
	TArray<TWeakInterfacePtr<ITestbed1StructArray2InterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnPropStringChanged.Broadcast(InPropString);
	for (const TWeakInterfacePtr<ITestbed1StructArray2InterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed1StructArray2InterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnPropStringChanged(InPropString);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTestbed1StructArray2InterfacePublisher>(this), BPSubscribersCopy, InPropString]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnPropStringChangedBP.Broadcast(InPropString);
		}

		for (const TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArray2InterfaceBPSubscriberInterface::Execute_OnPropStringChanged(Obj, InPropString);
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

void UTestbed1StructArray2InterfacePublisher::BroadcastPropEnumChanged(UPARAM(DisplayName = "PropEnum") const FTestbed1StructEnumWithArray& InPropEnum)
{
	TArray<TWeakInterfacePtr<ITestbed1StructArray2InterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnPropEnumChanged.Broadcast(InPropEnum);
	for (const TWeakInterfacePtr<ITestbed1StructArray2InterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed1StructArray2InterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnPropEnumChanged(InPropEnum);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTestbed1StructArray2InterfacePublisher>(this), BPSubscribersCopy, InPropEnum]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnPropEnumChangedBP.Broadcast(InPropEnum);
		}

		for (const TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArray2InterfaceBPSubscriberInterface::Execute_OnPropEnumChanged(Obj, InPropEnum);
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

void UTestbed1StructArray2InterfacePublisher::Subscribe(const TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	FWriteScopeLock WriteLock(BPSubscribersLock);
	BPSubscribers.Remove(Subscriber);
	BPSubscribers.Add(Subscriber);
}

void UTestbed1StructArray2InterfacePublisher::Subscribe(const TWeakInterfacePtr<ITestbed1StructArray2InterfaceSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
	Subscribers.Add(Subscriber);
}

void UTestbed1StructArray2InterfacePublisher::Unsubscribe(const TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(BPSubscribersLock);
	BPSubscribers.Remove(Subscriber);
}

void UTestbed1StructArray2InterfacePublisher::Unsubscribe(const TWeakInterfacePtr<ITestbed1StructArray2InterfaceSubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
}

void UTestbed1StructArray2InterfacePublisher::CleanUpSubscribers()
{
#if (ENGINE_MAJOR_VERSION >= 5)
	EAllowShrinking AllowShrinking = EAllowShrinking::No;
#else
	bool AllowShrinking = false;
#endif

	{
		FWriteScopeLock WriteLock(SubscribersLock);
		Subscribers.RemoveAllSwap([](const TWeakInterfacePtr<ITestbed1StructArray2InterfaceSubscriberInterface>& Subscriber)
			{
			return !Subscriber.IsValid();
		},
			AllowShrinking);
	}
	{
		FWriteScopeLock WriteLock(BPSubscribersLock);
		BPSubscribers.RemoveAllSwap([](const TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>& Subscriber)
			{
			return Subscriber.GetObject() == nullptr;
		},
			AllowShrinking);
	}
}
