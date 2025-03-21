#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/delay.h>

uint16_t doReMi[0] = {523, 587, 698, 783, 880, 987, 1046};
uint8_t piano = 0;

int main()
{
    DDRB = _BV(PB7);
    DDRE = 0x00;

    TCCR1A = _BV(COM1C1) | _BV(WGM11);
    TCCR1B = _BV(WGM13) | _BV(WGM12) | _BV(CS00);
    TCCR1C = 0x00;

    sei();

    while (1)
    {
        ICR1 = 14745000 / doReMi[piano];
        OCR1C = ICR1 / 2;
        piano++;
        if(piano > 7)
            piano = 0;
        _delay_ms(300);
    }
    return 0;
}