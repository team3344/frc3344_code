

#ifndef LOGITECH_GAMEPAD_H
#define LOGITECH_GAMEPAD_H


#include "wpilib.h"






class LogitechGamepad : public GenericHID {	//	FIXME: inherit from GenericHID???, Joystick???

public:
	LogitechGamepad(UINT32 portNumber);	//	FIXME: does wpi call it port number???
	~LogitechGamepad();
	
	
	
	enum {
		kButtonL1,
		kButtonL2,
		
		kButtonR1,
		kButtonR2,
		
		kButton1,
		kButton2,
		kButton3,
		kButton4,
		
		
	} Button;
	
	
	bool buttonIsToggledOn(Button b);
	bool buttonIsPressed(Button b);
	
	
	
	
	//	axes
	Vector rightJoystick();
	Vector leftJoystick();
	Vector dPad();
	
	
private:
	
	
};



#endif	//	LOGITECH_GAMEPAD_H

