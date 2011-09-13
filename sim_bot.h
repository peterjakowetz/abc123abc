#ifndef BOT_INCLUDED
#define BOT_INCLUDED

#include "sensor.h"
#include "SDL/SDL.h"

#define BOT_SENSOR_DIST_FORWARD 0.40
#define BOT_SENSOR_DIST_SIDE 0.12

#define LEFT 1
#define RIGHT 2
#define TURNAOUND 3


typedef unsigned char uint8_t;

struct Bot
{
    double leftSpeed;
    double rightSpeed;
    SensorValue leftSensor;
    SensorValue centreSensor;
    SensorValue rightSensor;
    int done;
    
    
    double posX;
    double posY;
    double rotation;
    
    SDL_Surface* screen;
    SDL_Surface* maze;
	
	int lastlogiccheck;
	int checkdelay;
	int uturn;
	int lastturn;

};

typedef struct Bot Bot;

void simBotStep(Bot* bot, double stepSize);


#endif