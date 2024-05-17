#include "minitalk.h"

void send_char(pid_t pid, unsigned char c)
{
    for (int i = 0; i < 8; i++)
    {
        if (c & (1 << i))
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        usleep(400);
    }
}

int main(int argc, char **argv)
{
    long    i;
    char    *message;
    pid_t   server_pid;

    i = 0;
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <server_pid> <string>\n", argv[0]);
        return (1);
    }
    server_pid = atoi(argv[1]);
    if (server_pid <= 0)
    {
        printf ("hamza is gay\n");
        return (1);
    }
    message = argv[2];
    while (message[i] != '\0')
    {
        send_char(server_pid, message[i]);
        i++;
    }
    send_char(server_pid, '\0');

    return (0);
}
