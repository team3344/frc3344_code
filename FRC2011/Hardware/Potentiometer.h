
#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H

#include "wpilib.h"



/*
 * PIDGet() returns the current position.
 */

class Potentiometer : public PIDSource, public SensorBase {	//	FIXME: implement sensor & pid stuff!!!
public:
	
	Potentiometer(UINT32 slot, UINT32 channel);
	~Potentiometer();
	
	float currentVoltage();
	float currentPosition();
	
	float positionRange();
	void setPositionRange(float range);
	
	float initialPosition();
	void setInitialPosition(float iPos);
	
	double PIDGet();	//	returns currentPosition()
	
private:
	AnalogChannel *_analogChannel;
	
	float _positionRange;	//	PI would mean that it can go 1/2 turn
	float _initialPosition;
};



#endif //	POTENTIOMETER_H

