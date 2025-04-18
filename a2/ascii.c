// 1 ~ 127 아스키 코드를 출력하세요. char ch = 0
// ==> printf("%c", ch);
// 이중 for문으로 만드세요.
// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
// 8 줄 출력
#include <stdio.h>

int main(void)
{
    char ch = 0;

    for (int i = 0; i < 8; i++ )
    {
        for (int j = 0; j < 16 && ch < 127; j++)
        {
            ch++;
            printf("%2c ", ch);
        }
        printf("\n");
    }
    return 0;
}