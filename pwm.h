#ifndef PWM_INCLUDED
#define PWM_INCLUDED

enum PWMChannel {OC1A, OC1B};
typedef enum PWMChannel PWMChannel;

void setPwmDuty(PWMChannel channel, unsigned char duty);

void initPwm();

#endif