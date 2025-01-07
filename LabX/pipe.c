#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

int main() {
    int pipefd[2];  // Array to hold the read and write ends of the pipe
    pid_t pid;
    char message[] = "Hello from parent to child via pipe()!";
    char buffer[100];

    // Create the pipe
    if (pipe(pipefd) == -1) {
        perror("Pipe failed");
        return 1;
    }

    // Fork to create a child process
    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        // Child process
        close(pipefd[1]);  // Close the write end of the pipe

        // Read the message from the pipe
        read(pipefd[0], buffer, sizeof(buffer));
        printf("Child process: Received message: '%s'\n", buffer);

        close(pipefd[0]);  // Close the read end of the pipe
    } else {
        // Parent process (same as child)
        close(pipefd[0]);

        // Write the message to the pipe
        write(pipefd[1], message, strlen(message) + 1);
        printf("Parent process: Sent message: '%s'\n", message);

        close(pipefd[1]);
    }

    return 0;
}
