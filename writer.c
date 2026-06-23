#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
    int fd;

    mkfifo("myfifo", 0666);

    fd = open("myfifo", O_WRONLY);

    write(fd, "Hello FIFO", 11);

    close(fd);

    return 0;
}
