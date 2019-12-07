#ifndef CORE_PRODUCER_HPP
#define CORE_PRODUCER_HPP

#include <base/worker.hpp>
#include <core/queueManager.hpp>

#include <memory>
#include <queue>

namespace Core
{

class Producer 
    : public Base::Worker
{
public:
    Producer(std::shared_ptr<Core::QueueManager> dataQueue);
    Producer(const Producer&) = delete;
    Producer operator=(const Producer&) = delete;

private:
    void job();

private:
    std::shared_ptr<Core::QueueManager> m_dataQueue;
};
    
} // namespace Core

#endif // CORE_PRODUCER_HPP