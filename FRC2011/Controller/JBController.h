
#ifndef JBCONTROLLER_H
#define JBCONTROLLER_H

#include "wpilib.h"


class JBController {
	
public:
	JBController(DriverStation *ds);
	~JBController();
	
	float getElbowAngle();
	float getShoulderAngle();
	
	bool clawClosed();
	
	
private:
	DriverStation *_driverStation;
	
};



#endif	//	JBCONTROLLER_H

