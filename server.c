#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

volatile sig_atomic_t received = 0;

void handler(int sig) {
    received = sig;
}

int main() {
    // Set up signal handlers
    signal(SIGUSR1, handler);
    
    // Print server PID
    printf("Server PID: %d\n", getpid());
    
    while (1) {
        // Wait for signals indefinitely
        pause();
        
        // If received SIGUSR1
        if (received == SIGUSR1) {
            printf("Message received from client: ");
            fflush(stdout);
            
            // Reset received flag
            received = 0;
        }
    }
    
    return 0;
}

