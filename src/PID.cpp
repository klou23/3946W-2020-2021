/**
 * @brief PID controller class
 * @details Used for calculating the PID controller output for a given
 * controller. Used in all custom PID loops.
 * @author Kevin Lou
 * @date 4/13/21
 */

#include "PID.hpp"

PID::PID(double kp, double ki, double kd, double threshold) : kp(kp), ki(ki),
         kd(kd), threshold(threshold) {
    error = 0;
    integral = 0;
    derivative = 0;
    max = 1;
}

PID::PID(double kp, double ki, double kd, double threshold, double max) :
         kp(kp), ki(ki), kd(kd), threshold(threshold), max(max){
    error = 0;
    integral = 0;
    derivative = 0;
}

void PID::start(double error) {
    reset(error);
}

void PID::update(double error) {
    derivative = error - this->error;
    integral += error;
    this->error = error;
}

double PID::getOutput() {
    return limit(kp*error + ki*integral + kd*derivative);
}

bool PID::targetReached() {
    return error < threshold;
}

double PID::limit(double val) {
    if(val > max) return max;
    if(val < -max) return -max;
    return val;
}

void PID::reset(double error) {
    this->error = error;
    derivative = 0;
    integral = 0;
}
