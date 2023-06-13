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
#include "types.h"

#include <string>
#include <map>


namespace ApiGear { namespace ObjectLink {

// ********************************************************************
// Name
// ********************************************************************

std::string Name::getObjectId(const std::string& memberId)
{
    return memberId.substr(0, memberId.find("/"));
}

std::string Name::getMemberName(const std::string& memberId)
{
    std::string memberName = "";
    if (isMemberId(memberId)){
        memberName = memberId.substr(memberId.find_last_of("/")+1);
    }
    return memberName;
}

bool Name::isMemberId(const std::string& id)
{
    return id.find("/") != std::string::npos && id.find_first_of("/") == id.find_last_of("/");
}

std::string Name::createMemberId(const std::string& objectId, const std::string& memberName)
{
    return objectId + "/" + memberName;
}

// ********************************************************************
// MessageConverter
// ********************************************************************

MessageConverter::MessageConverter(MessageFormat format)
    : m_format(format)
{
}

void MessageConverter::setMessageFormat(MessageFormat format)
{
    m_format = format;
}

nlohmann::json MessageConverter::fromString(const std::string& message)
{
    switch(m_format) {
    case MessageFormat::JSON:
        return nlohmann::json::parse(message);
    case MessageFormat::BSON:
        return nlohmann::json::from_bson(message);
    case MessageFormat::MSGPACK:
        return nlohmann::json::from_msgpack(message);
    case MessageFormat::CBOR:
        return nlohmann::json::from_cbor(message);
    }

    return nlohmann::json();
}

std::string MessageConverter::toString(const nlohmann::json& j)
{
    switch(m_format) {
    case MessageFormat::JSON:
        return j.dump();
    case MessageFormat::BSON:
    {
        auto bsonData = nlohmann::json::to_bson(j);
        return std::string(bsonData.begin(), bsonData.end());
    }
    case MessageFormat::MSGPACK:
    {
        auto msgPackData = nlohmann::json::to_msgpack(j);
        return std::string(msgPackData.begin(), msgPackData.end());
    }
    case MessageFormat::CBOR:
    {
        auto cbotData = nlohmann::json::to_cbor(j);
        return std::string(cbotData.begin(), cbotData.end());
    }
    }
    return std::string();
}

std::string toString(MsgType type) {
    static std::map<MsgType, std::string> typeNames = {
        { MsgType::Link, "link" },
        { MsgType::Unlink, "unlink" },
        { MsgType::Init, "init" },
        { MsgType::SetProperty, "property_change" },
        { MsgType::PropertyChange, "signal_property_change" },
        { MsgType::Invoke, "invoke" },
        { MsgType::InvokeReply, "invoke_reply" },
        { MsgType::Signal, "signal" },
        { MsgType::Error, "error"
        },
    };
    auto result = typeNames.find(type);
    if (result == typeNames.end()) {
        return std::string("unknown");
    }

    return result->second;
}

// ********************************************************************
// LoggerBase
// ********************************************************************

void LoggerBase::onLog(WriteLogFunc func){
    m_logFunc = func;
}

void LoggerBase::setLogLevel(LogLevel level)
{
    m_Loglevel = level;
}

} } // ApiGear::ObjectLink
