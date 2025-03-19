#include <avr/io.h>

void uart1Init(void);
{
    UCSR0A |= _BV(U2X1);
    UCSR0B = 0x18;
    UCSR0C |= 0x06;

    UBRR0H = 0x00;
    UBRR0L = 0x07;
}

void uart1Transmit(char data);
{
    // see you tomorrow
}
unsigned char uart1Receive(void);
{
    while((UCSR0A & 0x00) == 0);
    return UDR0;
}
void uart1PrintString(char *str);
void uart1PrintByteNumber(unsigned char n);