/**
 * @brief Represents a vex controller
 * @details This class extends off of the pros::Controller class and has some
 * added methods to make coding easier. This class has additional methods
 * for getting the values of the joysticks and checking if the buttons are
 * pressed.
 * @author Kevin Lou
 * @date 4/19/21
 */

#include "CustomController.hpp"

double CustomController::getLeftX(){
    return (double) (get_analog(ANALOG_LEFT_X)) / 127;
}

double CustomController::getLeftY(){
    return (double) (get_analog(ANALOG_LEFT_Y)) / 127;
}

double CustomController::getRightX(){
    return (double) (get_analog(ANALOG_RIGHT_X)) / 127;
}

double CustomController::getRightY(){
    return (double) (get_analog(ANALOG_RIGHT_Y)) / 127;
}

bool CustomController::leftPressed() {
    return get_digital(E_CONTROLLER_DIGITAL_LEFT);
}

bool CustomController::rightPressed() {
    return get_digital(E_CONTROLLER_DIGITAL_RIGHT);
}

bool CustomController::upPressed() {
    return get_digital(E_CONTROLLER_DIGITAL_UP);
}

bool CustomController::downPressed() {
    return get_digital(E_CONTROLLER_DIGITAL_DOWN);
}

bool CustomController::aPressed() {
    return get_digital(E_CONTROLLER_DIGITAL_A);
}

bool CustomController::bPressed() {
    return get_digital(E_CONTROLLER_DIGITAL_B);
}

bool CustomController::xPressed() {
    return get_digital(E_CONTROLLER_DIGITAL_X);
}

bool CustomController::yPressed() {
    return get_digital(E_CONTROLLER_DIGITAL_Y);
}

bool CustomController::r1Pressed() {
    return get_digital(E_CONTROLLER_DIGITAL_R1);
}

bool CustomController::r2Pressed() {
    return get_digital(E_CONTROLLER_DIGITAL_R2);
}

bool CustomController::l1Pressed() {
    return get_digital(E_CONTROLLER_DIGITAL_L1);
}

bool CustomController::l2Pressed() {
    return get_digital(E_CONTROLLER_DIGITAL_L2);
}
