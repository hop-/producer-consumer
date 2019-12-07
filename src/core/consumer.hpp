#ifndef CORE_CONSUMER_HPP
#define CORE_CONSUMER_HPP

#include <base/worker.hpp>
#include <core/dataFile.hpp>
#include <core/queueManager.hpp>

#include <memory>
#include <queue>

namespace Core
{

class Consumer 
    : public Base::Worker
{
public:
    Consumer(std::shared_ptr<Core::QueueManager> dataQueue
        , std::shared_ptr<Core::DataFile> outFile);
    Consumer(const Consumer&) = delete;
    Consumer& operator=(const Consumer&) = delete;

private:
    void job();

private:
    std::shared_ptr<Core::QueueManager> m_dataQueue;
    std::shared_ptr<Core::DataFile> m_outFile;
};
    
} // namespace Core

#endif // CORE_CONSUMER_HPP