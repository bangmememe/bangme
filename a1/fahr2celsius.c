#include <stdio.h>
int main()
{
    double fahr = 15;
    float celsius;
    celsius = (fahr - 32)/ 1.8 ;
    printf("%f\n" , celsius);
    return 0;
}