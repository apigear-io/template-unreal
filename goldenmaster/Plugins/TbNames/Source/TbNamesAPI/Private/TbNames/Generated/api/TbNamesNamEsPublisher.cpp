
#include "TbNames/Generated/api/TbNamesNamEsInterface.h"
#include "Async/Async.h"
#include "Async/TaskGraphInterfaces.h"

void UTbNamesNamEsPublisher::BroadcastSomeSignalSignal(bool bSomeParam)
{
	OnSomeSignalSignal.Broadcast(bSomeParam);

	TArray<TScriptInterface<ITbNamesNamEsBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnSomeSignalSignalBP.Broadcast(bSomeParam);

		for (const TScriptInterface<ITbNamesNamEsBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbNamesNamEsBPSubscriberInterface::Execute_OnSomeSignalSignal(Obj, bSomeParam);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbNamesNamEsPublisher>(this), SubscribersCopy, bSomeParam]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSomeSignalSignalBP.Broadcast(bSomeParam);
			}

			for (const TScriptInterface<ITbNamesNamEsBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbNamesNamEsBPSubscriberInterface::Execute_OnSomeSignalSignal(Obj, bSomeParam);
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

void UTbNamesNamEsPublisher::BroadcastSomeSignal2Signal(bool bSomeParam)
{
	OnSomeSignal2Signal.Broadcast(bSomeParam);

	TArray<TScriptInterface<ITbNamesNamEsBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnSomeSignal2SignalBP.Broadcast(bSomeParam);

		for (const TScriptInterface<ITbNamesNamEsBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbNamesNamEsBPSubscriberInterface::Execute_OnSomeSignal2Signal(Obj, bSomeParam);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbNamesNamEsPublisher>(this), SubscribersCopy, bSomeParam]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSomeSignal2SignalBP.Broadcast(bSomeParam);
			}

			for (const TScriptInterface<ITbNamesNamEsBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbNamesNamEsBPSubscriberInterface::Execute_OnSomeSignal2Signal(Obj, bSomeParam);
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

void UTbNamesNamEsPublisher::BroadcastSwitchChanged(UPARAM(DisplayName = "bSwitch") bool bInSwitch)
{
	OnSwitchChanged.Broadcast(bInSwitch);

	TArray<TScriptInterface<ITbNamesNamEsBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnSwitchChangedBP.Broadcast(bInSwitch);

		for (const TScriptInterface<ITbNamesNamEsBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbNamesNamEsBPSubscriberInterface::Execute_OnSwitchChanged(Obj, bInSwitch);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbNamesNamEsPublisher>(this), SubscribersCopy, bInSwitch]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSwitchChangedBP.Broadcast(bInSwitch);
			}

			for (const TScriptInterface<ITbNamesNamEsBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbNamesNamEsBPSubscriberInterface::Execute_OnSwitchChanged(Obj, bInSwitch);
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

void UTbNamesNamEsPublisher::BroadcastSomePropertyChanged(UPARAM(DisplayName = "SomeProperty") int32 InSomeProperty)
{
	OnSomePropertyChanged.Broadcast(InSomeProperty);

	TArray<TScriptInterface<ITbNamesNamEsBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnSomePropertyChangedBP.Broadcast(InSomeProperty);

		for (const TScriptInterface<ITbNamesNamEsBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbNamesNamEsBPSubscriberInterface::Execute_OnSomePropertyChanged(Obj, InSomeProperty);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbNamesNamEsPublisher>(this), SubscribersCopy, InSomeProperty]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSomePropertyChangedBP.Broadcast(InSomeProperty);
			}

			for (const TScriptInterface<ITbNamesNamEsBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbNamesNamEsBPSubscriberInterface::Execute_OnSomePropertyChanged(Obj, InSomeProperty);
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

void UTbNamesNamEsPublisher::BroadcastSomePoperty2Changed(UPARAM(DisplayName = "SomePoperty2") int32 InSomePoperty2)
{
	OnSomePoperty2Changed.Broadcast(InSomePoperty2);

	TArray<TScriptInterface<ITbNamesNamEsBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnSomePoperty2ChangedBP.Broadcast(InSomePoperty2);

		for (const TScriptInterface<ITbNamesNamEsBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbNamesNamEsBPSubscriberInterface::Execute_OnSomePoperty2Changed(Obj, InSomePoperty2);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbNamesNamEsPublisher>(this), SubscribersCopy, InSomePoperty2]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSomePoperty2ChangedBP.Broadcast(InSomePoperty2);
			}

			for (const TScriptInterface<ITbNamesNamEsBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbNamesNamEsBPSubscriberInterface::Execute_OnSomePoperty2Changed(Obj, InSomePoperty2);
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

void UTbNamesNamEsPublisher::BroadcastEnumPropertyChanged(UPARAM(DisplayName = "EnumProperty") ETbNamesEnum_With_Under_scores InEnumProperty)
{
	OnEnumPropertyChanged.Broadcast(InEnumProperty);

	TArray<TScriptInterface<ITbNamesNamEsBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnEnumPropertyChangedBP.Broadcast(InEnumProperty);

		for (const TScriptInterface<ITbNamesNamEsBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbNamesNamEsBPSubscriberInterface::Execute_OnEnumPropertyChanged(Obj, InEnumProperty);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbNamesNamEsPublisher>(this), SubscribersCopy, InEnumProperty]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnEnumPropertyChangedBP.Broadcast(InEnumProperty);
			}

			for (const TScriptInterface<ITbNamesNamEsBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbNamesNamEsBPSubscriberInterface::Execute_OnEnumPropertyChanged(Obj, InEnumProperty);
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

void UTbNamesNamEsPublisher::Subscribe(const TScriptInterface<ITbNamesNamEsBPSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
	Subscribers.Add(Subscriber);
}

void UTbNamesNamEsPublisher::Unsubscribe(const TScriptInterface<ITbNamesNamEsBPSubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
}
