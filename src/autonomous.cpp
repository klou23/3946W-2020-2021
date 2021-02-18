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

void PIDdriveForward(double dist, double maxSpeed, double threshold, double turnThreshold){
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

    double gyroInitial = gyroscope.get_yaw();
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

//        //gyroscope adjustment
//        gyroPrevError = gyroError;
//        gyroError = gyroInitial - gyroscope.get_yaw();
//        gyroIntegral += gyroError;
//        gyroDerivative = error - prevError;
//        if(gyroError > turnThreshold){
//            double change = std::min((rotationalKP * gyroError) + (rotationalKI * gyroIntegral) + (rotationalKD * gyroDerivative), maxSpeed/3.0);
//            leftVel += change;
//            rightVel -= change;
//        }
        backLeftDrive.moveVelocity(leftVel);
        frontLeftDrive.moveVelocity(leftVel);
        backRightDrive.moveVelocity(rightVel);
        frontRightDrive.moveVelocity(rightVel);
        pros::delay(5);
    }while(error > threshold);
}

void PIDturnAngle(double angle, double maxSpeed, double turnThreshold){
    double initial = gyroscope.get_rotation();
    double target = initial + angle;

    double gyroPrevError;
    double gyroError = target - initial;
    double gyroIntegral = gyroError;
    double gyroDerivative = 0;

    do{
        gyroPrevError = gyroError;
        gyroError = target - gyroscope.get_rotation();
        gyroIntegral + gyroError;
        gyroDerivative = gyroError - gyroPrevError;

        double change = std::min((rotationalKP * gyroError) + (rotationalKI * gyroIntegral) + (rotationalKD * gyroDerivative), maxSpeed);
        double leftVel = change;
        double rightVel = -change;

        backLeftDrive.moveVelocity(leftVel);
        frontLeftDrive.moveVelocity(leftVel);
        backRightDrive.moveVelocity(rightVel);
        frontRightDrive.moveVelocity(rightVel);

        pros::delay(5);
    }while(gyroError > turnThreshold);
}

void turnAngle(double angle, int direction, int speed){
    const double scale = 5.5;
    double motorTurn = angle * scale;
    if(direction == LEFT){
        frontRightDrive.moveRelative(motorTurn, speed);
        backRightDrive.moveRelative(motorTurn, speed);
        frontLeftDrive.moveRelative(-motorTurn, speed);
        backLeftDrive.moveRelative(-motorTurn, speed);
    }else if(direction == RIGHT){
        frontRightDrive.moveRelative(-motorTurn, speed);
        backRightDrive.moveRelative(-motorTurn, speed);
        frontLeftDrive.moveRelative(motorTurn, speed);
        backLeftDrive.moveRelative(motorTurn, speed);
    }
    while(abs(frontRightDrive.getTargetPosition() - frontRightDrive.getPosition() > 1) ||
          abs(backRightDrive.getTargetPosition() - backRightDrive.getPosition() > 1) ||
          abs(frontLeftDrive.getTargetPosition() - frontLeftDrive.getPosition() > 1) ||
          abs(backLeftDrive.getTargetPosition() - backLeftDrive.getPosition() > 1)){
        pros::delay(5);
    }
}

void drive(double dist, int speed){
    const double scale = 28.21;
    double motorTurn = dist * scale;
    frontRightDrive.moveRelative(motorTurn, speed);
    backRightDrive.moveRelative(motorTurn, speed);
    frontLeftDrive.moveRelative(motorTurn, speed);
    backLeftDrive.moveRelative(motorTurn, speed);
    while(abs(frontRightDrive.getTargetPosition() - frontRightDrive.getPosition() > 1) ||
          abs(backRightDrive.getTargetPosition() - backRightDrive.getPosition() > 1) ||
          abs(frontLeftDrive.getTargetPosition() - frontLeftDrive.getPosition() > 1) ||
          abs(backLeftDrive.getTargetPosition() - backLeftDrive.getPosition() > 1)){
        pros::delay(5);
    }
}

void autonomous() {
    turnAngle(90, LEFT, 50);
}

void singleScore(){
}

void prog(){
    
}