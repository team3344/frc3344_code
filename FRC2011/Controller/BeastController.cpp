
#include "BeastController.h"



BeastController::BeastController(DriverStation *ds)
{
	_dsIO = ds->GetEnhancedIO();
}

BeastController::setupCypressBoard()
{
	//enum tDigitalConfig {kUnknown, kInputFloating, kInputPullUp
	//	kInputPullDown, kOutput, kPWM, kAnalogComparator};
	//void SetDigitalConfig(UINT32 channel, tDigitalConfig config);
	
	SetDigitalConfig(CYPRESS_DI_PIN_MINIBOT_DEPLOYED, kInputPullDown);	//	pin is off by default
}


BeastController::~BeastController()
{
	//delete _driverStation;	//	FIXME: is this right???  ref counting???
}

float BeastController::getElbowAngle()
{
	//	FIXME: implement
	//
	//double GetAnalogInRatio(UINT32 channel);
}

float BeastController::getShoulderAngle()
{
	//	FIXME: implement
}

bool BeastController::clawClosed()
{
	//	FIXME: implement
}

bool BeastController::minibotDeployed()
{
	
}



