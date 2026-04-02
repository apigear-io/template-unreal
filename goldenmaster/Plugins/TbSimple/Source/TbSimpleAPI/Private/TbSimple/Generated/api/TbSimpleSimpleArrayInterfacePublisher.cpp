
#include "TbSimple/Generated/api/TbSimpleSimpleArrayInterfaceInterface.h"
#include "Async/Async.h"
#include "Async/TaskGraphInterfaces.h"
#include "Runtime/Launch/Resources/Version.h"

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastSigBoolSignal(const TArray<bool>& ParamBool)
{
	TArray<TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	auto BroadcastAll = [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleArrayInterfacePublisher>(this), SubscribersCopy, BPSubscribersCopy, ParamBool]()
	{
		if (!WeakPtr.IsValid())
		{
			return;
		}

		WeakPtr.Get()->OnSigBoolSignal.Broadcast(ParamBool);
		for (const TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (Subscriber.IsValid())
			{
				if (ITbSimpleSimpleArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
				{
					Iface->OnSigBoolSignal(ParamBool);
				}
			}
		}

		WeakPtr.Get()->OnSigBoolSignalBP.Broadcast(ParamBool);
		for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnSigBoolSignal(Obj, ParamBool);
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

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastSigIntSignal(const TArray<int32>& ParamInt)
{
	TArray<TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	auto BroadcastAll = [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleArrayInterfacePublisher>(this), SubscribersCopy, BPSubscribersCopy, ParamInt]()
	{
		if (!WeakPtr.IsValid())
		{
			return;
		}

		WeakPtr.Get()->OnSigIntSignal.Broadcast(ParamInt);
		for (const TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (Subscriber.IsValid())
			{
				if (ITbSimpleSimpleArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
				{
					Iface->OnSigIntSignal(ParamInt);
				}
			}
		}

		WeakPtr.Get()->OnSigIntSignalBP.Broadcast(ParamInt);
		for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnSigIntSignal(Obj, ParamInt);
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

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastSigInt32Signal(const TArray<int32>& ParamInt32)
{
	TArray<TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	auto BroadcastAll = [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleArrayInterfacePublisher>(this), SubscribersCopy, BPSubscribersCopy, ParamInt32]()
	{
		if (!WeakPtr.IsValid())
		{
			return;
		}

		WeakPtr.Get()->OnSigInt32Signal.Broadcast(ParamInt32);
		for (const TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (Subscriber.IsValid())
			{
				if (ITbSimpleSimpleArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
				{
					Iface->OnSigInt32Signal(ParamInt32);
				}
			}
		}

		WeakPtr.Get()->OnSigInt32SignalBP.Broadcast(ParamInt32);
		for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnSigInt32Signal(Obj, ParamInt32);
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

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastSigInt64Signal(const TArray<int64>& ParamInt64)
{
	TArray<TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	auto BroadcastAll = [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleArrayInterfacePublisher>(this), SubscribersCopy, BPSubscribersCopy, ParamInt64]()
	{
		if (!WeakPtr.IsValid())
		{
			return;
		}

		WeakPtr.Get()->OnSigInt64Signal.Broadcast(ParamInt64);
		for (const TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (Subscriber.IsValid())
			{
				if (ITbSimpleSimpleArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
				{
					Iface->OnSigInt64Signal(ParamInt64);
				}
			}
		}

		WeakPtr.Get()->OnSigInt64SignalBP.Broadcast(ParamInt64);
		for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnSigInt64Signal(Obj, ParamInt64);
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

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastSigFloatSignal(const TArray<float>& ParamFloat)
{
	TArray<TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	auto BroadcastAll = [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleArrayInterfacePublisher>(this), SubscribersCopy, BPSubscribersCopy, ParamFloat]()
	{
		if (!WeakPtr.IsValid())
		{
			return;
		}

		WeakPtr.Get()->OnSigFloatSignal.Broadcast(ParamFloat);
		for (const TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (Subscriber.IsValid())
			{
				if (ITbSimpleSimpleArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
				{
					Iface->OnSigFloatSignal(ParamFloat);
				}
			}
		}

		WeakPtr.Get()->OnSigFloatSignalBP.Broadcast(ParamFloat);
		for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnSigFloatSignal(Obj, ParamFloat);
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

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastSigFloat32Signal(const TArray<float>& ParamFloa32)
{
	TArray<TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	auto BroadcastAll = [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleArrayInterfacePublisher>(this), SubscribersCopy, BPSubscribersCopy, ParamFloa32]()
	{
		if (!WeakPtr.IsValid())
		{
			return;
		}

		WeakPtr.Get()->OnSigFloat32Signal.Broadcast(ParamFloa32);
		for (const TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (Subscriber.IsValid())
			{
				if (ITbSimpleSimpleArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
				{
					Iface->OnSigFloat32Signal(ParamFloa32);
				}
			}
		}

		WeakPtr.Get()->OnSigFloat32SignalBP.Broadcast(ParamFloa32);
		for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnSigFloat32Signal(Obj, ParamFloa32);
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

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastSigFloat64Signal(const TArray<double>& ParamFloat64)
{
	TArray<TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	auto BroadcastAll = [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleArrayInterfacePublisher>(this), SubscribersCopy, BPSubscribersCopy, ParamFloat64]()
	{
		if (!WeakPtr.IsValid())
		{
			return;
		}

		WeakPtr.Get()->OnSigFloat64Signal.Broadcast(ParamFloat64);
		for (const TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (Subscriber.IsValid())
			{
				if (ITbSimpleSimpleArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
				{
					Iface->OnSigFloat64Signal(ParamFloat64);
				}
			}
		}

		WeakPtr.Get()->OnSigFloat64SignalBP.Broadcast(ParamFloat64);
		for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnSigFloat64Signal(Obj, ParamFloat64);
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

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastSigStringSignal(const TArray<FString>& ParamString)
{
	TArray<TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	auto BroadcastAll = [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleArrayInterfacePublisher>(this), SubscribersCopy, BPSubscribersCopy, ParamString]()
	{
		if (!WeakPtr.IsValid())
		{
			return;
		}

		WeakPtr.Get()->OnSigStringSignal.Broadcast(ParamString);
		for (const TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (Subscriber.IsValid())
			{
				if (ITbSimpleSimpleArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
				{
					Iface->OnSigStringSignal(ParamString);
				}
			}
		}

		WeakPtr.Get()->OnSigStringSignalBP.Broadcast(ParamString);
		for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnSigStringSignal(Obj, ParamString);
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

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastPropBoolChanged(UPARAM(DisplayName = "PropBool") const TArray<bool>& InPropBool)
{
	TArray<TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	auto BroadcastAll = [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleArrayInterfacePublisher>(this), SubscribersCopy, BPSubscribersCopy, InPropBool]()
	{
		if (!WeakPtr.IsValid())
		{
			return;
		}

		WeakPtr.Get()->OnPropBoolChanged.Broadcast(InPropBool);
		for (const TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (Subscriber.IsValid())
			{
				if (ITbSimpleSimpleArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
				{
					Iface->OnPropBoolChanged(InPropBool);
				}
			}
		}

		WeakPtr.Get()->OnPropBoolChangedBP.Broadcast(InPropBool);
		for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropBoolChanged(Obj, InPropBool);
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

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastPropIntChanged(UPARAM(DisplayName = "PropInt") const TArray<int32>& InPropInt)
{
	TArray<TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	auto BroadcastAll = [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleArrayInterfacePublisher>(this), SubscribersCopy, BPSubscribersCopy, InPropInt]()
	{
		if (!WeakPtr.IsValid())
		{
			return;
		}

		WeakPtr.Get()->OnPropIntChanged.Broadcast(InPropInt);
		for (const TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (Subscriber.IsValid())
			{
				if (ITbSimpleSimpleArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
				{
					Iface->OnPropIntChanged(InPropInt);
				}
			}
		}

		WeakPtr.Get()->OnPropIntChangedBP.Broadcast(InPropInt);
		for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropIntChanged(Obj, InPropInt);
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

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastPropInt32Changed(UPARAM(DisplayName = "PropInt32") const TArray<int32>& InPropInt32)
{
	TArray<TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	auto BroadcastAll = [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleArrayInterfacePublisher>(this), SubscribersCopy, BPSubscribersCopy, InPropInt32]()
	{
		if (!WeakPtr.IsValid())
		{
			return;
		}

		WeakPtr.Get()->OnPropInt32Changed.Broadcast(InPropInt32);
		for (const TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (Subscriber.IsValid())
			{
				if (ITbSimpleSimpleArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
				{
					Iface->OnPropInt32Changed(InPropInt32);
				}
			}
		}

		WeakPtr.Get()->OnPropInt32ChangedBP.Broadcast(InPropInt32);
		for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropInt32Changed(Obj, InPropInt32);
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

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastPropInt64Changed(UPARAM(DisplayName = "PropInt64") const TArray<int64>& InPropInt64)
{
	TArray<TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	auto BroadcastAll = [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleArrayInterfacePublisher>(this), SubscribersCopy, BPSubscribersCopy, InPropInt64]()
	{
		if (!WeakPtr.IsValid())
		{
			return;
		}

		WeakPtr.Get()->OnPropInt64Changed.Broadcast(InPropInt64);
		for (const TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (Subscriber.IsValid())
			{
				if (ITbSimpleSimpleArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
				{
					Iface->OnPropInt64Changed(InPropInt64);
				}
			}
		}

		WeakPtr.Get()->OnPropInt64ChangedBP.Broadcast(InPropInt64);
		for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropInt64Changed(Obj, InPropInt64);
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

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastPropFloatChanged(UPARAM(DisplayName = "PropFloat") const TArray<float>& InPropFloat)
{
	TArray<TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	auto BroadcastAll = [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleArrayInterfacePublisher>(this), SubscribersCopy, BPSubscribersCopy, InPropFloat]()
	{
		if (!WeakPtr.IsValid())
		{
			return;
		}

		WeakPtr.Get()->OnPropFloatChanged.Broadcast(InPropFloat);
		for (const TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (Subscriber.IsValid())
			{
				if (ITbSimpleSimpleArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
				{
					Iface->OnPropFloatChanged(InPropFloat);
				}
			}
		}

		WeakPtr.Get()->OnPropFloatChangedBP.Broadcast(InPropFloat);
		for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropFloatChanged(Obj, InPropFloat);
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

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastPropFloat32Changed(UPARAM(DisplayName = "PropFloat32") const TArray<float>& InPropFloat32)
{
	TArray<TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	auto BroadcastAll = [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleArrayInterfacePublisher>(this), SubscribersCopy, BPSubscribersCopy, InPropFloat32]()
	{
		if (!WeakPtr.IsValid())
		{
			return;
		}

		WeakPtr.Get()->OnPropFloat32Changed.Broadcast(InPropFloat32);
		for (const TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (Subscriber.IsValid())
			{
				if (ITbSimpleSimpleArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
				{
					Iface->OnPropFloat32Changed(InPropFloat32);
				}
			}
		}

		WeakPtr.Get()->OnPropFloat32ChangedBP.Broadcast(InPropFloat32);
		for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropFloat32Changed(Obj, InPropFloat32);
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

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastPropFloat64Changed(UPARAM(DisplayName = "PropFloat64") const TArray<double>& InPropFloat64)
{
	TArray<TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	auto BroadcastAll = [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleArrayInterfacePublisher>(this), SubscribersCopy, BPSubscribersCopy, InPropFloat64]()
	{
		if (!WeakPtr.IsValid())
		{
			return;
		}

		WeakPtr.Get()->OnPropFloat64Changed.Broadcast(InPropFloat64);
		for (const TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (Subscriber.IsValid())
			{
				if (ITbSimpleSimpleArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
				{
					Iface->OnPropFloat64Changed(InPropFloat64);
				}
			}
		}

		WeakPtr.Get()->OnPropFloat64ChangedBP.Broadcast(InPropFloat64);
		for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropFloat64Changed(Obj, InPropFloat64);
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

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastPropStringChanged(UPARAM(DisplayName = "PropString") const TArray<FString>& InPropString)
{
	TArray<TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	auto BroadcastAll = [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleArrayInterfacePublisher>(this), SubscribersCopy, BPSubscribersCopy, InPropString]()
	{
		if (!WeakPtr.IsValid())
		{
			return;
		}

		WeakPtr.Get()->OnPropStringChanged.Broadcast(InPropString);
		for (const TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (Subscriber.IsValid())
			{
				if (ITbSimpleSimpleArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
				{
					Iface->OnPropStringChanged(InPropString);
				}
			}
		}

		WeakPtr.Get()->OnPropStringChangedBP.Broadcast(InPropString);
		for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropStringChanged(Obj, InPropString);
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

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastPropReadOnlyStringChanged(UPARAM(DisplayName = "PropReadOnlyString") const FString& InPropReadOnlyString)
{
	TArray<TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	auto BroadcastAll = [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleArrayInterfacePublisher>(this), SubscribersCopy, BPSubscribersCopy, InPropReadOnlyString]()
	{
		if (!WeakPtr.IsValid())
		{
			return;
		}

		WeakPtr.Get()->OnPropReadOnlyStringChanged.Broadcast(InPropReadOnlyString);
		for (const TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (Subscriber.IsValid())
			{
				if (ITbSimpleSimpleArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
				{
					Iface->OnPropReadOnlyStringChanged(InPropReadOnlyString);
				}
			}
		}

		WeakPtr.Get()->OnPropReadOnlyStringChangedBP.Broadcast(InPropReadOnlyString);
		for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropReadOnlyStringChanged(Obj, InPropReadOnlyString);
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

void UTbSimpleSimpleArrayInterfacePublisher::Subscribe(const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	FWriteScopeLock WriteLock(BPSubscribersLock);
	BPSubscribers.Remove(Subscriber);
	BPSubscribers.Add(Subscriber);
}

void UTbSimpleSimpleArrayInterfacePublisher::Subscribe(const TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
	Subscribers.Add(Subscriber);
}

void UTbSimpleSimpleArrayInterfacePublisher::Unsubscribe(const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(BPSubscribersLock);
	BPSubscribers.Remove(Subscriber);
}

void UTbSimpleSimpleArrayInterfacePublisher::Unsubscribe(const TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
}

void UTbSimpleSimpleArrayInterfacePublisher::CleanUpSubscribers()
{
#if (ENGINE_MAJOR_VERSION >= 5)
	EAllowShrinking AllowShrinking = EAllowShrinking::No;
#else
	bool AllowShrinking = false;
#endif

	{
		FWriteScopeLock WriteLock(SubscribersLock);
		Subscribers.RemoveAllSwap([](const TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>& Subscriber)
			{
			return !Subscriber.IsValid();
		},
			AllowShrinking);
	}
	{
		FWriteScopeLock WriteLock(BPSubscribersLock);
		BPSubscribers.RemoveAllSwap([](const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber)
			{
			UObject* Obj = Subscriber.GetObject();
			return !((Obj != nullptr) && IsValid(Obj));
		},
			AllowShrinking);
	}
}
