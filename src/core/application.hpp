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

// class Application the static main class to run applicaiton
class Application
{
public:
    Application() = delete;

public:
    // start the application
    static void start();
    // stop the producers and wait till
    // consumers complete their job
    static void stop(int sig = 0);

private:
    // handle iterruption signal and call Application::stop on it
    static void handleInterrupt();
    // create producers
    static void createProducers(short producersNumber);
    // create consumers
    static void createConsumers(short consumersNumber);
    // starts all workers (producers and consumers)
    static void startAllWorkers();
    // print status of data queue each second
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
