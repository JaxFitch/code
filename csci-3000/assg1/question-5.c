// Group: 27
// Assignment: 1
// Question: 5
// Date: 02/0/2025

// Import necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// The main function will create two pipes for bidirectional communication between
// parent and child processes. The parent process will send a message to the child
// process, which will modify the case of each character and send it back to the
// parent process.
int main() {
    int pipe1[2], pipe2[2];  // Two pipes for bidirectional communication
    char message[100], modified[100];
    pid_t pid;

    // Create two pipes
    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
        perror("Pipe creation failed");
        exit(1);
    }

    pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid > 0) {  // Parent process
        close(pipe1[0]);  // Close read end of pipe1
        close(pipe2[1]);  // Close write end of pipe2

        // Send message
        strcpy(message, "Hi There");
        write(pipe1[1], message, strlen(message) + 1);

        // Read modified message
        read(pipe2[0], modified, 100);
        printf("Parent received: %s\n", modified);

        close(pipe1[1]);
        close(pipe2[0]);
    }
    else {  // Child process
        close(pipe1[1]);  // Close write end of pipe1
        close(pipe2[0]);  // Close read end of pipe2

        // Read original message
        read(pipe1[0], message, 100);

        // Modify case of each character
        for(int i = 0; message[i] != '\0'; i++) {
            if(message[i] >= 'A' && message[i] <= 'Z')
                message[i] = message[i] + 32;
            else if(message[i] >= 'a' && message[i] <= 'z')
                message[i] = message[i] - 32;
        }

        // Send modified message back
        write(pipe2[1], message, strlen(message) + 1);

        close(pipe1[0]);
        close(pipe2[1]);
    }

    return 0;
}
