#include "main.h"

using namespace okapi;
using namespace std;

#ifndef GLOBALS
#define GLOBALS

//global constants
const int LEFT = 0;
const int RIGHT = 1;

//driver control stuff
extern const bool quadraticControl;

//extern ports
extern const int frontLeftDrivePort;
extern const int frontRightDrivePort;
extern const int backLeftDrivePort;
extern const int backRightDrivePort;
extern const int leftIntakePort;
extern const int rightIntakePort;
extern const int lowerManipulatorPort;
extern const int upperManipulatorPort;

extern const int gyroPort;

//extern controller
extern Controller masterController;
extern ControllerButton masterL1;
extern ControllerButton masterL2;
extern ControllerButton masterR1;
extern ControllerButton masterR2;
extern ControllerButton masterUp;
extern ControllerButton masterDown;
extern ControllerButton masterLeft;
extern ControllerButton masterRight;
extern ControllerButton masterX;
extern ControllerButton masterB;
extern ControllerButton masterY;
extern ControllerButton masterA;

extern Controller partnerController;
extern ControllerButton partnerL1;
extern ControllerButton partnerL2;
extern ControllerButton partnerR1;
extern ControllerButton partnerR2;
extern ControllerButton partnerUp;
extern ControllerButton partnerDown;
extern ControllerButton partnerLeft;
extern ControllerButton partnerRight;
extern ControllerButton partnerX;
extern ControllerButton partnerB;
extern ControllerButton partnerY;
extern ControllerButton partnerA;


//extern motors
extern Motor frontLeftDrive;
extern Motor frontRightDrive;
extern Motor backLeftDrive;
extern Motor backRightDrive;
extern Motor leftIntake;
extern Motor rightIntake;
extern Motor lowerManipulator;
extern Motor upperManipulator;

//extern encoders
extern pros::ADIEncoder leftEncoder;
extern pros::ADIEncoder rightEncoder;

//extern motor rpms
extern const int driveSpeed;
extern const int intakeSpeed;
extern const int manipulatorSpeed;

//extern chassis controller
//extern std::shared_ptr<OdomChassisController> drive;

//extern auton variables
extern const int RED;
extern const int BLUE;
extern int autonColor;
extern int autonNum;
extern const QLength& rollerCenterDist;

extern const int linearKP;
extern const int linearKI;
extern const int linearKD;

extern const int rotationalKP;
extern const int rotationalKI;
extern const int rotationalKD;

extern void turnAngle(double angle, int direction, int speed);
extern void drive(double dist, int speed);
extern void singleScore();
extern void driveRev(double dist, int speed);

extern void prog();
extern void prog2();
extern void PDDrive(double dist, double maxVoltage, double thresholdDist, double slaveThresholdAngle, int maxWait);
extern void PDTurn(double angle, double maxVoltage, int direction, double thresholdAngle, int maxWait);
extern void strafeDist(double dist, int direction, int speed);

//extern UI components
extern lv_obj_t *tabview;
extern lv_obj_t *btnAutonRed;
extern lv_obj_t *btnAutonBlue;
extern lv_obj_t *btnAuton1;
extern lv_obj_t *btnAuton2;
extern lv_obj_t *btnAuton3;
extern lv_obj_t *btnAuton4;
extern lv_obj_t *autonDescription;

extern lv_obj_t *frontLeftDriveTempBar;
extern lv_obj_t *frontRightDriveTempBar;
extern lv_obj_t *backLeftDriveTempBar;
extern lv_obj_t *backRightDriveTempBar;
extern lv_obj_t *lowerManipulatorTempBar;
extern lv_obj_t *upperManipulatorTempBar;
extern lv_obj_t *leftIntakeTempBar;
extern lv_obj_t *rightIntakeTempBar;

extern lv_obj_t *frontLeftDriveTempLabel;
extern lv_obj_t *frontRightDriveTempLabel;
extern lv_obj_t *backLeftDriveTempLabel;
extern lv_obj_t *backRightDriveTempLabel;
extern lv_obj_t *lowerManipulatorTempLabel;
extern lv_obj_t *upperManipulatorTempLabel;
extern lv_obj_t *leftIntakeTempLabel;
extern lv_obj_t *rightIntakeTempLabel;

extern lv_style_t *greenInnerStyle;
extern lv_style_t *orangeInnerStyle;
extern lv_style_t *yellowInnerStyle;
extern lv_style_t *redInnerStyle;

//extern lvgl ops
extern lv_obj_t *createButton(lv_obj_t *parent, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height);
extern lv_obj_t *createButtonWithStyle(lv_obj_t *parent, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height, lv_style_t *releasedStyle, lv_style_t *pressedStyle);
extern lv_obj_t *createButton(lv_obj_t *parent, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height, const char * labelText);
extern lv_obj_t *createButtonWithStyle(lv_obj_t *parent, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height, lv_style_t *releasedStyle, lv_style_t *pressedStyle, const char * labelText);
extern lv_obj_t *createToggleButton(lv_obj_t *parent, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height);
extern lv_obj_t *createToggleButtonWithStyle(lv_obj_t *parent, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height, lv_style_t *pressedStyle, lv_style_t *releasedStyle, lv_style_t *togglePressedStyle, lv_style_t *toggleReleasedStyle);
extern lv_obj_t *createToggleButton(lv_obj_t *parent, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height, const char * labelText);
extern lv_obj_t *createToggleButtonWithStyle(lv_obj_t *parent, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height, lv_style_t *pressedStyle, lv_style_t *releasedStyle, lv_style_t *togglePressedStyle, lv_style_t *toggleReleasedStyle, const char * labelText);
extern lv_obj_t *createLabel(lv_obj_t *parent, lv_coord_t x, lv_coord_t y, const char * text);
extern void createButtonStyle(lv_style_t *style, uint8_t bodyR, uint8_t bodyG, uint8_t bodyB, uint8_t borderR, uint8_t borderG, uint8_t borderB, int radius, int borderWeight, uint8_t textR, uint8_t textG, uint8_t textB);
extern void createBarOutsideStyle(lv_style_t *style, int radius, uint8_t r, uint8_t g, uint8_t b);
extern void createBarInsideStyle(lv_style_t *style, int radius, uint8_t r, uint8_t g, uint8_t b, int padding);
extern lv_obj_t *createBar(lv_obj_t *parent, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height, int16_t min, int16_t max);
extern lv_obj_t *createBarWithStyle(lv_obj_t *parent, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height, int16_t min, int16_t max, lv_style_t *innerStyle, lv_style_t *outerStyle);

//extern lvgl funcs
extern lv_res_t setAutonRed(lv_obj_t *button);
extern lv_res_t setAutonBlue(lv_obj_t *button);
extern lv_res_t setAuton1(lv_obj_t *button);
extern lv_res_t setAuton2(lv_obj_t *button);
extern lv_res_t setAuton3(lv_obj_t *button);
extern lv_res_t setAuton4(lv_obj_t *button);

#endif
