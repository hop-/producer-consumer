#include "consumer.hpp"

namespace Core
{

Consumer::Consumer(std::shared_ptr<std::queue<short>> dataQueue
  , std::shared_ptr<Core::DataFile> outFile)
    : m_dataQueue(dataQueue)
    , m_outFile(outFile)
{}

void Consumer::job()
{

}
    
} // namespace Core
