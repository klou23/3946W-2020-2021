/**
 * @brief PID controller class
 * @details Used for calculating the PID controller output for a given
 * controller. Used in all custom PID loops.
 * @author Kevin Lou
 * @date 4/13/21
 */

#ifndef ODOM_PID_HPP
#define ODOM_PID_HPP

#include "main.h"

class PID {

private:

    /**
     * Proportional constant
     */
    double kp;

    /**
     * Integral constant
     */
    double ki;

    /**
     * Derivative constant
     */
    double kd;

    /**
     * Threshold error for motion
     */
    double threshold;

    /**
     * Current error from target
     */
    double error;

    /**
     * Integral from t=0 to now of the error
     */
    double integral;

    /**
     * Derivative of the error
     */
    double derivative;

    /**
     * Absolute value of maximum return value. Should be a positive
     * value. Default is 1
     */
    double max;

    /**
     * Ensures that the value is between the min and max values of the
     * controller
     *
     * @param val
     *          The value to be checked
     * @return
     *          A new value that guaranteed to be within the min and max
     */
    double limit(double val);

public:

    /**
     * Creates a new instance of PID with the given PID constants and the
     * given PID threshold.
     *
     * @param kp
     *          Proportional constant
     * @param ki
     *          Integral constant
     * @param kd
     *          Derivative constant
     * @param threshold
     *          Error threshold
     */
    PID(double kp, double ki, double kd, double threshold);

    /**
     * Creates a new instance of PID with the given PID constants and the
     * given PID threshold, along with upper and lower bounds for the return
     * value
     *
     * @param kp
     *          Proportional constant
     * @param ki
     *          Integral constant
     * @param kd
     *          Derivative constant
     * @param threshold
     *          Error threshold
     * @param min
     *          Minimum return value
     * @param max
     *          Maximum return value
     */
    PID(double kp, double ki, double kd, double threshold, double max);

    /**
     * Sets an initial error value to use for PID
     *
     * @param error
     *          initial error
     */
    void start(double error);

    /**
     * Resets the derivative and integrals and sets a new initial error value
     *
     * @param error
     */
    void reset(double error);

    /**
     * Updates the controller with a new error value
     *
     * @param error
     */
    void update(double error);

    /**
     * Calculates the output value of the PID controller
     *
     * @return the output value
     */
    double getOutput();

    /**
     * Checks if the controller is within its threshold error
     *
     * @return whether or not the error is within the threshold
     */
    bool targetReached();


};


#endif //ODOM_PID_HPP
