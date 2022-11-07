#pragma once

#include "core/olink_common.h"
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
 * The client node will be added for node when linking sink with source objectId.
 * The order of registration is not relevant.
 * Sink object should always be removed from registry before deleting it.
 */
class OLINK_EXPORT ClientRegistry: public LoggerBase {
public:
    /**dtor*/
    virtual ~ClientRegistry() = default;

    /**
    * Set ClientNode for a sink object registered with objectId
    * @param objectId An id of object, for which the node should be added.
    * @param node A ClientNode that should be added for a source with given objectId.
    *   If node exist for given objectId node is not added.
    */
    void setNode(std::weak_ptr<IClientNode> node, const std::string& objectId);
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
    * @param node A node for which objects using it should be found.
    * @return a collection of Ids of all the objects that use given node.
    */
    std::vector<std::string> getObjectIds(std::weak_ptr<IClientNode> node);

    /**
    * Returns ClientNode for given objectId.
    * @param objectId An id of object, for which the node should be searched.
    * @return A node found for an objectId or nullptr if there is no objectId in registry or sink 
    * is currently not using any nodes.
    */
    std::weak_ptr<IClientNode> getNode(const std::string& objectId);
private:
    /**
     * Internal structure to manage sink/node associations
     */
    struct OLINK_EXPORT SinkToClientEntry{
        std::weak_ptr<IObjectSink> sink;
        std::weak_ptr<IClientNode> node;
    };

    /**
    * Collection of registered ObjectSinks for given objectId with ClientNodes they use.
    * They objectId must be unique for whole registry, only one Object sink and one ClientNode
    * can be registered for one objectId
    */
    std::map <std::string, SinkToClientEntry> m_entries;
    /* A mutex to guard operations on stored entries.*/
    std::mutex m_entriesMutex;
};

} } // ApiGear::ObjectLink
