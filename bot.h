#ifndef BOT_INCLUDED
#define BOT_INCLUDED

#include <avr/io.h>
#include "sensor.h"
#include "pwm.h"

#define PWM_LEFT OC1A
#define PWM_RIGHT OC1B
#define LEFT 1
#define RIGHT 2
#define TURNAOUND 3


typedef unsigned char uint8_t;

struct Bot
{
    char leftSpeed;
    char rightSpeed;
    SensorValue leftSensor;
    SensorValue centreSensor;
    SensorValue rightSensor;
    int done;
	int keepgoing;
	int direction;
};

typedef struct Bot Bot;

void updateMotors(Bot* bot);

#endif