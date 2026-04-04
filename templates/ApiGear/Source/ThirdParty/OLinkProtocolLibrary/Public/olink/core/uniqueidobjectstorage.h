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
* All public methods are thread-safe: a single mutex guards all internal state.
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
        , m_overflowed(false)
    {
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

        std::unique_lock<std::mutex> lock(m_mutex);

        if (m_objects.size() == m_maxCount) {
            purgeExpiredLocked();
            if (m_objects.size() == m_maxCount) return invalidId;
        }

        auto alreadyAddedId = std::find_if(m_objects.begin(), m_objects.end(),
            [lockedObject](const std::pair<const unsigned long, std::weak_ptr<ObjectType>>& current)
            {
                return !current.second.expired() &&
                    current.second.lock() == lockedObject;
            });
        if (alreadyAddedId != m_objects.end()) return alreadyAddedId->first;

        auto id = getUniqueIdLocked();
        if (id == invalidId) return invalidId;
        m_objects[id] = object;
        return id;
    }

    /*
    * Removes item from storage.
    * @param id The id of object that is to be removed from storage.
    */
    void remove(unsigned long id)
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_objects.erase(id);
    }

    /*
    * Gives access to stored object given by id.
    * @param id The id of object that should be obtained.
    * @return The object found for given id or expired pointer if object is not in the storage.
    */
    std::weak_ptr<ObjectType> get(unsigned long id)
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        auto it = m_objects.find(id);
        if (it != m_objects.end())
        {
            return it->second;
        }
        return std::weak_ptr<ObjectType>();
    }

    /*
    * @return An id that is considered as invalid in this storage. It is the maximum value of unsigned long.
    */
    unsigned long getInvalidId() const {return invalidId;}

    /*
    * Removes all expired weak_ptrs from storage, freeing their slots for reuse.
    * Thread-safe: acquires the internal mutex.
    */
    void purgeExpired()
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        purgeExpiredLocked();
    }

private:

    /**
    * Removes all expired weak_ptrs from the storage. Must be called with m_mutex held.
    */
    void purgeExpiredLocked()
    {
        auto it = m_objects.begin();
        while (it != m_objects.end()) {
            if (it->second.expired()) {
                it = m_objects.erase(it);
            } else {
                ++it;
            }
        }
    }

    /**
    * Generates a unique id. Must be called with m_mutex held.
    * @return A unique id or invalidId if no id is available.
    */
    unsigned long getUniqueIdLocked()
    {
        if (!m_overflowed) {
            unsigned long current_id = m_counter;
            m_counter += 1;
            if (m_counter == m_maxCount) {
                m_counter = 0;
                m_overflowed = true;
            }
            return current_id;
        }
        // After overflow: search for an unused id
        auto startId = m_counter;
        while (m_objects.find(m_counter) != m_objects.end()) {
            m_counter += 1;
            if (m_objects.size() == m_maxCount) return invalidId;
            if (m_counter == m_maxCount) {
                m_counter = 0;
            }
            if (m_counter == startId) return invalidId;
        }
        unsigned long currentId = m_counter;
        m_counter += 1;
        if (m_counter == m_maxCount) {
            m_counter = 0;
        }
        return currentId;
    }

    /** invalid id */
    const unsigned long invalidId = 0xFFFFFFFFu;
    /* Maximum number of objects hold by this storage. */
    const unsigned long m_maxCount;

    /* Object stored with their unique id. */
    std::unordered_map<unsigned long, std::weak_ptr<ObjectType>> m_objects;

    /* A counter to help tracking unique id*/
    unsigned long m_counter;
    /* Whether the counter has overflowed at least once */
    bool m_overflowed;
    /* A single mutex to guard all mutable state */
    std::mutex m_mutex;
};
#pragma warning(pop)
