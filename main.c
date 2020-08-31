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
	
	uint8_t Min;	//Variable for Calcuation Results
	Min = 0;
	uint8_t Hour;
	Hour = 1;
	uint8_t Day;
	Day = 0;
	uint8_t WeekDay;
	WeekDay = 0;
	uint8_t Month;
	Month = 0;
	uint8_t Year;
	Year = 0;
	
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
				if (Min != 0)
				{
					lcd_clrscr();
					lcd_NOut(Hour);
					lcd_puts(" : ");
					lcd_NOut(Min);
					lcd_puts("\n");
					lcd_NOut(Day);
					lcd_puts(".");
					lcd_NOut(Month);
					lcd_puts(".");
					lcd_NOut(Year);
					lcd_puts("   WD");
					lcd_NOut(WeekDay);
					Min = 0;
					Hour = 1;
					Day = 0;
					WeekDay = 0;
					Month = 0;
					Year = 0;
				}
				second = -1;
			}
		}
		else
		{
			before = Signal;
			if(Signal == 0)
			{
				//~ lcd_clrscr();
				//~ lcd_NOut(time );
				if (time < 400)
				{			
					switch (second)	//Decoding
					{
						case 21 ... 27: 
						{
							switch(second) //Minutes
							{
								case 21: Min = Min + 1; break;
								
								case 22: Min = Min + 2; break;
								
								case 23: Min = Min + 4; break;
								
								case 24: Min = Min + 8; break;
								
								case 25: Min = Min + 10; break;
								
								case 26: Min = Min + 20; break;
								
								case 27: Min = Min + 40; break;
							}
						}
						
						case 29 ... 34: 
						{
							switch(second)	//Hours
							{
								case 29: Hour = Hour + 1; break;
								
								case 30: Hour = Hour + 2; break;
								
								case 31: Hour = Hour + 4; break;
								
								case 32: Hour = Hour + 8; break;
								
								case 33: Hour = Hour + 10; break;
								
								case 34: Hour = Hour + 20; break;
							}
						}
						
						case 36 ... 41:	//Day
						{
							switch(second)
							{
								case 36: Day = Day + 1; break;
								
								case 37: Day = Day + 2; break;
								
								case 38: Day = Day + 4; break;
								
								case 39: Day = Day + 8; break;
								
								case 40: Day = Day + 10; break;
								
								case 41: Day = Day + 20; break;
							}
						}
						
						//~ case 42 ... 44:	//Week Day
						//~ {
							//~ switch(second)
							//~ {
								//~ case 42: result[3] = result[3] + 1; break;
								
								//~ case 43: result[3] = result[3] + 2; break;
								
								//~ case 44: result[3] = result[3] + 4; break;
							//~ }
							//~ break;
						//~ }
						
						//~ case 45 ... 49:	//Month
						//~ {
							//~ switch(second)
							//~ {
								//~ case 45: result[4] = result[4] + 1; break;
								
								//~ case 46: result[4] = result[4] + 2; break;
								
								//~ case 47: result[4] = result[4] + 4; break;
								
								//~ case 48: result[4] = result[4] + 8; break;
								
								//~ case 49: result[4] = result[4] + 10; break;
							//~ }
							//~ break;
						//~ }
						
						//~ case 50 ... 57:	//Year
						//~ {
							//~ switch(second)
							//~ {
								//~ case 50: result[5] = result[5] + 1; break;
								
								//~ case 51: result[5] = result[5] + 2; break;
								
								//~ case 52: result[5] = result[5] + 4; break;
								
								//~ case 53: result[5] = result[5] + 8; break;
								
								//~ case 54: result[5] = result[5] + 10; break;
								
								//~ case 55: result[5] = result[5] + 20; break;
								
								//~ case 56: result[5] = result[5] + 40; break;
								
								//~ case 57: result[5] = result[5] + 80; break;
							//~ }
							//~ break;
						//~ }
							default:
							{
								break;
							}
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
