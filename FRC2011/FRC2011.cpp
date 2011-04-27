
#include "wpilib.h"
#include "Hardware/Arm.h"
#include "Hardware/Claw.h"
#include "Hardware/LightSensorArray.h"
#include "Defines.h"
#include "Controller/Gamepad.h"
#include "Controller/BeastController.h"





class FRC2011 : public IterativeRobot
{
	RobotDrive *_robotDrive;
	Arm *_arm;
	Claw *_claw;
	LightSensorArray *_lightSensors;

	DriverStation *_driverStation;
	
	Compressor *_compressor;
	
	double _teleopStartTime;

	
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
		
		
		
		_claw = new Claw(CLAW_RELAY_CHANNEL);
		
		_minibotDeployerSolenoid = new DoubleSolenoid(SOLENOID_BREAKOUT_SLOT, MINIBOT_IN_SOLENOID, MINIBOT_OUT_SOLENOID);
		
		
		_arm = new Arm();
		
		
		//_rollerGrip = new RollerGrip(7, 8, 9, 10);
		

		// Acquire the Driver Station object
		_driverStation = DriverStation::GetInstance();


		_teleopStartTime = 10000000.0;	//	ridiculously huge number
		

		/**********		Init Controllers	**********/
		_driverGamepad = new Gamepad(1);
		_armGamepad = new Gamepad(2);
		
		_beastController = new BeastController(_driverStation);

		
		//	initialize the SmartDashboard
		SmartDashboard::init();


		//	initialize the light sensor array
		_lightSensors = new LightSensorArray(LIGHT_SENSOR_LEFT_PORT, LIGHT_SENSOR_MID_PORT, LIGHT_SENSOR_RIGHT_PORT);
		

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
		
		printf("RobotInit() completed.\n");
	}
	
	


	/********************************** Autonomous *************************************/

	
#include "Autonomous.h"

	

	void AutonomousInit(void)
	{
		//	_autonomousTask("Autonomous", AutonomousTask());
		//	start task
		
		//	FIXME: uncomment below line to re-enable autonomous
		//AutonomousTask();	//	FIXME: do this with a wpi task, not a direct call!!!!!!!!!!!
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
	
	
	void GamepadArmControl(Gamepad *gp)
	{
		//	arm shoulder control
		if ( gp->GetButton(Gamepad::kBottomButton) )
			_arm->lowerShoulder();
		else if ( gp->GetButton(Gamepad::kTopButton) )
			_arm->raiseShoulder();
		
		
		
		//	claw control w/top right trigger
		
		if ( gp->GetButton(Gamepad::kRightTopTrigger) )
			_claw->open();
		else
			_claw->close();
		
		
		
		
		double stick = gp->GetLeftY();	//	FIXME: is the minus sign necessary????
		SmartDashboard::Log(stick, "Elbow Control Stick");
		double elbowPower = stick * -ELBOW_MAX_POWER;
		_arm->_elbowController->Set(elbowPower);
		
	}
	
	
	
	void TeleopInit(void)
	{
		_teleopStartTime = GetTime();
	}
	
	void TeleopPeriodic(void)
	{
		//if ( _driverStation->IsNewControlData() )
		//{
			GamepadDrive(_driverGamepad);
			GamepadArmControl(_armGamepad);
			
			
			double elapsedTime = GetTime() - _teleopStartTime;
			bool deploymentPeriod = elapsedTime > MINIBOT_DEPLOYMENT_WAIT_TIME;
			bool oneSecondRemaining = elapsedTime >= (TELEOP_DURATION - 1);
			
			
			//	minibot deployment
			if ( _beastController->minibotDeployed() && deploymentPeriod && !oneSecondRemaining )
			{
				//_arm->raiseShoulder();
				//Wait(1);	//	FIXME: is this necessary???????????
				_minibotDeployerSolenoid->Set(DoubleSolenoid::kForward);
			}
			else
			{
				_minibotDeployerSolenoid->Set(DoubleSolenoid::kReverse);
			}
			
		//}
		
		LogToDashboard();
	}
};

START_ROBOT_CLASS(FRC2011);
