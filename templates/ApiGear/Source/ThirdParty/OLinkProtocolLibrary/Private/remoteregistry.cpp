#include "remoteregistry.h"
#include "iremotenode.h"
#include "iobjectsource.h"

namespace ApiGear {
namespace ObjectLink {

void RemoteRegistry::addSource(std::weak_ptr<IObjectSource> source)
{
    auto lockedSource = source.lock();
    if (!lockedSource){
        emitLog(LogLevel::Warning, "Trying to add source to registry, but source already expired");
        return;
    }
    const auto& objectId = lockedSource->olinkObjectName();
    emitLog(LogLevel::Info, "RemoteRegistry.addObjectSource: " + objectId);
    std::unique_lock<std::mutex> lock(m_entriesMutex);
    auto found = m_entries.find(objectId);
    auto anyAdded = found != m_entries.end() && !found->second.source.expired();
    auto alreadyAdded = anyAdded && found->second.source.lock() == lockedSource;
    if (found == m_entries.end()){
        SourceToNodesEntry entry;
        entry.source = source;
        m_entries[objectId] = entry;
    }
    else if (alreadyAdded){
        return;
    } else if (anyAdded) {
        emitLog(LogLevel::Info, objectId + " has already a source, source object not changed. Please remove first the existing source. Have in mind, that all associated nodes will also be removed and must be added again." );
        return;
    } 
}

void RemoteRegistry::removeSource(const std::string& objectId)
{
    emitLog(LogLevel::Info, "RemoteRegistry.removeObjectSource: " + objectId);
    removeEntry(objectId);
}

std::weak_ptr<IObjectSource> RemoteRegistry::getSource(const std::string& objectId)
{
    emitLog(LogLevel::Info, "RemoteRegistry.getObjectSource: " + objectId);
    std::unique_lock<std::mutex> lock(m_entriesMutex);
    auto found = m_entries.find(objectId);
    auto source = found != m_entries.end() ? found->second.source : std::weak_ptr<IObjectSource>();
    return source;
}

std::vector< std::weak_ptr<IRemoteNode>> RemoteRegistry::getNodes(const std::string& objectId)
{
    emitLog(LogLevel::Info, "RemoteRegistry.getRemoteNodes: " + objectId);
    std::unique_lock<std::mutex> lock(m_entriesMutex);
    auto found = m_entries.find(objectId);
    if (found != m_entries.end())
    {
        auto nodes = found->second.nodes;
        return nodes;
    } 
    return {};
}

std::vector<std::string> RemoteRegistry::getObjectIds(std::weak_ptr<IRemoteNode> node)
{
    std::vector<std::string> ids;
    std::unique_lock<std::mutex> lock(m_entriesMutex);

    for (auto& entry : m_entries) {
        auto nodeIsAdded = std::find_if(entry.second.nodes.begin(),
                                        entry.second.nodes.end(),
                                        [node](auto element){ return !node.expired() && node.lock() == element.lock(); })
                            != entry.second.nodes.end();

        if (nodeIsAdded) {
            ids.push_back(entry.first);
        }
    }
   
    return ids;
}

void RemoteRegistry::addNodeForSource(std::weak_ptr<IRemoteNode> node, const std::string& objectId)
{

    auto lockedNode = node.lock();
    if (!lockedNode){
        emitLog(LogLevel::Warning, "Trying to add node, but it is already gone. Node NOT added.");
        return;
    }

    emitLog(LogLevel::Info, "RemoteRegistry.linkRemoteNode: " + objectId);

    std::unique_lock<std::mutex> lock(m_entriesMutex);
    auto foundEntry = m_entries.find(objectId);
    if (foundEntry != m_entries.end()){
        auto alreadyAdded = std::find_if(foundEntry->second.nodes.begin(),
            foundEntry->second.nodes.end(),
            [node](auto element){ return !node.expired() && node.lock() == element.lock(); })
            != foundEntry->second.nodes.end();
        if (!alreadyAdded)
        {
            foundEntry->second.nodes.push_back(node);
        }
    }
}

void RemoteRegistry::removeNodeFromSource(std::weak_ptr<IRemoteNode> node, const std::string& objectId)
{
    emitLog(LogLevel::Info, "RemoteRegistry.removeNodeFromSource: " + objectId);
    std::unique_lock<std::mutex> lock(m_entriesMutex);
    auto found = m_entries.find(objectId);
    if (found != m_entries.end())
    {
        auto nodeInCollection = std::find_if(found->second.nodes.begin(),
                                found->second.nodes.end(),
                                [node](auto element){ return !node.expired() && node.lock() == element.lock(); });
        if (nodeInCollection != found->second.nodes.end()){
            found->second.nodes.erase(nodeInCollection);
        }
    }
}

void RemoteRegistry::removeEntry(const std::string& objectId)
{
    std::unique_lock<std::mutex> lock(m_entriesMutex);
    auto found = m_entries.find(objectId);
    if (found != m_entries.end()) {
        m_entries.erase(found);
    }
}

} } // Apigear::ObjectLink