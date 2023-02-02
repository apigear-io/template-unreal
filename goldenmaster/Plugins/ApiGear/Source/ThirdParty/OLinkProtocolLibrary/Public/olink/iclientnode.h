#pragma once

#include "nlohmann/json.hpp"
#include "core/olink_common.h"
#include "core/types.h"
#include <string>

namespace ApiGear{
namespace ObjectLink{


/**
 * @brief Describes outgoing messages part of the protocol for client side.
 * Implementation should send appropriate messages to service side.
 */
class OLINK_EXPORT IClientNode {
public:
    virtual ~IClientNode() = default;
    /**
     * Sends a message to request linking this client with a service side.
     * Use this function to link remote sinks and associate them with source through this node.
     * After linking the sink will be able to receive messages from source through this node.
     * @param objectId An identifier of an object, used to find source object on service side with a matching objectId.
     *   Typically contains the module name and the object name.
     */
    virtual void linkRemote(const std::string& objectId) = 0;
    /**
    * Sends a message to inform that client no longer uses the connection to service side.
    * @param objectId An identifier of an object, used to find source object on service side with a matching objectId.
    *   Typically contains the module name and the object name.
    */
    virtual void unlinkRemote(const std::string& objectId) = 0;
    /**
     * Requests a service to invoke a method.
     * @param methodId Identifier that consists of the object identifier and the name of the method for which the invoke request is sent.
     * @param args The arguments with which method should be invoked on service side.
     * @param func a handler for a invokeReplyMessage, called when a reply message will be returned from service.
     * Make sure that the function is always valid to call, especially if the Sink is no longer available.
     *
     * see ApiGear::ObjectLink::Name::createMemberId to create methodId. 
     * see also: ApiGear::ObjectLink::Name::getObjectId, ApiGear::ObjectLink::getMemberName
     */
    virtual void invokeRemote(const std::string& methodId, const nlohmann::json& args = nlohmann::json{}, InvokeReplyFunc func = nullptr) = 0;
    /**
     * Request a service to change a property to requested value.
     * Once the request is accepted and property is changed the service side will send propertyChangeMessage.
     * @param propertyId Identifier that consists of the objectId and the name of the property for which change request is sent.
     * @param value The value of property to set to.
     * 
     * see ApiGear::ObjectLink::Name::createMemberId to create propertyId .
     * see also: ApiGear::ObjectLink::Name::getObjectId, ApiGear::ObjectLink::getMemberName
     */
    virtual void setRemoteProperty(const std::string& propertyId, const nlohmann::json& value) = 0;
};

}} // ApiGear::ObjectLink
