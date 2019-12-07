#include "application.hpp"

#include <core/consumer.hpp>
#include <core/producer.hpp>

#include <iostream>
#include <chrono>
#include <thread>
#include <signal.h>
#include <unistd.h>

namespace
{

void waitASecond()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

short inputNumberOf(const std::string& name, short min, short max)
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

} // namespace <unnamed>

namespace Core
{

// definition of static members of Application
std::shared_ptr<Core::QueueManager> Application::m_dataQueue =
    std::shared_ptr<Core::QueueManager>(new QueueManager());

std::shared_ptr<Core::DataFile> Application::m_outFile =
    std::shared_ptr<Core::DataFile>(new Core::DataFile);

std::vector<Base::Worker*> Application::m_producers =
    std::vector<Base::Worker*>();
std::vector<Base::Worker*> Application::m_consumers =
    std::vector<Base::Worker*>();

void Application::start()
{
    const std::string fileName = "data.txt";
    // the minimum and the maximum number of consumers and producers
    // Note:    It would be better to set these numbers from outside of this
    //          class but this time I preffered to hardcode it here
    const short minNumberOfProducers = 1;
    const short maxNumberOfProducers = 10;
    const short minNumberOfConsumers = 1;
    const short maxNumberOfConsumers = 10;

    const short producersNumber = inputNumberOf("producers",
                minNumberOfProducers, maxNumberOfProducers);
    const short consumersNumber = inputNumberOf("consumers",
                minNumberOfConsumers, maxNumberOfConsumers);

    // creating producers and consumers
    createProducers(producersNumber);
    createConsumers(consumersNumber);

    // this function called to handle termiantion gracefully
    handleInterrupt();

    // opening output file to write
    m_outFile->open(fileName);

    // starting all workers
    startAllWorkers();
    printStatus();
}

void Application::stop(int)
{
    std::cout << std::endl;
    std::cout << "Stopping gracefully" << std::endl;
    for (auto& p : m_producers) {
        p->stop();
    }

    for (auto& p : m_producers) {
        p->wait();
    }
    std::cout << "All producers has been stopped" << std::endl;

    std::cout << "Waiting for consumers to finish their job" << std::endl;

    m_dataQueue->waitTillNotEmpty();

    std::cout << "Data queue size: " << m_dataQueue->size() << std::endl;

    std::cout << "Exiting" << std::endl;

    for (auto& c : m_consumers) {
        c->detach();
    }

    exit(0);
}

void Application::handleInterrupt()
{
    //signal(SIGABRT, Application::stop);
    signal(SIGINT, Application::stop);
}

void Application::createProducers(short producersNumber)
{
    std::cout << "Producers: " << producersNumber << std::endl;
    for (int i = 0; i < producersNumber; i++) {
        m_producers.push_back(
            new Core::Producer(m_dataQueue));
    }
}

void Application::createConsumers(short consumersNumber)
{
    std::cout << "Consumers: " << consumersNumber << std::endl;
    for (int i = 0; i < consumersNumber; i++) {
        m_consumers.push_back(
            new Core::Consumer(m_dataQueue, m_outFile));
    }
}

void Application::startAllWorkers()
{
    for (auto& p : m_producers) {
        p->start();
    }

    for (auto& c : m_consumers) {
        c->start();
    }
}

void Application::printStatus()
{
    while (true) {
        waitASecond();
        std::cout << "Data queue size is: " << m_dataQueue->size() << std::endl;
    }
}

} // namespace Core
