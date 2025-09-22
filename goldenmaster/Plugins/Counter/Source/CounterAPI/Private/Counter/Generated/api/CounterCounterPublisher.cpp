
#include "Counter/Generated/api/CounterCounterInterface.h"
#include "Async/Async.h"
#include "Async/TaskGraphInterfaces.h"

void UCounterCounterPublisher::BroadcastValueChangedSignal(const FCustomTypesVector3D& Vector, const FVector& ExternVector, const TArray<FCustomTypesVector3D>& VectorArray, const TArray<FVector>& ExternVectorArray)
{
	OnValueChangedSignal.Broadcast(Vector, ExternVector, VectorArray, ExternVectorArray);

	TArray<TScriptInterface<ICounterCounterBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnValueChangedSignalBP.Broadcast(Vector, ExternVector, VectorArray, ExternVectorArray);

		for (const TScriptInterface<ICounterCounterBPSubscriberInterface>& Subscriber : SubscribersCopy)
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
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UCounterCounterPublisher>(this), SubscribersCopy, Vector, ExternVector, VectorArray, ExternVectorArray]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnValueChangedSignalBP.Broadcast(Vector, ExternVector, VectorArray, ExternVectorArray);
			}

			for (const TScriptInterface<ICounterCounterBPSubscriberInterface>& Subscriber : SubscribersCopy)
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

	TArray<TScriptInterface<ICounterCounterBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnVectorChangedBP.Broadcast(InVector);

		for (const TScriptInterface<ICounterCounterBPSubscriberInterface>& Subscriber : SubscribersCopy)
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
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UCounterCounterPublisher>(this), SubscribersCopy, InVector]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnVectorChangedBP.Broadcast(InVector);
			}

			for (const TScriptInterface<ICounterCounterBPSubscriberInterface>& Subscriber : SubscribersCopy)
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

	TArray<TScriptInterface<ICounterCounterBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnExternVectorChangedBP.Broadcast(InExternVector);

		for (const TScriptInterface<ICounterCounterBPSubscriberInterface>& Subscriber : SubscribersCopy)
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
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UCounterCounterPublisher>(this), SubscribersCopy, InExternVector]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnExternVectorChangedBP.Broadcast(InExternVector);
			}

			for (const TScriptInterface<ICounterCounterBPSubscriberInterface>& Subscriber : SubscribersCopy)
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

	TArray<TScriptInterface<ICounterCounterBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnVectorArrayChangedBP.Broadcast(InVectorArray);

		for (const TScriptInterface<ICounterCounterBPSubscriberInterface>& Subscriber : SubscribersCopy)
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
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UCounterCounterPublisher>(this), SubscribersCopy, InVectorArray]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnVectorArrayChangedBP.Broadcast(InVectorArray);
			}

			for (const TScriptInterface<ICounterCounterBPSubscriberInterface>& Subscriber : SubscribersCopy)
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

	TArray<TScriptInterface<ICounterCounterBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnExternVectorArrayChangedBP.Broadcast(InExternVectorArray);

		for (const TScriptInterface<ICounterCounterBPSubscriberInterface>& Subscriber : SubscribersCopy)
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
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UCounterCounterPublisher>(this), SubscribersCopy, InExternVectorArray]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnExternVectorArrayChangedBP.Broadcast(InExternVectorArray);
			}

			for (const TScriptInterface<ICounterCounterBPSubscriberInterface>& Subscriber : SubscribersCopy)
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

	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
	Subscribers.Add(Subscriber);
}

void UCounterCounterPublisher::Unsubscribe(const TScriptInterface<ICounterCounterBPSubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
}
