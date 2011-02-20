
#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H

#include "wpilib.h"


class Potentiometer : public PIDSource {	//	FIXME: implement SensorBase stuff?!?
public:
	
	Potentiometer(UINT32 slot, UINT32 channel);
	~Potentiometer();
	
	
	void calibrate(float voltage1, float position1, float voltage2, float position2);
	
	
	float currentVoltage();
	float currentPosition();
	
	
	double PIDGet();	//	returns currentPosition()
	
private:
	AnalogChannel *_analogChannel;

	//	parameters for a line that converts voltage to position
	float _slope;
	float _intercept;
	
	
	
	
};


#endif //	POTENTIOMETER_H

