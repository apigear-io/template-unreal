#include "basenode.h"
#include <iostream>

namespace ApiGear { namespace ObjectLink {

void BaseNode::onWrite(WriteMessageFunc func)
{
    m_writeFunc = func;
}

void BaseNode::emitWrite(const nlohmann::json& msg)
{
    emitLog(LogLevel::Debug, "writeMessage " + msg.dump());
    if(m_writeFunc) {
        m_writeFunc(m_converter.toString(msg));
    } else {
        emitLog(LogLevel::Warning, "no writer set, can not write");
    }
}
void BaseNode::setMessageFormat(MessageFormat format)
{
    m_converter.setMessageFormat(format);
}

void BaseNode::handleMessage(const std::string& data)
{
    m_protocol.handleMessage(m_converter.fromString(data), *this);
}

void BaseNode::handleLink(const std::string& objectId)
{
    emitLog(LogLevel::Warning, "not implemented " + std::string(__func__) + objectId);
}

void BaseNode::handleUnlink(const std::string& objectId)
{
    emitLog(LogLevel::Warning, "not implemented " + std::string(__func__) + objectId);
}

void BaseNode::handleInvoke(int, const std::string& methodId, const nlohmann::json& args)
{
    emitLog(LogLevel::Warning, "not implemented " + std::string(__func__) + methodId + " args " + args.dump());
}

void BaseNode::handleSetProperty(const std::string& propertyId, const nlohmann::json& value)
{
    emitLog(LogLevel::Warning, "not implemented " + std::string(__func__) + propertyId + " value " + value.dump());
}

void BaseNode::handleInit(const std::string& objectId, const nlohmann::json& props)
{
    emitLog(LogLevel::Warning, "not implemented " + std::string(__func__) + objectId + " props " + props.dump());
}

void BaseNode::handleInvokeReply(int requestId, const std::string& methodId, const nlohmann::json& value)
{
    emitLog(LogLevel::Warning, "not implemented " + std::string(__func__) + methodId +" requestId " + std::to_string(requestId) + " value " + value.dump());
}

void BaseNode::handleSignal(const std::string& signalId, const nlohmann::json& args)
{
    emitLog(LogLevel::Warning, "not implemented " + std::string(__func__) + signalId + " args " + args.dump());
}

void BaseNode::handlePropertyChange(const std::string& propertyId, const nlohmann::json& value)
{
    emitLog(LogLevel::Warning, "not implemented " + std::string(__func__) + propertyId + " value " + value.dump());
}

void BaseNode::handleError(int, int requestId, const std::string& error)
{
    emitLog(LogLevel::Warning, "not implemented " + std::string(__func__) + " requestId " + std::to_string(requestId) + " error " + error);
}

} } // ApiGear::ObjectLink
