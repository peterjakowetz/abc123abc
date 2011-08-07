#include "sim_bot.h"
#include "math.h"

void simBotStep(Bot* bot, double stepSize)
{
    double avgSpeed = (bot->leftSpeed + bot->rightSpeed) /2;
    
    bot->rotation += stepSize*(bot->leftSpeed - bot->rightSpeed);
    
    bot->posY += -cos(bot->rotation) * stepSize * avgSpeed;
    bot->posX += sin(bot->rotation) * stepSize * avgSpeed;
    
    if (bot->posY > 10) bot->done = 1;
};