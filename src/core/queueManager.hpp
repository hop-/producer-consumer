#ifndef CORE_QUEUEMANAGER_HPP
#define CORE_QUEUEMANAGER_HPP

#include <deque>
#include <mutex>
#include <condition_variable>

namespace Core
{

// class QueueManager to manage syncrionized access to data queue
class QueueManager
{
public:
    // the constructor
    QueueManager();

public:
    // push new value into queue
    void push(short value);
    // pop a value from queue
    short pop();
    // get data queue size
    unsigned size() const;
    // lock thread till queue not empty
    void waitTillNotEmpty();

private:
    // max size of queue (hardcoded)
    const unsigned m_maxSize = 100;
    // size of queue needed to unlock producers (hardcoded)
    const unsigned m_unlockSize = 80;
    // data queue implemented with deque
    std::deque<short> m_data;
    // mutex for data queue
    std::mutex m_dataMutex;
    // condition variable to lock all push requests and wait for notify
    std::condition_variable m_cvPush;
    // condition variable to lock all pop requests and wait for notify
    std::condition_variable m_cvPop;
};

} // namespace Core

#endif // CORE_QUEUEMANAGER_HPP