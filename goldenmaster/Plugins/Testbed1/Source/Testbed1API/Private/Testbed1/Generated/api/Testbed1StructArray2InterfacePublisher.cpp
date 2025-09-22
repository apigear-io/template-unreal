
#include "Testbed1/Generated/api/Testbed1StructArray2InterfaceInterface.h"
#include "Async/Async.h"
#include "Async/TaskGraphInterfaces.h"

void UTestbed1StructArray2InterfacePublisher::BroadcastSigBoolSignal(const FTestbed1StructBoolWithArray& ParamBool)
{
	OnSigBoolSignal.Broadcast(ParamBool);

	TArray<TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnSigBoolSignalBP.Broadcast(ParamBool);

		for (const TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArray2InterfaceBPSubscriberInterface::Execute_OnSigBoolSignal(Obj, ParamBool);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTestbed1StructArray2InterfacePublisher>(this), SubscribersCopy, ParamBool]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSigBoolSignalBP.Broadcast(ParamBool);
			}

			for (const TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITestbed1StructArray2InterfaceBPSubscriberInterface::Execute_OnSigBoolSignal(Obj, ParamBool);
				}
			}
		});
	}
}

void UTestbed1StructArray2InterfacePublisher::BroadcastSigIntSignal(const FTestbed1StructIntWithArray& ParamInt)
{
	OnSigIntSignal.Broadcast(ParamInt);

	TArray<TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnSigIntSignalBP.Broadcast(ParamInt);

		for (const TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArray2InterfaceBPSubscriberInterface::Execute_OnSigIntSignal(Obj, ParamInt);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTestbed1StructArray2InterfacePublisher>(this), SubscribersCopy, ParamInt]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSigIntSignalBP.Broadcast(ParamInt);
			}

			for (const TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITestbed1StructArray2InterfaceBPSubscriberInterface::Execute_OnSigIntSignal(Obj, ParamInt);
				}
			}
		});
	}
}

void UTestbed1StructArray2InterfacePublisher::BroadcastSigFloatSignal(const FTestbed1StructFloatWithArray& ParamFloat)
{
	OnSigFloatSignal.Broadcast(ParamFloat);

	TArray<TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnSigFloatSignalBP.Broadcast(ParamFloat);

		for (const TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArray2InterfaceBPSubscriberInterface::Execute_OnSigFloatSignal(Obj, ParamFloat);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTestbed1StructArray2InterfacePublisher>(this), SubscribersCopy, ParamFloat]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSigFloatSignalBP.Broadcast(ParamFloat);
			}

			for (const TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITestbed1StructArray2InterfaceBPSubscriberInterface::Execute_OnSigFloatSignal(Obj, ParamFloat);
				}
			}
		});
	}
}

void UTestbed1StructArray2InterfacePublisher::BroadcastSigStringSignal(const FTestbed1StructStringWithArray& ParamString)
{
	OnSigStringSignal.Broadcast(ParamString);

	TArray<TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnSigStringSignalBP.Broadcast(ParamString);

		for (const TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArray2InterfaceBPSubscriberInterface::Execute_OnSigStringSignal(Obj, ParamString);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTestbed1StructArray2InterfacePublisher>(this), SubscribersCopy, ParamString]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSigStringSignalBP.Broadcast(ParamString);
			}

			for (const TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITestbed1StructArray2InterfaceBPSubscriberInterface::Execute_OnSigStringSignal(Obj, ParamString);
				}
			}
		});
	}
}

void UTestbed1StructArray2InterfacePublisher::BroadcastPropBoolChanged(UPARAM(DisplayName = "PropBool") const FTestbed1StructBoolWithArray& InPropBool)
{
	OnPropBoolChanged.Broadcast(InPropBool);

	TArray<TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnPropBoolChangedBP.Broadcast(InPropBool);

		for (const TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArray2InterfaceBPSubscriberInterface::Execute_OnPropBoolChanged(Obj, InPropBool);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTestbed1StructArray2InterfacePublisher>(this), SubscribersCopy, InPropBool]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnPropBoolChangedBP.Broadcast(InPropBool);
			}

			for (const TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITestbed1StructArray2InterfaceBPSubscriberInterface::Execute_OnPropBoolChanged(Obj, InPropBool);
				}
			}
		});
	}
}

void UTestbed1StructArray2InterfacePublisher::BroadcastPropIntChanged(UPARAM(DisplayName = "PropInt") const FTestbed1StructIntWithArray& InPropInt)
{
	OnPropIntChanged.Broadcast(InPropInt);

	TArray<TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnPropIntChangedBP.Broadcast(InPropInt);

		for (const TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArray2InterfaceBPSubscriberInterface::Execute_OnPropIntChanged(Obj, InPropInt);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTestbed1StructArray2InterfacePublisher>(this), SubscribersCopy, InPropInt]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnPropIntChangedBP.Broadcast(InPropInt);
			}

			for (const TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITestbed1StructArray2InterfaceBPSubscriberInterface::Execute_OnPropIntChanged(Obj, InPropInt);
				}
			}
		});
	}
}

void UTestbed1StructArray2InterfacePublisher::BroadcastPropFloatChanged(UPARAM(DisplayName = "PropFloat") const FTestbed1StructFloatWithArray& InPropFloat)
{
	OnPropFloatChanged.Broadcast(InPropFloat);

	TArray<TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnPropFloatChangedBP.Broadcast(InPropFloat);

		for (const TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArray2InterfaceBPSubscriberInterface::Execute_OnPropFloatChanged(Obj, InPropFloat);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTestbed1StructArray2InterfacePublisher>(this), SubscribersCopy, InPropFloat]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnPropFloatChangedBP.Broadcast(InPropFloat);
			}

			for (const TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITestbed1StructArray2InterfaceBPSubscriberInterface::Execute_OnPropFloatChanged(Obj, InPropFloat);
				}
			}
		});
	}
}

void UTestbed1StructArray2InterfacePublisher::BroadcastPropStringChanged(UPARAM(DisplayName = "PropString") const FTestbed1StructStringWithArray& InPropString)
{
	OnPropStringChanged.Broadcast(InPropString);

	TArray<TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnPropStringChangedBP.Broadcast(InPropString);

		for (const TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArray2InterfaceBPSubscriberInterface::Execute_OnPropStringChanged(Obj, InPropString);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTestbed1StructArray2InterfacePublisher>(this), SubscribersCopy, InPropString]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnPropStringChangedBP.Broadcast(InPropString);
			}

			for (const TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITestbed1StructArray2InterfaceBPSubscriberInterface::Execute_OnPropStringChanged(Obj, InPropString);
				}
			}
		});
	}
}

void UTestbed1StructArray2InterfacePublisher::BroadcastPropEnumChanged(UPARAM(DisplayName = "PropEnum") const FTestbed1StructEnumWithArray& InPropEnum)
{
	OnPropEnumChanged.Broadcast(InPropEnum);

	TArray<TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnPropEnumChangedBP.Broadcast(InPropEnum);

		for (const TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed1StructArray2InterfaceBPSubscriberInterface::Execute_OnPropEnumChanged(Obj, InPropEnum);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTestbed1StructArray2InterfacePublisher>(this), SubscribersCopy, InPropEnum]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnPropEnumChangedBP.Broadcast(InPropEnum);
			}

			for (const TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITestbed1StructArray2InterfaceBPSubscriberInterface::Execute_OnPropEnumChanged(Obj, InPropEnum);
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

	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
	Subscribers.Add(Subscriber);
}

void UTestbed1StructArray2InterfacePublisher::Unsubscribe(const TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
}
