#pragma once

#if WITH_DEV_AUTOMATION_TESTS

#include "ApiGearOLink/Private/OLinkHostConnection.h"

class INetworkingWebSocket;
class MockNode;

class FOLinkHostConnectionFixture
{
public:
	FOLinkHostConnectionFixture()
	{
	}
	~FOLinkHostConnectionFixture()
	{
		CleanUp();
	}

	ApiGear::ObjectLink::RemoteRegistry& GetRegistry()
	{
		return Registry;
	}

	TSharedPtr<FOLinkHostConnection> HostConnection{nullptr};

	std::shared_ptr<MockNode> Node{nullptr};

	// no clean up needed, is handled by HostConnection
	INetworkingWebSocket* Socket{nullptr};

private:
	void CleanUp()
	{
		Node.reset();
		if (HostConnection.IsValid())
		{
			HostConnection->ConnectionClosedCallBack.Unbind();
			HostConnection.Reset();
		}
	}

	ApiGear::ObjectLink::RemoteRegistry Registry;
};

#endif // WITH_DEV_AUTOMATION_TESTS
