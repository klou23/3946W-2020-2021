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

//extern auton variables
extern const int RED;
extern const int BLUE;
extern int autonColor;
extern int autonNum;

//extern lvgl ops
extern lv_obj_t * createButton(lv_obj_t * parent, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height);
extern lv_obj_t * createButtonWithStyle(lv_obj_t * parent, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height, lv_style_t releasedStyle, lv_style_t pressedStyle);
extern lv_obj_t * createButton(lv_obj_t * parent, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height, const char * labelText);
extern lv_obj_t * createButtonWithStyle(lv_obj_t * parent, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height, lv_style_t releasedStyle, lv_style_t pressedStyle, const char * labelText);
extern lv_obj_t * createToggleButton(lv_obj_t * parent, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height);
extern lv_obj_t * createToggleButtonWithStyle(lv_obj_t * parent, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height, lv_style_t pressedStyle, lv_style_t releasedStyle, lv_style_t togglePressedStyle, lv_style_t toggleReleasedStyle);
extern lv_obj_t * createToggleButton(lv_obj_t * parent, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height, const char * labelText);
extern lv_obj_t * createToggleButtonWithStyle(lv_obj_t * parent, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height, lv_style_t pressedStyle, lv_style_t releasedStyle, lv_style_t togglePressedStyle, lv_style_t toggleReleasedStyle, const char * labelText);
extern lv_obj_t * createLabel(lv_obj_t * parent, lv_coord_t x, lv_coord_t y, const char * text);
extern lv_style_t createButtonStyle(uint8_t bodyR, uint8_t bodyG, uint8_t bodyB, uint8_t borderR, uint8_t borderG, uint8_t borderB, int radius, int borderWeight, uint8_t textR, uint8_t textG, uint8_t textB);

//extern lvgl funcs
extern lv_res_t setAutonRed(lv_obj_t * button);
extern lv_res_t setAutonBlue(lv_obj_t * button);
extern lv_res_t setAuton1(lv_obj_t * button);
extern lv_res_t setAuton2(lv_obj_t * button);
extern lv_res_t setAuton3(lv_obj_t * button);
extern lv_res_t setAuton4(lv_obj_t * button);

#endif
