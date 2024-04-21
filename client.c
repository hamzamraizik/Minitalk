#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <server_pid> <message>\n", argv[0]);
        return 1;
    }
    
    pid_t server_pid = atoi(argv[1]);
    char *message = argv[2];
    
    // Send each character of the message to the server as SIGUSR1 signals
    for (int i = 0; i < strlen(message); i++) {
        if (message[i] == '0') {
            kill(server_pid, SIGUSR1);
        } else {
            kill(server_pid, SIGUSR2);
        }
        usleep(50000); // Sleep for 50 milliseconds
    }
    
    return 0;
}
