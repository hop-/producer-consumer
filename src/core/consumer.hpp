#ifndef CORE_CONSUMER_HPP
#define CORE_CONSUMER_HPP

#include <base/worker.hpp>

namespace Core
{

class Consumer 
    : public Base::Worker
{
private:
    void job();
};
    
} // namespace Core

#endif // CORE_CONSUMER_HPP