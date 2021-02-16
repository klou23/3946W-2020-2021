#include "main.h"
#include "globals.hpp"

//lv_font_t lv_font_dejavu_30;

//driver control stuff
const bool quadraticControl = true;

//motor ports
const int frontLeftDrivePort = 11;
const int frontRightDrivePort = 20;
const int backLeftDrivePort = 12;
const int backRightDrivePort = 19;
const int leftIntakePort = 1;
const int rightIntakePort = 10;
const int lowerManipulatorPort = 2;
const int upperManipulatorPort = 9;

//declare controller and buttons
Controller masterController(ControllerId::master);
ControllerButton masterL1(ControllerId::master, ControllerDigital::L1);
ControllerButton masterL2(ControllerId::master, ControllerDigital::L2);
ControllerButton masterR1(ControllerId::master, ControllerDigital::R1);
ControllerButton masterR2(ControllerId::master, ControllerDigital::R2);
ControllerButton masterUp(ControllerId::master, ControllerDigital::up);
ControllerButton masterDown(ControllerId::master, ControllerDigital::down);
ControllerButton masterLeft(ControllerId::master, ControllerDigital::left);
ControllerButton masterRight(ControllerId::master, ControllerDigital::right);
ControllerButton masterX(ControllerId::master, ControllerDigital::X);
ControllerButton masterB(ControllerId::master, ControllerDigital::B);
ControllerButton masterY(ControllerId::master, ControllerDigital::Y);
ControllerButton masterA(ControllerId::master, ControllerDigital::A);

Controller partnerController(ControllerId::partner);
ControllerButton partnerL1(ControllerId::partner, ControllerDigital::L1);
ControllerButton partnerL2(ControllerId::partner, ControllerDigital::L2);
ControllerButton partnerR1(ControllerId::partner, ControllerDigital::R1);
ControllerButton partnerR2(ControllerId::partner, ControllerDigital::R2);
ControllerButton partnerUp(ControllerId::partner, ControllerDigital::up);
ControllerButton partnerDown(ControllerId::partner, ControllerDigital::down);
ControllerButton partnerLeft(ControllerId::partner, ControllerDigital::left);
ControllerButton partnerRight(ControllerId::partner, ControllerDigital::right);
ControllerButton partnerX(ControllerId::partner, ControllerDigital::X);
ControllerButton partnerB(ControllerId::partner, ControllerDigital::B);
ControllerButton partnerY(ControllerId::partner, ControllerDigital::Y);
ControllerButton partnerA(ControllerId::partner, ControllerDigital::A);

//declare motors
Motor frontLeftDrive(frontLeftDrivePort, false, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);
Motor frontRightDrive(frontRightDrivePort, true, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);
Motor backLeftDrive(backLeftDrivePort, false, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);
Motor backRightDrive(backRightDrivePort, true, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);
Motor leftIntake(leftIntakePort, true, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);
Motor rightIntake(rightIntakePort, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);
Motor lowerManipulator(lowerManipulatorPort, true, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);
Motor upperManipulator(upperManipulatorPort, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);

//auton variables
const int RED = 0;
const int BLUE = 1;
int autonNum = 1;
int autonColor = 0;
const QLength& rollerCenterDist = 5_in;

//motor rpms
const int driveSpeed = 200;
const int intakeSpeed = 600;
const int manipulatorSpeed = 600;

//declare chassis controller
std::shared_ptr<OdomChassisController> drive = ChassisControllerBuilder()
    .withMotors(
            {frontLeftDrivePort, backLeftDrivePort},
            {-frontRightDrivePort, -backRightDrivePort}
    )
    .withGains(                  //TODO: tune PID
      {0.001, 0.000, 0.000},     //distance controller gains (kp, ki, kd)
      {0.003, 0.000, 0.000}      //turn controller gains (kp, ki, kd);
    )
    .withDimensions(                    //TODO: measure wheelbase
        AbstractMotor::gearset::green,	//green gear cartridge
		{{4_in,							//4 inch wheel diameter
		10_in},						//11.5 inch wheelbase
		imev5GreenTPR * (1.0 / 1.0)}	//1:1 external gear ratio
	)
    .withOdometry()
    .buildOdometry();
