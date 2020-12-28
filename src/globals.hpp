#include "main.h"

using namespace okapi;

#ifndef GLOBALS
#define GLOBALS

//extern ports
extern const int frontLeftDrivePort;
extern const int frontRightDrivePort;
extern const int backLeftDrivePort;
extern const int backRightDrivePort;
extern const int leftIntakePort;
extern const int rightIntakePort;
extern const int lowerManipulatorPort;
extern const int upperManipulatorPort;

//extern controller
extern Controller controller;
extern ControllerButton btnL1;
extern ControllerButton btnL2;
extern ControllerButton btnR1;
extern ControllerButton btnR2;
extern ControllerButton btnUp;
extern ControllerButton btnDown;
extern ControllerButton btnLeft;
extern ControllerButton btnRight;
extern ControllerButton btnX;
extern ControllerButton btnB;
extern ControllerButton btnY;
extern ControllerButton btnA;

//extern motors
extern Motor frontLeftDrive;
extern Motor frontRightDrive;
extern Motor backLeftDrive;
extern Motor backRightDrive;
extern Motor leftIntake;
extern Motor rightIntake;
extern Motor lowerManipulator;
extern Motor upperManipulator;

//extern chassis controller
extern std::shared_ptr<OdomChassisController> drive;

//extern global variables
extern int auton;

//extern lvgl functions
extern lv_obj_t * createButton(lv_obj_t * parent, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height, const char * labelText, bool toggleable);
extern lv_obj_t * createButton(lv_obj_t * parent, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height, bool toggleable);
extern lv_obj_t * createLabel(lv_obj_t * parent, lv_coord_t x, lv_coord_t y, const char * text);

#endif
