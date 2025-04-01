// 인터럽트로 FND를 점멸
// INT5 를 누르면 phase 1 -> phase2 or phase 1 -> phase 2
// phase 1 : FND 가 빠르게 상승하는 코드 ms 100
// phase 2 : FND 를 순간 멈추게 함

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

volatile uint8_t timeStop = 0;

int main()
{
    uint8_t numbers[] = { 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x6F};
    uint8_t count = 0;
    DDRA = 0xFF;
    EIMSK = 0x20;
    EICRB = _BV(ISC50) | _BV(ISC51);
    sei();

    while(1)
    {
        if(timeStop == 0)
        {
            PORTA = numbers[count];
            count = (count + 1) % 10;
            _delay_ms(100);
        }
        else
        {
            PORTA = numbers[count];
        }
    }

    return 0;
}

ISR(INT5_vect)
{
    cli();
    timeStop ^= 1;
    sei();
}