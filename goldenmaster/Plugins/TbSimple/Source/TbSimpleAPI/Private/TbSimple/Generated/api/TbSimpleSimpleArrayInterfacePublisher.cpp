
#include "TbSimple/Generated/api/TbSimpleSimpleArrayInterfaceInterface.h"
#include "Async/Async.h"
#include "Async/TaskGraphInterfaces.h"

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastSigBoolSignal(const TArray<bool>& ParamBool)
{
	OnSigBoolSignal.Broadcast(ParamBool);
	TArray<TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleSimpleArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSigBoolSignal(ParamBool);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnSigBoolSignalBP.Broadcast(ParamBool);

		for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnSigBoolSignal(Obj, ParamBool);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleArrayInterfacePublisher>(this), BPSubscribersCopy, ParamBool]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSigBoolSignalBP.Broadcast(ParamBool);
			}

			for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnSigBoolSignal(Obj, ParamBool);
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

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastSigIntSignal(const TArray<int32>& ParamInt)
{
	OnSigIntSignal.Broadcast(ParamInt);
	TArray<TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleSimpleArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSigIntSignal(ParamInt);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnSigIntSignalBP.Broadcast(ParamInt);

		for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnSigIntSignal(Obj, ParamInt);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleArrayInterfacePublisher>(this), BPSubscribersCopy, ParamInt]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSigIntSignalBP.Broadcast(ParamInt);
			}

			for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnSigIntSignal(Obj, ParamInt);
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

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastSigInt32Signal(const TArray<int32>& ParamInt32)
{
	OnSigInt32Signal.Broadcast(ParamInt32);
	TArray<TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleSimpleArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSigInt32Signal(ParamInt32);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnSigInt32SignalBP.Broadcast(ParamInt32);

		for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnSigInt32Signal(Obj, ParamInt32);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleArrayInterfacePublisher>(this), BPSubscribersCopy, ParamInt32]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSigInt32SignalBP.Broadcast(ParamInt32);
			}

			for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnSigInt32Signal(Obj, ParamInt32);
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

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastSigInt64Signal(const TArray<int64>& ParamInt64)
{
	OnSigInt64Signal.Broadcast(ParamInt64);
	TArray<TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleSimpleArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSigInt64Signal(ParamInt64);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnSigInt64SignalBP.Broadcast(ParamInt64);

		for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnSigInt64Signal(Obj, ParamInt64);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleArrayInterfacePublisher>(this), BPSubscribersCopy, ParamInt64]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSigInt64SignalBP.Broadcast(ParamInt64);
			}

			for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnSigInt64Signal(Obj, ParamInt64);
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

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastSigFloatSignal(const TArray<float>& ParamFloat)
{
	OnSigFloatSignal.Broadcast(ParamFloat);
	TArray<TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleSimpleArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSigFloatSignal(ParamFloat);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnSigFloatSignalBP.Broadcast(ParamFloat);

		for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnSigFloatSignal(Obj, ParamFloat);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleArrayInterfacePublisher>(this), BPSubscribersCopy, ParamFloat]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSigFloatSignalBP.Broadcast(ParamFloat);
			}

			for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnSigFloatSignal(Obj, ParamFloat);
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

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastSigFloat32Signal(const TArray<float>& ParamFloa32)
{
	OnSigFloat32Signal.Broadcast(ParamFloa32);
	TArray<TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleSimpleArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSigFloat32Signal(ParamFloa32);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnSigFloat32SignalBP.Broadcast(ParamFloa32);

		for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnSigFloat32Signal(Obj, ParamFloa32);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleArrayInterfacePublisher>(this), BPSubscribersCopy, ParamFloa32]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSigFloat32SignalBP.Broadcast(ParamFloa32);
			}

			for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnSigFloat32Signal(Obj, ParamFloa32);
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

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastSigFloat64Signal(const TArray<double>& ParamFloat64)
{
	OnSigFloat64Signal.Broadcast(ParamFloat64);
	TArray<TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleSimpleArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSigFloat64Signal(ParamFloat64);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnSigFloat64SignalBP.Broadcast(ParamFloat64);

		for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnSigFloat64Signal(Obj, ParamFloat64);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleArrayInterfacePublisher>(this), BPSubscribersCopy, ParamFloat64]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSigFloat64SignalBP.Broadcast(ParamFloat64);
			}

			for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnSigFloat64Signal(Obj, ParamFloat64);
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

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastSigStringSignal(const TArray<FString>& ParamString)
{
	OnSigStringSignal.Broadcast(ParamString);
	TArray<TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleSimpleArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSigStringSignal(ParamString);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnSigStringSignalBP.Broadcast(ParamString);

		for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnSigStringSignal(Obj, ParamString);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleArrayInterfacePublisher>(this), BPSubscribersCopy, ParamString]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSigStringSignalBP.Broadcast(ParamString);
			}

			for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnSigStringSignal(Obj, ParamString);
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

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastPropBoolChanged(UPARAM(DisplayName = "PropBool") const TArray<bool>& InPropBool)
{
	OnPropBoolChanged.Broadcast(InPropBool);
	TArray<TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleSimpleArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnPropBoolChanged(InPropBool);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnPropBoolChangedBP.Broadcast(InPropBool);

		for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropBoolChanged(Obj, InPropBool);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleArrayInterfacePublisher>(this), BPSubscribersCopy, InPropBool]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnPropBoolChangedBP.Broadcast(InPropBool);
			}

			for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropBoolChanged(Obj, InPropBool);
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

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastPropIntChanged(UPARAM(DisplayName = "PropInt") const TArray<int32>& InPropInt)
{
	OnPropIntChanged.Broadcast(InPropInt);
	TArray<TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleSimpleArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnPropIntChanged(InPropInt);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnPropIntChangedBP.Broadcast(InPropInt);

		for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropIntChanged(Obj, InPropInt);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleArrayInterfacePublisher>(this), BPSubscribersCopy, InPropInt]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnPropIntChangedBP.Broadcast(InPropInt);
			}

			for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropIntChanged(Obj, InPropInt);
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

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastPropInt32Changed(UPARAM(DisplayName = "PropInt32") const TArray<int32>& InPropInt32)
{
	OnPropInt32Changed.Broadcast(InPropInt32);
	TArray<TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleSimpleArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnPropInt32Changed(InPropInt32);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnPropInt32ChangedBP.Broadcast(InPropInt32);

		for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropInt32Changed(Obj, InPropInt32);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleArrayInterfacePublisher>(this), BPSubscribersCopy, InPropInt32]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnPropInt32ChangedBP.Broadcast(InPropInt32);
			}

			for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropInt32Changed(Obj, InPropInt32);
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

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastPropInt64Changed(UPARAM(DisplayName = "PropInt64") const TArray<int64>& InPropInt64)
{
	OnPropInt64Changed.Broadcast(InPropInt64);
	TArray<TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleSimpleArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnPropInt64Changed(InPropInt64);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnPropInt64ChangedBP.Broadcast(InPropInt64);

		for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropInt64Changed(Obj, InPropInt64);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleArrayInterfacePublisher>(this), BPSubscribersCopy, InPropInt64]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnPropInt64ChangedBP.Broadcast(InPropInt64);
			}

			for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropInt64Changed(Obj, InPropInt64);
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

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastPropFloatChanged(UPARAM(DisplayName = "PropFloat") const TArray<float>& InPropFloat)
{
	OnPropFloatChanged.Broadcast(InPropFloat);
	TArray<TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleSimpleArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnPropFloatChanged(InPropFloat);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnPropFloatChangedBP.Broadcast(InPropFloat);

		for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropFloatChanged(Obj, InPropFloat);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleArrayInterfacePublisher>(this), BPSubscribersCopy, InPropFloat]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnPropFloatChangedBP.Broadcast(InPropFloat);
			}

			for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropFloatChanged(Obj, InPropFloat);
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

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastPropFloat32Changed(UPARAM(DisplayName = "PropFloat32") const TArray<float>& InPropFloat32)
{
	OnPropFloat32Changed.Broadcast(InPropFloat32);
	TArray<TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleSimpleArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnPropFloat32Changed(InPropFloat32);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnPropFloat32ChangedBP.Broadcast(InPropFloat32);

		for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropFloat32Changed(Obj, InPropFloat32);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleArrayInterfacePublisher>(this), BPSubscribersCopy, InPropFloat32]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnPropFloat32ChangedBP.Broadcast(InPropFloat32);
			}

			for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropFloat32Changed(Obj, InPropFloat32);
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

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastPropFloat64Changed(UPARAM(DisplayName = "PropFloat64") const TArray<double>& InPropFloat64)
{
	OnPropFloat64Changed.Broadcast(InPropFloat64);
	TArray<TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleSimpleArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnPropFloat64Changed(InPropFloat64);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnPropFloat64ChangedBP.Broadcast(InPropFloat64);

		for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropFloat64Changed(Obj, InPropFloat64);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleArrayInterfacePublisher>(this), BPSubscribersCopy, InPropFloat64]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnPropFloat64ChangedBP.Broadcast(InPropFloat64);
			}

			for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropFloat64Changed(Obj, InPropFloat64);
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

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastPropStringChanged(UPARAM(DisplayName = "PropString") const TArray<FString>& InPropString)
{
	OnPropStringChanged.Broadcast(InPropString);
	TArray<TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleSimpleArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnPropStringChanged(InPropString);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnPropStringChangedBP.Broadcast(InPropString);

		for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropStringChanged(Obj, InPropString);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleArrayInterfacePublisher>(this), BPSubscribersCopy, InPropString]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnPropStringChangedBP.Broadcast(InPropString);
			}

			for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropStringChanged(Obj, InPropString);
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

void UTbSimpleSimpleArrayInterfacePublisher::BroadcastPropReadOnlyStringChanged(UPARAM(DisplayName = "PropReadOnlyString") const FString& InPropReadOnlyString)
{
	OnPropReadOnlyStringChanged.Broadcast(InPropReadOnlyString);
	TArray<TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleSimpleArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnPropReadOnlyStringChanged(InPropReadOnlyString);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnPropReadOnlyStringChangedBP.Broadcast(InPropReadOnlyString);

		for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropReadOnlyStringChanged(Obj, InPropReadOnlyString);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleSimpleArrayInterfacePublisher>(this), BPSubscribersCopy, InPropReadOnlyString]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnPropReadOnlyStringChangedBP.Broadcast(InPropReadOnlyString);
			}

			for (const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleSimpleArrayInterfaceBPSubscriberInterface::Execute_OnPropReadOnlyStringChanged(Obj, InPropReadOnlyString);
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
