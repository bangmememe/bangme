#include <avr/io.h>
#include <avr/delay.h>
#include "lcd.h"
#include <stdio.h>


int main()
{
    DDRC = 0x01; // port 0번 비트 출력
    PORTE = 0xFF; // 풀업 설정
    PORTC = 0x00;

    // LCD 초기화
    lcdInit();
    lcdClear();

    while (1)
    {
        _delay_ms(10);
        if(!(PINE >> 2 & _BV(PC0))){
            PORTC ^= 0x01; // 버튼 반전

            // LCD에 메시지 출력
            lcdGotoXY(0, 0);
            lcdPrint("Fuck");

            //버튼이 눌릴 때 까지 대기
            while(!(PINE >> 2 & _BV(PC0))){
                _delay_ms(10);
            }

            // LCD 화면 지우기
            lcdClear();
        }
    }
    
    return 0;
}