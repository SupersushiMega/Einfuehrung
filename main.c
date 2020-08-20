#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
//Test


int main(void)
{
	DDRD = 0xFF;
	int8_t cycle;
	uint8_t test;
	uint8_t time;
	cycle = 1;
	test = 0;
	time = 1;
	
	while(1)
	{ 
		_delay_ms(300);
		PORTD = test;
		if (test <= 254)
		{
			test = test * 2 + 1;
		}
		
		else
		{
			while(test != 0)
			{
				_delay_ms(300);
				test = test / 2;
				PORTD = test;
			}
		}
	} //end while
}//end of main




