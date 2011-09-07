void doLogicStep (Bot* bot, unsigned short timeDeltaMillis)
{
    if (bot->leftSensor == GREY || bot->rightSensor == GREY || bot->centreSensor == GREY) bot->done = 1;
    else if (bot->leftSensor == WHITE && bot->rightSensor == WHITE)
    {
	bot->leftSpeed = 127;
	bot->rightSpeed = 127;
	
    }
    else if (bot->leftSensor == BLACK && bot->rightSensor == WHITE)
    {
	bot->leftSpeed = -127;
	bot->rightSpeed = 127;
    }
    else if (bot->leftSensor == WHITE && bot->rightSensor == BLACK)
    {
	bot->leftSpeed = 127;
	bot->rightSpeed = -127;
    }
    
    
}