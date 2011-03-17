
#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H

#include "wpilib.h"
#include "../Derivatizer.h"


class Potentiometer : public PIDSource {	//	FIXME: implement SensorBase stuff?!?
public:
	Potentiometer(UINT32 slot, UINT32 channel);
	 virtual ~Potentiometer();
	
	
	void calibrate(double voltage1, double position1, double voltage2, double position2);
	void update();	//	tells it to calculate derivatives
	
	double currentVoltage();
	double currentPosition();
	double currentVelocity();
	double currentAcceleration();
	
	
	typedef enum {
		kPosition,
		kVelocity,
		kAcceleration
	} ControlType;
	
	ControlType pidControlType;	//	set this to control what PIDGet returns
	
	double PIDGet();
	
private:
	AnalogChannel *_analogChannel;

	//	parameters for a line that converts voltage to position
	double _slope;
	double _intercept;
	
	Derivatizer *_derivatizer;
};


#endif //	POTENTIOMETER_H

