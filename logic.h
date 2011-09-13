void doLogicStep (Bot* bot, unsigned short timeDeltaMillis)
{
  bot->lastlogiccheck += timeDeltaMillis;

  if (bot->lastlogiccheck > bot->checkdelay)
  {
	bot->lastlogiccheck = 0;
    if (bot->leftSensor == GREY || bot->rightSensor == GREY || bot->centreSensor == GREY) bot->done = 1;
	else if (bot->checkright == 1)
	{
	  if (bot->centreSensor == WHITE)
	  {
		bot->leftSpeed = 127;
		bot->rightSpeed = -127;
		bot->checkright = 0;
		bot->checkdelay = 0;
	  }
// 	  else if(bot->centreSensor == BLACK)
// 	  {
// 		bot->leftSpeed = 127;
// 		bot->rightSpeed = 127;
// 		bot->checkright == 0;
// 	  }
	}
	else if (bot->centreSensor == WHITE)
	{ // when all sensers r white
	  if (bot->leftSensor == WHITE && bot->rightSensor == WHITE)
	  { // goes forward for a bit
		if (bot->uturn == 0)
		{
		  bot->leftSpeed = 127;
		  bot->rightSpeed = 127;
		  bot->checkdelay = 200;
		  bot->uturn = 1;
		} // then do a u turn to left or right
		else if (bot->uturn == 1)
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
	  { //when mid is white and one of side is black
		bot->leftSpeed = 127;
		bot->rightSpeed = -127;
		bot->checkdelay = 50;
		bot->uturn = 0;
	  }
	  else if (bot->leftSensor == BLACK && bot->rightSensor == WHITE)
	  {
		bot->leftSpeed = -127;
		bot->rightSpeed = 127;
		bot->checkdelay = 50;
		bot->uturn = 0;
	  }
	}
    else if (bot->centreSensor == BLACK)
	{ //mid sensor is black
	  bot->uturn = 0; //no u turn when middle touches white straight away
	  if (bot->leftSensor == WHITE && bot->rightSensor == WHITE)
	  { //side sensors all white then go straight
	  bot->leftSpeed = 127;
	  bot->rightSpeed = 127;
	  bot->checkdelay = 0;
	  
	  }
	  else if (bot->leftSensor == BLACK && bot->rightSensor == WHITE)
	  { // left sensor black, then turn left
	  bot->leftSpeed = 0;
	  bot->rightSpeed = 127;
	  bot->checkdelay = 150;
	  }
	  else if (bot->leftSensor == BLACK && bot->rightSensor == BLACK)
	  { // both black, then also turn left with longer delay
		  bot->leftSpeed = 0;
		  bot->rightSpeed = 127;
		  bot->checkdelay = 1000;
	  }
	  else if (bot->leftSensor == WHITE && bot->rightSensor == BLACK)
	  { // right sensor black, then turn right
		if (bot->checkright == 0)
		{
		bot->leftSpeed = 127;
		bot->rightSpeed = 127;
		bot->checkdelay = 150;
		bot->checkright = 1;
		}
	  }
	}
  }
  
  // codes to remember the last turning direction for the uturn
  if (bot->leftSpeed == 127 && bot->rightSpeed <= 0)
	bot->lastturn = RIGHT;
  else if (bot->rightSpeed == 127 && bot->leftSpeed <= 0)
	bot->lastturn = LEFT;
  
}