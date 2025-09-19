
#include "Counter/Generated/api/CounterCounterInterface.h"
void UCounterCounterPublisher::BroadcastValueChangedSignal(const FCustomTypesVector3D& Vector, const FVector& ExternVector, const TArray<FCustomTypesVector3D>& VectorArray, const TArray<FVector>& ExternVectorArray)
{
	OnValueChangedSignal.Broadcast(Vector, ExternVector, VectorArray, ExternVectorArray);
	OnValueChangedSignalBP.Broadcast(Vector, ExternVector, VectorArray, ExternVectorArray);

	TArray<TScriptInterface<ICounterCounterBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ICounterCounterBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ICounterCounterBPSubscriberInterface::Execute_OnValueChangedSignal(Obj, Vector, ExternVector, VectorArray, ExternVectorArray);
		}
	}
}

void UCounterCounterPublisher::BroadcastVectorChanged(UPARAM(DisplayName = "Vector") const FCustomTypesVector3D& InVector)
{
	OnVectorChanged.Broadcast(InVector);
	OnVectorChangedBP.Broadcast(InVector);

	TArray<TScriptInterface<ICounterCounterBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ICounterCounterBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ICounterCounterBPSubscriberInterface::Execute_OnVectorChanged(Obj, InVector);
		}
	}
}

void UCounterCounterPublisher::BroadcastExternVectorChanged(UPARAM(DisplayName = "ExternVector") const FVector& InExternVector)
{
	OnExternVectorChanged.Broadcast(InExternVector);
	OnExternVectorChangedBP.Broadcast(InExternVector);

	TArray<TScriptInterface<ICounterCounterBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ICounterCounterBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ICounterCounterBPSubscriberInterface::Execute_OnExternVectorChanged(Obj, InExternVector);
		}
	}
}

void UCounterCounterPublisher::BroadcastVectorArrayChanged(UPARAM(DisplayName = "VectorArray") const TArray<FCustomTypesVector3D>& InVectorArray)
{
	OnVectorArrayChanged.Broadcast(InVectorArray);
	OnVectorArrayChangedBP.Broadcast(InVectorArray);

	TArray<TScriptInterface<ICounterCounterBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ICounterCounterBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ICounterCounterBPSubscriberInterface::Execute_OnVectorArrayChanged(Obj, InVectorArray);
		}
	}
}

void UCounterCounterPublisher::BroadcastExternVectorArrayChanged(UPARAM(DisplayName = "ExternVectorArray") const TArray<FVector>& InExternVectorArray)
{
	OnExternVectorArrayChanged.Broadcast(InExternVectorArray);
	OnExternVectorArrayChangedBP.Broadcast(InExternVectorArray);

	TArray<TScriptInterface<ICounterCounterBPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<ICounterCounterBPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			ICounterCounterBPSubscriberInterface::Execute_OnExternVectorArrayChanged(Obj, InExternVectorArray);
		}
	}
}

void UCounterCounterPublisher::Subscribe(const TScriptInterface<ICounterCounterBPSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	Subscribers.Remove(Subscriber);
	Subscribers.Add(Subscriber);
}

void UCounterCounterPublisher::Unsubscribe(const TScriptInterface<ICounterCounterBPSubscriberInterface>& Subscriber)
{
	Subscribers.Remove(Subscriber);
}
