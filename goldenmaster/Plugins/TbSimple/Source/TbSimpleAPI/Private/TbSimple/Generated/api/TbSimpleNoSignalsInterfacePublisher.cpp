
#include "TbSimple/Generated/api/TbSimpleNoSignalsInterfaceInterface.h"
#include "Async/Async.h"
#include "Async/TaskGraphInterfaces.h"

void UTbSimpleNoSignalsInterfacePublisher::BroadcastPropBoolChanged(UPARAM(DisplayName = "bPropBool") bool bInPropBool)
{
	OnPropBoolChanged.Broadcast(bInPropBool);

	TArray<TScriptInterface<ITbSimpleNoSignalsInterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnPropBoolChangedBP.Broadcast(bInPropBool);

		for (const TScriptInterface<ITbSimpleNoSignalsInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleNoSignalsInterfaceBPSubscriberInterface::Execute_OnPropBoolChanged(Obj, bInPropBool);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleNoSignalsInterfacePublisher>(this), SubscribersCopy, bInPropBool]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnPropBoolChangedBP.Broadcast(bInPropBool);
			}

			for (const TScriptInterface<ITbSimpleNoSignalsInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleNoSignalsInterfaceBPSubscriberInterface::Execute_OnPropBoolChanged(Obj, bInPropBool);
				}
			}
		});
	}
}

void UTbSimpleNoSignalsInterfacePublisher::BroadcastPropIntChanged(UPARAM(DisplayName = "PropInt") int32 InPropInt)
{
	OnPropIntChanged.Broadcast(InPropInt);

	TArray<TScriptInterface<ITbSimpleNoSignalsInterfaceBPSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	if (IsInGameThread())
	{
		OnPropIntChangedBP.Broadcast(InPropInt);

		for (const TScriptInterface<ITbSimpleNoSignalsInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleNoSignalsInterfaceBPSubscriberInterface::Execute_OnPropIntChanged(Obj, InPropInt);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleNoSignalsInterfacePublisher>(this), SubscribersCopy, InPropInt]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnPropIntChangedBP.Broadcast(InPropInt);
			}

			for (const TScriptInterface<ITbSimpleNoSignalsInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleNoSignalsInterfaceBPSubscriberInterface::Execute_OnPropIntChanged(Obj, InPropInt);
				}
			}
		});
	}
}

void UTbSimpleNoSignalsInterfacePublisher::Subscribe(const TScriptInterface<ITbSimpleNoSignalsInterfaceBPSubscriberInterface>& Subscriber)
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
	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
}
