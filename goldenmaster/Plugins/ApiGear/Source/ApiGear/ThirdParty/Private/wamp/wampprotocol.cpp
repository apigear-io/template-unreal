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
#include "wampprotocol.h"
#include "messages.h"

#include <vector>

using namespace std;

namespace ApiGear { namespace WAMP {

Protocol::Protocol(IMessageWriter *writer, ILogger *log, MessageFormat format, IProtocolListener *listener)
    : m_writer(writer)
    , m_log(log)
    , m_format(format)
    , m_listener(listener)
{
    assert(m_writer);
    assert(m_log);
    assert(m_listener);
}

template<typename retType>
retType getSafeValue(json j)
{
    return ( j.is_object() || j.is_array()) ? j.get<retType>() : retType();
}

void Protocol::handleMessage(std::string message)
{
    json j = toJSON(message);
    m_log->debug("handle message: " +  j.dump());
    if(!j.is_array()) {
        m_log->warning("message must be array");
        return;
    }
    switch(j[0].get<int>()) {
    case int(MessageType::HELLO): {
        const string realm = j[1].get<string>();
        const Details details = j[2].get<Details>();
        listener()->handleHello(realm, details);
        break;
    }
    case int(MessageType::WELCOME): {
        const Id id = j[1].get<Id>();
        const Details details = j[2].get<Details>();
        listener()->handleWelcome(id, details);
        break;
    }
    case int(MessageType::ABORT): {
        const Details details = j[1].get<Details>();
        const string reason = j[2].get<string>();
        listener()->handleAbort(details, reason);
        break;
    }
    case int(MessageType::GOODBYE): {
        const Details details = j[1].get<Details>();
        const string reason = j[2].get<string>();
        listener()->handleGoodbye(details, reason);
        break;
    }
    case int(MessageType::ERROR): {
        int messageType = j[1].get<int>();
        const Id requestId = j[2].get<Id>();
        const Details details = j[3].get<Details>();
        const string error = j[4].get<string>();
        switch(messageType) {
        case int(MessageType::SUBSCRIBE):
            listener()->handleSubscribeError(requestId, details, error);
            break;
        case int(MessageType::UNSUBSCRIBE):
            listener()->handleUnsubscribeError(requestId, details, error);
            break;
        case int(MessageType::PUBLISH):
            listener()->handlePublishError(requestId, details, error);
            break;
        case int(MessageType::REGISTER):
            listener()->handleRegisterError(requestId, details, error);
            break;
        case int(MessageType::UNREGISTER):
            listener()->handleUnregisterError(requestId, details, error);
            break;
        case int(MessageType::CALL):
            listener()->handleCallError(requestId, details, error);
            break;
        case int(MessageType::INVOCATION):
            listener()->handleInvocationError(requestId, details, error);
            break;
        default:
            m_log->debug("unhandled error message type");
        }
        break;
    }
    case int(MessageType::PUBLISH): {
        const Id requestId = j[1].get<Id>();
        const Options options = j[2].get<Options>();
        const string topic = j[3].get<string>();
        const Arguments args = getSafeValue<Arguments>(j[4]);
        const ArgumentsKw kwargs = getSafeValue<ArgumentsKw>(j[5]);
        listener()->handlePublish(requestId, options, topic, args, kwargs);
        break;
    }
    case int(MessageType::PUBLISHED): {
        const Id requestId = j[1].get<Id>();
        const Id publicationId = j[2].get<Id>();
        listener()->handlePublished(requestId, publicationId);
        break;
    }
    case int(MessageType::SUBSCRIBE): {
        const Id requestId = j[1].get<Id>();
        const Options options = j[2].get<Options>();
        const string topic = j[3].get<string>();
        listener()->handleSubscribe(requestId, options, topic);
        break;
    }
    case int(MessageType::SUBSCRIBED): {
        const Id requestId = j[1].get<Id>();
        const Id subscriptionId = j[2].get<Id>();
        listener()->handleSubscribed(requestId, subscriptionId);
        break;
    }
    case int(MessageType::UNSUBSCRIBE): {
        const Id requestId = j[1].get<Id>();
        const Id subscriptionId = j[2].get<Id>();
        listener()->handleUnsubscribe(requestId, subscriptionId);
        break;
    }
    case int(MessageType::UNSUBSCRIBED): {
        const Id requestId = j[1].get<Id>();
        listener()->handleUnsubscribed(requestId);
        break;
    }
    case int(MessageType::EVENT): {
        const Id subscriptionId = j[1].get<Id>();
        const Id publicationId = j[2].get<Id>();
        const Details details = j[3].get<Details>();
        const Arguments args = getSafeValue<Arguments>(j[4]);
        const ArgumentsKw kwargs = getSafeValue<ArgumentsKw>(j[5]);
        listener()->handleEvent(subscriptionId, publicationId, details, args, kwargs);
        break;
    }
    case int(MessageType::CALL): {
        const Id requestId = j[1].get<Id>();
        const Options options = j[2].get<Options>();
        const string procedure = j[3].get<string>();
        const Arguments args = getSafeValue<Arguments>(j[4]);
        const ArgumentsKw kwargs = getSafeValue<ArgumentsKw>(j[5]);
        listener()->handleCall(requestId, options, procedure, args, kwargs);
        break;
    }
    case int(MessageType::RESULT): {
        const Id requestId = j[1].get<Id>();
        const Details details = j[2].get<Details>();
        const Arguments args = j[3].get<Arguments>();
        const ArgumentsKw kwargs = getSafeValue<ArgumentsKw>(j[4]);
        listener()->handleResult(requestId, details, args, kwargs);
        break;
    }
    case int(MessageType::REGISTER): {
        const Id requestId = j[1].get<Id>();
        const Options options = j[2].get<Options>();
        const string procedure = j[3].get<string>();
        listener()->handleRegister(requestId, options, procedure);
        break;
    }
    case int(MessageType::REGISTERED): {
        const Id requestId = j[1].get<Id>();
        const Id registrationId = j[2].get<Id>();
        listener()->handleRegistered(requestId, registrationId);
        break;
    }
    case int(MessageType::UNREGISTER): {
        const Id requestId = j[1].get<Id>();
        const Id registrationId = j[2].get<Id>();
        listener()->handleUnregister(requestId, registrationId);
        break;
    }
    case int(MessageType::UNREGISTERED): {
        const Id requestId = j[1].get<Id>();
        listener()->handleUnregistered(requestId);
        break;
    }
    case int(MessageType::INVOCATION): {
        const Id requestId = j[1].get<Id>();
        const Id registrationId = j[2].get<Id>();
        const Details details = j[3].get<Details>();
        const Arguments args = getSafeValue<Arguments>(j[4]);
        const ArgumentsKw kwargs = getSafeValue<ArgumentsKw>(j[5]);
        listener()->handleInvocation(requestId, registrationId, details, args, kwargs);
        break;
    }
    case int(MessageType::YIELD): {
        const Id requestId = j[1].get<Id>();
        const Options options = j[2].get<Options>();
        const Arguments args = j[3].get<Arguments>();
        const ArgumentsKw kwargs = getSafeValue<ArgumentsKw>(j[4]);
        listener()->handleYield(requestId, options, args, kwargs);
        break;
    }
    default:
        m_log->warning("message not support " + message);
    }
}

void Protocol::writeMessage(json j)
{
    assert(m_writer);
    string message = fromJSON(j);
    m_log->debug("write message " + message);
    if(m_writer) {
        m_writer->writeMessage(message);
    } else {
        m_log->warning("no write set, can not send");
    }
}

IProtocolListener *Protocol::listener() const
{
    assert(m_listener);
    return m_listener;
}



json Protocol::toJSON(string message)
{
    switch(m_format) {
    case MessageFormat::JSON:
        return json::parse(message);
    case MessageFormat::BSON:
        return json::from_bson(message);
    case MessageFormat::MSGPACK:
        return json::from_msgpack(message);
    case MessageFormat::CBOR:
        return json::from_cbor(message);
    }

    return json();
}

string Protocol::fromJSON(json j)
{
    vector<uint8_t> v;
    switch(m_format) {
    case MessageFormat::JSON:
        return j.dump();
    case MessageFormat::BSON:
        v = json::to_bson(j);
        return string(v.begin(), v.end());
    case MessageFormat::MSGPACK:
        v = json::to_msgpack(j);
        return string(v.begin(), v.end());
    case MessageFormat::CBOR:
        v = json::to_cbor(j);
        return string(v.begin(), v.end());
    }

    return string();
}

} } // ApiGear::WAMP
