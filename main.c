#include <avr/io.h>          // this contains all the IO port definitions
#include <compat/ina90.h>    // among other things, contains _NOP()

#include "bot.h"
#include "logic.h"
#include "pwm.h"
#include "sensor.h"

void wait_some_time()
{
    // Use this to store the counter at SRAM. This will be slower.
    //volatile unsigned short int t = 0;

    // Use this to store the counter inside registers.
    register unsigned short int t = 0;

    while(++t) _NOP();
}

int main()
{
    //Setup PB1 & PB2 as outputs
    DDRD  = 0x2 | 0x4;
    
    //Setup PD0 to PD3 as outputs
    DDRD  = 0x1 | 0x2 | 0x4 | 0x8;
    
    //Initialise PWM
    initPwm();
    
    //PORTB = 0x00;  // all PORTB output pins Off
    //PORTD = 0x00;  // all PORTD output pins Off

    Bot bot;
    bot.leftSpeed = 0;
    bot.rightSpeed = 0;
    

    int i;
    char dir = 1, pos = 0;
    while(1)
    {
	bot.leftSensor = readSensor(SENSOR_LEFT, &bot);
	bot.centreSensor = readSensor(SENSOR_CENTRE, &bot);
	bot.rightSensor = readSensor(SENSOR_RIGHT, &bot);
    
	doLogicStep(&bot, 0);
	
	/*
	
	
	
	bot.leftSpeed = 1;
	bot.rightSpeed = 0;
	updateMotors(&bot);
	for (i=0; i < 5; i++) wait_some_time();
	
	bot.leftSpeed = 1;
	bot.rightSpeed = 1;
	updateMotors(&bot);
	for (i=0; i < 5; i++) wait_some_time();
	*/
	pos += dir;
	if (pos > 126)
	{
	    dir = -1;
	    pos = 126;
	}
	if (pos < -127)
	{
	    dir = 1;
	    pos = -127;
	}
	
	bot.leftSpeed = pos;
	updateMotors(&bot);
	wait_some_time();
	
    }
    return 0;
}