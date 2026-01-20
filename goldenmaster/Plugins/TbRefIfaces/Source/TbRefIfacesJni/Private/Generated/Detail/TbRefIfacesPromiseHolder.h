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

class TBREFIFACESJNI_API ITbRefIfacesPromiseHolder
{
public:
	virtual ~ITbRefIfacesPromiseHolder() = default;

	virtual void FulfillWithDefaultValue();
};

template <typename ResultType>
class TBREFIFACESJNI_API TTbRefIfacesPromiseHolder : public ITbRefIfacesPromiseHolder
{
public:
	explicit TTbRefIfacesPromiseHolder(TPromise<ResultType>&& InPromise);
	~TTbRefIfacesPromiseHolder() override;

	void FulfillWithDefaultValue() override;

	void VisitPromise(const TFunction<void(TPromise<ResultType>&)>& InVisitorFunc);

private:
	TUniquePtr<TPromise<ResultType>> Promise;
};

template <typename ResultType>
TTbRefIfacesPromiseHolder<ResultType>::TTbRefIfacesPromiseHolder(TPromise<ResultType>&& InPromise)
    : Promise(MakeUnique<TPromise<ResultType>>(MoveTemp(InPromise)))
{
}

template <typename ResultType>
TTbRefIfacesPromiseHolder<ResultType>::~TTbRefIfacesPromiseHolder() = default;

template <typename ResultType>
void TTbRefIfacesPromiseHolder<ResultType>::VisitPromise(const TFunction<void(TPromise<ResultType>&)>& InVisitorFunc)
{
    InVisitorFunc(*Promise);
}

template <typename ResultType>
void TTbRefIfacesPromiseHolder<ResultType>::FulfillWithDefaultValue()
{
	ResultType DefaultValue;
	Promise->SetValue(DefaultValue);
}
