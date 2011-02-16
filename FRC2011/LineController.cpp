
#include "LineController.h"

LineController::LineController(LightSensorArray *lsArray)
{
	
}

LineController::~LineController()
{
	
}


//	line-following speed
void LineController::setSpeed(float speed)
{
	_followingSpeed = speed;
}

float LineController::speed()
{
	return _followingSpeed;
}


float LineController::calculateTurn()
{
	//	FIXME: implement
	
	
	
}


bool LineController::followingLine()
{
	return false;	//	FIXME: implement!!! look at running Task?
}

bool LineController::lineIsThick()
{
	return _lsArray->state() == (LightSensorArray::LightSensorState)(LightSensorArray::kLeftOn | LightSensorArray::kMidOn | LightSensorArray::kRightOn);	//	return true if they're all on
}


