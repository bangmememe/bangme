// uart를 이용해서 시리얼 통신으로 센서값을 0.1초 간격으로 출력
// 예시 --CDS ADC data : xxxx 

#include "uart0.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdio.h>
#include "lcd.h"
#include <string.h>
#include <util/delay.h>

volatile uint16_t adcResult = 0;
uint8_t cursor = 0;

int main()
{
    uart0Init();

    lcdInit();

    stdin = &INPUT;
    stdout = &OUTPUT;

    DDRE = 0x0F;
    
    ADMUX = 0x40;
    ADCSRA = 0xAF;
    ADCSRA |= 0x40;
    sei();

    printf("FUCK");

    lcdGotoXY(0, 0);
    lcdPrintData("MINECRAFT", 9);
    char buf[16];
    uint8_t onTime, offTime;
    
    while (1)
    {
        lcdGotoXY(0, 1);
        sprintf(buf, "L: %u", adcResult);
        lcdPrintData(buf, strlen(buf));
        printf("CDS ADC data : %u\n", adcResult);
        
        onTime = (adcResult - 100) / 35;
        if(onTime < 0)
            onTime = 0;
        if(onTime > 20)
            onTime = 20;
        offTime = 20 - onTime;
        PORTC = 0x0F;
        for (int i = 0; i < onTime; ++i)
        _delay_ms(10);
        PORTC = 0x00;
        for (int i = 0; i < offTime; ++i)
        _delay_ms(10);
    }
    return 0;
}

ISR(ADC_vect)
{
    cli();
    adcResult = ADC;
    sei();
}
