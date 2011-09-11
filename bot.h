#ifndef BOT_INCLUDED
#define BOT_INCLUDED

#include <avr/io.h>
#include "sensor.h"
#include "pwm.h"

#define PWM_LEFT OC1A
#define PWM_RIGHT OC1B

typedef unsigned char uint8_t;

struct Bot
{
    char leftSpeed;
    char rightSpeed;
    SensorValue leftSensor;
    SensorValue centreSensor;
    SensorValue rightSensor;
    int done;
};

typedef struct Bot Bot;

void updateMotors(Bot* bot);

#endif