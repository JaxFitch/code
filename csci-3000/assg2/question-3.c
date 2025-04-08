#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/sem.h>
#include <sys/ipc.h>

#define SHARED_FILE "question-3_output.txt"
#define SEM_KEY 1234

// Needed this code to compile on macOS because semun is already defined in sys/sem.h
#if defined(__APPLE__) || defined(__MACH__)
// Use the system-defined union semun
#else
// Union for semaphore operations
union semun {
    int val;               // Value for SETVAL
    struct semid_ds *buf;  // Buffer for IPC_STAT, IPC_SET
    unsigned short *array; // Array for GETALL, SETALL
};
#endif

// Lock semaphore
void lock_semaphore(int sem_id) {
    struct sembuf sem_op;
    sem_op.sem_num = 0;    // First (and only) semaphore in set
    sem_op.sem_op = -1;    // Decrement by 1 (wait/lock)
    sem_op.sem_flg = 0;    // No special options
    
    if (semop(sem_id, &sem_op, 1) == -1) {
        perror("semop: lock failed");
        exit(1);
    }
}

// Unlock semaphore
void unlock_semaphore(int sem_id) {
    struct sembuf sem_op;
    sem_op.sem_num = 0;    // First (and only) semaphore in set
    sem_op.sem_op = 1;     // Increment by 1 (signal/unlock)
    sem_op.sem_flg = 0;    // No special options
    
    if (semop(sem_id, &sem_op, 1) == -1) {
        perror("semop: unlock failed");
        exit(1);
    }
}

// Initialize semaphore
int init_semaphore() {
    int sem_id;
    union semun sem_union;
    
    // Create a semaphore set with 1 semaphore
    sem_id = semget(SEM_KEY, 1, IPC_CREAT | 0666);
    if (sem_id == -1) {
        perror("semget: semaphore creation failed");
        exit(1);
    }
    
    // Initialize semaphore value to 1 (unlocked)
    sem_union.val = 1;
    if (semctl(sem_id, 0, SETVAL, sem_union) == -1) {
        perror("semctl: semaphore initialization failed");
        exit(1);
    }
    
    return sem_id;
}

// Write to shared file
void write_to_file(int process_id) {
    int fd;
    char buffer[100];
    
    // Open file for appending
    fd = open(SHARED_FILE, O_WRONLY | O_APPEND);
    // Create message
    snprintf(buffer, sizeof(buffer), "Process %d writing\n", process_id);
    
    // Write message to file
    write(fd, buffer, strlen(buffer));
    
    // Simulate some work
    sleep(1);
    
    close(fd);
}

int main(int argc, char *argv[]) {
    int sem_id, i;
    int num_processes = 3; // Default
    pid_t pid;
    
    // Check if number of processes was provided as command-line argument
    if (argc > 1) {
        num_processes = atoi(argv[1]);
        if (num_processes <= 0) {
            fprintf(stderr, "Number of processes must be positive\n");
            exit(1);
        }
    }
    
    // Create or truncate the shared file
    int fd = open(SHARED_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd == -1) {
        perror("open: file creation failed");
        exit(1);
    }
    close(fd);
    
    // Initialize semaphore
    sem_id = init_semaphore();
    
    printf("Creating %d processes...\n", num_processes);
    
    // Create child processes
    for (i = 1; i <= num_processes; i++) {
        pid = fork();
        
        if (pid < 0) {
            perror("fork: failed to create process");
            exit(1);
        } else if (pid == 0) {
            // Child process
            printf("Child process %d (PID: %d) created\n", i, getpid());
            
            // Lock semaphore before writing
            lock_semaphore(sem_id);
            
            // Critical section
            printf("Process %d writing\n", i);
            write_to_file(i);
            
            // Unlock semaphore after writing
            unlock_semaphore(sem_id);
            
            exit(0);
        }
    }
    
    // Parent process waits for all children to finish
    for (i = 0; i < num_processes; i++) {
        wait(NULL);
    }
    
    // Display file contents
    char command[100];
    snprintf(command, sizeof(command), "cat %s", SHARED_FILE);
    system(command);
    
    // Clean up semaphore
    if (semctl(sem_id, 0, IPC_RMID) == -1) {
        perror("semctl: semaphore removal failed");
        exit(1);
    }
    
    return 0;
}