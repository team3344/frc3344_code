
#include "wpilib.h"
#include "Hardware/Arm.h"
#include "Hardware/RollerGrip.h"
#include "Hardware/LightSensorArray.h"
#include "Defines.h"
#include "Controller/Gamepad.h"
#include "Controller/BeastController.h"


#define LOGITECH_CONTROLLER




/*****	Autonomous Power Profiles	*****/
//double forkProfile[] = {.7, .7, .55, .6, .6, .5, .4, 0.0};
//double straightProfile[] = {.65, .6, .6, .6, .35, .35, .35, 0.0};



class FRC2011 : public IterativeRobot
{
	RobotDrive *_robotDrive;	//	FIXME: make this a SafeDrive?
	Arm *_arm;
	RollerGrip *_rollerGrip;
	
	LightSensorArray *_lightSensors;

	DriverStation *_driverStation;
	
	Compressor *_compressor;

	
	DoubleSolenoid *_minibotDeployerSolenoid;
	
	

	/*****	Controllers	*****/
	Gamepad *_driverGamepad;
	Gamepad *_armGamepad;

	BeastController *_beastController;

	Joystick *_armJoystick;
	


	/*****	Autonomous	*****/

	//Task _autonomousTask;



public:

	FRC2011()
	{
		// standard right/left robot drive on PWMS 1, 2, 3, and 4
		_robotDrive = new RobotDrive(1, 2, 3, 4);
		
		
		
		_minibotDeployerSolenoid = new DoubleSolenoid(SOLENOID_BREAKOUT_SLOT, MINIBOT_IN_SOLENOID, MINIBOT_OUT_SOLENOID);
		
		
		_arm = new Arm();
		
		
		_rollerGrip = new RollerGrip(1, 2, 3, 4);	//	FIXME: these are the wrong channels
		

		// Acquire the Driver Station object
		_driverStation = DriverStation::GetInstance();



		/**********		Init Controllers	**********/
		_driverGamepad = new Gamepad(1);
		_armGamepad = new Gamepad(2);
		
		_beastController = new BeastController(_driverStation);

		
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
		_arm->logInfo();
		
		_lightSensors->logInfo();
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
	
	
	
	

	/*
	void TeleopInit(void) {

	}*/

	/********************************** Autonomous *************************************/

	
#include "Autonomous.h"

	

	void AutonomousInit(void)
	{
		//	_autonomousTask("Autonomous", AutonomousTask());
		//	start task
		
		
		AutonomousTask();	//	FIXME: do this with a wpi task, not a direct call!!!!!!!!!!!
	}

	

	bool LineThick()
	{
		return ( _lightSensors->state() == LightSensorArray::kLeftOn | LightSensorArray::kMidOn | LightSensorArray::kRightOn );	//	all sensors are on
	}


	void AutonomousPeriodic(void)
	{








		LogToDashboard();
	}



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

	
	
	/***************	TeleOp		***************/
	
	/*
	void JoystickArmControl(Joystick *j)
	{
		//	elbow control w/y-axis of joystick
		_arm->_elbowController->Set( -(j->GetY()) );
		
		
		
		//	FIXME: add stuff for shoulder
		
		
		
		//	claw open/close
		if ( j->GetTrigger() )
		{
			_claw->open();
		}
		else
		{
			_claw->close();
		}
	}
	*/
	
	
	
	
	void GamepadDrive(Gamepad *gp)
	{
		float throttle;
		if ( gp->GetButton(Gamepad::kRightTopTrigger) )
			throttle = DRIVE_SPEED_HIGH;
		else if ( gp->GetButton(Gamepad::kLeftTopTrigger) )
			throttle = DRIVE_SPEED_LOW;
		else
			throttle = DRIVE_SPEED_MID;
		
		_robotDrive->SetMaxOutput(throttle);
		_robotDrive->TankDrive(gp->GetLeftY(), gp->GetRightY());
	}
	
	
	/*
	//	arcade drive w/a joystick
	void JoystickDrive(Joystick *j)
	{
		float throttle = j->GetThrottle();	//	-1 to 1
		throttle -= 1;	//	0 to -2
		throttle /= -2;	//	0 to 1 - backwards from the default setup
		
		
		_robotDrive->SetMaxOutput(throttle);
		_robotDrive->ArcadeDrive(j);
	}
	*/
	
	void GamepadArmControl(Gamepad *gp)
	{
		
		//	arm shoulder control
		if ( gp->GetButton(Gamepad::kBottomButton) )
			_arm->lowerShoulder();
		else if ( gp->GetButton(Gamepad::kTopButton) )
			_arm->raiseShoulder();
		
		
		
		if ( gp->GetButton(Gamepad::kRightTopTrigger) )
		{
			_rollerGrip->release();
		}
		else if ( gp->GetButton(Gamepad::kRightBottomTrigger) )
		{
			_rollerGrip->intake();
		}
		else if ( gp->GetButton(Gamepad::kLeftTopTrigger) )
		{
			_rollerGrip->rotateUp();
		}
		else if ( gp->GetButton(Gamepad::kLeftBottomTrigger) )
		{
			_rollerGrip->rotateDown();
		}
		else
		{
			_rollerGrip->intake();
			//	_rollerGrip->disable();
		}
		
		
		
		
		
		
		//	claw control w/top right trigger
		/*
		if ( gp->GetButton(Gamepad::kRightTopTrigger) )
			_claw->open();
		else
			_claw->close();
		*/
		/*
		//	shoulder - right joystick
		if ( gp->GetRightY() > .5 )
		{
			_arm->lowerShoulder();
		}
		else if ( gp->GetRightY() < -.5 )
		{
			_arm->raiseShoulder();
		}*/
		
		
		//	elbow - left joystick
		double elbowPower = gp->GetLeftY() * -ELBOW_MAX_POWER;
		_arm->_elbowController->Set(elbowPower);
	}
	
	
	
	
	void TeleopPeriodic(void)
	{
		if ( _driverStation->IsNewControlData())
		{
			GamepadDrive(_driverGamepad);
			GamepadArmControl(_armGamepad);
			
			
			//	minibot deployment
			if ( _beastController->minibotDeployed())
			{
				_minibotDeployerSolenoid->Set(DoubleSolenoid::kForward);
			}
			else
			{
				_minibotDeployerSolenoid->Set(DoubleSolenoid::kReverse);
			}
			
		}
		
		
		LogToDashboard();
	}
	
};

START_ROBOT_CLASS(FRC2011);
