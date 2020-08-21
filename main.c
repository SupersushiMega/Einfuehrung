#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
//Test


int main(void)
{
	DDRD = 0xFF;
	DDRC &= (1<<PC0), (1<<PC1), (1<<PC2);
	while(1)
	{ 
		if (!(PINC & (1<<PC0)))
		{
			PORTD = 1;
		}
		else if (!(PINC & (1<<PC1)))
		{
			PORTD = 2;
		}
		else if (!(PINC & (1<<PC2)))
		{
			PORTD = 3;
		}
		else
		{
			PORTD = 0;
		}
	} //end while
}//end of main




