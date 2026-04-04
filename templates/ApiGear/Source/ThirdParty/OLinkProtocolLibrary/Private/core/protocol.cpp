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

#include "protocol.h"
#include "nothrow.h"
#include "nlohmann/json.hpp"
#include <string>


namespace ApiGear { namespace ObjectLink {

nlohmann::json Protocol::linkMessage(const std::string& objectId)
{
    return nlohmann::json::array(
                { MsgType::Link, objectId }
                );
}

nlohmann::json Protocol::unlinkMessage(const std::string& objectId)
{
    return nlohmann::json::array(
                { MsgType::Unlink, objectId }
                );
}

nlohmann::json Protocol::initMessage(const std::string& objectId, const nlohmann::json& props)
{
    return nlohmann::json::array(
                { MsgType::Init, objectId, props }
                );
}

nlohmann::json Protocol::setPropertyMessage(const std::string& propertyId, const nlohmann::json& value)
{
    return nlohmann::json::array(
                { MsgType::SetProperty, propertyId, value }
                );

}

nlohmann::json Protocol::propertyChangeMessage(const std::string& propertyId, const nlohmann::json& value)
{
    return nlohmann::json::array(
                { MsgType::PropertyChange, propertyId, value }
                );
}

nlohmann::json Protocol::invokeMessage(unsigned int requestId, const std::string& methodId, const nlohmann::json& args)
{
    return nlohmann::json::array(
                { MsgType::Invoke, requestId, methodId, args }
                );
}

nlohmann::json Protocol::invokeReplyMessage(unsigned int requestId, const std::string& methodId, const nlohmann::json& value)
{
    return nlohmann::json::array(
                { MsgType::InvokeReply, requestId, methodId, value }
                );
}

nlohmann::json Protocol::signalMessage(const std::string& signalId , const nlohmann::json& args)
{
    return nlohmann::json::array(
                { MsgType::Signal, signalId, args }
                );
}

nlohmann::json Protocol::errorMessage(MsgType msgType, int requestId, const std::string& error)
{
    return nlohmann::json::array(
                { MsgType::Error, msgType, requestId, error }
                );
}

bool Protocol::handleMessage(const nlohmann::json& msg, IProtocolListener& listener) {

    m_lastError = "";
    if(!msg.is_array()) {
        m_lastError = "message must be array";
        return false;
    }
    if(msg.size() < 1) {
        m_lastError = "message array is empty";
        return false;
    }
    if(!msg[0].is_number_integer()) {
        m_lastError = "message type must be integer";
        return false;
    }
#if OLINK_HAS_EXCEPTIONS
    try {
#endif
    const int msgType = msg[0].get<int>();
    switch(msgType) {
    case int(MsgType::Link): {
        if(msg.size() < 2) { m_lastError = "truncated Link message"; return false; }
        if(!msg[1].is_string()) { m_lastError = "Link: objectId must be string"; return false; }
        const auto& objectId = msg[1].get<std::string>();
        listener.handleLink(objectId);
        break;
    }
    case int(MsgType::Init): {
        if(msg.size() < 3) { m_lastError = "truncated Init message"; return false; }
        if(!msg[1].is_string()) { m_lastError = "Init: objectId must be string"; return false; }
        const auto& objectId = msg[1].get<std::string>();
        const auto& props = msg[2];
        listener.handleInit(objectId, props);
        break;
    }
    case int(MsgType::Unlink): {
        if(msg.size() < 2) { m_lastError = "truncated Unlink message"; return false; }
        if(!msg[1].is_string()) { m_lastError = "Unlink: objectId must be string"; return false; }
        const auto& objectId = msg[1].get<std::string>();
        listener.handleUnlink(objectId);
        break;
    }
    case int(MsgType::SetProperty): {
        if(msg.size() < 3) { m_lastError = "truncated SetProperty message"; return false; }
        if(!msg[1].is_string()) { m_lastError = "SetProperty: propertyId must be string"; return false; }
        const auto& propertyId = msg[1].get<std::string>();
        const auto& value = msg[2];
        listener.handleSetProperty(propertyId, value);
        break;
    }
    case int(MsgType::PropertyChange): {
        if(msg.size() < 3) { m_lastError = "truncated PropertyChange message"; return false; }
        if(!msg[1].is_string()) { m_lastError = "PropertyChange: propertyId must be string"; return false; }
        const auto& propertyId = msg[1].get<std::string>();
        const auto& value = msg[2];
        listener.handlePropertyChange(propertyId, value);
        break;
    }
    case int(MsgType::Invoke): {
        if(msg.size() < 4) { m_lastError = "truncated Invoke message"; return false; }
        if(!msg[1].is_number()) { m_lastError = "Invoke: requestId must be number"; return false; }
        if(!msg[2].is_string()) { m_lastError = "Invoke: methodId must be string"; return false; }
        const auto& id = msg[1].get<unsigned int>();
        const auto& methodId = msg[2].get<std::string>();
        const auto& args = msg[3];
        listener.handleInvoke(id, methodId, args);
        break;
    }
    case int(MsgType::InvokeReply): {
        if(msg.size() < 4) { m_lastError = "truncated InvokeReply message"; return false; }
        if(!msg[1].is_number()) { m_lastError = "InvokeReply: requestId must be number"; return false; }
        if(!msg[2].is_string()) { m_lastError = "InvokeReply: methodId must be string"; return false; }
        const auto& id = msg[1].get<unsigned int>();
        const auto& methodId = msg[2].get<std::string>();
        const auto& value = msg[3];
        listener.handleInvokeReply(id, methodId, value);
        break;
    }
    case int(MsgType::Signal): {
        if(msg.size() < 3) { m_lastError = "truncated Signal message"; return false; }
        if(!msg[1].is_string()) { m_lastError = "Signal: signalId must be string"; return false; }
        const auto& signalId = msg[1].get<std::string>();
        const auto& args = msg[2];
        listener.handleSignal(signalId, args);
        break;
    }
    case int(MsgType::Error): {
        if(msg.size() < 4) { m_lastError = "truncated Error message"; return false; }
        if(!msg[1].is_number_integer()) { m_lastError = "Error: msgType must be integer"; return false; }
        if(!msg[2].is_number_integer()) { m_lastError = "Error: requestId must be integer"; return false; }
        if(!msg[3].is_string()) { m_lastError = "Error: error must be string"; return false; }
        const auto& msgTypeErr = msg[1].get<int>();
        const auto& requestId = msg[2].get<int>();
        const auto& error = msg[3].get<std::string>();
        listener.handleError(msgTypeErr, requestId, error);
        break;
    }
    default:
        m_lastError = "message not supported: " + msg.dump();
        return false;
    }
#if OLINK_HAS_EXCEPTIONS
    } catch (const nlohmann::json::exception& e) {
        m_lastError = std::string("message parse error: ") + e.what();
        return false;
    }
#endif
    return true;
}

std::string Protocol::lastError()
{
    return m_lastError;
}

} } // ApiGear::ObjectLink


