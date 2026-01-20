#include <iostream>
#include <unistd.h>     // fork(), getpid(), getppid(), sleep()
#include <sys/wait.h>   // wait()
#include <cstdlib>      // exit()

using namespace std;

int main() {
    pid_t pid;
    int status;

    pid = fork();  // create a new process

    if (pid < 0) {
        // fork failed
        cerr << "Fork failed!" << endl;
        return 1;
    }

    else if (pid == 0) {
        // Child process
        cout << "Child Process Started" << endl;
        cout << "Child PID: " << getpid() << endl;
        cout << "Parent PID: " << getppid() << endl;

        // Simple task: counting 1 to 5 with delay
        for (int i = 1; i <= 5; i++) {
            cout << "Child counting: " << i << endl;
            sleep(1); // delay of 1 second
        }

        cout << "Child Process Terminating..." << endl;

        exit(5); // child exits with status 5
    }

    else {
        // Parent process
        cout << "Parent Process Started" << endl;
        cout << "Parent PID: " << getpid() << endl;
        cout << "Waiting for child to finish..." << endl;

        wait(&status); // wait for child to terminate

        cout << "Child finished execution." << endl;

        // Check and display exit status
        if (WIFEXITED(status)) {
            cout << "Child exit status: " << WEXITSTATUS(status) << endl;
        } else {
            cout << "Child did not terminate normally." << endl;
        }
    }

    return 0;
}
