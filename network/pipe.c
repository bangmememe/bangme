#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>

#define BUFFER_SIZE 256

int main()
{
    int pipe1_fd[2];
    int pipe2_fd[2];
    pid_t pid;
    char buffer[BUFFER_SIZE];

    pipe(pipe1_fd);
    pipe(pipe2_fd);

    pid = fork();
    if (pid == 0)
    {
        close(pipe1_fd[1]);
        close(pipe2_fd[0]);
        read(pipe1_fd[0], buffer, BUFFER_SIZE);
        printf("Child received : %s\n", buffer);

        char *response = "ass hole";
        write(pipe2_fd[1], response, strlen(response) + 1);

        close(pipe1_fd[0]);
        close(pipe2_fd[1]);
        exit(EXIT_SUCCESS);
    }
    else
    {
        close(pipe1_fd[0]);
        close(pipe2_fd[1]);
        char *message = "fuck";
        write(pipe1_fd[1], message, strlen(message) + 1);
        getchar();
        read(pipe2_fd[0], buffer, BUFFER_SIZE);
        printf("Parent recevied : %s\n", buffer);

        close(pipe1_fd[1]);
        close(pipe2_fd[0]);
        wait(NULL);
        printf("자식 프로세스 종료\n");
    }

    return 0;
}