
#include "Potentiometer.h"


const float POTENTIOMETER_VOLTAGE_READING_RANGE = 5.0;



Potentiometer::Potentiometer(UINT32 slot, UINT32 channel)
{
	_analogChannel = new AnalogChannel(slot, channel);
	_derivatizer = new Derivatizer();
}

virtual Potentiometer::~Potentiometer()
{
	delete _analogChannel;
}

void Potentiometer::calibrate(double voltage1, double position1, double voltage2, double position2)
{
	_slope = (position2 - position1) / (voltage2 - voltage1);
	_intercept = position1 - (_slope * voltage1);
}

void Potentiometer::update()
{
	_derivatizer->update(currentPosition());
}

double Potentiometer::currentPosition()
{
	return (currentVoltage() * _slope) + _intercept;
}

double Potentiometer::currentVelocity()
{
	
}

double Potentiometer::currentVoltage()
{
	return _analogChannel->GetVoltage();
}


//	PID Source
double Potentiometer::PIDGet()
{
	update(currentPosition);
	
	if ( pidControlType == Potentiometer::kPosition )
		return currentPosition();
	else if ( pidControlType == Potentiometer::kVelocity )
		return _derivatizer->firstDerivative();
	else
		return _derivatizer->secondDerivative();
}


