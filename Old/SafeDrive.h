
#ifndef SAFEDRIVE_H_
#define SAFEDRIVE_H_

#include "wpilib.h"
#include "../Vector.h"
#include <math.h>
#include "../Defines.h"



class SafeDrive	{	//FIXME: : public RobotDrive {
public:
	SafeDrive(double wheelbaseWidth, double wheelbaseLength, FUNCPTR cgLocationFunction = NULL);
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
	void SafeDrive::initPIDControllers();
	
	double reduceAngle(double angle);
	
	double _forceEquationXValue(Vector cg, double angle, double y);
	double _forceEquationYValue(Vector &cg, double angle, double x);
	
	bool _safeModeActive;
	//Task _protectionTask;
	double _wheelbaseWidth, _wheelbaseLength;
	FUNCPTR _cgLocationFunction;	//	FIXME: make this return a Vector!!!!!!!!!!!!!!!
	
	PIDController *_leftSpeedController;
	PIDController *_rightSpeedController;
	
	
	
	double _leftTarget, _rightTarget;
	
	//	double _leftAcceleration, _rightAcceleration;	//	FIXME: are these necessary???
	
	
	//	max velocity???????
};



#endif /* SAFEDRIVE_H_ */

