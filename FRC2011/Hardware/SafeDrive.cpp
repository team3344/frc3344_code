
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



//	returns an equivalent angle between 0 & 2pi
double SafeDrive::reduceAngle(double angle)
{
	double two_pi = 2 * PI;
	
	while ( angle > two_pi )
	{
		angle -= two_pi;
	}
	while ( angle < 0 )
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
	
	
	Vector cg;	//	FIXME:	=	_cgLocationFunction();	//	????
	
	
	
	double angle = reduceAngle(direction + PI);
	//	slope = tan(angle)
	//	linear equation: Y - cg.y = slope * (X - cg.x)
	//	Y = X*tan(angle) - cg.x*tan(angle) + cg.y
	//	X = (Y - cg.y) / slope + cg.x
	
	double yIntercept = cg.y - cg.x*tan(angle);
	
	
	
	if ( angle > (PI / 2) && angle < (3/4 *PI) )	//	quadrants 2 & 3
	{
		//	FIXME:
	}
	else	//	quadrants 1 & 4
	{
		//	FIXME: 
	}
	
	
	double x, y;	//	FIXME: solve these!!!
	
	
	double radius = sqrt( pow(x, 2) + pow(y, 2) );
	
	//	max acceleration = g * (radius)/(cg height)
	double maxAcceleration = (32) * (radius / cg.z);
	
	
	
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



