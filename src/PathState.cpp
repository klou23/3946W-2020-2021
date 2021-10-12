/**
 * @brief Holds a state for the robot's drive.
 * @details Stores the drive state with three values: x, y, theta. Theta is
 * an optional value. This class can also be used as a point class.
 * @author Kevin Lou
 * @date 4/17/21
 */

#include "PathState.hpp"

PathState::PathState(double x, double y) : x(x), y(y) {
    theta = 0;
    turn = false;
}

PathState::PathState(double x, double y, double theta) : x(x), y(y),
                                                         theta(theta) {
    turn = true;
}

double PathState::getX() const {
    return x;
}

double PathState::getY() const {
    return y;
}

double PathState::getTheta() const {
    return theta;
}

bool PathState::isTurn() const {
    return turn;
}
