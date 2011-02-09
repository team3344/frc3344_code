
#include "wpilib.h"


#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H



class Potentiometer : public PIDSource, public SensorBase {	//	FIXME: implement sensor & pid stuff!!!
public:
	Potentiometer(UINT32 slot, UINT32 channel);
	~Potentiometer();
	
	
	float currentVoltage();
	float currentPosition();
	
	
	
	float positionRange();
	void setPositionRange(float range);
	
	float voltageRange();
	void setVoltageRange(float range);
	
	
private:
	AnalogChannel *_analogChannel;
	
	//	pot parameters
	float _positionRange;	//	PI would mean that it can go 1/2 turn
	float _voltageRange;	//	5 means it at the max position, we get a reading of 5v
};




#endif //	POTENTIOMETER_H

