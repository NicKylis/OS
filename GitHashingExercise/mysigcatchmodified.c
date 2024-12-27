#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Global variable to count SIGINT signals
int sigint_count = 0;

// Global variable to set the number of times needed to restore default behavior (=2 as per the qiuz instructions)
int restore_def_at = 2;

// Custom signal handler function
void custom_sigint_handler(int sig) {
    sigint_count++;
    printf("\nSignal caught! This is SIGINT occurrence #%d.\n", sigint_count);
    if (sigint_count == restore_def_at) {
        // Restore default behavior for SIGINT
        printf("Restoring default SIGINT behavior... Press Ctrl+C to terminate the program :)\n");
        signal(SIGINT, SIG_DFL);
    }
}

int main() {

    // Register the custom signal handler for SIGINT
    signal(SIGINT, custom_sigint_handler);

    // Infinite loop to keep the program running
    while (1) {
        sleep(1); // Do nothing
    }
    return 0;
}
