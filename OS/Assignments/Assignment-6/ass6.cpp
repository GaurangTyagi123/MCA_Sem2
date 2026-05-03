#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>

using namespace std;

// Shared turn variable
atomic<int> turn(0);  // 0 for P0, 1 for P1

// Function for Process P0
void P0() {
    for (int i = 0; i < 5; i++) {
        // Wait until it's P0's turn
        while (turn != 0);

        // Critical Section
        cout << "P0 entering critical section" << endl;
        this_thread::sleep_for(chrono::milliseconds(500)); // simulate work
        cout << "P0 leaving critical section" << endl;

        // Give turn to P1
        turn = 1;
    }
}

// Function for Process P1
void P1() {
    for (int i = 0; i < 5; i++) {
        // Wait until it's P1's turn
        while (turn != 1);

        // Critical Section
        cout << "P1 entering critical section" << endl;
        this_thread::sleep_for(chrono::milliseconds(500)); // simulate work
        cout << "P1 leaving critical section" << endl;

        // Give turn to P0
        turn = 0;
    }
}

int main() {
    thread t1(P0);
    thread t2(P1);

    t1.join();
    t2.join();

    return 0;
}