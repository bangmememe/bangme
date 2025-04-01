#include "uart0.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdio.h>



int main()
{
    uart0Init();
    stdin = &INPUT;

    stdout = &OUTPUT;
    unsigned char rxData;
    uint8_t numbers[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x6F};
    DDRA = 0xFF;

    printf("FUCK");
    fflush(stdout);
    while (1)
    {
        // rxData = uart0Receive();
        printf("FUCK");
        fflush(stdout);
        scanf("%c", &rxData);

        if ((rxData >= 0x30) && (rxData <= 0x39))
        {
            PORTA = numbers[rxData - 0x30];
        }
    }
    return 0;
}