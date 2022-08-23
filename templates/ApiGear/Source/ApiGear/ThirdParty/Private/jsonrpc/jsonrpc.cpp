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
#include "jsonrpc.h"

using json = nlohmann::json;

namespace ApiGear { namespace JSONRPC {

JsonRpc::JsonRpc()
{
}

json JsonRpc::callMessage(Id id, string method, Params params)
{
    json j;
    j["jsonrpc"] = "2.0";
    j["id"] = id;
    j["method"] = method;
    j["params"] = params;
    return j;
}

json JsonRpc::resultMessage(Id callId, string method, json result)
{
    json j;
    j["jsonrpc"] = "2.0";
    j["id"] = callId;
    j["result"] = result;
    return j;
}

json JsonRpc::notifyMessage(string method, Params params)
{
    json j;
    j["jsonrpc"] = "2.0";
    j["method"] = method;
    j["params"] = params;
    return j;
}

json JsonRpc::errorMessage(Id id, int code, string message)
{
    json err;
    err["code"] = code;
    err["message"] = message;

    json j;
    j["jsonrpc"] = "2.0";
    if (id)
    {
        j["id"] = id;
    }
    j["error"] = err;
    return j;
}
}} // ApiGear // JSONRPC
