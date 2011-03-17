	
#include "RollerGrip.h"

#define SERVO_MAX_ANGLE 180

RollerGrip::RollerGrip(UINT32 topLeftChannel, UINT32 topRightChannel,
					UINT32 bottomLeftChannel, UINT32 bottomRightChannel)
{
	topLeft = new Servo(SIDECAR_SLOT, topLeftChannel);
	topRight = new Servo(SIDECAR_SLOT, topRightChannel);
	bottomLeft = new Servo(SIDECAR_SLOT, bottomLeftChannel);
	bottomRight = new Servo(SIDECAR_SLOT, bottomRightChannel);
}
		
RollerGrip::~RollerGrip()
{
	delete topLeft;
	delete topRight;
	delete bottomLeft;
	delete bottomRight;
}
		


void RollerGrip::setTopRollerDirection(RollerDirection d)
{
	topLeft->SetAngle(SERVO_MAX_ANGLE - d);
	topRight->SetAngle(d);
}

void RollerGrip::setBottomRollerDirection(RollerDirection d)
{
	bottomLeft->SetAngle(d);
	bottomRight->SetAngle(SERVO_MAX_ANGLE - d);
}

		
void RollerGrip::intake()
{
	setTopRollerDirection(kIn);
	setBottomRollerDirection(kIn);
}
void RollerGrip::rotateUp()
{
	setTopRollerDirection(kIn);
	setBottomRollerDirection(kOut);
}
void RollerGrip::rotateDown()
{
	setTopRollerDirection(kOut);
	setBottomRollerDirection(kIn);
}
void RollerGrip::release()
{
	setTopRollerDirection(kOut);
	setBottomRollerDirection(kOut);
}
void RollerGrip::disable()
{
	setTopRollerDirection(kOff);
	setBottomRollerDirection(kOff);
}
