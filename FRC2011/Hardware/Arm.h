
#include "wpilib.h"
#include "ThreeStateSolenoid.h"


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
	|   shoulder
	|
	|support bar

*/



//	all in inches
const double FOREARM_LENGTH 33;	//	FIXME: these aren't right???
const double BACKARM_LENGTH 33;
const double SUPPORT_HEIGHT 51;


class Arm {
	
	//	FIXME: create constructor
	
	
	
	
	
	
	//	arm position
	float shoulderAngle();	//	0 is horizontal.  vertical is pi / 2
	float elbowAngle();		//	0 is fully extended.  
	
	
	//	shoulder adjustment
	void holdShoulder();
	void raiseShoulder();
	void lowerShoulder();
	
	//	elbow adjustment
	void holdElbow();
	void raiseElbow();
	void lowerElbow();
	
	
	void calibrate();
	
	
	
private:
	//	solenoid that controls shoulder cylinder
	ThreeStateSolenoid *_shoulderSolenoid;
	
	//	elbow
	Jaguar *_elbowJaguar;
	
	PIDController *_elbowPositionController;
	
	
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
