
#include "BeastController.h"



BeastController::BeastController(DriverStation *ds)
{
	_ds = ds;
}

void BeastController::setupCypressBoard()
{
	//enum tDigitalConfig {kUnknown, kInputFloating, kInputPullUp
	//	kInputPullDown, kOutput, kPWM, kAnalogComparator};
	//void SetDigitalConfig(UINT32 channel, tDigitalConfig config);
	
	
	
	_ds->GetEnhancedIO().SetDigitalConfig(CYPRESS_DI_PIN_MINIBOT_DEPLOYED,
											DriverStationEnhancedIO::kInputPullDown);
	
	
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

bool BeastController::getShoulderUp()
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



