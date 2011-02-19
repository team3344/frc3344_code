
#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H

#include "wpilib.h"


class Potentiometer : public PIDSource {	//	FIXME: implement SensorBase stuff?!?
public:
	
	Potentiometer(UINT32 slot, UINT32 channel);
	~Potentiometer();
	
	
	void calibrate(float voltage1, float position1, float voltage2, float position2);
	
	
	//bool inverted();
	//void setInverted(bool inverted);	//	inverted = the way the pot is setup, it is full voltage at its min position, and no voltage at its max

	float currentVoltage();
	float currentPosition();
	
	//float positionRange();
	//void setPositionRange(float range);
	
	//float initialPosition();
	//void setInitialPosition(float iPos);
	
	double PIDGet();	//	returns currentPosition()
	
private:
	AnalogChannel *_analogChannel;

	//	parameters for a line that converts voltage to position
	float _slope;
	float _intercept;
	
	
	
	
};


#endif //	POTENTIOMETER_H

