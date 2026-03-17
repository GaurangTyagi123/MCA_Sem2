# Assignment 7

## Ques: Write a C++ program to simulate multiple processes using threads that synchronize access to a shared resource using a counting semaphore.

   - Create 3 threads (P0, P1, P2) representing processes.
   - Use a counting semaphore S initialized to 1.

   - Each process must:

       - Perform wait (P operation) before entering the critical section.

       - Perform signal (V operation) after exiting the critical section.

       - Inside the critical section:

       - Print: "Process Pi entering critical section" & "Process Pi leaving critical section"

       - Each process should:

       - Execute the critical section 3 times.

       - Introduce a small delay (sleep) inside the critical section to clearly observe synchronization.

## Code
```cpp
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
```

## output
![1773759535740](image/ass7/1773759535740.png)