
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
#include "HAL/CriticalSection.h"
#include "TbSimple/Generated/api/TbSimple_data.h"

/**
	\brief data structure to hold interface property values

	This can be used for caching, e.g. last sent value over the network.

	Simple atomic types are directly exposed for read, write.
	All other properties expose setter, getter functions to wrap thread-safety functionality.
*/
class TBSIMPLECORE_API TbSimpleSimpleInterfacePropertiesData
{
public:
	std::atomic<bool> bPropBool{false};
	std::atomic<int32> PropInt{0};
	std::atomic<int32> PropInt32{0};
	std::atomic<int64> PropInt64{0LL};
	std::atomic<float> PropFloat{0.0f};
	std::atomic<float> PropFloat32{0.0f};
	std::atomic<double> PropFloat64{0.0};
	void SetPropString(const FString& InPropString);
	FString GetPropString() const;

private:
	mutable FCriticalSection PropStringCS;
	FString PropString{FString()};
};

/**
	\brief data structure to hold interface property values

	This can be used for caching, e.g. last sent value over the network.

	Simple atomic types are directly exposed for read, write.
	All other properties expose setter, getter functions to wrap thread-safety functionality.
*/
class TBSIMPLECORE_API TbSimpleSimpleArrayInterfacePropertiesData
{
public:
	void SetPropBool(const TArray<bool>& InPropBool);
	TArray<bool> GetPropBool() const;
	void SetPropInt(const TArray<int32>& InPropInt);
	TArray<int32> GetPropInt() const;
	void SetPropInt32(const TArray<int32>& InPropInt32);
	TArray<int32> GetPropInt32() const;
	void SetPropInt64(const TArray<int64>& InPropInt64);
	TArray<int64> GetPropInt64() const;
	void SetPropFloat(const TArray<float>& InPropFloat);
	TArray<float> GetPropFloat() const;
	void SetPropFloat32(const TArray<float>& InPropFloat32);
	TArray<float> GetPropFloat32() const;
	void SetPropFloat64(const TArray<double>& InPropFloat64);
	TArray<double> GetPropFloat64() const;
	void SetPropString(const TArray<FString>& InPropString);
	TArray<FString> GetPropString() const;
	void SetPropReadOnlyString(const FString& InPropReadOnlyString);
	FString GetPropReadOnlyString() const;

private:
	mutable FCriticalSection PropBoolCS;
	TArray<bool> PropBool{TArray<bool>()};
	mutable FCriticalSection PropIntCS;
	TArray<int32> PropInt{TArray<int32>()};
	mutable FCriticalSection PropInt32CS;
	TArray<int32> PropInt32{TArray<int32>()};
	mutable FCriticalSection PropInt64CS;
	TArray<int64> PropInt64{TArray<int64>()};
	mutable FCriticalSection PropFloatCS;
	TArray<float> PropFloat{TArray<float>()};
	mutable FCriticalSection PropFloat32CS;
	TArray<float> PropFloat32{TArray<float>()};
	mutable FCriticalSection PropFloat64CS;
	TArray<double> PropFloat64{TArray<double>()};
	mutable FCriticalSection PropStringCS;
	TArray<FString> PropString{TArray<FString>()};
	mutable FCriticalSection PropReadOnlyStringCS;
	FString PropReadOnlyString{FString()};
};

/**
	\brief data structure to hold interface property values

	This can be used for caching, e.g. last sent value over the network.

	Simple atomic types are directly exposed for read, write.
	All other properties expose setter, getter functions to wrap thread-safety functionality.
*/
class TBSIMPLECORE_API TbSimpleNoOperationsInterfacePropertiesData
{
public:
	std::atomic<bool> bPropBool{false};
	std::atomic<int32> PropInt{0};

private:
};

/**
	\brief data structure to hold interface property values

	This can be used for caching, e.g. last sent value over the network.

	Simple atomic types are directly exposed for read, write.
	All other properties expose setter, getter functions to wrap thread-safety functionality.
*/
class TBSIMPLECORE_API TbSimpleNoSignalsInterfacePropertiesData
{
public:
	std::atomic<bool> bPropBool{false};
	std::atomic<int32> PropInt{0};

private:
};
