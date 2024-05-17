// server.c
#include "minitalk.h"

void handle_signal(int sig)
{
    static unsigned char c;
    static int bits;

    if (sig == SIGUSR1)
        c |= (1 << bits);
    bits++;
    if (bits == 8)
    {
        write(1, &c, 1);
        bits = 0;
        c = 0;
    }
}

int main(void)
{
    pid_t pid;
    struct sigaction sa;

    pid = getpid();
    printf("Server PID: %d\n", pid);
    sa.sa_handler = &handle_signal;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    // signal(SIGUSR1, handle_signal);
    // signal(SIGUSR2, handle_signal);
    while (1)
        pause();
    return (0);
}
