#include "main.h"
#include "globals.hpp"

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not resume it
 * from where it left off.
 */

void driveForward(double dist, double maxSpeed, double threshold, double turnThreshold){
    maxSpeed = std::min(maxSpeed, (double) driveSpeed);
    double distTraveled = 0;
    frontLeftDrive.tarePosition();
    backLeftDrive.tarePosition();
    frontRightDrive.tarePosition();
    backRightDrive.tarePosition();

    double prevError;
    double error = dist;
    double errorIntegral = dist;
    double errorDerivative = 0;

    double gyroInitial = gyroscope.getYaw();
    double gyroPrevError = 0;
    double gyroError = 0;
    double gyroIntegral = 0;
    double gyroDerivative = 0;

    do{
        //linear motion
        prevError = error;
        distTraveled += (frontLeftDrive.getPosition() + backLeftDrive.getPosition() + frontRightDrive.getPosition() +
                         backRightDrive.getPosition()) / 4.0;
        error = dist - distTraveled;
        errorIntegral += error;
        errorDerivative = error - prevError;
        double rightVel = std::min((linearKP * error) + (linearKI * errorIntegral) + (linearKD * errorDerivative), maxSpeed);
        double leftVel = rightVel;

        //gyroscope adjustment
        gyroPrevError = gyroError;
        gyroError = gyroInitial - gyroscope.getYaw();
        gyroErrorIntegral += gyroError;
        gyroErrorDerivative = error - prevError;
        if(gyroError > turnThreshold){
            double change = std::min((rotationalKP * gyroError) + (rotationalKI * gyroErrorIntegral) + (rotationalKD * gyroErrorDerivative), maxSpeed/3.0);
            leftVel += change;
            rightVel -= change;
        }
        backLeftDrive.moveVelocity(leftVel);
        frontLeftDrive.moveVelocity(leftVel);
        backRightDrive.moveVelocity(rightVel);
        frontRightDrive.moveVelocity(rightVel);
        pros::delay(5);
    }while(error > threshold);
}

void autonomous() {

    //sets current motor position as 0
    lowerManipulator.tarePosition();

    //move 10 deg clockwise at 200 rpm
    lowerManipulator.moveRelative(10, 200);

    //move to 10 deg (absolute) at 200 rpm
    lowerManipulator.moveAbsolute(10, 200);
}

void singleScore(){
}

void prog(){
    
}