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

#include "types.h"

namespace ApiGear { namespace WAMP {

// client -> gateway -> service
// Client: Peer, Caller, Subscriber
// Service: Peer, Callee, Publisher
// Gateway: Peer, Broker, Dealer

// client -> service
// Client: Peer, Caller, Subscriber
// Service: Peer, Broker, Dealer, Callee, Publisher


// ====================================================================
// Client               Gateway
// Peer                 Router
// ====================================================================
//            hello ->
//         <- welcome
//
//         <- abort ->
//         <- goodbye ->
// ====================================================================

class ISessionProtocolListener {
public:
    virtual ~ISessionProtocolListener() {}
    virtual void handleHello(std::string realm, Details details) = 0;
    virtual void handleWelcome(Id sessionId, Details details) = 0;
    virtual void handleGoodbye(Details details, std::string reason) = 0;
    virtual void handleAbort(Details details, std::string reason) = 0;
};

// ====================================================================
// Client               Gateway                   Service
// Subscriber           Broker                    Publisher
// ====================================================================
//
// PUBLISH AND SUBSCRIBE
//
//            subscribe ->
//         <- subscribed or error
//
//            unsubscribe ->
//         <- unsubscribed or error
//
// PUBLISHING AND EVENTS
//
//                              <- publish
//                                 published or error ->
//            <- event
// ====================================================================
// https://wamp-proto.org/_static/gen/wamp_latest.html#publish-and-subscribe
// https://wamp-proto.org/_static/gen/wamp_latest.html#publishing-and-events
// ====================================================================


class IBrokerProtocolListener {
public:
    virtual ~IBrokerProtocolListener() {}
    virtual void handlePublish(Id requestId, Options options, std::string topic, Arguments arguments, ArgumentsKw argumentsKw) = 0;
    virtual void handleSubscribe(Id requestId, Options options, std::string topic) = 0;
    virtual void handleUnsubscribe(Id requestId, Id subscriptionId) = 0;
};

class ISubscriberProtocolListener {
public:
    virtual ~ISubscriberProtocolListener() {}
    virtual void handleSubscribed(Id requestId, Id subscriptionId) = 0;
    virtual void handleSubscribeError(Id requestId, Details details, std::string error) = 0;
    virtual void handleUnsubscribed(Id requestId) = 0;
    virtual void handleUnsubscribeError(Id requestId, Details details, std::string error) = 0;
    virtual void handleEvent(Id subscriptionId, Id publicationId, Details details, Arguments arguments, ArgumentsKw argumentsKw) = 0;
};

class IPublisherProtocolListener {
public:
    virtual ~IPublisherProtocolListener() {}
    virtual void handlePublished(Id requestId, Id publicationId) = 0;
    virtual void handlePublishError(Id requestId, Details details, std::string error) = 0;
};


// ====================================================================
// Client               Gateway                   Service
// Caller               Dealer                    Callee
// ====================================================================
//
// REGISTER AND UNREGISTER
//
//                                 <- register
//                                 registered or error ->
//
//                              <- unregister
//                                 unregistered or error ->
//
// CALLING AND INVOCATIONS
//
//           call ->
//                                 invocation ->
//                              <- yield or error
//        <- result or error
// ====================================================================
// https://wamp-proto.org/_static/gen/wamp_latest.html#registering-and-unregistering
// https://wamp-proto.org/_static/gen/wamp_latest.html#calling-and-invocations
// ====================================================================


class ICallerProtocolListener {
public:
    virtual ~ICallerProtocolListener() {}
    virtual void handleResult(Id requestId, Details details, Arguments arguments, ArgumentsKw argumentsKw) = 0;
    virtual void handleCallError(Id requestId, Details details, std::string error) = 0;
};

class IDealerProtocolListener {
public:
    virtual ~IDealerProtocolListener() {}
    virtual void handleCall(Id requestId, Options options, std::string procedure, Arguments arguments, ArgumentsKw argumentsKw) = 0;
    virtual void handleRegister(Id requestId, Options options, std::string procedure) = 0;
    virtual void handleUnregister(Id requestId, Id registrationId) = 0;
    virtual void handleYield(Id requestId, Options options, Arguments arguments, ArgumentsKw argumentsKw) = 0;
    virtual void handleInvocationError(Id requestId, Details details, std::string error) = 0;
};

class ICalleeProtocolListener {
public:
    virtual ~ICalleeProtocolListener() {}
    virtual void handleInvocation(Id requestId, Id registrationId, Details details, Arguments arguments, ArgumentsKw argumentsKw) = 0;
    virtual void handleRegistered(Id requestId, Id registrationId) = 0;
    virtual void handleRegisterError(Id requestId, Details details, std::string error) = 0;
    virtual void handleUnregistered(Id requestId) = 0;
    virtual void handleUnregisterError(Id requestId, Details details, std::string error) = 0;
};



class IProtocolListener:
        public ISessionProtocolListener,
        public IBrokerProtocolListener,
        public ISubscriberProtocolListener,
        public IPublisherProtocolListener,
        public ICallerProtocolListener,
        public IDealerProtocolListener,
        public ICalleeProtocolListener
{
public:
    virtual ~IProtocolListener() {}
};


class EmptyProtocolListener : public IProtocolListener {
public:
    ~EmptyProtocolListener() {}

    // ICalleeProtocolListener interface
public:
    void handleInvocation(Id requestId, Id registrationId, Details details, Arguments arguments, ArgumentsKw argumentsKw) override;
    void handleRegistered(Id requestId, Id registrationId) override;
    void handleRegisterError(Id requestId, Details details, std::string error) override;
    void handleUnregistered(Id requestId) override;
    void handleUnregisterError(Id requestId, Details details, std::string error) override;

    // IDealerProtocolListener interface
public:
    void handleCall(Id requestId, Options options, std::string procedure, Arguments arguments, ArgumentsKw argumentsKw) override;
    void handleRegister(Id requestId, Options options, std::string procedure) override;
    void handleUnregister(Id requestId, Id registrationId) override;
    void handleYield(Id requestId, Options options, Arguments arguments, ArgumentsKw argumentsKw) override;
    void handleInvocationError(Id requestId, Details details, std::string error) override;

    // ICallerProtocolListener interface
public:
    void handleResult(Id requestId, Details details, Arguments arguments, ArgumentsKw argumentsKw) override;
    void handleCallError(Id requestId, Details details, std::string error) override;

    // IPublisherProtocolListener interface
public:
    void handlePublished(Id requestId, Id publicationId) override;
    void handlePublishError(Id requestId, Details details, std::string error) override;

    // ISubscriberProtocolListener interface
public:
    void handleSubscribed(Id requestId, Id subscriptionId) override;
    void handleSubscribeError(Id requestId, Details details, std::string error) override;
    void handleUnsubscribed(Id requestId) override;
    void handleUnsubscribeError(Id requestId, Details details, std::string error) override;
    void handleEvent(Id subscriptionId, Id publicationId, Details details, Arguments arguments, ArgumentsKw argumentsKw) override;

    // IBrokerProtocolListener interface
public:
    void handlePublish(Id requestId, Options options, std::string topic, Arguments arguments, ArgumentsKw argumentsKw) override;
    void handleSubscribe(Id requestId, Options options, std::string topic) override;
    void handleUnsubscribe(Id requestId, Id subscriptionId) override;

    // ISessionProtocolListener interface
public:
    void handleHello(std::string realm, Details details) override;
    void handleWelcome(Id sessionId, Details details) override;
    void handleGoodbye(Details details, std::string reason) override;
    void handleAbort(Details details, std::string reason) override;
};


} } // ApiGear::WAMP
