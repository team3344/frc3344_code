
#ifndef DERIVATIZER_H
#define DERIVATIZER_H

#include "wpilib.h"



class Derivatizer {
public:
	Derivatizer();
	~Derivatizer();
	
	void update(double position);
	
	
	double firstDerivative();
	double secondDerivative();
	
private:
	double _previousUpdateTime;
	double _previousPosition;
	double _firstDerivative;
	double _secondDerivative;
};




#endif	//	DERIVATIZER_H

