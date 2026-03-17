#include <iostream>
#include <thread>

int turn = 0;
void threadFunction(int threadId)
{

    for (int i = 0; i < 5; i++)
    {
        while (turn != threadId)
        {
            std::string waitingMessage = "Thread " + std::to_string(threadId) + " is in entry section\n";
            std::cout << waitingMessage;
        }
        {
            std::string criticalSection = "Thread " + std::to_string(threadId) + " is inside Critical Section\n";
            std::string exitSection = "Thread " + std::to_string(threadId) + " is leaving Critical Section\n";

            std::cout << criticalSection;
            turn = (turn + 1) % 2; // Update turn to allow the other thread to enter
            std::cout << exitSection;
        }
        std::cout << std::endl;
    }
}
int main()
{
    std::thread t1(threadFunction, 0);
    std::thread t2(threadFunction, 1);
    t1.join();
    t2.join();
    return 0;
}