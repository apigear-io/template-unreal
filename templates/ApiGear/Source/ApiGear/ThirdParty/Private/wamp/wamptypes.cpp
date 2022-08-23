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
#include "wamptypes.h"

#include <string>
#include <map>

namespace ApiGear { namespace WAMP {

std::string toString(MessageType type) {
    static std::map<MessageType, std::string> typeNames = {
        { MessageType::HELLO, "hello" },
        { MessageType::WELCOME, "welcome" },
        { MessageType::ABORT, "abort" },
        { MessageType::GOODBYE, "goodbye" },
        { MessageType::ERROR, "error" },
        { MessageType::PUBLISH, "publish" },
        { MessageType::PUBLISHED, "published" },
        { MessageType::SUBSCRIBE, "subscribe" },
        { MessageType::SUBSCRIBED, "subscribed" },
        { MessageType::UNSUBSCRIBE, "unsubscribe" },
        { MessageType::UNSUBSCRIBED, "unsubscribed" },
        { MessageType::EVENT, "event" },
        { MessageType::CALL, "call" },
        { MessageType::RESULT, "result" },
        { MessageType::REGISTER, "register" },
        { MessageType::REGISTERED, "registered" },
        { MessageType::UNREGISTER, "unregister" },
        { MessageType::UNREGISTERED, "unregistered" },
        { MessageType::INVOCATION, "invocation" },
        { MessageType::YIELD, "yield" }
    };
    auto result = typeNames.find(type);
    if (result == typeNames.end()) {
        return std::string("unknown");
    }

    return result->second;
}


} } // ApiGear::WAMP


//IMessageWriter::~IMessageWriter()
//{
//}

//IMessageHandler::~IMessageHandler()
//{
//}
