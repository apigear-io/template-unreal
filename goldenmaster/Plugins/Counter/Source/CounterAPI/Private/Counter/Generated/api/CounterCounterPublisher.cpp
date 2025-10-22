
#include "Counter/Generated/api/CounterCounterInterface.h"
#include "Async/Async.h"
#include "Async/TaskGraphInterfaces.h"
#include "Runtime/Launch/Resources/Version.h"

void UCounterCounterPublisher::BroadcastValueChangedSignal(const FCustomTypesVector3D& Vector, const FVector& ExternVector, const TArray<FCustomTypesVector3D>& VectorArray, const TArray<FVector>& ExternVectorArray)
{
	TArray<TWeakInterfacePtr<ICounterCounterSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}

	TArray<TScriptInterface<ICounterCounterBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnValueChangedSignal.Broadcast(Vector, ExternVector, VectorArray, ExternVectorArray);
	for (const TWeakInterfacePtr<ICounterCounterSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ICounterCounterSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnValueChangedSignal(Vector, ExternVector, VectorArray, ExternVectorArray);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UCounterCounterPublisher>(this), BPSubscribersCopy, Vector, ExternVector, VectorArray, ExternVectorArray]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnValueChangedSignalBP.Broadcast(Vector, ExternVector, VectorArray, ExternVectorArray);
		}

		for (const TScriptInterface<ICounterCounterBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ICounterCounterBPSubscriberInterface::Execute_OnValueChangedSignal(Obj, Vector, ExternVector, VectorArray, ExternVectorArray);
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

void UCounterCounterPublisher::BroadcastVectorChanged(UPARAM(DisplayName = "Vector") const FCustomTypesVector3D& InVector)
{
	TArray<TWeakInterfacePtr<ICounterCounterSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ICounterCounterBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnVectorChanged.Broadcast(InVector);
	for (const TWeakInterfacePtr<ICounterCounterSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ICounterCounterSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnVectorChanged(InVector);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UCounterCounterPublisher>(this), BPSubscribersCopy, InVector]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnVectorChangedBP.Broadcast(InVector);
		}

		for (const TScriptInterface<ICounterCounterBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ICounterCounterBPSubscriberInterface::Execute_OnVectorChanged(Obj, InVector);
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

void UCounterCounterPublisher::BroadcastExternVectorChanged(UPARAM(DisplayName = "ExternVector") const FVector& InExternVector)
{
	TArray<TWeakInterfacePtr<ICounterCounterSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ICounterCounterBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnExternVectorChanged.Broadcast(InExternVector);
	for (const TWeakInterfacePtr<ICounterCounterSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ICounterCounterSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnExternVectorChanged(InExternVector);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UCounterCounterPublisher>(this), BPSubscribersCopy, InExternVector]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnExternVectorChangedBP.Broadcast(InExternVector);
		}

		for (const TScriptInterface<ICounterCounterBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ICounterCounterBPSubscriberInterface::Execute_OnExternVectorChanged(Obj, InExternVector);
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

void UCounterCounterPublisher::BroadcastVectorArrayChanged(UPARAM(DisplayName = "VectorArray") const TArray<FCustomTypesVector3D>& InVectorArray)
{
	TArray<TWeakInterfacePtr<ICounterCounterSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ICounterCounterBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnVectorArrayChanged.Broadcast(InVectorArray);
	for (const TWeakInterfacePtr<ICounterCounterSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ICounterCounterSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnVectorArrayChanged(InVectorArray);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UCounterCounterPublisher>(this), BPSubscribersCopy, InVectorArray]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnVectorArrayChangedBP.Broadcast(InVectorArray);
		}

		for (const TScriptInterface<ICounterCounterBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ICounterCounterBPSubscriberInterface::Execute_OnVectorArrayChanged(Obj, InVectorArray);
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

void UCounterCounterPublisher::BroadcastExternVectorArrayChanged(UPARAM(DisplayName = "ExternVectorArray") const TArray<FVector>& InExternVectorArray)
{
	TArray<TWeakInterfacePtr<ICounterCounterSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ICounterCounterBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnExternVectorArrayChanged.Broadcast(InExternVectorArray);
	for (const TWeakInterfacePtr<ICounterCounterSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ICounterCounterSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnExternVectorArrayChanged(InExternVectorArray);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UCounterCounterPublisher>(this), BPSubscribersCopy, InExternVectorArray]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnExternVectorArrayChangedBP.Broadcast(InExternVectorArray);
		}

		for (const TScriptInterface<ICounterCounterBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ICounterCounterBPSubscriberInterface::Execute_OnExternVectorArrayChanged(Obj, InExternVectorArray);
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

void UCounterCounterPublisher::Subscribe(const TScriptInterface<ICounterCounterBPSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	FWriteScopeLock WriteLock(BPSubscribersLock);
	BPSubscribers.Remove(Subscriber);
	BPSubscribers.Add(Subscriber);
}

void UCounterCounterPublisher::Subscribe(const TWeakInterfacePtr<ICounterCounterSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
	Subscribers.Add(Subscriber);
}

void UCounterCounterPublisher::Unsubscribe(const TScriptInterface<ICounterCounterBPSubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(BPSubscribersLock);
	BPSubscribers.Remove(Subscriber);
}

void UCounterCounterPublisher::Unsubscribe(const TWeakInterfacePtr<ICounterCounterSubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
}

void UCounterCounterPublisher::CleanUpSubscribers()
{
#if (ENGINE_MAJOR_VERSION >= 5)
	EAllowShrinking AllowShrinking = EAllowShrinking::No;
#else
	bool AllowShrinking = false;
#endif

	{
		FWriteScopeLock WriteLock(SubscribersLock);
		Subscribers.RemoveAllSwap([](const TWeakInterfacePtr<ICounterCounterSubscriberInterface>& Subscriber)
			{
			return !Subscriber.IsValid();
		},
			AllowShrinking);
	}
	{
		FWriteScopeLock WriteLock(BPSubscribersLock);
		BPSubscribers.RemoveAllSwap([](const TScriptInterface<ICounterCounterBPSubscriberInterface>& Subscriber)
			{
			UObject* Obj = Subscriber.GetObject();
			return !((Obj != nullptr) && IsValid(Obj));
		},
			AllowShrinking);
	}
}
