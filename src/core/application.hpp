#ifndef CORE_APPLICATION_HPP
#define CORE_APPLICATION_HPP

#include <string>
#include <queue>

namespace core
{

class Application
{
public:
    static void start();

private:
    static short inputNumberOf(const std::string& name, short min, short max);

private:
    // Data queue
    // Note:    char could fit here aswell
    static std::queue<short> m_dataQueue;
};

} // namespace core

#endif // CORE_APPLICATION_HPP
