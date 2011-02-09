
#include "wpilib.h"


#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H



class Potentiometer : public PIDSource, public SensorBase {	//	FIXME: implement sensor & pid stuff!!!
public:
	
	
	
	typedef enum {
		kLinearType,
		kLogarithmicType
	} Type;
	
	
	
	Potentiometer(UINT32 slot, UINT32 channel, Type type = kLogarithmicType);
	~Potentiometer();
	
	float currentVoltage();
	float currentPosition();
	
	float positionRange();
	void setPositionRange(float range);
	
	float initialPosition();
	void setInitialPosition(float iPos);
	
	Type type();
	
private:
	AnalogChannel *_analogChannel;
	
	float _positionRange;	//	PI would mean that it can go 1/2 turn
	float _initialPosition;
	Type _type;
};




#endif //	POTENTIOMETER_H

