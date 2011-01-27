
#include "ThreeStateSolenoid.h"


	void setState(State s);
	State getState();
	

ThreeStateSolenoid::ThreeStateSolenoid(UINT32 slot, UINT32 leftChannel, UINT32 rightChannel)
{
	_leftSolenoid = new Solenoid(slot, leftChannel);
	_rightSolenoid = new Solenoid(slot, rightChannel);
	
	
}

ThreeStateSolenoid::~ThreeStateSolenoid()
{
	delete _leftSolenoid;
	delete _rightSolenoid;
}



// States

void ThreeStateSolenoid::hold()
{
	
}

void ThreeStateSolenoid::fireLeft()
{
	
	
}


ThreeStateSolenoid::fireRight()
{
	
}



