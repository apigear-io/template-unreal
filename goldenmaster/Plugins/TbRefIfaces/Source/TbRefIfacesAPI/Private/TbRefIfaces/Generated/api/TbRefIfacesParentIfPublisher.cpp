
#include "TbIfaceimport/Generated/api/TbIfaceimportEmptyIfInterface.h"
#include "TbRefIfaces/Generated/api/TbRefIfacesSimpleLocalIfInterface.h"
#include "TbRefIfaces/Generated/api/TbRefIfacesParentIfInterface.h"
void UTbRefIfacesParentIfPublisher::BroadcastLocalIfSignalSignal(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Param)
{
	OnLocalIfSignalSignal.Broadcast(Param);
	OnLocalIfSignalSignalBP.Broadcast(Param);

	TArray<TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnLocalIfSignalSignal(Obj, Param);
		}
	}
}

void UTbRefIfacesParentIfPublisher::BroadcastLocalIfSignalListSignal(const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& Param)
{
	OnLocalIfSignalListSignal.Broadcast(Param);
	OnLocalIfSignalListSignalBP.Broadcast(Param);

	TArray<TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnLocalIfSignalListSignal(Obj, Param);
		}
	}
}

void UTbRefIfacesParentIfPublisher::BroadcastImportedIfSignalSignal(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& Param)
{
	OnImportedIfSignalSignal.Broadcast(Param);
	OnImportedIfSignalSignalBP.Broadcast(Param);

	TArray<TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnImportedIfSignalSignal(Obj, Param);
		}
	}
}

void UTbRefIfacesParentIfPublisher::BroadcastImportedIfSignalListSignal(const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& Param)
{
	OnImportedIfSignalListSignal.Broadcast(Param);
	OnImportedIfSignalListSignalBP.Broadcast(Param);

	TArray<TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnImportedIfSignalListSignal(Obj, Param);
		}
	}
}

void UTbRefIfacesParentIfPublisher::BroadcastLocalIfChanged(UPARAM(DisplayName = "LocalIf") const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& InLocalIf)
{
	OnLocalIfChanged.Broadcast(InLocalIf);
	OnLocalIfChangedBP.Broadcast(InLocalIf);

	TArray<TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnLocalIfChanged(Obj, InLocalIf);
		}
	}
}

void UTbRefIfacesParentIfPublisher::BroadcastLocalIfListChanged(UPARAM(DisplayName = "LocalIfList") const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& InLocalIfList)
{
	OnLocalIfListChanged.Broadcast(InLocalIfList);
	OnLocalIfListChangedBP.Broadcast(InLocalIfList);

	TArray<TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnLocalIfListChanged(Obj, InLocalIfList);
		}
	}
}

void UTbRefIfacesParentIfPublisher::BroadcastImportedIfChanged(UPARAM(DisplayName = "ImportedIf") const TScriptInterface<ITbIfaceimportEmptyIfInterface>& InImportedIf)
{
	OnImportedIfChanged.Broadcast(InImportedIf);
	OnImportedIfChangedBP.Broadcast(InImportedIf);

	TArray<TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnImportedIfChanged(Obj, InImportedIf);
		}
	}
}

void UTbRefIfacesParentIfPublisher::BroadcastImportedIfListChanged(UPARAM(DisplayName = "ImportedIfList") const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& InImportedIfList)
{
	OnImportedIfListChanged.Broadcast(InImportedIfList);
	OnImportedIfListChangedBP.Broadcast(InImportedIfList);

	TArray<TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnImportedIfListChanged(Obj, InImportedIfList);
		}
	}
}

void UTbRefIfacesParentIfPublisher::Subscribe(const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	Subscribers.Remove(Subscriber);
	Subscribers.Add(Subscriber);
}

void UTbRefIfacesParentIfPublisher::Unsubscribe(const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber)
{
	Subscribers.Remove(Subscriber);
}
