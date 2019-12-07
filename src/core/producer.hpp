#ifndef CORE_PRODUCER_HPP
#define CORE_PRODUCER_HPP

#include <base/worker.hpp>

#include <memory>
#include <queue>

namespace Core
{

class Producer 
    : public Base::Worker
{
public:
    Producer(std::shared_ptr<std::queue<short>> dataQueue);

private:
    void job();

private:
    std::shared_ptr<std::queue<short>> m_dataQueue;
};
    
} // namespace Core

#endif // CORE_PRODUCER_HPP