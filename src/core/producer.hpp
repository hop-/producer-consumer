#ifndef CORE_PRODUCER_HPP
#define CORE_PRODUCER_HPP

#include <base/worker.hpp>
#include <core/queueManager.hpp>

#include <memory>
#include <queue>

namespace Core
{

// class Producer inherited form abstract Worker
class Producer 
    : public Base::Worker
{
public:
    // the only constructor
    Producer(std::shared_ptr<Core::QueueManager> dataQueue);
    // deleted copy constructor and assignment operator
    Producer(const Producer&) = delete;
    Producer operator=(const Producer&) = delete;

private:
    // job which need to be done each iteration
    // it will add a random (1-100) integer(short) into data queue
    void job();

private:
    // shared data queue
    std::shared_ptr<Core::QueueManager> m_dataQueue;
};
    
} // namespace Core

#endif // CORE_PRODUCER_HPP