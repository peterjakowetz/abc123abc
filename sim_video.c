#include <math.h>
#include "sim_video.h"
#include "SDL/SDL_gfxPrimitives.h"

//Rotation matrix:
// rm[0]   rm[1]
// rm[2]   rm[3]
//
double rotMatrix[4] = {0,0,0,0};

Point offset;

double scalar;

SDL_Surface* mazeSurf;

void clearScreenRect(SDL_Surface* screen, SDL_Rect* rect)
{
    SDL_FillRect(screen, rect, 0xFFFFFF);
}

void clearScreen(SDL_Surface* screen)
{
    clearScreenRect(screen,NULL);
}

void setRotationMatrix(double rotation)
{
    rotMatrix[0] = cos(rotation);
    rotMatrix[1] = -sin(rotation);
    rotMatrix[2] = -rotMatrix[1];
    rotMatrix[3] = rotMatrix[0];  
}

Point getTransformedPoint(double x, double y)
{
    Point ret;
    ret.x=(rotMatrix[0]*x + rotMatrix[1]*y + offset.x)*scalar;
    ret.y=(rotMatrix[2]*x + rotMatrix[3]*y + offset.y)*scalar;
    return ret;
}

SDL_Rect getBotRect(double x, double y)
{
    SDL_Rect rect;
    setOffset(x,y);
    Point centre = getTransformedPoint(0,0);
    rect.x = centre.x - 50;
    rect.y = centre.y - 50;
    rect.w = 100;
    rect.h = 100;
    return rect;
}

void setOffset(double x, double y)
{
    offset.x = x;
    offset.y = y;
}

void setScaleFactor(double pixelsPerMetre)
{
    scalar = pixelsPerMetre;
}

void setMaze(SDL_Surface* maze)
{
    mazeSurf = maze;
}

void drawBot(Bot* bot)
{
    setOffset(bot->posX,bot->posY);
    setRotationMatrix(bot->rotation);
    
    
    Point chassis1 = getTransformedPoint(-0.2,.26);
    Point chassis2 = getTransformedPoint(0.2,.26);
    Point chassis3 = getTransformedPoint(0.2,-.26);
    Point chassis4 = getTransformedPoint(-0.2,-.26);
    
    Point leftAxis1 = getTransformedPoint(-0.2,0);
    Point leftAxis2 = getTransformedPoint(-.26,0);
    Point rightAxis1 = getTransformedPoint(0.2,0);
    Point rightAxis2 = getTransformedPoint(.26,0);
    
    Point sensorLeft = getTransformedPoint(-BOT_SENSOR_DIST_SIDE, -BOT_SENSOR_DIST_FORWARD);
    Point sensorCentre = getTransformedPoint(0, -BOT_SENSOR_DIST_FORWARD);
    Point sensorRight = getTransformedPoint(BOT_SENSOR_DIST_SIDE, -BOT_SENSOR_DIST_FORWARD);
    
    
    
    aalineRGBA (bot->screen, chassis1.x, chassis1.y, chassis2.x, chassis2.y, 0, 0, 0, 255);
    aalineRGBA (bot->screen, chassis3.x, chassis3.y, chassis2.x, chassis2.y, 0, 0, 0, 255);
    aalineRGBA (bot->screen, chassis3.x, chassis3.y, chassis4.x, chassis4.y, 0, 0, 0, 255);
    aalineRGBA (bot->screen, chassis1.x, chassis1.y, chassis4.x, chassis4.y, 0, 0, 0, 255);
    
    aalineRGBA (bot->screen, leftAxis1.x, leftAxis1.y, leftAxis2.x, leftAxis2.y, 0, 0, 0, 255);
    aalineRGBA (bot->screen, rightAxis1.x, rightAxis1.y, rightAxis2.x, rightAxis2.y, 0, 0, 0, 255);
    
    pixelRGBA (bot->screen, sensorLeft.x, sensorLeft.y, 0,0,0,255);
    pixelRGBA (bot->screen, sensorCentre.x, sensorCentre.y, 0,0,0,255);
    pixelRGBA (bot->screen, sensorRight.x, sensorRight.y, 0,0,0,255);
    
}

void drawMaze(SDL_Surface* screen, SDL_Rect* rect)
{
    SDL_BlitSurface(mazeSurf, rect, screen, rect);
}