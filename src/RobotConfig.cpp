#include "RobotConfig.hpp"
#include "main.h"
#include "Rollers.hpp"
#include "Drive.hpp"
#include "Globals.hpp"
#include "Constants.hpp"

//motor ports
const uint8_t frontLeftDrivePort = 11;
const uint8_t frontRightDrivePort = 20;
const uint8_t backLeftDrivePort = 12;
const uint8_t backRightDrivePort = 19;
const uint8_t leftIntakePort = 1;
const uint8_t rightIntakePort = 10;
const uint8_t lowerManipulatorPort = 2;
const uint8_t upperManipulatorPort = 9;

//motor gearsets
const motor_gearset_e_t driveGearset = GREEN_GEARSET;
const motor_gearset_e_t intakeGearset = BLUE_GEARSET;
const motor_gearset_e_t manipulatorGearset = BLUE_GEARSET;

//controllers
Controller prosMasterController(E_CONTROLLER_MASTER);
Controller prosPartnerController(E_CONTROLLER_PARTNER);
CustomController masterController(prosMasterController);
CustomController partnerController(prosPartnerController);

//encoders
ADIEncoder leftEncoder('C', 'D', true);
ADIEncoder rightEncoder('E', 'F', false);

//motors
Motor frontLeftDrive(frontLeftDrivePort, driveGearset, false, E_MOTOR_ENCODER_DEGREES);
Motor frontRightDrive(frontRightDrivePort, driveGearset, true, E_MOTOR_ENCODER_DEGREES);
Motor backLeftDrive(backLeftDrivePort, driveGearset, false, E_MOTOR_ENCODER_DEGREES);
Motor backRightDrive(backRightDrivePort, driveGearset, true, E_MOTOR_ENCODER_DEGREES);
Motor leftIntake(leftIntakePort, intakeGearset, false, E_MOTOR_ENCODER_DEGREES);
Motor rightIntake(rightIntakePort, intakeGearset, true, E_MOTOR_ENCODER_DEGREES);
Motor lowerManipulator(lowerManipulatorPort, manipulatorGearset, true, E_MOTOR_ENCODER_DEGREES);
Motor upperManipulator(upperManipulatorPort, manipulatorGearset, true, E_MOTOR_ENCODER_DEGREES);

//drive
Drive drive(frontLeftDrive, frontRightDrive, backLeftDrive, backRightDrive, leftEncoder, rightEncoder);
Rollers rollers(leftIntake, rightIntake, lowerManipulator, upperManipulator);