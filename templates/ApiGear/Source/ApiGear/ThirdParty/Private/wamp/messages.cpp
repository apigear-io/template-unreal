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
#include "messages.h"
#include "nlohmann/json.hpp"


using json = nlohmann::json;

namespace ApiGear { namespace WAMP {


// See also https://github.com/crossbario/autobahn-cpp/tree/master/autobahn

Message::Message()
{

}

// ====================================================================
// session
// ====================================================================



// Client               Gateway                   Service
// Client               Router                    Service
// ===========          ===========               ===========
//            hello ->
//         <- welcome
//
//         <- abort ->
//         <- goodbye ->

// https://wamp-proto.org/_static/gen/wamp_latest.html#hello-0
json Message::helloMessage(std::string realm, Details details)
{
    return json::array(
                { MessageType::HELLO, realm, details }
                );
}

// https://wamp-proto.org/_static/gen/wamp_latest.html#welcome-0
json Message::welcomeMessage(Id sessionId, Details details)
{
    return json::array(
                { MessageType::WELCOME, sessionId, details }
                );
}

// https://wamp-proto.org/_static/gen/wamp_latest.html#abort-0
json Message::abortMessage(Details details, std::string reason)
{
    return json::array(
                { MessageType::ABORT, details, reason }
                );
}

// https://wamp-proto.org/_static/gen/wamp_latest.html#session-closing
json Message::goodbyeMessage(Details details, std::string reason)
{
    return json::array(
                { MessageType::GOODBYE, details, reason }
                );
}

// ====================================================================
// https://wamp-proto.org/_static/gen/wamp_latest.html#publish-and-subscribe
// ====================================================================


// Client               Gateway                   Service
// Subscriber           Broker                    Publisher
// ===========          ===========               ===========
//            subscribe ->
//         <- subscribed or error
//
//            unsubscribe ->
//         <- unsubscribed or error

// https://wamp-proto.org/_static/gen/wamp_latest.html#subscribe-0
json Message::subscribeMessage(Id requestId, Options options, std::string topic)
{
    return json::array(
                { MessageType::SUBSCRIBE, requestId, options, topic }
                );
}

// https://wamp-proto.org/_static/gen/wamp_latest.html#subscribed-0
json Message::subscribedMessage(Id requestId, Id subscriptionId)
{
    return json::array(
                { MessageType::SUBSCRIBED, requestId, subscriptionId }
                );
}

// https://wamp-proto.org/_static/gen/wamp_latest.html#subscribe-error
json Message::subscribeErrorMessage(Id requestId, Details details, std::string error)
{
    return json::array(
                { MessageType::ERROR, MessageType::SUBSCRIBE, requestId, details, error }
                );
}

// https://wamp-proto.org/_static/gen/wamp_latest.html#unsubscribe-0
json Message::unsubscribeMessage(Id requestId, Id subscriptionId)
{
    return json::array(
                { MessageType::UNSUBSCRIBE, requestId, subscriptionId }
                );
}

// https://wamp-proto.org/_static/gen/wamp_latest.html#unsubscribed-0
json Message::unsubscribedMessage(Id requestId)
{
    return json::array(
                { MessageType::UNSUBSCRIBED, requestId }
                );
}

// https://wamp-proto.org/_static/gen/wamp_latest.html#unsubscribe-error
json Message::unsubscribeErrorMessage(Id requestId, Details details, std::string error)
{
    return json::array(
                { MessageType::ERROR, MessageType::UNSUBSCRIBE, requestId, details, error }
                );
}

// ====================================================================
// https://wamp-proto.org/_static/gen/wamp_latest.html#publishing-and-events
// ====================================================================


// Client               Gateway                   Service
// Subscriber           Broker                    Publisher
// ===========          ===========               ===========
//                              <- publish
//                                 published or error ->
//            <- event

// https://wamp-proto.org/_static/gen/wamp_latest.html#publish-0
json Message::publishMessage(Id requestId, Options options, std::string topic, Arguments arguments, ArgumentsKw argumentsKw)
{
    return json::array(
                { MessageType::PUBLISH, requestId, options, topic, arguments, argumentsKw }
                );

}

// https://wamp-proto.org/_static/gen/wamp_latest.html#published-0
json Message::publishedMessage(Id requestId, Id publicationId)
{
    return json::array(
                { MessageType::PUBLISHED, requestId, publicationId }
                );

}

// https://wamp-proto.org/_static/gen/wamp_latest.html#publish-error
json Message::publishErrorMessage(Id requestId, Details details, std::string error)
{
    return json::array(
                { MessageType::ERROR, MessageType::PUBLISH, requestId, details, error }
                );
}


json Message::eventMessage(Id subscriptionId, Id publicationId, Details details, Arguments arguments, ArgumentsKw argumentsKw)
{
    return json::array(
                { MessageType::EVENT, subscriptionId, publicationId, details, arguments, argumentsKw }
                );
}


// ====================================================================
// https://wamp-proto.org/_static/gen/wamp_latest.html#registering-and-unregistering
// ====================================================================


// Client               Gateway                   Service
// Caller               Dealer                    Callee
// ===========          ===========               ===========
//                                 <- register
//                                 registered or error ->
//
//                              <- unregister
//                                 unregistered or error ->


// https://wamp-proto.org/_static/gen/wamp_latest.html#register-0
json Message::registerMessage(Id requestId, Options options, std::string procedure)
{
    return json::array(
                { MessageType::REGISTER, requestId, options, procedure }
                );
}

// https://wamp-proto.org/_static/gen/wamp_latest.html#registered-0
json Message::registeredMessage(Id requestId, Id registrationId)
{
    return json::array(
                { MessageType::REGISTERED, requestId, registrationId }
                );

}

// https://wamp-proto.org/_static/gen/wamp_latest.html#register-error
json Message::registerErrorMessage(Id requestId, Details details, std::string error)
{
    return json::array(
                { MessageType::ERROR, MessageType::REGISTER, requestId, details, error }
                );

}

// https://wamp-proto.org/_static/gen/wamp_latest.html#unregister-0
json Message::unregisterMessage(Id requestId, Id registrationId)
{
    return json::array(
                { MessageType::UNREGISTER, requestId, registrationId }
                );

}

// https://wamp-proto.org/_static/gen/wamp_latest.html#unregistered-0
json Message::unregisteredMessage(Id requestId)
{
    return json::array(
                { MessageType::UNREGISTERED, requestId }
                );
}

// https://wamp-proto.org/_static/gen/wamp_latest.html#unregister-error
json Message::unregisterErrorMessage(Id requestId, Details details, std::string error)
{
    return json::array(
                { MessageType::ERROR, MessageType::UNREGISTER, requestId, details, error }
                );
}

// ====================================================================
// https://wamp-proto.org/_static/gen/wamp_latest.html#calling-and-invocations
// ======================================j[1==============================

// Client               Gateway                   Service
// Caller               Dealer                    Callee
// ===========          ===========               ===========
//           call ->
//                                 invocation ->
//                              <- yield or error
//        <- result or error
//

// https://wamp-proto.org/_static/gen/wamp_latest.html#call-0
json Message::callMessage(Id requestId, Options options, std::string procedure, Arguments arguments, ArgumentsKw argumentsKw)
{
    return json::array(
                { MessageType::CALL, requestId, options, procedure, arguments, argumentsKw }
                );
}

json Message::callErrorMessage(Id requestId, Details details, std::string error)
{
    return json::array(
                { MessageType::ERROR, MessageType::CALL, requestId, details, error }
                );
}

// https://wamp-proto.org/_static/gen/wamp_latest.html#invocation-0
json Message::invocationMessage(Id requestId, Id registrationId, Details details, Arguments arguments, ArgumentsKw argumentsKw)
{
    return json::array(
                { MessageType::INVOCATION, requestId, registrationId, details, arguments, argumentsKw }
                );
}

json Message::invocationErrorMessage(Id requestId, Details details, std::string error)
{
    return json::array(
                { MessageType::ERROR, MessageType::INVOCATION, requestId, details, error }
                );
}

// https://wamp-proto.org/_static/gen/wamp_latest.html#yield-0
json Message::yieldMessage(Id requestId, Options options, Arguments arguments, ArgumentsKw argumentsKw)
{
    return json::array(
                { MessageType::YIELD, requestId, options, arguments, argumentsKw }
                );
}

// https://wamp-proto.org/_static/gen/wamp_latest.html#result-0
json Message::resultMessage(Id requestId, Details details, Arguments arguments, ArgumentsKw argumentsKw)
{
    return json::array(
                { MessageType::RESULT, requestId, details, arguments, argumentsKw }
                );
}

} } // ApiGear::Wamp

