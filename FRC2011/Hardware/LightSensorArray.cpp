
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


LightSensorState LightSensorArray::state()
{
	LightSensorState state = ( _left->Get() ) || ( _mid->Get() << 1 ) || ( _right->Get() << 2 );
	return state;
}








