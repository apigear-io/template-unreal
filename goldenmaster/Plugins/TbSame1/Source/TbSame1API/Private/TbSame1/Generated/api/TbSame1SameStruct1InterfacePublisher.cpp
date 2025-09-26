
#include "TbSame1/Generated/api/TbSame1SameStruct1InterfaceInterface.h"
#include "Async/Async.h"
#include "Async/TaskGraphInterfaces.h"
#include "Runtime/Launch/Resources/Version.h"

void UTbSame1SameStruct1InterfacePublisher::BroadcastSig1Signal(const FTbSame1Struct1& Param1)
{
	TArray<TWeakInterfacePtr<ITbSame1SameStruct1InterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}

	TArray<TScriptInterface<ITbSame1SameStruct1InterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnSig1Signal.Broadcast(Param1);
	for (const TWeakInterfacePtr<ITbSame1SameStruct1InterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSame1SameStruct1InterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSig1Signal(Param1);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTbSame1SameStruct1InterfacePublisher>(this), BPSubscribersCopy, Param1]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnSig1SignalBP.Broadcast(Param1);
		}

		for (const TScriptInterface<ITbSame1SameStruct1InterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSame1SameStruct1InterfaceBPSubscriberInterface::Execute_OnSig1Signal(Obj, Param1);
			}
		}

		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->CleanUpSubscribers();
		}
	};

	if (IsInGameThread())
	{
		BroadCastOnGameThread();
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, MoveTemp(BroadCastOnGameThread));
	}
}

void UTbSame1SameStruct1InterfacePublisher::BroadcastProp1Changed(UPARAM(DisplayName = "Prop1") const FTbSame1Struct1& InProp1)
{
	TArray<TWeakInterfacePtr<ITbSame1SameStruct1InterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITbSame1SameStruct1InterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	OnProp1Changed.Broadcast(InProp1);
	for (const TWeakInterfacePtr<ITbSame1SameStruct1InterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSame1SameStruct1InterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnProp1Changed(InProp1);
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<UTbSame1SameStruct1InterfacePublisher>(this), BPSubscribersCopy, InProp1]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->OnProp1ChangedBP.Broadcast(InProp1);
		}

		for (const TScriptInterface<ITbSame1SameStruct1InterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSame1SameStruct1InterfaceBPSubscriberInterface::Execute_OnProp1Changed(Obj, InProp1);
			}
		}

		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->CleanUpSubscribers();
		}
	};
	if (IsInGameThread())
	{
		BroadCastOnGameThread();
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, MoveTemp(BroadCastOnGameThread));
	}
}

void UTbSame1SameStruct1InterfacePublisher::Subscribe(const TScriptInterface<ITbSame1SameStruct1InterfaceBPSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	FWriteScopeLock WriteLock(BPSubscribersLock);
	BPSubscribers.Remove(Subscriber);
	BPSubscribers.Add(Subscriber);
}

void UTbSame1SameStruct1InterfacePublisher::Subscribe(const TWeakInterfacePtr<ITbSame1SameStruct1InterfaceSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
	Subscribers.Add(Subscriber);
}

void UTbSame1SameStruct1InterfacePublisher::Unsubscribe(const TScriptInterface<ITbSame1SameStruct1InterfaceBPSubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(BPSubscribersLock);
	BPSubscribers.Remove(Subscriber);
}

void UTbSame1SameStruct1InterfacePublisher::Unsubscribe(const TWeakInterfacePtr<ITbSame1SameStruct1InterfaceSubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
}

void UTbSame1SameStruct1InterfacePublisher::CleanUpSubscribers()
{
#if (ENGINE_MAJOR_VERSION >= 5)
	EAllowShrinking AllowShrinking = EAllowShrinking::No;
#else
	bool AllowShrinking = false;
#endif

	{
		FWriteScopeLock WriteLock(SubscribersLock);
		Subscribers.RemoveAllSwap([](const TWeakInterfacePtr<ITbSame1SameStruct1InterfaceSubscriberInterface>& Subscriber)
			{
			return !Subscriber.IsValid();
		},
			AllowShrinking);
	}
	{
		FWriteScopeLock WriteLock(BPSubscribersLock);
		BPSubscribers.RemoveAllSwap([](const TScriptInterface<ITbSame1SameStruct1InterfaceBPSubscriberInterface>& Subscriber)
			{
			return Subscriber.GetObject() == nullptr;
		},
			AllowShrinking);
	}
}
