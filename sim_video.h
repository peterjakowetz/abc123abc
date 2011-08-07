#include "SDL/SDL.h"
#include "sim_bot.h"

struct Point
{
    double x, y;
};
typedef struct Point Point;

void setScaleFactor(double pixelsPerMetre);

void clearScreen(SDL_Surface* screen);

void clearScreenRect(SDL_Surface* screen, SDL_Rect* rect);

SDL_Rect getBotRect(double x, double y);

void drawBot(Bot* bot);

void drawMaze(SDL_Surface* screen, SDL_Rect* rect);

Point getTransformedPoint(double x, double y);