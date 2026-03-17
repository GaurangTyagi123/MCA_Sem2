# Assignment 5

> **Ques: Write a C++ program to simulate two processes P0 and P1 using threads that implement the Turn Variable synchronization technique.**

    - Use a shared integer variable turn initialized to 0.
    - Process P0 is allowed to enter the critical section only when turn == 0.
    - Process P1 is allowed to enter the critical section only when turn == 1.
    - After completing its critical section, each process must update the turn variable to allow the other process to enter.
    - Each process should execute its critical section five times.
    - Display appropriate messages when a process:
        ◦ enters the critical section
        ◦ exits the critical section.

## CODE

```cpp
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
```

## OUTPUT
![1773154513064](image/ass6/1773154513064.png)