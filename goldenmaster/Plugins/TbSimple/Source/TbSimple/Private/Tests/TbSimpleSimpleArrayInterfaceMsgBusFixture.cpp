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
#include "TbSimpleSimpleArrayInterfaceMsgBusFixture.h"
#include "TbSimpleTestsCommon.h"
#include "Generated/MsgBus/TbSimpleSimpleArrayInterfaceMsgBusClient.h"
#include "Generated/MsgBus/TbSimpleSimpleArrayInterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

UTbSimpleSimpleArrayInterfaceMsgBusHelper::~UTbSimpleSimpleArrayInterfaceMsgBusHelper()
{
	Spec = nullptr;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::SetParentFixture(TWeakPtr<FTbSimpleSimpleArrayInterfaceMsgBusFixture> InFixture)
{
	ImplFixture = InFixture;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::SetSpec(FAutomationTestBase* InSpec)
{
	Spec = InSpec;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::SetTestDone(const FDoneDelegate& InDone)
{
	testDoneDelegate = InDone;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropBoolPropertyCb(const TArray<bool>& InPropBool)
{
	TArray<bool> TestValue = TArray<bool>();
	// use different test value
	TestValue.Add(true);
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
	if (TSharedPtr<FTbSimpleSimpleArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropBool(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropBoolPropertyChangeLocalCheckRemoteCb(const TArray<bool>& InPropBool)
{
	TArray<bool> TestValue = TArray<bool>();
	// use different test value
	TestValue.Add(true);
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
	if (TSharedPtr<FTbSimpleSimpleArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropBool(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropBoolPropertyChangeLocalChangeRemoteCb(const TArray<bool>& InPropBool)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		TArray<bool> TestValue = TArray<bool>();
		// use different test value
		TestValue.Add(true);
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
		if (TSharedPtr<FTbSimpleSimpleArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropBool(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = TArray<bool>(); // default value
		if (TSharedPtr<FTbSimpleSimpleArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetPropBool(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		TArray<bool> TestValue = TArray<bool>(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
		if (TSharedPtr<FTbSimpleSimpleArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropBool(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropIntPropertyCb(const TArray<int32>& InPropInt)
{
	TArray<int32> TestValue = TArray<int32>();
	// use different test value
	TestValue.Add(1);
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
	if (TSharedPtr<FTbSimpleSimpleArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropIntPropertyChangeLocalCheckRemoteCb(const TArray<int32>& InPropInt)
{
	TArray<int32> TestValue = TArray<int32>();
	// use different test value
	TestValue.Add(1);
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
	if (TSharedPtr<FTbSimpleSimpleArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropIntPropertyChangeLocalChangeRemoteCb(const TArray<int32>& InPropInt)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		TArray<int32> TestValue = TArray<int32>();
		// use different test value
		TestValue.Add(1);
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
		if (TSharedPtr<FTbSimpleSimpleArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = TArray<int32>(); // default value
		if (TSharedPtr<FTbSimpleSimpleArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetPropInt(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		TArray<int32> TestValue = TArray<int32>(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
		if (TSharedPtr<FTbSimpleSimpleArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropInt32PropertyCb(const TArray<int32>& InPropInt32)
{
	TArray<int32> TestValue = TArray<int32>();
	// use different test value
	TestValue.Add(1);
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt32, TestValue);
	if (TSharedPtr<FTbSimpleSimpleArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt32(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropInt32PropertyChangeLocalCheckRemoteCb(const TArray<int32>& InPropInt32)
{
	TArray<int32> TestValue = TArray<int32>();
	// use different test value
	TestValue.Add(1);
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt32, TestValue);
	if (TSharedPtr<FTbSimpleSimpleArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt32(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropInt32PropertyChangeLocalChangeRemoteCb(const TArray<int32>& InPropInt32)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		TArray<int32> TestValue = TArray<int32>();
		// use different test value
		TestValue.Add(1);
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt32, TestValue);
		if (TSharedPtr<FTbSimpleSimpleArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt32(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = TArray<int32>(); // default value
		if (TSharedPtr<FTbSimpleSimpleArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetPropInt32(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		TArray<int32> TestValue = TArray<int32>(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt32, TestValue);
		if (TSharedPtr<FTbSimpleSimpleArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt32(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropInt64PropertyCb(const TArray<int64>& InPropInt64)
{
	TArray<int64> TestValue = TArray<int64>();
	// use different test value
	TestValue.Add(1LL);
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt64, TestValue);
	if (TSharedPtr<FTbSimpleSimpleArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt64(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropInt64PropertyChangeLocalCheckRemoteCb(const TArray<int64>& InPropInt64)
{
	TArray<int64> TestValue = TArray<int64>();
	// use different test value
	TestValue.Add(1LL);
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt64, TestValue);
	if (TSharedPtr<FTbSimpleSimpleArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt64(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropInt64PropertyChangeLocalChangeRemoteCb(const TArray<int64>& InPropInt64)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		TArray<int64> TestValue = TArray<int64>();
		// use different test value
		TestValue.Add(1LL);
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt64, TestValue);
		if (TSharedPtr<FTbSimpleSimpleArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt64(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = TArray<int64>(); // default value
		if (TSharedPtr<FTbSimpleSimpleArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetPropInt64(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		TArray<int64> TestValue = TArray<int64>(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt64, TestValue);
		if (TSharedPtr<FTbSimpleSimpleArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt64(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropFloatPropertyCb(const TArray<float>& InPropFloat)
{
	TArray<float> TestValue = TArray<float>();
	// use different test value
	TestValue.Add(1.0f);
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
	if (TSharedPtr<FTbSimpleSimpleArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropFloatPropertyChangeLocalCheckRemoteCb(const TArray<float>& InPropFloat)
{
	TArray<float> TestValue = TArray<float>();
	// use different test value
	TestValue.Add(1.0f);
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
	if (TSharedPtr<FTbSimpleSimpleArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropFloatPropertyChangeLocalChangeRemoteCb(const TArray<float>& InPropFloat)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		TArray<float> TestValue = TArray<float>();
		// use different test value
		TestValue.Add(1.0f);
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
		if (TSharedPtr<FTbSimpleSimpleArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = TArray<float>(); // default value
		if (TSharedPtr<FTbSimpleSimpleArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetPropFloat(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		TArray<float> TestValue = TArray<float>(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
		if (TSharedPtr<FTbSimpleSimpleArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropFloat32PropertyCb(const TArray<float>& InPropFloat32)
{
	TArray<float> TestValue = TArray<float>();
	// use different test value
	TestValue.Add(1.0f);
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat32, TestValue);
	if (TSharedPtr<FTbSimpleSimpleArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat32(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropFloat32PropertyChangeLocalCheckRemoteCb(const TArray<float>& InPropFloat32)
{
	TArray<float> TestValue = TArray<float>();
	// use different test value
	TestValue.Add(1.0f);
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat32, TestValue);
	if (TSharedPtr<FTbSimpleSimpleArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat32(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropFloat32PropertyChangeLocalChangeRemoteCb(const TArray<float>& InPropFloat32)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		TArray<float> TestValue = TArray<float>();
		// use different test value
		TestValue.Add(1.0f);
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat32, TestValue);
		if (TSharedPtr<FTbSimpleSimpleArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat32(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = TArray<float>(); // default value
		if (TSharedPtr<FTbSimpleSimpleArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetPropFloat32(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		TArray<float> TestValue = TArray<float>(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat32, TestValue);
		if (TSharedPtr<FTbSimpleSimpleArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat32(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropFloat64PropertyCb(const TArray<double>& InPropFloat64)
{
	TArray<double> TestValue = TArray<double>();
	// use different test value
	TestValue.Add(1.0);
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat64, TestValue);
	if (TSharedPtr<FTbSimpleSimpleArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat64(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropFloat64PropertyChangeLocalCheckRemoteCb(const TArray<double>& InPropFloat64)
{
	TArray<double> TestValue = TArray<double>();
	// use different test value
	TestValue.Add(1.0);
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat64, TestValue);
	if (TSharedPtr<FTbSimpleSimpleArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat64(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropFloat64PropertyChangeLocalChangeRemoteCb(const TArray<double>& InPropFloat64)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		TArray<double> TestValue = TArray<double>();
		// use different test value
		TestValue.Add(1.0);
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat64, TestValue);
		if (TSharedPtr<FTbSimpleSimpleArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat64(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = TArray<double>(); // default value
		if (TSharedPtr<FTbSimpleSimpleArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetPropFloat64(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		TArray<double> TestValue = TArray<double>(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat64, TestValue);
		if (TSharedPtr<FTbSimpleSimpleArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat64(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropStringPropertyCb(const TArray<FString>& InPropString)
{
	TArray<FString> TestValue = TArray<FString>();
	// use different test value
	TestValue.Add(FString("xyz"));
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
	if (TSharedPtr<FTbSimpleSimpleArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropString(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropStringPropertyChangeLocalCheckRemoteCb(const TArray<FString>& InPropString)
{
	TArray<FString> TestValue = TArray<FString>();
	// use different test value
	TestValue.Add(FString("xyz"));
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
	if (TSharedPtr<FTbSimpleSimpleArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropString(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropStringPropertyChangeLocalChangeRemoteCb(const TArray<FString>& InPropString)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		TArray<FString> TestValue = TArray<FString>();
		// use different test value
		TestValue.Add(FString("xyz"));
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
		if (TSharedPtr<FTbSimpleSimpleArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropString(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = TArray<FString>(); // default value
		if (TSharedPtr<FTbSimpleSimpleArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetPropString(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		TArray<FString> TestValue = TArray<FString>(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
		if (TSharedPtr<FTbSimpleSimpleArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropString(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::SigBoolSignalCb(const TArray<bool>& InParamBool)
{
	// known test value
	TArray<bool> ParamBoolTestValue = TArray<bool>(); // default value
	ParamBoolTestValue.Add(true);
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamBool, ParamBoolTestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::SigIntSignalCb(const TArray<int32>& InParamInt)
{
	// known test value
	TArray<int32> ParamIntTestValue = TArray<int32>(); // default value
	ParamIntTestValue.Add(1);
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt, ParamIntTestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::SigInt32SignalCb(const TArray<int32>& InParamInt32)
{
	// known test value
	TArray<int32> ParamInt32TestValue = TArray<int32>(); // default value
	ParamInt32TestValue.Add(1);
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt32, ParamInt32TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::SigInt64SignalCb(const TArray<int64>& InParamInt64)
{
	// known test value
	TArray<int64> ParamInt64TestValue = TArray<int64>(); // default value
	ParamInt64TestValue.Add(1LL);
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt64, ParamInt64TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::SigFloatSignalCb(const TArray<float>& InParamFloat)
{
	// known test value
	TArray<float> ParamFloatTestValue = TArray<float>(); // default value
	ParamFloatTestValue.Add(1.0f);
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat, ParamFloatTestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::SigFloat32SignalCb(const TArray<float>& InParamFloa32)
{
	// known test value
	TArray<float> ParamFloa32TestValue = TArray<float>(); // default value
	ParamFloa32TestValue.Add(1.0f);
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloa32, ParamFloa32TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::SigFloat64SignalCb(const TArray<double>& InParamFloat64)
{
	// known test value
	TArray<double> ParamFloat64TestValue = TArray<double>(); // default value
	ParamFloat64TestValue.Add(1.0);
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat64, ParamFloat64TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::SigStringSignalCb(const TArray<FString>& InParamString)
{
	// known test value
	TArray<FString> ParamStringTestValue = TArray<FString>(); // default value
	ParamStringTestValue.Add(FString("xyz"));
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamString, ParamStringTestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	if (bConnected)
	{
		testDoneDelegate.Execute();
	}
}

FTbSimpleSimpleArrayInterfaceMsgBusFixture::FTbSimpleSimpleArrayInterfaceMsgBusFixture()
{
	Helper = NewObject<UTbSimpleSimpleArrayInterfaceMsgBusHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterfaceMsgBusClient>();
}

FTbSimpleSimpleArrayInterfaceMsgBusFixture::~FTbSimpleSimpleArrayInterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> FTbSimpleSimpleArrayInterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTbSimpleSimpleArrayInterfaceMsgBusAdapter* FTbSimpleSimpleArrayInterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterfaceMsgBusAdapter>();
}

TSoftObjectPtr<UTbSimpleSimpleArrayInterfaceMsgBusHelper> FTbSimpleSimpleArrayInterfaceMsgBusFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSimpleSimpleArrayInterfaceMsgBusFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>(GetTransientPackage());
		GameInstance->Init();
		// needed to prevent garbage collection and we can't use UPROPERTY on raw c++ objects
		GameInstance->AddToRoot();
	}

	return GameInstance.Get();
}

void FTbSimpleSimpleArrayInterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
UTbSimpleSimpleArrayInterfaceMsgBusHelper::~UTbSimpleSimpleArrayInterfaceMsgBusHelper()
{
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::SetParentFixture(TWeakPtr<FTbSimpleSimpleArrayInterfaceMsgBusFixture> /*InFixture*/)
{
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::SetSpec(FAutomationTestBase* /*InSpec*/)
{
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::SetTestDone(const FDoneDelegate& /*InDone*/)
{
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropBoolPropertyCb(const TArray<bool>& InPropBool)
{
	(void)InPropBool;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropBoolPropertyChangeLocalCheckRemoteCb(const TArray<bool>& InPropBool)
{
	(void)InPropBool;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropBoolPropertyChangeLocalChangeRemoteCb(const TArray<bool>& InPropBool)
{
	(void)InPropBool;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropIntPropertyCb(const TArray<int32>& InPropInt)
{
	(void)InPropInt;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropIntPropertyChangeLocalCheckRemoteCb(const TArray<int32>& InPropInt)
{
	(void)InPropInt;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropIntPropertyChangeLocalChangeRemoteCb(const TArray<int32>& InPropInt)
{
	(void)InPropInt;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropInt32PropertyCb(const TArray<int32>& InPropInt32)
{
	(void)InPropInt32;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropInt32PropertyChangeLocalCheckRemoteCb(const TArray<int32>& InPropInt32)
{
	(void)InPropInt32;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropInt32PropertyChangeLocalChangeRemoteCb(const TArray<int32>& InPropInt32)
{
	(void)InPropInt32;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropInt64PropertyCb(const TArray<int64>& InPropInt64)
{
	(void)InPropInt64;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropInt64PropertyChangeLocalCheckRemoteCb(const TArray<int64>& InPropInt64)
{
	(void)InPropInt64;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropInt64PropertyChangeLocalChangeRemoteCb(const TArray<int64>& InPropInt64)
{
	(void)InPropInt64;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropFloatPropertyCb(const TArray<float>& InPropFloat)
{
	(void)InPropFloat;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropFloatPropertyChangeLocalCheckRemoteCb(const TArray<float>& InPropFloat)
{
	(void)InPropFloat;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropFloatPropertyChangeLocalChangeRemoteCb(const TArray<float>& InPropFloat)
{
	(void)InPropFloat;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropFloat32PropertyCb(const TArray<float>& InPropFloat32)
{
	(void)InPropFloat32;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropFloat32PropertyChangeLocalCheckRemoteCb(const TArray<float>& InPropFloat32)
{
	(void)InPropFloat32;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropFloat32PropertyChangeLocalChangeRemoteCb(const TArray<float>& InPropFloat32)
{
	(void)InPropFloat32;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropFloat64PropertyCb(const TArray<double>& InPropFloat64)
{
	(void)InPropFloat64;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropFloat64PropertyChangeLocalCheckRemoteCb(const TArray<double>& InPropFloat64)
{
	(void)InPropFloat64;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropFloat64PropertyChangeLocalChangeRemoteCb(const TArray<double>& InPropFloat64)
{
	(void)InPropFloat64;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropStringPropertyCb(const TArray<FString>& InPropString)
{
	(void)InPropString;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropStringPropertyChangeLocalCheckRemoteCb(const TArray<FString>& InPropString)
{
	(void)InPropString;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropStringPropertyChangeLocalChangeRemoteCb(const TArray<FString>& InPropString)
{
	(void)InPropString;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::SigBoolSignalCb(const TArray<bool>& ParamBool)
{
	(void)ParamBool;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::SigIntSignalCb(const TArray<int32>& ParamInt)
{
	(void)ParamInt;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::SigInt32SignalCb(const TArray<int32>& ParamInt32)
{
	(void)ParamInt32;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::SigInt64SignalCb(const TArray<int64>& ParamInt64)
{
	(void)ParamInt64;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::SigFloatSignalCb(const TArray<float>& ParamFloat)
{
	(void)ParamFloat;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::SigFloat32SignalCb(const TArray<float>& ParamFloa32)
{
	(void)ParamFloa32;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::SigFloat64SignalCb(const TArray<double>& ParamFloat64)
{
	(void)ParamFloat64;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::SigStringSignalCb(const TArray<FString>& ParamString)
{
	(void)ParamString;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	(void)bConnected;
}
#endif // WITH_DEV_AUTOMATION_TESTS
