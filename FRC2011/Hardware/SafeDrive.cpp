
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

double _forceEquationXValue(Vector cg, double angle, double y)
{
	//	X = ((Y - cg.y) / slope) + cg.x
	return ( (y -cg.y) / tan(angle)) + cg.x;
}

double _forceEquationYValue(Vector &cg, double angle, double x)
{
	//	Y = X*tan(angle) - cg.x*tan(angle) + cg.y
	return (x - cg.x) * tan(angle) + cg.y;
}


double SafeDrive::maxAllowedAcceleration(double direction)
{
	//	FIXME: implement
	
	Vector cg;	//	FIXME:	=	_cgLocationFunction();	//	????
	
	
	double angle = reduceAngle(direction + PI);
	//	slope = tan(angle)
	//	linear equation: Y - cg.y = slope * (X - cg.x)
	//	Y = X*tan(angle) - cg.x*tan(angle) + cg.y
	//	X = ((Y - cg.y) / slope) + cg.x
	
	
	double yIntercept = _forceEquationYValue(&cg, angle, 0);
	double xIntercept = _forceEquationXValue(&cg, angle, 0);

	
	bool leftEdge = yIntercept >= 0 && yIntercept <= wheelbaseLength;
	bool bottomEdge = xIntercept >= 0 && xIntercept <= wheelbaseWidth;
	//bool rightEdge = ???
	//bool topEdge = //	???
	//	FIXME:



	bool up = angle < PI;	//	is angle in quadrants 1 or 2?
	
	



	double x, y;	//	FIXME: solve these!!!
	
	
	double radius = sqrt( pow(x, 2) + pow(y, 2) );
	
	//	max acceleration = g * (radius)/(cg height)
	double maxAcceleration = (32) * (radius / cg.z);
	
	return maxAcceleration;
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



