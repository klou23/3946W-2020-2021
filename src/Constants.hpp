/**
 * @file
 * @brief A list of constants used as enums or for ease of typing.
 */

#ifndef PROS_OKAPI_CONSTANTS_HPP
#define PROS_OKAPI_CONSTANTS_HPP

#include "main.h"

/**
 * Represents the 100 rpm gearset. Used for motor setup.
 */
extern const motor_gearset_e_t RED_GEARSET;
/**
 * Represents the 200 rpm gearset. Used for motor setup.
 */
extern const motor_gearset_e_t GREEN_GEARSET;
/**
 * Represents the 600 rpm gearset. Used for motor setup.
 */
extern const motor_gearset_e_t BLUE_GEARSET;


/**
 * Represents the direction left. Used for auton turning
 * and strafing.
 */
extern const int LEFT;
/**
 * Represents the direction right. Used for auton turning
 * and strafing
 */
extern const int RIGHT;


/**
 * Represents the right arrow button on the controller.
 * Used for getting controller feedback.
 */
extern const int BUTTON_RIGHT;
/**
 * Represents the left arrow button on the controller.
 * Used for getting controller feedback.
 */
extern const int BUTTON_LEFT;
/**
 * Represents the up arrow button on the controller.
 * Used for getting controller feedback.
 */
extern const int BUTTON_UP;
/**
 * Represents the down arrow button on the controller.
 * Used for getting controller feedback.
 */
extern const int BUTTON_DOWN;
/**
 * Represents the 'A' button on the controller.
 * Used for getting controller feedback.
 */
extern const int BUTTON_A;
/**
 * Represents the 'B' button on the controller.
 * Used for getting controller feedback.
 */
extern const int BUTTON_B;
/**
 * Represents the 'X' button on the controller.
 * Used for getting controller feedback.
 */
extern const int BUTTON_X;
/**
 * Represents the 'Y' button on the controller.
 * Used for getting controller feedback.
 */
extern const int BUTTON_Y;
/**
 * Represents the top right trigger on the controller.
 * Used for getting controller feedback.
 */
extern const int BUTTON_R1;
/**
 * Represents the bottom right trigger on the controller.
 * Used for getting controller feedback.
 */
extern const int BUTTON_R2;
/**
 * Represents the top left trigger on the controller.
 * Used for getting controller feedback.
 */
extern const int BUTTON_L1;
/**
 * Represents the bottom left trigger on the controller.
 * Used for getting controller feedback.
 */
extern const int BUTTON_L2;


/**
 * Represents the color red. Used for printing text
 * to the log.
 */
extern const string PRINT_RED;
/**
 * Represents the color orange. Used for printing text
 * to the log.
 */
extern const string PRINT_ORANGE;
/**
 * Represents the color maroon. Used for printing text
 * to the log.
 */
extern const string PRINT_MAROON;
/**
 * Represents the color yellow. Used for printing text
 * to the log.
 */
extern const string PRINT_YELLOW;
/**
 * Represents the color olive. Used for printing text
 * to the log.
 */
extern const string PRINT_OLIVE;
/**
 * Represents the color lime. Used for printing text
 * to the log.
 */
extern const string PRINT_LIME;
/**
 * Represents the color green. Used for printing text
 * to the log.
 */
extern const string PRINT_GREEN;
/**
 * Represents the color aqua. Used for printing text
 * to the log.
 */
extern const string PRINT_AQUA;
/**
 * Represents the color teal. Used for printing text
 * to the log.
 */
extern const string PRINT_TEAL;
/**
 * Represents the color blue. Used for printing text
 * to the log.
 */
extern const string PRINT_BLUE;
/**
 * Represents the color navy. Used for printing text
 * to the log.
 */
extern const string PRINT_NAVY;
/**
 * Represents the color fuchsia. Used for printing text
 * to the log.
 */
extern const string PRINT_FUCHSIA;
/**
 * Represents the color purple. Used for printing text
 * to the log.
 */
extern const string PRINT_PURPLE;


/**
 * Represents the blue side for auton. Used in
 * autonomous selection.
 */
extern const int AUTON_BLUE;
/**
 * Represents the red side for auton. Used in
 * autonomous selection
 */
extern const int AUTON_RED;

#endif //PROS_OKAPI_CONSTANTS_HPP
