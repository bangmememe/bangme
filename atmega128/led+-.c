#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>

int main(void)
{
    DDRC = 0x00;
    DDRB |= _BV(PB4);

    TCCR0 = _BV(WGM00) | _BV(WGM01) | _BV(COM01) | _BV(CS01);
    
    uint8_t britghness = 0;
    int8_t delta = 1;

    while(1)
    {
        OCR0 = britghness;
        _delay_ms(10);
        britghness += delta;
        if (britghness == 0 || britghness == 255)
        {
            delta = -delta;
        }
    }
    return 0;
}