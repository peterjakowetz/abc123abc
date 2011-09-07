#ifndef BOT_INCLUDED
#define BOT_INCLUDED

#include "sensor.h"
#include <avr/io.h>

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