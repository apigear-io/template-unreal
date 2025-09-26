
#include "TbSimple/Generated/api/TbSimpleNoSignalsInterfaceInterface.h"
#include "Async/Async.h"
#include "Async/TaskGraphInterfaces.h"
#include "Runtime/Launch/Resources/Version.h"

void UTbSimpleNoSignalsInterfacePublisher::BroadcastPropBoolChanged(UPARAM(DisplayName = "bPropBool") bool bInPropBool)
{
	OnPropBoolChanged.Broadcast(bInPropBool);
	TArray<TWeakInterfacePtr<ITbSimpleNoSignalsInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbSimpleNoSignalsInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleNoSignalsInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnPropBoolChanged(bInPropBool);
			}
		}
	}

	TArray<TScriptInterface<ITbSimpleNoSignalsInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnPropBoolChangedBP.Broadcast(bInPropBool);

		for (const TScriptInterface<ITbSimpleNoSignalsInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleNoSignalsInterfaceBPSubscriberInterface::Execute_OnPropBoolChanged(Obj, bInPropBool);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleNoSignalsInterfacePublisher>(this), BPSubscribersCopy, bInPropBool]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnPropBoolChangedBP.Broadcast(bInPropBool);
			}

			for (const TScriptInterface<ITbSimpleNoSignalsInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleNoSignalsInterfaceBPSubscriberInterface::Execute_OnPropBoolChanged(Obj, bInPropBool);
				}
			}
		});
	}

	CleanUpSubscribers();
}

void UTbSimpleNoSignalsInterfacePublisher::BroadcastPropIntChanged(UPARAM(DisplayName = "PropInt") int32 InPropInt)
{
	OnPropIntChanged.Broadcast(InPropInt);
	TArray<TWeakInterfacePtr<ITbSimpleNoSignalsInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbSimpleNoSignalsInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleNoSignalsInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnPropIntChanged(InPropInt);
			}
		}
	}

	TArray<TScriptInterface<ITbSimpleNoSignalsInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnPropIntChangedBP.Broadcast(InPropInt);

		for (const TScriptInterface<ITbSimpleNoSignalsInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleNoSignalsInterfaceBPSubscriberInterface::Execute_OnPropIntChanged(Obj, InPropInt);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleNoSignalsInterfacePublisher>(this), BPSubscribersCopy, InPropInt]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnPropIntChangedBP.Broadcast(InPropInt);
			}

			for (const TScriptInterface<ITbSimpleNoSignalsInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleNoSignalsInterfaceBPSubscriberInterface::Execute_OnPropIntChanged(Obj, InPropInt);
				}
			}
		});
	}

	CleanUpSubscribers();
}

void UTbSimpleNoSignalsInterfacePublisher::Subscribe(const TScriptInterface<ITbSimpleNoSignalsInterfaceBPSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	FWriteScopeLock WriteLock(BPSubscribersLock);
	BPSubscribers.Remove(Subscriber);
	BPSubscribers.Add(Subscriber);
}

void UTbSimpleNoSignalsInterfacePublisher::Subscribe(const TWeakInterfacePtr<ITbSimpleNoSignalsInterfaceSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
	Subscribers.Add(Subscriber);
}

void UTbSimpleNoSignalsInterfacePublisher::Unsubscribe(const TScriptInterface<ITbSimpleNoSignalsInterfaceBPSubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(BPSubscribersLock);
	BPSubscribers.Remove(Subscriber);
}

void UTbSimpleNoSignalsInterfacePublisher::Unsubscribe(const TWeakInterfacePtr<ITbSimpleNoSignalsInterfaceSubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
}

void UTbSimpleNoSignalsInterfacePublisher::CleanUpSubscribers()
{
#if (ENGINE_MAJOR_VERSION >= 5)
	EAllowShrinking AllowShrinking = EAllowShrinking::No;
#else
	bool AllowShrinking = false;
#endif

	{
		FWriteScopeLock WriteLock(SubscribersLock);
		Subscribers.RemoveAllSwap([](const TWeakInterfacePtr<ITbSimpleNoSignalsInterfaceSubscriberInterface>& Subscriber)
			{
			return !Subscriber.IsValid();
		},
			AllowShrinking);
	}
	{
		FWriteScopeLock WriteLock(BPSubscribersLock);
		BPSubscribers.RemoveAllSwap([](const TScriptInterface<ITbSimpleNoSignalsInterfaceBPSubscriberInterface>& Subscriber)
			{
			return Subscriber.GetObject() == nullptr;
		},
			AllowShrinking);
	}
}
