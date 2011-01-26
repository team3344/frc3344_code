#ifndef DOUBLE_SOLENOID_H_
#define DOUBLE_SOLENOID_H_

#include "Solenoid.h"

/**
 * Wraps two Solenoid objects into a single class for double solenoids.
 */
class DoubleSolenoid
{
public:
	typedef enum { kOnA, kOnB, kOff } DoubleSolenoidState;
	DoubleSolenoid(UINT32 aChannel, UINT32 bChannel);
	DoubleSolenoid(UINT32 aSlot, UINT32 aChannel, UINT32 bSlot, UINT32 bChannel);
	~DoubleSolenoid();
	void Set(DoubleSolenoidState state);
	DoubleSolenoidState Get();

private:
	Solenoid *aSolenoid;
	Solenoid *bSolenoid;
};

#endif
