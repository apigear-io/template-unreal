
#include "TbSimple/Generated/api/TbSimpleSimpleInterfaceInterface.h"
#include "Async/Async.h"
#include "Async/TaskGraphInterfaces.h"

void UTbSimpleSimpleInterfacePublisher::BroadcastSigBoolSignal(bool bParamBool)
{
	OnSigBoolSignal.Broadcast(bParamBool);
	TArray<TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleSimpleInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSigBoolSignal(bParamBool);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnSigBoolSignalBP.Broadcast(bParamBool);

		for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnSigBoolSignal(Obj, bParamBool);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleInterfacePublisher>(this), BPSubscribersCopy, bParamBool]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSigBoolSignalBP.Broadcast(bParamBool);
			}

			for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnSigBoolSignal(Obj, bParamBool);
				}
				else
				{
					if (WeakPtr.IsValid())
					{
						WeakPtr.Get()->Unsubscribe(Subscriber);
					}
				}
			}
		});
	}
}

void UTbSimpleSimpleInterfacePublisher::BroadcastSigIntSignal(int32 ParamInt)
{
	OnSigIntSignal.Broadcast(ParamInt);
	TArray<TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleSimpleInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSigIntSignal(ParamInt);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnSigIntSignalBP.Broadcast(ParamInt);

		for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnSigIntSignal(Obj, ParamInt);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleInterfacePublisher>(this), BPSubscribersCopy, ParamInt]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSigIntSignalBP.Broadcast(ParamInt);
			}

			for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnSigIntSignal(Obj, ParamInt);
				}
				else
				{
					if (WeakPtr.IsValid())
					{
						WeakPtr.Get()->Unsubscribe(Subscriber);
					}
				}
			}
		});
	}
}

void UTbSimpleSimpleInterfacePublisher::BroadcastSigInt32Signal(int32 ParamInt32)
{
	OnSigInt32Signal.Broadcast(ParamInt32);
	TArray<TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleSimpleInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSigInt32Signal(ParamInt32);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnSigInt32SignalBP.Broadcast(ParamInt32);

		for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnSigInt32Signal(Obj, ParamInt32);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleInterfacePublisher>(this), BPSubscribersCopy, ParamInt32]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSigInt32SignalBP.Broadcast(ParamInt32);
			}

			for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnSigInt32Signal(Obj, ParamInt32);
				}
				else
				{
					if (WeakPtr.IsValid())
					{
						WeakPtr.Get()->Unsubscribe(Subscriber);
					}
				}
			}
		});
	}
}

void UTbSimpleSimpleInterfacePublisher::BroadcastSigInt64Signal(int64 ParamInt64)
{
	OnSigInt64Signal.Broadcast(ParamInt64);
	TArray<TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleSimpleInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSigInt64Signal(ParamInt64);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnSigInt64SignalBP.Broadcast(ParamInt64);

		for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnSigInt64Signal(Obj, ParamInt64);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleInterfacePublisher>(this), BPSubscribersCopy, ParamInt64]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSigInt64SignalBP.Broadcast(ParamInt64);
			}

			for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnSigInt64Signal(Obj, ParamInt64);
				}
				else
				{
					if (WeakPtr.IsValid())
					{
						WeakPtr.Get()->Unsubscribe(Subscriber);
					}
				}
			}
		});
	}
}

void UTbSimpleSimpleInterfacePublisher::BroadcastSigFloatSignal(float ParamFloat)
{
	OnSigFloatSignal.Broadcast(ParamFloat);
	TArray<TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleSimpleInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSigFloatSignal(ParamFloat);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnSigFloatSignalBP.Broadcast(ParamFloat);

		for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnSigFloatSignal(Obj, ParamFloat);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleInterfacePublisher>(this), BPSubscribersCopy, ParamFloat]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSigFloatSignalBP.Broadcast(ParamFloat);
			}

			for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnSigFloatSignal(Obj, ParamFloat);
				}
				else
				{
					if (WeakPtr.IsValid())
					{
						WeakPtr.Get()->Unsubscribe(Subscriber);
					}
				}
			}
		});
	}
}

void UTbSimpleSimpleInterfacePublisher::BroadcastSigFloat32Signal(float ParamFloat32)
{
	OnSigFloat32Signal.Broadcast(ParamFloat32);
	TArray<TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleSimpleInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSigFloat32Signal(ParamFloat32);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnSigFloat32SignalBP.Broadcast(ParamFloat32);

		for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnSigFloat32Signal(Obj, ParamFloat32);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleInterfacePublisher>(this), BPSubscribersCopy, ParamFloat32]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSigFloat32SignalBP.Broadcast(ParamFloat32);
			}

			for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnSigFloat32Signal(Obj, ParamFloat32);
				}
				else
				{
					if (WeakPtr.IsValid())
					{
						WeakPtr.Get()->Unsubscribe(Subscriber);
					}
				}
			}
		});
	}
}

void UTbSimpleSimpleInterfacePublisher::BroadcastSigFloat64Signal(double ParamFloat64)
{
	OnSigFloat64Signal.Broadcast(ParamFloat64);
	TArray<TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleSimpleInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSigFloat64Signal(ParamFloat64);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnSigFloat64SignalBP.Broadcast(ParamFloat64);

		for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnSigFloat64Signal(Obj, ParamFloat64);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleInterfacePublisher>(this), BPSubscribersCopy, ParamFloat64]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSigFloat64SignalBP.Broadcast(ParamFloat64);
			}

			for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnSigFloat64Signal(Obj, ParamFloat64);
				}
				else
				{
					if (WeakPtr.IsValid())
					{
						WeakPtr.Get()->Unsubscribe(Subscriber);
					}
				}
			}
		});
	}
}

void UTbSimpleSimpleInterfacePublisher::BroadcastSigStringSignal(const FString& ParamString)
{
	OnSigStringSignal.Broadcast(ParamString);
	TArray<TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleSimpleInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSigStringSignal(ParamString);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnSigStringSignalBP.Broadcast(ParamString);

		for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnSigStringSignal(Obj, ParamString);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleInterfacePublisher>(this), BPSubscribersCopy, ParamString]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSigStringSignalBP.Broadcast(ParamString);
			}

			for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnSigStringSignal(Obj, ParamString);
				}
				else
				{
					if (WeakPtr.IsValid())
					{
						WeakPtr.Get()->Unsubscribe(Subscriber);
					}
				}
			}
		});
	}
}

void UTbSimpleSimpleInterfacePublisher::BroadcastPropBoolChanged(UPARAM(DisplayName = "bPropBool") bool bInPropBool)
{
	OnPropBoolChanged.Broadcast(bInPropBool);
	TArray<TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleSimpleInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnPropBoolChanged(bInPropBool);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnPropBoolChangedBP.Broadcast(bInPropBool);

		for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnPropBoolChanged(Obj, bInPropBool);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleInterfacePublisher>(this), BPSubscribersCopy, bInPropBool]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnPropBoolChangedBP.Broadcast(bInPropBool);
			}

			for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnPropBoolChanged(Obj, bInPropBool);
				}
				else
				{
					if (WeakPtr.IsValid())
					{
						WeakPtr.Get()->Unsubscribe(Subscriber);
					}
				}
			}
		});
	}
}

void UTbSimpleSimpleInterfacePublisher::BroadcastPropIntChanged(UPARAM(DisplayName = "PropInt") int32 InPropInt)
{
	OnPropIntChanged.Broadcast(InPropInt);
	TArray<TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleSimpleInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnPropIntChanged(InPropInt);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnPropIntChangedBP.Broadcast(InPropInt);

		for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnPropIntChanged(Obj, InPropInt);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleInterfacePublisher>(this), BPSubscribersCopy, InPropInt]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnPropIntChangedBP.Broadcast(InPropInt);
			}

			for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnPropIntChanged(Obj, InPropInt);
				}
				else
				{
					if (WeakPtr.IsValid())
					{
						WeakPtr.Get()->Unsubscribe(Subscriber);
					}
				}
			}
		});
	}
}

void UTbSimpleSimpleInterfacePublisher::BroadcastPropInt32Changed(UPARAM(DisplayName = "PropInt32") int32 InPropInt32)
{
	OnPropInt32Changed.Broadcast(InPropInt32);
	TArray<TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleSimpleInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnPropInt32Changed(InPropInt32);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnPropInt32ChangedBP.Broadcast(InPropInt32);

		for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnPropInt32Changed(Obj, InPropInt32);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleInterfacePublisher>(this), BPSubscribersCopy, InPropInt32]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnPropInt32ChangedBP.Broadcast(InPropInt32);
			}

			for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnPropInt32Changed(Obj, InPropInt32);
				}
				else
				{
					if (WeakPtr.IsValid())
					{
						WeakPtr.Get()->Unsubscribe(Subscriber);
					}
				}
			}
		});
	}
}

void UTbSimpleSimpleInterfacePublisher::BroadcastPropInt64Changed(UPARAM(DisplayName = "PropInt64") int64 InPropInt64)
{
	OnPropInt64Changed.Broadcast(InPropInt64);
	TArray<TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleSimpleInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnPropInt64Changed(InPropInt64);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnPropInt64ChangedBP.Broadcast(InPropInt64);

		for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnPropInt64Changed(Obj, InPropInt64);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleInterfacePublisher>(this), BPSubscribersCopy, InPropInt64]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnPropInt64ChangedBP.Broadcast(InPropInt64);
			}

			for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnPropInt64Changed(Obj, InPropInt64);
				}
				else
				{
					if (WeakPtr.IsValid())
					{
						WeakPtr.Get()->Unsubscribe(Subscriber);
					}
				}
			}
		});
	}
}

void UTbSimpleSimpleInterfacePublisher::BroadcastPropFloatChanged(UPARAM(DisplayName = "PropFloat") float InPropFloat)
{
	OnPropFloatChanged.Broadcast(InPropFloat);
	TArray<TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleSimpleInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnPropFloatChanged(InPropFloat);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnPropFloatChangedBP.Broadcast(InPropFloat);

		for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnPropFloatChanged(Obj, InPropFloat);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleInterfacePublisher>(this), BPSubscribersCopy, InPropFloat]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnPropFloatChangedBP.Broadcast(InPropFloat);
			}

			for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnPropFloatChanged(Obj, InPropFloat);
				}
				else
				{
					if (WeakPtr.IsValid())
					{
						WeakPtr.Get()->Unsubscribe(Subscriber);
					}
				}
			}
		});
	}
}

void UTbSimpleSimpleInterfacePublisher::BroadcastPropFloat32Changed(UPARAM(DisplayName = "PropFloat32") float InPropFloat32)
{
	OnPropFloat32Changed.Broadcast(InPropFloat32);
	TArray<TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleSimpleInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnPropFloat32Changed(InPropFloat32);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnPropFloat32ChangedBP.Broadcast(InPropFloat32);

		for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnPropFloat32Changed(Obj, InPropFloat32);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleInterfacePublisher>(this), BPSubscribersCopy, InPropFloat32]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnPropFloat32ChangedBP.Broadcast(InPropFloat32);
			}

			for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnPropFloat32Changed(Obj, InPropFloat32);
				}
				else
				{
					if (WeakPtr.IsValid())
					{
						WeakPtr.Get()->Unsubscribe(Subscriber);
					}
				}
			}
		});
	}
}

void UTbSimpleSimpleInterfacePublisher::BroadcastPropFloat64Changed(UPARAM(DisplayName = "PropFloat64") double InPropFloat64)
{
	OnPropFloat64Changed.Broadcast(InPropFloat64);
	TArray<TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleSimpleInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnPropFloat64Changed(InPropFloat64);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnPropFloat64ChangedBP.Broadcast(InPropFloat64);

		for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnPropFloat64Changed(Obj, InPropFloat64);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleInterfacePublisher>(this), BPSubscribersCopy, InPropFloat64]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnPropFloat64ChangedBP.Broadcast(InPropFloat64);
			}

			for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnPropFloat64Changed(Obj, InPropFloat64);
				}
				else
				{
					if (WeakPtr.IsValid())
					{
						WeakPtr.Get()->Unsubscribe(Subscriber);
					}
				}
			}
		});
	}
}

void UTbSimpleSimpleInterfacePublisher::BroadcastPropStringChanged(UPARAM(DisplayName = "PropString") const FString& InPropString)
{
	OnPropStringChanged.Broadcast(InPropString);
	TArray<TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleSimpleInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnPropStringChanged(InPropString);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnPropStringChangedBP.Broadcast(InPropString);

		for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnPropStringChanged(Obj, InPropString);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleInterfacePublisher>(this), BPSubscribersCopy, InPropString]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnPropStringChangedBP.Broadcast(InPropString);
			}

			for (const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleSimpleInterfaceBPSubscriberInterface::Execute_OnPropStringChanged(Obj, InPropString);
				}
				else
				{
					if (WeakPtr.IsValid())
					{
						WeakPtr.Get()->Unsubscribe(Subscriber);
					}
				}
			}
		});
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
