
#ifndef SAFEDRIVE_H_
#define SAFEDRIVE_H_

#include "wpilib.h"




class SafeDrive : public RobotDrive {



	double wheelbaseWidth, wheelbaseLength;


	//	direction: 0 is right, PI / 2 is straight ahead, etc.
	double maxAllowedAcceleration(double direction);




	//	given the left & right wheel speeds, finds the turn radius
	//	negative values = right turn, positive = left turn
	double calculateTurnRadius(double left, double right);


	double calculateCentripetalAcceleration(double velocity, double turnRadius);

	double momentOfInertia;
	double robotRadius;
	double cgHeight;
	double maxAcceleration;

};




#endif /* SAFEDRIVE_H_ */
