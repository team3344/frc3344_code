
#ifndef GAMEPAD_H_
#define GAMEPAD_H_

#include "wpilib.h"
#include <stdio.h>

class DriverStation;

/**
 * Handle input from Logitech Dual Action Gamepad connected to the Driver
 * Station.
 */
class Gamepad
{
public:
    typedef enum
    {
        kLeftXAxis, kLeftYAxis, kRightXAxis, kRightYAxis
    } AxisType;

    typedef enum
    {
        kCenter, kUp, kUpLeft, kLeft, kDownLeft, kDown, kDownRight, kRight,
        kUpRight
    } DPadDirection;
    
    typedef enum
    {
    	kLeftButton = 1, kBottomButton, kRightButton, kTopButton,
    	kLeftTopTrigger, kRightTopTrigger, kLeftBottomTrigger, kRightBottomTrigger,
    	kLeftCenterButton, kRightCenterButton,
    	kLeftAnalogStickButton, kRightAnalogStickButton
    } ButtonType;

    Gamepad(UINT32 port);
    ~Gamepad();

    
    void logButtons();
    
    
    float GetLeftX();
    float GetLeftY();
    float GetRightX();
    float GetRightY();
    float GetAxis(AxisType axis);
    float GetRawAxis(UINT32 axis);

    bool GetNumberedButton(unsigned buttonNumber);
    bool GetButton(ButtonType button);
    bool GetLeftPush();
    bool GetRightPush();

    DPadDirection GetDPad();

protected:
    static const UINT32 kLeftXAxisNum = 1;
    static const UINT32 kLeftYAxisNum = 2;
    static const UINT32 kRightXAxisNum = 3;
    static const UINT32 kRightYAxisNum = 4;
    static const UINT32 kDPadXAxisNum = 5;
    static const UINT32 kDPadYAxisNum = 6;

    DriverStation *ap_ds;
    UINT32 a_port;
};

#endif // GAMEPAD_H_

