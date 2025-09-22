
#include "Testbed1/Generated/api/Testbed1StructArrayInterfaceInterface.h"
#include "Async/Async.h"
#include "Async/TaskGraphInterfaces.h"

void UTestbed1StructArrayInterfacePublisher::BroadcastSigBoolSignal(const TArray<FTestbed1StructBool>& ParamBool)
{
	OnSigBoolSignal.Broadcast(ParamBool);

	TArray<TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnSigBoolSignalBP.Broadcast(ParamBool);

		for (const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArrayInterfaceBPSubscriberInterface::Execute_OnSigBoolSignal(Obj, ParamBool);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTestbed1StructArrayInterfacePublisher>(this), SubscribersCopy, ParamBool]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSigBoolSignalBP.Broadcast(ParamBool);
			}

			for (const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITestbed1StructArrayInterfaceBPSubscriberInterface::Execute_OnSigBoolSignal(Obj, ParamBool);
				}
			}
		});
	}
}

void UTestbed1StructArrayInterfacePublisher::BroadcastSigIntSignal(const TArray<FTestbed1StructInt>& ParamInt)
{
	OnSigIntSignal.Broadcast(ParamInt);

	TArray<TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnSigIntSignalBP.Broadcast(ParamInt);

		for (const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArrayInterfaceBPSubscriberInterface::Execute_OnSigIntSignal(Obj, ParamInt);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTestbed1StructArrayInterfacePublisher>(this), SubscribersCopy, ParamInt]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSigIntSignalBP.Broadcast(ParamInt);
			}

			for (const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITestbed1StructArrayInterfaceBPSubscriberInterface::Execute_OnSigIntSignal(Obj, ParamInt);
				}
			}
		});
	}
}

void UTestbed1StructArrayInterfacePublisher::BroadcastSigFloatSignal(const TArray<FTestbed1StructFloat>& ParamFloat)
{
	OnSigFloatSignal.Broadcast(ParamFloat);

	TArray<TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnSigFloatSignalBP.Broadcast(ParamFloat);

		for (const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArrayInterfaceBPSubscriberInterface::Execute_OnSigFloatSignal(Obj, ParamFloat);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTestbed1StructArrayInterfacePublisher>(this), SubscribersCopy, ParamFloat]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSigFloatSignalBP.Broadcast(ParamFloat);
			}

			for (const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITestbed1StructArrayInterfaceBPSubscriberInterface::Execute_OnSigFloatSignal(Obj, ParamFloat);
				}
			}
		});
	}
}

void UTestbed1StructArrayInterfacePublisher::BroadcastSigStringSignal(const TArray<FTestbed1StructString>& ParamString)
{
	OnSigStringSignal.Broadcast(ParamString);

	TArray<TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnSigStringSignalBP.Broadcast(ParamString);

		for (const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArrayInterfaceBPSubscriberInterface::Execute_OnSigStringSignal(Obj, ParamString);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTestbed1StructArrayInterfacePublisher>(this), SubscribersCopy, ParamString]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSigStringSignalBP.Broadcast(ParamString);
			}

			for (const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITestbed1StructArrayInterfaceBPSubscriberInterface::Execute_OnSigStringSignal(Obj, ParamString);
				}
			}
		});
	}
}

void UTestbed1StructArrayInterfacePublisher::BroadcastSigEnumSignal(const TArray<ETestbed1Enum0>& ParamEnum)
{
	OnSigEnumSignal.Broadcast(ParamEnum);

	TArray<TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnSigEnumSignalBP.Broadcast(ParamEnum);

		for (const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArrayInterfaceBPSubscriberInterface::Execute_OnSigEnumSignal(Obj, ParamEnum);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTestbed1StructArrayInterfacePublisher>(this), SubscribersCopy, ParamEnum]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSigEnumSignalBP.Broadcast(ParamEnum);
			}

			for (const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITestbed1StructArrayInterfaceBPSubscriberInterface::Execute_OnSigEnumSignal(Obj, ParamEnum);
				}
			}
		});
	}
}

void UTestbed1StructArrayInterfacePublisher::BroadcastPropBoolChanged(UPARAM(DisplayName = "PropBool") const TArray<FTestbed1StructBool>& InPropBool)
{
	OnPropBoolChanged.Broadcast(InPropBool);

	TArray<TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnPropBoolChangedBP.Broadcast(InPropBool);

		for (const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArrayInterfaceBPSubscriberInterface::Execute_OnPropBoolChanged(Obj, InPropBool);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTestbed1StructArrayInterfacePublisher>(this), SubscribersCopy, InPropBool]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnPropBoolChangedBP.Broadcast(InPropBool);
			}

			for (const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITestbed1StructArrayInterfaceBPSubscriberInterface::Execute_OnPropBoolChanged(Obj, InPropBool);
				}
			}
		});
	}
}

void UTestbed1StructArrayInterfacePublisher::BroadcastPropIntChanged(UPARAM(DisplayName = "PropInt") const TArray<FTestbed1StructInt>& InPropInt)
{
	OnPropIntChanged.Broadcast(InPropInt);

	TArray<TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnPropIntChangedBP.Broadcast(InPropInt);

		for (const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArrayInterfaceBPSubscriberInterface::Execute_OnPropIntChanged(Obj, InPropInt);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTestbed1StructArrayInterfacePublisher>(this), SubscribersCopy, InPropInt]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnPropIntChangedBP.Broadcast(InPropInt);
			}

			for (const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITestbed1StructArrayInterfaceBPSubscriberInterface::Execute_OnPropIntChanged(Obj, InPropInt);
				}
			}
		});
	}
}

void UTestbed1StructArrayInterfacePublisher::BroadcastPropFloatChanged(UPARAM(DisplayName = "PropFloat") const TArray<FTestbed1StructFloat>& InPropFloat)
{
	OnPropFloatChanged.Broadcast(InPropFloat);

	TArray<TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnPropFloatChangedBP.Broadcast(InPropFloat);

		for (const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArrayInterfaceBPSubscriberInterface::Execute_OnPropFloatChanged(Obj, InPropFloat);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTestbed1StructArrayInterfacePublisher>(this), SubscribersCopy, InPropFloat]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnPropFloatChangedBP.Broadcast(InPropFloat);
			}

			for (const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITestbed1StructArrayInterfaceBPSubscriberInterface::Execute_OnPropFloatChanged(Obj, InPropFloat);
				}
			}
		});
	}
}

void UTestbed1StructArrayInterfacePublisher::BroadcastPropStringChanged(UPARAM(DisplayName = "PropString") const TArray<FTestbed1StructString>& InPropString)
{
	OnPropStringChanged.Broadcast(InPropString);

	TArray<TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnPropStringChangedBP.Broadcast(InPropString);

		for (const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArrayInterfaceBPSubscriberInterface::Execute_OnPropStringChanged(Obj, InPropString);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTestbed1StructArrayInterfacePublisher>(this), SubscribersCopy, InPropString]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnPropStringChangedBP.Broadcast(InPropString);
			}

			for (const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITestbed1StructArrayInterfaceBPSubscriberInterface::Execute_OnPropStringChanged(Obj, InPropString);
				}
			}
		});
	}
}

void UTestbed1StructArrayInterfacePublisher::BroadcastPropEnumChanged(UPARAM(DisplayName = "PropEnum") const TArray<ETestbed1Enum0>& InPropEnum)
{
	OnPropEnumChanged.Broadcast(InPropEnum);

	TArray<TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnPropEnumChangedBP.Broadcast(InPropEnum);

		for (const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArrayInterfaceBPSubscriberInterface::Execute_OnPropEnumChanged(Obj, InPropEnum);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTestbed1StructArrayInterfacePublisher>(this), SubscribersCopy, InPropEnum]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnPropEnumChangedBP.Broadcast(InPropEnum);
			}

			for (const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITestbed1StructArrayInterfaceBPSubscriberInterface::Execute_OnPropEnumChanged(Obj, InPropEnum);
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

	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
	Subscribers.Add(Subscriber);
}

void UTestbed1StructArrayInterfacePublisher::Unsubscribe(const TScriptInterface<ITestbed1StructArrayInterfaceBPSubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
}
