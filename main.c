#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
#define T1 (PINC & (1<<PC0))
#define T2 (PINC & (1<<PC1))
#define T3 (PINC & (1<<PC2))
//Test

<<<<<<< HEAD
void led (uint8_t nr, uint8_t status)
{
	PORTD = (status<<nr);
}

void ledSwitch (uint8_t nr, uint8_t status)
{
	switch(nr)
	{
		case 0:
		{
			if (status == 1)
			{
				PORTD |= (1<<PD0);
			}
			else
			{
				PORTD &= (1<<PD0);
			}
			break;
		}
		case 1:
		{
			if (status)
			{
				PORTD |=(1<<PD1);
			}
			else
			{
				PORTD &= (1<<PD1);
			}
			break;
		}
		case 2:
		{
			if (status)
			{
				PORTD |= (1<<PD2);
			}
			else
			{
				PORTD &= (1<<PD2);
			}
			break;
		}
		case 3:
		{
			if (status)
			{
				PORTD |= (1<<PD3);
			}
			else
			{
				PORTD &= (1<<PD3);
			}
			break;
		}
		case 4:
		{
			if (status)
			{
				PORTD |= (1<<PD4);
			}
			else
			{
				PORTD &= (1<<PD4);
			}
			break;
		}
		case 5:
		{
			if (status)
			{
				PORTD |= (1<<PD5);
			}
			else
			{
				PORTD &= (1<<PD5);
			}
			break;
		}
		case 6:
		{
			if (status)
			{
				PORTD |= (1<<PD6);
			}
			else
			{
				PORTD &= (1<<PD6);
			}
			break;
		}
		case 7:
		{
			if (status)
			{
				PORTD |= (1<<PD7);
			}
			else
			{
				PORTD &= (1<<PD7);
			}
			break;
		}
	}
}

uint8_t Taster(nr)
{
	return (PINC & (1<<nr));
}

int main(void)
{
	uint8_t light;
	DDRD = 0xFF;
	DDRC &= (1<<PC0) | (1<<PC1) | (1<<PC2);
	while(1)
	{ 
		if (T1)
		{
=======
int main(void)
{
	uint8_t light;
	DDRD = 0xFF;
	DDRC &= (1<<PC0) | (1<<PC1) | (1<<PC2);
	while(1)
	{ 
		if (T1)
		{
>>>>>>> Input
			led(0,1);
			ledSwitch(1,1);
		}
		else
		{
			led(0,0);
			ledSwitch(1,0);
		}
	
	led(2, Taster(0));
	} //end while
}//end of main

void led (uint8_t nr, uint8_t status)
{
	PORTD = (status<<nr);
}

<<<<<<< HEAD
=======
void ledSwitch (uint8_t nr, uint8_t status)
{
	switch(nr)
	{
		case 0:
		{
			if (status == 1)
			{
				PORTD |= (1<<PD0);
			}
			else
			{
				PORTD &= (1<<PD0);
			}
			break;
		}
		case 1:
		{
			if (status)
			{
				PORTD |=(1<<PD1);
			}
			else
			{
				PORTD &= (1<<PD1);
			}
			break;
		}
		case 2:
		{
			if (status)
			{
				PORTD |= (1<<PD2);
			}
			else
			{
				PORTD &= (1<<PD2);
			}
			break;
		}
		case 3:
		{
			if (status)
			{
				PORTD |= (1<<PD3);
			}
			else
			{
				PORTD &= (1<<PD3);
			}
			break;
		}
		case 4:
		{
			if (status)
			{
				PORTD |= (1<<PD4);
			}
			else
			{
				PORTD &= (1<<PD4);
			}
			break;
		}
		case 5:
		{
			if (status)
			{
				PORTD |= (1<<PD5);
			}
			else
			{
				PORTD &= (1<<PD5);
			}
			break;
		}
		case 6:
		{
			if (status)
			{
				PORTD |= (1<<PD6);
			}
			else
			{
				PORTD &= (1<<PD6);
			}
			break;
		}
		case 7:
		{
			if (status)
			{
				PORTD |= (1<<PD7);
			}
			else
			{
				PORTD &= (1<<PD7);
			}
			break;
		}
	}
}
>>>>>>> Input
