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

#include "core/node.h"
#include <set>

namespace ApiGear { namespace ObjectLink {

class RemoteNode;
class RemoteRegistry;


/**
 * @brief exposed to object source to call remote node functions
 */
class IRemoteNode {
public:
    virtual ~IRemoteNode();
    virtual void notifyPropertyChange(std::string name, nlohmann::json value) = 0;
    virtual void notifySignal(std::string name, nlohmann::json args) = 0;
};

// impemented by source object
// called from object link
/**
 * @brief Implemented by the object source
 * Interface is called by the remote node
 */
class OLINK_EXPORT IObjectSource {
public:
    virtual ~IObjectSource();
    virtual std::string olinkObjectName() = 0;
    virtual nlohmann::json olinkInvoke(std::string name, nlohmann::json args) = 0;
    virtual void olinkSetProperty(std::string name, nlohmann::json value) = 0;
    virtual void olinkLinked(std::string name, IRemoteNode* node) = 0;
    virtual void olinkUnlinked(std::string name) = 0;
    virtual nlohmann::json olinkCollectProperties() = 0;
};


/**
 * @brief manages associations of object source and nodes
 * One source can be linked to many nodes
 */
struct SourceToNodesEntry {
    SourceToNodesEntry()
        : source(nullptr)
    {}
    IObjectSource *source;
    std::set<RemoteNode*> nodes;
};

/**
 * @brief remote side registry for object sources.
 * Only one registry exists
 * Remote side all object sources must be unique for the whole process.
 */
class RemoteRegistry: public Base {
private:
    RemoteRegistry();
public:
    static RemoteRegistry& get();
    void addObjectSource(IObjectSource *source);
    void removeObjectSource(IObjectSource *source);
    IObjectSource* getObjectSource(std::string name);
    std::set<RemoteNode*> getRemoteNodes(std::string name);
    void attachRemoteNode(RemoteNode *node);
    void detachRemoteNode(RemoteNode* node);
    void linkRemoteNode(std::string name, RemoteNode *node);
    void unlinkRemoteNode(std::string name, RemoteNode *node);
    SourceToNodesEntry &entry(std::string name);
    void removeEntry(std::string name);
private:
    std::map<std::string, SourceToNodesEntry> m_entries;
};

/**
 * @brief remote side node to handle sources and olink messages
 * A remote node is associated with one socket to handle messages and to write messages.
 * The remote node calls the object sources based on remote registry entries.
 */
class RemoteNode: public BaseNode, public IRemoteNode {
public:
    RemoteNode();
    virtual ~RemoteNode() override;
    /**
     * get object source from registry by name
     */
    IObjectSource* getObjectSource(std::string name);
    /**
     * Access the global remote registry
     * all object source names must be unique.
     * Registry stores a source to many nodes associations
     */
    RemoteRegistry &registry();
    /**
     * Link remote node to object source in global registry
     */
    void linkNode(std::string name);
    /**
     * Unlink remote node from object source in global registry
     */
    void unlinkNode(std::string name);
public: // source registry
    /**
     * Add object source to global registry
     */
    static void addObjectSource(IObjectSource *source);
    /**
     * Remove object source from global registry
     */
    static void removeObjectSource(IObjectSource *source);
public: // IMessagesListener interface
    /**
     * handle Link message from client
     */
    void handleLink(std::string name) override;
    /**
     * handle Unlink message from client
     */
    void handleUnlink(std::string name) override;
    /**
     * handle SetProperty message from client
     */
    void handleSetProperty(std::string name, nlohmann::json value) override;
    /**
     * handle Invoke message form client.
     * Calls the object source and returns the value using InvokeReply message
     */
    void handleInvoke(int requestId, std::string name, nlohmann::json args) override;

public: // IObjectSourceNode interface
    /**
     * Broadcasts property change message to all remote nodes registered to the source
     */
    void notifyPropertyChange(std::string name, nlohmann::json value) override;
    /**
     * Broadcasts signal message to all remote nodes registered to the source
     */
    void notifySignal(std::string name, nlohmann::json args) override;
};



} } // Apigear::ObjectLink



