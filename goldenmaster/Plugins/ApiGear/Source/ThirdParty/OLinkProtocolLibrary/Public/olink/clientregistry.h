#pragma once

#include "core/olink_common.h"
#include "core/uniqueidobjectstorage.h"

#include "core/basenode.h"
#include <map>
#include <vector>
#include <mutex>


namespace ApiGear {
namespace ObjectLink {

class IObjectSink;
class IClientNode;

/**
 * A Registry is a global storage to keep track of objects stored as objectSink for the messages 
 * and a client node associated with that objectSink.
 * Each object can use only one client node.
 * Each object is registered with its id, available with olinkObjectName() call.
 * This id has to be unique in the registry, only first object with same id will be registered.
 * A client node may be used for many objects.
 * Register your object and a client node separately: an object with addSink function. 
 * It is suggested that client node is added for sink when linking sink with source objectId
 * and removed from sink on unlink.
 * To use client node it needs to be registered in registry.
 * Sink object should be removed from registry before deleting it.
 */
class OLINK_EXPORT ClientRegistry: public LoggerBase {
public:
    /** dtor */
    virtual ~ClientRegistry() = default;

    /**
    * Set ClientNode for a sink object registered with objectId
    * @param objectId An id of object, for which the node should be added.
    * @param nodeId An id of a ClientNode that should be added for a source with given objectId.
    *  If other node is set for given objectId, node is not changed.
    */
    void setNode(unsigned long nodeId, const std::string& objectId);
    /**
    * Unset the ClientNode from registry for objectId.
    * @param objectId An id of object, for which the node should be removed.
    */
    void unsetNode(const std::string& objectId);

    /**
    * Registers a Sink Object with its objectId.
    * Sink Object must provide objectId that is unique in this registry.
    * @param sink A sink object added to registry.
    *   If object already exist for given objectId this sinkObject is not added.
    */
    void addSink(std::weak_ptr<IObjectSink> sink);

    /**
    * Removes a Sink Object from registry for objectId.
    * @param objectId An id of object, for which the sink should be removed.
    *   If there is no sink registered for objectId no action is taken.
    */
    void removeSink(const std::string& objectId);

    /**
    * Returns a sink object for the given objectId.
    * @param objectId Identifier of a sink Object.
    * @return Sink Object with given objectId or nullptr if no sink found for an objectId.
    */
    std::weak_ptr<IObjectSink> getSink(const std::string& objectId);

    /**
    * Returns List of ids of all ids of objects for which a node was set.
    * @param nodeId An id of a node, for which objects using it are to be found.
    * @return a collection of Ids of all the objects that use given node.
    */
    std::vector<std::string> getObjectIds(unsigned long nodeId);

    /**
    * Returns ClientNode for given objectId.
    * @param objectId An id of object, for which the node should be searched.
    * @return A node found for an objectId or nullptr if there is no objectId in registry or sink 
    * is currently not using any nodes.
    */
    std::weak_ptr<IClientNode> getNode(const std::string& objectId);

    /**
    * Use this function to register node and obtain a unique id, with which you can connect it with sink objects.
    * @return A unique id given to added node.It should be used to get or remove the node.
    */

    unsigned long registerNode(std::weak_ptr<IClientNode> node);
    /**
    * Remove the node from registry, it will be no longer valid to use with any sink object.
    */
    void unregisterNode(unsigned long id);
private:
    /**
     * Internal structure to manage sink/node associations
     */
    struct OLINK_EXPORT SinkToClientEntry{
        std::weak_ptr<IObjectSink> sink;
        unsigned long nodeId;
    };

    /**
    * Collection of registered ObjectSinks for given objectId with ClientNodes they use.
    * They objectId must be unique for whole registry, only one Object sink and one ClientNode
    * can be registered for one objectId.
    */
    std::map <std::string, SinkToClientEntry> m_entries;
    /* A mutex to guard operations on stored entries.*/
    std::mutex m_entriesMutex;
    /* Storage for client nodes, keeps them by Id*/
    UniqueIdObjectStorage<ApiGear::ObjectLink::IClientNode> m_clientNodesById;
};

} } // ApiGear::ObjectLink
