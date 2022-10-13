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

#include "TbSame1_data.h"
#include "TbSame1_apig.generated.h"

/**
 * Declaration for SameStruct1Interface
 */
// signal delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame1SameStruct1InterfaceSig1Delegate, const FTbSame1Struct1&, Param1);

// property delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame1SameStruct1InterfaceProp1ChangedDelegate, const FTbSame1Struct1&, Prop1);

/**
 * Interface UTbSame1SameStruct1InterfaceInterface only for Unreal Engine's reflection system
 */
UINTERFACE(Blueprintable, MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UTbSame1SameStruct1InterfaceInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITbSame1SameStruct1InterfaceInterface
 */
class TBSAME1_API ITbSame1SameStruct1InterfaceInterface
{
	GENERATED_BODY()

public:
	// signals
	virtual FTbSame1SameStruct1InterfaceSig1Delegate& GetSig1SignalDelegate() = 0;

	virtual FTbSame1SameStruct1InterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() = 0;

	// methods
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameStruct1Interface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame1Struct1& Result, const FTbSame1Struct1& Param1) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameStruct1Interface")
	virtual FTbSame1Struct1 Func1(const FTbSame1Struct1& Param1) = 0;

	// properties
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameStruct1Interface")
	virtual FTbSame1Struct1 GetProp1() const = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameStruct1Interface")
	virtual void SetProp1(const FTbSame1Struct1& Prop1) = 0;
};
/**
 * Declaration for SameStruct2Interface
 */
// signal delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame1SameStruct2InterfaceSig1Delegate, const FTbSame1Struct1&, Param1);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTbSame1SameStruct2InterfaceSig2Delegate, const FTbSame1Struct1&, Param1, const FTbSame1Struct2&, Param2);

// property delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame1SameStruct2InterfaceProp1ChangedDelegate, const FTbSame1Struct2&, Prop1);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame1SameStruct2InterfaceProp2ChangedDelegate, const FTbSame1Struct2&, Prop2);

/**
 * Interface UTbSame1SameStruct2InterfaceInterface only for Unreal Engine's reflection system
 */
UINTERFACE(Blueprintable, MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UTbSame1SameStruct2InterfaceInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITbSame1SameStruct2InterfaceInterface
 */
class TBSAME1_API ITbSame1SameStruct2InterfaceInterface
{
	GENERATED_BODY()

public:
	// signals
	virtual FTbSame1SameStruct2InterfaceSig1Delegate& GetSig1SignalDelegate() = 0;

	virtual FTbSame1SameStruct2InterfaceSig2Delegate& GetSig2SignalDelegate() = 0;

	virtual FTbSame1SameStruct2InterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() = 0;

	virtual FTbSame1SameStruct2InterfaceProp2ChangedDelegate& GetProp2ChangedDelegate() = 0;

	// methods
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameStruct2Interface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame1Struct1& Result, const FTbSame1Struct1& Param1) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameStruct2Interface")
	virtual FTbSame1Struct1 Func1(const FTbSame1Struct1& Param1) = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameStruct2Interface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void Func2Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame1Struct1& Result, const FTbSame1Struct1& Param1, const FTbSame1Struct2& Param2) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameStruct2Interface")
	virtual FTbSame1Struct1 Func2(const FTbSame1Struct1& Param1, const FTbSame1Struct2& Param2) = 0;

	// properties
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameStruct2Interface")
	virtual FTbSame1Struct2 GetProp1() const = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameStruct2Interface")
	virtual void SetProp1(const FTbSame1Struct2& Prop1) = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameStruct2Interface")
	virtual FTbSame1Struct2 GetProp2() const = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameStruct2Interface")
	virtual void SetProp2(const FTbSame1Struct2& Prop2) = 0;
};
/**
 * Declaration for SameEnum1Interface
 */
// signal delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame1SameEnum1InterfaceSig1Delegate, const ETbSame1Enum1&, Param1);

// property delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame1SameEnum1InterfaceProp1ChangedDelegate, const ETbSame1Enum1&, Prop1);

/**
 * Interface UTbSame1SameEnum1InterfaceInterface only for Unreal Engine's reflection system
 */
UINTERFACE(Blueprintable, MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UTbSame1SameEnum1InterfaceInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITbSame1SameEnum1InterfaceInterface
 */
class TBSAME1_API ITbSame1SameEnum1InterfaceInterface
{
	GENERATED_BODY()

public:
	// signals
	virtual FTbSame1SameEnum1InterfaceSig1Delegate& GetSig1SignalDelegate() = 0;

	virtual FTbSame1SameEnum1InterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() = 0;

	// methods
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum1Interface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame1Enum1& Result, const ETbSame1Enum1& Param1) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum1Interface")
	virtual ETbSame1Enum1 Func1(const ETbSame1Enum1& Param1) = 0;

	// properties
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum1Interface")
	virtual ETbSame1Enum1 GetProp1() const = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum1Interface")
	virtual void SetProp1(const ETbSame1Enum1& Prop1) = 0;
};
/**
 * Declaration for SameEnum2Interface
 */
// signal delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame1SameEnum2InterfaceSig1Delegate, const ETbSame1Enum1&, Param1);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTbSame1SameEnum2InterfaceSig2Delegate, const ETbSame1Enum1&, Param1, const ETbSame1Enum2&, Param2);

// property delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame1SameEnum2InterfaceProp1ChangedDelegate, const ETbSame1Enum1&, Prop1);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame1SameEnum2InterfaceProp2ChangedDelegate, const ETbSame1Enum2&, Prop2);

/**
 * Interface UTbSame1SameEnum2InterfaceInterface only for Unreal Engine's reflection system
 */
UINTERFACE(Blueprintable, MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UTbSame1SameEnum2InterfaceInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITbSame1SameEnum2InterfaceInterface
 */
class TBSAME1_API ITbSame1SameEnum2InterfaceInterface
{
	GENERATED_BODY()

public:
	// signals
	virtual FTbSame1SameEnum2InterfaceSig1Delegate& GetSig1SignalDelegate() = 0;

	virtual FTbSame1SameEnum2InterfaceSig2Delegate& GetSig2SignalDelegate() = 0;

	virtual FTbSame1SameEnum2InterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() = 0;

	virtual FTbSame1SameEnum2InterfaceProp2ChangedDelegate& GetProp2ChangedDelegate() = 0;

	// methods
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum2Interface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame1Enum1& Result, const ETbSame1Enum1& Param1) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum2Interface")
	virtual ETbSame1Enum1 Func1(const ETbSame1Enum1& Param1) = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum2Interface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void Func2Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame1Enum1& Result, const ETbSame1Enum1& Param1, const ETbSame1Enum2& Param2) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum2Interface")
	virtual ETbSame1Enum1 Func2(const ETbSame1Enum1& Param1, const ETbSame1Enum2& Param2) = 0;

	// properties
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum2Interface")
	virtual ETbSame1Enum1 GetProp1() const = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum2Interface")
	virtual void SetProp1(const ETbSame1Enum1& Prop1) = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum2Interface")
	virtual ETbSame1Enum2 GetProp2() const = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum2Interface")
	virtual void SetProp2(const ETbSame1Enum2& Prop2) = 0;
};
