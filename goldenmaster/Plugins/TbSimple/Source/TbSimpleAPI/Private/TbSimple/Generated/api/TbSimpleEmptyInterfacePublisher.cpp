
#include "TbSimple/Generated/api/TbSimpleEmptyInterfaceInterface.h"
#include "Async/Async.h"
#include "Async/TaskGraphInterfaces.h"

void UTbSimpleEmptyInterfacePublisher::Subscribe(const TScriptInterface<ITbSimpleEmptyInterfaceBPSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	FWriteScopeLock WriteLock(BPSubscribersLock);
	BPSubscribers.Remove(Subscriber);
	BPSubscribers.Add(Subscriber);
}

void UTbSimpleEmptyInterfacePublisher::Subscribe(const TWeakInterfacePtr<ITbSimpleEmptyInterfaceSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
	Subscribers.Add(Subscriber);
}

void UTbSimpleEmptyInterfacePublisher::Unsubscribe(const TScriptInterface<ITbSimpleEmptyInterfaceBPSubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(BPSubscribersLock);
	BPSubscribers.Remove(Subscriber);
}

void UTbSimpleEmptyInterfacePublisher::Unsubscribe(const TWeakInterfacePtr<ITbSimpleEmptyInterfaceSubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
}
