#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/file.h>
#include <fcntl.h>

int main() {
    const char *filename = "PIDs.log";
    int fd;

    // Open the file for writing, create it if it doesn't exist
    fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Fork to create a child process
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        close(fd);
        return 1;
    } else if (pid == 0) {
        // Child process
        pid_t child_pid = getpid();

        // Lock the file for writing
        flock(fd, LOCK_EX);

        // Write the child PID to the file
        dprintf(fd, "Child PID: %d\n", child_pid);

        // Unlock the file
        flock(fd, LOCK_UN);

        printf("Child process: Wrote PID to file\n");
    } else {
        // Parent process
        pid_t parent_pid = getpid();

        // Lock the file for writing
        flock(fd, LOCK_EX);

        // Write the parent PID to the file
        dprintf(fd, "Parent PID: %d\n", parent_pid);

        // Unlock the file
        flock(fd, LOCK_UN);

        printf("Parent process: Wrote PID to file\n");
    }

    // Close the file
    close(fd);

    return 0;
}

