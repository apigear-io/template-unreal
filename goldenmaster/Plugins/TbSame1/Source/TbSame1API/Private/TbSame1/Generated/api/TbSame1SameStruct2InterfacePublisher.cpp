
#include "TbSame1/Generated/api/TbSame1SameStruct2InterfaceInterface.h"
#include "Async/Async.h"
#include "Async/TaskGraphInterfaces.h"

void UTbSame1SameStruct2InterfacePublisher::BroadcastSig1Signal(const FTbSame1Struct1& Param1)
{
	OnSig1Signal.Broadcast(Param1);

	TArray<TScriptInterface<ITbSame1SameStruct2InterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	if (IsInGameThread())
	{
		OnSig1SignalBP.Broadcast(Param1);

		for (const TScriptInterface<ITbSame1SameStruct2InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSame1SameStruct2InterfaceBPSubscriberInterface::Execute_OnSig1Signal(Obj, Param1);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSame1SameStruct2InterfacePublisher>(this), SubscribersCopy, Param1]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSig1SignalBP.Broadcast(Param1);
			}

			for (const TScriptInterface<ITbSame1SameStruct2InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSame1SameStruct2InterfaceBPSubscriberInterface::Execute_OnSig1Signal(Obj, Param1);
				}
			}
		});
	}
}

void UTbSame1SameStruct2InterfacePublisher::BroadcastSig2Signal(const FTbSame1Struct1& Param1, const FTbSame1Struct2& Param2)
{
	OnSig2Signal.Broadcast(Param1, Param2);

	TArray<TScriptInterface<ITbSame1SameStruct2InterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	if (IsInGameThread())
	{
		OnSig2SignalBP.Broadcast(Param1, Param2);

		for (const TScriptInterface<ITbSame1SameStruct2InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSame1SameStruct2InterfaceBPSubscriberInterface::Execute_OnSig2Signal(Obj, Param1, Param2);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSame1SameStruct2InterfacePublisher>(this), SubscribersCopy, Param1, Param2]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSig2SignalBP.Broadcast(Param1, Param2);
			}

			for (const TScriptInterface<ITbSame1SameStruct2InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSame1SameStruct2InterfaceBPSubscriberInterface::Execute_OnSig2Signal(Obj, Param1, Param2);
				}
			}
		});
	}
}

void UTbSame1SameStruct2InterfacePublisher::BroadcastProp1Changed(UPARAM(DisplayName = "Prop1") const FTbSame1Struct2& InProp1)
{
	OnProp1Changed.Broadcast(InProp1);

	TArray<TScriptInterface<ITbSame1SameStruct2InterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	if (IsInGameThread())
	{
		OnProp1ChangedBP.Broadcast(InProp1);

		for (const TScriptInterface<ITbSame1SameStruct2InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSame1SameStruct2InterfaceBPSubscriberInterface::Execute_OnProp1Changed(Obj, InProp1);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSame1SameStruct2InterfacePublisher>(this), SubscribersCopy, InProp1]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnProp1ChangedBP.Broadcast(InProp1);
			}

			for (const TScriptInterface<ITbSame1SameStruct2InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSame1SameStruct2InterfaceBPSubscriberInterface::Execute_OnProp1Changed(Obj, InProp1);
				}
			}
		});
	}
}

void UTbSame1SameStruct2InterfacePublisher::BroadcastProp2Changed(UPARAM(DisplayName = "Prop2") const FTbSame1Struct2& InProp2)
{
	OnProp2Changed.Broadcast(InProp2);

	TArray<TScriptInterface<ITbSame1SameStruct2InterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	if (IsInGameThread())
	{
		OnProp2ChangedBP.Broadcast(InProp2);

		for (const TScriptInterface<ITbSame1SameStruct2InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSame1SameStruct2InterfaceBPSubscriberInterface::Execute_OnProp2Changed(Obj, InProp2);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSame1SameStruct2InterfacePublisher>(this), SubscribersCopy, InProp2]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnProp2ChangedBP.Broadcast(InProp2);
			}

			for (const TScriptInterface<ITbSame1SameStruct2InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSame1SameStruct2InterfaceBPSubscriberInterface::Execute_OnProp2Changed(Obj, InProp2);
				}
			}
		});
	}
}

void UTbSame1SameStruct2InterfacePublisher::Subscribe(const TScriptInterface<ITbSame1SameStruct2InterfaceBPSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	Subscribers.Remove(Subscriber);
	Subscribers.Add(Subscriber);
}

void UTbSame1SameStruct2InterfacePublisher::Unsubscribe(const TScriptInterface<ITbSame1SameStruct2InterfaceBPSubscriberInterface>& Subscriber)
{
	Subscribers.Remove(Subscriber);
}
