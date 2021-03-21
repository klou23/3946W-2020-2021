//
// Created by Kevin Lou on 3/20/21.
//

#ifndef PROS_OKAPI_CUSTOMCONTROLLER_HPP
#define PROS_OKAPI_CUSTOMCONTROLLER_HPP

#include "Constants.hpp"
#include "main.h"

class CustomController {
public:
    Controller c;

    /**
     * Creates a custom controller object for the given pros::controller
     *
     * @param controller
     *      The pros::controller object used by the custom controller
     */
    CustomController(Controller controller);

    CustomController(const Controller &c);

    /**
	 * Checks if the controller is connected.
	 *
	 * This function uses the following values of errno when an error state is
	 * reached:
	 * EACCES - Another resource is currently trying to access the controller
	 * port.
	 *
	 * @return 1 if the controller is connected, 0 otherwise
	 */
    int32_t is_connected();

    /**
	 * Gets the battery capacity of the controller.
	 *
	 * This function uses the following values of errno when an error state is
	 * reached:
	 * EACCES - Another resource is currently trying to access the controller
	 * port.
	 *
	 * @return The controller's battery capacity
	 */
    int32_t get_battery_capacity();

    /**
	 * Gets the battery level of the controller.
	 *
	 * This function uses the following values of errno when an error state is
	 * reached:
	 * EACCES - Another resource is currently trying to access the controller
	 * port.
	 *
	 * @return The controller's battery level
	 */
    int32_t get_battery_level(void);

    /**
	 * Sets text to the controller LCD screen.
	 *
	 * @note Controller text setting is currently in beta, so continuous, fast
	 * updates will not work well.
	 *
	 * This function uses the following values of errno when an error state is
	 * reached:
	 * EACCES - Another resource is currently trying to access the controller
	 * port.
	 *
	 * @param line
	 *        The line number at which the text will be displayed [0-2]
	 * @param col
	 *        The column number at which the text will be displayed [0-14]
	 * @param str
	 *        The pre-formatted string to print to the controller
	 *
	 * \return 1 if the operation was successful or PROS_ERR if the operation
	 * failed, setting errno.
	 */
    int32_t set_text(std::uint8_t line, std::uint8_t col, const char* str);

    /**
	 * Clears an individual line of the controller screen.
	 *
	 * @note Controller text setting is currently in beta, so continuous, fast
	 * updates will not work well.
	 *
	 * This function uses the following values of errno when an error state is
	 * reached:
	 * EACCES - Another resource is currently trying to access the controller
	 * port.
	 *
	 * @param line
	 *        The line number to clear [0-2]
	 *
	 * @return 1 if the operation was successful or PROS_ERR if the operation
	 * failed, setting errno.
	 */
    int32_t clear_line(std::uint8_t line);

    /**
	 * Rumble the controller.
	 *
	 * @note Controller rumble activation is currently in beta, so continuous, fast
	 * updates will not work well.
	 *
	 * This function uses the following values of errno when an error state is
	 * reached:
	 * EACCES - Another resource is currently trying to access the controller
	 * port.
	 *
	 * @param rumble_pattern
	 *				A string consisting of the characters '.', '-', and ' ', where dots
	 *				are short rumbles, dashes are long rumbles, and spaces are pauses.
	 *				Maximum supported length is 8 characters.
	 *
	 * @return 1 if the operation was successful or PROS_ERR if the operation
	 * failed, setting errno.
	 */
    int32_t rumble(const char* rumble_pattern);

    /**
	 * Clears all of the lines on the controller screen.
	 *
	 * This function uses the following values of errno when an error state is
	 * reached:
	 * EACCES - Another resource is currently trying to access the controller
	 * port.
	 *
	 * @return 1 if the operation was successful or PROS_ERR if the operation
	 * failed, setting errno.
	 */
    int32_t clear(void);

    /**
     * Returns the analog value for the x axis of the left joystick
     *
     * @return The current reading of the analog channel with range [-1,1].
     * If the controller was not connected, then 0 is returned
     */
     double getLeftX();

    /**
    * Returns the analog value for the y axis of the left joystick
    *
    * @return The current reading of the analog channel with range [-1,1].
    * If the controller was not connected, then 0 is returned
    */
    double getLeftY();

    /**
     * Returns the analog value for the x axis of the right joystick
     *
     * @return The current reading of the analog channel with range [-1,1].
     * If the controller was not connected, then 0 is returned
     */
    double getRightX();

    /**
     * Returns the analog value for the y axis of the right joystick
     *
     * @return The current reading of the analog channel with range [-1,1].
     * If the controller was not connected, then 0 is returned
     */
    double getRightY();

    /**
     * Returns if the button is currentely pressed
     *
     * @param button
     *          An integer representing the button with the range [0,11]
     *
     * @return if the buttons on the controller is pressed.
     * If the controller was not connected, false is returned.
     */
     bool pressed(int button);
};


#endif //PROS_OKAPI_CUSTOMCONTROLLER_HPP
