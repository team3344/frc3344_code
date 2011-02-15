
#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H

#include "wpilib.h"


class Potentiometer : public PIDSource {	//	FIXME: implement SensorBase stuff?!?
public:
	
	Potentiometer(UINT32 slot, UINT32 channel);
	~Potentiometer();
	
	bool inverted();
	void setInverted(bool inverted);	//	inverted = the way the pot is setup, it is full voltage at its min position, and no voltage at its max

	float currentVoltage();
	float currentPosition();
	
	float positionRange();
	void setPositionRange(float range);
	
	float initialPosition();
	void setInitialPosition(float iPos);
	
	double PIDGet();	//	returns currentPosition()
	
private:
	AnalogChannel *_analogChannel;
	
	bool _inverted;

	float _positionRange;	//	PI would mean that it can go 1/2 turn
	float _initialPosition;
};


#endif //	POTENTIOMETER_H

