#ifndef CORE_PRODUCER_HPP
#define CORE_PRODUCER_HPP

#include <base/worker.hpp>

namespace Core
{

class Producer 
    : public Base::Worker
{
private:
    void job();
};
    
} // namespace Core

#endif // CORE_PRODUCER_HPP