
#include "Testbed2/Generated/api/Testbed2NestedStruct2InterfaceInterface.h"
#include "Async/Async.h"
#include "Async/TaskGraphInterfaces.h"

void UTestbed2NestedStruct2InterfacePublisher::BroadcastSig1Signal(const FTestbed2NestedStruct1& Param1)
{
	OnSig1Signal.Broadcast(Param1);

	TArray<TScriptInterface<ITestbed2NestedStruct2InterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnSig1SignalBP.Broadcast(Param1);

		for (const TScriptInterface<ITestbed2NestedStruct2InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed2NestedStruct2InterfaceBPSubscriberInterface::Execute_OnSig1Signal(Obj, Param1);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTestbed2NestedStruct2InterfacePublisher>(this), SubscribersCopy, Param1]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSig1SignalBP.Broadcast(Param1);
			}

			for (const TScriptInterface<ITestbed2NestedStruct2InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITestbed2NestedStruct2InterfaceBPSubscriberInterface::Execute_OnSig1Signal(Obj, Param1);
				}
			}
		});
	}
}

void UTestbed2NestedStruct2InterfacePublisher::BroadcastSig2Signal(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	OnSig2Signal.Broadcast(Param1, Param2);

	TArray<TScriptInterface<ITestbed2NestedStruct2InterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnSig2SignalBP.Broadcast(Param1, Param2);

		for (const TScriptInterface<ITestbed2NestedStruct2InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed2NestedStruct2InterfaceBPSubscriberInterface::Execute_OnSig2Signal(Obj, Param1, Param2);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTestbed2NestedStruct2InterfacePublisher>(this), SubscribersCopy, Param1, Param2]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSig2SignalBP.Broadcast(Param1, Param2);
			}

			for (const TScriptInterface<ITestbed2NestedStruct2InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITestbed2NestedStruct2InterfaceBPSubscriberInterface::Execute_OnSig2Signal(Obj, Param1, Param2);
				}
			}
		});
	}
}

void UTestbed2NestedStruct2InterfacePublisher::BroadcastProp1Changed(UPARAM(DisplayName = "Prop1") const FTestbed2NestedStruct1& InProp1)
{
	OnProp1Changed.Broadcast(InProp1);

	TArray<TScriptInterface<ITestbed2NestedStruct2InterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnProp1ChangedBP.Broadcast(InProp1);

		for (const TScriptInterface<ITestbed2NestedStruct2InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed2NestedStruct2InterfaceBPSubscriberInterface::Execute_OnProp1Changed(Obj, InProp1);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTestbed2NestedStruct2InterfacePublisher>(this), SubscribersCopy, InProp1]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnProp1ChangedBP.Broadcast(InProp1);
			}

			for (const TScriptInterface<ITestbed2NestedStruct2InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITestbed2NestedStruct2InterfaceBPSubscriberInterface::Execute_OnProp1Changed(Obj, InProp1);
				}
			}
		});
	}
}

void UTestbed2NestedStruct2InterfacePublisher::BroadcastProp2Changed(UPARAM(DisplayName = "Prop2") const FTestbed2NestedStruct2& InProp2)
{
	OnProp2Changed.Broadcast(InProp2);

	TArray<TScriptInterface<ITestbed2NestedStruct2InterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnProp2ChangedBP.Broadcast(InProp2);

		for (const TScriptInterface<ITestbed2NestedStruct2InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed2NestedStruct2InterfaceBPSubscriberInterface::Execute_OnProp2Changed(Obj, InProp2);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTestbed2NestedStruct2InterfacePublisher>(this), SubscribersCopy, InProp2]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnProp2ChangedBP.Broadcast(InProp2);
			}

			for (const TScriptInterface<ITestbed2NestedStruct2InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITestbed2NestedStruct2InterfaceBPSubscriberInterface::Execute_OnProp2Changed(Obj, InProp2);
				}
			}
		});
	}
}

void UTestbed2NestedStruct2InterfacePublisher::Subscribe(const TScriptInterface<ITestbed2NestedStruct2InterfaceBPSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
	Subscribers.Add(Subscriber);
}

void UTestbed2NestedStruct2InterfacePublisher::Unsubscribe(const TScriptInterface<ITestbed2NestedStruct2InterfaceBPSubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
}
