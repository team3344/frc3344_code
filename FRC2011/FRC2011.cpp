
#include "WPILib.h"
#include "Hardware/Arm.h"
#include "Defines.h"





class FRC2011 : public IterativeRobot
{
	RobotDrive *_robotDrive;
	Arm *_arm;
	
	DriverStation *_driverStation;
	
	
	SmartDashboard *_dashboard;
	
	Joystick *_rightJoystick;
	Joystick *_leftJoystick;
	
	
	Compressor *_compressor;
	

	enum {						// drive mode selection
		ARCADE_DRIVE = 1,
		TANK_DRIVE = 2
	} _driveMode;
	
		
public:

	FRC2011()
	{
		printf("FRC2011 Constructor Started\n");
		
		// Set drive mode
		_driveMode = ARCADE_DRIVE;
		

		// Create a robot using standard right/left robot drive on PWMS 1, 2, 3, and #4
		_robotDrive = new RobotDrive(1, 3, 2, 4);	//	FIXME: asdf;asdkjf;asdjfl;asdj;

		// Acquire the Driver Station object
		_driverStation = DriverStation::GetInstance();

		// Define joysticks being used at USB port #1 and USB port #2 on the Drivers Station
		_rightJoystick = new Joystick(1);
		_leftJoystick = new Joystick(2);
		
		
		
		//	init and start compressor
		_compressor = new Compressor(SIDECAR_SLOT, 1, SIDECAR_SLOT, 1);
		_compressor->Start();
	}
	
	
	
	
	void LogToDashboard()
	{
		//	relay ports
		
		
		
		_dashboard->Log("hello world", "try1");
		
		
		
		
		//	power sent to motors
		
		
		
		
		
		//	light sensors
		
		//	arm position
		
		//	camera image
		
		//	pressure of storage tanks
		
		//	
		
		
		
		
		
		
		
		
		
	}
	
	
	
	
	/********************************** Init Routines *************************************/

	void RobotInit(void) {
		// Actions which would be performed once (and only once) upon initialization of the
		// robot would be put here.
		
		printf("RobotInit() completed.\n");
	}
	
	/*
	void DisabledInit(void) {
		m_disabledPeriodicLoops = 0;			// Reset the loop counter for disabled mode
		ClearSolenoidLEDsKITT();
		// Move the cursor down a few, since we'll move it back up in periodic.
		printf("\x1b[2B");
	}*/
	/*
	void AutonomousInit(void) {
		m_autoPeriodicLoops = 0;				// Reset the loop counter for autonomous mode
		ClearSolenoidLEDsKITT();
	}*/
	/*
	void TeleopInit(void) {
		m_driveMode = UNINITIALIZED_DRIVE;		// Set drive mode to uninitialized
		ClearSolenoidLEDsKITT();
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
	
	
	void TeleopPeriodic(void) {
		// determine if tank or arcade mode, based upon position of "Z" wheel on kit joystick
		if (_rightJoystick->GetZ() <= 0) {    // Logitech Attack3 has z-polarity reversed; up is negative
			// use arcade drive
			_robotDrive->ArcadeDrive(_rightJoystick);			// drive with arcade style (use right stick)
			if (_driveMode != ARCADE_DRIVE) {
				// if newly entered arcade drive, print out a message
				printf("Arcade Drive\n");
				_driveMode = ARCADE_DRIVE;
			}
		} else {
			// use tank drive
			_robotDrive->TankDrive(_leftJoystick, _rightJoystick);	// drive with tank style
			if (_driveMode != TANK_DRIVE) {
				// if newly entered tank drive, print out a message
				printf("Tank Drive\n");
				_driveMode = TANK_DRIVE;
			}
		}
		
		
		
		LogToDashboard();
		
		
	} // TeleopPeriodic(void)


/********************************** Continuous Routines *************************************/

	/* 
	 * These routines are not used in this demonstration robot
	 *
	 * 
	void DisabledContinuous(void) {
	}

	void AutonomousContinuous(void)	{
	}

	void TeleopContinuous(void) {
	}
	*/

	
/********************************** Miscellaneous Routines *************************************/
	
	/**
	 * Clear KITT-style LED display on the solenoids
	 * 
	 * Clear the solenoid LEDs used for a KITT-style LED display.
	 */	/*
	void ClearSolenoidLEDsKITT() {
		// Iterate over all the solenoids on the robot, clearing each in turn
		UINT8 solenoidNum = 1;						// start counting solenoids at solenoid 1
		for (solenoidNum = 1; solenoidNum <= NUM_SOLENOIDS; solenoidNum++) {
			m_solenoids[solenoidNum]->Set(false);
		}
	}*/
	
	/**
	 * Generate KITT-style LED display on the solenoids
	 * 
	 * This method expects to be called during each periodic loop, with the argument being the 
	 * loop number for the current loop.
	 * 
	 * The goal here is to generate a KITT-style LED display.  (See http://en.wikipedia.org/wiki/KITT )
	 * However, since the solenoid module has two scan bars, we can have ours go in opposite directions!
	 * The scan bar is written to have a period of one second with six different positions.
	 *//*
	void SolenoidLEDsKITT(UINT32 numloops) {
		unsigned int const NUM_KITT_POSITIONS = 6;
		UINT16 numloop_within_second = numloops % (UINT32)GetLoopsPerSec();

		if (numloop_within_second == 0) {
			// position 1; solenoids 1 and 8 on
			m_solenoids[1]->Set(true);  m_solenoids[8]->Set(true);
			m_solenoids[2]->Set(false); m_solenoids[7]->Set(false);
		} else if (numloop_within_second == ((UINT32)GetLoopsPerSec() / NUM_KITT_POSITIONS)) {
			// position 2; solenoids 2 and 7 on
			m_solenoids[2]->Set(true);  m_solenoids[7]->Set(true);
			m_solenoids[1]->Set(false); m_solenoids[8]->Set(false);
		} else if (numloop_within_second == ((UINT32)GetLoopsPerSec() * 2 / NUM_KITT_POSITIONS)) {
			// position 3; solenoids 3 and 6 on
			m_solenoids[3]->Set(true);  m_solenoids[6]->Set(true);
			m_solenoids[2]->Set(false); m_solenoids[7]->Set(false);
		} else if (numloop_within_second == ((UINT32)GetLoopsPerSec() * 3 / NUM_KITT_POSITIONS)) {
			// position 4; solenoids 4 and 5 on
			m_solenoids[4]->Set(true);  m_solenoids[5]->Set(true);
			m_solenoids[3]->Set(false); m_solenoids[6]->Set(false);
		} else if (numloop_within_second == ((UINT32)GetLoopsPerSec() * 4 / NUM_KITT_POSITIONS)) {
			// position 5; solenoids 3 and 6 on
			m_solenoids[3]->Set(true);  m_solenoids[6]->Set(true);
			m_solenoids[4]->Set(false); m_solenoids[5]->Set(false);
		} else if (numloop_within_second == ((UINT32)GetLoopsPerSec() * 5 / NUM_KITT_POSITIONS)) {
			// position 6; solenoids 2 and 7 on
			m_solenoids[2]->Set(true);  m_solenoids[7]->Set(true);
			m_solenoids[3]->Set(false); m_solenoids[6]->Set(false);
		} 
	}*/
			
};

START_ROBOT_CLASS(FRC2011);
