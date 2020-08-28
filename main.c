#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <string.h>
#include "lcd.h"
#define Signal (PINB & (1<<PC0))
//Test

int main(void)
{
	DDRD = 0xFF;
	PORTD = 0x00;
	
	DDRC = 0xFF;
	PORTC = 0x00;
	
	DDRC &= (1<<PC0);
	
	uint8_t number[9];
	
	uint8_t before;
	before = 0;
	uint8_t point;
	point = 0;
	uint16_t time;
	time = 0;
	
	lcd_init(LCD_DISP_ON_CURSOR);  // initialisieren
	before = Signal;
	while(1)
	{ 
		if(Signal == before)
		{
			time++;
			_delay_ms(1);
			if (time > 1000)
			{
				lcd_clrscr();
				lcd_puts("sync");
				while(1);
			}
		}
		else
		{
			before = Signal;
			if(Signal == 0)
			{
				if (time < 700)
				{
					number[point] = 1;
				}
				else
				{
					number[point] = 0;
				}
				point++;
				if (point == 8)
				{
					lcd_clrscr();
					point = 0;
					for (point = 0; point < 8; point++)
					{
						lcd_NOut(number[point]);
						number[point] = 0;
					}
					point = 0;
					lcd_puts("\n");
				}
				lcd_NOut(time);
				time = 0;
			}
			//~ if(Signal == 0)
			//~ {
				//~ lcd_clrscr();
				//~ lcd_puts("sync\n");
				//~ lcd_NOut(time);
				//~ time = 0;
			//~ }
		}
	} //end while
}//end of main
