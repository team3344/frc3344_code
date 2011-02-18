
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

bool Potentiometer::inverted()
{
	return _inverted;
}

float Potentiometer::initialPosition()
{
	return _initialPosition;
}

void Potentiometer::setInverted(bool inverted)
{
	_inverted = inverted;
}


float Potentiometer::currentVoltage()
{
	return _analogChannel->GetVoltage();
}

float Potentiometer::currentPosition()
{
	float voltage = currentVoltage();
	if ( voltage < 0 ) voltage *= -1;	//	make voltage positive

	float portion = voltage / POTENTIOMETER_VOLTAGE_READING_RANGE;
	if (_inverted) portion = 1 - portion;
	float offset = portion * _positionRange;

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
double Potentiometer::PIDGet()
{
	return (double)currentPosition();
}


