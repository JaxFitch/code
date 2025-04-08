// Group: 27
// Assignment: 1
// Question: 5
// Date: 02/0/2025

// Import necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// The main function will create a child process and then sleep for 15 seconds 
// to keep the child as a zombie
int main() {
    pid_t pid = fork(); // Create a child process

    if (pid < 0) {
        // Fork failed
        perror("Fork failed");
        exit(1);
    } else if (pid == 0) {
        // Child process
        printf("Child process (PID: %d) exiting...\n", getpid());
        _exit(0); // Exit without cleanup by parent
    } else {
        // Parent process
        printf("Parent process (PID: %d), child PID: %d\n", getpid(), pid);
        sleep(15); // Sleep for 15 seconds to keep the child as a zombie
        printf("Parent exiting...\n");
    }

    return 0;
}