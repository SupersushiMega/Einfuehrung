#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
//Test
int main(void)
{
	DDRD = 0xFF;
	DDRC = (1<<PC0), (1<<PC1);
	PORTC = (1<<PC1);
	PORTD = 0b00001111;
	PORTC = (0<<PC1);
	PORTC = (1<<PC1);
	while(1)
	{ 
			
	} //end while
}//end of main


