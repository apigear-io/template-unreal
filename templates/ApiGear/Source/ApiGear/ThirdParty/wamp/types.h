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

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <map>

#include "nlohmann/json.hpp"

using json = nlohmann::json;

namespace ApiGear { namespace WAMP {

typedef unsigned long long Id;
typedef json::object_t Details;
typedef json::object_t Options;
typedef json::array_t Arguments;
typedef json::object_t ArgumentsKw;

enum class MessageType : int
{
    HELLO = 1,
    WELCOME = 2,
    ABORT = 3,
    GOODBYE = 6,
    ERROR = 8,
    PUBLISH = 16,
    PUBLISHED = 17,
    SUBSCRIBE = 32,
    SUBSCRIBED = 33,
    UNSUBSCRIBE = 34,
    UNSUBSCRIBED = 35,
    EVENT = 36,
    CALL = 48,
    RESULT = 50,
    REGISTER = 64,
    REGISTERED = 65,
    UNREGISTER = 66,
    UNREGISTERED = 67,
    INVOCATION = 68,
    YIELD = 70
};

std::string toString(MessageType type);


enum class MessageFormat : int
{
    JSON = 1,
    BSON = 2,
    MSGPACK = 3,
    CBOR = 4,
};

class IMessageWriter
{
public:
    virtual ~IMessageWriter() {}
    // or vector<uint8_t>?? (byte array>
    virtual void writeMessage(std::string message) = 0;
};


class IMessageHandler
{
public:
    virtual ~IMessageHandler() {}
    // or vector<uint8_t>?? (byte array>
    virtual void handleMessage(std::string message) = 0;
};


class ISessionListener
{
public:
    virtual ~ISessionListener(){}
    virtual void onJoin() = 0;
    virtual void onError(std::string error) = 0;
    virtual void onEvent(std::string topic, Arguments args, ArgumentsKw kwargs) = 0;
};

class ResponseArg {
public:
    std::string error;
    Details details;
    Arguments args;
    ArgumentsKw kwargs;
};

typedef std::function<void(ResponseArg)> ResponseFunc;


class ProcedureArg {
public:
    Details details;
    Arguments args;
    ArgumentsKw kwargs;
};

typedef std::function<void(ProcedureArg)> ProcedureFunc;

typedef std::function<void(void)> OnJoinFun;



class EventArg {
public:
    Arguments args;
    ArgumentsKw kwargs;
};

typedef std::function<void(EventArg)> EventFunc;


class ILogger
{
public:
    virtual ~ILogger() {}
    virtual void info(std::string message) = 0;
    virtual void debug(std::string message) = 0;
    virtual void warning(std::string message) = 0;
    virtual void error(std::string message) = 0;
};


} } // ApiGear::WAMP
