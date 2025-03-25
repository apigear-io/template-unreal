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

#include "TbIfaceimport/Implementation/TbIfaceimportEmptyIf.h"
#include "TbIfaceimportEmptyIfImplFixture.h"
#include "TbIfaceimport/Tests/TbIfaceimportTestsCommon.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(UTbIfaceimportEmptyIfImplSpec, "TbIfaceimport.EmptyIf.Impl", TbIfaceimportTestFilterMask);

TSharedPtr<FTbIfaceimportEmptyIfImplFixture> ImplFixture;

END_DEFINE_SPEC(UTbIfaceimportEmptyIfImplSpec);

void UTbIfaceimportEmptyIfImplSpec::Define()
{
	BeforeEach([this]()
		{
		ImplFixture = MakeShared<FTbIfaceimportEmptyIfImplFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		TestTrue("Check for valid Helper", ImplFixture->GetHelper().IsValid());
		ImplFixture->GetHelper()->SetSpec(this);
		ImplFixture->GetHelper()->SetParentFixture(ImplFixture);
	});

	AfterEach([this]()
		{
		ImplFixture.Reset();
	});
}

#endif // WITH_DEV_AUTOMATION_TESTS
