//
// Created by Kevin Lou on 3/20/21.
//

#include "CustomController.hpp"
#include "Constants.hpp"

CustomController::CustomController(Controller c) : c(c) {}

int32_t CustomController::is_connected(){
    return c.is_connected();
}

int32_t CustomController::get_battery_capacity(){
    return c.get_battery_capacity();
}

int32_t CustomController::get_battery_level(void){
    return c.get_battery_level();
}

int32_t CustomController::set_text(std::uint8_t line, std::uint8_t col, const char* str){
    return c.set_text(line, col, str);
}

int32_t CustomController::clear_line(std::uint8_t line){
    return c.clear_line(line);
}

int32_t CustomController::rumble(const char* rumble_pattern){
    return c.rumble(rumble_pattern);
}

int32_t CustomController::clear(void){
    return c.clear();
}

double CustomController::getLeftX(){
    return (double) (c.get_analog(ANALOG_LEFT_X)) / 127;
}

double CustomController::getLeftY(){
    return (double) (c.get_analog(ANALOG_LEFT_Y)) / 127;
}

double CustomController::getRightX(){
    return (double) (c.get_analog(ANALOG_RIGHT_X)) / 127;
}

double CustomController::getRightY(){
    return (double) (c.get_analog(ANALOG_RIGHT_Y)) / 127;
}

bool CustomController::pressed(int button){
    int32_t returnVal = 0;
    switch (button){
        case BUTTON_LEFT:
            returnVal = c.get_digital(E_CONTROLLER_DIGITAL_LEFT);
            break;
        case BUTTON_RIGHT:
            returnVal = c.get_digital(E_CONTROLLER_DIGITAL_RIGHT);
            break;
        case BUTTON_UP:
            returnVal = c.get_digital(E_CONTROLLER_DIGITAL_UP);
            break;
        case BUTTON_DOWN:
            returnVal = c.get_digital(E_CONTROLLER_DIGITAL_DOWN);
            break;
        case BUTTON_A:
            returnVal = c.get_digital(E_CONTROLLER_DIGITAL_A);
            break;
        case BUTTON_B:
            returnVal = c.get_digital(E_CONTROLLER_DIGITAL_B);
            break;
        case BUTTON_X:
            returnVal = c.get_digital(E_CONTROLLER_DIGITAL_X);
            break;
        case BUTTON_Y:
            returnVal = c.get_digital(E_CONTROLLER_DIGITAL_Y);
            break;
        case BUTTON_R1:
            returnVal = c.get_digital(E_CONTROLLER_DIGITAL_R1);
            break;
        case BUTTON_R2:
            returnVal = c.get_digital(E_CONTROLLER_DIGITAL_R2);
            break;
        case BUTTON_L1:
            returnVal = c.get_digital(E_CONTROLLER_DIGITAL_L1);
            break;
        case BUTTON_L2:
            returnVal = c.get_digital(E_CONTROLLER_DIGITAL_L2);
            break;
    }
    return returnVal == 1;
}
