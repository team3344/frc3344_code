
#include "ThreeStateSolenoid.h"

	

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
	_leftSolenoid->Set(false);	//	turn 'em both off so the solenoid holds in the middle position
	_rightSolenoid->Set(false);	//
}

void ThreeStateSolenoid::fireLeft()
{
	_leftSolenoid->Set(true);	//	left = on, right = off
	_rightSolenoid->Set(false);	//
}


void ThreeStateSolenoid::fireRight()
{
	_rightSolenoid->Set(true);	//	right = on, left = off
	_leftSolenoid->Set(false);	//
}


void ThreeStateSolenoid::setState(State s)
{
	if ( s == kLeftState )
		fireLeft();
	else if ( s == kRightState )
		fireRight();
	else
		hold();
}


ThreeStateSolenoid::State ThreeStateSolenoid::getState()
{
	if ( _leftSolenoid->Get() )
		return kLeftState;
	else if ( _rightSolenoid->Get() )
		return kRightState;
	else
		return kHoldState;
}



