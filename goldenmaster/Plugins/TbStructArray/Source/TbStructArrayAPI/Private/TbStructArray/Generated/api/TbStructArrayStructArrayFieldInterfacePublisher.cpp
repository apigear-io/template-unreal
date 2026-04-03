
#include "TbStructArray/Generated/api/TbStructArrayStructArrayFieldInterfaceInterface.h"
#include "Async/Async.h"
#include "Async/TaskGraphInterfaces.h"
#include "Runtime/Launch/Resources/Version.h"

void UTbStructArrayStructArrayFieldInterfacePublisher::BroadcastSigMixedSignal(const FTbStructArrayMixedStruct& ParamMixed)
{
	TArray<TWeakInterfacePtr<ITbStructArrayStructArrayFieldInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}

	TArray<TScriptInterface<ITbStructArrayStructArrayFieldInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	auto BroadcastAll = [WeakPtr = TWeakObjectPtr<UTbStructArrayStructArrayFieldInterfacePublisher>(this), SubscribersCopy, BPSubscribersCopy, ParamMixed]()
	{
		if (!WeakPtr.IsValid())
		{
			return;
		}

		WeakPtr.Get()->OnSigMixedSignal.Broadcast(ParamMixed);
		for (const TWeakInterfacePtr<ITbStructArrayStructArrayFieldInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (Subscriber.IsValid())
			{
				if (ITbStructArrayStructArrayFieldInterfaceSubscriberInterface* Iface = Subscriber.Get())
				{
					Iface->OnSigMixedSignal(ParamMixed);
				}
			}
		}

		WeakPtr.Get()->OnSigMixedSignalBP.Broadcast(ParamMixed);
		for (const TScriptInterface<ITbStructArrayStructArrayFieldInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbStructArrayStructArrayFieldInterfaceBPSubscriberInterface::Execute_OnSigMixedSignal(Obj, ParamMixed);
			}
		}

		WeakPtr.Get()->CleanUpSubscribers();
	};

	if (IsInGameThread())
	{
		BroadcastAll();
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, MoveTemp(BroadcastAll));
	}
}

void UTbStructArrayStructArrayFieldInterfacePublisher::BroadcastSigStructArraySignal(const FTbStructArrayStructWithArrayOfStructs& ParamPoints)
{
	TArray<TWeakInterfacePtr<ITbStructArrayStructArrayFieldInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}

	TArray<TScriptInterface<ITbStructArrayStructArrayFieldInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	auto BroadcastAll = [WeakPtr = TWeakObjectPtr<UTbStructArrayStructArrayFieldInterfacePublisher>(this), SubscribersCopy, BPSubscribersCopy, ParamPoints]()
	{
		if (!WeakPtr.IsValid())
		{
			return;
		}

		WeakPtr.Get()->OnSigStructArraySignal.Broadcast(ParamPoints);
		for (const TWeakInterfacePtr<ITbStructArrayStructArrayFieldInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (Subscriber.IsValid())
			{
				if (ITbStructArrayStructArrayFieldInterfaceSubscriberInterface* Iface = Subscriber.Get())
				{
					Iface->OnSigStructArraySignal(ParamPoints);
				}
			}
		}

		WeakPtr.Get()->OnSigStructArraySignalBP.Broadcast(ParamPoints);
		for (const TScriptInterface<ITbStructArrayStructArrayFieldInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbStructArrayStructArrayFieldInterfaceBPSubscriberInterface::Execute_OnSigStructArraySignal(Obj, ParamPoints);
			}
		}

		WeakPtr.Get()->CleanUpSubscribers();
	};

	if (IsInGameThread())
	{
		BroadcastAll();
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, MoveTemp(BroadcastAll));
	}
}

void UTbStructArrayStructArrayFieldInterfacePublisher::BroadcastPropStructArrayChanged(UPARAM(DisplayName = "PropStructArray") const FTbStructArrayStructWithArrayOfStructs& InPropStructArray)
{
	TArray<TWeakInterfacePtr<ITbStructArrayStructArrayFieldInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITbStructArrayStructArrayFieldInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	auto BroadcastAll = [WeakPtr = TWeakObjectPtr<UTbStructArrayStructArrayFieldInterfacePublisher>(this), SubscribersCopy, BPSubscribersCopy, InPropStructArray]()
	{
		if (!WeakPtr.IsValid())
		{
			return;
		}

		WeakPtr.Get()->OnPropStructArrayChanged.Broadcast(InPropStructArray);
		for (const TWeakInterfacePtr<ITbStructArrayStructArrayFieldInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (Subscriber.IsValid())
			{
				if (ITbStructArrayStructArrayFieldInterfaceSubscriberInterface* Iface = Subscriber.Get())
				{
					Iface->OnPropStructArrayChanged(InPropStructArray);
				}
			}
		}

		WeakPtr.Get()->OnPropStructArrayChangedBP.Broadcast(InPropStructArray);
		for (const TScriptInterface<ITbStructArrayStructArrayFieldInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbStructArrayStructArrayFieldInterfaceBPSubscriberInterface::Execute_OnPropStructArrayChanged(Obj, InPropStructArray);
			}
		}

		WeakPtr.Get()->CleanUpSubscribers();
	};

	if (IsInGameThread())
	{
		BroadcastAll();
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, MoveTemp(BroadcastAll));
	}
}

void UTbStructArrayStructArrayFieldInterfacePublisher::BroadcastPropEnumArrayChanged(UPARAM(DisplayName = "PropEnumArray") const FTbStructArrayStructWithArrayOfEnums& InPropEnumArray)
{
	TArray<TWeakInterfacePtr<ITbStructArrayStructArrayFieldInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITbStructArrayStructArrayFieldInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	auto BroadcastAll = [WeakPtr = TWeakObjectPtr<UTbStructArrayStructArrayFieldInterfacePublisher>(this), SubscribersCopy, BPSubscribersCopy, InPropEnumArray]()
	{
		if (!WeakPtr.IsValid())
		{
			return;
		}

		WeakPtr.Get()->OnPropEnumArrayChanged.Broadcast(InPropEnumArray);
		for (const TWeakInterfacePtr<ITbStructArrayStructArrayFieldInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (Subscriber.IsValid())
			{
				if (ITbStructArrayStructArrayFieldInterfaceSubscriberInterface* Iface = Subscriber.Get())
				{
					Iface->OnPropEnumArrayChanged(InPropEnumArray);
				}
			}
		}

		WeakPtr.Get()->OnPropEnumArrayChangedBP.Broadcast(InPropEnumArray);
		for (const TScriptInterface<ITbStructArrayStructArrayFieldInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbStructArrayStructArrayFieldInterfaceBPSubscriberInterface::Execute_OnPropEnumArrayChanged(Obj, InPropEnumArray);
			}
		}

		WeakPtr.Get()->CleanUpSubscribers();
	};

	if (IsInGameThread())
	{
		BroadcastAll();
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, MoveTemp(BroadcastAll));
	}
}

void UTbStructArrayStructArrayFieldInterfacePublisher::BroadcastPropIntArrayChanged(UPARAM(DisplayName = "PropIntArray") const FTbStructArrayStructWithArrayOfInts& InPropIntArray)
{
	TArray<TWeakInterfacePtr<ITbStructArrayStructArrayFieldInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITbStructArrayStructArrayFieldInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	auto BroadcastAll = [WeakPtr = TWeakObjectPtr<UTbStructArrayStructArrayFieldInterfacePublisher>(this), SubscribersCopy, BPSubscribersCopy, InPropIntArray]()
	{
		if (!WeakPtr.IsValid())
		{
			return;
		}

		WeakPtr.Get()->OnPropIntArrayChanged.Broadcast(InPropIntArray);
		for (const TWeakInterfacePtr<ITbStructArrayStructArrayFieldInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (Subscriber.IsValid())
			{
				if (ITbStructArrayStructArrayFieldInterfaceSubscriberInterface* Iface = Subscriber.Get())
				{
					Iface->OnPropIntArrayChanged(InPropIntArray);
				}
			}
		}

		WeakPtr.Get()->OnPropIntArrayChangedBP.Broadcast(InPropIntArray);
		for (const TScriptInterface<ITbStructArrayStructArrayFieldInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbStructArrayStructArrayFieldInterfaceBPSubscriberInterface::Execute_OnPropIntArrayChanged(Obj, InPropIntArray);
			}
		}

		WeakPtr.Get()->CleanUpSubscribers();
	};

	if (IsInGameThread())
	{
		BroadcastAll();
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, MoveTemp(BroadcastAll));
	}
}

void UTbStructArrayStructArrayFieldInterfacePublisher::BroadcastPropMixedChanged(UPARAM(DisplayName = "PropMixed") const FTbStructArrayMixedStruct& InPropMixed)
{
	TArray<TWeakInterfacePtr<ITbStructArrayStructArrayFieldInterfaceSubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	TArray<TScriptInterface<ITbStructArrayStructArrayFieldInterfaceBPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}

	auto BroadcastAll = [WeakPtr = TWeakObjectPtr<UTbStructArrayStructArrayFieldInterfacePublisher>(this), SubscribersCopy, BPSubscribersCopy, InPropMixed]()
	{
		if (!WeakPtr.IsValid())
		{
			return;
		}

		WeakPtr.Get()->OnPropMixedChanged.Broadcast(InPropMixed);
		for (const TWeakInterfacePtr<ITbStructArrayStructArrayFieldInterfaceSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (Subscriber.IsValid())
			{
				if (ITbStructArrayStructArrayFieldInterfaceSubscriberInterface* Iface = Subscriber.Get())
				{
					Iface->OnPropMixedChanged(InPropMixed);
				}
			}
		}

		WeakPtr.Get()->OnPropMixedChangedBP.Broadcast(InPropMixed);
		for (const TScriptInterface<ITbStructArrayStructArrayFieldInterfaceBPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				ITbStructArrayStructArrayFieldInterfaceBPSubscriberInterface::Execute_OnPropMixedChanged(Obj, InPropMixed);
			}
		}

		WeakPtr.Get()->CleanUpSubscribers();
	};

	if (IsInGameThread())
	{
		BroadcastAll();
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, MoveTemp(BroadcastAll));
	}
}

void UTbStructArrayStructArrayFieldInterfacePublisher::Subscribe(const TScriptInterface<ITbStructArrayStructArrayFieldInterfaceBPSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	FWriteScopeLock WriteLock(BPSubscribersLock);
	BPSubscribers.Remove(Subscriber);
	BPSubscribers.Add(Subscriber);
}

void UTbStructArrayStructArrayFieldInterfacePublisher::Subscribe(const TWeakInterfacePtr<ITbStructArrayStructArrayFieldInterfaceSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
	Subscribers.Add(Subscriber);
}

void UTbStructArrayStructArrayFieldInterfacePublisher::Unsubscribe(const TScriptInterface<ITbStructArrayStructArrayFieldInterfaceBPSubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(BPSubscribersLock);
	BPSubscribers.Remove(Subscriber);
}

void UTbStructArrayStructArrayFieldInterfacePublisher::Unsubscribe(const TWeakInterfacePtr<ITbStructArrayStructArrayFieldInterfaceSubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
}

void UTbStructArrayStructArrayFieldInterfacePublisher::CleanUpSubscribers()
{
#if (ENGINE_MAJOR_VERSION >= 5)
	EAllowShrinking AllowShrinking = EAllowShrinking::No;
#else
	bool AllowShrinking = false;
#endif

	{
		FWriteScopeLock WriteLock(SubscribersLock);
		Subscribers.RemoveAllSwap([](const TWeakInterfacePtr<ITbStructArrayStructArrayFieldInterfaceSubscriberInterface>& Subscriber)
			{
			return !Subscriber.IsValid();
		},
			AllowShrinking);
	}
	{
		FWriteScopeLock WriteLock(BPSubscribersLock);
		BPSubscribers.RemoveAllSwap([](const TScriptInterface<ITbStructArrayStructArrayFieldInterfaceBPSubscriberInterface>& Subscriber)
			{
			UObject* Obj = Subscriber.GetObject();
			return !((Obj != nullptr) && IsValid(Obj));
		},
			AllowShrinking);
	}
}
