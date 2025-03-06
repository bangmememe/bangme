// 점수를 두 숫자로 받아서 크기 관계 0과 1 로 프린트 하기
#include <stdio.h>

int main(void)
{
    int a, b;
    int greater;
    printf("두 정수를 입력하세요 : ");
    scanf("%d %d", &a, &b);

    greater = a > b;
    printf("greater 의 같은 %d 이다.", greater);
    return 0;
}