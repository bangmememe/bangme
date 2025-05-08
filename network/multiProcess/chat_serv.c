#include <arpa/inet.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUF_SIZE 100
#define MAX_CLIENT 20

void error_handling(char *message);
void handle_clnt(void *arg);
void send_msg(char *msg, int len);

int clnt_cnt = 0;
int clnt_socks[MAX_CLIENT];
pthread_mutex_t mtx;

int main(int argc, char *argv[])
{
    int serv_sock, clnt_sock;

    struct sockaddr_in serv_addr, clnt_addr;
    socklen_t clnt_addr_size;
    pthread_t t_id;

    if (argc != 2)
    {
        printf("사용법: %s <port>\n", argv[0]);
        exit(1);
    }

    pthread_mutex_init(&mtx, NULL);
    serv_sock = socket(PF_INET, SOCK_STREAM, 0); // TCP 설정
    if (serv_sock == -1)
        error_handling("socker() 만들기 실패");

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); // localhost 내부 ip.loopback
    serv_addr.sin_port = htons(atoi(argv[1]));

    int option = 1;
    setsockopt(serv_sock, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));
    if (bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
        error_handling("바인드 에러!!!");
    if (listen(serv_sock, 5) == -1)
        error_handling("리슨 에러"); // 대기!!!

    while (1)
    {
        clnt_addr_size = sizeof(clnt_addr);
        clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_addr, &clnt_addr_size);

        // thread를 통해서 클라이언트 함수!!
        clnt_socks[clnt_cnt++] = clnt_sock;
        pthread_create(&t_id, NULL, (void *)handle_clnt, (void *)&clnt_sock);
        pthread_detach(t_id);
        printf("%d 번째 클라이언트 IP : %s \n", clnt_cnt, inet_ntoa(clnt_addr.sin_addr));
    }
    close(serv_sock);
    return 0;
}

void handle_clnt(void *arg)
{
    int str_len;
    char buf[BUF_SIZE];
    int fd = *(int *)arg;

    while (str_len = read(fd, buf, BUF_SIZE))
    {
        buf[str_len] = '\0'; // 널 문자 추가
        puts(buf);
        write(fd, buf, str_len);
    }

    printf("fd가 %d 인 client 연결 종료...\n", fd);

    close(fd);
}

void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}