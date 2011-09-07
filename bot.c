#include "bot.h"

void updateMotors(Bot* bot)
{
    if (bot->leftSpeed == 0)
    {
	PORTB &= ~0x2; //Disable left
	PORTD &= ~0x3; //Set PD0 & 1 to 0
    }
    else
    {
	PORTB |= 0x2;
	if (bot->leftSpeed > 0)
	{
	    PORTD &= ~0x2;
	    PORTD |= 0x1;
	}
	else
	{
	    PORTD &= ~0x1;
	    PORTD |= 0x2;
	}
    }

    if (bot->rightSpeed == 0)
    {
	PORTB &= ~0x4; // Disable right
	PORTD &= ~0x12; // Set PD2 & 3 to 0
    }
    else
    {
	PORTB |= 0x4;
	if (bot->rightSpeed < 0)
	{
	    PORTD &= ~0x8;
	    PORTD |= 0x4;
	}
	else
	{
	    PORTD &= ~0x4;
	    PORTD |= 0x8;
	}
    }
}