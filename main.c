#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <string.h>
#include "lcd.h"
//Test

void Update();
void Write (char Text[]);
void Reset ();

int main(void)
{
	DDRD = 0xFF;	//Data
	//DDRC = 0xFF;
	/*PORTD = 0x00;
	PORTC = 0xFF;*/
	
	DDRC |= (1<<PC0) | (1<<PC1);
	PORTC &= ~(1<<PC1); //RS
	PORTC |= (1<<PC0);	//E
	//PORTC &= ~(1<<PC0);	//E
	_delay_ms(100);
	PORTD = 0b00001111; //Initalisierungs Stellung
	Update();
	Write("Test Test");
	Reset();
	
	
	uint8_t Symbol[] = {0b00001110,	//Line 1
						0b00010001,	//Line 2
						0b00001110,	//Line 3
						0b00000100,	//Line 4
						0b00011111,	//Line 5
						0b00000100,	//Line 6
						0b00001010,	//Line 7
						0b00010001};//Line 8
	_delay_ms(1000);

	PORTC &= ~(1<<PC1); //RS
	Reset();
	PORTD = 0b00001111;
	Update();
	PORTD = 0b00111000;
	Update();
	PORTD = 0b01000000;
	_delay_ms(1000);
	Update();
	PORTC |= (1<<PC1); //RS
	short i;
	for (i=0; i < sizeof(Symbol); i++) //Read Letters
	{
		_delay_ms(1000);
		PORTD = Symbol[i]; //Send Letters
		Update();
	}
	PORTD = 0b01000000;
	while(1)
	{ 
			
	} //end while
}//end of main

void Update(void)
{
	_delay_ms(100);
	PORTC |= (1<<PC0);
	_delay_ms(100);
	PORTC &= ~(1<<PC0);
	_delay_ms(100);
}

void Write (char Text[])
{
	PORTC |= (1<<PC1); //RS
	int i;
	for (i=0; i < strlen(Text); i++) //Read Letters
	{
		PORTD = Text[i]; //Send Letters
		Update();
	}
}

void Reset (Void)
{
	PORTC &= ~(1<<PC1); //RS
	PORTD = 0b00000001;
	Update();
	PORTD = 0b00000010;
	Update();
}
