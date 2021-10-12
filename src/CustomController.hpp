/**
 * @brief Represents a vex controller
 * @details This class extends off of the pros::Controller class and has some
 * added methods to make coding easier. This class has additional methods
 * for getting the values of the joysticks and checking if the buttons are
 * pressed.
 * @author Kevin Lou
 * @date 4/19/21
 */

#ifndef ODOM_CUSTOMCONTROLLER_HPP
#define ODOM_CUSTOMCONTROLLER_HPP

#include "main.h"

class CustomController : public Controller {
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
     * Checks if the left button is pressed
     *
     * @return true if pressed, false if not
     */
    bool leftPressed();

    /**
     * Checks if the right button is pressed
     *
     * @return true if pressed, false if not
     */
    bool rightPressed();

    /**
     * Checks if the up button is pressed
     *
     * @return true if pressed, false if not
     */
    bool upPressed();

    /**
     * Checks if the down button is pressed
     *
     * @return true if pressed, false if not
     */
    bool downPressed();

    /**
     * Checks if the A button is pressed
     *
     * @return true if pressed, false if not
     */
    bool aPressed();

    /**
     * Checks if the B button is pressed
     *
     * @return true if pressed, false if not
     */
    bool bPressed();

    /**
     * Checks if the X button is pressed
     *
     * @return true if pressed, false if not
     */
    bool xPressed();

    /**
     * Checks if the Y button is pressed
     *
     * @return true if pressed, false if not
     */
    bool yPressed();

    /**
     * Checks if the R1 button is pressed
     *
     * @return true if pressed, false if not
     */
    bool r1Pressed();

    /**
     * Checks if the R2 button is pressed
     *
     * @return true if pressed, false if not
     */
    bool r2Pressed();

    /**
     * Checks if the L1 button is pressed
     *
     * @return true if pressed, false if not
     */
    bool l1Pressed();

    /**
     * Checks if the L2 button is pressed
     *
     * @return true if pressed, false if not
     */
    bool l2Pressed();
};


#endif //ODOM_CUSTOMCONTROLLER_HPP
