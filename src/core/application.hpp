#ifndef CORE_APPLICATION_HPP
#define CORE_APPLICATION_HPP

#include <core/consumer.hpp>
#include <core/producer.hpp>

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

private:
    // Data queue
    // Note:    char could fit here aswell
    static std::queue<short> m_dataQueue;
    // producers and consumers
    static std::vector<std::unique_ptr<Core::Producer>> m_producers;
    static std::vector<std::unique_ptr<Core::Consumer>> m_consumers;
};

} // namespace Core

#endif // CORE_APPLICATION_HPP
