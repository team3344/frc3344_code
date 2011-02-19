
#include "BeastController.h"



BeastController::BeastController(DriverStation *ds)
{
	_ds = ds;
	setupCypressBoard();
}

void BeastController::setupCypressBoard()
{
	//enum tDigitalConfig {kUnknown, kInputFloating, kInputPullUp
	//	kInputPullDown, kOutput, kPWM, kAnalogComparator};
	//void SetDigitalConfig(UINT32 channel, tDigitalConfig config);
	
	//	set all digital input pins to pull-down
	for ( UINT16 i = 1; i < 8; i++ )
	{
		_ds->GetEnhancedIO().SetDigitalConfig(i, DriverStationEnhancedIO::kInputPullDown);
	}
	
}


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
	return _ds->GetEnhancedIO().GetDigital(pin);
}

BeastController::AutonomousPosition BeastController::autonomousPosition()
{
	if ( digitalIn(CYPRESS_DI_PIN_LEFT_AUTONOMOUS) )
		return BeastController::kLeftAutonomousPosition;
	else if ( digitalIn(CYPRESS_DI_PIN_RIGHT_AUTONOMOUS) )
		return BeastController::kRightAutonomousPosition;
	else if ( digitalIn(CYPRESS_DI_PIN_RIGHT_FORK) )
		return BeastController::kCenterForkRightAutonomousPosition;
	else
		return BeastController::kCenterForkLeftAutonomousPosition;
}


