
#include "Claw.h"
#include "../Defines.h"


Claw::Claw(UINT32 solenoidChannel)
{
	_solenoid = new Solenoid(SOLENOID_BREAKOUT_SLOT, solenoidChannel);
}

Claw::~Claw()
{
	delete _solenoid;
}

void Claw::open()
{
	_solenoid->Set(false);
}

void Claw::close()
{
	_solenoid->Set(true);
}

