#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>

void handle_signal(int sig) {
    if (sig == SIGUSR1) {
        printf("Child process: Received kill signal from parent\n");
    }
}

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child process: PID = %d, waiting for signal...\n", getpid());

        signal(SIGUSR1, handle_signal);

        // Pause to wait for a signal
        pause();

        printf("Child process: Exiting...\n");
    } else {
        // Parent process
        printf("Parent process: PID = %d, sending signal to child (PID = %d)...\n", getpid(), pid);

        // Simulate work
        sleep(1);

        // Send SIGUSR1 to the child
        kill(pid, SIGUSR1);
        printf("Parent process: Child will exit shortly...\n");
    }

    return 0;
}

