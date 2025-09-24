{{/* Copyright Epic Games, Inc. All Rights Reserved */}}
{{- $API_MACRO := printf "%sAPI_API" (CAMEL .Module.Name) }}
{{- $ModuleName := Camel .Module.Name -}}

{{- $Class := printf "%s%s" $ModuleName (Camel .Interface.Name) }}
{{- $Category := printf "ApiGear|%s|%s" $ModuleName (Camel .Interface.Name) }}
{{- $class := printf "U%sInterface" $Class }}
{{- $Iface := printf "%s%s" $ModuleName (Camel .Interface.Name) }}
{{- template "get_referenced_interfaces_includes" . }}
#include "{{$ModuleName}}/Generated/api/{{$Class}}Interface.h"
#include "Async/Async.h"
#include "Async/TaskGraphInterfaces.h"
{{- with .Interface }}
{{- if or (len .Properties) (len .Signals) }}{{- nl }}{{ end }}

{{- range $i, $e := .Signals }}
	{{- if $i }}{{nl}}{{ end }}
void U{{$Class}}Publisher::Broadcast{{Camel .Name}}Signal({{ueParams "" .Params}})
{
	On{{Camel .Name}}Signal.Broadcast({{ueVars "" .Params}});
	TArray<TWeakInterfacePtr<I{{$Class}}SubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<I{{$Class}}SubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (I{{$Class}}SubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->On{{Camel .Name}}Signal({{ueVars "" .Params}});
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<I{{$Class}}BPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		On{{Camel .Name}}SignalBP.Broadcast({{ueVars "" .Params}});

		for (const TScriptInterface<I{{$Class}}BPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				I{{$Class}}BPSubscriberInterface::Execute_On{{Camel .Name}}Signal(Obj{{- if (len .Params) }}, {{ end }}{{ueVars "" .Params}});
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<U{{$Class}}Publisher>(this), BPSubscribersCopy{{- if (len .Params) }}, {{ end }}{{ueVars "" .Params}}]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->On{{Camel .Name}}SignalBP.Broadcast({{ueVars "" .Params}});
			}

			for (const TScriptInterface<I{{$Class}}BPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					I{{$Class}}BPSubscriberInterface::Execute_On{{Camel .Name}}Signal(Obj{{- if (len .Params) }}, {{ end }}{{ueVars "" .Params}});
				}
				else
				{
					if (WeakPtr.IsValid())
					{
						WeakPtr.Get()->Unsubscribe(Subscriber);
					}
				}
			}
		});
	}
}
{{- end }}
{{- if and (len .Properties) (len .Signals) }}{{ nl }}{{ end }}
{{- range $i, $e := .Properties }}
{{- if $i }}{{nl}}{{ end }}
void U{{$Class}}Publisher::Broadcast{{Camel .Name}}Changed(UPARAM(DisplayName = "{{ueVar "" .}}") {{ueParam "In" .}})
{
	On{{Camel .Name}}Changed.Broadcast({{ueVar "In" .}});
	TArray<TWeakInterfacePtr<I{{$Class}}SubscriberInterface>> SubscribersCopy;
	{
		FReadScopeLock ReadLock(SubscribersLock);
		SubscribersCopy = Subscribers;
	}
	for (const TWeakInterfacePtr<I{{$Class}}SubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (I{{$Class}}SubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->On{{Camel .Name}}Changed({{ueVar "In" .}});
			}
		}
		else
		{
			Unsubscribe(Subscriber);
		}
	}

	TArray<TScriptInterface<I{{$Class}}BPSubscriberInterface>> BPSubscribersCopy;
	{
		FReadScopeLock ReadLock(BPSubscribersLock);
		BPSubscribersCopy = BPSubscribers;
	}
	if (IsInGameThread())
	{
		On{{Camel .Name}}ChangedBP.Broadcast({{ueVar "In" .}});

		for (const TScriptInterface<I{{$Class}}BPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				I{{$Class}}BPSubscriberInterface::Execute_On{{Camel .Name}}Changed(Obj, {{ueVar "In" .}});
			}
			else
			{
				Unsubscribe(Subscriber);
			}
		}
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakPtr = TWeakObjectPtr<U{{$Class}}Publisher>(this), BPSubscribersCopy, {{ueVar "In" .}}]()
			{
			if (WeakPtr.IsValid())
			{
				WeakPtr.Get()->On{{Camel .Name}}ChangedBP.Broadcast({{ueVar "In" .}});
			}

			for (const TScriptInterface<I{{$Class}}BPSubscriberInterface>& Subscriber : BPSubscribersCopy)
			{
				if (UObject* Obj = Subscriber.GetObject())
				{
					I{{$Class}}BPSubscriberInterface::Execute_On{{Camel .Name}}Changed(Obj, {{ueVar "In" .}});
				}
				else
				{
					if (WeakPtr.IsValid())
					{
						WeakPtr.Get()->Unsubscribe(Subscriber);
					}
				}
			}
		});
	}
}
{{- end }}

void U{{$Class}}Publisher::Subscribe(const TScriptInterface<I{{$Class}}BPSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	FWriteScopeLock WriteLock(BPSubscribersLock);
	BPSubscribers.Remove(Subscriber);
	BPSubscribers.Add(Subscriber);
}

void U{{$Class}}Publisher::Subscribe(const TWeakInterfacePtr<I{{$Class}}SubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
	Subscribers.Add(Subscriber);
}

void U{{$Class}}Publisher::Unsubscribe(const TScriptInterface<I{{$Class}}BPSubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(BPSubscribersLock);
	BPSubscribers.Remove(Subscriber);
}

void U{{$Class}}Publisher::Unsubscribe(const TWeakInterfacePtr<I{{$Class}}SubscriberInterface>& Subscriber)
{
	FWriteScopeLock WriteLock(SubscribersLock);
	Subscribers.Remove(Subscriber);
}
{{- end }}
