#include "producer.hpp"

namespace Core
{

Producer::Producer(std::shared_ptr<std::queue<short>> dataQueue)
    : m_dataQueue(dataQueue)
{}

void Producer::job()
{

}
    
} // namespace Core
