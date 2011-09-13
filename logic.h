void doLogicStep (Bot* bot, unsigned short timeDeltaMillis)
{
  bot->lastlogiccheck += timeDeltaMillis;

  if (bot->lastlogiccheck > bot->checkdelay)
  {
	bot->lastlogiccheck = 0;
    if (bot->leftSensor == GREY || bot->rightSensor == GREY || bot->centreSensor == GREY) bot->done = 1;
	else  if (bot->leftSensor == WHITE)
	{
	  bot->leftSpeed = 127;
	  bot->rightSpeed = 36;
	  bot->checkdelay = 100;
	}
// 		if (bot->centreSensor == BLACK && bot->rightSensor == WHITE)
// 	    {
// 		bot->leftSpeed = 127;
// 		bot->rightSpeed = 127;
// 		bot->checkdelay = 300;
// 		}
// 		else if (bot->centreSensor == WHITE && bot->rightSensor == BLACK)
// 	    {
// 		bot->leftSpeed = 127;
// 		bot->rightSpeed = 0;
// 		bot->checkdelay = 100;
// 		}
// 		else if (bot->centreSensor == BLACK && bot->rightSensor == BLACK)
// 	    {
// 		bot->leftSpeed = 127;
// 		bot->rightSpeed = 0;
// 		bot->checkdelay = 200;
// 		}
// 		else if (bot->centreSensor == WHITE && bot->rightSensor == WHITE)
// 	    {
// 		bot->leftSpeed = 127;
// 		bot->rightSpeed = -127;
// 		bot->checkdelay = 300;
// 		}
// 	}
	  else if(bot->leftSensor == BLACK)
	  {
		bot->leftSpeed = -127;
		bot->rightSpeed = 127;
		bot->checkdelay = 500;
	  }
	}
  
}