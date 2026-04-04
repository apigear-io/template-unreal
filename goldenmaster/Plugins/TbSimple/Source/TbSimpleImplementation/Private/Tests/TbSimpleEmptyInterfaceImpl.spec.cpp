// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "TbSimple/Implementation/TbSimpleEmptyInterface.h"
#include "TbSimpleEmptyInterfaceImplFixture.h"
#include "TbSimple/Tests/TbSimpleTestsCommon.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(UTbSimpleEmptyInterfaceImplSpec, "TbSimple.EmptyInterface.Impl", TbSimpleTestFilterMask);

TSharedPtr<FTbSimpleEmptyInterfaceImplFixture> ImplFixture;

END_DEFINE_SPEC(UTbSimpleEmptyInterfaceImplSpec);

void UTbSimpleEmptyInterfaceImplSpec::Define()
{
	BeforeEach([this]()
		{
		ImplFixture = MakeShared<FTbSimpleEmptyInterfaceImplFixture>();
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
