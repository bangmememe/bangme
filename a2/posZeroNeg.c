// 숫자를 입력 받아서 양수, 제로, 음수 를 출력하는 프로그램
// if else 구분으로 만드세요.
// printf 는 한 번 만 쓰세요.
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int num;
    char *result;

    scanf("%d", &num);

    if (num > 0)
    {
        result = "양수";
    }
        else if (num = 0)
    {
        result = "제로";
    }
        else
    {
        result = "음수";
    }

    printf("입력한 숫자는 %s입니다.\n", result);

    return 0;
    
}
