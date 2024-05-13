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
#pragma warning(push)
#pragma warning(disable: 4251)
#include "olink_common.h"
#include "types.h"
#include "nlohmann/json.hpp"
#include <cstring>

namespace ApiGear { namespace ObjectLink {


/**
 * Listener for the ObjectLink Protocol messages.
 * Provides handlers for received and decoded messages.
 * Contains handlers for all messages in protocol.
 * Not all handlers have to have full implementation for the protocol listener object,
 * some messages should be handled by server side, some by client side.
 */
class OLINK_EXPORT IProtocolListener
{
public:
    virtual ~IProtocolListener() = default;

    /**
     * Server side handler, handles link message.
     * After successful linking implementation should send initMessage back to the caller.
     * @param objectId Id of an object for which link message was received.
     */
    virtual void handleLink(const std::string& objectId) = 0;
    /**
     * Server side handler, handles unlink message.
     * @param objectId Id of an object for which unlink message was received.
     */
    virtual void handleUnlink(const std::string& objectId) = 0;
    /**
     * Client side handler, handles remote init message.
     * @param objectId Id of an object for which Init message was received
     * @param props Current values of properties for object service.
     */
    virtual void handleInit(const std::string& objectId, const nlohmann::json& props) = 0;
    /**
     * Server side handler, handles setProperty message.
     * @param propertyId Unambiguously describes property in object for which setProperty message was received.
     * @param value A value to which client request a property to be set.
     */
    virtual void handleSetProperty(const std::string& propertyId, const nlohmann::json& value) = 0;
    /**
     * Client side handler, handles propertyChange message.
     * @param propertyId Unambiguously describes property in object for which propertyChange message was received.
     * @param value A current value of property on server side
     */
    virtual void handlePropertyChange(const std::string& propertyId, const nlohmann::json& value) = 0;
    /**
     * Server side handler, handles Invoke message. 
     * Implementation shall call the method on object and return the result the invokeReplyMessage.
     * @param requestId Id of a invoke request, which should be sent back with the response.
     * @param methodId Unambiguously describes method in object for which invoke message was received.
     * @param args Arguments with which method should be invoked.
     */
    virtual void handleInvoke(unsigned int requestId, const std::string& methodId, const nlohmann::json& args) = 0;
    /**
     * Client side handler, handles invokeReply message.
     * @param requestId Identifier of a request with which the client requested method invocation.
     *    should be used to deliver the result to a caller.
     * @param methodId Unambiguously describes method in object for which invokeReply message was received.
     * @param value Method's result value.
     */
    virtual void handleInvokeReply(unsigned int requestId, const std::string& methodId, const nlohmann::json& value) = 0;
    /**
     * Client side handler, handles signal message.
     * @param signalId Unambiguously describes signal in object for which signal message was received.
     * @param args Arguments with which signal was emitted.
     */
    virtual void handleSignal(const std::string& signalId, const nlohmann::json& args) = 0;
    /**
     * Handles error message.
     * @param msgType Type of a message for which error occurred.
     * @param requestId If error is for method invocation message, this parameter holds the requestId of the invoke message.
     *   It should be used to inform the caller that the response for this call will never arrive and it should not wait for it.
     * @param error The error message.
     */
    virtual void handleError(int msgType, int requestId, const std::string& error) = 0;
};

/**
 * The ObjectLink protocol
 * Functions to create olink messages and to translate message from network and dispatch it to 
 * handlers provided by IProtocolListener.
 */
class OLINK_EXPORT Protocol : public LoggerBase
{
public:
    /**
    * Life-cycle message.
    * Composes a link message for given objectId.
    * Send this message from client side to inform the server, that a client wants to connect to service object described with objectId.
    * @param objectId Id of a service object to which client wants to connect.
    * @return Composed linkMessage in json format.
    */
    static nlohmann::json linkMessage(const std::string& objectId);
    /**
    * Life-cycle message.
    * Composes an unlink message for given objectId.
    * Send this message from client side to inform the server, that a client will no longer use the service object described wit objectId.
    * @param objectId Id of a service that client no longer wants to use. 
    * @return Composed unlinkMessage in json format.
    */
    static nlohmann::json unlinkMessage(const std::string& objectId);
    /**
    * Life-cycle message.
    * Composes an init message for given objectId and payload in json format.
    * Send this message from server side to inform the client, that a service confirmed connection, 
    * The message carries the current state of service.
    * @param objectId Id of an object for which message is dedicated.
    * @param props Current state of the properties provided by service.
    * @return Composed initMessage in json format.
    */
    static nlohmann::json initMessage(const std::string& objectId, const nlohmann::json& props);
    /**
    * Properties message.
    * Composes request a change of property described with propretyId.
    * Send this message from client side to request property change.
    * @param propertyId Id describing a property in an object. Consists of property name and objectID.
    * @param value Requested value of the property.
    * @return Composed setPropertyMessage in json format.
    */
    static nlohmann::json setPropertyMessage(const std::string& propertyId, const nlohmann::json& value);
    /**
    * Properties message.
    * Composes a notification message for change of property described with propretyId.
    * Send this message from server side to inform clients about property change.
    * @param propertyId Id describing a property in an object. Consists of property name and objectId.
    * @param value Current value of the property.
    * @return Composed propertyChangeMessage in json format.
    */
    static nlohmann::json propertyChangeMessage(const std::string& propertyId, const nlohmann::json& value);
    /**
    * Method message.
    * Composes a request of method invocation message for a methodId.
    * Send this message from client side to request method invocation.
    * @param requestId Id of a request, unique for the client object, client expects this id for the response.
    * @param methodId Id describing a method in an object. Consists of method name and objectId.
    * @param args Arguments with which method should be invoked.
    * @return Composed invokeMessage in json format.
    */
    static nlohmann::json invokeMessage(unsigned int requestId, const std::string& methodId, const nlohmann::json& args);
    /**
    * Method message.
    * Composes a response to a method invocation message for a methodId.
    * Send this message from server side to inform about method result (for non void methods).
    * @param requestId Id of a request, should match requestId send in invocation request.
    * @param methodId Id describing a method in an object. Consists of method name and objectId.
    * @param value Value that is an outcome of method invocation.
    * @return Composed invokeReplyMessage in json format.
    */
    static nlohmann::json invokeReplyMessage(unsigned int requestId, const std::string& methodId, const nlohmann::json& value);
    /**
    * Signal message.
    * Composes a notification message for signal emitted for signalId.
    * Send this message from server side to inform clients about signal emission.
    * @param signalId Id describing a signal in an object. Consists of signal name and objectId.
    * @param args Arguments with which the signal was emitted.
    * @return Composed signalMessage in json format.
    */
    static nlohmann::json signalMessage(const std::string& signalId, const nlohmann::json& args);
    /**
    * Error message.
    * Send this message to inform that message was not accepted.
    * @param requestId Filled for error of method invocation - should match requestId send in method invocation request.
    * @param error Error description.
    * @return Composed error message in json format.
    */
    static nlohmann::json errorMessage(MsgType msgType, int requestId, const std::string&error);

    /**
    * Decodes the message and calls appropriate function handler with decoded arguments.
    * @param msg A message payload in json format. 
    * @param listener An object providing handlers for protocol messages.
    * @return true if message translation was successful and a proper listener handler was called, false otherwise.
    */
    bool handleMessage(const nlohmann::json& msg, IProtocolListener& listener);
    
    /** @return error for most recent handleMessage execution*/
    std::string lastError();
private:
    /** Error for most recent handleMessage execution*/
    std::string m_lastError;
};

} } // Apigear::ObjectLink
#pragma warning(pop)
