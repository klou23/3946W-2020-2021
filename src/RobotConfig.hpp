/**
 * @file
 * @brief Configuration for robot
 */

#ifndef PROS_OKAPI_ROBOTCONFIG_HPP
#define PROS_OKAPI_ROBOTCONFIG_HPP

#include "Globals.hpp"

/**
 * The port the front left drive motor is plugged into
 */
extern const uint8_t frontLeftDrivePort;
/**
 * The port the front right drive motor is plugged into
 */
extern const uint8_t frontRightDrivePort;
/**
 * The port the back left drive motor is plugged into
 */
extern const uint8_t backLeftDrivePort;
/**
 * The port the back right drive motor is plugged into
 */
extern const uint8_t backRightDrivePort;
/**
 * The port the left intake motor is plugged into
 */
extern const uint8_t leftIntakePort;
/**
 * The port the right intake motor is plugged into
 */
extern const uint8_t rightIntakePort;
/**
 * The port the lower manipulator motor is plugged into
 */
extern const uint8_t lowerManipulatorPort;
/**
 * The port the upper manipulator motor is plugged into
 */
extern const uint8_t upperManipulatorPort;

/**
 * The internal gearset used in the drive motors
 */
extern const motor_gearset_e_t driveGearset;
/**
 * The internal gearset used in the intake motors
 */
extern const motor_gearset_e_t intakeGearset;
/**
 * The internal gearset used in the manipulator motors
 */
extern const motor_gearset_e_t manipulatorGearset;

/**
 * The pros::Controller used to initialize the custom
 * master controller
 */
extern Controller prosMasterController;
/**
 * The pros::Controller used to initialize the custom
 * partner controller
 */
extern Controller prosPartnerController;
/**
 * The CustomController representing the partner controller
 */
extern CustomController masterController;
/**
 * The CustomController representing the master controller
 */
extern CustomController partnerController;

/**
 * The left quadrature tracking encoder
 */
extern ADIEncoder leftEncoder;
/**
 * The right quadrature tracking encoder
 */
extern ADIEncoder rightEncoder;

/**
 * The front left drive motor
 */
extern Motor frontLeftDrive;
/**
 * The front right drive motor
 */
extern Motor frontRightDrive;
/**
 * The back left drive motor
 */
extern Motor backLeftDrive;
/**
 * The back right drive motor
 */
extern Motor backRightDrive;
/**
 * The left intake motor
 */
extern Motor leftIntake;
/**
 * The right intake motor
 */
extern Motor rightIntake;
/**
 * The lower manipulator motor
 */
extern Motor lowerManipulator;
/**
 * The upper manipulator motor
 */
extern Motor upperManipulator;

#endif //PROS_OKAPI_ROBOTCONFIG_HPP
