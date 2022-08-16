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
#include "listeners.h"

#include "nlohmann/json.hpp"
#include <queue>

using json = nlohmann::json;

namespace ApiGear { namespace WAMP {

class Protocol;

class Session : public EmptyProtocolListener, public IMessageHandler
{
public:
    Session(ISessionListener* listener, IMessageWriter *writer, ILogger *log, MessageFormat format);
    void init(std::string realm);
    void shutdown(std::string message);
public: // session
    void handleWelcome(Id sessionId, Details details) override;
    void handleGoodbye(Details details, std::string reason) override;
public: // pubsub
    void doPublish(std::string topic, Arguments arguments, ArgumentsKw argumentsKw);
    void doSubscribe(std::string topic, EventFunc &func);
    void doUnsubscribe(std::string topic);

public: // pubsub handler
    void handleEvent(Id subscriptionId, Id publicationId, Details details, Arguments arguments, ArgumentsKw argumentsKw) override;
    void handleSubscribed(Id requestId, Id subscriptionId) override;
    void handleSubscribeError(Id requestId, Details details, std::string error) override;
    void handleUnsubscribed(Id requestId) override;
    void handleUnsubscribeError(Id requestId, Details details, std::string error) override;
    void handlePublished(Id requestId, Id publicationId) override;
    void handlePublishError(Id requestId, Details details, std::string error) override;
public: // rpc calls
    void doCall(std::string procedure, Arguments arguments, ArgumentsKw argumentsKw, ResponseFunc& func);
    void doRegister(std::string procedure, ProcedureFunc& func);
    void doUnregister(std::string procedure);
public: // rpc handling
    void handleResult(Id requestId, Details details, Arguments arguments, ArgumentsKw argumentsKw) override;
    void handleCallError(Id requestId, Details details, std::string error) override;
    void handleInvocation(Id requestId, Id registrationId, Details details, Arguments arguments, ArgumentsKw argumentsKw) override;
    void handleRegistered(Id requestId, Id registrationId) override;
    void handleRegisterError(Id requestId, Details details, std::string error) override;
    void handleUnregistered(Id requestId) override;
    void handleUnregisterError(Id requestId, Details details, std::string error) override;
public: // utils
    void handleMessage(std::string message) override;
    Id nextRequestId();
    void writeMessage(json j);
    bool hasJoined() const;
    void processMessageQueue();
private:
    ISessionListener *m_listener;
    Protocol* m_protocol;
    ILogger *m_log;
    Id m_nextId;
    Id m_sessionId;
private: // rpc
    // pending hello request
    std::map<MessageType, bool> m_sessionStatePending;
    // doCall -> handleInvocation
    std::map<Id,ResponseFunc> m_callsPending;
    // rpc registry
    // lookup of procedure func by register id
    // doRegister -> handleRegistered
    std::map<Id, std::pair<ProcedureFunc, std::string> > m_registryPending;
    // lookup for registrationId by procedure URI
    std::map<std::string, Id> m_registryIds;
    // lookup procedure fnuc by registrationId
    // ProcedureFunc by registrationId see handleInvocation
    std::map<Id, std::pair<ProcedureFunc, std::string> > m_registryFuncs;

private: // pubsub

    // lookup topic by subscriptionId
    std::map<Id, std::pair<EventFunc, std::string> > m_subscriptions;
    // lookup topic by subscriptionId
    std::map<std::string, Id> m_subscriptionIds;
    // lookup of topic func by request id
    std::map<Id, std::pair<EventFunc, std::string> > m_subscriptionsPending;
    // queue used when we are not joined yet
    std::queue<json> m_messageQueue;

};


} } // ApiGear::WAMP
