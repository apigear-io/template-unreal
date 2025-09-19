
#include "Testbed2/Generated/api/Testbed2NestedStruct3InterfaceInterface.h"
#include "Async/Async.h"
#include "Async/TaskGraphInterfaces.h"

void UTestbed2NestedStruct3InterfacePublisher::BroadcastSig1Signal(const FTestbed2NestedStruct1& Param1)
{
	OnSig1Signal.Broadcast(Param1);

	TArray<TScriptInterface<ITestbed2NestedStruct3InterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	if (IsInGameThread())
	{
		OnSig1SignalBP.Broadcast(Param1);

		for (const TScriptInterface<ITestbed2NestedStruct3InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed2NestedStruct3InterfaceBPSubscriberInterface::Execute_OnSig1Signal(Obj, Param1);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTestbed2NestedStruct3InterfacePublisher>(this), SubscribersCopy, Param1]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSig1SignalBP.Broadcast(Param1);
			}

			for (const TScriptInterface<ITestbed2NestedStruct3InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITestbed2NestedStruct3InterfaceBPSubscriberInterface::Execute_OnSig1Signal(Obj, Param1);
				}
			}
		});
	}
}

void UTestbed2NestedStruct3InterfacePublisher::BroadcastSig2Signal(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	OnSig2Signal.Broadcast(Param1, Param2);

	TArray<TScriptInterface<ITestbed2NestedStruct3InterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	if (IsInGameThread())
	{
		OnSig2SignalBP.Broadcast(Param1, Param2);

		for (const TScriptInterface<ITestbed2NestedStruct3InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed2NestedStruct3InterfaceBPSubscriberInterface::Execute_OnSig2Signal(Obj, Param1, Param2);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTestbed2NestedStruct3InterfacePublisher>(this), SubscribersCopy, Param1, Param2]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSig2SignalBP.Broadcast(Param1, Param2);
			}

			for (const TScriptInterface<ITestbed2NestedStruct3InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITestbed2NestedStruct3InterfaceBPSubscriberInterface::Execute_OnSig2Signal(Obj, Param1, Param2);
				}
			}
		});
	}
}

void UTestbed2NestedStruct3InterfacePublisher::BroadcastSig3Signal(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3)
{
	OnSig3Signal.Broadcast(Param1, Param2, Param3);

	TArray<TScriptInterface<ITestbed2NestedStruct3InterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	if (IsInGameThread())
	{
		OnSig3SignalBP.Broadcast(Param1, Param2, Param3);

		for (const TScriptInterface<ITestbed2NestedStruct3InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed2NestedStruct3InterfaceBPSubscriberInterface::Execute_OnSig3Signal(Obj, Param1, Param2, Param3);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTestbed2NestedStruct3InterfacePublisher>(this), SubscribersCopy, Param1, Param2, Param3]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSig3SignalBP.Broadcast(Param1, Param2, Param3);
			}

			for (const TScriptInterface<ITestbed2NestedStruct3InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITestbed2NestedStruct3InterfaceBPSubscriberInterface::Execute_OnSig3Signal(Obj, Param1, Param2, Param3);
				}
			}
		});
	}
}

void UTestbed2NestedStruct3InterfacePublisher::BroadcastProp1Changed(UPARAM(DisplayName = "Prop1") const FTestbed2NestedStruct1& InProp1)
{
	OnProp1Changed.Broadcast(InProp1);

	TArray<TScriptInterface<ITestbed2NestedStruct3InterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	if (IsInGameThread())
	{
		OnProp1ChangedBP.Broadcast(InProp1);

		for (const TScriptInterface<ITestbed2NestedStruct3InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed2NestedStruct3InterfaceBPSubscriberInterface::Execute_OnProp1Changed(Obj, InProp1);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTestbed2NestedStruct3InterfacePublisher>(this), SubscribersCopy, InProp1]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnProp1ChangedBP.Broadcast(InProp1);
			}

			for (const TScriptInterface<ITestbed2NestedStruct3InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITestbed2NestedStruct3InterfaceBPSubscriberInterface::Execute_OnProp1Changed(Obj, InProp1);
				}
			}
		});
	}
}

void UTestbed2NestedStruct3InterfacePublisher::BroadcastProp2Changed(UPARAM(DisplayName = "Prop2") const FTestbed2NestedStruct2& InProp2)
{
	OnProp2Changed.Broadcast(InProp2);

	TArray<TScriptInterface<ITestbed2NestedStruct3InterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	if (IsInGameThread())
	{
		OnProp2ChangedBP.Broadcast(InProp2);

		for (const TScriptInterface<ITestbed2NestedStruct3InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed2NestedStruct3InterfaceBPSubscriberInterface::Execute_OnProp2Changed(Obj, InProp2);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTestbed2NestedStruct3InterfacePublisher>(this), SubscribersCopy, InProp2]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnProp2ChangedBP.Broadcast(InProp2);
			}

			for (const TScriptInterface<ITestbed2NestedStruct3InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITestbed2NestedStruct3InterfaceBPSubscriberInterface::Execute_OnProp2Changed(Obj, InProp2);
				}
			}
		});
	}
}

void UTestbed2NestedStruct3InterfacePublisher::BroadcastProp3Changed(UPARAM(DisplayName = "Prop3") const FTestbed2NestedStruct3& InProp3)
{
	OnProp3Changed.Broadcast(InProp3);

	TArray<TScriptInterface<ITestbed2NestedStruct3InterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	if (IsInGameThread())
	{
		OnProp3ChangedBP.Broadcast(InProp3);

		for (const TScriptInterface<ITestbed2NestedStruct3InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed2NestedStruct3InterfaceBPSubscriberInterface::Execute_OnProp3Changed(Obj, InProp3);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTestbed2NestedStruct3InterfacePublisher>(this), SubscribersCopy, InProp3]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnProp3ChangedBP.Broadcast(InProp3);
			}

			for (const TScriptInterface<ITestbed2NestedStruct3InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITestbed2NestedStruct3InterfaceBPSubscriberInterface::Execute_OnProp3Changed(Obj, InProp3);
				}
			}
		});
	}
}

void UTestbed2NestedStruct3InterfacePublisher::Subscribe(const TScriptInterface<ITestbed2NestedStruct3InterfaceBPSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	Subscribers.Remove(Subscriber);
	Subscribers.Add(Subscriber);
}

void UTestbed2NestedStruct3InterfacePublisher::Unsubscribe(const TScriptInterface<ITestbed2NestedStruct3InterfaceBPSubscriberInterface>& Subscriber)
{
	Subscribers.Remove(Subscriber);
}
