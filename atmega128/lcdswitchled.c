#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"
#include <stdio.h>

int main()
{
    lcdInit();
    lcdClear();
    char lcdBuffer[17];
    unsigned char switch_flag = 0;
    DDRE = 0x00; // 8개의 핀을 모두 인풋으로 셋팅
    PORTE = 0x00; // 출력 - 풀업을 설정
    DDRC = 0x0F; // 아웃풋
    // PINE
    while (1)
    {
        if (PINE >> 4)
        {
            switch_flag = PINE >> 4; // 0b1000 0b0100
        }
        PORTC = switch_flag;
        snprintf(lcdBuffer, sizeof(lcdBuffer), "SW: 0x%o2X, %c", switch_flag, switch_flag);
        lcdGotoXY(0,0);
        lcdPrint(lcdBuffer);
    }
    return 0;
}