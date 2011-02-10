
#include "SafeDrive.h"


double SafeDrive::maxAllowedAcceleration(double direction)
{
	//	FIXME: implement
}



//	given the left & right wheel speeds, finds the turn radius
double SafeDrive::calculateTurnRadius(double left, double right)
{
	//	FIXME: implement


	//	FIXME: does this work for all cases?????  which doesn't it work for???
	double radius = (wheelBaseWidth * (left + right)) / (2 * (left - right));






	return radius;
}


double SafeDrive::calculateCentripetalAcceleration(double velocity, double turnRadius)
{
	return abs( pow(velocity, 2) / turnRadius );	//	v^2 / r
}




