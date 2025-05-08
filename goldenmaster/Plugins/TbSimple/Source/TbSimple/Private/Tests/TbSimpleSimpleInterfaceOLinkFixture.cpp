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
#include "TbSimpleSimpleInterfaceOLinkFixture.h"
#include "TbSimpleTestsCommon.h"
#include "OLinkCommon.h"
#include "Generated/OLink/TbSimpleSimpleInterfaceOLinkClient.h"
#include "Generated/OLink/TbSimpleSimpleInterfaceOLinkAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
#include "OLinkHost.h"

void UTbSimpleSimpleInterfaceOLinkHelper::SetParentFixture(TWeakPtr<FTbSimpleSimpleInterfaceOLinkFixture> InFixture)
{
	ImplFixture = InFixture;
}

void UTbSimpleSimpleInterfaceOLinkHelper::SetSpec(FAutomationTestBase* InSpec)
{
	Spec = InSpec;
}

void UTbSimpleSimpleInterfaceOLinkHelper::SetTestDone(const FDoneDelegate& InDone)
{
	testDoneDelegate = InDone;
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropBoolPropertyCb(bool bInPropBool)
{
	bool TestValue = false;
	// use different test value
	TestValue = true;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), bInPropBool, TestValue);
	if (TSharedPtr<FTbSimpleSimpleInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropBool(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropBoolPropertyChangeLocalCheckRemoteCb(bool bInPropBool)
{
	bool TestValue = false;
	// use different test value
	TestValue = true;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), bInPropBool, TestValue);
	if (TSharedPtr<FTbSimpleSimpleInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropBool(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropBoolPropertyChangeLocalChangeRemoteCb(bool bInPropBool)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		bool TestValue = false;
		// use different test value
		TestValue = true;
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), bInPropBool, TestValue);
		if (TSharedPtr<FTbSimpleSimpleInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropBool(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = false; // default value
		if (TSharedPtr<FTbSimpleSimpleInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetPropBool(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		bool TestValue = false; // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), bInPropBool, TestValue);
		if (TSharedPtr<FTbSimpleSimpleInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropBool(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropIntPropertyCb(int32 InPropInt)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
	if (TSharedPtr<FTbSimpleSimpleInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropIntPropertyChangeLocalCheckRemoteCb(int32 InPropInt)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
	if (TSharedPtr<FTbSimpleSimpleInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropIntPropertyChangeLocalChangeRemoteCb(int32 InPropInt)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		int32 TestValue = 0;
		// use different test value
		TestValue = 1;
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
		if (TSharedPtr<FTbSimpleSimpleInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = 0; // default value
		if (TSharedPtr<FTbSimpleSimpleInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetPropInt(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		int32 TestValue = 0; // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
		if (TSharedPtr<FTbSimpleSimpleInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropInt32PropertyCb(int32 InPropInt32)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt32, TestValue);
	if (TSharedPtr<FTbSimpleSimpleInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt32(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropInt32PropertyChangeLocalCheckRemoteCb(int32 InPropInt32)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt32, TestValue);
	if (TSharedPtr<FTbSimpleSimpleInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt32(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropInt32PropertyChangeLocalChangeRemoteCb(int32 InPropInt32)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		int32 TestValue = 0;
		// use different test value
		TestValue = 1;
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt32, TestValue);
		if (TSharedPtr<FTbSimpleSimpleInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt32(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = 0; // default value
		if (TSharedPtr<FTbSimpleSimpleInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetPropInt32(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		int32 TestValue = 0; // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt32, TestValue);
		if (TSharedPtr<FTbSimpleSimpleInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt32(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropInt64PropertyCb(int64 InPropInt64)
{
	int64 TestValue = 0LL;
	// use different test value
	TestValue = 1LL;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt64, TestValue);
	if (TSharedPtr<FTbSimpleSimpleInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt64(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropInt64PropertyChangeLocalCheckRemoteCb(int64 InPropInt64)
{
	int64 TestValue = 0LL;
	// use different test value
	TestValue = 1LL;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt64, TestValue);
	if (TSharedPtr<FTbSimpleSimpleInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt64(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropInt64PropertyChangeLocalChangeRemoteCb(int64 InPropInt64)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		int64 TestValue = 0LL;
		// use different test value
		TestValue = 1LL;
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt64, TestValue);
		if (TSharedPtr<FTbSimpleSimpleInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt64(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = 0LL; // default value
		if (TSharedPtr<FTbSimpleSimpleInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetPropInt64(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		int64 TestValue = 0LL; // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt64, TestValue);
		if (TSharedPtr<FTbSimpleSimpleInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt64(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropFloatPropertyCb(float InPropFloat)
{
	float TestValue = 0.0f;
	// use different test value
	TestValue = 1.0f;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
	if (TSharedPtr<FTbSimpleSimpleInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropFloatPropertyChangeLocalCheckRemoteCb(float InPropFloat)
{
	float TestValue = 0.0f;
	// use different test value
	TestValue = 1.0f;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
	if (TSharedPtr<FTbSimpleSimpleInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropFloatPropertyChangeLocalChangeRemoteCb(float InPropFloat)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		float TestValue = 0.0f;
		// use different test value
		TestValue = 1.0f;
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
		if (TSharedPtr<FTbSimpleSimpleInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = 0.0f; // default value
		if (TSharedPtr<FTbSimpleSimpleInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetPropFloat(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		float TestValue = 0.0f; // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
		if (TSharedPtr<FTbSimpleSimpleInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropFloat32PropertyCb(float InPropFloat32)
{
	float TestValue = 0.0f;
	// use different test value
	TestValue = 1.0f;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat32, TestValue);
	if (TSharedPtr<FTbSimpleSimpleInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat32(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropFloat32PropertyChangeLocalCheckRemoteCb(float InPropFloat32)
{
	float TestValue = 0.0f;
	// use different test value
	TestValue = 1.0f;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat32, TestValue);
	if (TSharedPtr<FTbSimpleSimpleInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat32(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropFloat32PropertyChangeLocalChangeRemoteCb(float InPropFloat32)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		float TestValue = 0.0f;
		// use different test value
		TestValue = 1.0f;
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat32, TestValue);
		if (TSharedPtr<FTbSimpleSimpleInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat32(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = 0.0f; // default value
		if (TSharedPtr<FTbSimpleSimpleInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetPropFloat32(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		float TestValue = 0.0f; // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat32, TestValue);
		if (TSharedPtr<FTbSimpleSimpleInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat32(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropFloat64PropertyCb(double InPropFloat64)
{
	double TestValue = 0.0;
	// use different test value
	TestValue = 1.0;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat64, TestValue);
	if (TSharedPtr<FTbSimpleSimpleInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat64(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropFloat64PropertyChangeLocalCheckRemoteCb(double InPropFloat64)
{
	double TestValue = 0.0;
	// use different test value
	TestValue = 1.0;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat64, TestValue);
	if (TSharedPtr<FTbSimpleSimpleInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat64(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropFloat64PropertyChangeLocalChangeRemoteCb(double InPropFloat64)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		double TestValue = 0.0;
		// use different test value
		TestValue = 1.0;
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat64, TestValue);
		if (TSharedPtr<FTbSimpleSimpleInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat64(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = 0.0; // default value
		if (TSharedPtr<FTbSimpleSimpleInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetPropFloat64(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		double TestValue = 0.0; // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat64, TestValue);
		if (TSharedPtr<FTbSimpleSimpleInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat64(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropStringPropertyCb(const FString& InPropString)
{
	FString TestValue = FString();
	// use different test value
	TestValue = FString("xyz");
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
	if (TSharedPtr<FTbSimpleSimpleInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropString(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropStringPropertyChangeLocalCheckRemoteCb(const FString& InPropString)
{
	FString TestValue = FString();
	// use different test value
	TestValue = FString("xyz");
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
	if (TSharedPtr<FTbSimpleSimpleInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropString(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropStringPropertyChangeLocalChangeRemoteCb(const FString& InPropString)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		FString TestValue = FString();
		// use different test value
		TestValue = FString("xyz");
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
		if (TSharedPtr<FTbSimpleSimpleInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropString(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = FString(); // default value
		if (TSharedPtr<FTbSimpleSimpleInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetPropString(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		FString TestValue = FString(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
		if (TSharedPtr<FTbSimpleSimpleInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropString(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTbSimpleSimpleInterfaceOLinkHelper::SigBoolSignalCb(bool bInParamBool)
{
	// known test value
	bool bParamBoolTestValue = true;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), bInParamBool, bParamBoolTestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceOLinkHelper::SigIntSignalCb(int32 InParamInt)
{
	// known test value
	int32 ParamIntTestValue = 1;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt, ParamIntTestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceOLinkHelper::SigInt32SignalCb(int32 InParamInt32)
{
	// known test value
	int32 ParamInt32TestValue = 1;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt32, ParamInt32TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceOLinkHelper::SigInt64SignalCb(int64 InParamInt64)
{
	// known test value
	int64 ParamInt64TestValue = 1LL;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt64, ParamInt64TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceOLinkHelper::SigFloatSignalCb(float InParamFloat)
{
	// known test value
	float ParamFloatTestValue = 1.0f;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat, ParamFloatTestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceOLinkHelper::SigFloat32SignalCb(float InParamFloat32)
{
	// known test value
	float ParamFloat32TestValue = 1.0f;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat32, ParamFloat32TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceOLinkHelper::SigFloat64SignalCb(double InParamFloat64)
{
	// known test value
	double ParamFloat64TestValue = 1.0;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat64, ParamFloat64TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceOLinkHelper::SigStringSignalCb(const FString& InParamString)
{
	// known test value
	FString ParamStringTestValue = FString("xyz");
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamString, ParamStringTestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	if (bSubscribed)
	{
		testDoneDelegate.Execute();
	}
}

FTbSimpleSimpleInterfaceOLinkFixture::FTbSimpleSimpleInterfaceOLinkFixture()
{
	Helper = NewObject<UTbSimpleSimpleInterfaceOLinkHelper>(GetTransientPackage());
	Helper->AddToRoot();
	testImplementation = GetGameInstance()->GetSubsystem<UTbSimpleSimpleInterfaceOLinkClient>();
}

FTbSimpleSimpleInterfaceOLinkFixture::~FTbSimpleSimpleInterfaceOLinkFixture()
{
	CleanUp();
	Helper->RemoveFromRoot();
}

TScriptInterface<ITbSimpleSimpleInterfaceInterface> FTbSimpleSimpleInterfaceOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTbSimpleSimpleInterfaceOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTbSimpleSimpleInterfaceOLinkAdapter* FTbSimpleSimpleInterfaceOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSimpleSimpleInterfaceOLinkAdapter>();
}

TSoftObjectPtr<UTbSimpleSimpleInterfaceOLinkHelper> FTbSimpleSimpleInterfaceOLinkFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSimpleSimpleInterfaceOLinkFixture::GetGameInstance()
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

void FTbSimpleSimpleInterfaceOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
// create empty implementation in case we do not want to do automated testing
void UTbSimpleSimpleInterfaceOLinkHelper::SetParentFixture(TWeakPtr<FTbSimpleSimpleInterfaceOLinkFixture> /*InFixture*/)
{
}

void UTbSimpleSimpleInterfaceOLinkHelper::SetSpec(FAutomationTestBase* /*InSpec*/)
{
}

void UTbSimpleSimpleInterfaceOLinkHelper::SetTestDone(const FDoneDelegate& /*InDone*/)
{
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropBoolPropertyCb(bool bInPropBool)
{
	(void)bInPropBool;
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropBoolPropertyChangeLocalCheckRemoteCb(bool bInPropBool)
{
	(void)bInPropBool;
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropBoolPropertyChangeLocalChangeRemoteCb(bool bInPropBool)
{
	(void)bInPropBool;
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropIntPropertyCb(int32 InPropInt)
{
	(void)InPropInt;
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropIntPropertyChangeLocalCheckRemoteCb(int32 InPropInt)
{
	(void)InPropInt;
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropIntPropertyChangeLocalChangeRemoteCb(int32 InPropInt)
{
	(void)InPropInt;
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropInt32PropertyCb(int32 InPropInt32)
{
	(void)InPropInt32;
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropInt32PropertyChangeLocalCheckRemoteCb(int32 InPropInt32)
{
	(void)InPropInt32;
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropInt32PropertyChangeLocalChangeRemoteCb(int32 InPropInt32)
{
	(void)InPropInt32;
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropInt64PropertyCb(int64 InPropInt64)
{
	(void)InPropInt64;
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropInt64PropertyChangeLocalCheckRemoteCb(int64 InPropInt64)
{
	(void)InPropInt64;
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropInt64PropertyChangeLocalChangeRemoteCb(int64 InPropInt64)
{
	(void)InPropInt64;
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropFloatPropertyCb(float InPropFloat)
{
	(void)InPropFloat;
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropFloatPropertyChangeLocalCheckRemoteCb(float InPropFloat)
{
	(void)InPropFloat;
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropFloatPropertyChangeLocalChangeRemoteCb(float InPropFloat)
{
	(void)InPropFloat;
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropFloat32PropertyCb(float InPropFloat32)
{
	(void)InPropFloat32;
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropFloat32PropertyChangeLocalCheckRemoteCb(float InPropFloat32)
{
	(void)InPropFloat32;
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropFloat32PropertyChangeLocalChangeRemoteCb(float InPropFloat32)
{
	(void)InPropFloat32;
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropFloat64PropertyCb(double InPropFloat64)
{
	(void)InPropFloat64;
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropFloat64PropertyChangeLocalCheckRemoteCb(double InPropFloat64)
{
	(void)InPropFloat64;
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropFloat64PropertyChangeLocalChangeRemoteCb(double InPropFloat64)
{
	(void)InPropFloat64;
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropStringPropertyCb(const FString& InPropString)
{
	(void)InPropString;
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropStringPropertyChangeLocalCheckRemoteCb(const FString& InPropString)
{
	(void)InPropString;
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropStringPropertyChangeLocalChangeRemoteCb(const FString& InPropString)
{
	(void)InPropString;
}

void UTbSimpleSimpleInterfaceOLinkHelper::SigBoolSignalCb(bool bParamBool)
{
	(void)bParamBool;
}

void UTbSimpleSimpleInterfaceOLinkHelper::SigIntSignalCb(int32 ParamInt)
{
	(void)ParamInt;
}

void UTbSimpleSimpleInterfaceOLinkHelper::SigInt32SignalCb(int32 ParamInt32)
{
	(void)ParamInt32;
}

void UTbSimpleSimpleInterfaceOLinkHelper::SigInt64SignalCb(int64 ParamInt64)
{
	(void)ParamInt64;
}

void UTbSimpleSimpleInterfaceOLinkHelper::SigFloatSignalCb(float ParamFloat)
{
	(void)ParamFloat;
}

void UTbSimpleSimpleInterfaceOLinkHelper::SigFloat32SignalCb(float ParamFloat32)
{
	(void)ParamFloat32;
}

void UTbSimpleSimpleInterfaceOLinkHelper::SigFloat64SignalCb(double ParamFloat64)
{
	(void)ParamFloat64;
}

void UTbSimpleSimpleInterfaceOLinkHelper::SigStringSignalCb(const FString& ParamString)
{
	(void)ParamString;
}

void UTbSimpleSimpleInterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	(void)bSubscribed;
}
#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
