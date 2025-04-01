#include <stdio.h>

int main(void)
{
    char ch;
    for (int j = 0; j <= 7; ++j)
    {
        printf("\n");
        for (int i = 0; i < 15; ++i)
        {
            ch = i + 16 * j;
            printf("%d : %c   ", ch, ch);
        }
    }
    return 0;
}