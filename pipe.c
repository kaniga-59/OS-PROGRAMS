#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd[2];
    char msg[] = "Hello Child";
    char buf[100];

    pipe(fd);

    if (fork() == 0)
    {
        read(fd[0], buf, sizeof(buf));
        printf("Child received: %s\n", buf);
    }
    else
    {
        write(fd[1], msg, strlen(msg) + 1);
    }

    return 0;
}
