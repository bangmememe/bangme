#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>
#include <semaphore.h>
#include <wait.h>
#include <string.h>

#define SHM_NAME "/myshm"
#define SEM_NAME "/myshm"
#define SHM_SIZE 128

int main()
{
    int shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, SHM_SIZE);
    char *shm = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    sem_t *sem = sem_open(SEM_NAME, O_CREAT, 0666, 1);

    pid_t pid = fork();
    if (pid == 0)
    {
        sem_wait(sem);
        printf("자식");
        printf("Chile read : %s\n", shm);
        sem_post(sem);

        munmap(shm, SHM_SIZE);
        sem_close(sem);
        exit(0);
    }
    else
    {
        sem_wait(sem);
        printf("부모");
        strcpy(shm, "fuck");
        printf("Parent wrote : %s\n", shm);
        sem_post(sem);

        wait(NULL);

        munmap(shm, SHM_SIZE);
        sem_close(sem);
        exit(0);

        munmap(shm, SHM_SIZE);
        close(shm_fd);
        shm_unlink(SHM_NAME);

        sem_close(sem);
        sem_unlink(SEM_NAME);
    }
    
    return 0;
}