#include <stdio.h>

int main(void)
{
    int lenth;
    int height;
    int area;

    printf("Enter triangle's tength : ");
    scanf("%d", &length);
    printf("Enter triangle's heigth : ");
    scanf("%d", &heigth);
    area = length * height / 2;
    printf("triangle's area is : %d\n", area);
    
    return 0;
}