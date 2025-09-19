
#include "TbIfaceimport/Generated/api/TbIfaceimportEmptyIfInterface.h"
#include "TbRefIfaces/Generated/api/TbRefIfacesSimpleLocalIfInterface.h"
#include "TbRefIfaces/Generated/api/TbRefIfacesParentIfInterface.h"
#include "Async/Async.h"
#include "Async/TaskGraphInterfaces.h"

void UTbRefIfacesParentIfPublisher::BroadcastLocalIfSignalSignal(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Param)
{
	OnLocalIfSignalSignal.Broadcast(Param);

	TArray<TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>> SubscribersCopy = Subscribers;
	if (IsInGameThread())
	{
		OnLocalIfSignalSignalBP.Broadcast(Param);

		for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnLocalIfSignalSignal(Obj, Param);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbRefIfacesParentIfPublisher>(this), SubscribersCopy, Param]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnLocalIfSignalSignalBP.Broadcast(Param);
			}

			for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnLocalIfSignalSignal(Obj, Param);
				}
			}
		});
	}
}

void UTbRefIfacesParentIfPublisher::BroadcastLocalIfSignalListSignal(const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& Param)
{
	OnLocalIfSignalListSignal.Broadcast(Param);

	TArray<TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>> SubscribersCopy = Subscribers;
	if (IsInGameThread())
	{
		OnLocalIfSignalListSignalBP.Broadcast(Param);

		for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnLocalIfSignalListSignal(Obj, Param);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbRefIfacesParentIfPublisher>(this), SubscribersCopy, Param]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnLocalIfSignalListSignalBP.Broadcast(Param);
			}

			for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnLocalIfSignalListSignal(Obj, Param);
				}
			}
		});
	}
}

void UTbRefIfacesParentIfPublisher::BroadcastImportedIfSignalSignal(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& Param)
{
	OnImportedIfSignalSignal.Broadcast(Param);

	TArray<TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>> SubscribersCopy = Subscribers;
	if (IsInGameThread())
	{
		OnImportedIfSignalSignalBP.Broadcast(Param);

		for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnImportedIfSignalSignal(Obj, Param);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbRefIfacesParentIfPublisher>(this), SubscribersCopy, Param]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnImportedIfSignalSignalBP.Broadcast(Param);
			}

			for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnImportedIfSignalSignal(Obj, Param);
				}
			}
		});
	}
}

void UTbRefIfacesParentIfPublisher::BroadcastImportedIfSignalListSignal(const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& Param)
{
	OnImportedIfSignalListSignal.Broadcast(Param);

	TArray<TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>> SubscribersCopy = Subscribers;
	if (IsInGameThread())
	{
		OnImportedIfSignalListSignalBP.Broadcast(Param);

		for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnImportedIfSignalListSignal(Obj, Param);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbRefIfacesParentIfPublisher>(this), SubscribersCopy, Param]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnImportedIfSignalListSignalBP.Broadcast(Param);
			}

			for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnImportedIfSignalListSignal(Obj, Param);
				}
			}
		});
	}
}

void UTbRefIfacesParentIfPublisher::BroadcastLocalIfChanged(UPARAM(DisplayName = "LocalIf") const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& InLocalIf)
{
	OnLocalIfChanged.Broadcast(InLocalIf);

	TArray<TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>> SubscribersCopy = Subscribers;
	if (IsInGameThread())
	{
		OnLocalIfChangedBP.Broadcast(InLocalIf);

		for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnLocalIfChanged(Obj, InLocalIf);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbRefIfacesParentIfPublisher>(this), SubscribersCopy, InLocalIf]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnLocalIfChangedBP.Broadcast(InLocalIf);
			}

			for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnLocalIfChanged(Obj, InLocalIf);
				}
			}
		});
	}
}

void UTbRefIfacesParentIfPublisher::BroadcastLocalIfListChanged(UPARAM(DisplayName = "LocalIfList") const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& InLocalIfList)
{
	OnLocalIfListChanged.Broadcast(InLocalIfList);

	TArray<TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>> SubscribersCopy = Subscribers;
	if (IsInGameThread())
	{
		OnLocalIfListChangedBP.Broadcast(InLocalIfList);

		for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnLocalIfListChanged(Obj, InLocalIfList);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbRefIfacesParentIfPublisher>(this), SubscribersCopy, InLocalIfList]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnLocalIfListChangedBP.Broadcast(InLocalIfList);
			}

			for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnLocalIfListChanged(Obj, InLocalIfList);
				}
			}
		});
	}
}

void UTbRefIfacesParentIfPublisher::BroadcastImportedIfChanged(UPARAM(DisplayName = "ImportedIf") const TScriptInterface<ITbIfaceimportEmptyIfInterface>& InImportedIf)
{
	OnImportedIfChanged.Broadcast(InImportedIf);

	TArray<TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>> SubscribersCopy = Subscribers;
	if (IsInGameThread())
	{
		OnImportedIfChangedBP.Broadcast(InImportedIf);

		for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnImportedIfChanged(Obj, InImportedIf);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbRefIfacesParentIfPublisher>(this), SubscribersCopy, InImportedIf]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnImportedIfChangedBP.Broadcast(InImportedIf);
			}

			for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnImportedIfChanged(Obj, InImportedIf);
				}
			}
		});
	}
}

void UTbRefIfacesParentIfPublisher::BroadcastImportedIfListChanged(UPARAM(DisplayName = "ImportedIfList") const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& InImportedIfList)
{
	OnImportedIfListChanged.Broadcast(InImportedIfList);

	TArray<TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>> SubscribersCopy = Subscribers;
	if (IsInGameThread())
	{
		OnImportedIfListChangedBP.Broadcast(InImportedIfList);

		for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnImportedIfListChanged(Obj, InImportedIfList);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<UTbRefIfacesParentIfPublisher>(this), SubscribersCopy, InImportedIfList]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->OnImportedIfListChangedBP.Broadcast(InImportedIfList);
			}

			for (const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber : SubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					ITbRefIfacesParentIfBPSubscriberInterface::Execute_OnImportedIfListChanged(Obj, InImportedIfList);
				}
			}
		});
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
