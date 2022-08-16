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

#include "Testbed2_data.h"
#include "Testbed2_apig.generated.h"

/**
 * Declaration for ManyParamInterface
 */
// signal delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2ManyParamInterfaceSig1Delegate, int32, Param1);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTestbed2ManyParamInterfaceSig2Delegate, int32, Param1, int32, Param2);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FTestbed2ManyParamInterfaceSig3Delegate, int32, Param1, int32, Param2, int32, Param3);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FTestbed2ManyParamInterfaceSig4Delegate, int32, Param1, int32, Param2, int32, Param3, int32, Param4);

// property delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2ManyParamInterfaceProp1ChangedDelegate, int32, Prop1);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2ManyParamInterfaceProp2ChangedDelegate, int32, Prop2);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2ManyParamInterfaceProp3ChangedDelegate, int32, Prop3);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2ManyParamInterfaceProp4ChangedDelegate, int32, Prop4);

/**
 * Interface UTestbed2ManyParamInterfaceInterface only for Unreal Engine's reflection system
 */
UINTERFACE(MinimalAPI)
class UTestbed2ManyParamInterfaceInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITestbed2ManyParamInterfaceInterface
 */
class TESTBED2_API ITestbed2ManyParamInterfaceInterface
{
	GENERATED_BODY()

public:
	// signals
	virtual FTestbed2ManyParamInterfaceSig1Delegate& GetSig1SignalDelegate() = 0;

	virtual FTestbed2ManyParamInterfaceSig2Delegate& GetSig2SignalDelegate() = 0;

	virtual FTestbed2ManyParamInterfaceSig3Delegate& GetSig3SignalDelegate() = 0;

	virtual FTestbed2ManyParamInterfaceSig4Delegate& GetSig4SignalDelegate() = 0;

	virtual FTestbed2ManyParamInterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() = 0;

	virtual FTestbed2ManyParamInterfaceProp2ChangedDelegate& GetProp2ChangedDelegate() = 0;

	virtual FTestbed2ManyParamInterfaceProp3ChangedDelegate& GetProp3ChangedDelegate() = 0;

	virtual FTestbed2ManyParamInterfaceProp4ChangedDelegate& GetProp4ChangedDelegate() = 0;

	// methods
	virtual int32 Func1(int32 Param1) = 0;
	virtual int32 Func2(int32 Param1, int32 Param2) = 0;
	virtual int32 Func3(int32 Param1, int32 Param2, int32 Param3) = 0;
	virtual int32 Func4(int32 Param1, int32 Param2, int32 Param3, int32 Param4) = 0;
	// properties
	virtual int32 GetProp1() const = 0;
	virtual void SetProp1(int32 Prop1) = 0;
	virtual int32 GetProp2() const = 0;
	virtual void SetProp2(int32 Prop2) = 0;
	virtual int32 GetProp3() const = 0;
	virtual void SetProp3(int32 Prop3) = 0;
	virtual int32 GetProp4() const = 0;
	virtual void SetProp4(int32 Prop4) = 0;
};
/**
 * Declaration for NestedStruct1Interface
 */
// signal delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2NestedStruct1InterfaceSig1Delegate, const FTestbed2NestedStruct1&, Param1);

// property delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2NestedStruct1InterfaceProp1ChangedDelegate, const FTestbed2NestedStruct1&, Prop1);

/**
 * Interface UTestbed2NestedStruct1InterfaceInterface only for Unreal Engine's reflection system
 */
UINTERFACE(MinimalAPI)
class UTestbed2NestedStruct1InterfaceInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITestbed2NestedStruct1InterfaceInterface
 */
class TESTBED2_API ITestbed2NestedStruct1InterfaceInterface
{
	GENERATED_BODY()

public:
	// signals
	virtual FTestbed2NestedStruct1InterfaceSig1Delegate& GetSig1SignalDelegate() = 0;

	virtual FTestbed2NestedStruct1InterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() = 0;

	// methods
	virtual FTestbed2NestedStruct1 Func1(const FTestbed2NestedStruct1& Param1) = 0;
	// properties
	virtual FTestbed2NestedStruct1 GetProp1() const = 0;
	virtual void SetProp1(const FTestbed2NestedStruct1& Prop1) = 0;
};
/**
 * Declaration for NestedStruct2Interface
 */
// signal delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2NestedStruct2InterfaceSig1Delegate, const FTestbed2NestedStruct1&, Param1);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTestbed2NestedStruct2InterfaceSig2Delegate, const FTestbed2NestedStruct1&, Param1, const FTestbed2NestedStruct2&, Param2);

// property delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2NestedStruct2InterfaceProp1ChangedDelegate, const FTestbed2NestedStruct1&, Prop1);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2NestedStruct2InterfaceProp2ChangedDelegate, const FTestbed2NestedStruct2&, Prop2);

/**
 * Interface UTestbed2NestedStruct2InterfaceInterface only for Unreal Engine's reflection system
 */
UINTERFACE(MinimalAPI)
class UTestbed2NestedStruct2InterfaceInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITestbed2NestedStruct2InterfaceInterface
 */
class TESTBED2_API ITestbed2NestedStruct2InterfaceInterface
{
	GENERATED_BODY()

public:
	// signals
	virtual FTestbed2NestedStruct2InterfaceSig1Delegate& GetSig1SignalDelegate() = 0;

	virtual FTestbed2NestedStruct2InterfaceSig2Delegate& GetSig2SignalDelegate() = 0;

	virtual FTestbed2NestedStruct2InterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() = 0;

	virtual FTestbed2NestedStruct2InterfaceProp2ChangedDelegate& GetProp2ChangedDelegate() = 0;

	// methods
	virtual FTestbed2NestedStruct1 Func1(const FTestbed2NestedStruct1& Param1) = 0;
	virtual FTestbed2NestedStruct1 Func2(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2) = 0;
	// properties
	virtual FTestbed2NestedStruct1 GetProp1() const = 0;
	virtual void SetProp1(const FTestbed2NestedStruct1& Prop1) = 0;
	virtual FTestbed2NestedStruct2 GetProp2() const = 0;
	virtual void SetProp2(const FTestbed2NestedStruct2& Prop2) = 0;
};
/**
 * Declaration for NestedStruct3Interface
 */
// signal delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2NestedStruct3InterfaceSig1Delegate, const FTestbed2NestedStruct1&, Param1);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTestbed2NestedStruct3InterfaceSig2Delegate, const FTestbed2NestedStruct1&, Param1, const FTestbed2NestedStruct2&, Param2);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FTestbed2NestedStruct3InterfaceSig3Delegate, const FTestbed2NestedStruct1&, Param1, const FTestbed2NestedStruct2&, Param2, const FTestbed2NestedStruct3&, Param3);

// property delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2NestedStruct3InterfaceProp1ChangedDelegate, const FTestbed2NestedStruct1&, Prop1);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2NestedStruct3InterfaceProp2ChangedDelegate, const FTestbed2NestedStruct2&, Prop2);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2NestedStruct3InterfaceProp3ChangedDelegate, const FTestbed2NestedStruct3&, Prop3);

/**
 * Interface UTestbed2NestedStruct3InterfaceInterface only for Unreal Engine's reflection system
 */
UINTERFACE(MinimalAPI)
class UTestbed2NestedStruct3InterfaceInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITestbed2NestedStruct3InterfaceInterface
 */
class TESTBED2_API ITestbed2NestedStruct3InterfaceInterface
{
	GENERATED_BODY()

public:
	// signals
	virtual FTestbed2NestedStruct3InterfaceSig1Delegate& GetSig1SignalDelegate() = 0;

	virtual FTestbed2NestedStruct3InterfaceSig2Delegate& GetSig2SignalDelegate() = 0;

	virtual FTestbed2NestedStruct3InterfaceSig3Delegate& GetSig3SignalDelegate() = 0;

	virtual FTestbed2NestedStruct3InterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() = 0;

	virtual FTestbed2NestedStruct3InterfaceProp2ChangedDelegate& GetProp2ChangedDelegate() = 0;

	virtual FTestbed2NestedStruct3InterfaceProp3ChangedDelegate& GetProp3ChangedDelegate() = 0;

	// methods
	virtual FTestbed2NestedStruct1 Func1(const FTestbed2NestedStruct1& Param1) = 0;
	virtual FTestbed2NestedStruct1 Func2(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2) = 0;
	virtual FTestbed2NestedStruct1 Func3(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3) = 0;
	// properties
	virtual FTestbed2NestedStruct1 GetProp1() const = 0;
	virtual void SetProp1(const FTestbed2NestedStruct1& Prop1) = 0;
	virtual FTestbed2NestedStruct2 GetProp2() const = 0;
	virtual void SetProp2(const FTestbed2NestedStruct2& Prop2) = 0;
	virtual FTestbed2NestedStruct3 GetProp3() const = 0;
	virtual void SetProp3(const FTestbed2NestedStruct3& Prop3) = 0;
};
