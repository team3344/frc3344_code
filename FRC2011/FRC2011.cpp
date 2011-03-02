
#include "wpilib.h"
#include "Hardware/Arm.h"
#include "Hardware/Claw.h"
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
	Claw *_claw;
	
	LightSensorArray *_lightSensors;

	DriverStation *_driverStation;
	
	Compressor *_compressor;

	
	
	

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
		
		
		
		
		_arm = new Arm();
		
		
		_claw = new Claw(CLAW_RELAY_CHANNEL);
		
		

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

	int AutonomousTask()
	{
		
		_arm->raiseShoulder();
		
		
		
		_robotDrive->SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);
		_robotDrive->SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
		_robotDrive->SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
		_robotDrive->SetInvertedMotor(RobotDrive::kRearRightMotor, true);
		
		
		AutonomousPosition pos = _beastController->autonomousPosition();
		
		double defaultSteeringGain = .65;	// default value for steering gain - was .65

		int binaryValue;
		int previousValue = 0;
		double steeringGain;

		// the power profiles for the straight and forked robot path. They are
		// different to let the robot drive more slowly as the robot approaches
		// the fork on the forked line case.
		double forkProfile[] = {0.70, 0.70, .70, .55, 0.60, 0.60, 0.50, 0.40, 0.0};
		//double straightProfile[] = {.8, 0.8, .8, 0.7, .7, .7, .6, 0.60, .5, 0.35, 0.35, 0.35, 0.0};

		double straightProfile[] = {.6, 0.65, .6, 0.6, .4, .4, .4, 0.4, .35, 0.35, 0.3, 0.35, 0.0};

		
		
		double *powerProfile;  // the selected power profile
		
		// set the straight vs forked path variables as read from the DS digital
		// inputs or the I/O Setup panel on the driver station.
		bool straightLine = pos | kStraightAutonomous;
		
		SmartDashboard::Log(straightLine, "straightLine");
		
		powerProfile = (straightLine) ? straightProfile : forkProfile;
		double stopTime = (straightLine) ? 2.0 : 4.0;
		bool goLeft = (bool)(pos | kLeftAutonomous) && !straightLine;
		
		SmartDashboard::Log(goLeft, "goLeft");
		
		printf("StraightLine: %d\n", straightLine);
		printf("GoingLeft: %d\n", goLeft);

		bool atCross = false;	// true when robot has reached end

		// set up timer for 8 second max driving time and use the timer to
		// pick values from the power profile arrays
		Timer *timer = new Timer();
		timer->Start();
		timer->Reset();
				
		int oldTimeInSeconds = -1;
		double time;
		double speed, turn;
		
		// loop until either we hit the "T" at the end or 8 seconds has
		// elapsed. The time to the end should be less than 7 seconds
		// for either path.
		while ((time = timer->Get()) < 10.0 && !atCross) {
			LightSensorArray::LightSensorState lsState = _lightSensors->state();
			
			SmartDashboard::Log((float)lsState, "lsState");
			
			
			SmartDashboard::Log(_lightSensors->state(), "_lightSensors->state()");
			
			
			int timeInSeconds = (int) time;
			
			
			//int leftValue = (lsState | LightSensorArray::kLeftOn > 0) ? 1 : 0;	// read the line tracking sensors
			//int middleValue = (lsState | LightSensorArray::kMidOn > 0) ? 1 : 0;
			//int rightValue = (lsState | LightSensorArray::kRightOn > 0) ? 1 : 0;
			
			int leftValue = _lightSensors->left();
			int middleValue = _lightSensors->mid();
			int rightValue = _lightSensors->right();
			
			
			
			
			
			
			
			
			
		    // compute the single value from the 3 sensors. Notice that the bits
		    // for the outside sensors are flipped depending on left or right
		    // fork. Also the sign of the steering direction is different for left/right.
			if (goLeft) {
				binaryValue = leftValue * 4 + middleValue * 2 + rightValue;
				steeringGain = -defaultSteeringGain;
			} else {
				binaryValue = rightValue * 4 + middleValue * 2 + leftValue;
				steeringGain = defaultSteeringGain;
			}

			
			SmartDashboard::Log((float)leftValue, "leftValue");
			SmartDashboard::Log((float)middleValue, "middleValue");
			SmartDashboard::Log((float)rightValue, "rightValue");
			
			SmartDashboard::Log(binaryValue, "binaryValue");
			
			
			speed = powerProfile[timeInSeconds];	// speed value for this time
			turn = 0;								// default to no turn
			
			switch (binaryValue) {
				case 1:					// just the outside sensor - drive straight
					turn = 0;
					break;
				case 7:					// all sensors - maybe at the "T"
				if (time> stopTime) {
					atCross = true;
					speed = 0;
				}
				break;
				case 0:					// no sensors - apply previous correction
				if (previousValue == 0 || previousValue == 1) {
					turn = steeringGain;
				}
				else {
					turn = -steeringGain;
				}
				break;
				default:				// anything else, steer back to the line
				turn = -steeringGain;
			}
			// useful debugging output for tuning your power profile and steering gain
			if(binaryValue != previousValue)
				printf("Time: %2.2f sensor: %d speed: %1.2f turn: %1.2f atCross: %d\n", time, binaryValue, speed, turn, atCross);
			// move the robot forward
			_robotDrive->ArcadeDrive(speed, turn);
			
			SmartDashboard::Log(turn, "LF Turn");
			
			if (binaryValue != 0) previousValue = binaryValue;
			oldTimeInSeconds = timeInSeconds;
			Wait(0.01);
		}
		// stop driving when finished
		_robotDrive->ArcadeDrive(0.0, 0.0);
		
		
		_robotDrive->SetInvertedMotor(RobotDrive::kFrontLeftMotor, false);
		_robotDrive->SetInvertedMotor(RobotDrive::kFrontRightMotor, false);
		_robotDrive->SetInvertedMotor(RobotDrive::kRearLeftMotor, false);
		_robotDrive->SetInvertedMotor(RobotDrive::kRearRightMotor, false);
		

	}

	

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
	
	
	//	arcade drive w/a joystick
	void JoystickDrive(Joystick *j)
	{
		float throttle = j->GetThrottle();	//	-1 to 1
		throttle -= 1;	//	0 to -2
		throttle /= -2;	//	0 to 1 - backwards from the default setup
		
		
		_robotDrive->SetMaxOutput(throttle);
		_robotDrive->ArcadeDrive(j);
	}
	
	
	void GamepadArmControl(Gamepad *gp)
	{
		
		//	arm shoulder control
		if ( gp->GetButton(Gamepad::kBottomButton) )
			_arm->lowerShoulder();
		else if ( gp->GetButton(Gamepad::kTopButton) )
			_arm->raiseShoulder();
		
		
		
		/*
		
		Gamepad::DPadDirection dPad = gp->GetDPad();
		
		if ( dPad == Gamepad::kUp )
			_arm->_elbowController->Set(ELBOW_MAX_POWER);	//	up
		else if ( dPad == Gamepad::kDown )
			_arm->_elbowController->Set(-ELBOW_MAX_POWER);	//	down
		else
			_arm->_elbowController->Set(0);	//	turn it off
		*/
		
		
		//	claw control w/top right trigger
		if ( gp->GetButton(Gamepad::kRightTopTrigger) )
			_claw->open();
		else
			_claw->close();
		
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
		GamepadDrive(_driverGamepad);
		GamepadArmControl(_armGamepad);
		//JoystickArmControl(_armJoystick);
		
		LogToDashboard();
	} // TeleopPeriodic(void)
	
	
};

START_ROBOT_CLASS(FRC2011);
