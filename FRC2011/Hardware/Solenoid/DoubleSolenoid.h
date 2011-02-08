
#include "wpilib.h"


#ifndef DOUBLE_SOLENOID_H
#define DOUBLE_SOLENOID_H



class DoubleSolenoid {

public:
	typedef enum {
		kLeftState,
		kRightState
	} State;
	

	DoubleSolenoid(UINT32 slot, UINT32 leftChannel, UINT32 rightChannel);
	~DoubleSolenoid();
	
	
	void fireLeft();
	void fireRight();
	void setState(State s);
	State getState();
	
	
	
	
private:
	Solenoid *_leftSolenoid;
	Solenoid *_rightSolenoid;
	
};




#endif //	DOUBLE_SOLENOID_H

