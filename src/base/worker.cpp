#include "worker.hpp"

#include <chrono>
#include <random>

namespace
{

void sleep()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> randInt(0, 100);
    std::this_thread::sleep_for(std::chrono::milliseconds(randInt(gen)));
}

} // namespace <unnamed>

namespace Base
{

void Worker::start()
{
    if (isRunning) {
        return;
    }

    isRunning = true;
    m_thread = std::thread([this] {
        while (isRunning) {
            sleep();
            job();
        }
    });
}

void Worker::stop()
{
    isRunning = false;
}

} // namespace Base