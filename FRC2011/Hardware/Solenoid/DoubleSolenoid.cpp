
#include "DoubleSolenoid.h"

	

DoubleSolenoid::DoubleSolenoid(UINT32 slot, UINT32 leftChannel, UINT32 rightChannel)
{
	_leftSolenoid = new Solenoid(slot, leftChannel);
	_rightSolenoid = new Solenoid(slot, rightChannel);
	
	
}

DoubleSolenoid::~DoubleSolenoid()
{
	delete _leftSolenoid;
	delete _rightSolenoid;
}



// States

void DoubleSolenoid::fireLeft()
{
	_leftSolenoid->Set(true);	//	left = on, right = off
	_rightSolenoid->Set(false);	//
}


void DoubleSolenoid::fireRight()
{
	_rightSolenoid->Set(true);	//	right = on, left = off
	_leftSolenoid->Set(false);	//
}


void DoubleSolenoid::setState(State s)
{
	if ( s == kLeftState )
		fireLeft();
	else
		fireRight();
}


DoubleSolenoid::State DoubleSolenoid::getState()
{
	if ( _leftSolenoid->Get() )
		return kLeftState;
	else
		return kRightState;
}



