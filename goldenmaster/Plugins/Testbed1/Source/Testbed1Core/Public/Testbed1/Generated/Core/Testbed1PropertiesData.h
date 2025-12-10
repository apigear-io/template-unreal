
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
#include "Misc/ScopeRWLock.h"
#include "Testbed1/Generated/api/Testbed1_data.h"

/**
	\brief data structure to hold interface property values

	This can be used for caching, e.g. last sent value over the network.

	Simple atomic types are directly exposed for read, write.
	All other properties expose setter, getter functions to wrap thread-safety functionality.
*/
class TESTBED1CORE_API Testbed1StructInterfacePropertiesData
{
public:
	void SetPropBool(const FTestbed1StructBool& InPropBool);
	FTestbed1StructBool GetPropBool() const;
	void SetPropInt(const FTestbed1StructInt& InPropInt);
	FTestbed1StructInt GetPropInt() const;
	void SetPropFloat(const FTestbed1StructFloat& InPropFloat);
	FTestbed1StructFloat GetPropFloat() const;
	void SetPropString(const FTestbed1StructString& InPropString);
	FTestbed1StructString GetPropString() const;

private:
	mutable FRWLock PropBoolLock;
	FTestbed1StructBool PropBool{FTestbed1StructBool()};
	mutable FRWLock PropIntLock;
	FTestbed1StructInt PropInt{FTestbed1StructInt()};
	mutable FRWLock PropFloatLock;
	FTestbed1StructFloat PropFloat{FTestbed1StructFloat()};
	mutable FRWLock PropStringLock;
	FTestbed1StructString PropString{FTestbed1StructString()};
};

/**
	\brief data structure to hold interface property values

	This can be used for caching, e.g. last sent value over the network.

	Simple atomic types are directly exposed for read, write.
	All other properties expose setter, getter functions to wrap thread-safety functionality.
*/
class TESTBED1CORE_API Testbed1StructArrayInterfacePropertiesData
{
public:
	void SetPropBool(const TArray<FTestbed1StructBool>& InPropBool);
	TArray<FTestbed1StructBool> GetPropBool() const;
	void SetPropInt(const TArray<FTestbed1StructInt>& InPropInt);
	TArray<FTestbed1StructInt> GetPropInt() const;
	void SetPropFloat(const TArray<FTestbed1StructFloat>& InPropFloat);
	TArray<FTestbed1StructFloat> GetPropFloat() const;
	void SetPropString(const TArray<FTestbed1StructString>& InPropString);
	TArray<FTestbed1StructString> GetPropString() const;
	void SetPropEnum(const TArray<ETestbed1Enum0>& InPropEnum);
	TArray<ETestbed1Enum0> GetPropEnum() const;

private:
	mutable FRWLock PropBoolLock;
	TArray<FTestbed1StructBool> PropBool{TArray<FTestbed1StructBool>()};
	mutable FRWLock PropIntLock;
	TArray<FTestbed1StructInt> PropInt{TArray<FTestbed1StructInt>()};
	mutable FRWLock PropFloatLock;
	TArray<FTestbed1StructFloat> PropFloat{TArray<FTestbed1StructFloat>()};
	mutable FRWLock PropStringLock;
	TArray<FTestbed1StructString> PropString{TArray<FTestbed1StructString>()};
	mutable FRWLock PropEnumLock;
	TArray<ETestbed1Enum0> PropEnum{TArray<ETestbed1Enum0>()};
};

/**
	\brief data structure to hold interface property values

	This can be used for caching, e.g. last sent value over the network.

	Simple atomic types are directly exposed for read, write.
	All other properties expose setter, getter functions to wrap thread-safety functionality.
*/
class TESTBED1CORE_API Testbed1StructArray2InterfacePropertiesData
{
public:
	void SetPropBool(const FTestbed1StructBoolWithArray& InPropBool);
	FTestbed1StructBoolWithArray GetPropBool() const;
	void SetPropInt(const FTestbed1StructIntWithArray& InPropInt);
	FTestbed1StructIntWithArray GetPropInt() const;
	void SetPropFloat(const FTestbed1StructFloatWithArray& InPropFloat);
	FTestbed1StructFloatWithArray GetPropFloat() const;
	void SetPropString(const FTestbed1StructStringWithArray& InPropString);
	FTestbed1StructStringWithArray GetPropString() const;
	void SetPropEnum(const FTestbed1StructEnumWithArray& InPropEnum);
	FTestbed1StructEnumWithArray GetPropEnum() const;

private:
	mutable FRWLock PropBoolLock;
	FTestbed1StructBoolWithArray PropBool{FTestbed1StructBoolWithArray()};
	mutable FRWLock PropIntLock;
	FTestbed1StructIntWithArray PropInt{FTestbed1StructIntWithArray()};
	mutable FRWLock PropFloatLock;
	FTestbed1StructFloatWithArray PropFloat{FTestbed1StructFloatWithArray()};
	mutable FRWLock PropStringLock;
	FTestbed1StructStringWithArray PropString{FTestbed1StructStringWithArray()};
	mutable FRWLock PropEnumLock;
	FTestbed1StructEnumWithArray PropEnum{FTestbed1StructEnumWithArray()};
};
