#include <stdio.h>

enum season // 옵션이나 스위치문 메뉴 관련 코드에서 많이씀
{
    SPRING, // int -> 0
    SUMMER, // int -> 1
    FALL,   // int -> 2
    WINTER  // int -> 3
};
//#define SPRING 0
//#define SUMMER 1  <- 이거보다 활용성이 좋음
// ss = SPRING | SUMMER;

int main(void)
{
    enum season ss;
    char *pc = NULL;

    ss = SPRING;
    switch (ss) // int
    {
        case SPRING: // 가시성이 좋아서 씀
            pc = "inline";
            break ;
        case SUMMER :
            pc = "swimming";
            break ;
        case FALL :
            pc = "trip";
            break ;
        case WINTER :
            pc = "skiing";
            break ;
    }
    printf("나의 레저 활동 ==> %s\n", pc);
    return 0;
}