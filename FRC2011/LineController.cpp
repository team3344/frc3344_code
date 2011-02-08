
#include "LineController.h"

LineController(LightSensorArray *lsArray)
{
	
}

~LineController()
{
	
}


//	line-following speed
void setSpeed(float speed)
{
	_speed = speed;
}

float speed()
{
	return _speed;
}



bool followingLine()
{
	return false;	//	FIXME: implement!!! look at running Task?
}

bool lineIsThick()
{
	return _lsArray->state() == kLeftOn | kMidOn | kRightOn;	//	return true if they're all on
}


