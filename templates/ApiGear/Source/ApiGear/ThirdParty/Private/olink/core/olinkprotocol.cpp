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

#include "olinkprotocol.h"
#include "nlohmann/json.hpp"


namespace ApiGear { namespace ObjectLink {


// ********************************************************************
// IProtocolListener
// ********************************************************************


IProtocolListener::~IProtocolListener()
{

}

// ********************************************************************
// Protocol
// ********************************************************************


Protocol::Protocol(IProtocolListener *listener)
    : Base()
    , m_listener(listener)
{
    assert(m_listener);
}

nlohmann::json Protocol::linkMessage(std::string name)
{
    return nlohmann::json::array(
                { MsgType::Link, name }
                );
}

nlohmann::json Protocol::unlinkMessage(std::string name)
{
    return nlohmann::json::array(
                { MsgType::Unlink, name }
                );
}

nlohmann::json Protocol::initMessage(std::string name, nlohmann::json props)
{
    return nlohmann::json::array(
                { MsgType::Init, name, props }
                );
}

nlohmann::json Protocol::setPropertyMessage(std::string name, nlohmann::json value)
{
    return nlohmann::json::array(
                { MsgType::SetProperty, name, value }
                );

}

nlohmann::json Protocol::propertyChangeMessage(std::string name, nlohmann::json value)
{
    return nlohmann::json::array(
                { MsgType::PropertyChange, name, value }
                );
}

nlohmann::json Protocol::invokeMessage(int requestId, std::string name, nlohmann::json args)
{
    return nlohmann::json::array(
                { MsgType::Invoke, requestId, name, args }
                );
}

nlohmann::json Protocol::invokeReplyMessage(int requestId, std::string name, nlohmann::json value)
{
    return nlohmann::json::array(
                { MsgType::InvokeReply, requestId, name, value }
                );
}

nlohmann::json Protocol::signalMessage(std::string name, nlohmann::json args)
{
    return nlohmann::json::array(
                { MsgType::Signal, name, args }
                );
}

nlohmann::json Protocol::errorMessage(MsgType msgType, int requestId, std::string error)
{
    return nlohmann::json::array(
                { MsgType::Error, msgType, requestId, error }
                );
}

IProtocolListener *Protocol::listener() const
{
    assert(m_listener);
    return m_listener;
}

bool Protocol::handleMessage(nlohmann::json msg) {

    m_lastError = "";
    if(!msg.is_array()) {
        m_lastError = "message must be array";
        return false;
    }
    const int msgType = msg[0].get<int>();
    switch(msgType) {
    case int(MsgType::Link): {
        const std::string name = msg[1].get<std::string>();
        listener()->handleLink(name);
        break;
    }
    case int(MsgType::Init): {
        const std::string name = msg[1].get<std::string>();
        const nlohmann::json props = msg[2].get<nlohmann::json>();
        if(listener()) listener()->handleInit(name, props);
        break;
    }
    case int(MsgType::Unlink): {
        const std::string name = msg[1].get<std::string>();
        if(listener()) listener()->handleUnlink(name);
        break;
    }
    case int(MsgType::SetProperty): {
        const std::string name = msg[1].get<std::string>();
        const nlohmann::json value = msg[2].get<nlohmann::json>();
        if(listener()) listener()->handleSetProperty(name, value);
        break;
    }
    case int(MsgType::PropertyChange): {
        const std::string name = msg[1].get<std::string>();
        const nlohmann::json value = msg[2].get<nlohmann::json>();
        if(listener()) listener()->handlePropertyChange(name, value);
        break;
    }
    case int(MsgType::Invoke): {
        const int id = msg[1].get<int>();
        const std::string name = msg[2].get<std::string>();
        const nlohmann::json args = msg[3].get<nlohmann::json>();
        if(listener()) listener()->handleInvoke(id, name, args);
        break;
    }
    case int(MsgType::InvokeReply): {
        const int id = msg[1].get<int>();
        const std::string name = msg[2].get<std::string>();
        const nlohmann::json value = msg[3].get<nlohmann::json>();
        listener()->handleInvokeReply(id, name, value);
        break;
    }
    case int(MsgType::Signal): {
        const std::string name = msg[1].get<std::string>();
        const nlohmann::json args = msg[2].get<nlohmann::json>();
        listener()->handleSignal(name, args);
        break;
    }
    case int(MsgType::Error): {
        const int msgTypeErr = msg[1].get<int>();
        const int requestId = msg[2].get<int>();
        const std::string error = msg[3].get<std::string>();
        listener()->handleError(msgTypeErr, requestId, error);
        break;
    }
    default:
        m_lastError = "message not supported: " + msg.dump();
        return false;
    }
    return true;
}

} } // ApiGear::ObjectLink


