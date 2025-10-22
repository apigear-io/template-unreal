
#include "TbSimple/Generated/api/TbSimpleSimpleInterfaceInterface.h"
#include "Async/Async.h"
#include "Async/TaskGraphInterfaces.h"
#include "Runtime/Launch/Resources/Version.h"

void UTbSimpleSimpleInterfacePublisher::BroadcastSigBoolSignal(bool bParamBool)
{
	TArray<TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}

	TArray<TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnSigBoolSignal.Broadcast(bParamBool);
	for (const TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleSimpleInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSigBoolSignal(bParamBool);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleInterfacePublisher>(this), BPSubscribersCopy, bParamBool]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnSigBoolSignalBP.Broadcast(bParamBool);
		}

		for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnSigBoolSignal(Obj, bParamBool);
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

void UTbSimpleSimpleInterfacePublisher::BroadcastSigIntSignal(int32 ParamInt)
{
	TArray<TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}

	TArray<TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnSigIntSignal.Broadcast(ParamInt);
	for (const TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleSimpleInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSigIntSignal(ParamInt);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleInterfacePublisher>(this), BPSubscribersCopy, ParamInt]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnSigIntSignalBP.Broadcast(ParamInt);
		}

		for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnSigIntSignal(Obj, ParamInt);
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

void UTbSimpleSimpleInterfacePublisher::BroadcastSigInt32Signal(int32 ParamInt32)
{
	TArray<TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}

	TArray<TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnSigInt32Signal.Broadcast(ParamInt32);
	for (const TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleSimpleInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSigInt32Signal(ParamInt32);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleInterfacePublisher>(this), BPSubscribersCopy, ParamInt32]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnSigInt32SignalBP.Broadcast(ParamInt32);
		}

		for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnSigInt32Signal(Obj, ParamInt32);
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

void UTbSimpleSimpleInterfacePublisher::BroadcastSigInt64Signal(int64 ParamInt64)
{
	TArray<TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}

	TArray<TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnSigInt64Signal.Broadcast(ParamInt64);
	for (const TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleSimpleInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSigInt64Signal(ParamInt64);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleInterfacePublisher>(this), BPSubscribersCopy, ParamInt64]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnSigInt64SignalBP.Broadcast(ParamInt64);
		}

		for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnSigInt64Signal(Obj, ParamInt64);
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

void UTbSimpleSimpleInterfacePublisher::BroadcastSigFloatSignal(float ParamFloat)
{
	TArray<TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}

	TArray<TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnSigFloatSignal.Broadcast(ParamFloat);
	for (const TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleSimpleInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSigFloatSignal(ParamFloat);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleInterfacePublisher>(this), BPSubscribersCopy, ParamFloat]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnSigFloatSignalBP.Broadcast(ParamFloat);
		}

		for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnSigFloatSignal(Obj, ParamFloat);
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

void UTbSimpleSimpleInterfacePublisher::BroadcastSigFloat32Signal(float ParamFloat32)
{
	TArray<TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}

	TArray<TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnSigFloat32Signal.Broadcast(ParamFloat32);
	for (const TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleSimpleInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSigFloat32Signal(ParamFloat32);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleInterfacePublisher>(this), BPSubscribersCopy, ParamFloat32]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnSigFloat32SignalBP.Broadcast(ParamFloat32);
		}

		for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnSigFloat32Signal(Obj, ParamFloat32);
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

void UTbSimpleSimpleInterfacePublisher::BroadcastSigFloat64Signal(double ParamFloat64)
{
	TArray<TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}

	TArray<TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnSigFloat64Signal.Broadcast(ParamFloat64);
	for (const TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleSimpleInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSigFloat64Signal(ParamFloat64);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleInterfacePublisher>(this), BPSubscribersCopy, ParamFloat64]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnSigFloat64SignalBP.Broadcast(ParamFloat64);
		}

		for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnSigFloat64Signal(Obj, ParamFloat64);
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

void UTbSimpleSimpleInterfacePublisher::BroadcastSigStringSignal(const FString& ParamString)
{
	TArray<TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}

	TArray<TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnSigStringSignal.Broadcast(ParamString);
	for (const TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleSimpleInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSigStringSignal(ParamString);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleInterfacePublisher>(this), BPSubscribersCopy, ParamString]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnSigStringSignalBP.Broadcast(ParamString);
		}

		for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnSigStringSignal(Obj, ParamString);
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

void UTbSimpleSimpleInterfacePublisher::BroadcastPropBoolChanged(UPARAM(DisplayName = "bPropBool") bool bInPropBool)
{
	TArray<TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnPropBoolChanged.Broadcast(bInPropBool);
	for (const TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleSimpleInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnPropBoolChanged(bInPropBool);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleInterfacePublisher>(this), BPSubscribersCopy, bInPropBool]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnPropBoolChangedBP.Broadcast(bInPropBool);
		}

		for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnPropBoolChanged(Obj, bInPropBool);
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

void UTbSimpleSimpleInterfacePublisher::BroadcastPropIntChanged(UPARAM(DisplayName = "PropInt") int32 InPropInt)
{
	TArray<TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnPropIntChanged.Broadcast(InPropInt);
	for (const TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleSimpleInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnPropIntChanged(InPropInt);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleInterfacePublisher>(this), BPSubscribersCopy, InPropInt]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnPropIntChangedBP.Broadcast(InPropInt);
		}

		for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnPropIntChanged(Obj, InPropInt);
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

void UTbSimpleSimpleInterfacePublisher::BroadcastPropInt32Changed(UPARAM(DisplayName = "PropInt32") int32 InPropInt32)
{
	TArray<TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnPropInt32Changed.Broadcast(InPropInt32);
	for (const TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleSimpleInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnPropInt32Changed(InPropInt32);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleInterfacePublisher>(this), BPSubscribersCopy, InPropInt32]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnPropInt32ChangedBP.Broadcast(InPropInt32);
		}

		for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnPropInt32Changed(Obj, InPropInt32);
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

void UTbSimpleSimpleInterfacePublisher::BroadcastPropInt64Changed(UPARAM(DisplayName = "PropInt64") int64 InPropInt64)
{
	TArray<TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnPropInt64Changed.Broadcast(InPropInt64);
	for (const TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleSimpleInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnPropInt64Changed(InPropInt64);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleInterfacePublisher>(this), BPSubscribersCopy, InPropInt64]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnPropInt64ChangedBP.Broadcast(InPropInt64);
		}

		for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnPropInt64Changed(Obj, InPropInt64);
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

void UTbSimpleSimpleInterfacePublisher::BroadcastPropFloatChanged(UPARAM(DisplayName = "PropFloat") float InPropFloat)
{
	TArray<TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnPropFloatChanged.Broadcast(InPropFloat);
	for (const TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleSimpleInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnPropFloatChanged(InPropFloat);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleInterfacePublisher>(this), BPSubscribersCopy, InPropFloat]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnPropFloatChangedBP.Broadcast(InPropFloat);
		}

		for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnPropFloatChanged(Obj, InPropFloat);
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

void UTbSimpleSimpleInterfacePublisher::BroadcastPropFloat32Changed(UPARAM(DisplayName = "PropFloat32") float InPropFloat32)
{
	TArray<TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnPropFloat32Changed.Broadcast(InPropFloat32);
	for (const TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleSimpleInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnPropFloat32Changed(InPropFloat32);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleInterfacePublisher>(this), BPSubscribersCopy, InPropFloat32]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnPropFloat32ChangedBP.Broadcast(InPropFloat32);
		}

		for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnPropFloat32Changed(Obj, InPropFloat32);
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

void UTbSimpleSimpleInterfacePublisher::BroadcastPropFloat64Changed(UPARAM(DisplayName = "PropFloat64") double InPropFloat64)
{
	TArray<TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnPropFloat64Changed.Broadcast(InPropFloat64);
	for (const TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleSimpleInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnPropFloat64Changed(InPropFloat64);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleInterfacePublisher>(this), BPSubscribersCopy, InPropFloat64]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnPropFloat64ChangedBP.Broadcast(InPropFloat64);
		}

		for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnPropFloat64Changed(Obj, InPropFloat64);
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

void UTbSimpleSimpleInterfacePublisher::BroadcastPropStringChanged(UPARAM(DisplayName = "PropString") const FString& InPropString)
{
	TArray<TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnPropStringChanged.Broadcast(InPropString);
	for (const TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleSimpleInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnPropStringChanged(InPropString);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleInterfacePublisher>(this), BPSubscribersCopy, InPropString]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnPropStringChangedBP.Broadcast(InPropString);
		}

		for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnPropStringChanged(Obj, InPropString);
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

void UTbSimpleSimpleInterfacePublisher::Subscribe(const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	FWriteScopeLock WriteLock(BPSubscribersLock);
	BPSubscribers.Remove(Subscriber);
	BPSubscribers.Add(Subscriber);
}

void UTbSimpleSimpleInterfacePublisher::Subscribe(const TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
	Subscribers.Add(Subscriber);
}

void UTbSimpleSimpleInterfacePublisher::Unsubscribe(const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(BPSubscribersLock);
	BPSubscribers.Remove(Subscriber);
}

void UTbSimpleSimpleInterfacePublisher::Unsubscribe(const TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
}

void UTbSimpleSimpleInterfacePublisher::CleanUpSubscribers()
{
#if (ENGINE_MAJOR_VERSION >= 5)
	EAllowShrinking AllowShrinking = EAllowShrinking::No;
#else
	bool AllowShrinking = false;
#endif

	{
		FWriteScopeLock WriteLock(SubscribersLock);
		Subscribers.RemoveAllSwap([](const TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>& Subscriber)
			{
			return !Subscriber.IsValid();
		},
			AllowShrinking);
	}
	{
		FWriteScopeLock WriteLock(BPSubscribersLock);
		BPSubscribers.RemoveAllSwap([](const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber)
			{
			UObject* Obj = Subscriber.GetObject();
			return !((Obj != nullptr) && IsValid(Obj));
		},
			AllowShrinking);
	}
}
