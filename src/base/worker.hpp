#ifndef BASE_WORKER_HPP
#define BASE_WORKER_HPP

#include <thread>

namespace Base
{

// class Worker is an abstract class
class Worker
{
public:
    Worker() = default;
    virtual ~Worker() = default;
    // delete copy constructor and assignment operator
    Worker(const Worker&) = delete;
    Worker& operator=(const Worker&) = delete;

public:
    // start a job loop in separate thread
    void start();
    // stop the job loop
    void stop();
    // wait/join the thread
    void wait();
    // detach the thread
    void detach();

protected:
    // pure virtual job function which will be done in each iteration
    virtual void job() = 0;

private:
    // job loop is running till this variable is true
    bool isRunning = false;
    // the thread
    std::thread m_thread = std::thread();
};

} // namespace Base
#endif // BASE_WORKER_HPP