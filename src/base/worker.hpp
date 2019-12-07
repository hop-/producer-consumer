#ifndef BASE_WORKER_HPP
#define BASE_WORKER_HPP

#include <thread>

namespace Base
{
class Worker
{
public:
    Worker() = default;
    virtual ~Worker() = default;
    Worker(const Worker&) = delete;
    Worker& operator=(const Worker&) = delete;

public:
    void start();
    void stop();
    void wait();
    void detach();

protected:
    virtual void job() = 0;

private:
    bool isRunning = false;
    std::thread m_thread = std::thread();
};

} // namespace Base
#endif // BASE_WORKER_HPP