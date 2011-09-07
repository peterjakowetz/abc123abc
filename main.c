#include <avr/io.h>          // this contains all the IO port definitions
#include <compat/ina90.h>    // among other things, contains _NOP()

#include "bot.h"
#include "logic.h"

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
    DDRB  = 0xFF;  
    PORTB = 0x00;  // all PORTB output pins Off

    DDRD  = 0xFF;  
    PORTD = 0x00;  // all PORTD output pins Off

    Bot bot;
    bot.leftSpeed = 0;
    bot.rightSpeed = 0;
    

    int i;
    while(1)
    {
	bot.leftSpeed = 1;
	bot.rightSpeed = 0;
	updateMotors(&bot);
	for (i=0; i < 5; i++) wait_some_time();
	
	bot.leftSpeed = 1;
	bot.rightSpeed = 1;
	updateMotors(&bot);
	for (i=0; i < 5; i++) wait_some_time();

	
    }
    return 0;
}