#include "clientnode.h"
#include "clientregistry.h"
#include "iobjectsink.h"
#include <iostream>

namespace ApiGear { namespace ObjectLink {


ClientNode::ClientNode(ClientRegistry& registry)
    : BaseNode()
    , m_registry(registry)
{
}

void ClientNode::setNodeId(unsigned long id) {
    m_nodeId = id;
}

std::shared_ptr<ClientNode> ClientNode::create(ClientRegistry& registry)
{
    auto node = std::shared_ptr<ClientNode>(new ClientNode(registry));
    node->setNodeId(registry.registerNode(node));
    return node;
}

void ClientNode::linkRemote(const std::string& objectId)
{
    static const std::string linkRemoteLog = "ClientNode.linkRemote: ";
    emitLog(LogLevel::Info, linkRemoteLog, objectId);
    emitWrite(Protocol::linkMessage(objectId));
    m_registry.unsetNode(objectId);
    m_registry.setNode(m_nodeId, objectId);
}

void ClientNode::unlinkRemote(const std::string& objectId)
{
    static const std::string unlinkRemoteLog = "ClientNode.unlinkRemote: ";
    emitLog(LogLevel::Info, unlinkRemoteLog, objectId);
    auto sink = m_registry.getSink(objectId).lock();
    if (sink){
        sink->olinkOnRelease();
    }
    emitWrite(Protocol::unlinkMessage(objectId));
    m_registry.unsetNode(objectId);
}

void ClientNode::invokeRemote(const std::string& methodId, const nlohmann::json& args, InvokeReplyFunc func)
{
    static const std::string invokeRemoteLog = "ClientNode.invokeRemote: ";
    emitLog(LogLevel::Info, invokeRemoteLog, methodId);
    std::unique_lock<std::mutex> lock(m_pendingInvokesMutex);
    auto requestId = nextRequestId();
    m_invokesPending[requestId] = func;
    lock.unlock();
    nlohmann::json msg = Protocol::invokeMessage(requestId, methodId, args);
    emitWrite(msg);
}

void ClientNode::setRemoteProperty(const std::string& propertyId, const nlohmann::json& value)
{
    static const std::string setRemotePropertyLog = "ClientNode.setRemoteProperty: ";
    emitLog(LogLevel::Info, setRemotePropertyLog, propertyId);
    nlohmann::json msg = Protocol::setPropertyMessage(propertyId, value);
    emitWrite(msg);
}

ClientRegistry& ClientNode::registry()
{
    return m_registry;
}

ClientNode::~ClientNode()
{
    auto ids = m_registry.getObjectIds(m_nodeId);
    for (const auto& id : ids)
    {
        unlinkRemote(id);
    }
    m_registry.unregisterNode(m_nodeId);
}

unsigned long ClientNode::getNodeId() const
{
    return m_nodeId;
}

void ClientNode::handleInit(const std::string& objectId, const nlohmann::json& props)
{
    static const std::string handeInitLog = "ClientNode.handleInit: ";
    emitLogWithPayload(LogLevel::Info, props, handeInitLog, objectId);
    auto sink = m_registry.getSink(objectId).lock();
    if(sink) {
        sink->olinkOnInit(objectId, props, this);
    }
    else {
        static const std::string noSinkFoundLog = "No sink found for id ";
        emitLog(LogLevel::Warning, noSinkFoundLog, objectId);
    }
}

void ClientNode::handlePropertyChange(const std::string& propertyId, const nlohmann::json& value)
{
    static const std::string handlePropertyChangedlog = "ClientNode.handlePropertyChange: ";
    emitLogWithPayload(LogLevel::Info, value, handlePropertyChangedlog, propertyId);
    auto sink = m_registry.getSink(Name::getObjectId(propertyId)).lock();
    if(sink){
        sink->olinkOnPropertyChanged(propertyId, value);
    }
    else {
        static const std::string noSinkFoundLog = "No sink found for id ";
        emitLog(LogLevel::Warning, noSinkFoundLog, Name::getObjectId(propertyId));
    }
}

void ClientNode::handleInvokeReply(unsigned int requestId, const std::string& methodId, const nlohmann::json& value)
{
    static const std::string handleInvokeLog = "ClientNode.handleInvokeReply: ";
    emitLogWithPayload(LogLevel::Info, value, handleInvokeLog, methodId);
    std::unique_lock<std::mutex> lock(m_pendingInvokesMutex);
    auto responseHandler = m_invokesPending.find(requestId);
    InvokeReplyFunc callback = nullptr;
    if (responseHandler != m_invokesPending.end())
    {
        callback =  responseHandler->second;
        m_invokesPending.erase(responseHandler);
    }
    lock.unlock();
    if(callback) {
        const InvokeReplyArg arg{ methodId, value};
        callback(arg);
    } else {
        static const std::string noPedningInvokeLog = "no pending invoke ";
        emitLog(LogLevel::Warning, noPedningInvokeLog, methodId, std::to_string(requestId));
    }
}

void ClientNode::handleSignal(const std::string& signalId, const nlohmann::json& args)
{
    static const std::string handleSignalLog ="ClientNode.handleSignal: ";
    emitLog(LogLevel::Info, handleSignalLog, signalId);
    auto sink = m_registry.getSink(Name::getObjectId(signalId)).lock();
    if(sink) {
        sink->olinkOnSignal(signalId, args);
    } else {
        static const std::string noSinkFoundLog = "No sink found for id";
        emitLog(LogLevel::Warning, noSinkFoundLog, Name::getObjectId(signalId));
    }
}

void ClientNode::handleError(int msgType, int requestId, const std::string& error)
{
    static const std::string errorLog = "ClientNode.handleError: ";
    emitLog(LogLevel::Info, errorLog, std::to_string(msgType), std::to_string(requestId), error);
}

unsigned int ClientNode::nextRequestId()
{
    m_nextRequestId++;
    return m_nextRequestId;
}

} } // ApiGear::ObjectLink
