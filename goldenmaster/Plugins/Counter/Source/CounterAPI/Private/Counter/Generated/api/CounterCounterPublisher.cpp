
#include "Counter/Generated/api/CounterCounterInterface.h"
#include "Async/Async.h"
#include "Async/TaskGraphInterfaces.h"

void UCounterCounterPublisher::BroadcastValueChangedSignal(const FCustomTypesVector3D& Vector, const FVector& ExternVector, const TArray<FCustomTypesVector3D>& VectorArray, const TArray<FVector>& ExternVectorArray)
{
	OnValueChangedSignal.Broadcast(Vector, ExternVector, VectorArray, ExternVectorArray);
	TArray<TWeakInterfacePtr<ICounterCounterSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ICounterCounterSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ICounterCounterSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnValueChangedSignal(Vector, ExternVector, VectorArray, ExternVectorArray);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ICounterCounterBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnValueChangedSignalBP.Broadcast(Vector, ExternVector, VectorArray, ExternVectorArray);

		for (const TScriptInterface<ICounterCounterBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ICounterCounterBPSubscriberInterface::Execute_OnValueChangedSignal(Obj, Vector, ExternVector, VectorArray, ExternVectorArray);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UCounterCounterPublisher>(this), BPSubscribersCopy, Vector, ExternVector, VectorArray, ExternVectorArray]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnValueChangedSignalBP.Broadcast(Vector, ExternVector, VectorArray, ExternVectorArray);
			}

			for (const TScriptInterface<ICounterCounterBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ICounterCounterBPSubscriberInterface::Execute_OnValueChangedSignal(Obj, Vector, ExternVector, VectorArray, ExternVectorArray);
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

void UCounterCounterPublisher::BroadcastVectorChanged(UPARAM(DisplayName = "Vector") const FCustomTypesVector3D& InVector)
{
	OnVectorChanged.Broadcast(InVector);
	TArray<TWeakInterfacePtr<ICounterCounterSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ICounterCounterSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ICounterCounterSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnVectorChanged(InVector);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ICounterCounterBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnVectorChangedBP.Broadcast(InVector);

		for (const TScriptInterface<ICounterCounterBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ICounterCounterBPSubscriberInterface::Execute_OnVectorChanged(Obj, InVector);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UCounterCounterPublisher>(this), BPSubscribersCopy, InVector]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnVectorChangedBP.Broadcast(InVector);
			}

			for (const TScriptInterface<ICounterCounterBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ICounterCounterBPSubscriberInterface::Execute_OnVectorChanged(Obj, InVector);
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

void UCounterCounterPublisher::BroadcastExternVectorChanged(UPARAM(DisplayName = "ExternVector") const FVector& InExternVector)
{
	OnExternVectorChanged.Broadcast(InExternVector);
	TArray<TWeakInterfacePtr<ICounterCounterSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ICounterCounterSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ICounterCounterSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnExternVectorChanged(InExternVector);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ICounterCounterBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnExternVectorChangedBP.Broadcast(InExternVector);

		for (const TScriptInterface<ICounterCounterBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ICounterCounterBPSubscriberInterface::Execute_OnExternVectorChanged(Obj, InExternVector);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UCounterCounterPublisher>(this), BPSubscribersCopy, InExternVector]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnExternVectorChangedBP.Broadcast(InExternVector);
			}

			for (const TScriptInterface<ICounterCounterBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ICounterCounterBPSubscriberInterface::Execute_OnExternVectorChanged(Obj, InExternVector);
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

void UCounterCounterPublisher::BroadcastVectorArrayChanged(UPARAM(DisplayName = "VectorArray") const TArray<FCustomTypesVector3D>& InVectorArray)
{
	OnVectorArrayChanged.Broadcast(InVectorArray);
	TArray<TWeakInterfacePtr<ICounterCounterSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ICounterCounterSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ICounterCounterSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnVectorArrayChanged(InVectorArray);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ICounterCounterBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnVectorArrayChangedBP.Broadcast(InVectorArray);

		for (const TScriptInterface<ICounterCounterBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ICounterCounterBPSubscriberInterface::Execute_OnVectorArrayChanged(Obj, InVectorArray);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UCounterCounterPublisher>(this), BPSubscribersCopy, InVectorArray]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnVectorArrayChangedBP.Broadcast(InVectorArray);
			}

			for (const TScriptInterface<ICounterCounterBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ICounterCounterBPSubscriberInterface::Execute_OnVectorArrayChanged(Obj, InVectorArray);
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

void UCounterCounterPublisher::BroadcastExternVectorArrayChanged(UPARAM(DisplayName = "ExternVectorArray") const TArray<FVector>& InExternVectorArray)
{
	OnExternVectorArrayChanged.Broadcast(InExternVectorArray);
	TArray<TWeakInterfacePtr<ICounterCounterSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ICounterCounterSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ICounterCounterSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnExternVectorArrayChanged(InExternVectorArray);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ICounterCounterBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnExternVectorArrayChangedBP.Broadcast(InExternVectorArray);

		for (const TScriptInterface<ICounterCounterBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ICounterCounterBPSubscriberInterface::Execute_OnExternVectorArrayChanged(Obj, InExternVectorArray);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UCounterCounterPublisher>(this), BPSubscribersCopy, InExternVectorArray]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnExternVectorArrayChangedBP.Broadcast(InExternVectorArray);
			}

			for (const TScriptInterface<ICounterCounterBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ICounterCounterBPSubscriberInterface::Execute_OnExternVectorArrayChanged(Obj, InExternVectorArray);
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
