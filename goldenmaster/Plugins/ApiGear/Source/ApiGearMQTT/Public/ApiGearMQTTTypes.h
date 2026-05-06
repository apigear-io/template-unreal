// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#pragma once

#include "CoreMinimal.h"
#include "Templates/Function.h"
#include "Misc/Guid.h"
#include "IApiGearMqttClient.h"
#include <string>

namespace ApiGear
{
namespace MQTT
{
using FCallbackFunction = TFunction<void(const IApiGearMqttClient::FReceivedMessage& Message)>;

class APIGEARMQTT_API InvokeReplyArg
{
public:
	std::string JsonValue;
};

using InvokeReplyFunc = TFunction<void(const InvokeReplyArg&)>;
} // namespace MQTT
} // namespace ApiGear
