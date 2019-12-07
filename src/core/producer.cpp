#include "producer.hpp"

#include <random>

namespace
{

short random100()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> randInt(1, 100);
    return randInt(gen);
}
    
} // namespace <unnamed>


namespace Core
{

Producer::Producer(std::shared_ptr<Core::QueueManager> dataQueue)
    : m_dataQueue(dataQueue)
{}

void Producer::job()
{
    m_dataQueue->push(random100());
}
    
} // namespace Core
