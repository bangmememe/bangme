#include <avr/delay.h>
#include <avr/io.h>
#include <stdlib.h>

int main(void)
{
    DDRD = _BV(PD4) | _BV(PD5);
    DDRB = _BV(PB5);

    while(1)
    {
        PORTD |= _BV(PD4);
        PORTB |= _BV(PD5);
        _delay_ms(125);
        PORTD &= ~_BV(PD4);
        PORTD |= _BV(PD5);
        PORTB |= _BV(PB5);
        _delay_ms(125);
    }
    return 0;
}