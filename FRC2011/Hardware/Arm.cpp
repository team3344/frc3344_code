

#include "Arm.h"


float Arm::shoulderAngle()
{
	return 1;	//	FIXME: ;asdkfj;asdjf;sdjkf
}

float Arm::elbowAngle()
{
	return 1.0;	//	FIXME: sd;fajsd;fjas;fj;sdafkj
}

float Arm::absoluteElbowAngle()
{
	return shoulderAngle() + elbowAngle();
}

//	shoulder adjustment
void Arm::holdShoulder()
{
	
}

void Arm::raiseShoulder()
{
	
}

void Arm::lowerShoulder()
{
	
}

//	elbow adjustment
void Arm::holdElbow()
{
	
}
void Arm::raiseElbow()
{
	
}
void Arm::lowerElbow()
{
	
}



/*	Arm protection - keeps joints from over-extending	*/

void Arm::protectArm()
{
	while ( true )
	{
		//	if elbow at end of range & trying to go further, stop!!!
	}
}


void Arm::InitArmProtector()
{
	_armProtector = new Task("Arm Protector", &Arm::protectArm);	//	FIXME: is this legit syntax
}


