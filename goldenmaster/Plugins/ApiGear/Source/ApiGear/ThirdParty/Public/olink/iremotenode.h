#pragma once

#include <string>
#include <nlohmann/json.hpp>
#include "core/olink_common.h"

namespace ApiGear {
namespace ObjectLink {

/**
 * @brief Describes outgoing messages part of the protocol for server side.
 * Implementation should send appropriate messages to client side.
 */
class OLINK_EXPORT IRemoteNode {
public:
    virtual ~IRemoteNode() = default;
    /**
     * Sends information that property has changed to send value.
     * @param propertyId Identifier that consists of the objectId and the name of the property for value has changed.
     * @param value The current value of property.
     *
     * see ApiGear::ObjectLink::Name::createMemberId to create propertyId .
     * see also: ApiGear::ObjectLink::Name::getObjectId, ApiGear::ObjectLink::getMemberName
     */
    virtual void notifyPropertyChange(const std::string& propertyId, const nlohmann::json& value) = 0;
    /**
     * Sends notification that signal has was emitted by service on server side.
     * @param signalId Identifier that consists of the objectId and the name of the signal.
     * @param args The arguments with which the signal was emitted.
     *
     * see ApiGear::ObjectLink::Name::createMemberId to create propertyId .
     * see also: ApiGear::ObjectLink::Name::getObjectId, ApiGear::ObjectLink::getMemberName
     */
    virtual void notifySignal(const std::string& signalId, const nlohmann::json& args) = 0;
};

}} //ApiGear::ObjectLink
