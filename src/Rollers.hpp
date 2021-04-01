/**
 * @file
 * @brief Rollers class for all roller operations
 */

#ifndef PROS_OKAPI_ROLLERS_HPP
#define PROS_OKAPI_ROLLERS_HPP

#include "main.h"
#include "CustomController.hpp"
#include "Constants.hpp"

class Rollers {
private:
    /**
     * Left intake motor
     */
    Motor leftIntake;
    /**
     * Right intake motor;
     */
    Motor rightIntake;

    /**
     * Lower manipulator motor
     */
    Motor lowerManipulator;
    /**
     * Upper manipulator motor
     */
    Motor upperManipulator;

public:
    /**
     * Creates a new rollers object given the motors
     *
     * @param leftIntake
     *          pros::motor to act as the left intake motor
     * @param rightIntake
     *          pros::motor to act as the right intake motor
     * @param lowerManipulator
     *          pros::motor to act as the lower manipulator motor
     * @param upperManipulator
     *          pros::motor to act as the upper manipulator motor
     */
    Rollers(const Motor &leftIntake, const Motor &rightIntake, const Motor &lowerManipulator,
            const Motor &upperManipulator);

    /**
     * Stops the left and right intake rollers by setting
     * the motor velocities to zero
     */
    void stopRollers();

    /**
     * Stops the upper and lower manipulator rollers by setting
     * the motor velocities to zero
     */
    void stopManipulators();

    /**
     * Stops all of the rollers (intake and manipulator) by
     * setting the motor velocities to zero
     */
    void stopAll();

    /**
     * Runs both of the intakes to intake balls
     *
     * @param vel
     *          The speed in rotations per minute to run the
     *          intakes at
     */
    void intake(int vel);

    /**
     * Runs both of the intakes to intake balls
     *
     * @param vel
     *          The speed in rotations per minute to run the
     *          intakes at
     * @param time
     *          The time to run the intakes for in milliseconds
     * @param blocking
     *          Whether or not this function should block all other
     *          operations. If true, everything will stop until the
     *          intakes are done. If false, other operations will
     *          run while the rollers are running.
     */
    void intake(int vel, int time, bool blocking);

    /**
     * Runs both of the intakes to extake balls
     *
     * @param vel
     *          The speed in rotations per minute to run the
     *          intakes at
     */
    void extake(int vel);

    /**
     * Runs both of the intakes to extake balls
     *
     * @param vel
     *          The speed in rotations per minute to run the
     *          intakes at
     * @param time
     *          The time to run the intakes for in milliseconds
     * @param blocking
     *          Whether or not this function should block all other
     *          operations. If true, everything will stop until the
     *          intakes are done. If false, other operations will
     *          run while the rollers are running.
     */
    void extake(int vel, int time, bool blocking);

    /**
     * Runs both of the manipulators to shoot balls into goals
     *
     * @param vel
     *          The speed in rotations per minute to run the
     *          rollers at
     */
    void shoot(int vel);

    /**
     * Runs both of the manipulators to shoot balls into goals
     *
     * @param vel
     *          The speed in rotations per minute to run the
     *          rollers at
     * @param time
     *          The time to run the rollers for int milliseconds
     * @param blocking
     *          Whether or not this function should block all other
     *          operations. If true, everything will stop until the
     *          intakes are done. If false, other operations will
     *          run while the rollers are running.
     */
    void shoot(int vel, int time, bool blocking);

    /**
     * Runs both of the manipulators to move balls toward
     * the intakes
     *
     * @param vel
     *          The speed in rotations per minute to run the
     *          rollers at
     */
    void shootRev(int vel);

    /**
     * Runs both of the manipulators to move balls toward
     * the intakes
     *
     * @param vel
     *          The speed in rotations per minute to run the
     *          rollers at
     * @param time
     *          The time to run the rollers for int milliseconds
     * @param blocking
     *          Whether or not this function should block all other
     *          operations. If true, everything will stop until the
     *          intakes are done. If false, other operations will
     *          run while the rollers are running.
     */
    void shootRev(int vel, int time, bool blocking);

    /**
     * Runs both of the manipulators to poop balls out the
     * back of the robot
     *
     * @param vel
     *          The speed in rotations per minute to run the
     *          rollers at
     */
    void poop(int vel);

    /**
     * Runs both of the manipulators to poop balls out the
     * back of the robot
     *
     * @param vel
     *          The speed in rotations per minute to run the
     *          rollers at
     * @param time
     *          The time to run the rollers for int milliseconds
     * @param blocking
     *          Whether or not this function should block all other
     *          operations. If true, everything will stop until the
     *          intakes are done. If false, other operations will
     *          run while the rollers are running.
     */
    void poop(int vel, int time, bool blocking);

    /**
     * Runs all of the rollers to cycle balls
     *
     * @param vel
     *          The speed int rotations per minute to run the
     *          rollers at
     */
    void cycle(int vel);

    /**
     * Runs all of the rollers to cycle balls
     *
     * @param vel
     *          The speed in rotations per minute to run the
     *          rollers at
     * @param time
     *          The time to run the rollers for int milliseconds
     * @param blocking
     *          Whether or not this function should block all other
     *          operations. If true, everything will stop until the
     *          intakes are done. If false, other operations will
     *          run while the rollers are running.
     */
    void cycle(int vel, int time, bool blocking);

    /**
     * Runs all of the rollers to cycle balls reversed
     *
     * @param vel
     *          The speed in rotations per minute to run the
     *          rollers at
     */
    void cycleRev(int vel);

    /**
     * Runs all of the rollers to cycle balls reversed
     *
     * @param vel
     *          The speed in rotations per minute to run the
     *          rollers at
     * @param time
     *          The time to run the rollers for int milliseconds
     * @param blocking
     *          Whether or not this function should block all other
     *          operations. If true, everything will stop until the
     *          intakes are done. If false, other operations will
     *          run while the rollers are running.
     */
    void cycleRev(int vel, int time, bool blocking);

    /**
     * Flips out the rollers and the hood by running the intake
     * rollers and the upper manipulator backwards
     */
    void flipOut();

    /**
     * Runs the intake rollers and lower manipulator to
     * move balls into a shooting position
     *
     * @note Running this function for too long or too quickly
     * will result in the balls being pooped out the back
     *
     * @param vel
     *          The speed in rotations per minute to run the
     *          rollers at
     */
    void primeBalls(int vel);

    /**
     * Runs the intake rollers and lower manipulator to
     * move balls into a shooting position
     *
     * @note Running this function for too long or too quickly
     * will result in the balls being pooped out the back
     *
     * @param vel
     *          The speed in rotations per minute to run the
     *          rollers at
     * @param time
     *          The time to run the rollers for int milliseconds
     * @param blocking
     *          Whether or not this function should block all other
     *          operations. If true, everything will stop until the
     *          intakes are done. If false, other operations will
     *          run while the rollers are running.
     */
    void primeBalls(int vel, int time, bool blocking);

    /**
     * Runs the rollers based on the two controllers passed in
     *
     * Runs one of the following operations based on the controller
     * buttons/joysticks listed in order of precedence:
     * - Partner A - runs the upper manipulator backwards for hood flipout
     * - Master R1 - runs all of the rollers to cycle
     * - Master L1 - runs both of the manipulators to shoot balls
     * - Partner L1 - runs all of the rollers to cycle all of the balls backwards
     * - Partner L2 - runs both of the manipulators to move balls towards the rollers
     * - Partner R1 - runs both of the intakes to intake balls
     * - Partner R2 - runs both of the intakes to extake balls
     * - Partner Left Joystick Y - runs both of the manipulators to poop balls out the back
     *
     * @note intake control with the right partner triggers is not mutually
     * exclusive with pooping control with the left joystick
     *
     * @param master
     *          Master controller
     * @param partner
     *          Partner controller
     */
    void driverControl(CustomController master, CustomController partner);
};

#endif //PROS_OKAPI_ROLLERS_HPP
