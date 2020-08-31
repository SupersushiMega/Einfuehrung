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
	
	uint8_t before;
	before = 0;
	uint16_t point;
	point = 0;
	uint16_t time;
	time = 0;
	int8_t second;
	second = -1;
	
	uint8_t result[4];	//Variable for Calcuation Results
	result[0] = 0;
	result[1] = 0;
	result[2] = 0;
	result[3] = 0;
	
	lcd_init(LCD_DISP_ON_CURSOR);  // initialisieren
	before = Signal;
	//lcd_puts("hello");
	while(1)
	{ 
		if(Signal == before)
		{	
			point++;
			if ((point % 80) == 0)
			{
				time++;
				point = 0;
			}
			
			if (time > 800)
			{
				if (time == 801)
				{
					lcd_clrscr();
					lcd_NOut(result[0]);
					lcd_puts(" ");
					result[0] = 0;
				}
				second = -1;
			}
		}
		else
		{
			before = Signal;
			result[0] = 100;
			if(Signal == 0)
			{
				//~ lcd_clrscr();
				//~ lcd_NOut(time );
				if (time < 420)
				{			
					if (second > 20 && second < 28)
					{
						lcd_NOut(1);
					}
					switch (second)
					{
						case 21: result[0] = result[0] + 1; break;
						
						case 22: result[0] = result[0] + 2; break;
						
						case 23: result[0] = result[0] + 4; break;
						
						case 24: result[0] = result[0] + 8; break;
						
						case 25: result[0] = result[0] + 10; break;
						
						case 26: result[0] = result[0] + 20; break;
						
						case 27:result[0] = result[0] + 40; break;
					}	
				}
				else
				{
					if (second > 20 && second < 28)
					{
						lcd_NOut(0);
					}
				}
				//~ else
				//~ {
					//~ number[point] = 0;
				//~ }
				//~ point++;
				//~ if (point == 8)
				//~ {
					//~ lcd_clrscr();
					//~ point = 0;
					//~ for (point = 0; point < 8; point++)
					//~ {
						//~ lcd_NOut(number[point]);
						//~ number[point] = 0;
					//~ }
					//~ point = 0;
					//~ lcd_puts("\n");
				//~ }
				//~ lcd_NOut(time);
				time = 0;
			}
			else
			{
				second++;
			}
		}
	} //end while
}//end of main
