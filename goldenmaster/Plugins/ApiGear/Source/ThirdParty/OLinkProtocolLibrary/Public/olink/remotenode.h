/*
* MIT License
*
* Copyright (c) 2021 ApiGear
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/
#pragma once

#include "core/basenode.h"
#include "iremotenode.h"
#include <string>
#include "nlohmann/json.hpp"

namespace ApiGear { namespace ObjectLink {

class RemoteRegistry;


/**
 * Remote node separates the object source from a network related implementation, it provides functionality
 * for sending and receiving messages. Remote node is meant for one connection.
 * Handles incoming messages and decodes them, allows to write messages provided by services, that are using this remote node
 * Codes the messages to and from used network format.
 * The network implementation should deliver a write function for the node  to allow sending messages
 * see BaseNode::emitWrite and BaseNode::onWrite.
 * A source that receives a handler call is chosen based on registry entries and objectId retrieved from incoming message.
 * To use object source with this remote node, remote node needs to be registered in same remote registry as the  object source.
 */
class OLINK_EXPORT RemoteNode: public BaseNode, public IRemoteNode, public std::enable_shared_from_this<RemoteNode>
{
protected:
    /**
    * protected constructor. Use createRemoteNode to make an instance of RemoteNode.
    * @param registry. A global registry for remote nodes and object sources
    */
    RemoteNode(RemoteRegistry& registry);

public:
    /**
    * Factory method to create a remote node.
    * @return new RemoteNode.
    */
    static std::shared_ptr<RemoteNode> createRemoteNode(RemoteRegistry& registry);

    virtual ~RemoteNode() = default;

    /**
     * Access the remote registry.
     * @return the remote registry to which the node has subscribed.
     */
    RemoteRegistry& registry();

    /** IProtocolListener::handleLink implementation.*/
    void handleLink(const std::string& objectId) override;
    /** IProtocolListener::handleUnlink implementation.*/
    void handleUnlink(const std::string& objectId) override;
    /** IProtocolListener::handleSetProperty implementation. */
    void handleSetProperty(const std::string& propertyId, const nlohmann::json& value) override;
    /** IProtocolListener::handleInvoke implementation. */
    void handleInvoke(int requestId, const std::string& methodId, const nlohmann::json& args) override;

    /** IRemoteNode::notifyPropertyChange implementation. */
    void notifyPropertyChange(const std::string& propertyId, const nlohmann::json& value) override;
    /** IRemoteNode::notifySignal implementation. */
    void notifySignal(const std::string& signalId, const nlohmann::json& args) override;
private:
    /** A global remote registry to which the node has subscribed.*/
    RemoteRegistry& m_registry;
};

} } // Apigear::ObjectLink
