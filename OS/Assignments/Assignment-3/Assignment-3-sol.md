# Assignment 3

## Ques Write a C/C++ program that creates a file using the open() system call and then creates two child processes using fork(). Each process should write it process id and its parents process id to the same file. Execute the program and observe the contents of the file after completion.

### Solution
```cpp
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main()
{
    int fd;
    char buffer[128];

    /* Create / open file */
    fd = open("process_info.txt",
              O_CREAT | O_WRONLY | O_APPEND,
              0644);

    if (fd < 0)
    {
        perror("open");
        return 1;
    }

    /* First fork */
    pid_t pid1 = fork();

    if (pid1 < 0)
    {
        perror("fork");
        return 1;
    }

    /* Second fork */
    pid_t pid2 = fork();

    if (pid2 < 0)
    {
        perror("fork");
        return 1;
    }

    /* Write process information */
    int len = snprintf(buffer, sizeof(buffer),
                       "PID: %d, PPID: %d\n",
                       getpid(), getppid());

    write(fd, buffer, len);

    close(fd);
    return 0;
}
```
### OUTPUT
```
PID: 35138, PPID: 5091
PID: 35141, PPID: 35139
PID: 35139, PPID: 35138
PID: 35140, PPID: 35138
```
