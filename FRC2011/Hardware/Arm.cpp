

#include "Arm.h"


Arm::Arm()
{
	_shoulderSolenoid = new DoubleSolenoid(SHOULDER_SOLENOID_UP_CHANNEL, SHOULDER_SOLENOID_UP_CHANNEL);

	_elbowPositionSensor = new Potentiometer(ANALOG_BREAKOUT_SLOT, ELBOW_POT_CHANNEL);
	//	FIXME: set parameters on the pot

	_elbowController = new Victor(ELBOW_CONTROLLER_CHANNEL);

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
	SmartDashboard::Log(_elbowPositionSensor->initialPosition(), "Elbow Pot Initial Position (rads)");
	SmartDashboard::Log(_elbowPositionSensor->positionRange(), "Elbow Pot Position Range (rads)");
	SmartDashboard::Log(_elbowPositionSensor->currentVoltage(), "Elbow Pot Current Voltage");
	SmartDashboard::Log(_elbowPositionSensor->currentPosition(), "ELbow Pot Current Position (rads)");
	SmartDashboard::Log(_elbowPositionSensor->inverted(), "Elbow Pot Inverted?");	
}


float Arm::shoulderAngle()
{
	return 1;	//	FIXME: ;asdkfj;asdjf;sdjkf
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


