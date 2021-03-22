//
// Created by Kevin Lou on 3/20/21.
//

#ifndef PROS_OKAPI_CONSTANTS_HPP
#define PROS_OKAPI_CONSTANTS_HPP

#include "main.h"

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

//colors for printing to log
extern const string COLOR_RED = "#FF0000";
extern const string COLOR_MAROON = "#800000";
extern const string COLOR_YELLOW = "#FFFF00";
extern const string COLOR_OLIVE = "#808000";
extern const string COLOR_LIME = "#00FF00";
extern const string COLOR_GREEN = "#008000";
extern const string COLOR_AQUA = "#00FFFF";
extern const string COLOR_TEAL = "#008080";
extern const string COLOR_BLUE = "#0000FF";
extern const string COLOR_NAVY = "#000080";
extern const string COLOR_FUCHSIA = "#FF00FF";
extern const string COLOR_PURPLE = "#800080";

#endif //PROS_OKAPI_CONSTANTS_HPP
