#pragma once

#include "core/basenode.h"
#include "core/types.h"

#include <chrono>
#include <memory>
#include <mutex>
#include <string>
#include <vector>

namespace ApiGear {
namespace ObjectLink {

class IRemoteNode;
class IObjectSource;

/**
 * A Registry is a global storage to keep track of objects stored as objectSources and RemoteNodes associated with them.
 * Each object source provides a service, for many clients, therefore may be used with many RemoteNodes.
 * Each object is registered with its id, available with olinkObjectName() call.
 * This id has to be unique in the registry, only first object with same id will be registered.
 * Also the RemoteNode which is an abstraction for connection endpoint may be used for many objects.
 * The registration is made separately for ObjectSource and RemoteNodes. The order of registration is not relevant, but
 * they have to provide same objectId to be associated in following manner:
 * for one unique object source, there can be many remote nodes (each node may be also used for other object source).
 * Source object implementation should always be removed from registry before destroying it.
 */
class OLINK_EXPORT RemoteRegistry : public LoggerBase {
public:
    virtual ~RemoteRegistry() = default;

    /**
    * Registers a Source Object with its objectId.
    * Source Object must provide objectId that is unique in this registry.
    * @param source A source that will be added.
    *   If object already exist for given objectId this source is not added.
    */
    void addSource(std::weak_ptr<IObjectSource> source);
    
    /**
    * Removes a Source Object from registry for objectId.
    * @param objectId An id of object, for which the Source should be removed.
    *   If there is no source registered for objectId no action is taken.
    */
    void removeSource(const std::string& objectId);
    
    /**
    * Returns a source object for the given objectId.
    * @param objectId Identifier of a source Object.
    * @return Source Object with given objectId, or nullptr if no source found for an objectId.
    */
    
    std::weak_ptr<IObjectSource> getSource(const std::string& objectId);
    /**
    * Returns Collection of ids of all objects that are using given node.
    * @param node A node for which objects using it should be found.
    * @return a collection of Ids of all the objects that use given node.
    */
    
    std::vector<std::string> getObjectIds(std::weak_ptr<IRemoteNode> node);
    /**
    * Returns Remote Nodes for given objectId.
    * @param objectId An id of object, for which the nodes should be searched.
    * @return A node a collection of nodes for an objectId or nullptr if there is no objectId in registry or source 
    * is currently not using any nodes.
    */
    std::vector<std::weak_ptr<IRemoteNode>> getNodes(const std::string& objectId);
    
    /**
    * Add a RemoteNode for a Source Object registered with objectId
    * If no source yet added, the node is still going to be added, for the id.
    * @param objectId An id of object, for which the node should be added.
    * @param node A RemoteNode to be added for an object Id.
    */
    void addNodeForSource(std::weak_ptr<IRemoteNode> node, const std::string& objectId);
    /**
    * Remove the RemoteNode from registry for objectId.
    * @param objectId An id of object, for which the node should be removed.
    * @param node A RemoteNode that is going to be removed from source with given objectId.
    *   If there is no object with given objectId or given node is not among nodes registered for this objectId no action is taken.
    */
    void removeNodeFromSource(std::weak_ptr<IRemoteNode> node, const std::string& objectId);

private:

    /**
     * Internal structure to manage source - RemoteNode associations
     */
    struct OLINK_EXPORT SourceToNodesEntry {
        std::weak_ptr<IObjectSource> source;
        std::vector< std::weak_ptr<IRemoteNode>> nodes;
    };
    
    /**
    * Removes entry for given objectId.
    * @param objectId. Identifier for which an entry would be removed.
    * If entry not found no action is made.
    */
    void removeEntry(const std::string& objectId);

    /**
    * Collection of registered ObjectSources for given objectId with RemoteNodes they use.
    * They objectId must be unique for whole registry, only one Object Source can be registered for one objectId,
    * but many RemoteNodes can be used with this objectId as source can be linked with many clients.
    */
    std::map<std::string, SourceToNodesEntry> m_entries;

    std::mutex m_entriesMutex;
    
};

}} //ApiGear::ObjectLink
