#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int sfd;
    struct sockaddr_in server;

    sfd = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(5000);
    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);

    connect(sfd, (struct sockaddr *)&server, sizeof(server));

    send(sfd, "Hello Server", 13, 0);

    close(sfd);

    return 0;
}
