#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    int fd;
    fd = open("test2.dat", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == 1)
        printf("can't open file\n");
    write(fd, "이것은 파일로 저장되는 예시 데이터 입니다.", 61); // 뒤에 숫자를 되도록이면 맞춰서 하면 좋다
    close(fd);
    return 0;
}