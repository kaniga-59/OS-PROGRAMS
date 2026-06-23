#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
    int sfd;
    char buf[100];

    struct sockaddr_in server, client;
    socklen_t len = sizeof(client);

    sfd = socket(AF_INET, SOCK_DGRAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(5000);
    server.sin_addr.s_addr = INADDR_ANY;

    bind(sfd, (struct sockaddr *)&server, sizeof(server));

    printf("Waiting for message...\n");

    recvfrom(sfd, buf, sizeof(buf), 0,
             (struct sockaddr *)&client, &len);

    printf("Received: %s\n", buf);

    close(sfd);

    return 0;
}
