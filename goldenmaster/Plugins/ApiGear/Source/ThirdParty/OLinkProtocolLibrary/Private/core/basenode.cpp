#include "basenode.h"
#include "nothrow.h"
#include <iostream>

namespace ApiGear { namespace ObjectLink {

namespace
{
static const std::string notImplementedLog = "not implemented ";
}

void BaseNode::onWrite(WriteMessageFunc func)
{
    std::unique_lock<std::mutex> lock(m_nodeMutex);
    m_writeFunc = func;
}

void BaseNode::emitWrite(const nlohmann::json& msg)
{
    static const std::string writeMessageLog = "writeMessage: ";
    emitLogWithPayload(LogLevel::Debug, msg, writeMessageLog);

    // Copy the write function and convert under the lock, then call outside
    WriteMessageFunc writeFuncCopy;
    std::string converted;
    {
        std::unique_lock<std::mutex> lock(m_nodeMutex);
        writeFuncCopy = m_writeFunc;
        if (writeFuncCopy) {
            converted = m_converter.toString(msg);
        }
    }
    if(writeFuncCopy) {
        writeFuncCopy(converted);
    } else {
        static const std::string noWriterSetLog = "Messages are not sent if the write function is not set";
        emitLog(LogLevel::Warning, noWriterSetLog);
    }
}
void BaseNode::setMessageFormat(MessageFormat format)
{
    std::unique_lock<std::mutex> lock(m_nodeMutex);
    m_converter.setMessageFormat(format);
}

void BaseNode::setMaxMessageSize(size_t size)
{
    std::unique_lock<std::mutex> lock(m_nodeMutex);
    m_converter.setMaxMessageSize(size);
}

void BaseNode::handleMessage(const std::string& data)
{
    nlohmann::json parsed;
    std::string convertError;
    {
        std::unique_lock<std::mutex> lock(m_nodeMutex);
#if OLINK_HAS_EXCEPTIONS
        try {
            parsed = m_converter.fromString(data);
        } catch (const nlohmann::json::exception& e) {
            convertError = e.what();
        } catch (const std::exception& e) {
            convertError = e.what();
        }
#else
        parsed = m_converter.fromString(data);
#endif
    }
    // Log outside the lock to avoid ABBA deadlock with m_logMutex
    if (!convertError.empty()) {
        static const std::string handleMessageErrorLog = "handleMessage exception: ";
        emitLog(LogLevel::Error, handleMessageErrorLog, convertError);
        return;
    }
    // Protocol dispatch does not need the node mutex - it calls virtual handler methods
#if OLINK_HAS_EXCEPTIONS
    try {
        m_protocol.handleMessage(parsed, *this);
    } catch (const nlohmann::json::exception& e) {
        static const std::string handleMessageErrorLog = "handleMessage json exception: ";
        emitLog(LogLevel::Error, handleMessageErrorLog, std::string(e.what()));
    } catch (const std::exception& e) {
        static const std::string handleMessageErrorLog = "handleMessage exception: ";
        emitLog(LogLevel::Error, handleMessageErrorLog, std::string(e.what()));
    }
#else
    m_protocol.handleMessage(parsed, *this);
#endif
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
