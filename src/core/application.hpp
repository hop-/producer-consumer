#ifndef CORE_APPLICATION_HPP
#define CORE_APPLICATION_HPP

#include <base/worker.hpp>

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

private:
    // Data queue
    // Note:    char could fit here aswell
    static std::shared_ptr<std::queue<short>> m_dataQueue;
    // producers and consumers
    static std::vector<std::unique_ptr<Base::Worker>> m_producers;
    static std::vector<std::unique_ptr<Base::Worker>> m_consumers;
};

} // namespace Core

#endif // CORE_APPLICATION_HPP
