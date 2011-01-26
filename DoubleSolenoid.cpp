#include "DoubleSolenoid.h"

/**
 * Constructs an instance of the DoubleSolenoid class.
 * Passes the channels to the two member solenoid object constructors.
 * 
 * @param aChannel The port of the first side of the double solenoid
 * @param bChannel The port of the second side of the double solenoid
 */
DoubleSolenoid::DoubleSolenoid(UINT32 aChannel, UINT32 bChannel)
{
	aSolenoid = new Solenoid(aChannel);
	bSolenoid = new Solenoid(bChannel);
}

/**
 * Constructs an instance of the DoubleSolenoid class.
 * Passes the channels and slots to the two member solenoid object constructors.
 *
 * @param aChannel The slot of the first side of the double solenoid
 * @param aChannel The port of the first side of the double solenoid
 * @param bChannel The slot of the second side of the double solenoid
 * @param bChannel The port of the second side of the double solenoid
 */
DoubleSolenoid::DoubleSolenoid(UINT32 aSlot, UINT32 aChannel, UINT32 bSlot, UINT32 bChannel)
{
	aSolenoid = new Solenoid(aSlot, aChannel);
	bSolenoid = new Solenoid(bSlot, bChannel);
}

/**
 * Cleans up the two solenoid member objects.
 */
DoubleSolenoid::~DoubleSolenoid()
{
	delete aSolenoid;
	delete bSolenoid;
}

/**
 * Forwards the set request to the solenoid member objects.
 * 
 * @param state The state to set the double solenoid to
 */
void DoubleSolenoid::Set(DoubleSolenoidState state)
{
	switch (state)
	{
		case kOnA:
			aSolenoid->Set(true);
			bSolenoid->Set(false);
			break;
		case kOnB:
			aSolenoid->Set(false);
			bSolenoid->Set(true);
			break;
		default:
			aSolenoid->Set(false);
			bSolenoid->Set(false);
	}
}

/**
 * Retrieves the state of the double solenoid.
 */
DoubleSolenoid::DoubleSolenoidState DoubleSolenoid::Get()
{
	if (aSolenoid->Get())
		return kOnA;
	if (bSolenoid->Get())
		return kOnB;
	return kOff;
}
