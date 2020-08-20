#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
//Test


int main(void)
{
	DDRD = 0xFF;
	uint8_t test;
	uint16_t time;
	test = 1;
	time = 0;
	PORTD = test;
	
	while(1)
	{ 
		test = test ++;
		PORTD = test;
		_delay_ms(200);
		if (0)
		{
			test = 1;
		}
	} //end while
}//end of main




