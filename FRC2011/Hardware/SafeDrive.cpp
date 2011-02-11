
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





void SafeDrive::initPIDControllers()
{
	//	FIXME: the following line is complete garbage!!!!!!!!!!!!!!!!!
	//_leftSpeedController = new PIDController(2, 1, 2, /*src*/, PIDOutput *output);
}




double SafeDrive::reduceAngle(double angle)
{
	double two_pi = 2 * PI;
	
	while ( angle > two_pi )
	{
		angle -= two_pi;
	}
	while ( angle < -two_pi )
	{
		angle += two_pi;
	}
	
	return angle;
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
	
	
	
	double angle = direction + PI;
	//	slope = tan(angle)
	//	linear equation: Y - cg.y = slope * (X - cg.x)
	//	Y = X*tan(angle) - cg.x*tan(angle) + cg.y
	
	
	double x, y;
	
	
	if ( angle = PI / 2 )
	{
		
	}
	
	
	
	
	Vector cgLocation;	//	=	_cgLocationFunction();	//	????
	
	
	
	
	
}


double SafeDrive::calculateVelocity(double left, double right)
{
	
}


//	given the left & right wheel speeds, finds the turn radius.  negative values = right turn. positive = left
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



