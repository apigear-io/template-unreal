
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
#include "TbSame2/Generated/api/TbSame2_data.h"

/**
	\brief data structure to hold interface property values

	This can be used for caching, e.g. last sent value over the network.

	Simple atomic types are directly exposed for read, write.
	All other properties expose setter, getter functions to wrap thread-safety functionality.
*/
class TBSAME2CORE_API TbSame2SameStruct1InterfacePropertiesData
{
public:
	void SetProp1(const FTbSame2Struct1& InProp1);
	FTbSame2Struct1 GetProp1() const;

private:
	mutable FRWLock Prop1Lock;
	FTbSame2Struct1 Prop1{FTbSame2Struct1()};
};

/**
	\brief data structure to hold interface property values

	This can be used for caching, e.g. last sent value over the network.

	Simple atomic types are directly exposed for read, write.
	All other properties expose setter, getter functions to wrap thread-safety functionality.
*/
class TBSAME2CORE_API TbSame2SameStruct2InterfacePropertiesData
{
public:
	void SetProp1(const FTbSame2Struct2& InProp1);
	FTbSame2Struct2 GetProp1() const;
	void SetProp2(const FTbSame2Struct2& InProp2);
	FTbSame2Struct2 GetProp2() const;

private:
	mutable FRWLock Prop1Lock;
	FTbSame2Struct2 Prop1{FTbSame2Struct2()};
	mutable FRWLock Prop2Lock;
	FTbSame2Struct2 Prop2{FTbSame2Struct2()};
};

/**
	\brief data structure to hold interface property values

	This can be used for caching, e.g. last sent value over the network.

	Simple atomic types are directly exposed for read, write.
	All other properties expose setter, getter functions to wrap thread-safety functionality.
*/
class TBSAME2CORE_API TbSame2SameEnum1InterfacePropertiesData
{
public:
	std::atomic<ETbSame2Enum1> Prop1{ETbSame2Enum1::TS2E1_Value1};

private:
};

/**
	\brief data structure to hold interface property values

	This can be used for caching, e.g. last sent value over the network.

	Simple atomic types are directly exposed for read, write.
	All other properties expose setter, getter functions to wrap thread-safety functionality.
*/
class TBSAME2CORE_API TbSame2SameEnum2InterfacePropertiesData
{
public:
	std::atomic<ETbSame2Enum1> Prop1{ETbSame2Enum1::TS2E1_Value1};
	std::atomic<ETbSame2Enum2> Prop2{ETbSame2Enum2::TS2E2_Value1};

private:
};
