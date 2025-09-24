
#include "Testbed2/Generated/api/Testbed2NestedStruct1InterfaceInterface.h"
#include "Async/Async.h"
#include "Async/TaskGraphInterfaces.h"

void UTestbed2NestedStruct1InterfacePublisher::BroadcastSig1Signal(const FTestbed2NestedStruct1& Param1)
{
	OnSig1Signal.Broadcast(Param1);
	TArray<TWeakInterfacePtr<ITestbed2NestedStruct1InterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITestbed2NestedStruct1InterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed2NestedStruct1InterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSig1Signal(Param1);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITestbed2NestedStruct1InterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnSig1SignalBP.Broadcast(Param1);

		for (const TScriptInterface<ITestbed2NestedStruct1InterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed2NestedStruct1InterfaceBPSubscriberInterface::Execute_OnSig1Signal(Obj, Param1);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTestbed2NestedStruct1InterfacePublisher>(this), BPSubscribersCopy, Param1]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSig1SignalBP.Broadcast(Param1);
			}

			for (const TScriptInterface<ITestbed2NestedStruct1InterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITestbed2NestedStruct1InterfaceBPSubscriberInterface::Execute_OnSig1Signal(Obj, Param1);
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

void UTestbed2NestedStruct1InterfacePublisher::BroadcastProp1Changed(UPARAM(DisplayName = "Prop1") const FTestbed2NestedStruct1& InProp1)
{
	OnProp1Changed.Broadcast(InProp1);
	TArray<TWeakInterfacePtr<ITestbed2NestedStruct1InterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITestbed2NestedStruct1InterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITestbed2NestedStruct1InterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnProp1Changed(InProp1);
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<ITestbed2NestedStruct1InterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnProp1ChangedBP.Broadcast(InProp1);

		for (const TScriptInterface<ITestbed2NestedStruct1InterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed2NestedStruct1InterfaceBPSubscriberInterface::Execute_OnProp1Changed(Obj, InProp1);
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTestbed2NestedStruct1InterfacePublisher>(this), BPSubscribersCopy, InProp1]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnProp1ChangedBP.Broadcast(InProp1);
			}

			for (const TScriptInterface<ITestbed2NestedStruct1InterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITestbed2NestedStruct1InterfaceBPSubscriberInterface::Execute_OnProp1Changed(Obj, InProp1);
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

void UTestbed2NestedStruct1InterfacePublisher::Subscribe(const TScriptInterface<ITestbed2NestedStruct1InterfaceBPSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	FWriteScopeLock WriteLock(BPSubscribersLock);
	BPSubscribers.Remove(Subscriber);
	BPSubscribers.Add(Subscriber);
}

void UTestbed2NestedStruct1InterfacePublisher::Subscribe(const TWeakInterfacePtr<ITestbed2NestedStruct1InterfaceSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
	Subscribers.Add(Subscriber);
}

void UTestbed2NestedStruct1InterfacePublisher::Unsubscribe(const TScriptInterface<ITestbed2NestedStruct1InterfaceBPSubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(BPSubscribersLock);
	BPSubscribers.Remove(Subscriber);
}

void UTestbed2NestedStruct1InterfacePublisher::Unsubscribe(const TWeakInterfacePtr<ITestbed2NestedStruct1InterfaceSubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
}
