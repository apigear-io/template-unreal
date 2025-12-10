
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
#include <atomic>
#include "Misc/ScopeRWLock.h"
#include "Testbed2/Generated/api/Testbed2_data.h"

/**
	\brief data structure to hold interface property values

	This can be used for caching, e.g. last sent value over the network.

	Simple atomic types are directly exposed for read, write.
	All other properties expose setter, getter functions to wrap thread-safety functionality.
*/
class TESTBED2CORE_API Testbed2ManyParamInterfacePropertiesData
{
public:
	std::atomic<int32> Prop1{0};
	std::atomic<int32> Prop2{0};
	std::atomic<int32> Prop3{0};
	std::atomic<int32> Prop4{0};

private:
};

/**
	\brief data structure to hold interface property values

	This can be used for caching, e.g. last sent value over the network.

	Simple atomic types are directly exposed for read, write.
	All other properties expose setter, getter functions to wrap thread-safety functionality.
*/
class TESTBED2CORE_API Testbed2NestedStruct1InterfacePropertiesData
{
public:
	void SetProp1(const FTestbed2NestedStruct1& InProp1);
	FTestbed2NestedStruct1 GetProp1() const;

private:
	mutable FRWLock Prop1Lock;
	FTestbed2NestedStruct1 Prop1{FTestbed2NestedStruct1()};
};

/**
	\brief data structure to hold interface property values

	This can be used for caching, e.g. last sent value over the network.

	Simple atomic types are directly exposed for read, write.
	All other properties expose setter, getter functions to wrap thread-safety functionality.
*/
class TESTBED2CORE_API Testbed2NestedStruct2InterfacePropertiesData
{
public:
	void SetProp1(const FTestbed2NestedStruct1& InProp1);
	FTestbed2NestedStruct1 GetProp1() const;
	void SetProp2(const FTestbed2NestedStruct2& InProp2);
	FTestbed2NestedStruct2 GetProp2() const;

private:
	mutable FRWLock Prop1Lock;
	FTestbed2NestedStruct1 Prop1{FTestbed2NestedStruct1()};
	mutable FRWLock Prop2Lock;
	FTestbed2NestedStruct2 Prop2{FTestbed2NestedStruct2()};
};

/**
	\brief data structure to hold interface property values

	This can be used for caching, e.g. last sent value over the network.

	Simple atomic types are directly exposed for read, write.
	All other properties expose setter, getter functions to wrap thread-safety functionality.
*/
class TESTBED2CORE_API Testbed2NestedStruct3InterfacePropertiesData
{
public:
	void SetProp1(const FTestbed2NestedStruct1& InProp1);
	FTestbed2NestedStruct1 GetProp1() const;
	void SetProp2(const FTestbed2NestedStruct2& InProp2);
	FTestbed2NestedStruct2 GetProp2() const;
	void SetProp3(const FTestbed2NestedStruct3& InProp3);
	FTestbed2NestedStruct3 GetProp3() const;

private:
	mutable FRWLock Prop1Lock;
	FTestbed2NestedStruct1 Prop1{FTestbed2NestedStruct1()};
	mutable FRWLock Prop2Lock;
	FTestbed2NestedStruct2 Prop2{FTestbed2NestedStruct2()};
	mutable FRWLock Prop3Lock;
	FTestbed2NestedStruct3 Prop3{FTestbed2NestedStruct3()};
};
