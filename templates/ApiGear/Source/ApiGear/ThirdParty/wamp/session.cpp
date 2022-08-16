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
#include "session.h"
#include "messages.h"
#include "protocol.h"

namespace ApiGear { namespace WAMP {

using namespace std;

Session::Session(ISessionListener *listener, IMessageWriter *writer, ILogger *log, MessageFormat format)
    : m_listener(listener), m_protocol(new Protocol(writer, log, format, this)), m_log(log), m_nextId(0), m_sessionId(0), m_sessionStatePending({{MessageType::HELLO, false}, {MessageType::GOODBYE, false}})
{
    assert(m_listener);
    assert(m_protocol);
    assert(m_log);
}

void Session::init(std::string realm)
{
    assert(m_log);
    assert(m_protocol);
    if (m_sessionStatePending[MessageType::HELLO] || m_sessionId)
    {
        m_log->info("session already initialized");
        return;
    }
    m_log->debug("Session::init()");
    json roles = json::object();
    roles["publisher"] = json::object();
    roles["subscriber"] = json::object();
    roles["caller"] = json::object();
    roles["callee"] = json::object();
    m_sessionStatePending[MessageType::HELLO] = true;
    m_protocol->writeMessage(Message::helloMessage(realm, {{"roles", roles}}));
}

void Session::shutdown(std::string message)
{
    if (m_sessionStatePending[MessageType::GOODBYE] || !m_sessionId)
    {
        m_log->debug("session already shutdown");
        return;
    }
    m_log->debug("Session::shutdown()");
    m_sessionStatePending[MessageType::GOODBYE] = true;
    m_protocol->writeMessage(Message::goodbyeMessage({{"message", message}}, "wamp.close.system_shutdown"));
}

void Session::doCall(std::string procedure, Arguments arguments, ArgumentsKw argumentsKw, ResponseFunc &func)
{
    const Id id = nextRequestId();
    m_callsPending[id] = func;
    writeMessage(Message::callMessage(id, {}, procedure, arguments, argumentsKw));
}

void Session::doRegister(string procedure, ProcedureFunc &func)
{
    const Id requestId = nextRequestId();
    m_registryPending[requestId] = make_pair(func, procedure);
    writeMessage(Message::registerMessage(requestId, {{}}, procedure));
}

void Session::doUnregister(string procedure)
{
    const Id registrationId = m_registryIds[procedure];
    const Id requestId = nextRequestId();
    writeMessage(Message::unregisterMessage(requestId, registrationId));
    // TODO: add a pending unregister request and move code to handleUnregistered
    m_registryIds.erase(procedure);
    m_registryFuncs.erase(registrationId);
}

void Session::doSubscribe(std::string topic, EventFunc &func)
{
    const Id requestId = nextRequestId();
    m_subscriptionsPending[requestId] = make_pair(func, topic);

    writeMessage(Message::subscribeMessage(requestId, {}, topic));
}

void Session::doUnsubscribe(std::string topic)
{
    const Id subscriptionId = m_subscriptionIds[topic];
    const Id requestId = nextRequestId();
    writeMessage(Message::unsubscribeMessage(requestId, subscriptionId));
}

void Session::doPublish(std::string topic, Arguments arguments, ArgumentsKw argumentsKw)
{
    const Id requestId = nextRequestId();
    writeMessage(Message::publishMessage(requestId, {}, topic, arguments, argumentsKw));
}

Id Session::nextRequestId()
{
    m_nextId++;
    return m_nextId;
}

void Session::writeMessage(json j)
{
    m_messageQueue.push(j);
    processMessageQueue();
}

void Session::processMessageQueue() {
    if(!hasJoined()) {
        return;
    }
    while(!m_messageQueue.empty()) {
        m_log->debug("drain message queue: " + std::to_string(m_messageQueue.size()));
        const json &j = m_messageQueue.front();
        m_protocol->writeMessage(j);
        m_messageQueue.pop();
    }
}

void Session::handleWelcome(Id sessionId, Details details)
{
    m_sessionStatePending[MessageType::HELLO] = false;
    m_sessionId = sessionId;
    m_log->debug("handle join " + std::to_string(sessionId));
    m_listener->onJoin();
    // make sure queued messages are delivered
    processMessageQueue();
}

void Session::handleGoodbye(Details details, std::string reason)
{
    m_sessionStatePending[MessageType::GOODBYE] = false;
    m_log->debug("handle goodbye: " + reason);
    m_sessionId = 0;
}

bool Session::hasJoined() const
{
    return m_sessionId != 0;
}

void Session::handleResult(Id requestId, Details details, Arguments arguments, ArgumentsKw argumentsKw)
{
    m_log->debug("result " + std::to_string(requestId));
    if (m_callsPending.count(requestId) == 1)
    {
        const ResponseFunc &func = m_callsPending[requestId];
        const ResponseArg response{"", details, arguments, argumentsKw};
        if (func)
            func(response);
    }
}

void Session::handleEvent(Id subscriptionId, Id publicationId, Details details, Arguments arguments, ArgumentsKw argumentsKw)
{
    m_log->debug("handle event" + std::to_string(subscriptionId));
    // get topic from subscription, or callback fro topic
    EventFunc &func = m_subscriptions[subscriptionId].first;
    std::string topic = m_subscriptions[subscriptionId].second;
    m_listener->onEvent(topic, arguments, argumentsKw);
    const EventArg response{arguments, argumentsKw};
    if (func)
        func(response);
}

void Session::handleMessage(std::string message)
{
    m_protocol->handleMessage(message);
}

void Session::handleCallError(Id requestId, Details details, string error)
{
    m_log->debug("call error" + std::to_string(requestId) + " error: " + error);
    if (m_callsPending.count(requestId) == 1)
    {
        const ResponseFunc &func = m_callsPending[requestId];
        const ResponseArg response{error, details, {}, {{}}};
        if (func)
            func(response);
    }
}

void Session::handleSubscribed(Id requestId, Id subscriptionId)
{
    m_log->debug("handle subscribed" + std::to_string(requestId) = " subscriptionId: " + std::to_string(subscriptionId));
    std::string topic = m_subscriptionsPending[requestId].second;
    m_subscriptionIds[topic] = subscriptionId;
    m_subscriptions[subscriptionId] = m_subscriptionsPending[requestId];
    m_subscriptionsPending.erase(requestId);
}

void Session::handleSubscribeError(Id requestId, Details details, string error)
{
    m_log->debug("handle subscribe error: " + std::to_string(requestId));

    m_subscriptionsPending.erase(requestId);
    m_log->warning("error subscribing: " + error);
    // TODO: call session listener
}

void Session::handleUnsubscribed(Id requestId)
{
    m_log->debug("handle unsubscribed " + std::to_string(requestId));
    // nothing todo
}

void Session::handleUnsubscribeError(Id requestId, Details details, string error)
{
    m_log->warning("handle unsubscribe error: " + error);
}

void Session::handleInvocation(Id requestId, Id registrationId, Details details, Arguments arguments, ArgumentsKw argumentsKw)
{ // invoke a registered func
    ProcedureFunc &func = m_registryFuncs[registrationId].first;
    ProcedureArg arg{details, arguments, argumentsKw};
    func(arg);
}

void Session::handleRegistered(Id requestId, Id registrationId)
{ // now we have a registrationId for our func call
    string procedure = m_registryPending[requestId].second;
    // store registration id for unregister later
    m_registryIds[procedure] = registrationId;
    // store the func of call callback
    m_registryFuncs[registrationId] = m_registryPending[requestId];
    // erase the pending registration
    m_registryPending.erase(requestId);
}

void Session::handleRegisterError(Id requestId, Details details, string error)
{
    m_log->debug("handle register error: " + error);
    m_listener->onError(error);
}

void Session::handleUnregistered(Id requestId)
{
}

void Session::handleUnregisterError(Id requestId, Details details, string error)
{
    m_log->debug("handle unregister error: " + error);
    m_listener->onError(error);
}

void Session::handlePublished(Id requestId, Id publicationId)
{
}

void Session::handlePublishError(Id requestId, Details details, string error)
{
    m_log->debug("handle publish error: " + error);
    m_listener->onError(error);
}

} } // namespace ApiGear::WAMP
