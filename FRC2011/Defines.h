

#ifndef DEFINES_H
#define DEFINES_H

#include "wpilib.h"
#include <math.h>


const double PI = 3.14159265358979323846;


//	FIXME: fix these!
const UINT32 SOLENOID_BREAKOUT_SLOT = 8;
const UINT32 ANALOG_BREAKOUT_SLOT = 6;
const UINT32 SIDECAR_SLOT = 4;



//	drive speeds
const float DRIVE_SPEED_HIGH = 1;
const float DRIVE_SPEED_MID = .45;
const float DRIVE_SPEED_LOW = .27;



//	light sensors	//	FIXME: GET THE REAL VALUES FOR THESE
const UINT32 LIGHT_SENSOR_LEFT_PORT = 1;
const UINT32 LIGHT_SENSOR_MID_PORT = 2;
const UINT32 LIGHT_SENSOR_RIGHT_PORT = 3;

const float LIGHT_SENSOR_DISTANCE_FROM_CENTER = 20;	//	FIXME: fix
const float LIGHT_SENSOR_SPACING = 1.5;	//	FIXME: fix


const UINT32 PRESSURE_SWITCH_CHANNEL = 5;
const UINT32 COMPRESSOR_RELAY_CHANNEL = 1;


const UINT32 CLAW_RELAY_CHANNEL = 2;


//	arm
const UINT32 ELBOW_POT_CHANNEL = 1;
const UINT32 ELBOW_CONTROLLER_CHANNEL = 5;	//	FIXME: Channel for the victor - connected by Y cable

const float ELBOW_MAX_POWER = .4;

const float ELBOW_PID_P = 1;	//	FIXME: htf do u tune these??
const float ELBOW_PID_I = 0;
const float ELBOW_PID_D = 0;



const UINT32 SHOULDER_SOLENOID_UP_CHANNEL = 2;	//	not 1
const UINT32 SHOULDER_SOLENOID_DOWN_CHANNEL = 3;



#endif //	DEFINES_H



