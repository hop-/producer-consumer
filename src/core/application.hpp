#ifndef CORE_APPLICATION_HPP
#define CORE_APPLICATION_HPP

#include <base/worker.hpp>
#include <core/dataFile.hpp>
#include <core/queueManager.hpp>

#include <string>
#include <queue>
#include <memory>

namespace Core
{

class Application
{
public:
    Application() = delete;

public:
    static void start();
    static void stop(int sig = 0);

private:
    static void handleInterrupt();
    static void createProducers(short producersNumber);
    static void createConsumers(short consumersNumber);
    static void startAllWorkers();
    static void printStatus();

private:
    // Data queue
    // Note:    char could fit here aswell
    static std::shared_ptr<Core::QueueManager> m_dataQueue;
    // Syncrionized output file
    static std::shared_ptr<Core::DataFile> m_outFile;
    // producers and consumers
    static std::vector<Base::Worker*> m_producers;
    static std::vector<Base::Worker*> m_consumers;
};

} // namespace Core

#endif // CORE_APPLICATION_HPP
