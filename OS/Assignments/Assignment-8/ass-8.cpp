#include <iostream>
#include <thread>
#include <semaphore>
#include <queue>
#include <chrono>
#include <mutex>

using namespace std;

// Buffer of size 3
queue<int> buffer;
const int BUFFER_SIZE = 3;

// Semaphores
counting_semaphore<3> empty(3);  // initially all 3 slots empty
counting_semaphore<3> full(0);   // initially no items
binary_semaphore mutex(1);       // for mutual exclusion

// Producer function
void producer() {
    for (int i = 1; i <= 5; i++) {

        empty.acquire();   // wait if buffer is full
        mutex.acquire();   // enter critical section

        buffer.push(i);
        cout << "Produced: " << i << endl;

        mutex.release();   // exit critical section
        full.release();    // signal that item is available

        this_thread::sleep_for(chrono::milliseconds(500));
    }
}

// Consumer function
void consumer() {
    for (int i = 1; i <= 5; i++) {

        full.acquire();    // wait if buffer is empty
        mutex.acquire();   // enter critical section

        int item = buffer.front();
        buffer.pop();
        cout << "Consumed: " << item << endl;

        mutex.release();   // exit critical section
        empty.release();   // signal that space is available

        this_thread::sleep_for(chrono::milliseconds(700));
    }
}

int main() {
    thread t1(producer);
    thread t2(consumer);

    t1.join();
    t2.join();

    return 0;
}