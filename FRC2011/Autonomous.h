


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
		
		return 1;
	}
