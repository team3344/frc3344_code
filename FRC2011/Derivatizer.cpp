

#include "Derivatizer.h"


Derivatizer::Derivatizer() {}
Derivatizer::~Derivatizer() {}


void Derivatizer::update(double position)
{
	double currentTime = Timer::GetFPGATimestamp();
	double deltaT = currentTime - _previousUpdateTime;
	
	
	double derivative1 = (position - _previousPosition) / deltaT;
	_secondDerivative = (derivative1 - _firstDerivative) / deltaT;
	
	_previousPosition = position;
	_firstDerivative = derivative1;
	_previousUpdateTime = currentTime;
}


double Derivatizer::firstDerivative()
{
	return _firstDerivative;
}

double Derivatizer::secondDerivative()
{
	return _secondDerivative;
}


