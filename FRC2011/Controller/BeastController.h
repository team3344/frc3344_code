
#ifndef BEAST_CONTROLLER_H
#define BEAST_CONTROLLER_H

#include "wpilib.h"





const UINT32 CYPRESS_AI_PIN_ELBOW_ANGLE = 3;

const UINT32 CYPRESS_DI_PIN_MINIBOT_DEPLOYED = 2;
const UINT32 CYPRESS_DI_PIN_SHOULDER_UP = 1;

const UINT32 CYPRESS_DI_PIN_LEFT_AUTONOMOUS = 1;	//	if it's neither of these, go center
const UINT32 CYPRESS_DI_PIN_RIGHT_AUTONOMOUS = 2;	//
const UINT32 CYPRESS_DI_PIN_LEFT_FORK = 1;	//	if left is off, go right


//const float CYPRESS_DIO_VOLTAGE = 3.3;	//	can be 3.3 or 5, depending on the jumpers on the board






class BeastController {
	
public:
	BeastController(DriverStation *ds);
	~BeastController();
	
	float getElbowAngle();
	bool getShoulderUp();
	
	bool clawClosed();
	
	bool minibotDeployed();
	
	
private:
	DriverStationEnhancedIO *_dsIO;
	
};



#endif	//	BEAST_CONTROLLER_H
