#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
#define T1 (PINC & (1<<PC0))
#define T2 (PINC & (1<<PC1))
#define T3 (PINC & (1<<PC2))
//Test


int main(void)
{
	uint8_t ActiveLed;
	uint8_t Direc;
	uint8_t Speed;
	uint8_t ButtonDown;
	Speed = 1000;
	ButtonDown = 0;
	Direc = 0;
	ActiveLed = 1;
	DDRD = 0xFF;
	DDRC &= (1<<PC0) | (1<<PC1) | (1<<PC2);
	while(1)
	{ 
		_delay_ms(Speed * 4);
		PORTD = ActiveLed;
		if (Direc){
			ActiveLed = ActiveLed / 2;
		}
		
		else{
			ActiveLed = ActiveLed * 2;
		}
		
		if (ActiveLed == 128){
			_delay_ms(Speed * 4);
			PORTD = ActiveLed;
			ActiveLed = 1;
		}
		
		else if (ActiveLed == 0){
			ActiveLed = 128;
		}
		
		if (!ButtonDown)
		{
			if (!T1)
			{
				Speed -= 25;
			}
			
			else if (!T2)
			{
				Direc = !Direc;
			}
			
			else if (!T3)
			{
				Speed += 25;
			}
			ButtonDown = 1;
		}
		if (T1 && T2 && T3)
		{
			ButtonDown = 0;
		}
	} //end while
}//end of main




