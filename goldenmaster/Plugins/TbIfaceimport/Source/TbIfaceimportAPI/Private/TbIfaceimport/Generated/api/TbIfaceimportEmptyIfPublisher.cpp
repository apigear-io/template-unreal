
#include "TbIfaceimport/Generated/api/TbIfaceimportEmptyIfInterface.h"
#include "Async/Async.h"
#include "Async/TaskGraphInterfaces.h"

void UTbIfaceimportEmptyIfPublisher::Subscribe(const TScriptInterface<ITbIfaceimportEmptyIfBPSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	FWriteScopeLock WriteLock(BPSubscribersLock);
	BPSubscribers.Remove(Subscriber);
	BPSubscribers.Add(Subscriber);
}

void UTbIfaceimportEmptyIfPublisher::Subscribe(const TWeakInterfacePtr<ITbIfaceimportEmptyIfSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
	Subscribers.Add(Subscriber);
}

void UTbIfaceimportEmptyIfPublisher::Unsubscribe(const TScriptInterface<ITbIfaceimportEmptyIfBPSubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(BPSubscribersLock);
	BPSubscribers.Remove(Subscriber);
}

void UTbIfaceimportEmptyIfPublisher::Unsubscribe(const TWeakInterfacePtr<ITbIfaceimportEmptyIfSubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
}
