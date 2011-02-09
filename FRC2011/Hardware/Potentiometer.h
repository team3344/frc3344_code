
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
	
private:
	AnalogChannel *_analogChannel;
	
	float _positionRange;	//	PI would mean that it can go 1/2 turn
};




#endif //	POTENTIOMETER_H

