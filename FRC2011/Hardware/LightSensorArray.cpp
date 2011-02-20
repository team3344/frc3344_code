
#include "LightSensorArray.h"

LightSensorArray::LightSensorArray(UINT32 leftChannel, UINT32 midChannel, UINT32 rightChannel)
{
	_left = new DigitalInput(leftChannel);
	_mid = new DigitalInput(midChannel);
	_right = new DigitalInput(rightChannel);
}

LightSensorArray::~LightSensorArray()
{
	delete _left;
	delete _mid;
	delete _right;
}

bool LightSensorArray::left()
{
	return _left->Get() == 0;
}

bool LightSensorArray::mid()
{
	return _mid->Get() == 0;
}
bool LightSensorArray::right()
{
	return _right->Get() == 0;
}
	


void LightSensorArray::logInfo()
{
	SmartDashboard::Log(state(), "Light Sensor State");
	SmartDashboard::Log(!(bool)_left->Get(), "Left Light Sensor");
	SmartDashboard::Log(!(bool)_mid->Get(), "Mid Light Sensor");
	SmartDashboard::Log(!(bool)_right->Get(), "Right Light Sensor");
}


LightSensorArray::LightSensorState LightSensorArray::state()
{
	LightSensorState state = (LightSensorState)( ( !(bool)_left->Get() ) || ( !(bool)_mid->Get() << 1 ) || ( !(bool)_right->Get() << 2 ) );
	return state;
}


