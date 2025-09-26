
#include "Testbed1/Generated/api/Testbed1StructInterfaceInterface.h"
#include "Async/Async.h"
#include "Async/TaskGraphInterfaces.h"
#include "Runtime/Launch/Resources/Version.h"

void UTestbed1StructInterfacePublisher::BroadcastSigBoolSignal(const FTestbed1StructBool& ParamBool)
{
	TArray<TWeakInterfacePtr<ITestbed1StructInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}

	TArray<TScriptInterface<ITestbed1StructInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnSigBoolSignal.Broadcast(ParamBool);
	for (const TWeakInterfacePtr<ITestbed1StructInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed1StructInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSigBoolSignal(ParamBool);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTestbed1StructInterfacePublisher>(this), BPSubscribersCopy, ParamBool]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnSigBoolSignalBP.Broadcast(ParamBool);
		}

		for (const TScriptInterface<ITestbed1StructInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructInterfaceBPSubscriberInterface::Execute_OnSigBoolSignal(Obj, ParamBool);
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

void UTestbed1StructInterfacePublisher::BroadcastSigIntSignal(const FTestbed1StructInt& ParamInt)
{
	TArray<TWeakInterfacePtr<ITestbed1StructInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}

	TArray<TScriptInterface<ITestbed1StructInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnSigIntSignal.Broadcast(ParamInt);
	for (const TWeakInterfacePtr<ITestbed1StructInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed1StructInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSigIntSignal(ParamInt);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTestbed1StructInterfacePublisher>(this), BPSubscribersCopy, ParamInt]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnSigIntSignalBP.Broadcast(ParamInt);
		}

		for (const TScriptInterface<ITestbed1StructInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructInterfaceBPSubscriberInterface::Execute_OnSigIntSignal(Obj, ParamInt);
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

void UTestbed1StructInterfacePublisher::BroadcastSigFloatSignal(const FTestbed1StructFloat& ParamFloat)
{
	TArray<TWeakInterfacePtr<ITestbed1StructInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}

	TArray<TScriptInterface<ITestbed1StructInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnSigFloatSignal.Broadcast(ParamFloat);
	for (const TWeakInterfacePtr<ITestbed1StructInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed1StructInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSigFloatSignal(ParamFloat);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTestbed1StructInterfacePublisher>(this), BPSubscribersCopy, ParamFloat]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnSigFloatSignalBP.Broadcast(ParamFloat);
		}

		for (const TScriptInterface<ITestbed1StructInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructInterfaceBPSubscriberInterface::Execute_OnSigFloatSignal(Obj, ParamFloat);
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

void UTestbed1StructInterfacePublisher::BroadcastSigStringSignal(const FTestbed1StructString& ParamString)
{
	TArray<TWeakInterfacePtr<ITestbed1StructInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}

	TArray<TScriptInterface<ITestbed1StructInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnSigStringSignal.Broadcast(ParamString);
	for (const TWeakInterfacePtr<ITestbed1StructInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed1StructInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSigStringSignal(ParamString);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTestbed1StructInterfacePublisher>(this), BPSubscribersCopy, ParamString]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnSigStringSignalBP.Broadcast(ParamString);
		}

		for (const TScriptInterface<ITestbed1StructInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructInterfaceBPSubscriberInterface::Execute_OnSigStringSignal(Obj, ParamString);
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

void UTestbed1StructInterfacePublisher::BroadcastPropBoolChanged(UPARAM(DisplayName = "PropBool") const FTestbed1StructBool& InPropBool)
{
	TArray<TWeakInterfacePtr<ITestbed1StructInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITestbed1StructInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnPropBoolChanged.Broadcast(InPropBool);
	for (const TWeakInterfacePtr<ITestbed1StructInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed1StructInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnPropBoolChanged(InPropBool);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTestbed1StructInterfacePublisher>(this), BPSubscribersCopy, InPropBool]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnPropBoolChangedBP.Broadcast(InPropBool);
		}

		for (const TScriptInterface<ITestbed1StructInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructInterfaceBPSubscriberInterface::Execute_OnPropBoolChanged(Obj, InPropBool);
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

void UTestbed1StructInterfacePublisher::BroadcastPropIntChanged(UPARAM(DisplayName = "PropInt") const FTestbed1StructInt& InPropInt)
{
	TArray<TWeakInterfacePtr<ITestbed1StructInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITestbed1StructInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnPropIntChanged.Broadcast(InPropInt);
	for (const TWeakInterfacePtr<ITestbed1StructInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed1StructInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnPropIntChanged(InPropInt);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTestbed1StructInterfacePublisher>(this), BPSubscribersCopy, InPropInt]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnPropIntChangedBP.Broadcast(InPropInt);
		}

		for (const TScriptInterface<ITestbed1StructInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructInterfaceBPSubscriberInterface::Execute_OnPropIntChanged(Obj, InPropInt);
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

void UTestbed1StructInterfacePublisher::BroadcastPropFloatChanged(UPARAM(DisplayName = "PropFloat") const FTestbed1StructFloat& InPropFloat)
{
	TArray<TWeakInterfacePtr<ITestbed1StructInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITestbed1StructInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnPropFloatChanged.Broadcast(InPropFloat);
	for (const TWeakInterfacePtr<ITestbed1StructInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed1StructInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnPropFloatChanged(InPropFloat);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTestbed1StructInterfacePublisher>(this), BPSubscribersCopy, InPropFloat]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnPropFloatChangedBP.Broadcast(InPropFloat);
		}

		for (const TScriptInterface<ITestbed1StructInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructInterfaceBPSubscriberInterface::Execute_OnPropFloatChanged(Obj, InPropFloat);
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

void UTestbed1StructInterfacePublisher::BroadcastPropStringChanged(UPARAM(DisplayName = "PropString") const FTestbed1StructString& InPropString)
{
	TArray<TWeakInterfacePtr<ITestbed1StructInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITestbed1StructInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnPropStringChanged.Broadcast(InPropString);
	for (const TWeakInterfacePtr<ITestbed1StructInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed1StructInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnPropStringChanged(InPropString);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTestbed1StructInterfacePublisher>(this), BPSubscribersCopy, InPropString]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnPropStringChangedBP.Broadcast(InPropString);
		}

		for (const TScriptInterface<ITestbed1StructInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructInterfaceBPSubscriberInterface::Execute_OnPropStringChanged(Obj, InPropString);
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

void UTestbed1StructInterfacePublisher::Subscribe(const TScriptInterface<ITestbed1StructInterfaceBPSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	FWriteScopeLock WriteLock(BPSubscribersLock);
	BPSubscribers.Remove(Subscriber);
	BPSubscribers.Add(Subscriber);
}

void UTestbed1StructInterfacePublisher::Subscribe(const TWeakInterfacePtr<ITestbed1StructInterfaceSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
	Subscribers.Add(Subscriber);
}

void UTestbed1StructInterfacePublisher::Unsubscribe(const TScriptInterface<ITestbed1StructInterfaceBPSubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(BPSubscribersLock);
	BPSubscribers.Remove(Subscriber);
}

void UTestbed1StructInterfacePublisher::Unsubscribe(const TWeakInterfacePtr<ITestbed1StructInterfaceSubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
}

void UTestbed1StructInterfacePublisher::CleanUpSubscribers()
{
#if (ENGINE_MAJOR_VERSION >= 5)
	EAllowShrinking AllowShrinking = EAllowShrinking::No;
#else
	bool AllowShrinking = false;
#endif

	{
		FWriteScopeLock WriteLock(SubscribersLock);
		Subscribers.RemoveAllSwap([](const TWeakInterfacePtr<ITestbed1StructInterfaceSubscriberInterface>& Subscriber)
			{
			return !Subscriber.IsValid();
		},
			AllowShrinking);
	}
	{
		FWriteScopeLock WriteLock(BPSubscribersLock);
		BPSubscribers.RemoveAllSwap([](const TScriptInterface<ITestbed1StructInterfaceBPSubscriberInterface>& Subscriber)
			{
			return Subscriber.GetObject() == nullptr;
		},
			AllowShrinking);
	}
}
