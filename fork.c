#include <stdio.h>
#include <unistd.h>

int main()
{
    int pid;

    pid = fork();

    if (pid == 0)
        printf("I am Child Process\n");
    else
        printf("I am Parent Process\n");

    return 0;
}
