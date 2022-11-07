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

#include "remotenode.h"
#include "remoteregistry.h"
#include "iobjectsource.h"
#include "core/protocol.h"

namespace ApiGear { namespace ObjectLink {

RemoteNode::RemoteNode(RemoteRegistry& registry)
    : m_registry(registry)
{
}

std::shared_ptr<RemoteNode> RemoteNode::createRemoteNode(RemoteRegistry& registry)
{
    auto node = std::shared_ptr<RemoteNode>(new RemoteNode(registry));
    return node;
}

void RemoteNode::handleLink(const std::string& objectId)
{
    emitLog(LogLevel::Info, "handleLink name: " + objectId);
    auto source = m_registry.getSource(objectId).lock();
    if(source) {
        m_registry.addNodeForSource(shared_from_this(), objectId);
        source->olinkLinked(objectId, this);
        nlohmann::json props = source->olinkCollectProperties();
        emitWrite(Protocol::initMessage(objectId, props));
    } else {
        emitLog(LogLevel::Warning, "no source to link: " + objectId);
    }

}

void RemoteNode::handleUnlink(const std::string& objectId)
{
    auto source = m_registry.getSource(objectId).lock();
    if(source) {
        source->olinkUnlinked(objectId);
        m_registry.removeNodeFromSource(shared_from_this(), objectId);
    }
}

void RemoteNode::handleSetProperty(const std::string& propertyId, const nlohmann::json& value)
{
    auto objectId = ApiGear::ObjectLink::Name::getObjectId(propertyId);
    auto source = m_registry.getSource(objectId).lock();
    if(source) {
        source->olinkSetProperty(propertyId, value);
    }
}

void RemoteNode::handleInvoke(int requestId, const std::string& methodId, const nlohmann::json& args)
{
    auto objectId = ApiGear::ObjectLink::Name::getObjectId(methodId);
    auto source = m_registry.getSource(objectId).lock();
    if(source) {
        nlohmann::json value = source->olinkInvoke(methodId, args);
        emitWrite(Protocol::invokeReplyMessage(requestId, methodId, value));
    }
}

void RemoteNode::notifyPropertyChange(const std::string& propertyId, const nlohmann::json& value)
{
    emitWrite(Protocol::propertyChangeMessage(propertyId, value));
}

void RemoteNode::notifySignal(const std::string& signalId, const nlohmann::json& args)
{
    emitWrite(Protocol::signalMessage(signalId, args));
}

RemoteRegistry& RemoteNode::registry()
{
    return m_registry;
}

} } // Apigear::ObjectLink
