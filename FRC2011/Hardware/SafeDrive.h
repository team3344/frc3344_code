
#ifndef SAFEDRIVE_H_
#define SAFEDRIVE_H_

#include "wpilib.h"




class SafeDrive : public RobotDrive {




	//	given the left & right wheel speeds, finds the turn radius
	double calculateTurnRadius(double left, double right);


	double calculateCentripetalAcceleration(double velocity, double turnRadius);

	double momentOfInertia;
	double robotRadius;
	double cgHeight;
	double maxAcceleration;

};




#endif /* SAFEDRIVE_H_ */
