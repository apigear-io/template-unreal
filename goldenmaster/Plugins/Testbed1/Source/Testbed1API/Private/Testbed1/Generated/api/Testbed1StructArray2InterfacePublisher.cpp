
#include "Testbed1/Generated/api/Testbed1StructArray2InterfaceInterface.h"
#include "Async/Async.h"
#include "Async/TaskGraphInterfaces.h"

void UTestbed1StructArray2InterfacePublisher::BroadcastSigBoolSignal(const FTestbed1StructBoolWithArray& ParamBool)
{
	OnSigBoolSignal.Broadcast(ParamBool);
	TArray<TWeakInterfacePtr<ITestbed1StructArray2InterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITestbed1StructArray2InterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed1StructArray2InterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSigBoolSignal(ParamBool);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnSigBoolSignalBP.Broadcast(ParamBool);

		for (const TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArray2InterfaceBPSubscriberInterface::Execute_OnSigBoolSignal(Obj, ParamBool);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTestbed1StructArray2InterfacePublisher>(this), BPSubscribersCopy, ParamBool]()
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

void UTestbed1StructArray2InterfacePublisher::BroadcastSigIntSignal(const FTestbed1StructIntWithArray& ParamInt)
{
	OnSigIntSignal.Broadcast(ParamInt);
	TArray<TWeakInterfacePtr<ITestbed1StructArray2InterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITestbed1StructArray2InterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed1StructArray2InterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSigIntSignal(ParamInt);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnSigIntSignalBP.Broadcast(ParamInt);

		for (const TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArray2InterfaceBPSubscriberInterface::Execute_OnSigIntSignal(Obj, ParamInt);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTestbed1StructArray2InterfacePublisher>(this), BPSubscribersCopy, ParamInt]()
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

void UTestbed1StructArray2InterfacePublisher::BroadcastSigFloatSignal(const FTestbed1StructFloatWithArray& ParamFloat)
{
	OnSigFloatSignal.Broadcast(ParamFloat);
	TArray<TWeakInterfacePtr<ITestbed1StructArray2InterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITestbed1StructArray2InterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed1StructArray2InterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSigFloatSignal(ParamFloat);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnSigFloatSignalBP.Broadcast(ParamFloat);

		for (const TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArray2InterfaceBPSubscriberInterface::Execute_OnSigFloatSignal(Obj, ParamFloat);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTestbed1StructArray2InterfacePublisher>(this), BPSubscribersCopy, ParamFloat]()
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

void UTestbed1StructArray2InterfacePublisher::BroadcastSigStringSignal(const FTestbed1StructStringWithArray& ParamString)
{
	OnSigStringSignal.Broadcast(ParamString);
	TArray<TWeakInterfacePtr<ITestbed1StructArray2InterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITestbed1StructArray2InterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed1StructArray2InterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSigStringSignal(ParamString);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnSigStringSignalBP.Broadcast(ParamString);

		for (const TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArray2InterfaceBPSubscriberInterface::Execute_OnSigStringSignal(Obj, ParamString);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTestbed1StructArray2InterfacePublisher>(this), BPSubscribersCopy, ParamString]()
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

void UTestbed1StructArray2InterfacePublisher::BroadcastPropBoolChanged(UPARAM(DisplayName = "PropBool") const FTestbed1StructBoolWithArray& InPropBool)
{
	OnPropBoolChanged.Broadcast(InPropBool);
	TArray<TWeakInterfacePtr<ITestbed1StructArray2InterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITestbed1StructArray2InterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed1StructArray2InterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnPropBoolChanged(InPropBool);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnPropBoolChangedBP.Broadcast(InPropBool);

		for (const TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArray2InterfaceBPSubscriberInterface::Execute_OnPropBoolChanged(Obj, InPropBool);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTestbed1StructArray2InterfacePublisher>(this), BPSubscribersCopy, InPropBool]()
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

void UTestbed1StructArray2InterfacePublisher::BroadcastPropIntChanged(UPARAM(DisplayName = "PropInt") const FTestbed1StructIntWithArray& InPropInt)
{
	OnPropIntChanged.Broadcast(InPropInt);
	TArray<TWeakInterfacePtr<ITestbed1StructArray2InterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITestbed1StructArray2InterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed1StructArray2InterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnPropIntChanged(InPropInt);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnPropIntChangedBP.Broadcast(InPropInt);

		for (const TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArray2InterfaceBPSubscriberInterface::Execute_OnPropIntChanged(Obj, InPropInt);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTestbed1StructArray2InterfacePublisher>(this), BPSubscribersCopy, InPropInt]()
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

void UTestbed1StructArray2InterfacePublisher::BroadcastPropFloatChanged(UPARAM(DisplayName = "PropFloat") const FTestbed1StructFloatWithArray& InPropFloat)
{
	OnPropFloatChanged.Broadcast(InPropFloat);
	TArray<TWeakInterfacePtr<ITestbed1StructArray2InterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITestbed1StructArray2InterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed1StructArray2InterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnPropFloatChanged(InPropFloat);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnPropFloatChangedBP.Broadcast(InPropFloat);

		for (const TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArray2InterfaceBPSubscriberInterface::Execute_OnPropFloatChanged(Obj, InPropFloat);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTestbed1StructArray2InterfacePublisher>(this), BPSubscribersCopy, InPropFloat]()
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

void UTestbed1StructArray2InterfacePublisher::BroadcastPropStringChanged(UPARAM(DisplayName = "PropString") const FTestbed1StructStringWithArray& InPropString)
{
	OnPropStringChanged.Broadcast(InPropString);
	TArray<TWeakInterfacePtr<ITestbed1StructArray2InterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITestbed1StructArray2InterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed1StructArray2InterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnPropStringChanged(InPropString);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnPropStringChangedBP.Broadcast(InPropString);

		for (const TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArray2InterfaceBPSubscriberInterface::Execute_OnPropStringChanged(Obj, InPropString);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTestbed1StructArray2InterfacePublisher>(this), BPSubscribersCopy, InPropString]()
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

void UTestbed1StructArray2InterfacePublisher::BroadcastPropEnumChanged(UPARAM(DisplayName = "PropEnum") const FTestbed1StructEnumWithArray& InPropEnum)
{
	OnPropEnumChanged.Broadcast(InPropEnum);
	TArray<TWeakInterfacePtr<ITestbed1StructArray2InterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITestbed1StructArray2InterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed1StructArray2InterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnPropEnumChanged(InPropEnum);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnPropEnumChangedBP.Broadcast(InPropEnum);

		for (const TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArray2InterfaceBPSubscriberInterface::Execute_OnPropEnumChanged(Obj, InPropEnum);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTestbed1StructArray2InterfacePublisher>(this), BPSubscribersCopy, InPropEnum]()
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
