
#ifndef ROLLER_GRIP_H
#define ROLLER_GRIP_H

#include "wpilib.h"
#include "../Defines.h"



class RollerGrip {
public:
	RollerGrip(UINT32 topLeftChannel, UINT32 topRightChannel,
				UINT32 bottomLeftChannel, UINT32 bottomRightChannel);
	
	~RollerGrip();
	
	
	typedef enum {
		kIn 	= 10,
		kOut	= 170,
		kOff	= 90
	} RollerDirection;
	
	
	void setTopRollerDirection(RollerDirection d);
	void setBottomRollerDirection(RollerDirection d);
	
	
	void intake();
	void rotateUp();
	void rotateDown();
	void release();
	void disable();
	
	
private:
	Servo *topLeft, *topRight, *bottomLeft, *bottomRight;
};


#endif	//	ROLLER_GRIP_H
