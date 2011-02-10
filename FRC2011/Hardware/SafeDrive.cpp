
#include "SafeDrive.h"


SafeDrive::SafeDrive(double wheelbaseWidth, double wheelbaseLength, FUNCPTR cgHeightFunction)
{
	_wheelbaseWidth = wheelbaseWidth;
	_wheelbaseLength = wheelbaseLength;
	_cgLocationFunction = cgLocationFunction;
	
	//	FIXME: initialize??????
}

SafeDrive::~SafeDrive()
{
	//	FIXME: implement
}


void SafeDrive::setSafeModeActive(bool active)
{
	_safeModeActive = active;
	
	//	FIXME: activate protection task???????
}

bool SafeDrive::safeModeActive()
{
	return _safeModeActive;
}



/********************	Calculations	********************/

double SafeDrive::maxAllowedAcceleration(double direction)
{
	//	FIXME: implement
	
}


double SafeDrive::calculateVelocity(double left, double right)
{
	
}


//	given the left & right wheel speeds, finds the turn radius
double SafeDrive::calculateTurnRadius(double left, double right)
{
	//	FIXME: does this work for all cases?????  which doesn't it work for???
	double radius = (wheelBaseWidth * (left + right)) / (2 * (left - right));

	return radius;
}

double SafeDrive::calculateCentripetalAcceleration(double velocity, double turnRadius)
{
	return abs( pow(velocity, 2) / turnRadius );	//	v^2 / r
}



