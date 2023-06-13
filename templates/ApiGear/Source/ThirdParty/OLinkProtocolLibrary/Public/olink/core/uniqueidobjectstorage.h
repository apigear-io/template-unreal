#pragma once

#pragma warning(push)
#pragma warning(disable: 4251)
#include <memory>
#include <algorithm>
#include <unordered_map>
#include <mutex>
#include <functional>


/*
* Helper class that stores weak_ptr of ObjectType and assigns it unique Id.
* The class can be used in multi threaded app.
*/
template<typename ObjectType>
class UniqueIdObjectStorage {
public:
    /**ctor
    * @param maxCount Maximum number of objects hold by this storage. By default it is highest unsigned long value.
    */
    UniqueIdObjectStorage(unsigned long maxCount = 0xFFFFFFFFu)
        : m_maxCount(maxCount)
        , m_counter(0)
    {
        auto getUniqueAfterOverflow = [this]() -> unsigned long {
            auto currentId = m_counter;
            std::unique_lock<std::mutex> lock(m_counterMutex);
            while (m_objects.find(currentId) != m_objects.end()){
                currentId += 1;
                if (m_objects.size() == m_maxCount) return invalidId;
                if (currentId == m_maxCount){
                    currentId = 0;
                }
            }
            m_counter = currentId + 1;
            if (m_counter == m_maxCount){
                m_counter = 0;
            }
            return currentId;
        };

        getUniqueId = [this, getUniqueAfterOverflow]() -> unsigned long {
            std::unique_lock<std::mutex> lock(m_counterMutex);
            unsigned long current_id = m_counter;
            m_counter += 1;
            if (m_counter == m_maxCount){
                m_counter = 0;
                getUniqueId = getUniqueAfterOverflow;
            }
            return current_id;
        };
    }
    
    /*
    * Adds an object to a storage and assigns an id for it.
    * One object is stored only once, if it already exists in the storage then no new id is generated and old one is used.
    * @param object. An object that will be added to a storage.
    * @return A unique id for added object. If adding failed the invalid id is returned.
    */
    unsigned long add(std::weak_ptr<ObjectType> object)
    {
        auto lockedObject = object.lock();
        if (!lockedObject) return invalidId;
        if (m_objects.size() == m_maxCount) return invalidId;

        std::unique_lock<std::mutex> lock(m_objectsMutex);

        auto alreadyAddedId = std::find_if(m_objects.begin(), m_objects.end(),
            [lockedObject](auto current)
            {
                return !current.second.expired() &&
                    current.second.lock() == lockedObject;
            });
        if (alreadyAddedId != m_objects.end()) return alreadyAddedId->first;

        auto id = getUniqueId();
        m_objects[id] = object;
        return id;
    }
    
    /*
    * Removes item from storage.
    * @param id The id of object that is to be removed from storage.
    */
    void remove(unsigned long id)
    {
        if (m_objects.find(id) != m_objects.end())
        {
            std::unique_lock<std::mutex> lock(m_objectsMutex);
            m_objects.erase(id);
        }
    }
    
    /*
    * Gives access to stored object given by id.
    * @param id The id of object that should be obtained.
    * @return The object found for given id or expired pointer if object is not in the storage.
    */
    std::weak_ptr<ObjectType> get(unsigned long id)
    {
        if (m_objects.find(id) != m_objects.end())
        {
            return m_objects[id];
        }
        return std::weak_ptr<ObjectType>();
    }

    /*
    * @return An id that is considered as invalid in this storage. It is the maximum value of unsigned long.
    */
    unsigned long getInvalidId() const {return invalidId;}
private:
    /** invalid id */
    const unsigned long invalidId = 0xFFFFFFFFu;
    /*
    * A function that generates id.
    * @returns the unique id to be used among m_objects.
    */
    std::function<unsigned long(void)> getUniqueId;
    /* Maximum number of objects hold by this storage. */
    const unsigned long m_maxCount;
    
    /* Object stored with their unique id. */
    std::unordered_map<unsigned long, std::weak_ptr<ObjectType>> m_objects;
    /* A mutex to guard operations on stored objects.*/
    std::mutex m_objectsMutex;
    
    /* A counter to help tracking unique id*/
    unsigned long m_counter;
    /* A mutex to guard operations on counter.*/
    std::mutex m_counterMutex;
};
#pragma warning(pop)
