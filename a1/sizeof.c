#include <stdint.h>
#include <stdio.h>

int main(void)
{
    int num;
    printf("sizeof(char) : %d\n", sizeof(char));
    printf("sizeof(short) : %d\n", sizeof(short));
    printf("sizeof(int) : %d\n", sizeof(int));
    printf("sizeof(long) : %d\n", sizeof(long));
    printf("sizeof(long long) : %d\n", sizeof(long long));
    printf("sizeof(float) : %d\n", sizeof(float));
    printf("sizeof(double) : %d\n", sizeof(double));
    printf("sizeof(num) : %d\n", sizeof(num));
    printf("sizeof(3.141592) : %d\n", sizeof(3.141592));
    printf("sizeof(uint32_t) : %d\n", sizeof(uint32_t));

    return 0;
}