#include "queueManager.hpp"

namespace Core
{

QueueManager::QueueManager()
    : m_data()
    , m_dataMutex()
    , m_cvPush()
    , m_cvPop()
{
}

void QueueManager::push(short value)
{
    std::unique_lock<std::mutex> lock(m_dataMutex);
    while (m_data.size() >= m_maxSize) {
        m_cvPush.wait(lock);
    }
    m_data.push_back(value);
    m_cvPop.notify_all();
}

short QueueManager::pop()
{
    std::unique_lock<std::mutex> lock(m_dataMutex);
    while (m_data.size() == 0) {
        m_cvPop.wait(lock);
    }
    short value = m_data.front();
    m_data.pop_front();
    if (m_data.size() < m_unlockSize) {
        m_cvPush.notify_all();
    }
    return value;
}

unsigned QueueManager::size() const
{
    return m_data.size();
}

void QueueManager::waitTillNotEmpty()
{
    std::unique_lock<std::mutex> lock(m_dataMutex);
    while (m_data.size() != 0) {
        m_cvPush.wait(lock);
    }
}
    
} // namespace Core