void doLogicStep (Bot* bot, unsigned short timeDeltaMillis)
{
  bot->lastlogiccheck += timeDeltaMillis;
  
/*
  if (bot->lastlogiccheck > 50 + bot->checkdelay)

  {
	bot->lastlogiccheck = 0;
    if (bot->leftSensor == GREY || bot->centreSensor == GREY || bot->rightSensor == GREY) bot->done = 1;
	else if (bot->leftSensor == WHITE && bot->centreSensor == BLACK)
	{
	bot->leftSpeed = 127;
	bot->rightSpeed = 127;
	
	}
	else if (bot->leftSensor == BLACK && bot->centreSensor == BLACK)
	{
	bot->leftSpeed = -127;
	bot->rightSpeed = 127;
	bot->checkdelay = 100;
	
	}
	else if (bot->leftSensor == WHITE && bot->centreSensor == WHITE)
	{
	  bot->leftSpeed = 127;
	  bot->rightSpeed = -127;
	bot->checkdelay = 100;
	}
  }
*/

  if (bot->lastlogiccheck > bot->checkdelay)
  {
	bot->lastlogiccheck = 0;
    if (bot->leftSensor == GREY || bot->rightSensor == GREY || bot->centreSensor == GREY) bot->done = 1;
	else if (bot->centreSensor == WHITE)
	{
	  if (bot->leftSensor == WHITE && bot->rightSensor == WHITE)
	  {
		if (bot->uturn == 0)
		{
		  bot->leftSpeed = 127;
		  bot->rightSpeed = 127;
		  bot->checkdelay = 200;
		  bot->uturn = 1;
		}
		else
		{
		  if (bot->lastturn == LEFT)
		  {
			bot->leftSpeed = -127;
		    bot->rightSpeed = 127;
		    bot->checkdelay = 0;
		  }
		  else if (bot->lastturn == RIGHT)
		  {
			bot->leftSpeed = 127;
		    bot->rightSpeed = -127;
		    bot->checkdelay = 0;
		  }
		}
		  
	  }
	  else if (bot->leftSensor == WHITE && bot->rightSensor == BLACK)
	  {
		bot->leftSpeed = 127;
		bot->rightSpeed = -127;
		bot->checkdelay = 75;
		bot->uturn = 0;
	  }
	  else if (bot->leftSensor == BLACK && bot->rightSensor == WHITE)
	  {
		bot->leftSpeed = -127;
		bot->rightSpeed = 127;
		bot->checkdelay = 75;
		bot->uturn = 0;
	  }
	}
    else if (bot->centreSensor == BLACK)
	{
	  if (bot->leftSensor == WHITE && bot->rightSensor == WHITE)
	  {
	  bot->leftSpeed = 127;
	  bot->rightSpeed = 127;
	  bot->checkdelay = 0;
	  
	  }
	  else if (bot->leftSensor == BLACK && bot->rightSensor == WHITE)
	  {
	  bot->leftSpeed = 0;
	  bot->rightSpeed = 127;
	  bot->checkdelay = 125;
	  bot->lastturn = LEFT;
	  }
	  else if (bot->leftSensor == WHITE && bot->rightSensor == BLACK)
	  {
	  bot->leftSpeed = 127;
	  bot->rightSpeed = 0;
	  bot->checkdelay = 125;
	  bot->lastturn = RIGHT;
	  }
	  else if (bot->leftSensor == BLACK && bot->rightSensor == BLACK)
	  {
	  bot->leftSpeed = 0;
	  bot->rightSpeed = 127;
	  bot->checkdelay = 125;
	  bot->lastturn = LEFT;
	  }
	}
  }
}