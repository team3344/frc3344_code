
#include "wpilib.h"
#include "ThreeStateSolenoid.h"


#ifndef ARM_H
#define ARM_H




/*

counter-clockwise is positive

					 /
					/
			elbow  /
	______________/
	|
	| shoulder
	|
	|
	|

*/


class Arm {
	
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
	
	
private:
	//	solenoid that controls shoulder cylinder
	ThreeStateSolenoid *_shoulderSolenoid;
	
	//	elbow
	Jaguar *_shoulderDensoLeft;
	Jaguar *_shoulderDensoRight;
	
};






#endif	//	ARM_H
