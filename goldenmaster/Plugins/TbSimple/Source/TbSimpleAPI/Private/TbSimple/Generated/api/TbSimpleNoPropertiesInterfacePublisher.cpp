
#include "TbSimple/Generated/api/TbSimpleNoPropertiesInterfaceInterface.h"
#include "Async/Async.h"
#include "Async/TaskGraphInterfaces.h"
#include "Runtime/Launch/Resources/Version.h"

void UTbSimpleNoPropertiesInterfacePublisher::BroadcastSigVoidSignal()
{
	OnSigVoidSignal.Broadcast();
	TArray<TWeakInterfacePtr<ITbSimpleNoPropertiesInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbSimpleNoPropertiesInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleNoPropertiesInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSigVoidSignal();
			}
		}
	}

	TArray<TScriptInterface<ITbSimpleNoPropertiesInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnSigVoidSignalBP.Broadcast();

		for (const TScriptInterface<ITbSimpleNoPropertiesInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleNoPropertiesInterfaceBPSubscriberInterface::Execute_OnSigVoidSignal(Obj);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleNoPropertiesInterfacePublisher>(this), BPSubscribersCopy]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSigVoidSignalBP.Broadcast();
			}

			for (const TScriptInterface<ITbSimpleNoPropertiesInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleNoPropertiesInterfaceBPSubscriberInterface::Execute_OnSigVoidSignal(Obj);
				}
			}
		});
	}

	CleanUpSubscribers();
}

void UTbSimpleNoPropertiesInterfacePublisher::BroadcastSigBoolSignal(bool bParamBool)
{
	OnSigBoolSignal.Broadcast(bParamBool);
	TArray<TWeakInterfacePtr<ITbSimpleNoPropertiesInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbSimpleNoPropertiesInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleNoPropertiesInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSigBoolSignal(bParamBool);
			}
		}
	}

	TArray<TScriptInterface<ITbSimpleNoPropertiesInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnSigBoolSignalBP.Broadcast(bParamBool);

		for (const TScriptInterface<ITbSimpleNoPropertiesInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleNoPropertiesInterfaceBPSubscriberInterface::Execute_OnSigBoolSignal(Obj, bParamBool);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleNoPropertiesInterfacePublisher>(this), BPSubscribersCopy, bParamBool]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSigBoolSignalBP.Broadcast(bParamBool);
			}

			for (const TScriptInterface<ITbSimpleNoPropertiesInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleNoPropertiesInterfaceBPSubscriberInterface::Execute_OnSigBoolSignal(Obj, bParamBool);
				}
			}
		});
	}

	CleanUpSubscribers();
}

void UTbSimpleNoPropertiesInterfacePublisher::Subscribe(const TScriptInterface<ITbSimpleNoPropertiesInterfaceBPSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	FWriteScopeLock WriteLock(BPSubscribersLock);
	BPSubscribers.Remove(Subscriber);
	BPSubscribers.Add(Subscriber);
}

void UTbSimpleNoPropertiesInterfacePublisher::Subscribe(const TWeakInterfacePtr<ITbSimpleNoPropertiesInterfaceSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
	Subscribers.Add(Subscriber);
}

void UTbSimpleNoPropertiesInterfacePublisher::Unsubscribe(const TScriptInterface<ITbSimpleNoPropertiesInterfaceBPSubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(BPSubscribersLock);
	BPSubscribers.Remove(Subscriber);
}

void UTbSimpleNoPropertiesInterfacePublisher::Unsubscribe(const TWeakInterfacePtr<ITbSimpleNoPropertiesInterfaceSubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
}

void UTbSimpleNoPropertiesInterfacePublisher::CleanUpSubscribers()
{
#if (ENGINE_MAJOR_VERSION >= 5)
	EAllowShrinking AllowShrinking = EAllowShrinking::No;
#else
	bool AllowShrinking = false;
#endif

	{
		FWriteScopeLock WriteLock(SubscribersLock);
		Subscribers.RemoveAllSwap([](const TWeakInterfacePtr<ITbSimpleNoPropertiesInterfaceSubscriberInterface>& Subscriber)
			{
			return !Subscriber.IsValid();
		},
			AllowShrinking);
	}
	{
		FWriteScopeLock WriteLock(BPSubscribersLock);
		BPSubscribers.RemoveAllSwap([](const TScriptInterface<ITbSimpleNoPropertiesInterfaceBPSubscriberInterface>& Subscriber)
			{
			return Subscriber.GetObject() == nullptr;
		},
			AllowShrinking);
	}
}
