
#include "TbSimple/Generated/api/TbSimpleSimpleArrayInterfaceInterface.h"
#include "Async/Async.h"
#include "Async/TaskGraphInterfaces.h"

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastSigBoolSignal(const TArray<bool>& ParamBool)
{
	OnSigBoolSignal.Broadcast(ParamBool);

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnSigBoolSignalBP.Broadcast(ParamBool);

		for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnSigBoolSignal(Obj, ParamBool);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleArrayInterfacePublisher>(this), SubscribersCopy, ParamBool]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSigBoolSignalBP.Broadcast(ParamBool);
			}

			for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnSigBoolSignal(Obj, ParamBool);
				}
			}
		});
	}
}

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastSigIntSignal(const TArray<int32>& ParamInt)
{
	OnSigIntSignal.Broadcast(ParamInt);

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnSigIntSignalBP.Broadcast(ParamInt);

		for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnSigIntSignal(Obj, ParamInt);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleArrayInterfacePublisher>(this), SubscribersCopy, ParamInt]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSigIntSignalBP.Broadcast(ParamInt);
			}

			for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnSigIntSignal(Obj, ParamInt);
				}
			}
		});
	}
}

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastSigInt32Signal(const TArray<int32>& ParamInt32)
{
	OnSigInt32Signal.Broadcast(ParamInt32);

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnSigInt32SignalBP.Broadcast(ParamInt32);

		for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnSigInt32Signal(Obj, ParamInt32);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleArrayInterfacePublisher>(this), SubscribersCopy, ParamInt32]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSigInt32SignalBP.Broadcast(ParamInt32);
			}

			for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnSigInt32Signal(Obj, ParamInt32);
				}
			}
		});
	}
}

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastSigInt64Signal(const TArray<int64>& ParamInt64)
{
	OnSigInt64Signal.Broadcast(ParamInt64);

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnSigInt64SignalBP.Broadcast(ParamInt64);

		for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnSigInt64Signal(Obj, ParamInt64);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleArrayInterfacePublisher>(this), SubscribersCopy, ParamInt64]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSigInt64SignalBP.Broadcast(ParamInt64);
			}

			for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnSigInt64Signal(Obj, ParamInt64);
				}
			}
		});
	}
}

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastSigFloatSignal(const TArray<float>& ParamFloat)
{
	OnSigFloatSignal.Broadcast(ParamFloat);

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnSigFloatSignalBP.Broadcast(ParamFloat);

		for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnSigFloatSignal(Obj, ParamFloat);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleArrayInterfacePublisher>(this), SubscribersCopy, ParamFloat]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSigFloatSignalBP.Broadcast(ParamFloat);
			}

			for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnSigFloatSignal(Obj, ParamFloat);
				}
			}
		});
	}
}

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastSigFloat32Signal(const TArray<float>& ParamFloa32)
{
	OnSigFloat32Signal.Broadcast(ParamFloa32);

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnSigFloat32SignalBP.Broadcast(ParamFloa32);

		for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnSigFloat32Signal(Obj, ParamFloa32);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleArrayInterfacePublisher>(this), SubscribersCopy, ParamFloa32]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSigFloat32SignalBP.Broadcast(ParamFloa32);
			}

			for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnSigFloat32Signal(Obj, ParamFloa32);
				}
			}
		});
	}
}

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastSigFloat64Signal(const TArray<double>& ParamFloat64)
{
	OnSigFloat64Signal.Broadcast(ParamFloat64);

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnSigFloat64SignalBP.Broadcast(ParamFloat64);

		for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnSigFloat64Signal(Obj, ParamFloat64);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleArrayInterfacePublisher>(this), SubscribersCopy, ParamFloat64]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSigFloat64SignalBP.Broadcast(ParamFloat64);
			}

			for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnSigFloat64Signal(Obj, ParamFloat64);
				}
			}
		});
	}
}

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastSigStringSignal(const TArray<FString>& ParamString)
{
	OnSigStringSignal.Broadcast(ParamString);

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnSigStringSignalBP.Broadcast(ParamString);

		for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnSigStringSignal(Obj, ParamString);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleArrayInterfacePublisher>(this), SubscribersCopy, ParamString]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSigStringSignalBP.Broadcast(ParamString);
			}

			for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnSigStringSignal(Obj, ParamString);
				}
			}
		});
	}
}

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastPropBoolChanged(UPARAM(DisplayName = "PropBool") const TArray<bool>& InPropBool)
{
	OnPropBoolChanged.Broadcast(InPropBool);

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnPropBoolChangedBP.Broadcast(InPropBool);

		for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropBoolChanged(Obj, InPropBool);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleArrayInterfacePublisher>(this), SubscribersCopy, InPropBool]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnPropBoolChangedBP.Broadcast(InPropBool);
			}

			for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropBoolChanged(Obj, InPropBool);
				}
			}
		});
	}
}

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastPropIntChanged(UPARAM(DisplayName = "PropInt") const TArray<int32>& InPropInt)
{
	OnPropIntChanged.Broadcast(InPropInt);

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnPropIntChangedBP.Broadcast(InPropInt);

		for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropIntChanged(Obj, InPropInt);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleArrayInterfacePublisher>(this), SubscribersCopy, InPropInt]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnPropIntChangedBP.Broadcast(InPropInt);
			}

			for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropIntChanged(Obj, InPropInt);
				}
			}
		});
	}
}

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastPropInt32Changed(UPARAM(DisplayName = "PropInt32") const TArray<int32>& InPropInt32)
{
	OnPropInt32Changed.Broadcast(InPropInt32);

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnPropInt32ChangedBP.Broadcast(InPropInt32);

		for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropInt32Changed(Obj, InPropInt32);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleArrayInterfacePublisher>(this), SubscribersCopy, InPropInt32]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnPropInt32ChangedBP.Broadcast(InPropInt32);
			}

			for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropInt32Changed(Obj, InPropInt32);
				}
			}
		});
	}
}

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastPropInt64Changed(UPARAM(DisplayName = "PropInt64") const TArray<int64>& InPropInt64)
{
	OnPropInt64Changed.Broadcast(InPropInt64);

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnPropInt64ChangedBP.Broadcast(InPropInt64);

		for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropInt64Changed(Obj, InPropInt64);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleArrayInterfacePublisher>(this), SubscribersCopy, InPropInt64]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnPropInt64ChangedBP.Broadcast(InPropInt64);
			}

			for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropInt64Changed(Obj, InPropInt64);
				}
			}
		});
	}
}

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastPropFloatChanged(UPARAM(DisplayName = "PropFloat") const TArray<float>& InPropFloat)
{
	OnPropFloatChanged.Broadcast(InPropFloat);

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnPropFloatChangedBP.Broadcast(InPropFloat);

		for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropFloatChanged(Obj, InPropFloat);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleArrayInterfacePublisher>(this), SubscribersCopy, InPropFloat]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnPropFloatChangedBP.Broadcast(InPropFloat);
			}

			for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropFloatChanged(Obj, InPropFloat);
				}
			}
		});
	}
}

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastPropFloat32Changed(UPARAM(DisplayName = "PropFloat32") const TArray<float>& InPropFloat32)
{
	OnPropFloat32Changed.Broadcast(InPropFloat32);

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnPropFloat32ChangedBP.Broadcast(InPropFloat32);

		for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropFloat32Changed(Obj, InPropFloat32);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleArrayInterfacePublisher>(this), SubscribersCopy, InPropFloat32]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnPropFloat32ChangedBP.Broadcast(InPropFloat32);
			}

			for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropFloat32Changed(Obj, InPropFloat32);
				}
			}
		});
	}
}

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastPropFloat64Changed(UPARAM(DisplayName = "PropFloat64") const TArray<double>& InPropFloat64)
{
	OnPropFloat64Changed.Broadcast(InPropFloat64);

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnPropFloat64ChangedBP.Broadcast(InPropFloat64);

		for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropFloat64Changed(Obj, InPropFloat64);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleArrayInterfacePublisher>(this), SubscribersCopy, InPropFloat64]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnPropFloat64ChangedBP.Broadcast(InPropFloat64);
			}

			for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropFloat64Changed(Obj, InPropFloat64);
				}
			}
		});
	}
}

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastPropStringChanged(UPARAM(DisplayName = "PropString") const TArray<FString>& InPropString)
{
	OnPropStringChanged.Broadcast(InPropString);

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnPropStringChangedBP.Broadcast(InPropString);

		for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropStringChanged(Obj, InPropString);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleArrayInterfacePublisher>(this), SubscribersCopy, InPropString]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnPropStringChangedBP.Broadcast(InPropString);
			}

			for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropStringChanged(Obj, InPropString);
				}
			}
		});
	}
}

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastPropReadOnlyStringChanged(UPARAM(DisplayName = "PropReadOnlyString") const FString& InPropReadOnlyString)
{
	OnPropReadOnlyStringChanged.Broadcast(InPropReadOnlyString);

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnPropReadOnlyStringChangedBP.Broadcast(InPropReadOnlyString);

		for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropReadOnlyStringChanged(Obj, InPropReadOnlyString);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleArrayInterfacePublisher>(this), SubscribersCopy, InPropReadOnlyString]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnPropReadOnlyStringChangedBP.Broadcast(InPropReadOnlyString);
			}

			for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropReadOnlyStringChanged(Obj, InPropReadOnlyString);
				}
			}
		});
	}
}

void UTbSimpleSimpleArrayInterfacePublisher::Subscribe(const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber)
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
	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
}
