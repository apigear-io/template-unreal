/*
* MIT License
*
* Copyright (c) 2021 ApiGear
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/
#pragma once

#include "wamptypes.h"

namespace ApiGear { namespace WAMP {

class Message
{
public:
    Message();
    static json helloMessage(std::string realm, Details details);
    static json welcomeMessage(Id sessionId, Details details);
    static json abortMessage(Details details, std::string reason);
    static json goodbyeMessage(Details details, std::string reason);
    // publish subscribe
    static json subscribeMessage(Id requestId, Options options, std::string topic);
    static json subscribedMessage(Id requestId, Id subscriptionId);
    static json subscribeErrorMessage(Id requestId, Details details, std::string error);
    static json unsubscribeMessage(Id requestId, Id subscriptionId);
    static json unsubscribedMessage(Id requestId);
    static json unsubscribeErrorMessage(Id requestId, Details details, std::string error);
    // publishing and events
    static json publishMessage(Id requestId, Options options, std::string topic, Arguments arguments, ArgumentsKw argumentsKw);
    static json publishedMessage(Id requestId, Id publicationId);
    static json publishErrorMessage(Id requestId, Details details, std::string error);
    static json eventMessage(Id subscriptionId, Id publicationId, Details details, Arguments arguments, ArgumentsKw argumentsKw);

    // remote procesure calls
    static json registerMessage(Id requestId, Options options, std::string procedure);
    static json registeredMessage(Id requestId, Id registrationId);
    static json registerErrorMessage(Id requestId, Details details, std::string error);
    static json unregisterMessage(Id requestId, Id registrationId);
    static json unregisteredMessage(Id requestId);
    static json unregisterErrorMessage(Id requestId, Details details, std::string error);

    // calling and incocations
    static json callMessage(Id requestId, Options options, std::string procedure, Arguments arguments, ArgumentsKw argumentsKw);
    static json callErrorMessage(Id requestId, Details details, std::string error);
    static json invocationMessage(Id requestId, Id registrationId, Details details, Arguments arguments, ArgumentsKw argumentsKw);
    static json invocationErrorMessage(Id requestId, Details details, std::string error);
    static json yieldMessage(Id requestId, Options options, Arguments arguments, ArgumentsKw argumentsKw);
    static json resultMessage(Id requestId, Details details, Arguments arguments, ArgumentsKw argumentsKw);
};

} } // Apigear::WAMP

