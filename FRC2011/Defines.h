

#ifndef DEFINES_H
#define DEFINES_H

#include "wpilib.h"
#include <math.h>


#define SIGN(x) ( (x < 0) ? -1 : 1 )

const double PI = 3.14159265358979323846;



const UINT32 SOLENOID_BREAKOUT_SLOT = 8;
const UINT32 ANALOG_BREAKOUT_SLOT = 1;
const UINT32 SIDECAR_SLOT = 4;



//	drive speeds
const float DRIVE_SPEED_HIGH = 1;
const float DRIVE_SPEED_MID = .65;
const float DRIVE_SPEED_LOW = .27;



//	light sensors
const UINT32 LIGHT_SENSOR_LEFT_PORT = 1;
const UINT32 LIGHT_SENSOR_MID_PORT = 2;
const UINT32 LIGHT_SENSOR_RIGHT_PORT = 3;


const UINT32 PRESSURE_SWITCH_CHANNEL = 5;
const UINT32 COMPRESSOR_RELAY_CHANNEL = 1;


const UINT32 CLAW_RELAY_CHANNEL = 2;


//	arm
const UINT32 ELBOW_POT_CHANNEL = 2;
const UINT32 ELBOW_CONTROLLER_CHANNEL = 5;

const float ELBOW_MAX_POWER = .5;
const float ELBOW_MIN_POWER = .05;

const float ELBOW_PID_P = 1;	//	FIXME: htf do u tune these??
const float ELBOW_PID_I = 0;
const float ELBOW_PID_D = 0;



const UINT32 SHOULDER_SOLENOID_UP_CHANNEL = 1;
const UINT32 SHOULDER_SOLENOID_DOWN_CHANNEL = 2;



const UINT32 MINIBOT_IN_SOLENOID = 3;
const UINT32 MINIBOT_OUT_SOLENOID = 4;




#endif //	DEFINES_H



