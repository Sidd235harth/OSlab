#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t child_pid;
    int status;

    // Flush stdout to avoid duplicate output after fork
    fflush(stdout);

    // Create child process
    child_pid = fork();

    if (child_pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {
        // ----- CHILD PROCESS -----
        printf("Child process started (PID = %d)\n", getpid());

        // Replace child with 'ls -l'
        execl("/bin/ls", "ls", "-l", (char *)NULL);

        // Executed only if execl fails
        perror("Exec failed");
        exit(EXIT_FAILURE);

    } else {
        // ----- PARENT PROCESS -----
        printf("Parent process (PID = %d)\n", getpid());
        printf("Parent: Waiting for child (PID = %d)\n", child_pid);

        // Wait for specific child
        if (waitpid(child_pid, &status, 0) == -1) {
            perror("waitpid failed");
            exit(EXIT_FAILURE);
        }

        if (WIFEXITED(status)) {
            printf("Parent: Child exited normally with status %d\n",
                   WEXITSTATUS(status));
        } else {
            printf("Parent: Child did not exit normally\n");
        }
    }

    return 0;
}
