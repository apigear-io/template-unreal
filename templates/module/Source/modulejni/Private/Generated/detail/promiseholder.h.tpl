{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/

{{- $API_MACRO := printf "%sJNI_API" (CAMEL .Module.Name) }}
#pragma once

#include "Async/Future.h"
#include "Templates/Function.h"
#include "Templates/UniquePtr.h"

class {{$API_MACRO}} I{{Camel .Module.Name}}PromiseHolder
{
public:
	virtual ~I{{Camel .Module.Name}}PromiseHolder() = default;

	virtual void FulfillWithDefaultValue();
};

template <typename ResultType>
class {{$API_MACRO}} T{{Camel .Module.Name}}PromiseHolder : public I{{Camel .Module.Name}}PromiseHolder
{
public:
	explicit T{{Camel .Module.Name}}PromiseHolder(TPromise<ResultType>&& InPromise);
	~T{{Camel .Module.Name}}PromiseHolder() override;

	void FulfillWithDefaultValue() override;

	void VisitPromise(const TFunction<void(TPromise<ResultType>&)>& InVisitorFunc);

private:
	TUniquePtr<TPromise<ResultType>> Promise;
};

template <typename ResultType>
T{{Camel .Module.Name}}PromiseHolder<ResultType>::T{{Camel .Module.Name}}PromiseHolder(TPromise<ResultType>&& InPromise)
	: Promise(MakeUnique<TPromise<ResultType>>(MoveTemp(InPromise)))
{
}

template <typename ResultType>
T{{Camel .Module.Name}}PromiseHolder<ResultType>::~T{{Camel .Module.Name}}PromiseHolder() = default;

template <typename ResultType>
void T{{Camel .Module.Name}}PromiseHolder<ResultType>::VisitPromise(const TFunction<void(TPromise<ResultType>&)>& InVisitorFunc)
{
	InVisitorFunc(*Promise);
}

template <typename ResultType>
void T{{Camel .Module.Name}}PromiseHolder<ResultType>::FulfillWithDefaultValue()
{
	ResultType DefaultValue;
	Promise->SetValue(DefaultValue);
}
