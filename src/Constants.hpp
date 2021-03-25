/**
 * @file
 * @brief A list of constants used as enums or for ease of typing.
 */

#ifndef PROS_OKAPI_CONSTANTS_HPP
#define PROS_OKAPI_CONSTANTS_HPP

#include "Globals.hpp"

/**
 * Represents the 100 rpm gearset. Used for motor setup.
 */
extern const motor_gearset_e_t RED_GEARSET = E_MOTOR_GEARSET_36;
/**
 * Represents the 200 rpm gearset. Used for motor setup.
 */
extern const motor_gearset_e_t GREEN_GEARSET = E_MOTOR_GEARSET_18;
/**
 * Represents the 600 rpm gearset. Used for motor setup.
 */
extern const motor_gearset_e_t BLUE_GEARSET = E_MOTOR_GEARSET_06;


/**
 * Represents the direction left. Used for auton turning
 * and strafing.
 */
extern const int LEFT = 0;
/**
 * Represents the direction right. Used for auton turning
 * and strafing
 */
extern const int RIGHT = 1;


/**
 * Represents the right arrow button on the controller.
 * Used for getting controller feedback.
 */
extern const int BUTTON_RIGHT = 0;
/**
 * Represents the left arrow button on the controller.
 * Used for getting controller feedback.
 */
extern const int BUTTON_LEFT = 1;
/**
 * Represents the up arrow button on the controller.
 * Used for getting controller feedback.
 */
extern const int BUTTON_UP = 2;
/**
 * Represents the down arrow button on the controller.
 * Used for getting controller feedback.
 */
extern const int BUTTON_DOWN = 3;
/**
 * Represents the 'A' button on the controller.
 * Used for getting controller feedback.
 */
extern const int BUTTON_A = 4;
/**
 * Represents the 'B' button on the controller.
 * Used for getting controller feedback.
 */
extern const int BUTTON_B = 5;
/**
 * Represents the 'X' button on the controller.
 * Used for getting controller feedback.
 */
extern const int BUTTON_X = 6;
/**
 * Represents the 'Y' button on the controller.
 * Used for getting controller feedback.
 */
extern const int BUTTON_Y = 7;
/**
 * Represents the top right trigger on the controller.
 * Used for getting controller feedback.
 */
extern const int BUTTON_R1 = 8;
/**
 * Represents the bottom right trigger on the controller.
 * Used for getting controller feedback.
 */
extern const int BUTTON_R2 = 9;
/**
 * Represents the top left trigger on the controller.
 * Used for getting controller feedback.
 */
extern const int BUTTON_L1 = 10;
/**
 * Represents the bottom left trigger on the controller.
 * Used for getting controller feedback.
 */
extern const int BUTTON_L2 = 11;


/**
 * Represents the color red. Used for printing text
 * to the log.
 */
extern const string PRINT_RED = "#FF0000";
/**
 * Represents the color maroon. Used for printing text
 * to the log.
 */
extern const string PRINT_MAROON = "#800000";
/**
 * Represents the color yellow. Used for printing text
 * to the log.
 */
extern const string PRINT_YELLOW = "#FFFF00";
/**
 * Represents the color olive. Used for printing text
 * to the log.
 */
extern const string PRINT_OLIVE = "#808000";
/**
 * Represents the color lime. Used for printing text
 * to the log.
 */
extern const string PRINT_LIME = "#00FF00";
/**
 * Represents the color green. Used for printing text
 * to the log.
 */
extern const string PRINT_GREEN = "#008000";
/**
 * Represents the color aqua. Used for printing text
 * to the log.
 */
extern const string PRINT_AQUA = "#00FFFF";
/**
 * Represents the color teal. Used for printing text
 * to the log.
 */
extern const string PRINT_TEAL = "#008080";
/**
 * Represents the color blue. Used for printing text
 * to the log.
 */
extern const string PRINT_BLUE = "#0000FF";
/**
 * Represents the color navy. Used for printing text
 * to the log.
 */
extern const string PRINT_NAVY = "#000080";
/**
 * Represents the color fuchsia. Used for printing text
 * to the log.
 */
extern const string PRINT_FUCHSIA = "#FF00FF";
/**
 * Represents the color purple. Used for printing text
 * to the log.
 */
extern const string PRINT_PURPLE = "#800080";


/**
 * Represents the blue side for auton. Used in
 * autonomous selection.
 */
extern const int AUTON_BLUE = 0;
/**
 * Represents the red side for auton. Used in
 * autonomous selection
 */
extern const int AUTON_RED = 0;

#endif //PROS_OKAPI_CONSTANTS_HPP
