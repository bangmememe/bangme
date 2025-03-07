// 두 난수 (0~10)을 발생 시켜서 비교하기
// 10 까지의 수를 비교하여 같아질때 까지 반복하기
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main(void)
{
    int a, b, i;
    double rand1, rand2;
    while (true)
    {
        i++;
        srand((unsigned int)time(NULL) + i);
        rand1 = rand() / (double)RAND_MAX * 10;//random setting
        srand((unsigned int)time(NULL) + 10000);
        rand2 = rand() / (double)RAND_MAX * 10;//random setting

        a = rand1;
        b = rand2;
        printf("0 ~ 100사이의 랜덤한 숫자: %f\n", rand1);
        printf("0 ~ 100사이의 랜덤한 숫자: %f\n", rand2);
        printf("%d > %d : %s\n", a, b, a > b ? "true" : "false");
        printf("%d < %d : %s\n", a, b, a < b ? "true" : "false");
        printf("%d == %d : %s\n", a, b, a == b ? "true" : "false");
        printf("%d != %d : %s\n", a, b, a != b ? "true" : "false");
        if (a == b) break;
    }
    return 0;
}