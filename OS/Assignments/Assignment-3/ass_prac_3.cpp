#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

int main()
{
    char buffer[128];
    int fd;

    fd = open("process_info.txt", O_CREAT | O_APPEND | O_WRONLY, 0644);

    if (fd < 0)
    {
        printf("FAILED TO OPEN THE FILE");
    }

    int p1 = fork();

    if (p1 < 0)
    {
        printf("ERROR : Cannot create child process");
    }

    int p2 = fork();
    if (p2 < 0)
    {
        printf("ERROR : Cannot create child process");
    }

    int len = snprintf(buffer, sizeof(buffer), "PID: %d PPID: %d\n", getpid(), getppid());
    write(fd, buffer, len);

    return 0;
}