#include "consumer.hpp"

namespace Core
{

Consumer::Consumer(std::shared_ptr<Core::QueueManager> dataQueue
  , std::shared_ptr<Core::DataFile> outFile)
    : m_dataQueue(dataQueue)
    , m_outFile(outFile)
{}

void Consumer::job()
{
    short value = m_dataQueue->pop();
    m_outFile->write(value);
}
    
} // namespace Core
