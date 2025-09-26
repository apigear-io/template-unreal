
#include "TbSimple/Generated/api/TbSimpleNoOperationsInterfaceInterface.h"
#include "Async/Async.h"
#include "Async/TaskGraphInterfaces.h"
#include "Runtime/Launch/Resources/Version.h"

void UTbSimpleNoOperationsInterfacePublisher::BroadcastSigVoidSignal()
{
	OnSigVoidSignal.Broadcast();
	TArray<TWeakInterfacePtr<ITbSimpleNoOperationsInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbSimpleNoOperationsInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleNoOperationsInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSigVoidSignal();
			}
		}
	}

	TArray<TScriptInterface<ITbSimpleNoOperationsInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnSigVoidSignalBP.Broadcast();

		for (const TScriptInterface<ITbSimpleNoOperationsInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleNoOperationsInterfaceBPSubscriberInterface::Execute_OnSigVoidSignal(Obj);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleNoOperationsInterfacePublisher>(this), BPSubscribersCopy]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSigVoidSignalBP.Broadcast();
			}

			for (const TScriptInterface<ITbSimpleNoOperationsInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleNoOperationsInterfaceBPSubscriberInterface::Execute_OnSigVoidSignal(Obj);
				}
			}
		});
	}

	CleanUpSubscribers();
}

void UTbSimpleNoOperationsInterfacePublisher::BroadcastSigBoolSignal(bool bParamBool)
{
	OnSigBoolSignal.Broadcast(bParamBool);
	TArray<TWeakInterfacePtr<ITbSimpleNoOperationsInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbSimpleNoOperationsInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleNoOperationsInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSigBoolSignal(bParamBool);
			}
		}
	}

	TArray<TScriptInterface<ITbSimpleNoOperationsInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnSigBoolSignalBP.Broadcast(bParamBool);

		for (const TScriptInterface<ITbSimpleNoOperationsInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleNoOperationsInterfaceBPSubscriberInterface::Execute_OnSigBoolSignal(Obj, bParamBool);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleNoOperationsInterfacePublisher>(this), BPSubscribersCopy, bParamBool]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSigBoolSignalBP.Broadcast(bParamBool);
			}

			for (const TScriptInterface<ITbSimpleNoOperationsInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleNoOperationsInterfaceBPSubscriberInterface::Execute_OnSigBoolSignal(Obj, bParamBool);
				}
			}
		});
	}

	CleanUpSubscribers();
}

void UTbSimpleNoOperationsInterfacePublisher::BroadcastPropBoolChanged(UPARAM(DisplayName = "bPropBool") bool bInPropBool)
{
	OnPropBoolChanged.Broadcast(bInPropBool);
	TArray<TWeakInterfacePtr<ITbSimpleNoOperationsInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbSimpleNoOperationsInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleNoOperationsInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnPropBoolChanged(bInPropBool);
			}
		}
	}

	TArray<TScriptInterface<ITbSimpleNoOperationsInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnPropBoolChangedBP.Broadcast(bInPropBool);

		for (const TScriptInterface<ITbSimpleNoOperationsInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleNoOperationsInterfaceBPSubscriberInterface::Execute_OnPropBoolChanged(Obj, bInPropBool);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleNoOperationsInterfacePublisher>(this), BPSubscribersCopy, bInPropBool]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnPropBoolChangedBP.Broadcast(bInPropBool);
			}

			for (const TScriptInterface<ITbSimpleNoOperationsInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleNoOperationsInterfaceBPSubscriberInterface::Execute_OnPropBoolChanged(Obj, bInPropBool);
				}
			}
		});
	}

	CleanUpSubscribers();
}

void UTbSimpleNoOperationsInterfacePublisher::BroadcastPropIntChanged(UPARAM(DisplayName = "PropInt") int32 InPropInt)
{
	OnPropIntChanged.Broadcast(InPropInt);
	TArray<TWeakInterfacePtr<ITbSimpleNoOperationsInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbSimpleNoOperationsInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleNoOperationsInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnPropIntChanged(InPropInt);
			}
		}
	}

	TArray<TScriptInterface<ITbSimpleNoOperationsInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnPropIntChangedBP.Broadcast(InPropInt);

		for (const TScriptInterface<ITbSimpleNoOperationsInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleNoOperationsInterfaceBPSubscriberInterface::Execute_OnPropIntChanged(Obj, InPropInt);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleNoOperationsInterfacePublisher>(this), BPSubscribersCopy, InPropInt]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnPropIntChangedBP.Broadcast(InPropInt);
			}

			for (const TScriptInterface<ITbSimpleNoOperationsInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleNoOperationsInterfaceBPSubscriberInterface::Execute_OnPropIntChanged(Obj, InPropInt);
				}
			}
		});
	}

	CleanUpSubscribers();
}

void UTbSimpleNoOperationsInterfacePublisher::Subscribe(const TScriptInterface<ITbSimpleNoOperationsInterfaceBPSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	FWriteScopeLock WriteLock(BPSubscribersLock);
	BPSubscribers.Remove(Subscriber);
	BPSubscribers.Add(Subscriber);
}

void UTbSimpleNoOperationsInterfacePublisher::Subscribe(const TWeakInterfacePtr<ITbSimpleNoOperationsInterfaceSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
	Subscribers.Add(Subscriber);
}

void UTbSimpleNoOperationsInterfacePublisher::Unsubscribe(const TScriptInterface<ITbSimpleNoOperationsInterfaceBPSubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(BPSubscribersLock);
	BPSubscribers.Remove(Subscriber);
}

void UTbSimpleNoOperationsInterfacePublisher::Unsubscribe(const TWeakInterfacePtr<ITbSimpleNoOperationsInterfaceSubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
}

void UTbSimpleNoOperationsInterfacePublisher::CleanUpSubscribers()
{
#if (ENGINE_MAJOR_VERSION >= 5)
	EAllowShrinking AllowShrinking = EAllowShrinking::No;
#else
	bool AllowShrinking = false;
#endif

	{
		FWriteScopeLock WriteLock(SubscribersLock);
		Subscribers.RemoveAllSwap([](const TWeakInterfacePtr<ITbSimpleNoOperationsInterfaceSubscriberInterface>& Subscriber)
			{
			return !Subscriber.IsValid();
		},
			AllowShrinking);
	}
	{
		FWriteScopeLock WriteLock(BPSubscribersLock);
		BPSubscribers.RemoveAllSwap([](const TScriptInterface<ITbSimpleNoOperationsInterfaceBPSubscriberInterface>& Subscriber)
			{
			return Subscriber.GetObject() == nullptr;
		},
			AllowShrinking);
	}
}
