
#include "TbSame1/Generated/api/TbSame1SameStruct1InterfaceInterface.h"
#include "Async/Async.h"
#include "Async/TaskGraphInterfaces.h"

void UTbSame1SameStruct1InterfacePublisher::BroadcastSig1Signal(const FTbSame1Struct1& Param1)
{
	OnSig1Signal.Broadcast(Param1);

	TArray<TScriptInterface<ITbSame1SameStruct1InterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	if (IsInGameThread())
	{
		OnSig1SignalBP.Broadcast(Param1);

		for (const TScriptInterface<ITbSame1SameStruct1InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSame1SameStruct1InterfaceBPSubscriberInterface::Execute_OnSig1Signal(Obj, Param1);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSame1SameStruct1InterfacePublisher>(this), SubscribersCopy, Param1]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSig1SignalBP.Broadcast(Param1);
			}

			for (const TScriptInterface<ITbSame1SameStruct1InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSame1SameStruct1InterfaceBPSubscriberInterface::Execute_OnSig1Signal(Obj, Param1);
				}
			}
		});
	}
}

void UTbSame1SameStruct1InterfacePublisher::BroadcastProp1Changed(UPARAM(DisplayName = "Prop1") const FTbSame1Struct1& InProp1)
{
	OnProp1Changed.Broadcast(InProp1);

	TArray<TScriptInterface<ITbSame1SameStruct1InterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	if (IsInGameThread())
	{
		OnProp1ChangedBP.Broadcast(InProp1);

		for (const TScriptInterface<ITbSame1SameStruct1InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSame1SameStruct1InterfaceBPSubscriberInterface::Execute_OnProp1Changed(Obj, InProp1);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSame1SameStruct1InterfacePublisher>(this), SubscribersCopy, InProp1]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnProp1ChangedBP.Broadcast(InProp1);
			}

			for (const TScriptInterface<ITbSame1SameStruct1InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSame1SameStruct1InterfaceBPSubscriberInterface::Execute_OnProp1Changed(Obj, InProp1);
				}
			}
		});
	}
}

void UTbSame1SameStruct1InterfacePublisher::Subscribe(const TScriptInterface<ITbSame1SameStruct1InterfaceBPSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	Subscribers.Remove(Subscriber);
	Subscribers.Add(Subscriber);
}

void UTbSame1SameStruct1InterfacePublisher::Unsubscribe(const TScriptInterface<ITbSame1SameStruct1InterfaceBPSubscriberInterface>& Subscriber)
{
	Subscribers.Remove(Subscriber);
}
