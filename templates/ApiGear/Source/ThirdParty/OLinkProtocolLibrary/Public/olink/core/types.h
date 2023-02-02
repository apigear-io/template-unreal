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

#include "olink_common.h"
#include "nlohmann/json.hpp"
#include <string>

namespace ApiGear { namespace ObjectLink {


/**
* Olink protocol message types.
* see more https://docs.apigear.io/objectlink/#message-types
*/
enum class MsgType : int
{
    Link = 10,
    Init = 11,
    Unlink = 12,
    SetProperty = 20,
    PropertyChange = 21,
    Invoke = 30,
    InvokeReply = 31,
    Signal = 40,
    Error = 99,
};

/**
* Use this function to convert message type to string with the message name.
*/
std::string toString(MsgType type);

/**
* Choose one of the available message formats for object link protocol messages.
*/
enum MessageFormat
{
    JSON = 1,
    BSON = 2,
    MSGPACK = 3,
    CBOR = 4,
};

/**
* Logging levels for logs across the application.
*/
enum class LogLevel {
    Info,
    Debug,
    Warning,
    Error
};

/**
* Provides functions to convert between member id (properties, signals, methods) and
* object id with member name.
*/
class OLINK_EXPORT Name {
public:
    /** Use this function to get an object Id from a memberId
    * @return the objectId extracted from given memberId or the input parameter memberId
    * in case input parameter doesn't follow the protocol requirement for member id.
    */
    static std::string getObjectId(const std::string& memberId);
    /** Use this function to get a member name from a membreId
    * @return a member name extracted from given memberId or the empty string
    * in case input parameter doesn't follow the protocol requirement for member id.
    */
    static std::string getMemberName(const std::string& memberId);
    /** Use this function to check if given string fulfills the syntax of a memberId 
    * @return true if given string fulfills the syntax for memberId, false otherwise.
    */
    static bool isMemberId(const std::string& id);
    /** Use this function to combines the given objectId and a member name into a memberId according to protocol*/
    static std::string createMemberId(const std::string& objectId, const std::string& memberName);
};

/**
* 
*/
class OLINK_EXPORT MessageConverter {
public:
    /**ctor
    * @param network message format used for packing messages
    */
    MessageConverter(MessageFormat format);
    /**
    * Change network format used for message packing.
    * @param format. Requested message format.
    */
    void setMessageFormat(MessageFormat format);
    /**
    * Unpacks message received from network according to selected message format.
    * @param message A message received from network.
    * @return Unpacked message in json format.
    */
    nlohmann::json fromString(const std::string& message);
    /**
    * Formats message to selected network message format.
    * @param message Message to send, not formated.
    * @return message in network message format.
    */
    std::string toString(const nlohmann::json& j);
private:
    /**Currently used network message format*/
    MessageFormat m_format;
};

/**
* Interface for handling network messages.
*/
class OLINK_EXPORT IMessageHandler
{
public:
    virtual ~IMessageHandler() = default;
    /**
    * Use this function to translate message from network format
    * and then according to a protocol.
    * @param message from network still in network format.
    */
    virtual void handleMessage(const std::string& message) = 0;
};

/**
* Helper structure for handling invoke reply message.
*/
class OLINK_EXPORT InvokeReplyArg {
public:
    /**Consists of invoked method name and objectId of an object it was invoked on*/
    std::string methodId;
    /** Result of the method invocation. */
    nlohmann::json value;
};

/** A type of function for handling invokeReply message*/
using InvokeReplyFunc = std::function<void(InvokeReplyArg)>;

/** A type of function to log*/
using WriteLogFunc = std::function<void(LogLevel level, const std::string& msg)>;

/** A type of function to write messages to network, should be provided by network endpoint implementation
@param message formated to network format.
*/
using WriteMessageFunc = std::function<void(const std::string& msg)>;

/**
* Helper base class enabling consistent logging behavior.
*/
class OLINK_EXPORT LoggerBase {
public:
    virtual ~LoggerBase() = default;
    /**
    * Use this function to set a logger writer.
    */
    void onLog(WriteLogFunc func);
    /**
    * Use this function to log any message using set logger function.
    */
    void emitLog(LogLevel level, const std::string& msg);
private:
    /**
    * User provided function that writes a log into user defined endpoint.
    */
    WriteLogFunc m_logFunc = nullptr;
};

} } // ApiGear::ObjectLink
