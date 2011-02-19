
#ifndef BEAST_CONTROLLER_H
#define BEAST_CONTROLLER_H

#include "wpilib.h"





const UINT32 CYPRESS_AI_PIN_ELBOW_ANGLE = 3;

const UINT32 CYPRESS_DI_PIN_MINIBOT_DEPLOYED = 2;
const UINT32 CYPRESS_DI_PIN_SHOULDER_UP = 1;

const UINT32 CYPRESS_DI_PIN_LEFT_AUTONOMOUS = 6;	//	if it's neither of these, go center
const UINT32 CYPRESS_DI_PIN_RIGHT_AUTONOMOUS = 4;	//
const UINT32 CYPRESS_DI_PIN_RIGHT_FORK = 8;	//	if left is off, go right




const UINT32 kLeftAutonomous 		= 1 << 0;
const UINT32 kRightAutonomous		= 1 << 1;
const UINT32 kStraightAutonomous	= 1 << 2;
const UINT32 kForkedAutonomous		= 1 << 3;

typedef UINT32 AutonomousPosition;




class BeastController {
	
public:
	
	
	BeastController(DriverStation *ds);
	~BeastController();
	
	float getElbowAngle();
	bool getShoulderUp();
	
	bool clawClosed();
	
	AutonomousPosition autonomousPosition();
	
	bool minibotDeployed();
	
	
private:
	void setupCypressBoard();
	bool digitalIn(UINT32 pin);
	
	DriverStation *_ds;
};



#endif	//	BEAST_CONTROLLER_H

