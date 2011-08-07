void doLogicStep (Bot* bot)
{
    if (bot->leftSensor == GREY || bot->rightSensor == GREY || bot->centreSensor == GREY) bot->done = 1;
    else if (bot->leftSensor == WHITE && bot->rightSensor == WHITE)
    {
	bot->leftSpeed = 1;
	bot->rightSpeed = 1;
	
    }
    else if (bot->leftSensor == BLACK && bot->rightSensor == WHITE)
    {
	bot->leftSpeed = -1;
	bot->rightSpeed = 1;
    }
    else if (bot->leftSensor == WHITE && bot->rightSensor == BLACK)
    {
	bot->leftSpeed = 1;
	bot->rightSpeed = -1;
    }
    
    
}