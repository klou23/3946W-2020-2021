//
// Created by Kevin Lou on 3/21/21.
//

#ifndef PROS_OKAPI_INITIALIZE_HPP
#define PROS_OKAPI_INITIALIZE_HPP

#include "main.h"
#include "Globals.hpp"

extern lv_obj_t *tabview;
//auton selector
extern lv_obj_t *btnAutonRed;
extern lv_obj_t *btnAutonBlue;
extern lv_obj_t *btnAuton1;
extern lv_obj_t *btnAuton2;
extern lv_obj_t *btnAuton3;
extern lv_obj_t *btnAuton4;
extern lv_obj_t *autonDescription;
//motor temp bars
extern lv_obj_t *frontLeftDriveTempBar;
extern lv_obj_t *frontRightDriveTempBar;
extern lv_obj_t *backLeftDriveTempBar;
extern lv_obj_t *backRightDriveTempBar;
extern lv_obj_t *lowerManipulatorTempBar;
extern lv_obj_t *upperManipulatorTempBar;
extern lv_obj_t *leftIntakeTempBar;
extern lv_obj_t *rightIntakeTempBar;
//motor temp labels
extern lv_obj_t *frontLeftDriveTempLabel;
extern lv_obj_t *frontRightDriveTempLabel;
extern lv_obj_t *backLeftDriveTempLabel;
extern lv_obj_t *backRightDriveTempLabel;
extern lv_obj_t *lowerManipulatorTempLabel;
extern lv_obj_t *upperManipulatorTempLabel;
extern lv_obj_t *leftIntakeTempLabel;
extern lv_obj_t *rightIntakeTempLabel;
//motor temp styles
extern lv_style_t *greenInnerStyle;
extern lv_style_t *orangeInnerStyle;
extern lv_style_t *yellowInnerStyle;
extern lv_style_t *redInnerStyle;
//log screen
extern lv_obj_t *logPage;
extern lv_obj_t *logLabel;
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
