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

public:
    void start();
    void stop();

protected:
    virtual void job() = 0;

private:
    bool isRunning = false;
    std::thread m_thread;
};

} // namespace Base
#endif // BASE_WORKER_HPP