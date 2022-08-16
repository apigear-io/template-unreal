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
#include <stdlib.h>
#include <stdio.h>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

using namespace std;

namespace ApiGear { namespace JSONRPC {

typedef unsigned long long Id;
typedef json::object_t Params;


enum class MessageFormat : int
{
    JSON = 1,
    BSON = 2,
    MSGPACK = 3,
    CBOR = 4,
};

// https://www.jsonrpc.org/specification


class Error {
public:
    int code;
    string message;
};

// handler for call responses
class CallResponseArg {
public:
    Error error;
    json result;
};

typedef std::function<void(CallResponseArg)> CallResponseFunc;


// handler for call requests
class CallRequestArg {
public:
    Params params;
};

typedef std::function<CallResponseArg(CallRequestArg)> CallRequestFunc;


// handler for notify requests
class NotifyRequestArg {
public:
    Params params;
};

typedef std::function<void(NotifyRequestArg)> NotifyRequestFunc;


// handler for error responses
class ErrorResponseArg {
public:
    Error error;
};

typedef std::function<void(ErrorResponseArg)> ErrorResponseFunc;



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


class ILogger
{
public:
    virtual ~ILogger() {}
    virtual void info(std::string message) = 0;
    virtual void debug(std::string message) = 0;
    virtual void warning(std::string message) = 0;
    virtual void error(std::string message) = 0;
};


class IRpcProtocolListener
{
public:
    virtual void onNotify(std::string method, Params params) = 0;
};
}} // ApiGear // JSONRPC
