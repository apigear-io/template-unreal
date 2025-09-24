
#include "TbSame2/Generated/api/TbSame2SameEnum1InterfaceInterface.h"
#include "Async/Async.h"
#include "Async/TaskGraphInterfaces.h"

void UTbSame2SameEnum1InterfacePublisher::BroadcastSig1Signal(ETbSame2Enum1 Param1)
{
	OnSig1Signal.Broadcast(Param1);
	TArray<TWeakInterfacePtr<ITbSame2SameEnum1InterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbSame2SameEnum1InterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSame2SameEnum1InterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSig1Signal(Param1);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITbSame2SameEnum1InterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnSig1SignalBP.Broadcast(Param1);

		for (const TScriptInterface<ITbSame2SameEnum1InterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSame2SameEnum1InterfaceBPSubscriberInterface::Execute_OnSig1Signal(Obj, Param1);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSame2SameEnum1InterfacePublisher>(this), BPSubscribersCopy, Param1]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSig1SignalBP.Broadcast(Param1);
			}

			for (const TScriptInterface<ITbSame2SameEnum1InterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSame2SameEnum1InterfaceBPSubscriberInterface::Execute_OnSig1Signal(Obj, Param1);
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

void UTbSame2SameEnum1InterfacePublisher::BroadcastProp1Changed(UPARAM(DisplayName = "Prop1") ETbSame2Enum1 InProp1)
{
	OnProp1Changed.Broadcast(InProp1);
	TArray<TWeakInterfacePtr<ITbSame2SameEnum1InterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbSame2SameEnum1InterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSame2SameEnum1InterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnProp1Changed(InProp1);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITbSame2SameEnum1InterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnProp1ChangedBP.Broadcast(InProp1);

		for (const TScriptInterface<ITbSame2SameEnum1InterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSame2SameEnum1InterfaceBPSubscriberInterface::Execute_OnProp1Changed(Obj, InProp1);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSame2SameEnum1InterfacePublisher>(this), BPSubscribersCopy, InProp1]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnProp1ChangedBP.Broadcast(InProp1);
			}

			for (const TScriptInterface<ITbSame2SameEnum1InterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSame2SameEnum1InterfaceBPSubscriberInterface::Execute_OnProp1Changed(Obj, InProp1);
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

void UTbSame2SameEnum1InterfacePublisher::Subscribe(const TScriptInterface<ITbSame2SameEnum1InterfaceBPSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	FWriteScopeLock WriteLock(BPSubscribersLock);
	BPSubscribers.Remove(Subscriber);
	BPSubscribers.Add(Subscriber);
}

void UTbSame2SameEnum1InterfacePublisher::Subscribe(const TWeakInterfacePtr<ITbSame2SameEnum1InterfaceSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
	Subscribers.Add(Subscriber);
}

void UTbSame2SameEnum1InterfacePublisher::Unsubscribe(const TScriptInterface<ITbSame2SameEnum1InterfaceBPSubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(BPSubscribersLock);
	BPSubscribers.Remove(Subscriber);
}

void UTbSame2SameEnum1InterfacePublisher::Unsubscribe(const TWeakInterfacePtr<ITbSame2SameEnum1InterfaceSubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
}
