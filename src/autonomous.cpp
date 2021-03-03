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
    const double scale = 26.5;
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
void accurateDrive(double dist, int speed, int maxWait){
    const double scale = 26.5;
    frontLeftDrive.tarePosition();
    backLeftDrive.tarePosition();
    frontRightDrive.tarePosition();
    backRightDrive.tarePosition();
    int targetTicks = dist*scale;
    int driveError = dist*scale;
    int kP = .01;
    //For the first 20% of the drive, the robot accelerates from 0 to the target speed in ~500ms.
        for (int i = 1; i < 100; i++) {
            frontLeftDrive.moveVelocity(speed * .01 * i);
            backLeftDrive.moveVelocity(speed * .01 * i);
            FrontRightDrive.moveVelocity(speed * .01 * i);
            BackRightDrive.moveVelocity(speed * .01 * i);
            pros::delay(5);
            if(driveError>(targetTicks/15) break;
        }
    //For the next 70% of the drive, the drive travels at the target speed.
    while(driveError>(targetTicks/10)){
        frontLeftDrive.moveVelocity(speed);
        backLeftDrive.moveVelocity(speed);
        FrontRightDrive.moveVelocity(speed);
        BackRightDrive.moveVelocity(speed);
        driveError = targetTicks-((backLeftDrive.getPosition() + frontLeftDrive.getPosition() +  backRightDrive.getPosition() + frontRightDrive.getPosition())/4)
    }
    while(driveError < 1 || driveError > 1){
        frontLeftDrive.moveVelocity(driveError*kP);
        backLeftDrive.moveVelocity(driveError*kP);
        FrontRightDrive.moveVelocity(driveError*kP);
        BackRightDrive.moveVelocity(driveError*kP);
        driveError = targetTicks-((backLeftDrive.getPosition() + frontLeftDrive.getPosition() +  backRightDrive.getPosition() + frontRightDrive.getPosition())/4)
    }
}
void drive(double dist, int speed, int maxWait){
    const double scale = 26.5;
    double motorTurn = dist * scale;
    frontRightDrive.moveRelative(motorTurn, speed);
    backRightDrive.moveRelative(motorTurn, speed);
    frontLeftDrive.moveRelative(motorTurn, speed);
    backLeftDrive.moveRelative(motorTurn, speed);

    for(int i = maxWait; i >= 0; i-=5){
        if(abs(frontRightDrive.getTargetPosition() - frontRightDrive.getPosition() > 1) ||
           abs(backRightDrive.getTargetPosition() - backRightDrive.getPosition() > 1) ||
           abs(frontLeftDrive.getTargetPosition() - frontLeftDrive.getPosition() > 1) ||
           abs(backLeftDrive.getTargetPosition() - backLeftDrive.getPosition() > 1)){
            pros::delay(5);
        }else{
            break;
        }
    }
}

void driveRev(double dist, int speed){
    frontRightDrive.setReversed(!frontRightDrive.isReversed());
    frontLeftDrive.setReversed(!frontLeftDrive.isReversed());
    backRightDrive.setReversed(!backRightDrive.isReversed());
    backLeftDrive.setReversed(!backLeftDrive.isReversed());
    drive(dist, speed);
    frontRightDrive.setReversed(!frontRightDrive.isReversed());
    frontLeftDrive.setReversed(!frontLeftDrive.isReversed());
    backRightDrive.setReversed(!backRightDrive.isReversed());
    backLeftDrive.setReversed(!backLeftDrive.isReversed());
}

void shoot(int vel){
    lowerManipulator.moveVelocity(vel);
    upperManipulator.moveVelocity(vel);
}

void rollers(int vel){
    rightIntake.moveVelocity(vel);
    leftIntake.moveVelocity(vel);
}

void poop(int vel){
    rollers(vel);
    lowerManipulator.moveVelocity(vel);
    upperManipulator.moveVelocity(-vel);
}

void stop(){
    shoot(0);
    rollers(0);
}

void flipOutHood(){
    upperManipulator.moveVelocity(-300);
    pros::delay(500);
    upperManipulator.moveVelocity(0);
}

void autonomous() {
    prog();
}

void singleScore(){
    //hood flipout
    flipOutHood();
    //score first ball
    shoot(600);
    pros::delay(1500);
    shoot(0);
    driveRev(10, 50);
    //flip out intake
    rollers(-300);
    pros::delay(500);
    rollers(300);
    pros::delay(500);
    rollers(0);

}

void prog(){
    //hood flipout
    flipOutHood();
    rollers(-600);
    drive(8,80);
    rollers(300);
    turnAngle(140, RIGHT,100);
    rollers(0);
    drive(9.5,40,2000);
    //score first ball
    shoot(600);
    pros::delay(5000);
    shoot(0);
    driveRev(10, 50);
    //flip out intake

    //drive to goal D
    poop (600);
    turnAngle(197, LEFT, 40);
    drive(107, 100);

    //turn to goal
    turnAngle(28, LEFT, 50);

    //get the ball out of the goal
    drive(14.5, 25, 5000);
    pros::delay(500);

    //head towards goal B
    driveRev(10,25);
    turnAngle(130,RIGHT,50);
    drive(65,100);

    //descore
    turnAngle(33,LEFT,50);
    drive(10,25, 3000);
    pros::delay(1000);
    driveRev(10,25);

    //drive towards goal C
    turnAngle(70,RIGHT,50);
    drive(55,100);

    //descore
    turnAngle(10, LEFT, 50);
    drive(10, 50, 3000);
    pros::delay(1000);
    driveRev(10, 50);
    drive(10, 50, 3000);
    pros::delay(1000);
    driveRev(10,100);

    stop();
}