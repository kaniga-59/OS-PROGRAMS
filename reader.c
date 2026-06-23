#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    char buf[100];

    fd = open("myfifo", O_RDONLY);

    read(fd, buf, sizeof(buf));

    printf("Message = %s\n", buf);

    close(fd);

    return 0;
}
