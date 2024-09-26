#pragma once

#if WITH_DEV_AUTOMATION_TESTS

#include "OLinkSink.h"
#include "Templates/SharedPointer.h"

class FOLinkSinkFixture
{
public:
	FOLinkSinkFixture()
	{
		Sink = MakeShared<FOLinkSink>("TestSink");
	}
	~FOLinkSinkFixture()
	{
		CleanUp();
	}

	TSharedPtr<FOLinkSink> GetSink()
	{
		return Sink;
	}

private:
	void CleanUp()
	{
		Sink.Reset();
	}

	TSharedPtr<FOLinkSink> Sink;
};

#endif // WITH_DEV_AUTOMATION_TESTS
