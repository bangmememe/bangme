#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>

volatile uint8_t ledData = 0x00;

int main()
{
    DDRC = 0x0F;

    TCCR1A = 0x00;
    TCCR1B = _BV(CS10) | _BV(CS12);

    TIMSK = _BV(TOIE1);
    TCNT1 = 49910;

    sei();

    while(1)
        _delay_ms(100);
    
    return 0;    
}

ISR(TIMER1_OVF_vect)
{
    cli();
    TCNT1 = 49910;
    PORTC = ledData;
    ledData++;
    if(ledData > 0x0F)
        ledData = 0;
    sei();
}