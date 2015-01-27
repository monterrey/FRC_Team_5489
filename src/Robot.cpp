#include "WPILib.h"

class Robot: public IterativeRobot
{


    const static int frontLeftChannel	= 2;
    const static int rearLeftChannel	= 3;
    const static int frontRightChannel	= 1;
    const static int rearRightChannel	= 0;
    const static int joystickChannel	= 0;
    float x,y,z;
    constexpr static float deadZone = 0.4;
    RobotDrive myRobot;
    Joystick stick;
public:
    Robot(): myRobot(frontLeftChannel,rearLeftChannel,frontRightChannel,rearRightChannel),
	stick(joystickChannel)
	{
    	x = y = z= 0;
    	myRobot.SetExpiration(0.1);
    	myRobot.SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);
    	myRobot.SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
    }
private:

	void RobotInit()
	{
		myRobot.SetSafetyEnabled(false);
	}

	void AutonomousInit()
	{

	}

	void AutonomousPeriodic()
	{
		myRobot.MecanumDrive_Cartesian(1,0,0);
		Wait(0.1);
	}

	void TeleopInit()
	{

	}

	void TeleopPeriodic()
	{
		x = stick.GetX();
		y = stick.GetY();
		z = stick.GetZ();
		if(x<deadZone || (x < 0 && -x < deadZone)){
			x= 0;
		}
		if(y<deadZone || ( x < 0 && -x <deadZone) ){
			y = 0;
		}
		if(z < deadZone || ( x < 0 && -x < deadZone ) ){
			z = 0;
		}


		myRobot.MecanumDrive_Cartesian(x,y,z);
	}

	void TestPeriodic()
	{

	}
};

START_ROBOT_CLASS(Robot);
