
#include "wpilib.h"


#ifndef CLAW_H
#define CLAW_H



class Claw {
public:
	Claw(UINT32 channel);
	~Claw();
	
	//	position
	void open();
	void close();
	
	
private:
	Relay *_relay;
};




#endif //	CLAW_H

