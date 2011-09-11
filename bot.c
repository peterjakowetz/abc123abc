#include "bot.h"
#include "stdlib.h"


void updateMotors(Bot* bot)
{
    if (bot->leftSpeed == 0)
    {
	//PORTB &= ~0x2; //Disable left
	setPwmDuty(PWM_LEFT, 0);
	PORTD &= ~0x3; //Set PD0 & 1 to 0
    }
    else
    {
	unsigned char rawSpeed = 2 * abs(bot->leftSpeed);
	//rawSpeed *= 2;
	//PORTB |= 0x2;
	setPwmDuty(PWM_LEFT, rawSpeed);
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
	//PORTB &= ~0x4; // Disable right
	setPwmDuty(PWM_RIGHT, 0);
	PORTD &= ~0x12; // Set PD2 & 3 to 0
    }
    else
    {
	unsigned char rawSpeed = 2 * abs(bot->rightSpeed);
	//rawSpeed *= 2;
	setPwmDuty(PWM_RIGHT, rawSpeed);
	//PORTB |= 0x4;
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