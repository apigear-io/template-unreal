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
#include "listeners.h"
#include <iostream>

namespace ApiGear { namespace WAMP {

void EmptyProtocolListener::handleInvocation(Id requestId, Id registrationId, Details details, Arguments arguments, ArgumentsKw argumentsKw)
{
    std::cout << "not implemented " << __func__ << std::endl;
}

void EmptyProtocolListener::handleRegistered(Id requestId, Id registrationId)
{
    std::cout << "not implemented " << __func__ << std::endl;
}

void EmptyProtocolListener::handleRegisterError(Id requestId, Details details, std::string error)
{
    std::cout << "not implemented " << __func__ << std::endl;
}

void EmptyProtocolListener::handleUnregistered(Id requestId)
{
    std::cout << "not implemented " << __func__ << std::endl;
}

void EmptyProtocolListener::handleUnregisterError(Id requestId, Details details, std::string error)
{
    std::cout << "not implemented " << __func__ << std::endl;
}

void EmptyProtocolListener::handleCall(Id requestId, Options options, std::string procedure, Arguments arguments, ArgumentsKw argumentsKw)
{
    std::cout << "not implemented " << __func__ << std::endl;
}

void EmptyProtocolListener::handleRegister(Id requestId, Options options, std::string procedure)
{
    std::cout << "not implemented " << __func__ << std::endl;
}

void EmptyProtocolListener::handleUnregister(Id requestId, Id registrationId)
{
    std::cout << "not implemented " << __func__ << std::endl;
}

void EmptyProtocolListener::handleYield(Id requestId, Options options, Arguments arguments, ArgumentsKw argumentsKw)
{
    std::cout << "not implemented " << __func__ << std::endl;
}

void EmptyProtocolListener::handleInvocationError(Id requestId, Details details, std::string error)
{
    std::cout << "not implemented " << __func__ << std::endl;
}

void EmptyProtocolListener::handleResult(Id requestId, Details details, Arguments arguments, ArgumentsKw argumentsKw)
{
    std::cout << "not implemented " << __func__ << std::endl;
}

void EmptyProtocolListener::handleCallError(Id requestId, Details details, std::string error)
{
    std::cout << "not implemented " << __func__ << std::endl;
}

void EmptyProtocolListener::handlePublished(Id requestId, Id publicationId)
{
    std::cout << "not implemented " << __func__ << std::endl;
}

void EmptyProtocolListener::handlePublishError(Id requestId, Details details, std::string error)
{
    std::cout << "not implemented " << __func__ << std::endl;
}

void EmptyProtocolListener::handleSubscribed(Id requestId, Id subscriptionId)
{
    std::cout << "not implemented " << __func__ << std::endl;
}

void EmptyProtocolListener::handleSubscribeError(Id requestId, Details details, std::string error)
{
    std::cout << "not implemented " << __func__ << std::endl;
}

void EmptyProtocolListener::handleUnsubscribed(Id requestId)
{
    std::cout << "not implemented " << __func__ << std::endl;
}

void EmptyProtocolListener::handleUnsubscribeError(Id requestId, Details details, std::string error)
{
    std::cout << "not implemented " << __func__ << std::endl;
}

void EmptyProtocolListener::handleEvent(Id subscriptionId, Id publicationId, Details details, Arguments arguments, ArgumentsKw argumentsKw)
{
    std::cout << "not implemented " << __func__ << std::endl;
}

void EmptyProtocolListener::handlePublish(Id requestId, Options options, std::string topic, Arguments arguments, ArgumentsKw argumentsKw)
{
    std::cout << "not implemented " << __func__ << std::endl;
}

void EmptyProtocolListener::handleSubscribe(Id requestId, Options options, std::string topic)
{
    std::cout << "not implemented " << __func__ << std::endl;
}

void EmptyProtocolListener::handleUnsubscribe(Id requestId, Id subscriptionId)
{
    std::cout << "not implemented " << __func__ << std::endl;
}

void EmptyProtocolListener::handleHello(std::string realm, Details details)
{
    std::cout << "not implemented " << __func__ << std::endl;
}

void EmptyProtocolListener::handleWelcome(Id sessionId, Details details)
{
    std::cout << "not implemented " << __func__ << std::endl;
}

void EmptyProtocolListener::handleGoodbye(Details details, std::string reason)
{
    std::cout << "not implemented " << __func__ << std::endl;
}

void EmptyProtocolListener::handleAbort(Details details, std::string reason)
{
    std::cout << "not implemented " << __func__ << std::endl;
}

} } // ApiGear::WAMP
