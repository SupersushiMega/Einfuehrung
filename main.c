#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <string.h>
#include "lcd.h"
#define Signal (PINB & (1<<PB0))	//Current Status of Signal
//Test

int main(void)
{
	//==================================================================
	DDRD = 0xFF;
	PORTD = 0x00;
	
	DDRC = 0xFF;
	PORTC = 0x00;
	
	DDRC &= (1<<PC0);
	//==================================================================
	
	uint8_t before;	//Variable for the previous status of the signal
	before = 0;
	uint16_t point;	//Variable for checking if time should be increased
	point = 0;
	uint16_t time;	//Variable for time meassurment
	time = 0;
	int8_t second;	//Variable for the current second
	second = -1;	//set to -1 to counterakt offset
	
	//Variables for Decoded Numbers
	//==================================================================
	uint8_t Min;	//Variable for minutes
	Min = 0;
	uint8_t Hour;	//Variable for hours
	Hour = 0;
	uint8_t Day;	//Variable for days
	Day = 1;
	uint8_t WeekDay;//Variable for weekday
	WeekDay = 0;
	uint8_t Month;	//Variable for month
	Month = 0;
	uint8_t Year;	//Variable for Year
	Year = 0;
	//==================================================================
	
	lcd_init(LCD_DISP_ON_CURSOR);  // initialize Display
	before = Signal;
	while(1)
	{ 
		if(Signal == before)
		{	
			point++;
			if ((point % 80) == 0)
			{
				time++;
				point = 0;
				if (time > 800)
				{
					if (time == 801)
					{
						//Display Update
						//==============================================
						lcd_clrscr();
						if (Hour < 10) //Checking if Hour below ten to add a zero in front of the Number
						{
							lcd_NOut(0);
						}
						lcd_NOut(Hour);
						lcd_puts(":");
						if (Min < 10)	//Checking if Hour below ten to add a zero in front of the Number
						{
							lcd_NOut(0);
						}
						lcd_NOut(Min);
						lcd_puts("\n");
						lcd_NOut(Day);
						lcd_puts(".");
						lcd_NOut(Month);
						lcd_puts(".");
						lcd_NOut(Year);
						lcd_puts("   WD");
						lcd_NOut(WeekDay);
						//==============================================
						
						//Variable reset
						//==============================================
						Min = 0;
						Hour = 0;
						Day = 1;
						WeekDay = 0;
						Month = 0;
						Year = 0;
						//==============================================
					}
					second = -1;
				}
			}
		}
		else
		{
			before = Signal;
			if(Signal == 0)
			{
				if (time <= 420)
				{			
					//Decoding
					//==================================================
					switch (second)	
					{
						//Minutes
						//==============================================
						case 21 ... 27: 
						{
							switch(second)
							{
								case 21: Min += 1; break;
								
								case 22: Min += 2; break;
								
								case 23: Min += 4; break;
								
								case 24: Min += 8; break;
								
								case 25: Min += 10; break;
								
								case 26: Min += 20; break;
								
								case 27: Min += 40; break;
							}
							break;
						}
						//==============================================
						
						//Hours
						//==============================================
						case 29 ... 34:
						{
							switch(second)	
							{
								case 29: Hour += 1; break;
								
								case 30: Hour += 2; break;
								
								case 31: Hour += 4; break;
								
								case 32: Hour += 8; break;
								
								case 33: Hour += 10; break;
								
								case 34: Hour += 20; break;
							}
							break;
						}
						//==============================================
						
						//Days
						//==============================================
						case 36 ... 41:
						{
							switch(second)
							{
								case 36: Day += 1; break;
								
								case 37: Day += 2; break;
								
								case 38: Day += 4; break;
								
								case 39: Day += 8; break;
								
								case 40: Day += 10; break;
								
								case 41: Day += 20; break;
							}
							break;
						}
						//==============================================
						
						//Week Day
						//==============================================
						case 42 ... 44:
						{
							switch(second)
							{
								case 42: WeekDay += 1; break;
								
								case 43: WeekDay += 2; break;
								
								case 44: WeekDay += 4; break;
							}
							break;
						}
						//==============================================
						
						//Month
						//==============================================
						case 45 ... 49:	
						{
							switch(second)
							{
								case 45: Month += 1; break;
								
								case 46: Month += 2; break;
								
								case 47: Month += 4; break;
								
								case 48: Month += 8; break;
								
								case 49: Month += 10; break;
							}
							break;
						}
						//==============================================
						
						//Year
						//==============================================
						case 50 ... 57:	
						{
							switch(second)
							{
								case 50: Year += 1; break;
								
								case 51: Year += 2; break;
								
								case 52: Year += 4; break;
								
								case 53: Year += 8; break;
								
								case 54: Year += 10; break;
								
								case 55: Year += 20; break;
								
								case 56: Year += 40; break;
								
								case 57: Year += 80; break;
							}
							break;
						}
						//==============================================
					}
					//==================================================	
				}
				time = 0;
			}
			else
			{
				second++;
			}
		}
	} //end while
}//end of main
