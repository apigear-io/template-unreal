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

namespace ApiGear { namespace ObjectLink {


/**
 * @brief listener for the protocol.
 */
class OLINK_EXPORT IProtocolListener
{
public:
    virtual ~IProtocolListener();

    virtual void handleLink(std::string name) = 0;
    virtual void handleUnlink(std::string name) = 0;
    virtual void handleInit(std::string name, nlohmann::json props) = 0;
    virtual void handleSetProperty(std::string name, nlohmann::json value) = 0;
    virtual void handlePropertyChange(std::string name, nlohmann::json value) = 0;
    virtual void handleInvoke(int requestId, std::string name, nlohmann::json args) = 0;
    virtual void handleInvokeReply(int requestId, std::string name, nlohmann::json value) = 0;
    virtual void handleSignal(std::string name, nlohmann::json args) = 0;
    virtual void handleError(int msgType, int requestId, std::string error) = 0;
};

/**
 * @brief The ObjectLink protocol
 * Functions to create olik messages and to handle all olink messages
 * On incoming messages the listeners is called.
 * A base implementation is available in BaseNode (see ndoe.h)
 */
class OLINK_EXPORT Protocol : public Base
{
public:
    Protocol(IProtocolListener *listener);
    // lifecycle
    static nlohmann::json linkMessage(std::string name);
    static nlohmann::json unlinkMessage(std::string name);
    static nlohmann::json initMessage(std::string name, nlohmann::json props);
    // properties
    static nlohmann::json setPropertyMessage(std::string name, nlohmann::json value);
    static nlohmann::json propertyChangeMessage(std::string name, nlohmann::json value);
    // remote invoke
    static nlohmann::json invokeMessage(int requestId, std::string name, nlohmann::json args);
    static nlohmann::json invokeReplyMessage(int requestId, std::string name, nlohmann::json value);
    // signal
    static nlohmann::json signalMessage(std::string name, nlohmann::json args);
    // error
    static nlohmann::json errorMessage(MsgType msgType, int requestId, std::string error);
    bool handleMessage(nlohmann::json msg);
    std::string lastError();
private:
    IProtocolListener *listener() const;
private:
    IProtocolListener* m_listener;
    std::string m_lastError;
};

} } // Apigear::ObjectLink

