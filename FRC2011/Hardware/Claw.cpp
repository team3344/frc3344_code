
#include "Claw.h"
#include "../Defines.h"


Claw::Claw(UINT32 channel)
{
	_relay = new Relay(SIDECAR_SLOT, channel);
}

Claw::~Claw()
{
	delete _relay;
}

void Claw::open()
{
	_relay->Set(Relay::kForward);
}

void Claw::close()
{
	_relay->Set(Relay::kOff);
}

