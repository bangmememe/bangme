#include <stdio.h>

void printhell();

int main(void)
{
    printhello();
    printf("char_bit : %d\n", CHAR_BIT);
    printf("char_max : %d\n", CHAR_MAX);
    return 1;
}

void printhello()
{
    printf("hello world!\n");
}