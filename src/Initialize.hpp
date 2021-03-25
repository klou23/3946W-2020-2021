/**
 * @file
 * @brief Creates the UI on the brain screen
 */

#ifndef PROS_OKAPI_INITIALIZE_HPP
#define PROS_OKAPI_INITIALIZE_HPP

#include "Globals.hpp"

/**
 * Tabview that holds the UI.
 */
extern lv_obj_t *tabview;

/**
 * Button for changing the auton color to red.
 */
extern lv_obj_t *btnAutonRed;
/**
 * Button for changing the auton color to blue.
 */
extern lv_obj_t *btnAutonBlue;
/**
 * Button for changing the current auton to 1.
 */
extern lv_obj_t *btnAuton1;
/**
 * Button for changing the current auton to 2.
 */
extern lv_obj_t *btnAuton2;
/**
 * Button for changing the current auton to 3.
 */
extern lv_obj_t *btnAuton3;
/**
 * Button for changing the current auton to 4.
 */
extern lv_obj_t *btnAuton4;
/**
 * Label for displaying a description of the
 * currently selected auton.
 */
extern lv_obj_t *autonDescription;


/**
 * Bar for displaying the temperature of the
 * front left drive motor
 */
extern lv_obj_t *frontLeftDriveTempBar;
/**
 * Bar for displaying the temperature of the
 * front right drive motor.
 */
extern lv_obj_t *frontRightDriveTempBar;
/**
 * Bar for displaying the temperature of the
 * back left drive motor.
 */
extern lv_obj_t *backLeftDriveTempBar;
/**
 * Bar for displaying the temperature of the
 * back right drive motor
 */
extern lv_obj_t *backRightDriveTempBar;
/**
 * Bar for displaying the temperature of the
 * lower manipulator motor
 */
extern lv_obj_t *lowerManipulatorTempBar;
/**
 * Bar for displaying the temperature of the
 * upper manipulator motor.
 */
extern lv_obj_t *upperManipulatorTempBar;
/**
 * Bar for displaying the temperature of the
 * left intake motor
 */
extern lv_obj_t *leftIntakeTempBar;
/**
 * Bar for displaying the temperature of the
 * right intake motor
 */
extern lv_obj_t *rightIntakeTempBar;

/**
 * Label for displaying the temperature of the
 * front left drive motor.
 */
extern lv_obj_t *frontLeftDriveTempLabel;
/**
 * Label for displaying the temperature of the
 * front right drive motor.
 */
extern lv_obj_t *frontRightDriveTempLabel;
/**
 * Label for displaying the temperature of the
 * back left drive motor.
 */
extern lv_obj_t *backLeftDriveTempLabel;
/**
 * Label for displaying the temperature of the
 * back right drive motor.
 */
extern lv_obj_t *backRightDriveTempLabel;
/**
 * Label for displaying the temperature of the
 * lower manipulator motor.
 */
extern lv_obj_t *lowerManipulatorTempLabel;
/**
 * Label for displaying the temperature of the
 * upper manipulator motor.
 */
extern lv_obj_t *upperManipulatorTempLabel;
/**
 * Label for displaying the temperature of the
 * left intake motor.
 */
extern lv_obj_t *leftIntakeTempLabel;
/**
 * Label for displaying the temperature of the
 * right intake motor.
 */
extern lv_obj_t *rightIntakeTempLabel;

/**
 * Green colored inner style for the motor
 * temperature bars
 */
extern lv_style_t *greenInnerStyle;
/**
 * Orange colored inner style for the motor
 * temperature bars
 */
extern lv_style_t *orangeInnerStyle;
/**
 * Yellow colored inner style for the motor
 * temperature bars
 */
extern lv_style_t *yellowInnerStyle;
/**
 * Red colored inner style for the motor
 * temperature bars
 */
extern lv_style_t *redInnerStyle;

/**
 * Scrolling page where the log screen
 * is located on
 */
extern lv_obj_t *logPage;
/**
 * Label that is used to display the log data
 * onto the screen
 */
extern lv_obj_t *logLabel;
/**
 * String representation of the text displayed
 * on the log screen
 */
extern string logText;

//Functions

/**
 * Creates an auton selector tab
 *
 * @param parent
 *          An lvgl page that the auton selector is created on
 */
void createAutonSelectorTab(lv_obj_t *parent);

/**
 * Creates a motor temperature monitoring tab
 *
 * @param parent
 *          An lvgl page that the motor temperature monitor is created on
 */
void createMotorTempTab(lv_obj_t *parent);

/**
 * Creates a new log tab
 *
 * @param parent
 *      An lvgl page that the log is created on
 */
void createLogTab(lv_obj_t *parent);

#endif //PROS_OKAPI_INITIALIZE_HPP
