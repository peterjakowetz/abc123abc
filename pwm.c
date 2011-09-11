#include "pwm.h"
#include <avr/io.h>

void setPwmDuty(PWMChannel channel, unsigned char duty)
{
    if (channel == OC1A) OCR1A = duty;
    else if (channel == OC1B) OCR1B = duty;
}


//Initialisation code from http://members.shaw.ca/climber/avrtimers.html
void initPwm()
{
    OCR1A = 0;
    OCR1B = 0;
    
    TCCR1A = _BV(WGM10)    // 8 bit fast PWM, see WGM12 below
       | _BV(COM1A1)   // set OC1A/B on compare match, clear them at top
       | _BV(COM1B1);
    
    TCCR1B = _BV(CS11)     // 1/8 prescale
       | _BV(WGM12) ;  // fast PWM
}