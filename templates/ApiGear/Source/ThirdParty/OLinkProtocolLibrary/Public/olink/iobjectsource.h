#pragma once

#pragma warning(push)
#pragma warning(disable: 4251)
#include "core/olink_common.h"
#include <nlohmann/json.hpp>
#include <string>

namespace ApiGear {
namespace ObjectLink {

class IRemoteNode;

/**
 * @brief Describes incoming part of messages of the protocol for server side.
 * Implementation should handle messages from a client side.
 * Implementation should always remove source object from remote registry before deleting the source object.
 */
class OLINK_EXPORT IObjectSource {
public:
    virtual ~IObjectSource() = default;
    
    /**
    * Provides olink object identifier.
    * @return The olink object identifier used to connect the client side to the service side,
    * therefore it has to be the same on both sides and has to allow unambiguous linking clients to service side.
    */
    virtual std::string olinkObjectName() = 0;

    /**
    * Handler function for requesting a invoking a method of a service.
    * @param methodId The identifier of method in object. Consists of the objectId and method name.
    * @param args The arguments with which method should be invoked.
    * Method should return result to a requesting client with invokeReplyMessage.
    * 
    * see ApiGear::ObjectLink::Name::getObjectId, ApiGear::ObjectLink::getMemberName to extract objectId and signal name
    * see also: ApiGear::ObjectLink::Name::createMemberId
    */
    virtual nlohmann::json olinkInvoke(const std::string& methodId, const nlohmann::json& args) = 0;
    /**
    * Handler function for requesting a property change.
    * @param propertyId The property identifier in object. Consists of the objectId and property name.
    * @param value A value to which property is requested to be set.
    *
    * see ApiGear::ObjectLink::Name::getObjectId, ApiGear::ObjectLink::getMemberName to extract objectId and signal name
    * see also: ApiGear::ObjectLink::Name::createMemberId
    */
    virtual void olinkSetProperty(const std::string& propertyId, const nlohmann::json& value) = 0;
    /**
    * Handler function for client request linking with this service.
    * @param objectId The olink object identifier for which the connection was established.
    * @param node The endpoint to with which server side sends messages.
    */
    virtual void olinkLinked(const std::string& objectId, IRemoteNode* node) = 0;
    /**
    * Handler function for client unlink notification.
    * @param objectId The olink object identifier for which the connection is no longer used.
    */
    virtual void olinkUnlinked(const std::string& objectId) = 0;

    /**
    * A helper function for getting state of object.
    * @return State of object in json format, containing pairs of property name and its value.
    */
    virtual nlohmann::json olinkCollectProperties() = 0;
};

}} // ApiGear::ObjectLink
#pragma warning(pop)
