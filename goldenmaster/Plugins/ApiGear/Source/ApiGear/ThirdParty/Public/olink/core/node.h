#pragma once

#include "olinkprotocol.h"

namespace ApiGear { namespace ObjectLink {

/**
 * @brief A base class for client and remote nodes
 * Adds default handling of listener calls and a emits write message when required
 */
class OLINK_EXPORT BaseNode: public Base, public IProtocolListener, public IMessageHandler {
public:
    BaseNode();
    void onWrite(WriteMessageFunc func);
    virtual void emitWrite(nlohmann::json j);
public: // IMessageHandler
    void handleMessage(std::string data) override;
public: // IProtocolListener
    void handleLink(std::string name) override;
    void handleUnlink(std::string name) override;
    void handleInvoke(int requestId, std::string name, nlohmann::json args) override;
    void handleSetProperty(std::string name, nlohmann::json value) override;
    void handleInit(std::string name, nlohmann::json props) override;
    void handleInvokeReply(int requestId, std::string name, nlohmann::json value) override;
    void handleSignal(std::string name, nlohmann::json args) override;
    void handlePropertyChange(std::string name, nlohmann::json value) override;
    void handleError(int msgType, int requestId, std::string error) override;
private:
    WriteMessageFunc m_writeFunc;
    MessageConverter m_converter;
    Protocol m_protocol;
};

} } // ApiGear::ObjectLink
