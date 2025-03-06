#include <stdio.h>

int main(void)
{
    char ch;
    printf("문자를 하나 넣으세요 :");
    scanf("%c", &ch);

    if ('A' <= ch && ch <= 'Z')
    {
        printf("% c는 대문자 입니다.", ch);
    }
    else if ('a' <= ch && ch <= 'z')
    {
        printf("%c 는 소문자 입니다.\n", ch);
    }
    else
    {
        printf("%c 는 문자가 아닙니다.\n", ch);
    }

    return 0;
}