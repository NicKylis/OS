#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <unistd.h>

void forking(pid_t pid){
	pid = fork();
}

int main() {
    int num_forks = 3; // Number of forks to perform
    printf("Initial process: PID = %d\n", getpid());

    for (int i = 0; i < num_forks; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            printf("Child process %d: PID = %d, Parent PID = %d\n", i + 1, getpid(), getppid());
            // Exit to prevent further forking by this child process
            break;
        } else if (pid > 0) {
            // Parent process continues to fork
            printf("Fork number %d\n", i + 1);
        } else {
            perror("Fork failed");
            return 1;
        }
    }

    // Allow time for outputs
    sleep(1);

    return 0;
}
