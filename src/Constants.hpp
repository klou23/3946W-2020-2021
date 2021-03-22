//
// Created by Kevin Lou on 3/20/21.
//

#ifndef PROS_OKAPI_CONSTANTS_HPP
#define PROS_OKAPI_CONSTANTS_HPP

#include "main.h"
#include "CustomController.hpp"


//gear sets
extern const motor_gearset_e_t RED_GEARSET = E_MOTOR_GEARSET_36;
extern const motor_gearset_e_t GREEN_GEARSET = E_MOTOR_GEARSET_18;
extern const motor_gearset_e_t BLUE_GEARSET = E_MOTOR_GEARSET_06;

//turning
extern const int LEFT = 0;
extern const int RIGHT = 1;

//controller buttons
extern const int BUTTON_RIGHT = 0;
extern const int BUTTON_LEFT = 1;
extern const int BUTTON_UP = 2;
extern const int BUTTON_DOWN = 3;
extern const int BUTTON_A = 4;
extern const int BUTTON_B = 5;
extern const int BUTTON_X = 6;
extern const int BUTTON_Y = 7;
extern const int BUTTON_R1 = 8;
extern const int BUTTON_R2 = 9;
extern const int BUTTON_L1 = 10;
extern const int BUTTON_L2 = 11;

#endif //PROS_OKAPI_CONSTANTS_HPP
