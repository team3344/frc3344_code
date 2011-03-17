

#include "Arm.h"


Arm::Arm()
{
	_shoulderSolenoid = new DoubleSolenoid(SOLENOID_BREAKOUT_SLOT,
											SHOULDER_SOLENOID_UP_CHANNEL,
											SHOULDER_SOLENOID_DOWN_CHANNEL);

	_elbowPositionSensor = new Potentiometer(ANALOG_BREAKOUT_SLOT, ELBOW_POT_CHANNEL);
	
	//	@v= 5.017, angle= 2.70526 rad
	//	@v= 3.535, angle= .48869 rad
	_elbowPositionSensor->calibrate(5.017, 2.70526,
										3.535, .48869);
	

	_elbowController = new Victor(SIDECAR_SLOT, ELBOW_CONTROLLER_CHANNEL);

	//	source = pot, output = victor
	_elbowPIDController = new PIDController(ELBOW_PID_P, ELBOW_PID_I, ELBOW_PID_D, _elbowPositionSensor, _elbowController);
	_elbowPIDController->SetInputRange(ELBOW_MIN_ANGLE, ELBOW_MAX_ANGLE);
	_elbowPIDController->SetOutputRange(-ELBOW_MAX_POWER, ELBOW_MAX_POWER);
}

Arm::~Arm()
{
	delete _shoulderSolenoid;
}


void Arm::logInfo()
{
	SmartDashboard::Log(_elbowPositionSensor->currentVoltage(), "Elbow Pot Current Voltage");
	SmartDashboard::Log(_elbowPositionSensor->currentPosition(), "ELbow Pot Current Position (rads)");	
}


float Arm::shoulderAngle()
{
	if ( _shoulderSolenoid->Get() == DoubleSolenoid::kForward )
		return SHOULDER_MAX_ANGLE;
	else
		return SHOULDER_MIN_ANGLE;
}

float Arm::elbowAngle()
{
	return _elbowPositionSensor->currentPosition();
}

float Arm::absoluteElbowAngle()
{
	return shoulderAngle() + elbowAngle();
}

/*
//	shoulder adjustment
void Arm::holdShoulder()
{
	
}*/

void Arm::raiseShoulder()
{
	_shoulderSolenoid->Set(DoubleSolenoid::kForward);
}

void Arm::lowerShoulder()
{
	_shoulderSolenoid->Set(DoubleSolenoid::kReverse);
}


/*
//	elbow adjustment
void Arm::holdElbow()
{
	
}
void Arm::raiseElbow()
{
	
}
void Arm::lowerElbow()
{
	
}
*/



void Arm::setElbowAngle(float angle)
{
	if ( angle > ELBOW_MAX_ANGLE )
		_elbowTarget = ELBOW_MAX_ANGLE;
	else if ( angle < ELBOW_MIN_ANGLE )
		_elbowTarget = ELBOW_MIN_ANGLE;
	else
		_elbowTarget = angle;

	//	set PID
	_elbowPIDController->SetSetpoint(_elbowTarget);
}

double Arm::recommendedElbowPowerForDirection(int direction)
{
	double multiplier = ELBOW_MAX_POWER - ELBOW_MIN_POWER;
	double upPower = ELBOW_MIN_POWER + (ELBOW_MAX_POWER * cos(absoluteElbowAngle()));
	
	return ( direction == 1 ) ? upPower : ELBOW_MAX_POWER - upPower;
}


bool Arm::positionOutOfRangeForElbow(float position)
{
	return position > ELBOW_MAX_ANGLE || position < ELBOW_MIN_ANGLE;
}

float Arm::restrictedElbowPosition(float position)
{
	if ( position > ELBOW_MAX_ANGLE )
		return ELBOW_MAX_ANGLE;
	else if ( position < ELBOW_MIN_ANGLE )
		return ELBOW_MIN_ANGLE;
	else
		return position;
}



/*
/*	Arm protection - keeps joints from over-extending	*/
/*
void Arm::protectArm()
{
	while ( true )
	{
		//	if elbow at end of range & trying to go further, stop!!!
	}
}


void Arm::InitArmProtector()
{
	//_armProtector = new Task("Arm Protector", &Arm::protectArm);	//	FIXME: is this legit syntax
}*/


