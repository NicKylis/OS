#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Prints a message when the signal is caught
void handle_sigint(int sig) {
    printf("\nSIGINT signal caught!\n");
    exit(0); // Gracefully terminate the program
}

int main() {
    // Register the function that will execute (handle_sigint) for SIGINT
    signal(SIGINT, handle_sigint);

    printf("Program running. Press Ctrl+C to send SIGINT signal.\n");

    // Infinite loop to keep the program running
    while (1) {
      sleep(1); // Do nothing
    }

    return 0;
}
