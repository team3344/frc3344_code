
#include "wpilib.h"


#ifndef CLAW_H
#define CLAW_H



class Claw {
public:
	Claw(UINT32 solenoidChannel);
	~Claw();
	
	//	position
	void open();
	void close();
	
	
private:
	Solenoid *_solenoid;
};




#endif //	CLAW_H

