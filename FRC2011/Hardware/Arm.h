
#include "wpilib.h"
#include "Potentiometer.h"
#include "../Defines.h"
#include <math.h>

#ifndef ARM_H
#define ARM_H



/*

counter-clockwise is positive

					 /
					/
			elbow  /	forearm
	______________/
	|	backarm
	| 
	|shoulder
	|
	|support bar

*/



//	all in inches
const double FOREARM_LENGTH = 33;	//	FIXME: these aren't right???
const double BACKARM_LENGTH = 33;
const double SUPPORT_HEIGHT = 51;


//	joint angle limits
const double ELBOW_MIN_ANGLE = -PI / 2;		//	FIXME: these are wrong
const double ELBOW_MAX_ANGLE = PI / 2;		//

const double SHOULDER_MIN_ANGLE = -PI / 4;	//
const double SHOULDER_MAX_ANGLE = 3/4 * PI;	//



class Arm {

public:
	Arm();
	~Arm();
	
	
	void logInfo();
	
	
	//	arm position
	float shoulderAngle();		//	0 is horizontal.  vertical is pi / 2
	float elbowAngle();			//	0 is fully extended.  relative to "backarm"
	float absoluteElbowAngle();	//	relative to ground.  0 is horizontal
	
	double recommendedElbowPowerForDirection(int direction);	//	direction is +/-1
	
	
	//	shoulder adjustment
	//void holdShoulder();
	void raiseShoulder();
	void lowerShoulder();
	
	//	elbow adjustment
	//void holdElbow();
	//void raiseElbow();
	//void lowerElbow();

	
	
	//float elbowPosition();
	//void setElbowAngle(float angle);
	bool positionOutOfRangeForElbow(float position);
	float restrictedElbowPosition(float position);
	//void setAbsoluteElbowAngle(float absAngle);

	Victor *_elbowController;

private:
	//	solenoid that controls shoulder cylinder
	DoubleSolenoid *_shoulderSolenoid;
	
	
	//	elbow
	Potentiometer *_elbowPositionSensor;
	PIDController *_elbowPIDController;
	
	
	
	
	/*
	 * 	tracks whether or not the arm should try to
	 *	get to the elbow & shoulder targets.
	 *	Use this in autonomous, but not in TeleOp.
	 */
	bool _autoElbow, _autoShoulder;
	
	
	//	angles where we want the elbow and shoulder to be
	double _elbowTarget, _shoulderTarget;	
};






#endif	//	ARM_H
