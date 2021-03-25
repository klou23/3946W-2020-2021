/**
 * @file
 * @brief Drive class for all drive operations
 */

#ifndef PROS_OKAPI_DRIVE_HPP
#define PROS_OKAPI_DRIVE_HPP

#include "Globals.hpp"

class Drive {
    //TODO: future implementation of some sort of odometry
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
     * Left quadrature encoder
     */
    ADIEncoder leftEncoder;

    /**
     * Right quadrature encoder
     */
    ADIEncoder rightEncoder;

    /**
     * Proportional constant for driving forward
     */
    double masterKp;

    /**
     * Integral constant for driving forward
     */
    double masterKi;

    /**
     * Derivative constant for driving forward
     */
    double masterKd;

    /**
     * Maximum error to leave driving PID loop
     */
    double masterThreshold;

    /**
     * Proportional constant for drift correction
     */
    double slaveKp;

    /**
     * Integral constant for drift correction
     */
    double slaveKi;

    /**
     * Derivative constant for drift correction
     */
    double slaveKd;

    /**
     * Proportional constant for turning
     */
    double turnK;

    /**
     * Integral constant for turning
     */
    double turnKi;

    /**
     * Derivative constant for turning
     */
    double turnKd;

    /**
     * Maxiumum error to leave turning PID loop
     */
    double turnThreshold;

    /**
     * Scale factor to convert form inches to drive linearly to
     * degree rotations on the tracking wheels
     */
    double driveScale;

    /**
     * Scale factor to convert from degrees to turn to degree
     * rotations on the tracking wheels
     */
    double turnScale;

    /**
     * Scale factor to convert from inches to drive linearly to
     * degree rotations on the internal motor encoders
     */
    double oldDriveScale;

    /**
     * Scale factor to convert from degrees to turn to degree
     * rotations on the internal motor encoders
     */
     double oldTurnScale;

     /**
      * Scale factor to convert from inches to strafe to
      * degree rotations on the internal motor encoders
      */
     double oldStrafeScale;

     /**
      * Waits for all four of the drive motors to reach
      * their target positions for the old auton functions
      */
     void waitForMotors();

     /**
      * Wait for all four of the drive motors to reach
      * their target positions for the old auton functions
      *
      * @param maxWait
      *         The maximum time to wait for the drive to reach the
      *         target in milliseconds
      */
     void waitForMotors(int maxWait);

     /**
      * Ensures that the absolute value of the voltage is
      * under the maximum voltage
      *
      * @param voltage
      *         The inputed voltage in millivolts
      * @param maxVoltage
      *         The maximum absolute value of the voltage
      * @return The new voltage that is guaranteed to have
      *         an absolute value lower than the maximum
      *         voltage.
      */
     double capVoltage(double voltage, double maxVoltage);

public:
    /**
     * Creates a drive object given the four motors
     *
     * @param frontLeft
     *          pros::Motor to act as the front left motor
     * @param frontRight
     *          pros::Motor to act as the front right motor
     * @param backLeft
     *          pros::Motor to act as the back left motor
     * @param backRight
     *          pros::Motor to act as the back right motor
     * @param leftEncoder
     *          pros::ADIEncoder to act as the left quadrature encoder
     * @param rightEncoder
     *          pros::ADIEncoder to act as the right quadrature encoder
     */
    Drive(const Motor &frontLeft, const Motor &frontRight, const Motor &backLeft, const Motor &backRight,
          const ADIEncoder &leftEncoder, const ADIEncoder &rightEncoder);

    /**
     * Uses basic motor control to drive some distance forward/backward
     *
     * @note the drive method using PID is more accurate than this method
     *
     * @param dist
     *          The distance that the robot drives. If this value is
     *          positive, the robot will drive forward. If this value
     *          is negative, the robot will drive backward
     * @param speed
     *          The maximum velocity for the drive motors to run
     *          in rotations per minute
     */
    void oldDrive(double dist, double speed);

    /**
     * Uses basic motor control to drive some distance forward/backward
     *
     * @note the drive method using PID is more accurate than this method
     *
     * @param dist
     *          The distance that the robot drives. If this value is
     *          positive, the robot will drive forward. If this value
     *          is negative, the robot will drive backward
     * @param speed
     *          The maximum velocity for the drive motors to run
     *          in rotations per minute
     * @param maxWait
     *          The maximum time to wait for the drive to reach the
     *          target in milliseconds
     */
    void oldDrive(double dist, double speed, int maxWait);

    /**
     * Uses basic motor control to turn some angle left/right
     *
     * @note the turn method using PID is more accurate than this method
     *
     * @param angle
     *          The angle that the robot turns. This value should
     *          be a positive number
     * @param speed
     *          The maximum velocity for the drive motors to run
     *          in rotations per minute
     * @param direction
     *          An integer representing the direction to turn. Can
     *          be either LEFT(0) or RIGHT(1)
     */
    void oldTurn(double angle, double speed, int direction);

    /**
     * Uses basic motor control to turn some angle left/right
     *
     * @note the turn method using PID is more accurate than this method
     *
     * @param angle
     *          The angle that the robot turns. This value should
     *          be a positive number
     * @param speed
     *          The maximum velocity for the drive motors to run
     *          in rotations per minute
     * @param direction
     *          An integer representing the direction to turn. Can
     *          be either LEFT(0) or RIGHT(1)
     * @param maxWait
     *          The maximum time to wait for the drive to reach the
     *          target in milliseconds
     */
    void oldTurn(double angle, double speed, int direction, int maxWait);

    /**
     * Uses basic motor control to strafe some distance left/right
     *
     * @note Strafing results in a lot of drift
     *
     * @param dist
     *          The distance that the robot strafes. This value
     *          should be a positive number.
     * @param speed
     *          The maximum velocity for the drive motors to run
     *          in rotations per minute
     * @param direction
     *          An integer representing the direction to strafe. Can
     *          be either LEFT(0) or RIGHT(1)
     */
    void oldStrafe(double dist, double speed, int direction);

    /**
     * Uses basic motor control to strafe some distance left/right
     *
     * @note Strafing results in a lot of drift
     *
     * @param dist
     *          The distance that the robot strafes. This value
     *          should be a positive number.
     * @param speed
     *          The maximum velocity for the drive motors to run
     *          in rotations per minute
     * @param direction
     *          An integer representing the direction to strafe. Can
     *          be either LEFT(0) or RIGHT(1)
     * @param maxWait
     *          The maximum time to wait for the drive to reach the
     *          target in milliseconds
     */
    void oldStrafe(double dist, double speed, int direction, int maxWait);

    /**
     * Uses PID control and drift correction to drive some distance
     * forward/backward
     *
     * @param dist
     *          The distance that the robot drives. If this value is
     *          positive, the robot will drive forward. If this value
     *          is negative, the robot will drive backward.
     * @param maxVoltage
     *          The maximum voltage to run the drive motors in
     *          millivolts. If this value is too low, the robot will
     *          not move. This value should be between 0 and 11000.
     */
    void drive(double dist, double maxVoltage);

    /**
     * Uses PID control and drift correction to drive some distance
     * forward/backward
     *
     * @param dist
     *          The distance that the robot drives. If this value is
     *          positive, the robot will drive forward. If this value
     *          is negative, the robot will drive backward.
     * @param maxVoltage
     *          The maximum voltage to run the drive motors in
     *          millivolts. If this value is too low, the robot will
     *          not move. This value should be between 0 and 11000.
     * @param maxWait
     *          The maximum time to wait for the drive to reach the
     *          target in milliseconds.
     */
    void drive(double dist, double maxVoltage, int maxWait);

    /**
     * Uses PID control to turn some angle left/right
     *
     * @param angle
     *          The angle that the robot turns. This value should
     *          be a positive number
     * @param maxVoltage
     *          The maximum voltage to run the drive motors in
     *          millivolts. If this value is too low, the robot will
     *          not move. This value should be between 0 and 11000.
     * @param direction
     *          An integer representing the direction to turn. Can
     *          be either LEFT(0) or RIGHT(1)
     */
    void turn(double angle, double maxVoltage, int direction);

    /**
     * Uses PID control to turn some angle left/right
     *
     * @param angle
     *          The angle that the robot turns. This value should
     *          be a positive number
     * @param maxVoltage
     *          The maximum voltage to run the drive motors in
     *          millivolts. If this value is too low, the robot will
     *          not move. This value should be between 0 and 11000.
     * @param direction
     *          An integer representing the direction to turn. Can
     *          be either LEFT(0) or RIGHT(1)
     * @param maxWait
     *          The maximum time to wait for the drive to reach the
     *          target in milliseconds.
     */
    void turn(double angle, double maxVoltage, int direction, int maxWait);

    /**
     * Sets the motor velocities of the drive based on the passed in
     * controller values for the driver control period
     *
     * @param leftX
     *          The x position of the left joystick on the controller.
     *          Should be in the range [-1,1]
     * @param leftY
     *          The y position of the left joystick on the controller.
     *          Should be in the range [-1,1]
     * @param rightX
     *          The x position of the right joystick on the controller.
     *          Should be in the range [-1,1]
     */
    void driverControl(double leftX, double leftY, double rightX);
};


#endif //PROS_OKAPI_DRIVE_HPP
