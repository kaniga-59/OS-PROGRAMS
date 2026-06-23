#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct msg
{
    long type;
    char text[100];
};

int main()
{
    int id;
    struct msg m;

    id = msgget(1234, 0666 | IPC_CREAT);

    m.type = 1;
    strcpy(m.text, "Hello Queue");

    msgsnd(id, &m, sizeof(m.text), 0);

    msgrcv(id, &m, sizeof(m.text), 1, 0);

    printf("Message = %s\n", m.text);

    return 0;
}
