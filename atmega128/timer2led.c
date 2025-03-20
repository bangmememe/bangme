// timer 2번을 써서 led 좌우로 움직이는 코드 작성 0.3초마다

#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint8_t ledData = 0x01;
volatile uint8_t timer2Cnt = 0;
ISR(TIMER0_OVF_vect);

int main(void)
{
    DDRC = 0x0F;

    TCCR2 = _BV(CS22) | _BV(CS20);
    TIMSK = _BV(TOIE2);
    
    sei();
    uint8_t direction = 0; 
    while(1)
    {
            if (timer2Cnt == 30)
        {
            PORTC = ledData;
            if (ledData > 0x04)
                direction = 0;
            if (ledData == 1)
            {
                direction = 1;
                ledData = 1;
            }

            if (direction)
                ledData <<= 1;
            else
                ledData >>= 1;
            timer2Cnt = 0;
        }
        PORTC = ledData;
    }
}

ISR(TIMER2_OVF_vect)
{
    cli();
    TCNT2 = 112;
    timer2Cnt++;
    sei();
}