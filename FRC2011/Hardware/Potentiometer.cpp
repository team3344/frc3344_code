
#include "Potentiometer.h"


const float POTENTIOMETER_VOLTAGE_READING_RANGE = 10;




Potentiometer::Potentiometer(UINT32 slot, UINT32 channel)
{
	_analogChannel = new AnalogChannel(slot, channel);
}

Potentiometer::~Potentiometer()
{
	delete _analogChannel;
}


float Potentiometer::currentVoltage()
{
	return _analogChannel->GetVoltage();
}

float Potentiometer::currentPosition()
{
#warning do abs(currentVoltage())
	float offset = (currentVoltage() / POTENTIOMETER_VOLTAGE_READING_RANGE) * _positionRange;
	return offset + _initialPosition;
}


float Potentiometer::positionRange()
{
	return _positionRange;
}

void Potentiometer::setPositionRange(float range)
{
	_positionRange = range;
}

/*
float Potentiometer::voltageRange()
{
	return _voltageRange;
}

void Potentiometer::setVoltageRange(float range)
{
	_voltageRange = range;
}
*/



//	PID Source
/*
double PIDGet()
{
	return currentPosition();
}
*/
#warning implement pid source

