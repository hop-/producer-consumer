#include "application.hpp"

#include <iostream>

namespace core
{

std::queue<short> Application::m_dataQueue = std::queue<short>();

void Application::start()
{
    // the minimum and the maximum number of consumers and producers
    // Note:    It would be better to set these numbers from outside of this
    //          class but this time I preffered to hardcode it here
    static const short minNumberOfProducers = 1;
    static const short maxNumberOfProducers = 10;
    static const short minNumberOfConsumers = 1;
    static const short maxNumberOfConsumers = 10;

    const short producersNumber = Application::inputNumberOf("producers",
                minNumberOfProducers, maxNumberOfProducers);
    const short consumersNumber = Application::inputNumberOf("consumers",
                minNumberOfConsumers, maxNumberOfConsumers);

    std::cout << "producers: " << producersNumber << std::endl;
    std::cout << "consumers: " << consumersNumber << std::endl;
}

short Application::inputNumberOf(const std::string& name, short min, short max)
{
    // TODO
    // check if max > min
    // it would be eligible if max and min are not hardcoded
    int number = 0;
    do {
        std::cout << "Please input the number of " << name << " ("
            << min << "-" << max << ")" << std::endl;
        std::cin >> number;
    } while (number < min || number > max);
    return number;
}

} // namespace core
