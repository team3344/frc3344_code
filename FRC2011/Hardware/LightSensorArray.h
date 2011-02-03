
#include "wpilib.h"


#ifndef LIGHT_SENSOR_ARRAY_H
#define LIGHT_SENSOR_ARRAY_H



class LightSensorArray {
public:
	LightSensorArray(UINT32 leftChannel, UINT32 midChannel, UINT32 rightChannel);
	~LightSensorArray();
	
	
	enum {
		kLeftOn		= 1 << 0,
		kMidOn		= 1 << 1,
		kRightOn	= 1 << 2
	} LightSensorState;
	
	LightSensorState state();
	
	
private:
	DigitalInput *_left, *_mid, *_right;
	
};


#endif	//	LIGHT_SENSOR_ARRAY_H
