#include "clientregistry.h"
#include "iobjectsink.h"
#include "iclientnode.h"


namespace ApiGear {
namespace ObjectLink {

void ClientRegistry::setNode(unsigned long id, const std::string& objectId)
{

    auto lockedNode = m_clientNodesById.get(id).lock();
    if (!lockedNode){
        emitLog(LogLevel::Warning, "Trying to add node, but it is already gone. Node NOT added.");
    }

    emitLog(LogLevel::Info, "ClientRegistry.setNode: " + objectId);

    std::unique_lock<std::mutex> lock(m_entriesMutex);
    auto entryForObject = m_entries.find(objectId);
    if (entryForObject == m_entries.end()){
        auto newEntry = SinkToClientEntry();
        m_entries[objectId] = newEntry;
        newEntry.nodeId = id;
    } else if (entryForObject->second.nodeId == m_clientNodesById.getInvalidId()){
        entryForObject->second.nodeId = id;
    } else if (entryForObject->second.nodeId != id){
        lock.unlock();
        emitLog(LogLevel::Warning, "Trying to set a client node for " + objectId + " but other node is already set. Node was NOT changed.");
    } 
}

void ClientRegistry::unsetNode(const std::string& objectId)
{
    emitLog(LogLevel::Info, "ClientRegistry.unsetNode: " + objectId);
    std::unique_lock<std::mutex> lock(m_entriesMutex);
    auto foundEntry = m_entries.find(objectId);
    if (foundEntry != m_entries.end()){
        foundEntry->second.nodeId = m_clientNodesById.getInvalidId();
    }
}

void ClientRegistry::addSink(std::weak_ptr<IObjectSink> sink)
{
    auto lockedSink = sink.lock();
    if (!lockedSink){
        emitLog(LogLevel::Warning, "Trying to add sink object, but it is already gone. New object NOT added.");
        return;
    }

    const auto& objectId = lockedSink->olinkObjectName();
    emitLog(LogLevel::Info, "ClientRegistry.addSink: " + objectId);
    auto newEntry = SinkToClientEntry();
    newEntry.sink = lockedSink;
    newEntry.nodeId = m_clientNodesById.getInvalidId();

    std::unique_lock<std::mutex> lock(m_entriesMutex);
    auto entryForObject = m_entries.find(objectId);
    if (entryForObject == m_entries.end()){
        m_entries[objectId] = newEntry;
    } else if (entryForObject->second.sink.expired()){
        m_entries[objectId].sink = lockedSink;
    } else if (entryForObject->second.sink.lock() != lockedSink){
        lock.unlock();
        emitLog(LogLevel::Warning, "Trying to add object for " + objectId + " but object for this id is already registered. New object NOT added.");
    }
}

void ClientRegistry::removeSink(const std::string& objectId)
{
    emitLog(LogLevel::Info, "ClientRegistry.removeSink: " + objectId);
    std::unique_lock<std::mutex> lock(m_entriesMutex);
    auto entry = m_entries.find(objectId);
    if (entry != m_entries.end()) 
    {
        m_entries.erase(entry);
        lock.unlock();
    }
}

std::weak_ptr<IObjectSink> ClientRegistry::getSink(const std::string& objectId)
{
    emitLog(LogLevel::Info, "ClientRegistry.getSink: " + objectId);
    std::unique_lock<std::mutex> lock(m_entriesMutex);
    auto entryForObject = m_entries.find(objectId);
    return entryForObject != m_entries.end() ? entryForObject->second.sink  : std::weak_ptr<IObjectSink>();
}

std::vector<std::string> ClientRegistry::getObjectIds(unsigned long nodeId)
{
    std::vector<std::string> sinks;
    sinks.reserve(m_entries.size());
    std::unique_lock<std::mutex> lock(m_entriesMutex);
    for (auto& entry : m_entries) {
        if (entry.second.nodeId == nodeId) {
            sinks.push_back(entry.first);
        }
    }
    return sinks;
}

std::weak_ptr<IClientNode> ClientRegistry::getNode(const std::string& objectId)
{
    emitLog(LogLevel::Info, "ClientRegistry.getNode: " + objectId);
    std::unique_lock<std::mutex> lock(m_entriesMutex);
    auto entry = m_entries.find(objectId);
    return entry != m_entries.end() ? m_clientNodesById.get(entry->second.nodeId) : std::weak_ptr<IClientNode>();
}

unsigned long ClientRegistry::registerNode(std::weak_ptr<IClientNode> node)
{
    auto lockedNode = node.lock();
    if (!lockedNode){
        emitLog(LogLevel::Warning, "Trying to add node, but it is already gone. Node NOT added.");
    }
    return m_clientNodesById.add(lockedNode);
}

void ClientRegistry::unregisterNode(unsigned long id)
{
    if (id != m_clientNodesById.getInvalidId())
    {
        std::unique_lock<std::mutex> lock(m_entriesMutex);
        for (auto& entry : m_entries) {
            if (entry.second.nodeId == id) {
                entry.second.nodeId = m_clientNodesById.getInvalidId();
            }
        }
        lock.unlock();
        m_clientNodesById.remove(id);
    }
}

}} //namespace ApiGear::ObjectLink
