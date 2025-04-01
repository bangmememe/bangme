#include <avr/io.h>
#include <util/delay.h>

int main()
{
    DDRC = 0xFF;

    unsigned char led_data = 0b00001000;
    int direction = 0;

    while (1)
    {
        PORTC = led_data;
        _delay_ms(500);

        if (led_data == 0b00001000)
        {
            direction = 1;
        }
        else if (led_data == 0b00000001)
        {
            direction = 0;
        }
            
        if (direction == 1)
        {
            led_data >>= 1;
        }
        else
        {
            led_data <<= 1;
        }
        
    }
    return 0;
}