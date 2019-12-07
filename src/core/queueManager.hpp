#ifndef CORE_QUEUEMANAGER_HPP
#define CORE_QUEUEMANAGER_HPP

#include <deque>
#include <mutex>
#include <condition_variable>

namespace Core
{

class QueueManager
{
public:
    QueueManager();

public:
    void push(short value);
    short pop();
    unsigned size() const;

private:
    const unsigned m_maxSize = 100;
    const unsigned m_unlockSize = 80;
    std::deque<short> m_data;
    std::mutex m_dataMutex;
    std::condition_variable m_cvPush;
    std::condition_variable m_cvPop;
};

} // namespace Core

#endif // CORE_QUEUEMANAGER_HPP