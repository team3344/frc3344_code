
#include "Potentiometer.h"


const float POTENTIOMETER_VOLTAGE_READING_RANGE = 10;




Potentiometer::Potentiometer(UINT32 slot, UINT32 channel, Type type = kLinearType)
{
	_analogChannel = new AnalogChannel(slot, channel);
}

Potentiometer::~Potentiometer()
{
	delete _analogInput;
}


float Potentiometer::currentVoltage()
{
	return _analogChannel->GetVoltage();
}

float Potentiometer::currentPosition()
{
	//	FIXME: different if logarithmic!!!!!!!!!!!!
	
	
	
	
	
	
	float offset = (abs(currentVoltage()) / POTENTIOMETER_VOLTAGE_READING_RANGE) * _positionRange;
	return pos + _initialPosition;
}


float Potentiometer::positionRange()
{
	return _positionRange;
}

void Potentiometer::setPositionRange(float range)
{
	_positionRange = range;
}


float Potentiometer::voltageRange()
{
	return _voltageRange;
}

void Potentiometer::setVoltageRange(float range)
{
	_voltageRange = range;
}





//	PID Source

double PIDGet()
{
	return currentPosition();
}






