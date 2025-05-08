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
#include "TbSimpleSimpleArrayInterfaceOLinkFixture.h"
#include "TbSimpleTestsCommon.h"
#include "OLinkCommon.h"
#include "Generated/OLink/TbSimpleSimpleArrayInterfaceOLinkClient.h"
#include "Generated/OLink/TbSimpleSimpleArrayInterfaceOLinkAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
#include "OLinkHost.h"

void UTbSimpleSimpleArrayInterfaceOLinkHelper::SetParentFixture(TWeakPtr<FTbSimpleSimpleArrayInterfaceOLinkFixture> InFixture)
{
	ImplFixture = InFixture;
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::SetSpec(FAutomationTestBase* InSpec)
{
	Spec = InSpec;
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::SetTestDone(const FDoneDelegate& InDone)
{
	testDoneDelegate = InDone;
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropBoolPropertyCb(const TArray<bool>& InPropBool)
{
	TArray<bool> TestValue = TArray<bool>();
	// use different test value
	TestValue.Add(true);
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
	if (TSharedPtr<FTbSimpleSimpleArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropBool(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropBoolPropertyChangeLocalCheckRemoteCb(const TArray<bool>& InPropBool)
{
	TArray<bool> TestValue = TArray<bool>();
	// use different test value
	TestValue.Add(true);
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
	if (TSharedPtr<FTbSimpleSimpleArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropBool(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropBoolPropertyChangeLocalChangeRemoteCb(const TArray<bool>& InPropBool)
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
		if (TSharedPtr<FTbSimpleSimpleArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropBool(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = TArray<bool>(); // default value
		if (TSharedPtr<FTbSimpleSimpleArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetPropBool(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		TArray<bool> TestValue = TArray<bool>(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
		if (TSharedPtr<FTbSimpleSimpleArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropBool(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropIntPropertyCb(const TArray<int32>& InPropInt)
{
	TArray<int32> TestValue = TArray<int32>();
	// use different test value
	TestValue.Add(1);
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
	if (TSharedPtr<FTbSimpleSimpleArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropIntPropertyChangeLocalCheckRemoteCb(const TArray<int32>& InPropInt)
{
	TArray<int32> TestValue = TArray<int32>();
	// use different test value
	TestValue.Add(1);
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
	if (TSharedPtr<FTbSimpleSimpleArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropIntPropertyChangeLocalChangeRemoteCb(const TArray<int32>& InPropInt)
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
		if (TSharedPtr<FTbSimpleSimpleArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = TArray<int32>(); // default value
		if (TSharedPtr<FTbSimpleSimpleArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetPropInt(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		TArray<int32> TestValue = TArray<int32>(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
		if (TSharedPtr<FTbSimpleSimpleArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropInt32PropertyCb(const TArray<int32>& InPropInt32)
{
	TArray<int32> TestValue = TArray<int32>();
	// use different test value
	TestValue.Add(1);
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt32, TestValue);
	if (TSharedPtr<FTbSimpleSimpleArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt32(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropInt32PropertyChangeLocalCheckRemoteCb(const TArray<int32>& InPropInt32)
{
	TArray<int32> TestValue = TArray<int32>();
	// use different test value
	TestValue.Add(1);
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt32, TestValue);
	if (TSharedPtr<FTbSimpleSimpleArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt32(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropInt32PropertyChangeLocalChangeRemoteCb(const TArray<int32>& InPropInt32)
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
		if (TSharedPtr<FTbSimpleSimpleArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt32(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = TArray<int32>(); // default value
		if (TSharedPtr<FTbSimpleSimpleArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetPropInt32(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		TArray<int32> TestValue = TArray<int32>(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt32, TestValue);
		if (TSharedPtr<FTbSimpleSimpleArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt32(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropInt64PropertyCb(const TArray<int64>& InPropInt64)
{
	TArray<int64> TestValue = TArray<int64>();
	// use different test value
	TestValue.Add(1LL);
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt64, TestValue);
	if (TSharedPtr<FTbSimpleSimpleArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt64(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropInt64PropertyChangeLocalCheckRemoteCb(const TArray<int64>& InPropInt64)
{
	TArray<int64> TestValue = TArray<int64>();
	// use different test value
	TestValue.Add(1LL);
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt64, TestValue);
	if (TSharedPtr<FTbSimpleSimpleArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt64(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropInt64PropertyChangeLocalChangeRemoteCb(const TArray<int64>& InPropInt64)
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
		if (TSharedPtr<FTbSimpleSimpleArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt64(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = TArray<int64>(); // default value
		if (TSharedPtr<FTbSimpleSimpleArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetPropInt64(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		TArray<int64> TestValue = TArray<int64>(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt64, TestValue);
		if (TSharedPtr<FTbSimpleSimpleArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt64(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropFloatPropertyCb(const TArray<float>& InPropFloat)
{
	TArray<float> TestValue = TArray<float>();
	// use different test value
	TestValue.Add(1.0f);
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
	if (TSharedPtr<FTbSimpleSimpleArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropFloatPropertyChangeLocalCheckRemoteCb(const TArray<float>& InPropFloat)
{
	TArray<float> TestValue = TArray<float>();
	// use different test value
	TestValue.Add(1.0f);
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
	if (TSharedPtr<FTbSimpleSimpleArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropFloatPropertyChangeLocalChangeRemoteCb(const TArray<float>& InPropFloat)
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
		if (TSharedPtr<FTbSimpleSimpleArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = TArray<float>(); // default value
		if (TSharedPtr<FTbSimpleSimpleArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetPropFloat(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		TArray<float> TestValue = TArray<float>(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
		if (TSharedPtr<FTbSimpleSimpleArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropFloat32PropertyCb(const TArray<float>& InPropFloat32)
{
	TArray<float> TestValue = TArray<float>();
	// use different test value
	TestValue.Add(1.0f);
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat32, TestValue);
	if (TSharedPtr<FTbSimpleSimpleArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat32(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropFloat32PropertyChangeLocalCheckRemoteCb(const TArray<float>& InPropFloat32)
{
	TArray<float> TestValue = TArray<float>();
	// use different test value
	TestValue.Add(1.0f);
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat32, TestValue);
	if (TSharedPtr<FTbSimpleSimpleArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat32(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropFloat32PropertyChangeLocalChangeRemoteCb(const TArray<float>& InPropFloat32)
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
		if (TSharedPtr<FTbSimpleSimpleArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat32(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = TArray<float>(); // default value
		if (TSharedPtr<FTbSimpleSimpleArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetPropFloat32(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		TArray<float> TestValue = TArray<float>(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat32, TestValue);
		if (TSharedPtr<FTbSimpleSimpleArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat32(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropFloat64PropertyCb(const TArray<double>& InPropFloat64)
{
	TArray<double> TestValue = TArray<double>();
	// use different test value
	TestValue.Add(1.0);
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat64, TestValue);
	if (TSharedPtr<FTbSimpleSimpleArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat64(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropFloat64PropertyChangeLocalCheckRemoteCb(const TArray<double>& InPropFloat64)
{
	TArray<double> TestValue = TArray<double>();
	// use different test value
	TestValue.Add(1.0);
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat64, TestValue);
	if (TSharedPtr<FTbSimpleSimpleArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat64(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropFloat64PropertyChangeLocalChangeRemoteCb(const TArray<double>& InPropFloat64)
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
		if (TSharedPtr<FTbSimpleSimpleArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat64(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = TArray<double>(); // default value
		if (TSharedPtr<FTbSimpleSimpleArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetPropFloat64(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		TArray<double> TestValue = TArray<double>(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat64, TestValue);
		if (TSharedPtr<FTbSimpleSimpleArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat64(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropStringPropertyCb(const TArray<FString>& InPropString)
{
	TArray<FString> TestValue = TArray<FString>();
	// use different test value
	TestValue.Add(FString("xyz"));
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
	if (TSharedPtr<FTbSimpleSimpleArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropString(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropStringPropertyChangeLocalCheckRemoteCb(const TArray<FString>& InPropString)
{
	TArray<FString> TestValue = TArray<FString>();
	// use different test value
	TestValue.Add(FString("xyz"));
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
	if (TSharedPtr<FTbSimpleSimpleArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropString(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropStringPropertyChangeLocalChangeRemoteCb(const TArray<FString>& InPropString)
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
		if (TSharedPtr<FTbSimpleSimpleArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropString(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = TArray<FString>(); // default value
		if (TSharedPtr<FTbSimpleSimpleArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetPropString(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		TArray<FString> TestValue = TArray<FString>(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
		if (TSharedPtr<FTbSimpleSimpleArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropString(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::SigBoolSignalCb(const TArray<bool>& InParamBool)
{
	// known test value
	TArray<bool> ParamBoolTestValue = TArray<bool>(); // default value
	ParamBoolTestValue.Add(true);
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamBool, ParamBoolTestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::SigIntSignalCb(const TArray<int32>& InParamInt)
{
	// known test value
	TArray<int32> ParamIntTestValue = TArray<int32>(); // default value
	ParamIntTestValue.Add(1);
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt, ParamIntTestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::SigInt32SignalCb(const TArray<int32>& InParamInt32)
{
	// known test value
	TArray<int32> ParamInt32TestValue = TArray<int32>(); // default value
	ParamInt32TestValue.Add(1);
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt32, ParamInt32TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::SigInt64SignalCb(const TArray<int64>& InParamInt64)
{
	// known test value
	TArray<int64> ParamInt64TestValue = TArray<int64>(); // default value
	ParamInt64TestValue.Add(1LL);
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt64, ParamInt64TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::SigFloatSignalCb(const TArray<float>& InParamFloat)
{
	// known test value
	TArray<float> ParamFloatTestValue = TArray<float>(); // default value
	ParamFloatTestValue.Add(1.0f);
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat, ParamFloatTestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::SigFloat32SignalCb(const TArray<float>& InParamFloa32)
{
	// known test value
	TArray<float> ParamFloa32TestValue = TArray<float>(); // default value
	ParamFloa32TestValue.Add(1.0f);
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloa32, ParamFloa32TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::SigFloat64SignalCb(const TArray<double>& InParamFloat64)
{
	// known test value
	TArray<double> ParamFloat64TestValue = TArray<double>(); // default value
	ParamFloat64TestValue.Add(1.0);
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat64, ParamFloat64TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::SigStringSignalCb(const TArray<FString>& InParamString)
{
	// known test value
	TArray<FString> ParamStringTestValue = TArray<FString>(); // default value
	ParamStringTestValue.Add(FString("xyz"));
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamString, ParamStringTestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	if (bSubscribed)
	{
		testDoneDelegate.Execute();
	}
}

FTbSimpleSimpleArrayInterfaceOLinkFixture::FTbSimpleSimpleArrayInterfaceOLinkFixture()
{
	Helper = NewObject<UTbSimpleSimpleArrayInterfaceOLinkHelper>(GetTransientPackage());
	Helper->AddToRoot();
	testImplementation = GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterfaceOLinkClient>();
}

FTbSimpleSimpleArrayInterfaceOLinkFixture::~FTbSimpleSimpleArrayInterfaceOLinkFixture()
{
	CleanUp();
	Helper->RemoveFromRoot();
}

TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> FTbSimpleSimpleArrayInterfaceOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTbSimpleSimpleArrayInterfaceOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTbSimpleSimpleArrayInterfaceOLinkAdapter* FTbSimpleSimpleArrayInterfaceOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterfaceOLinkAdapter>();
}

TSoftObjectPtr<UTbSimpleSimpleArrayInterfaceOLinkHelper> FTbSimpleSimpleArrayInterfaceOLinkFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSimpleSimpleArrayInterfaceOLinkFixture::GetGameInstance()
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

void FTbSimpleSimpleArrayInterfaceOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
// create empty implementation in case we do not want to do automated testing
void UTbSimpleSimpleArrayInterfaceOLinkHelper::SetParentFixture(TWeakPtr<FTbSimpleSimpleArrayInterfaceOLinkFixture> /*InFixture*/)
{
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::SetSpec(FAutomationTestBase* /*InSpec*/)
{
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::SetTestDone(const FDoneDelegate& /*InDone*/)
{
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropBoolPropertyCb(const TArray<bool>& InPropBool)
{
	(void)InPropBool;
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropBoolPropertyChangeLocalCheckRemoteCb(const TArray<bool>& InPropBool)
{
	(void)InPropBool;
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropBoolPropertyChangeLocalChangeRemoteCb(const TArray<bool>& InPropBool)
{
	(void)InPropBool;
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropIntPropertyCb(const TArray<int32>& InPropInt)
{
	(void)InPropInt;
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropIntPropertyChangeLocalCheckRemoteCb(const TArray<int32>& InPropInt)
{
	(void)InPropInt;
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropIntPropertyChangeLocalChangeRemoteCb(const TArray<int32>& InPropInt)
{
	(void)InPropInt;
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropInt32PropertyCb(const TArray<int32>& InPropInt32)
{
	(void)InPropInt32;
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropInt32PropertyChangeLocalCheckRemoteCb(const TArray<int32>& InPropInt32)
{
	(void)InPropInt32;
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropInt32PropertyChangeLocalChangeRemoteCb(const TArray<int32>& InPropInt32)
{
	(void)InPropInt32;
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropInt64PropertyCb(const TArray<int64>& InPropInt64)
{
	(void)InPropInt64;
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropInt64PropertyChangeLocalCheckRemoteCb(const TArray<int64>& InPropInt64)
{
	(void)InPropInt64;
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropInt64PropertyChangeLocalChangeRemoteCb(const TArray<int64>& InPropInt64)
{
	(void)InPropInt64;
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropFloatPropertyCb(const TArray<float>& InPropFloat)
{
	(void)InPropFloat;
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropFloatPropertyChangeLocalCheckRemoteCb(const TArray<float>& InPropFloat)
{
	(void)InPropFloat;
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropFloatPropertyChangeLocalChangeRemoteCb(const TArray<float>& InPropFloat)
{
	(void)InPropFloat;
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropFloat32PropertyCb(const TArray<float>& InPropFloat32)
{
	(void)InPropFloat32;
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropFloat32PropertyChangeLocalCheckRemoteCb(const TArray<float>& InPropFloat32)
{
	(void)InPropFloat32;
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropFloat32PropertyChangeLocalChangeRemoteCb(const TArray<float>& InPropFloat32)
{
	(void)InPropFloat32;
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropFloat64PropertyCb(const TArray<double>& InPropFloat64)
{
	(void)InPropFloat64;
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropFloat64PropertyChangeLocalCheckRemoteCb(const TArray<double>& InPropFloat64)
{
	(void)InPropFloat64;
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropFloat64PropertyChangeLocalChangeRemoteCb(const TArray<double>& InPropFloat64)
{
	(void)InPropFloat64;
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropStringPropertyCb(const TArray<FString>& InPropString)
{
	(void)InPropString;
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropStringPropertyChangeLocalCheckRemoteCb(const TArray<FString>& InPropString)
{
	(void)InPropString;
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropStringPropertyChangeLocalChangeRemoteCb(const TArray<FString>& InPropString)
{
	(void)InPropString;
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::SigBoolSignalCb(const TArray<bool>& ParamBool)
{
	(void)ParamBool;
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::SigIntSignalCb(const TArray<int32>& ParamInt)
{
	(void)ParamInt;
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::SigInt32SignalCb(const TArray<int32>& ParamInt32)
{
	(void)ParamInt32;
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::SigInt64SignalCb(const TArray<int64>& ParamInt64)
{
	(void)ParamInt64;
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::SigFloatSignalCb(const TArray<float>& ParamFloat)
{
	(void)ParamFloat;
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::SigFloat32SignalCb(const TArray<float>& ParamFloa32)
{
	(void)ParamFloa32;
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::SigFloat64SignalCb(const TArray<double>& ParamFloat64)
{
	(void)ParamFloat64;
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::SigStringSignalCb(const TArray<FString>& ParamString)
{
	(void)ParamString;
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	(void)bSubscribed;
}
#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
