#include "node.h"
#include <iostream>

namespace ApiGear { namespace ObjectLink {


// ********************************************************************
// BaseNode
// ********************************************************************


BaseNode::BaseNode()
    : Base()
    , m_writeFunc(nullptr)
    , m_converter(MessageFormat::JSON)
    , m_protocol(this)
{
}

void BaseNode::onWrite(WriteMessageFunc func)
{
    m_writeFunc = func;
}

void BaseNode::emitWrite(nlohmann::json msg)
{
    const std::string& data = m_converter.toString(msg);
    emitLog(LogLevel::Debug, "writeMessage " + msg.dump());
    if(m_writeFunc) {
        m_writeFunc(data);
    } else {
        emitLog(LogLevel::Warning, "no writer set, can not write");
    }
}


void BaseNode::handleMessage(std::string data)
{
    const nlohmann::json& j = m_converter.fromString(data);
    m_protocol.handleMessage(j);
}

void BaseNode::handleLink(std::string name)
{
    std::cout << "not implemented " << __func__ << name << std::endl;
}

void BaseNode::handleUnlink(std::string name)
{
    std::cout << "not implemented " << __func__ << name << std::endl;
}

void BaseNode::handleInvoke(int requestId, std::string name, nlohmann::json args)
{
    std::cout << "not implemented " << __func__ << requestId << name << args.dump() << std::endl;
}

void BaseNode::handleSetProperty(std::string name, nlohmann::json value)
{
    std::cout << "not implemented " << __func__ << name << value.dump() << std::endl;
}


void BaseNode::handleInit(std::string name, nlohmann::json props)
{
    std::cout << "not implemented " << __func__ << name << props.dump() << std::endl;
}

void BaseNode::handleInvokeReply(int requestId, std::string name, nlohmann::json value)
{
    std::cout << "not implemented " << __func__ << requestId << name << value.dump() << std::endl;
}

void BaseNode::handleSignal(std::string name, nlohmann::json args)
{
    std::cout << "not implemented " << __func__ << name << args.dump()  << std::endl;
}

void BaseNode::handlePropertyChange(std::string name, nlohmann::json value)
{
    std::cout << "not implemented " << __func__ << name << value.dump() << std::endl;
}

void BaseNode::handleError(int msgType, int requestId, std::string error)
{
    std::cout << "not implemented " << __func__ << msgType << requestId << error << std::endl;
}





} } // ApiGear::ObjectLink
