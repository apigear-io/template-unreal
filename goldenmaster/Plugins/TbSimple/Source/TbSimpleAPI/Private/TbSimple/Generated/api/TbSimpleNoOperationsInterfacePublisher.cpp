
#include "TbSimple/Generated/api/TbSimpleNoOperationsInterfaceInterface.h"
#include "Async/Async.h"
#include "Async/TaskGraphInterfaces.h"

void UTbSimpleNoOperationsInterfacePublisher::BroadcastSigVoidSignal()
{
	OnSigVoidSignal.Broadcast();

	TArray<TScriptInterface<ITbSimpleNoOperationsInterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnSigVoidSignalBP.Broadcast();

		for (const TScriptInterface<ITbSimpleNoOperationsInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleNoOperationsInterfaceBPSubscriberInterface::Execute_OnSigVoidSignal(Obj);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleNoOperationsInterfacePublisher>(this), SubscribersCopy]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSigVoidSignalBP.Broadcast();
			}

			for (const TScriptInterface<ITbSimpleNoOperationsInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleNoOperationsInterfaceBPSubscriberInterface::Execute_OnSigVoidSignal(Obj);
				}
			}
		});
	}
}

void UTbSimpleNoOperationsInterfacePublisher::BroadcastSigBoolSignal(bool bParamBool)
{
	OnSigBoolSignal.Broadcast(bParamBool);

	TArray<TScriptInterface<ITbSimpleNoOperationsInterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnSigBoolSignalBP.Broadcast(bParamBool);

		for (const TScriptInterface<ITbSimpleNoOperationsInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleNoOperationsInterfaceBPSubscriberInterface::Execute_OnSigBoolSignal(Obj, bParamBool);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleNoOperationsInterfacePublisher>(this), SubscribersCopy, bParamBool]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSigBoolSignalBP.Broadcast(bParamBool);
			}

			for (const TScriptInterface<ITbSimpleNoOperationsInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleNoOperationsInterfaceBPSubscriberInterface::Execute_OnSigBoolSignal(Obj, bParamBool);
				}
			}
		});
	}
}

void UTbSimpleNoOperationsInterfacePublisher::BroadcastPropBoolChanged(UPARAM(DisplayName = "bPropBool") bool bInPropBool)
{
	OnPropBoolChanged.Broadcast(bInPropBool);

	TArray<TScriptInterface<ITbSimpleNoOperationsInterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnPropBoolChangedBP.Broadcast(bInPropBool);

		for (const TScriptInterface<ITbSimpleNoOperationsInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleNoOperationsInterfaceBPSubscriberInterface::Execute_OnPropBoolChanged(Obj, bInPropBool);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleNoOperationsInterfacePublisher>(this), SubscribersCopy, bInPropBool]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnPropBoolChangedBP.Broadcast(bInPropBool);
			}

			for (const TScriptInterface<ITbSimpleNoOperationsInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleNoOperationsInterfaceBPSubscriberInterface::Execute_OnPropBoolChanged(Obj, bInPropBool);
				}
			}
		});
	}
}

void UTbSimpleNoOperationsInterfacePublisher::BroadcastPropIntChanged(UPARAM(DisplayName = "PropInt") int32 InPropInt)
{
	OnPropIntChanged.Broadcast(InPropInt);

	TArray<TScriptInterface<ITbSimpleNoOperationsInterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnPropIntChangedBP.Broadcast(InPropInt);

		for (const TScriptInterface<ITbSimpleNoOperationsInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleNoOperationsInterfaceBPSubscriberInterface::Execute_OnPropIntChanged(Obj, InPropInt);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleNoOperationsInterfacePublisher>(this), SubscribersCopy, InPropInt]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnPropIntChangedBP.Broadcast(InPropInt);
			}

			for (const TScriptInterface<ITbSimpleNoOperationsInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleNoOperationsInterfaceBPSubscriberInterface::Execute_OnPropIntChanged(Obj, InPropInt);
				}
			}
		});
	}
}

void UTbSimpleNoOperationsInterfacePublisher::Subscribe(const TScriptInterface<ITbSimpleNoOperationsInterfaceBPSubscriberInterface>& Subscriber)
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
	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
}
