#include "main.h"

//motor ports
const int frontLeftDrivePort = 1;
const int frontRightDrivePort = -2;
const int backLeftDrivePort = -3;
const int backRightDrivePort = 4;
const int leftIntakePort = 5;
const int rightIntakePort = 6;
const int lowerManipulatorPort = 7;
const int upperManipulatorPort = 8;

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

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
    //set position to (0,0) and orientation to 0
    drive->setState({0_in, 0_in, 0_deg});
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}
