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

#include "jsonrpc.h"
#include "types.h"
#include <map>

namespace ApiGear { namespace JSONRPC {

class RpcProtocol : public IMessageHandler
{
public:
    RpcProtocol(IRpcProtocolListener *m_listener, IMessageWriter *writer, ILogger *log, MessageFormat format);
    void doCall(string method, Params params, CallResponseFunc& func);
    void doNotify(string method, Params params);
    void onCall(string method, CallRequestFunc &func);
    void onNotify(string method, NotifyRequestFunc &func);
    void onError(ErrorResponseFunc &func);

    json fromMessage(string message);
    string toMessage(json j);
    void writeJson(json j);
    // IMessageHandler interface
public:
    Id nextId();
    void handleMessage(string message) override;
    void handleCallRequest(Id id, std::string method, Params params);
    void handleCallResult(Id id, json result);
    void handleNotifyRequest(std::string method, Params params);
    void handleError(Id id, int code, std::string error);
private:
    IRpcProtocolListener *m_listener;
    IMessageWriter *m_writer;
    ILogger* m_log;
    MessageFormat m_format;
    Id m_nextId;
    std::map<Id, CallResponseFunc> m_callsPending;
    std::map<std::string, CallRequestFunc> m_callRegistry;
    std::map<std::string, NotifyRequestFunc> m_notifyRegistry;
    ErrorResponseFunc m_errorHandler;
};
}} // ApiGear // JSONRPC
