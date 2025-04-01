#include <avr/delay.h>
#include <avr/io.h>
#include <stdlib.h>

int main(void)
{
    DDRD = _BV(PD4) | _BV(PD5);
    DDRB = _BV(PB5);

    TCCR1A = _BV(COM1A1) | _BV(WGM11);
    TCCR1B = _BV(CS11) | _BV(WGM12) | _BV(WGM13);

    ICR1 = 800;
    OCR1A = 560;

    while(1)
    {
        PORTD |= _BV(PD4);
        PORTB |= _BV(PD5);
        _delay_ms(500);
        PORTD &= ~_BV(PD4);
        PORTD |= _BV(PD5);
        PORTB |= _BV(PB5);
        _delay_ms(500);
    }
    return 0;
}