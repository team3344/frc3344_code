
#include "wpilib.h"


#ifndef THREE_STATE_SOLENOID_H
#define THREE_STATE_SOLENOID_H



class ThreeStateSolenoid {

public:
	typedef enum {
		kLeftState,
		kRightState,
		kHoldState
	} State;
	

	ThreeStateSolenoid(UINT32 slot, UINT32 leftChannel, UINT32 rightChannel);
	~ThreeStateSolenoid();
	
	
	void hold();
	void fireLeft();
	void fireRight();
	void setState(State s);
	State getState();
	
	
	
	
private:
	Solenoid *_leftSolenoid;
	Solenoid *_rightSolenoid;
	
};




#endif //	THREE_STATE_SOLENOID_H

