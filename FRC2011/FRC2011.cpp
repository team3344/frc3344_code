
#include "wpilib.h"
#include "Hardware/Arm.h"
#include "Hardware/Claw.h"
#include "Hardware/LightSensorArray.h"
#include "Defines.h"
#include "Controller/Gamepad.h"
#include "Controller/JBController.h"


#define LOGITECH_CONTROLLER
#define JB_CONTROLLER


class FRC2011 : public IterativeRobot
{
	RobotDrive *_robotDrive;	//	FIXME: make this a SafeDrive?
	Arm *_arm;
	Claw *_claw;
	
	LightSensorArray *_lightSensors;

	DriverStation *_driverStation;
	
	Compressor *_compressor;

	
#ifdef JB_CONTROLLER
	JBController *_jbController;
#endif
	
	

#ifdef LOGITECH_CONTROLLER
	Gamepad *_gamepad;
#else
	Joystick *_joystick;
#endif
	
	
public:

	FRC2011()
	{
		// standard right/left robot drive on PWMS 1, 2, 3, and 4
		_robotDrive = new RobotDrive(1, 2, 3, 4);
		
		
		//	FIXME: remove this
		//Victor *v = new Victor(SIDECAR_SLOT, 5);
		//v->Set(.1);
		
		
		
		//_arm = new Arm();
		
		
		
		
		
		
		_claw = new Claw(CLAW_RELAY_CHANNEL);
		
		

		// Acquire the Driver Station object
		_driverStation = DriverStation::GetInstance();

#ifdef LOGITECH_CONTROLLER
		_gamepad = new Gamepad(1);
#else
		// Define joystick being used at USB port #1 on the Drivers Station
		_joystick = new Joystick(1);
#endif
		
		
#ifdef JB_CONTROLLER
		_jbController = new JBController(_driverStation);
#endif
		
		//	initialize the SmartDashboard
		SmartDashboard::init();


		//	initialize the light sensor array
		_lightSensors = new LightSensorArray(LIGHT_SENSOR_LEFT_PORT, LIGHT_SENSOR_MID_PORT, LIGHT_SENSOR_RIGHT_PORT);	//	FIXME: is this the right syntax for a static object???
		

		//	init and start compressor
		_compressor = new Compressor(SIDECAR_SLOT, PRESSURE_SWITCH_CHANNEL, SIDECAR_SLOT, COMPRESSOR_RELAY_CHANNEL);
		_compressor->Start();
	}
	
	
	
	
	void LogToDashboard()
	{
		//	relay ports
		
		
		
		SmartDashboard::Log("hello world", "try1");
		
		SmartDashboard::Log(throttle(), "Throttle");
		
		
		
		_arm->logInfo();
		
		
		
		//	power sent to motors
		
		
		
		
		
		//	light sensors
		

		//	arm position
		
		//	camera image
		
		//	pressure of storage tanks
		
		//	
		
		
		
		_gamepad->logButtons();
		
	}
	
	
	
	
	/********************************** Init Routines *************************************/

	void RobotInit(void) {
		// Actions which would be performed once (and only once) upon initialization of the
		// robot would be put here.
		
		//	FIXME: calibrate stuff???

		printf("RobotInit() completed.\n");
	}
	
	/*
	void DisabledInit(void) {
		// Move the cursor down a few, since we'll move it back up in periodic.
		printf("\x1b[2B");
	}*/
	
	void AutonomousInit(void)
	{
		
	}
	/*
	void TeleopInit(void) {

	}*/

	/********************************** Periodic Routines *************************************/
	
	void DisabledPeriodic(void)
	{
		static INT32 printSec = (INT32)GetClock() + 1;
		static const INT32 startSec = (INT32)GetClock();

		
		// while disabled, printout the duration of current disabled mode in seconds
		if (GetClock() > printSec) {
			// Move the cursor back to the previous line and clear it.
			printf("\x1b[1A\x1b[2K");
			printf("Disabled seconds: %d\r\n", printSec - startSec);			
			printSec++;
		}
	}

	void AutonomousPeriodic(void) {
		
		LogToDashboard();
	}
	
	
	float throttle()
	{
#ifdef LOGITECH_CONTROLLER
		float throttle;
		
		if ( _gamepad->GetButton(Gamepad::kRightTopTrigger) )
		{
			throttle = DRIVE_SPEED_HIGH;
		}
		else if ( _gamepad->GetButton(Gamepad::kLeftTopTrigger) )
		{
			throttle = DRIVE_SPEED_LOW;
		}
		else
		{
			throttle = DRIVE_SPEED_MID;
		}
		
#else
		float throttle = _joystick->GetThrottle();	//	-1 to 1
		throttle -= 1;	//	0 to -2
		throttle /= -2;	//	0 to 1 - note that this is backwards from the default setup
#endif
		
		return throttle;
	}
	
	void TeleopPeriodic(void)
	{
		_robotDrive->SetMaxOutput(throttle());

#ifdef LOGITECH_CONTROLLER
		_robotDrive->TankDrive(_gamepad->GetLeftY(), _gamepad->GetRightY());
#else
		_robotDrive->ArcadeDrive(_joystick);			// drive with arcade style (use right stick)
#endif
		
		LogToDashboard();
		
		
		//_arm->raiseShoulder();
		
		
		//	arm
		/*
		if ( _gamepad->GetButton(Gamepad::kBottomButton) )
		{
			_arm->lowerShoulder();
		}
		else if ( _gamepad->GetButton(Gamepad::kTopButton) )
		{
			_arm->raiseShoulder();
		}
		*/
		
		
		//	claw
		if ( _gamepad->GetButton(Gamepad::kRightTopTrigger) )
		{
			_claw->open();
		}
		else
		{
			_claw->close();
		}
		
		
		
		
		
		/*	TEMPORARY ELBOW STUFF	*/
		
		Gamepad::DPadDirection dPad = _gamepad->GetDPad();
		
		if ( dPad == Gamepad::kUp )
		{
			_arm->_elbowController->Set(ELBOW_MAX_POWER);	//	up
		}
		else if ( dPad == Gamepad::kDown )
		{
			_arm->_elbowController->Set(-ELBOW_MAX_POWER);	//	down
		}
		else
		{
			_arm->_elbowController->Set(0);	//	turn it off
		}
		
		/*	TEMPORARY ELBOW STUFF	*/
		
		
		
	} // TeleopPeriodic(void)
			
};

START_ROBOT_CLASS(FRC2011);
