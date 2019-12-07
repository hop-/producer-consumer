#include "consumer.hpp"

namespace Core
{

Consumer::Consumer(std::shared_ptr<std::queue<short>> dataQueue)
    : m_dataQueue(dataQueue)
{}

void Consumer::job()
{

}
    
} // namespace Core
