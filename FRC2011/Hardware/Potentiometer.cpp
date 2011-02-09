
#include "Potentiometer.h"


Potentiometer(UINT32 slot, UINT32 channel)
{
	_analogChannel = new AnalogChannel(slot, channel);
}

~Potentiometer()
{
	delete _analogInput;
}


float currentVoltage()
{
	return _analogChannel->GetVoltage();
}

float currentPosition()
{
	float pos = (currentVoltage() / _voltageRange) * _positionRange;
	return pos;
}


float positionRange()
{
	return _positionRange;
}

void setPositionRange(float range)
{
	_positionRange = range;
}


float voltageRange()
{
	return _voltageRange;
}

void setVoltageRange(float range)
{
	_voltageRange = range;
}


