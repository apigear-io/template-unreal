
#include "TbSame2/Generated/api/TbSame2SameEnum2InterfaceInterface.h"
#include "Async/Async.h"
#include "Async/TaskGraphInterfaces.h"

void UTbSame2SameEnum2InterfacePublisher::BroadcastSig1Signal(ETbSame2Enum1 Param1)
{
	OnSig1Signal.Broadcast(Param1);
	TArray<TWeakInterfacePtr<ITbSame2SameEnum2InterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbSame2SameEnum2InterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSame2SameEnum2InterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSig1Signal(Param1);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITbSame2SameEnum2InterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnSig1SignalBP.Broadcast(Param1);

		for (const TScriptInterface<ITbSame2SameEnum2InterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSame2SameEnum2InterfaceBPSubscriberInterface::Execute_OnSig1Signal(Obj, Param1);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSame2SameEnum2InterfacePublisher>(this), BPSubscribersCopy, Param1]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSig1SignalBP.Broadcast(Param1);
			}

			for (const TScriptInterface<ITbSame2SameEnum2InterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSame2SameEnum2InterfaceBPSubscriberInterface::Execute_OnSig1Signal(Obj, Param1);
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

void UTbSame2SameEnum2InterfacePublisher::BroadcastSig2Signal(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2)
{
	OnSig2Signal.Broadcast(Param1, Param2);
	TArray<TWeakInterfacePtr<ITbSame2SameEnum2InterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbSame2SameEnum2InterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSame2SameEnum2InterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSig2Signal(Param1, Param2);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITbSame2SameEnum2InterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnSig2SignalBP.Broadcast(Param1, Param2);

		for (const TScriptInterface<ITbSame2SameEnum2InterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSame2SameEnum2InterfaceBPSubscriberInterface::Execute_OnSig2Signal(Obj, Param1, Param2);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSame2SameEnum2InterfacePublisher>(this), BPSubscribersCopy, Param1, Param2]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSig2SignalBP.Broadcast(Param1, Param2);
			}

			for (const TScriptInterface<ITbSame2SameEnum2InterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSame2SameEnum2InterfaceBPSubscriberInterface::Execute_OnSig2Signal(Obj, Param1, Param2);
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

void UTbSame2SameEnum2InterfacePublisher::BroadcastProp1Changed(UPARAM(DisplayName = "Prop1") ETbSame2Enum1 InProp1)
{
	OnProp1Changed.Broadcast(InProp1);
	TArray<TWeakInterfacePtr<ITbSame2SameEnum2InterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbSame2SameEnum2InterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSame2SameEnum2InterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnProp1Changed(InProp1);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITbSame2SameEnum2InterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnProp1ChangedBP.Broadcast(InProp1);

		for (const TScriptInterface<ITbSame2SameEnum2InterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSame2SameEnum2InterfaceBPSubscriberInterface::Execute_OnProp1Changed(Obj, InProp1);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSame2SameEnum2InterfacePublisher>(this), BPSubscribersCopy, InProp1]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnProp1ChangedBP.Broadcast(InProp1);
			}

			for (const TScriptInterface<ITbSame2SameEnum2InterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSame2SameEnum2InterfaceBPSubscriberInterface::Execute_OnProp1Changed(Obj, InProp1);
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

void UTbSame2SameEnum2InterfacePublisher::BroadcastProp2Changed(UPARAM(DisplayName = "Prop2") ETbSame2Enum2 InProp2)
{
	OnProp2Changed.Broadcast(InProp2);
	TArray<TWeakInterfacePtr<ITbSame2SameEnum2InterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbSame2SameEnum2InterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSame2SameEnum2InterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnProp2Changed(InProp2);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITbSame2SameEnum2InterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnProp2ChangedBP.Broadcast(InProp2);

		for (const TScriptInterface<ITbSame2SameEnum2InterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSame2SameEnum2InterfaceBPSubscriberInterface::Execute_OnProp2Changed(Obj, InProp2);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSame2SameEnum2InterfacePublisher>(this), BPSubscribersCopy, InProp2]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnProp2ChangedBP.Broadcast(InProp2);
			}

			for (const TScriptInterface<ITbSame2SameEnum2InterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSame2SameEnum2InterfaceBPSubscriberInterface::Execute_OnProp2Changed(Obj, InProp2);
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

void UTbSame2SameEnum2InterfacePublisher::Subscribe(const TScriptInterface<ITbSame2SameEnum2InterfaceBPSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	FWriteScopeLock WriteLock(BPSubscribersLock);
	BPSubscribers.Remove(Subscriber);
	BPSubscribers.Add(Subscriber);
}

void UTbSame2SameEnum2InterfacePublisher::Subscribe(const TWeakInterfacePtr<ITbSame2SameEnum2InterfaceSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
	Subscribers.Add(Subscriber);
}

void UTbSame2SameEnum2InterfacePublisher::Unsubscribe(const TScriptInterface<ITbSame2SameEnum2InterfaceBPSubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(BPSubscribersLock);
	BPSubscribers.Remove(Subscriber);
}

void UTbSame2SameEnum2InterfacePublisher::Unsubscribe(const TWeakInterfacePtr<ITbSame2SameEnum2InterfaceSubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
}
