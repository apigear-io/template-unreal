/**
Copyright 2021 ApiGear UG
Copyright 2021 Epic Games, Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
#pragma once

#include "Async/Future.h"
#include "Templates/Function.h"
#include "Templates/UniquePtr.h"

class TBSIMPLEJNI_API ITbSimplePromiseHolder
{
public:
	virtual ~ITbSimplePromiseHolder() = default;

	virtual void FulfillWithDefaultValue();
};

template <typename ResultType>
class TBSIMPLEJNI_API TTbSimplePromiseHolder : public ITbSimplePromiseHolder
{
public:
	explicit TTbSimplePromiseHolder(TPromise<ResultType>&& InPromise);
	~TTbSimplePromiseHolder() override;

	void FulfillWithDefaultValue() override;

	void VisitPromise(const TFunction<void(TPromise<ResultType>&)>& InVisitorFunc);

private:
	TUniquePtr<TPromise<ResultType>> Promise;
};

template <typename ResultType>
TTbSimplePromiseHolder<ResultType>::TTbSimplePromiseHolder(TPromise<ResultType>&& InPromise)
	: Promise(MakeUnique<TPromise<ResultType>>(MoveTemp(InPromise)))
{
}

template <typename ResultType>
TTbSimplePromiseHolder<ResultType>::~TTbSimplePromiseHolder() = default;

template <typename ResultType>
void TTbSimplePromiseHolder<ResultType>::VisitPromise(const TFunction<void(TPromise<ResultType>&)>& InVisitorFunc)
{
	InVisitorFunc(*Promise);
}

template <typename ResultType>
void TTbSimplePromiseHolder<ResultType>::FulfillWithDefaultValue()
{
	ResultType DefaultValue;
	Promise->SetValue(DefaultValue);
}
