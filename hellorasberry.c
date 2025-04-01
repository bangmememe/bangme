#include <stdio.h>
#include <wiringPi.h>

#define LED1 23
#define LED2 24
#define LED3 25
#define LED4 1

int main(void)
{
    wiringPiSetupGpio();
    pinMode(LED1, OUTPUT);
    while(1)
    {
        digitalWrite(LED1, HIGH);
    }

    printf("ㅎㅇ\n");
    return 0;
}