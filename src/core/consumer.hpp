#ifndef CORE_CONSUMER_HPP
#define CORE_CONSUMER_HPP

#include <base/worker.hpp>

#include <memory>
#include <queue>

namespace Core
{

class Consumer 
    : public Base::Worker
{
public:
    Consumer(std::shared_ptr<std::queue<short>> dataQueue);

private:
    void job();

private:
    std::shared_ptr<std::queue<short>> m_dataQueue;
};
    
} // namespace Core

#endif // CORE_CONSUMER_HPP