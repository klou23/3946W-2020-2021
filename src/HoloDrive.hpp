/**
 * @brief Represents a holonomic drive for controlling the drive in both
 * autonomous and driver control.
 * @details This class represents either an X-drive or a mecanum drive and
 * contains methods for drive control using odometry and pure pursuit for
 * autonomous and a method for controlling the drive during driver control.
 * @author Kevin Lou
 * @date 4/19/21
 */

#ifndef ODOM_HOLODRIVE_HPP
#define ODOM_HOLODRIVE_HPP

#include "main.h"
#include "Encoder.hpp"
#include "PID.hpp"
#include "PathState.hpp"

class HoloDrive {
private:

    /**
     * Front left drive motor
     */
    Motor frontLeft;

    /**
     * Front right drive motor
     */
    Motor frontRight;

    /**
     * Back left drive motor
     */
    Motor backLeft;

    /**
     * Back right drive motor
     */
    Motor backRight;

    /**
     * Left tracking encoder
     */
    Encoder leftEncoder;

    /**
     * Right tracking encoder
     */
    Encoder rightEncoder;

    /**
     * Back tracking encoder
     */
    Encoder backEncoder;

    /**
     * PID controller for x movement
     */
    PID xPID;

    /**
     * PID controller for y movement
     */
    PID yPID;

    /**
     * PID controller for turning
     */
    PID turnPID;

    /**
     * Diameter of the tracking wheels
     */
    double wheelDiam;

    /**
     * Distance from the center of rotation of the robot to the left tracking
     * wheel
     */
    double leftDist;

    /**
     * Distance from the center of rotation of the robot to the right
     * tracking wheel
     */
    double rightDist;

    /**
     * Distance from the center of rotation of the robot to the back tracking
     * wheel
     */
    double backDist;

    /**
     * X position of the robot on the field
     */
    double robotX;

    /**
     * Y Position of the robot on the field
     */
    double robotY;

    /**
     * Heading of the robot on the field
     */
    double robotTheta;

    /**
     * Look ahead distance for pure pursuit
     */
     double lookAheadDist;

public:

    /**
     * Creates a new instance of HoloDrive
     *
     * @param frontLeft
     *          Front left drive motor
     * @param frontRight
     *          Front right drive motor
     * @param backLeft
     *          Back left drive motor
     * @param backRight
     *          Back right drive motor
     * @param leftEncoder
     *          Left tracking encoder
     * @param rightEncoder
     *          Right tracking encoder
     * @param backEncoder
     *          Back tracking encoder
     * @param xPid
     *          X-directional PID controller
     * @param yPid
     *          Y-directional PID controller
     * @param turnPid
     *          turning PID controller
     */
    HoloDrive(const Motor &frontLeft, const Motor &frontRight,
              const Motor &backLeft, const Motor &backRight,
              const Encoder &leftEncoder, const Encoder &rightEncoder,
              const Encoder &backEncoder, const PID &xPid, const PID &yPid,
              const PID &turnPid);

    /**
     * Sets the values of the chassis information
     *
     * @param leftDist
     *          Distance from center of rotation to the left encoder
     * @param rightDist
     *          Distance from center of rotation to the right encoder
     * @param backDist
     *          Distance from center of rotation to the back encoder
     * @param wheelDiam
     *          Diameter of tracking wheels
     * @param lookAheadDist
     *          Look-ahead distance for pure pursuit
     */
    void setChassisInfo(double leftDist, double rightDist, double backDist,
                        double wheelDiam, double lookAheadDist);

    /**
     * Sets the positioning state of the robot
     *
     * @param x
     *          X-position of the robot
     * @param y
     *          Y-position of the robot
     * @param theta
     *          Heading of the robot
     */
    void setState(double x, double y, double theta);

    /**
     * Updates the position of the drive using odometry.
     *
     * @note This method assumes that the drive is moving at a constant
     * velocity, which isn't true, but it is accurate enough if this method
     * is called pretty often.
     */
    void updatePosition();

    /**
     * Stops all 4 drive motors
     */
    void stop();

    /**
     * Runs the drive with the given inputs
     *
     * @param x
     *          X value. Range: [-1,1]
     * @param y
     *          Y value. Range: [-1,1]
     * @param turn
     *          Turn value. Range: [-1,1]
     */
    void control(double x, double y, double turn);

    /**
     * Drives to a position and orientation (orientation is optional) on the
     * field.
     *
     * @param p
     *          The path state to drive to
     */
    void driveTo(PathState p);

    /**
     * Drives to a position on the field
     *
     * @param x
     *          X-coordinate of target position
     * @param y
     *          Y-coordinate of target position
     */
    void driveTo(double x, double y);

    /**
     * Drives to a position and orientation on the field
     *
     * @param x
     *          X-coordinate of target position
     * @param y
     *          Y-coordinate of target position
     * @param theta
     *          Target heading
     */
    void driveTo(double x, double y, double theta);

    /**
     * Uses a pure pursuit algorithm to follow a path
     *
     * @param p
     *          The path to be followed
     */
    void purePursuit(Path p);
};


#endif //ODOM_HOLODRIVE_HPP
