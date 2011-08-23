#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "sim_video.h"
#include "sim_bot.h"
#include "sensor.h"
//Include logic after everything else for lazy reasons
#include "logic.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480


int main(int argc, char* argv[])
{
    if (argc < 2)
    {
	printf("Usage: %s <maze image>\n", argv[0]);
	return 1;
    }
    
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    
    SDL_Surface* screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, 0);
    SDL_Surface* maze = IMG_Load(argv[1]);
    if (maze == NULL) printf("NULL MAZE\n");
    
    setScaleFactor(100);
    
    
    Bot bot;
    bot.done = 0;
    bot.posX = 1.5;
    bot.posY = 5.0;
    bot.leftSpeed = 255;
    bot.rightSpeed = 128;
    
    bot.rotation = 0;
    bot.screen = screen;
    bot.maze = maze;
    
    readSensor(SENSOR_LEFT, &bot);
    readSensor(SENSOR_CENTRE, &bot);
    readSensor(SENSOR_RIGHT, &bot);
    
    
    setMaze(maze);
    clearScreen(screen);
    drawMaze(screen, NULL);
    SDL_Flip(screen);
    int i;
    Uint32 ticks = SDL_GetTicks();
    Uint32 lastTicks = ticks;
    
    while (!bot.done)
    {
	
	Uint32 ticks = SDL_GetTicks();
	
	bot.leftSensor = readSensor(SENSOR_LEFT, &bot);
	bot.centreSensor = readSensor(SENSOR_CENTRE, &bot);
	bot.rightSensor = readSensor(SENSOR_RIGHT, &bot);
    
	doLogicStep(&bot);
	
	simBotStep(&bot, (double)(ticks-lastTicks)/1000.0);
	
	
	SDL_Rect updateRect = getBotRect(bot.posX,bot.posY);
	clearScreenRect(screen, &updateRect);
	drawMaze(screen, &updateRect);
	drawBot(&bot);
	SDL_UpdateRect(screen, updateRect.x,updateRect.y, updateRect.w, updateRect.h);
	lastTicks =  ticks;
	//printf("%d, %d, %d, %d\n", updateRect.x,updateRect.y, updateRect.w, updateRect.h);
    }
    //drawBot(0,0,0,screen);
    //SDL_Flip(screen);
    
    SDL_Delay(1000);
    
    
    SDL_FreeSurface(screen);
    
    IMG_Quit();
    SDL_Quit();
    
    
    
    
}
