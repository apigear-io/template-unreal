#include "CoreTypes.h"
THIRD_PARTY_INCLUDES_START
#include "olink/remoteregistry.h"
#include "olink/remotenode.h"
THIRD_PARTY_INCLUDES_END
#include "OLinkHostConnectionFixture.h"
#include "OLinkCommon.h"
#include <UObject/Object.h>
#include "ApiGearLogCategories.h"
#include "HAL/Platform.h"

#if !(PLATFORM_IOS || PLATFORM_ANDROID || PLATFORM_QNX)
#include "INetworkingWebSocket.h"
#include "Misc/AutomationTest.h"
#include "Runtime/Launch/Resources/Version.h"

#if (ENGINE_MAJOR_VERSION >= 5)
#if (ENGINE_MINOR_VERSION >= 5)
inline constexpr EAutomationTestFlags ApiGearOLinkHostConnTestFilterMask = EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::ProductFilter;
#else
inline constexpr int ApiGearOLinkHostConnTestFilterMask = EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter;
#endif
#else
constexpr int ApiGearOLinkHostConnTestFilterMask = EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter;
#endif

#if WITH_DEV_AUTOMATION_TESTS

class MockNetworkingWebSocket : public INetworkingWebSocket
{
	void SetConnectedCallBack(FWebSocketInfoCallBack CallBack) override{};
	void SetErrorCallBack(FWebSocketInfoCallBack CallBack) override{};
	void SetReceiveCallBack(FWebSocketPacketReceivedCallBack CallBack) override{};
	void SetSocketClosedCallBack(FWebSocketInfoCallBack CallBack) override{};

	bool Send(const uint8* Data, uint32 Size, bool bPrependSize = true) override
	{
		return true;
	};

	void Tick() override{};
	void Flush() override{};

	TArray<uint8> GetRawRemoteAddr(int32& OutPort) override
	{
		return TArray<uint8>();
	};
	FString RemoteEndPoint(bool bAppendPort) override
	{
		return FString();
	};
	FString LocalEndPoint(bool bAppendPort) override
	{
		return FString();
	};
	struct sockaddr_in* GetRemoteAddr() override
	{
		return nullptr;
	};

#if (ENGINE_MAJOR_VERSION >= 5 && ENGINE_MINOR_VERSION >= 4)
	virtual TArray<FString> GetUrlArgs() override
	{
		return TArray<FString>();
	}
	virtual FString GetUrlArgByName(const FString& Name) override
	{
		return FString();
	}
#endif // ENGINE_MAJOR_VERSION >= 5 && ENGINE_MINOR_VERSION >= 4
};

class MockNode final : public ApiGear::ObjectLink::RemoteNode
{
public:
	using FunctionCallback = std::function<void(const std::string&)>;

	MockNode(ApiGear::ObjectLink::RemoteRegistry& Registry)
		: ApiGear::ObjectLink::RemoteNode(Registry){
			  // Registry.registerNode(std::shared_ptr<MockNode>(this));
		  };
	// Delete the default constructor
	MockNode() = delete;
	~MockNode() final
	{
		UE_LOG(LogTemp, Log, TEXT("MockNode destroyed"));
	};

	void setCb(FunctionCallback callback)
	{
		FunctionCB = callback;
	};

	void handleMessage(const std::string& msg) final
	{
		if (FunctionCB)
		{
			FunctionCB(msg);
		}
	};

private:
	FunctionCallback FunctionCB;
};

BEGIN_DEFINE_SPEC(UOLinkHostConnectionSpec, "ApiGear.OLink.HostConnection", ApiGearOLinkHostConnTestFilterMask);

TUniquePtr<FOLinkHostConnectionFixture> Fixture;

END_DEFINE_SPEC(UOLinkHostConnectionSpec);

ApiGear::ObjectLink::WriteLogFunc logFunc = [](ApiGear::ObjectLink::LogLevel level, const std::string& msg)
{
	UE_LOG(LogTemp, Log, TEXT("%s"), UTF8_TO_TCHAR(msg.c_str()));
};

void UOLinkHostConnectionSpec::Define()
{
	BeforeEach([this]()
		{
		Fixture = MakeUnique<FOLinkHostConnectionFixture>();
		TestTrue("Check for valid Fixture", Fixture.IsValid());

		TestFalse(TEXT("The host connection should yet be valid"), Fixture->HostConnection.IsValid());

		Fixture->Socket = new MockNetworkingWebSocket();
		Fixture->HostConnection = MakeShared<FOLinkHostConnection>(Fixture->Socket, Fixture->GetRegistry(), logFunc);
		Fixture->Node = std::make_shared<MockNode>(Fixture->GetRegistry());
		Fixture->HostConnection->Node.reset();
		Fixture->HostConnection->Node = Fixture->Node;
	});

	AfterEach([this]()
		{
		Fixture.Reset();
	});

	Describe("Test Raw data", [this]()
		{
		It("Empty data", [this]()
			{
			char* str = nullptr;
			int32 size = 0;
			Fixture->Node->setCb([this](const std::string& msg)
				{
				TestEqual("Empty data", FString(msg.c_str()), TEXT(""));
			});

			Fixture->HostConnection->ReceivedRawPacket(str, size);
		});

		It("Null Terminated String", [this]()
			{
			char str[] = "Hello, World!";
			int32 size = strlen(str) + 1;
			Fixture->Node->setCb([this](const std::string& msg)
				{
				TestEqual("Converted", FString(msg.c_str()), TEXT("Hello, World!"));
			});

			Fixture->HostConnection->ReceivedRawPacket(str, size);
		});

		It("Non Empty Data", [this]()
			{
			uint8 data[] = {0x41, 0x42, 0x43, 0x44};
			int32 size = sizeof(data);
			Fixture->Node->setCb([this](const std::string& msg)
				{
				TestEqual("Converted", FString(msg.c_str()), TEXT("ABCD"));
			});

			Fixture->HostConnection->ReceivedRawPacket(data, size);
		});

		It("Partial Data", [this]()
			{
			uint8 data[] = {0x41, 0x42, 0x43, 0x44};
			int32 size = 2;
			Fixture->Node->setCb([this](const std::string& msg)
				{
				TestEqual("Converted", FString(msg.c_str()), TEXT("AB"));
			});

			Fixture->HostConnection->ReceivedRawPacket(data, size);
		});

		It("Large Data", [this]()
			{
			uint8 data[1024];
			for (int i = 0; i < 1024; i++)
			{
				data[i] = static_cast<uint8_t>(i % 256);
			}
			int32 size = sizeof(data);
			Fixture->Node->setCb([this, data, size](const std::string& msg)
				{
				TestEqual("Size", msg.size(), size);
				TestEqual("Converted msg[0]", static_cast<uint8_t>(msg[0]), 0x00);
				TestEqual("Converted msg[255]", static_cast<uint8_t>(msg[255]), 0xFF);
				TestEqual("Converted msg[256]", static_cast<uint8_t>(msg[256]), 0x00);
				TestEqual("Converted msg[511]", static_cast<uint8_t>(msg[511]), 0xFF);
			});

			Fixture->HostConnection->ReceivedRawPacket(data, size);
		});

		It("Data with Null Characters", [this]()
			{
			char str[] = "Hello\0World!";
			int32 size = sizeof(str);
			Fixture->Node->setCb([this](const std::string& msg)
				{
				TestEqual("Converted", FString(msg.c_str()), TEXT("Hello"));
			});

			Fixture->HostConnection->ReceivedRawPacket(str, size);
		});

		It("Data with Special Characters", [this]()
			{
			char str[] = "Special Characters: !@#$%^&*()";
			int32 size = sizeof(str);
			Fixture->Node->setCb([this](const std::string& msg)
				{
				TestEqual("Converted", FString(msg.c_str()), TEXT("Special Characters: !@#$%^&*()"));
			});

			Fixture->HostConnection->ReceivedRawPacket(str, size);
		});
	});
};

#endif // WITH_DEV_AUTOMATION_TESTS
#endif // !(PLATFORM_IOS || PLATFORM_ANDROID || PLATFORM_QNX)
