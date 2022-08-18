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

#include <cinttypes>
#include <string>
#include <list>
#include "UObject/Interface.h"

#include "TbSame2_data.h"
#include "TbSame2_apig.generated.h"

/**
 * Declaration for SameStruct1Interface
 */
// signal delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame2SameStruct1InterfaceSig1Delegate, const FTbSame2Struct1&, Param1);

// property delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame2SameStruct1InterfaceProp1ChangedDelegate, const FTbSame2Struct1&, Prop1);

/**
 * Interface UTbSame2SameStruct1InterfaceInterface only for Unreal Engine's reflection system
 */
UINTERFACE(MinimalAPI)
class UTbSame2SameStruct1InterfaceInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITbSame2SameStruct1InterfaceInterface
 */
class TBSAME2_API ITbSame2SameStruct1InterfaceInterface
{
	GENERATED_BODY()

public:
	// signals
	virtual FTbSame2SameStruct1InterfaceSig1Delegate& GetSig1SignalDelegate() = 0;

	virtual FTbSame2SameStruct1InterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() = 0;

	// methods
	virtual FTbSame2Struct1 Func1(const FTbSame2Struct1& Param1) = 0;
	// properties
	virtual FTbSame2Struct1 GetProp1() const = 0;
	virtual void SetProp1(const FTbSame2Struct1& Prop1) = 0;
};
/**
 * Declaration for SameStruct2Interface
 */
// signal delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame2SameStruct2InterfaceSig1Delegate, const FTbSame2Struct1&, Param1);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTbSame2SameStruct2InterfaceSig2Delegate, const FTbSame2Struct1&, Param1, const FTbSame2Struct2&, Param2);

// property delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame2SameStruct2InterfaceProp1ChangedDelegate, const FTbSame2Struct2&, Prop1);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame2SameStruct2InterfaceProp2ChangedDelegate, const FTbSame2Struct2&, Prop2);

/**
 * Interface UTbSame2SameStruct2InterfaceInterface only for Unreal Engine's reflection system
 */
UINTERFACE(MinimalAPI)
class UTbSame2SameStruct2InterfaceInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITbSame2SameStruct2InterfaceInterface
 */
class TBSAME2_API ITbSame2SameStruct2InterfaceInterface
{
	GENERATED_BODY()

public:
	// signals
	virtual FTbSame2SameStruct2InterfaceSig1Delegate& GetSig1SignalDelegate() = 0;

	virtual FTbSame2SameStruct2InterfaceSig2Delegate& GetSig2SignalDelegate() = 0;

	virtual FTbSame2SameStruct2InterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() = 0;

	virtual FTbSame2SameStruct2InterfaceProp2ChangedDelegate& GetProp2ChangedDelegate() = 0;

	// methods
	virtual FTbSame2Struct1 Func1(const FTbSame2Struct1& Param1) = 0;
	virtual FTbSame2Struct1 Func2(const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2) = 0;
	// properties
	virtual FTbSame2Struct2 GetProp1() const = 0;
	virtual void SetProp1(const FTbSame2Struct2& Prop1) = 0;
	virtual FTbSame2Struct2 GetProp2() const = 0;
	virtual void SetProp2(const FTbSame2Struct2& Prop2) = 0;
};
/**
 * Declaration for SameEnum1Interface
 */
// signal delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame2SameEnum1InterfaceSig1Delegate, const ETbSame2Enum1&, Param1);

// property delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame2SameEnum1InterfaceProp1ChangedDelegate, const ETbSame2Enum1&, Prop1);

/**
 * Interface UTbSame2SameEnum1InterfaceInterface only for Unreal Engine's reflection system
 */
UINTERFACE(MinimalAPI)
class UTbSame2SameEnum1InterfaceInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITbSame2SameEnum1InterfaceInterface
 */
class TBSAME2_API ITbSame2SameEnum1InterfaceInterface
{
	GENERATED_BODY()

public:
	// signals
	virtual FTbSame2SameEnum1InterfaceSig1Delegate& GetSig1SignalDelegate() = 0;

	virtual FTbSame2SameEnum1InterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() = 0;

	// methods
	virtual ETbSame2Enum1 Func1(const ETbSame2Enum1& Param1) = 0;
	// properties
	virtual ETbSame2Enum1 GetProp1() const = 0;
	virtual void SetProp1(const ETbSame2Enum1& Prop1) = 0;
};
/**
 * Declaration for SameEnum2Interface
 */
// signal delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame2SameEnum2InterfaceSig1Delegate, const ETbSame2Enum1&, Param1);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTbSame2SameEnum2InterfaceSig2Delegate, const ETbSame2Enum1&, Param1, const ETbSame2Enum2&, Param2);

// property delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame2SameEnum2InterfaceProp1ChangedDelegate, const ETbSame2Enum1&, Prop1);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame2SameEnum2InterfaceProp2ChangedDelegate, const ETbSame2Enum2&, Prop2);

/**
 * Interface UTbSame2SameEnum2InterfaceInterface only for Unreal Engine's reflection system
 */
UINTERFACE(MinimalAPI)
class UTbSame2SameEnum2InterfaceInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITbSame2SameEnum2InterfaceInterface
 */
class TBSAME2_API ITbSame2SameEnum2InterfaceInterface
{
	GENERATED_BODY()

public:
	// signals
	virtual FTbSame2SameEnum2InterfaceSig1Delegate& GetSig1SignalDelegate() = 0;

	virtual FTbSame2SameEnum2InterfaceSig2Delegate& GetSig2SignalDelegate() = 0;

	virtual FTbSame2SameEnum2InterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() = 0;

	virtual FTbSame2SameEnum2InterfaceProp2ChangedDelegate& GetProp2ChangedDelegate() = 0;

	// methods
	virtual ETbSame2Enum1 Func1(const ETbSame2Enum1& Param1) = 0;
	virtual ETbSame2Enum1 Func2(const ETbSame2Enum1& Param1, const ETbSame2Enum2& Param2) = 0;
	// properties
	virtual ETbSame2Enum1 GetProp1() const = 0;
	virtual void SetProp1(const ETbSame2Enum1& Prop1) = 0;
	virtual ETbSame2Enum2 GetProp2() const = 0;
	virtual void SetProp2(const ETbSame2Enum2& Prop2) = 0;
};