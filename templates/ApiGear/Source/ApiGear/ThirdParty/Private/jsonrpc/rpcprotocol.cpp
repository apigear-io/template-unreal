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
#include "rpcprotocol.h"

namespace ApiGear { namespace JSONRPC {

RpcProtocol::RpcProtocol(IRpcProtocolListener *listener, IMessageWriter *writer, ILogger *log, MessageFormat format)
    : m_listener(listener)
    , m_writer(writer)
    , m_log(log)
    , m_format(format)
    , m_nextId(0)
{
}

void RpcProtocol::doCall(string method, Params params, CallResponseFunc &func)
{
    Id requestId = nextId();
    m_callsPending[requestId] = func;
    writeJson(JsonRpc::callMessage(requestId, method, params));
}

void RpcProtocol::doNotify(string method, Params params)
{
    writeJson(JsonRpc::notifyMessage(method, params));
}

void RpcProtocol::onCall(string method, CallRequestFunc &func)
{
    m_callRegistry[method] = func;
}

void RpcProtocol::onNotify(string method, NotifyRequestFunc &func)
{
    m_notifyRegistry[method] = func;
}

void RpcProtocol::onError(ErrorResponseFunc &func)
{
    m_errorHandler = func;
}

void RpcProtocol::handleMessage(string message)
{
    if(m_log) {
        m_log->debug("handle message: " + message);
    }
    json j = fromMessage(message);
    Id id = 0;
    if(!j.is_object() && m_log) {
        m_log->debug("message must be an object");
        return;
    }
    if(j.contains("id") && j["id"].is_number_integer()) {
        id = j["id"].get<Id>();
    }
    // handle error ( error )
    if(j.contains("error")) {
        const json error = j["error"];
        const int code = error["code"].get<int>();
        const std::string errormessage = error["message"].get<std::string>();
        return handleError(id, code, errormessage);
    }
    // handle call request (id && method)
    if(id && j.contains("method")) {
        const std::string method = j["method"].get<std::string>();
        const Params params = j["params"].get<Params>();
        return handleCallRequest(id, method, params);
    }
    // handle call response (id && result)
    if(id && j.contains("result")) {
        // its result of a call
        if(m_log) {
            m_log->debug("call result with id" + std::to_string(id));
        }
        json result = j["result"];
        return handleCallResult(id, result);
    }
    // handle notify request (no id && method)
    if(!id && j.contains("method")) {
        const std::string method = j["method"].get<std::string>();
        const Params params = j["params"].get<Params>();
        return handleNotifyRequest(method, params);
    }


}

void RpcProtocol::handleCallRequest(Id id, string method, Params params)
{
    const CallRequestFunc& func = m_callRegistry[method];
    CallRequestArg arg;
    arg.params = params;
    const CallResponseArg result = func(arg);
    writeJson(JsonRpc::resultMessage(id, method, result.result));
}

void RpcProtocol::handleCallResult(Id id, json result)
{
    const CallResponseFunc &func = m_callsPending[id];
    CallResponseArg arg;
    arg.result = result;
    func(arg);

}

void RpcProtocol::handleNotifyRequest(string method, Params params)
{
    if(m_notifyRegistry.count(method) == 1)
    {
        const NotifyRequestFunc& func = m_notifyRegistry[method];
        NotifyRequestArg arg;
        arg.params = params;
        func(arg);
    }
    else
    {
        m_log->error("json rpc no notification registered for " + method);
    }
}

void RpcProtocol::handleError(Id id, int code, string error)
{
    if(m_log) {
        m_log->error("json rpc error id=" + std::to_string(id) + " code=" + std::to_string(code) + " message=" + error);
    }
}


json RpcProtocol::fromMessage(string message)
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

string RpcProtocol::toMessage(json j)
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

void RpcProtocol::writeJson(json j)
{
    const std::string message = toMessage(j);
    m_writer->writeMessage(message);
}

Id RpcProtocol::nextId()
{
    m_nextId++;
    return m_nextId;
}
}} // ApiGear // JSONRPC
