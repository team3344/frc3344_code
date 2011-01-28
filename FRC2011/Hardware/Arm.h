
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
	
	
	float shoulderAngle();	//	0 is horizontal.  vertical is pi / 2
	float elbowAngle();		//	0 is fully extended.  
	
	
	//	shoulder adjustment
	void holdShoulder();
	void raiseShoulder();
	void lowerShoulder();
	
	//	elbow adjustment
	
	
	
private:
	ThreeStateSolenoid *_shoulderSolenoid;
	
};






#endif	//	ARM_H
