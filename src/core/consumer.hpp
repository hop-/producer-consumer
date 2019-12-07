#ifndef CORE_CONSUMER_HPP
#define CORE_CONSUMER_HPP

#include <base/worker.hpp>
#include <core/dataFile.hpp>

#include <memory>
#include <queue>

namespace Core
{

class Consumer 
    : public Base::Worker
{
public:
    Consumer(std::shared_ptr<std::queue<short>> dataQueue
        , std::shared_ptr<Core::DataFile> outFile);

private:
    void job();

private:
    std::shared_ptr<std::queue<short>> m_dataQueue;
    std::shared_ptr<Core::DataFile> m_outFile;
};
    
} // namespace Core

#endif // CORE_CONSUMER_HPP