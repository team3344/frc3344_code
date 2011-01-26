#include "WPILib.h"



class FRC2011 : public IterativeRobot
{
	RobotDrive *_robotDrive;
	
	DriverStation _driverStation;
	
	Joystick *_rightJoystick;
	Joystick *_leftJoystick;
	

	enum {							// drive mode selection
		ARCADE_DRIVE = 1,
		TANK_DRIVE = 2
	} _driveMode;
	
		
public:

	FRC2011()	{
		printf("FRC2011 Constructor Started\n");

		// Create a robot using standard right/left robot drive on PWMS 1, 2, 3, and #4
		_robotDrive = new RobotDrive(1, 3, 2, 4);

		// Acquire the Driver Station object
		_driverStation = DriverStation::GetInstance();

		// Define joysticks being used at USB port #1 and USB port #2 on the Drivers Station
		_rightJoystick = new Joystick(1);
		_leftJoystick = new Joystick(2);
		
		// Set drive mode to uninitialized
		_driveMode = UNINITIALIZED_DRIVE;

		// Initialize counters to record the number of loops completed in autonomous and teleop modes
		m_autoPeriodicLoops = 0;
		m_disabledPeriodicLoops = 0;
		m_telePeriodicLoops = 0;

		printf("BuiltinDefaultCode Constructor Completed\n");
	}
	
	
	/********************************** Init Routines *************************************/

	void RobotInit(void) {
		// Actions which would be performed once (and only once) upon initialization of the
		// robot would be put here.
		
		printf("RobotInit() completed.\n");
	}
	
	void DisabledInit(void) {
		m_disabledPeriodicLoops = 0;			// Reset the loop counter for disabled mode
		ClearSolenoidLEDsKITT();
		// Move the cursor down a few, since we'll move it back up in periodic.
		printf("\x1b[2B");
	}

	void AutonomousInit(void) {
		m_autoPeriodicLoops = 0;				// Reset the loop counter for autonomous mode
		ClearSolenoidLEDsKITT();
	}

	void TeleopInit(void) {
		m_telePeriodicLoops = 0;				// Reset the loop counter for teleop mode
		m_dsPacketsReceivedInCurrentSecond = 0;	// Reset the number of dsPackets in current second
		m_driveMode = UNINITIALIZED_DRIVE;		// Set drive mode to uninitialized
		ClearSolenoidLEDsKITT();
	}

	/********************************** Periodic Routines *************************************/
	
	void DisabledPeriodic(void)  {
		static INT32 printSec = (INT32)GetClock() + 1;
		static const INT32 startSec = (INT32)GetClock();


		// increment the number of disabled periodic loops completed
		m_disabledPeriodicLoops++;
		
		// while disabled, printout the duration of current disabled mode in seconds
		if (GetClock() > printSec) {
			// Move the cursor back to the previous line and clear it.
			printf("\x1b[1A\x1b[2K");
			printf("Disabled seconds: %d\r\n", printSec - startSec);			
			printSec++;
		}
	}

	void AutonomousPeriodic(void) {
		
		m_autoPeriodicLoops++;

		// generate KITT-style LED display on the solenoids
		SolenoidLEDsKITT( m_autoPeriodicLoops );
				
		/* the below code (if uncommented) would drive the robot forward at half speed
		 * for two seconds.  This code is provided as an example of how to drive the 
		 * robot in autonomous mode, but is not enabled in the default code in order
		 * to prevent an unsuspecting team from having their robot drive autonomously!
		 */
		/* below code commented out for safety
		if (m_autoPeriodicLoops == 1) {
			// When on the first periodic loop in autonomous mode, start driving forwards at half speed
			m_robotDrive->Drive(0.5, 0.0);			// drive forwards at half speed
		}
		if (m_autoPeriodicLoops == (2 * GetLoopsPerSec())) {
			// After 2 seconds, stop the robot 
			m_robotDrive->Drive(0.0, 0.0);			// stop robot
		}
		*/
	}

	
	void TeleopPeriodic(void) {
		// increment the number of teleop periodic loops completed
		m_telePeriodicLoops++;

		/*
		 * No longer needed since periodic loops are now synchronized with incoming packets.
		if (m_ds->GetPacketNumber() != m_priorPacketNumber) {
		*/
			/* 
			 * Code placed in here will be called only when a new packet of information
			 * has been received by the Driver Station.  Any code which needs new information
			 * from the DS should go in here
			 */
			 
			m_dsPacketsReceivedInCurrentSecond++;					// increment DS packets received
						
			// put Driver Station-dependent code here

			// Demonstrate the use of the Joystick buttons
			DemonstrateJoystickButtons(m_rightStick, m_rightStickButtonState, "Right Stick", &m_solenoids[1]);
			DemonstrateJoystickButtons(m_leftStick, m_leftStickButtonState, "Left Stick ", &m_solenoids[5]);
		
			// determine if tank or arcade mode, based upon position of "Z" wheel on kit joystick
			if (m_rightStick->GetZ() <= 0) {    // Logitech Attack3 has z-polarity reversed; up is negative
				// use arcade drive
				m_robotDrive->ArcadeDrive(m_rightStick);			// drive with arcade style (use right stick)
				if (m_driveMode != ARCADE_DRIVE) {
					// if newly entered arcade drive, print out a message
					printf("Arcade Drive\n");
					m_driveMode = ARCADE_DRIVE;
				}
			} else {
				// use tank drive
				m_robotDrive->TankDrive(m_leftStick, m_rightStick);	// drive with tank style
				if (m_driveMode != TANK_DRIVE) {
					// if newly entered tank drive, print out a message
					printf("Tank Drive\n");
					m_driveMode = TANK_DRIVE;
				}
			} 
		/*
		}  // if (m_ds->GetPacketNumber()...
		*/

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
	 */	
	void ClearSolenoidLEDsKITT() {
		// Iterate over all the solenoids on the robot, clearing each in turn
		UINT8 solenoidNum = 1;						// start counting solenoids at solenoid 1
		for (solenoidNum = 1; solenoidNum <= NUM_SOLENOIDS; solenoidNum++) {
			m_solenoids[solenoidNum]->Set(false);
		}
	}
	
	/**
	 * Generate KITT-style LED display on the solenoids
	 * 
	 * This method expects to be called during each periodic loop, with the argument being the 
	 * loop number for the current loop.
	 * 
	 * The goal here is to generate a KITT-style LED display.  (See http://en.wikipedia.org/wiki/KITT )
	 * However, since the solenoid module has two scan bars, we can have ours go in opposite directions!
	 * The scan bar is written to have a period of one second with six different positions.
	 */
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
	}

	/**
	 * Demonstrate handling of joystick buttons
	 * 
	 * This method expects to be called during each periodic loop, providing the following
	 * capabilities:
	 * - Print out a message when a button is initially pressed
	 * - Solenoid LEDs light up according to joystick buttons:
	 *   - When no buttons pressed, clear the solenoid LEDs
	 *   - When only one button is pressed, show the button number (in binary) via the solenoid LEDs
	 *   - When more than one button is pressed, show "15" (in binary) via the solenoid LEDs
	 */
	void DemonstrateJoystickButtons(Joystick *currStick,
									bool *buttonPreviouslyPressed,
									const char *stickString,
									Solenoid *solenoids[]) {
		
		UINT8 buttonNum = 1;				// start counting buttons at button 1
		bool outputGenerated = false;		// flag for whether or not output is generated for a button
		INT8 numOfButtonPressed = 0;		// 0 if no buttons pressed, -1 if multiple buttons pressed
		
		/* Iterate over all the buttons on the joystick, checking to see if each is pressed
		 * If a button is pressed, check to see if it is newly pressed; if so, print out a
		 * message on the console
		 */ 
		for (buttonNum = 1; buttonNum <= NUM_JOYSTICK_BUTTONS; buttonNum++) {
			if (currStick->GetRawButton(buttonNum)) {
				// the current button is pressed, now act accordingly...
				if (!buttonPreviouslyPressed[buttonNum]) {
					// button newly pressed; print out a message
					if (!outputGenerated) {
						// print out a heading if no other button pressed this cycle
						outputGenerated = true;
						printf("%s button pressed:", stickString);
					}
					printf(" %d", buttonNum);
				}
				// remember that this button is pressed for the next iteration
				buttonPreviouslyPressed[buttonNum] = true;
				
				// set numOfButtonPressed appropriately
				if (numOfButtonPressed == 0) {
					// no button pressed yet this time through, set the number correctly
					numOfButtonPressed = buttonNum;
				} else {
					// another button (or buttons) must have already been pressed, set appropriately
					numOfButtonPressed = -1;
				}
			} else {
				buttonPreviouslyPressed[buttonNum] = false;
			}
		}
		
		// after iterating through all the buttons, add a newline to output if needed
		if (outputGenerated) {
			printf("\n");
		}
		
		if (numOfButtonPressed == -1) {
			// multiple buttons were pressed, display as if button 15 was pressed
			DisplayBinaryNumberOnSolenoidLEDs(15, solenoids);
		} else {
			// display the number of the button pressed on the solenoids;
			// note that if no button was pressed (0), the solenoid display will be cleared (set to 0)
			DisplayBinaryNumberOnSolenoidLEDs(numOfButtonPressed, solenoids);
		}
	}
	

	/**
	 * Display a given four-bit value in binary on the given solenoid LEDs
	 */
	void DisplayBinaryNumberOnSolenoidLEDs(UINT8 displayNumber, Solenoid *solenoids[]) {

		if (displayNumber > 15) {
			// if the number to display is larger than can be displayed in 4 LEDs, display 0 instead
			displayNumber = 0;
		}
		
		solenoids[3]->Set( (displayNumber & 1) != 0);
		solenoids[2]->Set( (displayNumber & 2) != 0);
		solenoids[1]->Set( (displayNumber & 4) != 0);
		solenoids[0]->Set( (displayNumber & 8) != 0);
	}
			
};

START_ROBOT_CLASS(BuiltinDefaultCode);
