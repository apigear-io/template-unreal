#include "basenode.h"
#include <iostream>

namespace ApiGear { namespace ObjectLink {

namespace
{
static const std::string notImplementedLog = "not implemented ";
}

void BaseNode::onWrite(WriteMessageFunc func)
{
    m_writeFunc = func;
}

void BaseNode::emitWrite(const nlohmann::json& msg)
{
    static const std::string writeMessageLog = "writeMessage: ";
    emitLogWithPayload(LogLevel::Debug, msg, writeMessageLog);
    if(m_writeFunc) {
        m_writeFunc(m_converter.toString(msg));
    } else {
        static const std::string noWriterSetLog = "Messages are not sent if the write function is not set";
        emitLog(LogLevel::Warning, noWriterSetLog);
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
    emitLog(LogLevel::Warning, notImplementedLog, std::string(__func__), objectId);
}

void BaseNode::handleUnlink(const std::string& objectId)
{
    emitLog(LogLevel::Warning, notImplementedLog, std::string(__func__), objectId);
}

void BaseNode::handleInvoke(unsigned int, const std::string& methodId, const nlohmann::json& args)
{
    emitLogWithPayload(LogLevel::Warning, args, notImplementedLog, std::string(__func__), methodId, " args ");
}

void BaseNode::handleSetProperty(const std::string& propertyId, const nlohmann::json& value)
{
    emitLogWithPayload(LogLevel::Warning, value, notImplementedLog, std::string(__func__), propertyId, " value ");
}

void BaseNode::handleInit(const std::string& objectId, const nlohmann::json& props)
{
    emitLogWithPayload(LogLevel::Warning, props, notImplementedLog, std::string(__func__), objectId, " props ");
}

void BaseNode::handleInvokeReply(unsigned int requestId, const std::string& methodId, const nlohmann::json& value)
{
    emitLog(LogLevel::Warning, notImplementedLog, std::string(__func__), methodId, " requestId ", std::to_string(requestId), " value ", value);
}

void BaseNode::handleSignal(const std::string& signalId, const nlohmann::json& args)
{
    emitLogWithPayload(LogLevel::Warning, args, notImplementedLog, std::string(__func__), signalId, " args ");
}

void BaseNode::handlePropertyChange(const std::string& propertyId, const nlohmann::json& value)
{
    emitLogWithPayload(LogLevel::Warning, value, notImplementedLog, std::string(__func__), propertyId, " value ");
}

void BaseNode::handleError(int, int requestId, const std::string& error)
{
    emitLog(LogLevel::Warning, notImplementedLog, std::string(__func__), " requestId ", std::to_string(requestId), " error ", error);
}

} } // ApiGear::ObjectLink
