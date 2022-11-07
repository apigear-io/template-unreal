#pragma once

#include "core/olink_common.h"
#include "nlohmann/json.hpp"
#include <string>

namespace ApiGear{
namespace ObjectLink {

class IClientNode;

/**
 * @brief Describes incoming part of messages of the protocol for client side.
 * Implementation should handle messages from a service side.
 * Implementation should always remove sink object from client registry before deleting the sink object.
 */
class OLINK_EXPORT IObjectSink {
public:
    virtual ~IObjectSink() = default;

    /**
    * Provides olink object identifier.
    * @return The olink object identifier used to connect the client side to the service side,
    * therefore it has to be the same on both sides and has to allow unambiguous linking clients to service side.
    */
    virtual std::string olinkObjectName() = 0;

    /**
    * Handler function for serving the signal emitted message from the service.
    * @param signalId The signal identifier in object. Consists of the objectId and signal name.
    * @param args Arguments with which the signal is emitted.
    * 
    * see ApiGear::ObjectLink::Name::getObjectId, ApiGear::ObjectLink::getMemberName to extract objectId and signal name
    * see also: ApiGear::ObjectLink::Name::createMemberId
    */
    virtual void olinkOnSignal(const std::string& signalId, const nlohmann::json& args) = 0;
    /**
    * Handler function for serving the property changed message from the service.
    * @param propertyId The property identifier in object. Consists the objectId and property name.
    * @param value The new value for the property.
    * 
    * see ApiGear::ObjectLink::Name::getObjectId, ApiGear::ObjectLink::getMemberName to extract objectId and property name
    * see also: ApiGear::ObjectLink::Name::createMemberId
    */
    virtual void olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value) = 0;
    /**
    * Handler function for serving the Init message.
    * @param objectId The olink object identifier for which the connection was established.
    * @param props The current values for all the properties from service side.
    * @param node The endpoint to with which client sends messages.
    */
    virtual void olinkOnInit(const std::string& objectId, const nlohmann::json& props, IClientNode* node) = 0;
    /**
    * USe this function to inform the sink that connection with service was released.
    */
    virtual void olinkOnRelease() = 0;
};

}} // ApiGear::ObjectLink
