
#ifndef SAFEDRIVE_H_
#define SAFEDRIVE_H_

#include "wpilib.h"



class SafeDrive : public RobotDrive {

	SafeDrive(double wheelbaseWidth, double wheelbaseLength, FUNCPTR cgHeightFunction = NULL);
	~SafeDrive();

	
	
	void Drive(double left, double right);
	
	//	FIXME: add TankDrive & ArcadeDrive functions!
	
	
	
	
	
	void setSafeModeActive(bool active);
	bool safeModeActive();
	
	
	
	/**********		Calculations	**********/
	
	//	direction: 0 is right, PI / 2 is straight ahead, etc.
	double maxAllowedAcceleration(double direction);


	//	given the left & right wheel speeds, finds the turn radius
	//	negative values = right turn, positive = left turn
	double calculateTurnRadius(double left, double right);

	double calculateVelocity(double left, double right);

	double calculateCentripetalAcceleration(double velocity, double turnRadius);
	
	
private:
	
	bool _safeModeActive;
	Task _protectionTask;
	double _wheelbaseWidth, _wheelbaseLength;
	FUNCPTR _cgHeightFunction;
	
	//	max velocity???????
};




#endif /* SAFEDRIVE_H_ */

