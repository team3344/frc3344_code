
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



