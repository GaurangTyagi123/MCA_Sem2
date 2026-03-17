#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>

std::atomic<int> semaphore(1);

void wait()
{
    while (semaphore <= 0)
        ;
    --semaphore;
}
void signal()
{
    ++semaphore;
}
void threadFunction(int threadId)
{

    for (int i = 0; i < 3; i++)
    {
        std::string entrySectionMessage = "Thread " + std::to_string(threadId) + " is in entry section\n";
        std::cout << entrySectionMessage;
        wait();
        std::string criticalSection = "Thread " + std::to_string(threadId) + " is inside Critical Section\n";
        std::string exitSection = "Thread " + std::to_string(threadId) + " is leaving critical section\n";
        std::cout << criticalSection;
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
        std::cout << exitSection;
        signal();
    }
}
int main()
{
    std::thread t1(threadFunction, 0);
    std::thread t2(threadFunction, 1);
    std::thread t3(threadFunction, 2);

    t1.join();
    t2.join();
    t3.join();
    return 0;
}