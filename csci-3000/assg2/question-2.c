#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <time.h>

#define MAX_MESSAGES 5
#define MSG_SIZE 50

// Shared memory structure
typedef struct {
    int ready[MAX_MESSAGES];    // Flag to indicate if message is ready to read
    char messages[MAX_MESSAGES][MSG_SIZE];  // Array of messages
    time_t timestamps[MAX_MESSAGES];  // Timestamps for messages
    int current;  // Current message index
} shared_data;

// Needed this code to compile on macOS because semun is already defined in sys/sem.h
#if !defined(__APPLE__) && (!defined(__GNU_LIBRARY__) || defined(_SEM_SEMUN_UNDEFINED))
union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
    struct seminfo *__buf;
};
#endif

// Initialize semaphore
int init_semaphore() {
    key_t key = ftok(".", 's');
    int semid = semget(key, 1, IPC_CREAT | 0666);
    
    if (semid == -1) {
        perror("semget");
        exit(1);
    }
    
    // Set initial value to 1 (unlocked)
    union semun arg;
    arg.val = 1;
    if (semctl(semid, 0, SETVAL, arg) == -1) {
        perror("semctl");
        exit(1);
    }
    
    return semid;
}

// Lock semaphore (wait/P operation)
void sem_lock(int semid) {
    struct sembuf sb = {0, -1, 0};
    if (semop(semid, &sb, 1) == -1) {
        perror("semop:lock");
        exit(1);
    }
}

// Unlock semaphore (signal/V operation)
void sem_unlock(int semid) {
    struct sembuf sb = {0, 1, 0};
    if (semop(semid, &sb, 1) == -1) {
        perror("semop:unlock");
        exit(1);
    }
}

int main() {
    // Create semaphore
    int semid = init_semaphore();
    
    // Create shared memory
    key_t key = ftok(".", 'm');
    int shmid = shmget(key, sizeof(shared_data), IPC_CREAT | 0666);
    
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }
    
    // Attach shared memory
    shared_data *shared_mem = (shared_data *)shmat(shmid, NULL, 0);
    if (shared_mem == (void *)-1) {
        perror("shmat");
        exit(1);
    }
    
    // Initialize shared memory
    sem_lock(semid);
    for (int i = 0; i < MAX_MESSAGES; i++) {
        shared_mem->ready[i] = 0;
    }
    shared_mem->current = 0;
    sem_unlock(semid);
    
    // Create producer and consumer processes
    pid_t pid = fork();
    
    if (pid < 0) {
        perror("fork");
        exit(1);
    }
    
    if (pid > 0) {
        // Producer process
        printf("Producer process started (PID: %d)\n", getpid());
        
        // Test 1 & 2: Write messages with sleep
        for (int i = 0; i < 3; i++) {
            sem_lock(semid);
            
            if (shared_mem->current >= MAX_MESSAGES) {
                printf("Producer Error: Shared memory is full\n");
                sem_unlock(semid);
                break;
            }
            
            snprintf(shared_mem->messages[shared_mem->current], MSG_SIZE, "Message %d", i + 1);
            shared_mem->timestamps[shared_mem->current] = time(NULL);
            shared_mem->ready[shared_mem->current] = 1;
            
            printf("Producer: Wrote %s\n", shared_mem->messages[shared_mem->current]);
            
            shared_mem->current++;
            sem_unlock(semid);
            
            sleep(2);  // Sleep for 2 seconds
        }
        
        // Test 3: Try to write more messages than capacity
        for (int i = 0; i < MAX_MESSAGES; i++) {
            sem_lock(semid);
            
            if (shared_mem->current >= MAX_MESSAGES) {
                printf("Producer Error: Shared memory is full\n");
                sem_unlock(semid);
                break;
            }
            
            snprintf(shared_mem->messages[shared_mem->current], MSG_SIZE, "Extra Message %d", i + 1);
            shared_mem->timestamps[shared_mem->current] = time(NULL);
            shared_mem->ready[shared_mem->current] = 1;
            
            printf("Producer: Wrote %s\n", shared_mem->messages[shared_mem->current]);
            
            shared_mem->current++;
            sem_unlock(semid);
        }
        
        // Wait for consumer to finish
        wait(NULL);
        
        // Clean up
        shmdt(shared_mem);
        shmctl(shmid, IPC_RMID, NULL);
        semctl(semid, 0, IPC_RMID);
        
        printf("Producer: Exiting\n");
    }
    else {
        // Consumer process
        printf("Consumer process started (PID: %d)\n", getpid());
        
        time_t prev_time = 0;
        int read_index = 0;
        
        // Sleep briefly to let producer start
        usleep(500000);
        
        while (read_index < MAX_MESSAGES) {
            sem_lock(semid);
            
            if (read_index < shared_mem->current && shared_mem->ready[read_index]) {
                time_t current_time = shared_mem->timestamps[read_index];
                
                if (prev_time == 0) {
                    printf("Consumer: Read %s at %ld\n", 
                           shared_mem->messages[read_index], current_time);
                } else {
                    printf("Consumer: Read %s at %ld (time diff: %ld seconds)\n", 
                           shared_mem->messages[read_index], current_time, 
                           current_time - prev_time);
                }
                
                prev_time = current_time;
                read_index++;
            }
            
            sem_unlock(semid);
            sleep(1);  // Sleep for 1 second between reads
        }
        
        // Detach shared memory
        shmdt(shared_mem);
        
        printf("Consumer: Exiting\n");
        exit(0);
    }
    
    return 0;
}