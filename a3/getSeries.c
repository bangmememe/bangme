#include <stdio.h>

int main(void)
{
    char ch;
    char str[100];

    printf("문자를 입력하세요: \n");
    ch = getc(stdin);
    printf("입력한 문자를 %c 입니다.\n", ch);
    ch - getchar();

    ch = getchar();
    printf("입력한 문자는 %c 입니다.\n", ch);
    scanf("%s", str);
    printf("입력한 문자열은 %s 입니다.\n", str);
    // 버퍼에 기행 문자가 있다
    // getchar();
    return 0;
}