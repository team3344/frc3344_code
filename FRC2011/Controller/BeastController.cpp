
#include "BeastController.h"



BeastController::BeastController(DriverStation *ds)
{
	_ds = ds;
	//setupCypressBoard();
}

/*
void BeastController::setupCypressBoard()
{
	//	set all digital input pins to pull-down
	for ( UINT16 i = 1; i < 8; i++ )
	{
		_ds->GetEnhancedIO().SetDigitalConfig(i, DriverStationEnhancedIO::kInputPullDown);
	}
	
}*/


BeastController::~BeastController()
{
	//delete _driverStation;	//	FIXME: is this right???  ref counting???
}

float BeastController::getElbowAngle()
{
	return 0;
	//	FIXME: implement
	//
	//double GetAnalogInRatio(UINT32 channel);
}

bool BeastController::getShoulderUp()
{
	//	FIXME: implement
	return false;
}

bool BeastController::clawClosed()
{
	//	FIXME: implement
	return false;
}

bool BeastController::minibotDeployed()
{
	return digitalIn(CYPRESS_DI_PIN_MINIBOT_DEPLOYED);
}

bool BeastController::digitalIn(UINT32 pin)
{
	return _ds->GetDigitalIn(pin);
}

AutonomousPosition BeastController::autonomousPosition()
{
	AutonomousPosition pos = 0;
	
	if ( digitalIn(CYPRESS_DI_PIN_LEFT_AUTONOMOUS) ||
			!digitalIn(CYPRESS_DI_PIN_RIGHT_FORK) )
	{
		pos = kLeftAutonomous;
	}
	else
	{
		pos = kRightAutonomous;
	}
	
	if ( !digitalIn(CYPRESS_DI_PIN_LEFT_AUTONOMOUS) &&
			!digitalIn(CYPRESS_DI_PIN_RIGHT_AUTONOMOUS) )
	{
		pos |= kForkedAutonomous;
	}
	else
	{
		pos |= kStraightAutonomous;
	}
	
	return pos;
}


