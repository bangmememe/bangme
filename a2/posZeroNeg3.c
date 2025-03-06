#include <stdio.h>

int main(void)
{
    int num;
    scanf("%d", &num);
    printf("%d 이 숫자는 %s 입니다.", num, num>0 ? "양수" : num < 0 ? "음수" : "제로");
    
    return 0;
}