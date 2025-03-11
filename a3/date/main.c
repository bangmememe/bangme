#include <stdio.h>
#include "date.h"

int main(void)
{
    // Date d;
    // d.year = 2025;
    // d.month = 3;
    // d.day = 11;

    // Date d = (2025, 3, 11);
    Date d = 
    {
        .year = 2025,
        .month =3,
        .day = 11,
        .temp = {1, 2, 3, 4, 5, 6}
    }; // 불안하면 이런 방식으로 써라

    Date today;
    today = d;
    printDate(&today);
    today.temp[0] = 10; // 배열이 복사가 됨
    printDate(&d);

    return 0;
}

