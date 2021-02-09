#include "main.h"
#include "globals.hpp"

//lv_font_t lv_font_dejavu_30;

//motor ports
const int frontLeftDrivePort = 11;
const int frontRightDrivePort = -20;
const int backLeftDrivePort = 12;
const int backRightDrivePort = -19;
const int leftIntakePort = 1;
const int rightIntakePort = -10;
const int lowerManipulatorPort = -2;
const int upperManipulatorPort = 9;

//declare controller and buttons
Controller controller;
ControllerButton btnL1(ControllerDigital::L1);
ControllerButton btnL2(ControllerDigital::L2);
ControllerButton btnR1(ControllerDigital::R1);
ControllerButton btnR2(ControllerDigital::R2);
ControllerButton btnUp(ControllerDigital::up);
ControllerButton btnDown(ControllerDigital::down);
ControllerButton btnLeft(ControllerDigital::left);
ControllerButton btnRight(ControllerDigital::right);
ControllerButton btnX(ControllerDigital::X);
ControllerButton btnB(ControllerDigital::B);
ControllerButton btnY(ControllerDigital::Y);
ControllerButton btnA(ControllerDigital::A);

//declare motors
Motor frontLeftDrive(frontLeftDrivePort);
Motor frontRightDrive(frontRightDrivePort);
Motor backLeftDrive(backLeftDrivePort);
Motor backRightDrive(backRightDrivePort);
Motor leftIntake(leftIntakePort);
Motor rightIntake(rightIntakePort);
Motor lowerManipulator(lowerManipulatorPort);
Motor upperManipulator(upperManipulatorPort);

//auton variables
const int RED = 0;
const int BLUE = 1;
int autonNum = 1;
int autonColor = 0;


//declare chassis controller
std::shared_ptr<OdomChassisController> drive = ChassisControllerBuilder()
    .withMotors(
		    1,        //Front left
            -2,       //Front right (reversed)
            -3,       //Back right (reversed)
            4         //Back left
    )
    .withGains(
      {0.001, 0, 0.0001},     //distance controller gains (kp, ki, kd)
      {0.001, 0, 0.0001}      //turn controller gains (kp, ki, kd);
    )
    .withSensors(
        ADIEncoder{'A', 'B'}, 		// left encoder in ADI ports A & B
        ADIEncoder{'C', 'D', true}, // right encoder in ADI ports C & D (reversed)
        ADIEncoder{'E', 'F'}  		// middle encoder in ADI ports E & F
    )
    .withDimensions(
        AbstractMotor::gearset::green,	//green gear cartridge
		{{4_in,							//4 inch tracking wheel diameter
		11.5_in},						//11.5 inch wheelbase
		imev5GreenTPR * (1.0 / 1.0)}	//1:1 external gear ratio
	)
    .withOdometry(
		{{2.75_in,		//tracking wheels diameter is 2.75 in
		7_in,			//tracking wheel base is 7 in
		1_in,			//middle encoder distance is 1 in
		2.75_in},		//middle tracking wheel diameter is 2.75 in
		quadEncoderTPR}
	)
    .buildOdometry();
