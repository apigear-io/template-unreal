
#include "TbEnum/Generated/api/TbEnumEnumInterfaceInterface.h"
#include "Async/Async.h"
#include "Async/TaskGraphInterfaces.h"

void UTbEnumEnumInterfacePublisher::BroadcastSig0Signal(ETbEnumEnum0 Param0)
{
	OnSig0Signal.Broadcast(Param0);

	TArray<TScriptInterface<ITbEnumEnumInterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnSig0SignalBP.Broadcast(Param0);

		for (const TScriptInterface<ITbEnumEnumInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbEnumEnumInterfaceBPSubscriberInterface::Execute_OnSig0Signal(Obj, Param0);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbEnumEnumInterfacePublisher>(this), SubscribersCopy, Param0]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSig0SignalBP.Broadcast(Param0);
			}

			for (const TScriptInterface<ITbEnumEnumInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbEnumEnumInterfaceBPSubscriberInterface::Execute_OnSig0Signal(Obj, Param0);
				}
			}
		});
	}
}

void UTbEnumEnumInterfacePublisher::BroadcastSig1Signal(ETbEnumEnum1 Param1)
{
	OnSig1Signal.Broadcast(Param1);

	TArray<TScriptInterface<ITbEnumEnumInterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnSig1SignalBP.Broadcast(Param1);

		for (const TScriptInterface<ITbEnumEnumInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbEnumEnumInterfaceBPSubscriberInterface::Execute_OnSig1Signal(Obj, Param1);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbEnumEnumInterfacePublisher>(this), SubscribersCopy, Param1]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSig1SignalBP.Broadcast(Param1);
			}

			for (const TScriptInterface<ITbEnumEnumInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbEnumEnumInterfaceBPSubscriberInterface::Execute_OnSig1Signal(Obj, Param1);
				}
			}
		});
	}
}

void UTbEnumEnumInterfacePublisher::BroadcastSig2Signal(ETbEnumEnum2 Param2)
{
	OnSig2Signal.Broadcast(Param2);

	TArray<TScriptInterface<ITbEnumEnumInterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnSig2SignalBP.Broadcast(Param2);

		for (const TScriptInterface<ITbEnumEnumInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbEnumEnumInterfaceBPSubscriberInterface::Execute_OnSig2Signal(Obj, Param2);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbEnumEnumInterfacePublisher>(this), SubscribersCopy, Param2]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSig2SignalBP.Broadcast(Param2);
			}

			for (const TScriptInterface<ITbEnumEnumInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbEnumEnumInterfaceBPSubscriberInterface::Execute_OnSig2Signal(Obj, Param2);
				}
			}
		});
	}
}

void UTbEnumEnumInterfacePublisher::BroadcastSig3Signal(ETbEnumEnum3 Param3)
{
	OnSig3Signal.Broadcast(Param3);

	TArray<TScriptInterface<ITbEnumEnumInterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnSig3SignalBP.Broadcast(Param3);

		for (const TScriptInterface<ITbEnumEnumInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbEnumEnumInterfaceBPSubscriberInterface::Execute_OnSig3Signal(Obj, Param3);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbEnumEnumInterfacePublisher>(this), SubscribersCopy, Param3]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSig3SignalBP.Broadcast(Param3);
			}

			for (const TScriptInterface<ITbEnumEnumInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbEnumEnumInterfaceBPSubscriberInterface::Execute_OnSig3Signal(Obj, Param3);
				}
			}
		});
	}
}

void UTbEnumEnumInterfacePublisher::BroadcastProp0Changed(UPARAM(DisplayName = "Prop0") ETbEnumEnum0 InProp0)
{
	OnProp0Changed.Broadcast(InProp0);

	TArray<TScriptInterface<ITbEnumEnumInterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnProp0ChangedBP.Broadcast(InProp0);

		for (const TScriptInterface<ITbEnumEnumInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbEnumEnumInterfaceBPSubscriberInterface::Execute_OnProp0Changed(Obj, InProp0);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbEnumEnumInterfacePublisher>(this), SubscribersCopy, InProp0]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnProp0ChangedBP.Broadcast(InProp0);
			}

			for (const TScriptInterface<ITbEnumEnumInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbEnumEnumInterfaceBPSubscriberInterface::Execute_OnProp0Changed(Obj, InProp0);
				}
			}
		});
	}
}

void UTbEnumEnumInterfacePublisher::BroadcastProp1Changed(UPARAM(DisplayName = "Prop1") ETbEnumEnum1 InProp1)
{
	OnProp1Changed.Broadcast(InProp1);

	TArray<TScriptInterface<ITbEnumEnumInterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnProp1ChangedBP.Broadcast(InProp1);

		for (const TScriptInterface<ITbEnumEnumInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbEnumEnumInterfaceBPSubscriberInterface::Execute_OnProp1Changed(Obj, InProp1);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbEnumEnumInterfacePublisher>(this), SubscribersCopy, InProp1]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnProp1ChangedBP.Broadcast(InProp1);
			}

			for (const TScriptInterface<ITbEnumEnumInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbEnumEnumInterfaceBPSubscriberInterface::Execute_OnProp1Changed(Obj, InProp1);
				}
			}
		});
	}
}

void UTbEnumEnumInterfacePublisher::BroadcastProp2Changed(UPARAM(DisplayName = "Prop2") ETbEnumEnum2 InProp2)
{
	OnProp2Changed.Broadcast(InProp2);

	TArray<TScriptInterface<ITbEnumEnumInterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnProp2ChangedBP.Broadcast(InProp2);

		for (const TScriptInterface<ITbEnumEnumInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbEnumEnumInterfaceBPSubscriberInterface::Execute_OnProp2Changed(Obj, InProp2);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbEnumEnumInterfacePublisher>(this), SubscribersCopy, InProp2]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnProp2ChangedBP.Broadcast(InProp2);
			}

			for (const TScriptInterface<ITbEnumEnumInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbEnumEnumInterfaceBPSubscriberInterface::Execute_OnProp2Changed(Obj, InProp2);
				}
			}
		});
	}
}

void UTbEnumEnumInterfacePublisher::BroadcastProp3Changed(UPARAM(DisplayName = "Prop3") ETbEnumEnum3 InProp3)
{
	OnProp3Changed.Broadcast(InProp3);

	TArray<TScriptInterface<ITbEnumEnumInterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnProp3ChangedBP.Broadcast(InProp3);

		for (const TScriptInterface<ITbEnumEnumInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbEnumEnumInterfaceBPSubscriberInterface::Execute_OnProp3Changed(Obj, InProp3);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbEnumEnumInterfacePublisher>(this), SubscribersCopy, InProp3]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnProp3ChangedBP.Broadcast(InProp3);
			}

			for (const TScriptInterface<ITbEnumEnumInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbEnumEnumInterfaceBPSubscriberInterface::Execute_OnProp3Changed(Obj, InProp3);
				}
			}
		});
	}
}

void UTbEnumEnumInterfacePublisher::Subscribe(const TScriptInterface<ITbEnumEnumInterfaceBPSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
	Subscribers.Add(Subscriber);
}

void UTbEnumEnumInterfacePublisher::Unsubscribe(const TScriptInterface<ITbEnumEnumInterfaceBPSubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
}
