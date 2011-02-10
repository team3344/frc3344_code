
#ifndef LINE_CONTROLLER_H
#define LINE_CONTROLLER_H


#include "wpilib.h"
#include "Hardware/LightSensorArray.h"
#include "Defines.h"


class LineController {
	
	//	FIXME: CREATE A CONSTRUCTOR!!! - params: lsArray? robot drive???
	
	
	LineController(LightSensorArray *lsArray);
	~LineController();
	
	
	//	line-following speed
	void setSpeed(float speed);
	float speed();
	
	
	
	bool followingLine();
	
	
	
	bool lineIsThick();	//	returns true if all 3 light sensors are "on"
	
	
	//	follow line for distance???
	
	//	follow until thick
		//	follow line until fork???
		//	follow line until T???
	
	//	follow line for time???
	
	
	
	
	
	
	
	
	
private:
	LightSensorArray *_lsArray;
	
	float _followingSpeed;
	
	
};




#endif	//	LINE_CONTROLLER_H

