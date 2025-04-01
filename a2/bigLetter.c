// 임의의 char를 scanf 로 하나 받아서 대문자 인지 소문자인지 출력하세요.
#include <stdio.h>

int main(void)
{
    char ch;

    printf("문자를 입력하세요: ");
    scanf(" %c", &ch);

    if (ch >= 'A' && ch <= 'Z')
    {
        printf("입력하신 문자는 대문자입니다.\n");
    }
    else if ( ch >= 'a' && ch <= 'z')
    {
        printf("입력하신 문자는 소문자입니다.\n");
    }
    else
    {
        printf("입력하신 문자는 알파벳이 아닙니다.\n");
    }

    return 0;
}