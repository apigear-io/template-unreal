#include "clientregistry.h"
#include "iobjectsink.h"
#include "iclientnode.h"


namespace ApiGear {
namespace ObjectLink {

void ClientRegistry::setNode(std::weak_ptr<IClientNode> node, const std::string& objectId)
{

    auto lockedNode = node.lock();
    if (!lockedNode){
        emitLog(LogLevel::Warning, "Trying to add node, but it is already gone. Node NOT added.");
        return;
    }

    emitLog(LogLevel::Info, "ClientRegistry.setNode: " + objectId);

    std::unique_lock<std::mutex> lock(m_entriesMutex);
    auto entryForObject = m_entries.find(objectId);
    if (entryForObject == m_entries.end()){
        auto newEntry = SinkToClientEntry();
        newEntry.node = lockedNode;
        m_entries[objectId] = newEntry;
    } else if (entryForObject->second.node.lock() == nullptr){
        entryForObject->second.node = node;
    } else if (entryForObject->second.node.lock() != lockedNode){
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
        foundEntry->second.node.reset();
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
    if (entry != m_entries.end()) {
        m_entries.erase(entry);
    }
}

std::weak_ptr<IObjectSink> ClientRegistry::getSink(const std::string& objectId)
{
    emitLog(LogLevel::Info, "ClientRegistry.getSink: " + objectId);
    std::unique_lock<std::mutex> lock(m_entriesMutex);
    auto entryForObject = m_entries.find(objectId);
    return entryForObject != m_entries.end() ? entryForObject->second.sink  : std::weak_ptr<IObjectSink>();
}

std::vector<std::string> ClientRegistry::getObjectIds(std::weak_ptr<IClientNode> node)
{
    std::vector<std::string> sinks;
    sinks.reserve(m_entries.size());
    std::unique_lock<std::mutex> lock(m_entriesMutex);
    for (auto& entry : m_entries) {
        if (entry.second.node.lock() == node.lock()) {
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
    return entry != m_entries.end() ? entry->second.node : std::weak_ptr<IClientNode>();
}

}} //namespace ApiGear::ObjectLink