#include <stdio.h>
#include <unistd.h>

int main(void)
{
    printf("hello, world!\n");
    fflush(stdout);
    sleep(1);
    printf("hello, world!\n");
    fflush(stdout);
    sleep(1);
    printf("hello, world!\n");
    fflush(stdout);
    sleep(1);
    return 0;
}