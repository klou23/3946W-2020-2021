#include "main.h"

using namespace okapi;

#ifndef GLOBALS
#define GLOBALS

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

#endif
