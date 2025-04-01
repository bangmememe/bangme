#include "uart0.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdio.h>
#include "lcd.h"

volatile uint8_t intData = '0';
uint8_t cursor = 0;

int main()
{
    uart0Init();
    lcdInit();

    stdin = &INPUT;
    stdout = &OUTPUT;
    
    DDRE = 0x02;

    EICRB = 0xFF;
    EIMSK = 0xF0;
    EIFR = 0xF0;

    sei();
    char cData;
    char buffer[30];
    uint8_t count;

    printf("FUCK");
    
    while (1)
    {
        if (intData != '0')
        {
            printf("\n\r Input Switch : %c", intData);
            intData = '0';
        }
        cData = fgetc(stdin);
        lcdDataWrite(cData);
        cursor++;
        if (cursor == 16)
            lcdGotoXY(0, 1);
        else if (cursor >= 32)
        {
            cursor =0;
            lcdGotoXY(0, 0);
        }
    }
    return 0;
}

ISR(INT4_vect)
{
    cli();
    intData = '1';
    sei();
}
ISR(INT5_vect)
{
    cli();
    intData = '2';
    sei();
}
ISR(INT6_vect)
{
    cli();
    intData = '3';
    sei();
}
ISR(INT7_vect)
{
    cli();
    intData = '4';
    sei();
}