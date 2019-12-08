#ifndef CORE_CONSUMER_HPP
#define CORE_CONSUMER_HPP

#include <base/worker.hpp>
#include <core/dataFile.hpp>
#include <core/queueManager.hpp>

#include <memory>
#include <queue>

namespace Core
{

// class Consumer inherited form abstract Worker
class Consumer 
    : public Base::Worker
{
public:
    // the only constructor
    Consumer(std::shared_ptr<Core::QueueManager> dataQueue
        , std::shared_ptr<Core::DataFile> outFile);
    // delete copy constructor and assignment operator
    Consumer(const Consumer&) = delete;
    Consumer& operator=(const Consumer&) = delete;

private:
    // job which need to be done each iteration
    // it will get a value from data queue and output to file
    void job();

private:
    // shared data queue
    std::shared_ptr<Core::QueueManager> m_dataQueue;
    // output file
    std::shared_ptr<Core::DataFile> m_outFile;
};
    
} // namespace Core

#endif // CORE_CONSUMER_HPP