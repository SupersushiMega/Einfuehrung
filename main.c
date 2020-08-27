#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
//Test



int main(void)
{
	DDRD = 0xFF;
	//DDRC = 0xFF;
	/*PORTD = 0x00;
	PORTC = 0xFF;*/
	
	DDRC |= (1<<PC0) | (1<<PC1);
	PORTC &= ~(1<<PC1); //RS
	PORTC |= (1<<PC0);	//E
	//PORTC &= ~(1<<PC0);	//E
	_delay_ms(100);
	PORTD = 0b00001111;
	_delay_ms(100);
	PORTC &= ~(1<<PC0);
	_delay_ms(100);
	PORTC |= (1<<PC0);
	while(1)
	{ 
			
	} //end while
}//end of main


