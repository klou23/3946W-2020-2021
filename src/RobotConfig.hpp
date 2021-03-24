//
// Created by Kevin Lou on 3/20/21.
//

#ifndef PROS_OKAPI_ROBOTCONFIG_HPP
#define PROS_OKAPI_ROBOTCONFIG_HPP

#include "Globals.hpp"

//controllers
extern Controller prosMasterController;
extern Controller prosPartnerController;

//encoders
extern ADIEncoder leftEncoder;
extern ADIEncoder rightEncoder;

//motors
extern Motor frontLeftDrive;
extern Motor frontRightDrive;
extern Motor backLeftDrive;
extern Motor backRightDrive;
extern Motor leftIntake;
extern Motor rightIntake;
extern Motor lowerManipulator;
extern Motor upperManipulator;

#endif //PROS_OKAPI_ROBOTCONFIG_HPP
