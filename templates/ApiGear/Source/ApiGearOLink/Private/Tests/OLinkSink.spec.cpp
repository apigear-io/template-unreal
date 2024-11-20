#include "OLinkSink.h"
#include "OLinkSinkFixture.h"
THIRD_PARTY_INCLUDES_START
#include "olink/iclientnode.h"
#include "olink/clientregistry.h"
THIRD_PARTY_INCLUDES_END
#include "Misc/AutomationTest.h"
#include "Runtime/Launch/Resources/Version.h"

#if WITH_DEV_AUTOMATION_TESTS

#if (ENGINE_MAJOR_VERSION >= 5)
#if (ENGINE_MINOR_VERSION >= 5)
inline constexpr EAutomationTestFlags ApiGearOLinkSinkTestFilterMask = EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::ProductFilter;
#else
inline constexpr int ApiGearOLinkSinkTestFilterMask = EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter;
#endif
#else
constexpr int ApiGearOLinkSinkTestFilterMask = EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter;
#endif

class MockClientNode : public ApiGear::ObjectLink::IClientNode
{
	void linkRemote(const std::string&){};
	void unlinkRemote(const std::string&){};
	void invokeRemote(const std::string&, const nlohmann::json&, ApiGear::ObjectLink::InvokeReplyFunc){};
	void setRemoteProperty(const std::string&, const nlohmann::json&){};
};

BEGIN_DEFINE_SPEC(UOLinkSinkSpec, "ApiGear.OLink.Sink", ApiGearOLinkSinkTestFilterMask);

TUniquePtr<FOLinkSinkFixture> Fixture;

END_DEFINE_SPEC(UOLinkSinkSpec);

void UOLinkSinkSpec::Define()
{
	BeforeEach([this]()
		{
		Fixture = MakeUnique<FOLinkSinkFixture>();
		TestTrue("Check for valid Fixture", Fixture.IsValid());

		TestEqual(TEXT("objectname should be the same as set in the constructor"), Fixture->GetSink()->olinkObjectName(), std::string("TestSink"));
		TestEqual(TEXT("The node should be a nullptr if not set by \"onInit\""), Fixture->GetSink()->GetNode() == nullptr, true);
		TestEqual(TEXT("Sink should not be ready"), Fixture->GetSink()->IsReady(), false);
	});

	AfterEach([this]()
		{
		Fixture.Reset();
	});

	It("Test initialization", [this]()
		{
		MockClientNode TestNode;
		Fixture->GetSink()->setOnInitCallback([this, &TestNode]()
			{
			TestTrue("Sink should be ready", Fixture->GetSink()->IsReady());
			TestEqual(TEXT("The node address should be equal to the test node"), Fixture->GetSink()->GetNode() == &TestNode, true);
		});

		Fixture->GetSink()->olinkOnInit("TestSink", nlohmann::json(), &TestNode);
	});

	It("Test initialization and release", [this]()
		{
		MockClientNode TestNode;
		Fixture->GetSink()->setOnInitCallback([this, &TestNode]()
			{
			TestTrue("Sink should be ready", Fixture->GetSink()->IsReady());
			TestEqual(TEXT("The node address should be equal to the test node"), Fixture->GetSink()->GetNode() == &TestNode, true);
		});
		Fixture->GetSink()->setOnReleaseCallback([this, &TestNode]()
			{
			// we haven't released yet, values should still be valid
			TestTrue("Sink should be ready", Fixture->GetSink()->IsReady());
			TestEqual(TEXT("The node address should be equal to the test node"), Fixture->GetSink()->GetNode() == &TestNode, true);
		});

		Fixture->GetSink()->olinkOnInit("TestSink", nlohmann::json(), &TestNode);
		TestTrue("Sink should be ready", Fixture->GetSink()->IsReady());
		TestEqual(TEXT("The node address should be equal to the test node"), Fixture->GetSink()->GetNode() == &TestNode, true);

		Fixture->GetSink()->olinkOnRelease();
		TestFalse("Sink should not be ready", Fixture->GetSink()->IsReady());
		TestEqual(TEXT("The node should be a nullptr if not set by \"onInit\""), Fixture->GetSink()->GetNode() == nullptr, true);
	});

	It("Test signals", [this]()
		{
		nlohmann::json testArgs = {
			{"arg1", "value1"},
			{"arg2", 42},
			{"arg3", true}};
		Fixture->GetSink()->setOnSignalEmittedCallback([this, &testArgs](const std::string& signalName, const nlohmann::json& args)
			{
			TestEqual("The signal name should match", signalName, std::string("Signal"));
			TestEqual("The arguments should match", args, testArgs);
		});
		Fixture->GetSink()->olinkOnSignal("TestModule.TestSink/Signal", testArgs);
	});

	It("Test properties", [this]()
		{
		nlohmann::json testArgs = {
			{"arg1", "value1"},
			{"arg2", 42},
			{"arg3", true}};
		Fixture->GetSink()->setOnPropertyChangedCallback([this, &testArgs](const nlohmann::json& args)
			{
			nlohmann::json modifiedTestArgs = {
				{"Property", testArgs}};
			TestEqual("The arguments should match", args, modifiedTestArgs);
		});
		Fixture->GetSink()->olinkOnPropertyChanged("TestModule.TestSink/Property", testArgs);
	});

	It("Test setting and releasing callbacks", [this]()
		{
		MockClientNode TestNode;
		Fixture->GetSink()->setOnInitCallback([this, &TestNode]()
			{
			TestTrue("This should be called", true);
		});
		Fixture->GetSink()->olinkOnInit("TestSink", nlohmann::json(), &TestNode);

		Fixture->GetSink()->setOnInitCallback([this, &TestNode]()
			{
			TestTrue("This should not be called", false);
		});
		Fixture->GetSink()->resetOnInitCallback();
		Fixture->GetSink()->olinkOnInit("TestSink", nlohmann::json(), &TestNode);

		Fixture->GetSink()->setOnReleaseCallback([this, &TestNode]()
			{
			TestTrue("This should be called", true);
		});
		Fixture->GetSink()->olinkOnRelease();

		Fixture->GetSink()->setOnReleaseCallback([this, &TestNode]()
			{
			TestTrue("This should not be called", false);
		});
		Fixture->GetSink()->resetOnReleaseCallback();
		Fixture->GetSink()->olinkOnRelease();

		Fixture->GetSink()->setOnSignalEmittedCallback([this, &TestNode](const std::string&, const nlohmann::json&)
			{
			TestTrue("This should be called", true);
		});
		Fixture->GetSink()->olinkOnSignal("TestModule.TestSink/Signal", nlohmann::json());

		Fixture->GetSink()->setOnSignalEmittedCallback([this, &TestNode](const std::string&, const nlohmann::json&)
			{
			TestTrue("This should not be called", false);
		});
		Fixture->GetSink()->resetOnSignalEmittedCallback();
		Fixture->GetSink()->olinkOnSignal("TestModule.TestSink/Signal", nlohmann::json());

		Fixture->GetSink()->setOnPropertyChangedCallback([this, &TestNode](const nlohmann::json&)
			{
			TestTrue("This should be called", true);
		});
		Fixture->GetSink()->olinkOnSignal("TestModule.TestSink/Property", nlohmann::json());

		Fixture->GetSink()->setOnPropertyChangedCallback([this, &TestNode](const nlohmann::json&)
			{
			TestTrue("This should not be called", false);
		});
		Fixture->GetSink()->resetOnPropertyChangedCallback();
		Fixture->GetSink()->olinkOnSignal("TestModule.TestSink/Property", nlohmann::json());
	});
};
#endif // WITH_DEV_AUTOMATION_TESTS
