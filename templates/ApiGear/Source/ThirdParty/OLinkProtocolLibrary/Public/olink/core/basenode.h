#pragma once
#pragma warning(push)
#pragma warning(disable: 4251)
#include "protocol.h"
#include "types.h"
#include "olink_common.h"
#include "nlohmann/json.hpp"
#include <cstring>

namespace ApiGear { namespace ObjectLink {

/**
 * A base class for client and remote nodes.
 * Provides a functionality for sending and receiving messages according to object link protocol.
 * Translates the received data and data to send according to selected message format.
 */
class OLINK_EXPORT BaseNode: public LoggerBase,
                             public IProtocolListener,
                             public IMessageHandler {
public:
    /**
    * Network layer implementation should deliver this function,
    * with which messages are sent through network.
    */
    void onWrite(WriteMessageFunc func);
    /**
    * Use this function to format message and send it through the network.
    * It uses the WriteMessageFunc provided by network layer implementation with onWrite(WriteMessageFunc) call.
    * @param j The data to send, translated according to chosen network message format before sending.
    */
    virtual void emitWrite(const nlohmann::json& j);

    /**
    * Use to change messages network format.
    */
    void setMessageFormat(MessageFormat format);

    // Implementation::IMessageHandler
    void handleMessage(const std::string& data) override;

    // Empty, logging only implementation of IProtocolListener::handleLink, should be overwritten on server side.
    void handleLink(const std::string& objectId) override;
    // Empty, logging only implementation of IProtocolListener::handleUnlink, should be overwritten on server side.
    void handleUnlink(const std::string& objectId) override;
    // Empty, logging only implementation of IProtocolListener::handleInvoke, should be overwritten on server side.
    void handleInvoke(int requestId, const std::string& methodId, const nlohmann::json& args) override;
    // Empty, logging only implementation of IProtocolListener::handleSetProperty, should be overwritten on server side.
    void handleSetProperty(const std::string& propertyId, const nlohmann::json& value) override;
    // Empty, logging only implementation of IProtocolListener::handleInit, should be overwritten on client side.
    void handleInit(const std::string& objectId, const nlohmann::json& props) override;
    // Empty, logging only implementation of IProtocolListener::handleInvokeReply, should be overwritten on client side.
    void handleInvokeReply(int requestId, const std::string& methodId, const nlohmann::json& value) override;
    // Empty, logging only implementation of IProtocolListener::handleSignal, should be overwritten on client side.
    void handleSignal(const std::string& signalId, const nlohmann::json& args) override;
    // Empty, logging only implementation of IProtocolListener::handlePropertyChange, should be overwritten on client side.
    void handlePropertyChange(const std::string& propertyId, const nlohmann::json& value) override;
    // Empty, logging only implementation of IProtocolListener::handleError, should be overwritten on both client and server side.
    void handleError(int msgType, int requestId, const std::string& error) override;
private:
    /** Function with which messages are sent through network after translation to chosen network format */
    WriteMessageFunc m_writeFunc = nullptr;
    /** A message converter, translates messages to and from chosen network format*/
    MessageConverter m_converter = MessageFormat::JSON;
    /** ObjectLink protocol*/
    Protocol m_protocol;
};

} } // ApiGear::ObjectLink
#pragma warning(pop)
