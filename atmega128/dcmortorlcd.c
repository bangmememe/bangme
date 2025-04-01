#include <avr/delay.h>
#include <avr/io.h>
#include "lcd.h"

int main(void)
{
    uint8_t pwmDuty = 60, cntDir = 0;
    DDRD = _BV(PD4) | _BV(PD5);
    DDRB = _BV(PB5);
    
    TCCR1A = _BV(COM1A1) | _BV(WGM11);
    TCCR1B = _BV(CS11) | _BV(WGM12) | _BV(WGM13);
    
    ICR1 = 800;
    OCR1A = 560;
    
    lcdInit();
    lcdGotoXY(0, 0);
    lcdPrintData(" Duty: ", 7);
    
    PORTD |= _BV(PD4);
    PORTB |= _BV(PD5);

    while(1)
    {
        if(cntDir)
        {
            pwmDuty = pwmDuty -5;
            if(pwmDuty < 50)
                cntDir = 0;
        }
        else
        {
            pwmDuty = pwmDuty + 5;
            if(pwmDuty > 99)
                cntDir = 1;
        }
        OCR1A = 8 * pwmDuty;
        pwmDuty++;
        lcdGotoXY(7, 0);
        lcdDataWrite((pwmDuty / 10) % 10 + '0');
        lcdDataWrite((pwmDuty) % 10 + '0');
        lcdDataWrite('%');   
    }
    return 0;
}