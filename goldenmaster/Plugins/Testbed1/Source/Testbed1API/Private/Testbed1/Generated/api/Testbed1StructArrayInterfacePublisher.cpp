
#include "Testbed1/Generated/api/Testbed1StructArrayInterfaceInterface.h"
#include "Async/Async.h"
#include "Async/TaskGraphInterfaces.h"

void UTestbed1StructArrayInterfacePublisher::BroadcastSigBoolSignal(const TArray<FTestbed1StructBool>& ParamBool)
{
	OnSigBoolSignal.Broadcast(ParamBool);
	TArray<TWeakInterfacePtr<ITestbed1StructArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITestbed1StructArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed1StructArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSigBoolSignal(ParamBool);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnSigBoolSignalBP.Broadcast(ParamBool);

		for (const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArrayInterfaceBPSubscriberInterface::Execute_OnSigBoolSignal(Obj, ParamBool);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTestbed1StructArrayInterfacePublisher>(this), BPSubscribersCopy, ParamBool]()
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

void UTestbed1StructArrayInterfacePublisher::BroadcastSigIntSignal(const TArray<FTestbed1StructInt>& ParamInt)
{
	OnSigIntSignal.Broadcast(ParamInt);
	TArray<TWeakInterfacePtr<ITestbed1StructArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITestbed1StructArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed1StructArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSigIntSignal(ParamInt);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnSigIntSignalBP.Broadcast(ParamInt);

		for (const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArrayInterfaceBPSubscriberInterface::Execute_OnSigIntSignal(Obj, ParamInt);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTestbed1StructArrayInterfacePublisher>(this), BPSubscribersCopy, ParamInt]()
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

void UTestbed1StructArrayInterfacePublisher::BroadcastSigFloatSignal(const TArray<FTestbed1StructFloat>& ParamFloat)
{
	OnSigFloatSignal.Broadcast(ParamFloat);
	TArray<TWeakInterfacePtr<ITestbed1StructArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITestbed1StructArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed1StructArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSigFloatSignal(ParamFloat);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnSigFloatSignalBP.Broadcast(ParamFloat);

		for (const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArrayInterfaceBPSubscriberInterface::Execute_OnSigFloatSignal(Obj, ParamFloat);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTestbed1StructArrayInterfacePublisher>(this), BPSubscribersCopy, ParamFloat]()
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

void UTestbed1StructArrayInterfacePublisher::BroadcastSigStringSignal(const TArray<FTestbed1StructString>& ParamString)
{
	OnSigStringSignal.Broadcast(ParamString);
	TArray<TWeakInterfacePtr<ITestbed1StructArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITestbed1StructArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed1StructArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSigStringSignal(ParamString);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnSigStringSignalBP.Broadcast(ParamString);

		for (const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArrayInterfaceBPSubscriberInterface::Execute_OnSigStringSignal(Obj, ParamString);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTestbed1StructArrayInterfacePublisher>(this), BPSubscribersCopy, ParamString]()
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

void UTestbed1StructArrayInterfacePublisher::BroadcastSigEnumSignal(const TArray<ETestbed1Enum0>& ParamEnum)
{
	OnSigEnumSignal.Broadcast(ParamEnum);
	TArray<TWeakInterfacePtr<ITestbed1StructArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITestbed1StructArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed1StructArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSigEnumSignal(ParamEnum);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnSigEnumSignalBP.Broadcast(ParamEnum);

		for (const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArrayInterfaceBPSubscriberInterface::Execute_OnSigEnumSignal(Obj, ParamEnum);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTestbed1StructArrayInterfacePublisher>(this), BPSubscribersCopy, ParamEnum]()
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

void UTestbed1StructArrayInterfacePublisher::BroadcastPropBoolChanged(UPARAM(DisplayName = "PropBool") const TArray<FTestbed1StructBool>& InPropBool)
{
	OnPropBoolChanged.Broadcast(InPropBool);
	TArray<TWeakInterfacePtr<ITestbed1StructArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITestbed1StructArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed1StructArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnPropBoolChanged(InPropBool);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnPropBoolChangedBP.Broadcast(InPropBool);

		for (const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArrayInterfaceBPSubscriberInterface::Execute_OnPropBoolChanged(Obj, InPropBool);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTestbed1StructArrayInterfacePublisher>(this), BPSubscribersCopy, InPropBool]()
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

void UTestbed1StructArrayInterfacePublisher::BroadcastPropIntChanged(UPARAM(DisplayName = "PropInt") const TArray<FTestbed1StructInt>& InPropInt)
{
	OnPropIntChanged.Broadcast(InPropInt);
	TArray<TWeakInterfacePtr<ITestbed1StructArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITestbed1StructArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed1StructArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnPropIntChanged(InPropInt);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnPropIntChangedBP.Broadcast(InPropInt);

		for (const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArrayInterfaceBPSubscriberInterface::Execute_OnPropIntChanged(Obj, InPropInt);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTestbed1StructArrayInterfacePublisher>(this), BPSubscribersCopy, InPropInt]()
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

void UTestbed1StructArrayInterfacePublisher::BroadcastPropFloatChanged(UPARAM(DisplayName = "PropFloat") const TArray<FTestbed1StructFloat>& InPropFloat)
{
	OnPropFloatChanged.Broadcast(InPropFloat);
	TArray<TWeakInterfacePtr<ITestbed1StructArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITestbed1StructArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed1StructArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnPropFloatChanged(InPropFloat);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnPropFloatChangedBP.Broadcast(InPropFloat);

		for (const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArrayInterfaceBPSubscriberInterface::Execute_OnPropFloatChanged(Obj, InPropFloat);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTestbed1StructArrayInterfacePublisher>(this), BPSubscribersCopy, InPropFloat]()
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

void UTestbed1StructArrayInterfacePublisher::BroadcastPropStringChanged(UPARAM(DisplayName = "PropString") const TArray<FTestbed1StructString>& InPropString)
{
	OnPropStringChanged.Broadcast(InPropString);
	TArray<TWeakInterfacePtr<ITestbed1StructArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITestbed1StructArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed1StructArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnPropStringChanged(InPropString);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnPropStringChangedBP.Broadcast(InPropString);

		for (const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArrayInterfaceBPSubscriberInterface::Execute_OnPropStringChanged(Obj, InPropString);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTestbed1StructArrayInterfacePublisher>(this), BPSubscribersCopy, InPropString]()
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

void UTestbed1StructArrayInterfacePublisher::BroadcastPropEnumChanged(UPARAM(DisplayName = "PropEnum") const TArray<ETestbed1Enum0>& InPropEnum)
{
	OnPropEnumChanged.Broadcast(InPropEnum);
	TArray<TWeakInterfacePtr<ITestbed1StructArrayInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITestbed1StructArrayInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed1StructArrayInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnPropEnumChanged(InPropEnum);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnPropEnumChangedBP.Broadcast(InPropEnum);

		for (const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArrayInterfaceBPSubscriberInterface::Execute_OnPropEnumChanged(Obj, InPropEnum);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTestbed1StructArrayInterfacePublisher>(this), BPSubscribersCopy, InPropEnum]()
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
