
#include "JBController.h"



JBController::JBController(DriverStation *ds)
{
	_driverStation = ds;
}

JBController::~JBController()
{
	//delete _driverStation;	//	FIXME: is this right???  ref counting???
}

float JBController::getElbowAngle()
{
	//	FIXME: implement
}

float JBController::getShoulderAngle()
{
	//	FIXME: implement
}

bool JBController::clawClosed()
{
	//	FIXME: implement
}

