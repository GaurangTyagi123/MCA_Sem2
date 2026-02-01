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
