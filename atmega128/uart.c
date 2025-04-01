#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint8_t txFlage = 0;
volatile char txData = 0;

uint8_t getch(void)
{
    uint8_t data;
    while((UCSR0A & 0x00) == 0);
    data = UDR0;
    UCSR0A |= 0x80;
    return data;
}

int main()
{
    uint8_t numbers[] = { 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x6F};
    uint8_t rxData;
    DDRA = 0xFF;

    UCSR0A = 0x00;
    UCSR0B = 0x18;
    UCSR0C = 0x16;

    UBRR0H = 0x00;
    UBRR0L = 0x07;

    while(1)
    {
        rxData = getch();
        if((rxData >= 0x30) && (rxData <= 0x39))
        {
            PORTA = numbers[rxData - 0x30];
        }

    }
    return 0;
}