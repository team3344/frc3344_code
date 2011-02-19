
#include "Potentiometer.h"


const float POTENTIOMETER_VOLTAGE_READING_RANGE = 5.0;



Potentiometer::Potentiometer(UINT32 slot, UINT32 channel)
{
	_analogChannel = new AnalogChannel(slot, channel);
}

Potentiometer::~Potentiometer()
{
	delete _analogChannel;
}

void Potentiometer::calibrate(float voltage1, float position1, float voltage2, float position2)
{
	_slope = (position2 - position1) / (voltage2 - voltage1);
	_intercept = position1 - (_slope * voltage1);
}


float Potentiometer::currentPosition()
{
	return (currentVoltage() * _slope) + _intercept;
}


float Potentiometer::currentVoltage()
{
	return _analogChannel->GetVoltage();
}


//	PID Source
double Potentiometer::PIDGet()
{
	return (double)currentPosition();
}


