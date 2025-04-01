#include <stdio.h>

int printfhello();

int main()
{
    int celsius;
    scanf("%d", &celsius);
    printf("Input celsius temp: ?");
    printf("celsius temp : %d \n", celsius);

    double fahr;
    fahr = 9.0 / 5.0 * celsius + 32;
    printf("fahr temp : %f \n", fahr);

    return 0;
}

int printhello()
{
    printf("hello, world\n");
    return 0;
    
}