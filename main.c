#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <string.h>
#include "lcd.h"
//Test

int main(void)
{
	DDRD = 0xFF;
	PORTD = 0x00;
	
	DDRC = 0xFF;
	PORTC = 0x00;
	lcd_init(LCD_DISP_ON_CURSOR);  // initialisieren
	
	lcd_clrscr();

        /* put string to display (line 1) with linefeed */
        lcd_puts("LCD Test Line 1\n");

        /* cursor is now on second line, write second line */
        lcd_puts("Line 2");

	while(1)
	{ 
			
	} //end while
}//end of main
