#include "sensor.h"
#include "sim_video.h"
#include "sim_bot.h"

SensorValue readSensor(SensorPosition pos, void* vbot)
{
    Bot* bot = (Bot*)vbot;
    SDL_Surface* maze = bot->maze;
    setOffset(bot->posX,bot->posY);
    setRotationMatrix(bot->rotation);
    
    Point sensor;
    
    if (pos == SENSOR_LEFT) sensor = getTransformedPoint(-BOT_SENSOR_DIST_SIDE, -BOT_SENSOR_DIST_FORWARD);
    else if (pos == SENSOR_CENTRE) sensor = getTransformedPoint(0, -BOT_SENSOR_DIST_FORWARD);
    else if (pos == SENSOR_RIGHT) sensor = getTransformedPoint(BOT_SENSOR_DIST_SIDE, -BOT_SENSOR_DIST_FORWARD);
    
    if (sensor.x < 0 || sensor.x > bot->screen->w || sensor.y < 0 || sensor.y > bot->screen->h) return WHITE;
    
    Uint32 pixel = *((Uint32*)(maze->pixels + maze->format->BytesPerPixel*((int)(sensor.x) + (int)(sensor.y)*maze->w)));
    
    Uint8 r,g,b;
    SDL_GetRGB(pixel, maze->format, &r,&g,&b);
    
    if (r < 20) return BLACK;
    else if (r < 220) return GREY;
    else return WHITE;
}