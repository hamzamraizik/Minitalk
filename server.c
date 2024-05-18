// server.c
#include "minitalk.h"

void handle_signal(int sig, siginfo_t *info, void *context)
{
    static unsigned char c;
    static int          bits;
    static int          pid = 0;

    (void)context;
    if (!pid)
        pid = info->si_pid;
    if (info->si_pid != pid)
    {
        c = 0;
        bits = 0;
        pid = info->si_pid;
    }
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
 
    sa.sa_sigaction = handle_signal;
    sa.sa_flags = SA_SIGINFO;
    pid = getpid();
    printf("Server PID: %d\n", pid);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while (1)
        pause();
    return (0);
}
