
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

////////////////////////////////
// WARNING AUTOGENERATED
// DO NOT MODIFY
///////////////////////////////

#include "Testbed2NestedStruct1InterfaceWAMP.h"
#include "apig/Testbed2.json.adapter.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "unrealwamp.h"

using namespace ApiGear::WAMP;

namespace Testbed2
{
namespace NestedStruct1Interface
{
namespace Private
{
WAMPService::WAMPService()
	: ITestbed2NestedStruct1InterfaceInterface()
	, Prop1(FTestbed2NestedStruct1())
{
	EventFunc NestedStruct1InterfaceStateChangedFunc = [this](EventArg arg)
	{
		const json fields = arg.kwargs;
		if (fields.contains("prop1"))
		{
			if (Prop1 != fields["prop1"].get<FTestbed2NestedStruct1>())
			{
				Prop1 = fields["prop1"].get<FTestbed2NestedStruct1>();
				Prop1Changed.Broadcast(Prop1);
			}
		}
	};
	UnrealWamp::instance()->doSubscribe("testbed2.NestedStruct1Interface", NestedStruct1InterfaceStateChangedFunc);

	ResponseFunc GetNestedStruct1InterfaceStateFunc = [this](ResponseArg arg)
	{
		if (arg.args.size() != 1)
		{
			return;
		}
		const json fields = arg.args[0];
		if (fields.contains("prop1"))
		{
			if (Prop1 != fields["prop1"].get<FTestbed2NestedStruct1>())
			{
				Prop1 = fields["prop1"].get<FTestbed2NestedStruct1>();
				Prop1Changed.Broadcast(Prop1);
			}
		}
	};
	UnrealWamp::instance()->doCall("testbed2.NestedStruct1Interface._get", Arguments(), ArgumentsKw(), GetNestedStruct1InterfaceStateFunc);

	EventFunc sig1Func = [this](EventArg arg)
	{
		if (arg.args.size() == 1)
		{
			Sig1Signal.Broadcast(arg.args[0].get<FTestbed2NestedStruct1>());
		}
	};
	UnrealWamp::instance()->doSubscribe("testbed2.NestedStruct1Interface.sig1", sig1Func);
}

WAMPService::~WAMPService()
{
	UnrealWamp::instance()->doUnSubscribe("testbed2.NestedStruct1Interface");
	UnrealWamp::instance()->doUnSubscribe("testbed2.NestedStruct1Interface.sig1");
}

FTestbed2NestedStruct1InterfaceSig1Delegate& WAMPService::GetSig1SignalDelegate()
{
	return Sig1Signal;
}

FTestbed2NestedStruct1 WAMPService::GetProp1() const
{
	return Prop1;
}

void WAMPService::SetProp1(const FTestbed2NestedStruct1& InProp1)
{
	ArgumentsKw fields_;
	fields_["prop1"] = InProp1;
	UnrealWamp::instance()->doCall("testbed2.NestedStruct1Interface._set", Arguments(), fields_);
}

FTestbed2NestedStruct1InterfaceProp1ChangedDelegate& WAMPService::GetProp1ChangedDelegate()
{
	return Prop1Changed;
}

FTestbed2NestedStruct1 WAMPService::Func1(const FTestbed2NestedStruct1& Param1)
{
	TPromise<FTestbed2NestedStruct1> Promise;
	Async(EAsyncExecution::Thread,
		[Param1, &Promise]()
		{
			ResponseFunc GetNestedStruct1InterfaceStateFunc = [&Promise](ResponseArg arg)
			{
				if (arg.args.size() != 1)
				{
					return;
				}
				Promise.SetValue(arg.args[0].get<FTestbed2NestedStruct1>());
			};
			UnrealWamp::instance()->doCall("testbed2.NestedStruct1Interface.func1", {Param1}, ArgumentsKw(), GetNestedStruct1InterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

} // namespace Private
} // namespace NestedStruct1Interface
} // namespace Testbed2
