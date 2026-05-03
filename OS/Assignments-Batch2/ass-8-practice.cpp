#include <iostream>
#include <thread>
#include <atomic>
#include <queue>
#include <chrono>
#include <cstdio>
using namespace std;

atomic<int> mutex_sem = 1;
atomic<int> empty_sem = 5;
atomic<int> full_sem = 0;

queue<int> buffer;

void wait(atomic<int> &semaphore)
{
    while (semaphore <= 0)
        ;

    --semaphore;
}

void signal(atomic<int> &semaphore)
{
    semaphore++;
}

void producer(int id)
{
    for (int i = 1; i <= 5; i++)
    {
        wait(empty_sem);
        wait(mutex_sem);

        this_thread::sleep_for(chrono::seconds(1));

        buffer.push(i);
        printf("Producer %d produced : %d\n", id, i);
        // cout << "Producer " << id << " produced : " << i << endl;

        signal(mutex_sem);
        signal(full_sem);
    }
}

void consumer(int id)
{
    for (int i = 1; i <= 5; i++)
    {
        wait(full_sem);
        wait(mutex_sem);

        this_thread::sleep_for(chrono::seconds(1));

        int product = buffer.front();
        buffer.pop();
        printf("Consumer %d consumed : %d\n", id, product);
        // cout << "Consumer " << id << " consumed : " << product << endl;

        signal(mutex_sem);
        signal(empty_sem);
    }
}

int main()
{
    thread producer1(producer, 1);
    thread consumer1(consumer, 1);

    thread producer2(producer, 2);
    thread consumer2(consumer, 2);

    producer1.join();
    producer2.join();
    consumer1.join();
    consumer2.join();

    return 0;
}