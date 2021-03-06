#include "WPILib.h"

/**
 * Disabled Mode:
 * - Once per second, print (on the console) the number of seconds the robot has been disabled.
 * 
 * Autonomous Mode:
 * - Flash the solenoid lights like KITT in Knight Rider
 * - Example code (commented out by default) to drive forward at half-speed for 2 seconds
 * 
 * Teleop Mode:
 * - Select between two different drive options depending upon Z-location of Joystick1
 * - When "Z-Up" (on Joystick1) provide "arcade drive" on Joystick1
 * - When "Z-Down" (on Joystick1) provide "tank drive" on Joystick1 and Joystick2
 * - Use Joystick buttons (on Joystick1 or Joystick2) to display the button number in binary on
 *   the solenoid LEDs (Note that this feature can be used to easily "map out" the buttons on a
 *   Joystick.  Note also that if multiple buttons are pressed simultaneously, a "15" is displayed
 *   on the solenoid LEDs to indicate that multiple buttons are pressed.)
 *
 * This code assumes the following connections:
 * - Driver Station:
 *   - USB 1 - The "right" joystick.  Used for either "arcade drive" or "right" stick for tank drive
 *   - USB 2 - The "left" joystick.  Used as the "left" stick for tank drive
 * 
 * - Robot:
 *   - Digital Sidecar 1:
 *     - PWM 1/3 - Connected to "left" drive motor(s)
 *     - PWM 2/4 - Connected to "right" drive motor(s)
 */



const UINT32 SOLENOID_BREAKOUT_SLOT = 8;
const UINT32 SIDECAR_SLOT = 4;
const UINT32 CYLINDER_RELAY_PORT = 3;


class Robot2010 : public IterativeRobot
{
	// Declare variable for the robot drive system
	RobotDrive *m_robotDrive;		// robot will use PWM 1-4 for drive motors
	
	// Declare a variable to use to access the driver station object
	DriverStation *m_ds;						// driver station object
	
	// Declare variables for the two joysticks being used
	Joystick *m_joystick;
	
	Compressor *m_compressor;
	
	Relay *m_cylinderRelay;
	
	
	Solenoid *upSolenoid;
	Solenoid *downSolenoid;
	
	
		
public:
/**
 * Constructor for this "BuiltinDefaultCode" Class.
 * 
 * The constructor creates all of the objects used for the different inputs and outputs of
 * the robot.  Essentially, the constructor defines the input/output mapping for the robot,
 * providing named objects for each of the robot interfaces. 
 */
	Robot2010(void)	{
		printf("Robot2010 Constructor Started\n");

		// Create a robot using standard right/left robot drive on PWMS 1, 2, 3, and #4
		m_robotDrive = new RobotDrive(1, 3);
		m_robotDrive->SetInvertedMotor(RobotDrive::kRearRightMotor, true);
		m_robotDrive->SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
		
		// Acquire the Driver Station object
		m_ds = DriverStation::GetInstance();
		
		// Define joysticks being used at USB port #1 and USB port #2 on the Drivers Station
		m_joystick = new Joystick(1);

		
		
		m_compressor = new Compressor(SIDECAR_SLOT, 1, SIDECAR_SLOT, 1);
		m_compressor->Start();
		
		
		m_cylinderRelay = new Relay(SIDECAR_SLOT, CYLINDER_RELAY_PORT);
		
		
		
		upSolenoid = new Solenoid(SOLENOID_BREAKOUT_SLOT, 1);
		downSolenoid = new Solenoid(SOLENOID_BREAKOUT_SLOT, 2);
		
		
		
		printf("FRC2010 Constructor Completed\n");
	}
	
	
	/********************************** Init Routines *************************************/

	void RobotInit(void) {
		// Actions which would be performed once (and only once) upon initialization of the
		// robot would be put here.
		
		printf("RobotInit() completed.\n");
	}
	
	void DisabledInit(void) {
		//ClearSolenoidLEDsKITT();
		// Move the cursor down a few, since we'll move it back up in periodic.
		printf("\x1b[2B");
	}

	void AutonomousInit(void) {
		//ClearSolenoidLEDsKITT();
	}

	void TeleopInit(void) {
		//ClearSolenoidLEDsKITT();
	}

	/********************************** Periodic Routines *************************************/
	
	void DisabledPeriodic(void)  {
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

	
	
	
	void PushUp()
	{
		m_cylinderRelay->Set(Relay::kForward);	//	let the exhause actually vent out
		downSolenoid->Set(false);
		upSolenoid->Set(true);	//	power A side of double solenoid
	}
	
	void PushDown()
	{
		m_cylinderRelay->Set(Relay::kForward);
		upSolenoid->Set(false);
		downSolenoid->Set(true);
	}
	
	void Hold()
	{
		m_cylinderRelay->Set(Relay::kOff);
		upSolenoid->Set(false);
		downSolenoid->Set(false);
	}
	
	
	
	
	
	
	void TeleopPeriodic(void) {
		
		double throttle = (m_joystick->GetThrottle() + 1) / 2;
		m_robotDrive->SetMaxOutput(throttle);
		
		m_robotDrive->ArcadeDrive(m_joystick);			// drive with arcade style (use right stick)
		
		//void SetSensitivity(float sensitivity);
		//void SetMaxOutput(double maxOutput);
		
		
		float pushTime = .02;
		
		//	kicker
		if ( m_joystick->GetRawButton(Joystick::kDefaultTriggerButton) )
		{
			if ( throttle > .5 )
			{
				PushUp();
				Wait(pushTime);
				Hold();
			}
			else
			{
				PushDown();
				Wait(pushTime);
				Hold();
			}
		}
		
	}


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
			
};

START_ROBOT_CLASS(Robot2010);
