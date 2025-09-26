
#include "TbSimple/Generated/api/TbSimpleVoidInterfaceInterface.h"
#include "Async/Async.h"
#include "Async/TaskGraphInterfaces.h"
#include "Runtime/Launch/Resources/Version.h"

void UTbSimpleVoidInterfacePublisher::BroadcastSigVoidSignal()
{
	OnSigVoidSignal.Broadcast();
	TArray<TWeakInterfacePtr<ITbSimpleVoidInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<ITbSimpleVoidInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (ITbSimpleVoidInterfaceSubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->OnSigVoidSignal();
			}
		}
	}

	TArray<TScriptInterface<ITbSimpleVoidInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		OnSigVoidSignalBP.Broadcast();

		for (const TScriptInterface<ITbSimpleVoidInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleVoidInterfaceBPSubscriberInterface::Execute_OnSigVoidSignal(Obj);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleVoidInterfacePublisher>(this), BPSubscribersCopy]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSigVoidSignalBP.Broadcast();
			}

			for (const TScriptInterface<ITbSimpleVoidInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleVoidInterfaceBPSubscriberInterface::Execute_OnSigVoidSignal(Obj);
				}
			}
		});
	}

	CleanUpSubscribers();
}

void UTbSimpleVoidInterfacePublisher::Subscribe(const TScriptInterface<ITbSimpleVoidInterfaceBPSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	FWriteScopeLock WriteLock(BPSubscribersLock);
	BPSubscribers.Remove(Subscriber);
	BPSubscribers.Add(Subscriber);
}

void UTbSimpleVoidInterfacePublisher::Subscribe(const TWeakInterfacePtr<ITbSimpleVoidInterfaceSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
	Subscribers.Add(Subscriber);
}

void UTbSimpleVoidInterfacePublisher::Unsubscribe(const TScriptInterface<ITbSimpleVoidInterfaceBPSubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(BPSubscribersLock);
	BPSubscribers.Remove(Subscriber);
}

void UTbSimpleVoidInterfacePublisher::Unsubscribe(const TWeakInterfacePtr<ITbSimpleVoidInterfaceSubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
}

void UTbSimpleVoidInterfacePublisher::CleanUpSubscribers()
{
#if (ENGINE_MAJOR_VERSION >= 5)
	EAllowShrinking AllowShrinking = EAllowShrinking::No;
#else
	bool AllowShrinking = false;
#endif

	{
		FWriteScopeLock WriteLock(SubscribersLock);
		Subscribers.RemoveAllSwap([](const TWeakInterfacePtr<ITbSimpleVoidInterfaceSubscriberInterface>& Subscriber)
			{
			return !Subscriber.IsValid();
		},
			AllowShrinking);
	}
	{
		FWriteScopeLock WriteLock(BPSubscribersLock);
		BPSubscribers.RemoveAllSwap([](const TScriptInterface<ITbSimpleVoidInterfaceBPSubscriberInterface>& Subscriber)
			{
			return Subscriber.GetObject() == nullptr;
		},
			AllowShrinking);
	}
}
