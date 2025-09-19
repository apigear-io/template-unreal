
#include "TbSimple/Generated/api/TbSimpleVoidInterfaceInterface.h"
#include "Async/Async.h"
#include "Async/TaskGraphInterfaces.h"

void UTbSimpleVoidInterfacePublisher::BroadcastSigVoidSignal()
{
	OnSigVoidSignal.Broadcast();

	TArray<TScriptInterface<ITbSimpleVoidInterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
	if (IsInGameThread())
	{
		OnSigVoidSignalBP.Broadcast();

		for (const TScriptInterface<ITbSimpleVoidInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbSimpleVoidInterfaceBPSubscriberInterface::Execute_OnSigVoidSignal(Obj);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbSimpleVoidInterfacePublisher>(this), SubscribersCopy]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnSigVoidSignalBP.Broadcast();
			}

			for (const TScriptInterface<ITbSimpleVoidInterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbSimpleVoidInterfaceBPSubscriberInterface::Execute_OnSigVoidSignal(Obj);
				}
			}
		});
	}
}

void UTbSimpleVoidInterfacePublisher::Subscribe(const TScriptInterface<ITbSimpleVoidInterfaceBPSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	Subscribers.Remove(Subscriber);
	Subscribers.Add(Subscriber);
}

void UTbSimpleVoidInterfacePublisher::Unsubscribe(const TScriptInterface<ITbSimpleVoidInterfaceBPSubscriberInterface>& Subscriber)
{
	Subscribers.Remove(Subscriber);
}
