#include "sim_bot.h"
#include "math.h"

void simBotStep(Bot* bot, double stepSize)
{
    double leftSpeed = (double)bot->leftSpeed/127.0;
    double rightSpeed = (double)bot->rightSpeed/127.0;
    
    
    double avgSpeed = (leftSpeed + rightSpeed) /2;
    
    bot->rotation += stepSize*(leftSpeed - rightSpeed);
    
    bot->posY += -cos(bot->rotation) * stepSize * avgSpeed;
    bot->posX += sin(bot->rotation) * stepSize * avgSpeed;
    
    if (bot->posY > 10) bot->done = 1;
};