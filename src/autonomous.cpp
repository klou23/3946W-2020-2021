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

//void accurateDrive(double dist, int speed, int maxWait){
//    const double scale = 26.5;
//    frontLeftDrive.tarePosition();
//    backLeftDrive.tarePosition();
//    frontRightDrive.tarePosition();
//    backRightDrive.tarePosition();
//    int targetTicks = dist*scale;
//    int driveError = dist*scale;
//    int kP = .01;
//    //For the first 20% of the drive, the robot accelerates from 0 to the target speed in ~500ms.
//        for (int i = 1; i < 100; i++) {
//            frontLeftDrive.moveVelocity(speed * .01 * i);
//            backLeftDrive.moveVelocity(speed * .01 * i);
//            FrontRightDrive.moveVelocity(speed * .01 * i);
//            BackRightDrive.moveVelocity(speed * .01 * i);
//            pros::delay(5);
//            if(driveError>(targetTicks/15) break;
//        }
//    //For the next 70% of the drive, the drive travels at the target speed.
//    while(driveError>(targetTicks/10)){
//        frontLeftDrive.moveVelocity(speed);
//        backLeftDrive.moveVelocity(speed);
//        FrontRightDrive.moveVelocity(speed);
//        BackRightDrive.moveVelocity(speed);
//        driveError = targetTicks-((backLeftDrive.getPosition() + frontLeftDrive.getPosition() +  backRightDrive.getPosition() + frontRightDrive.getPosition())/4)
//    }
//    while(driveError < 1 || driveError > 1){
//        frontLeftDrive.moveVelocity(driveError*kP);
//        backLeftDrive.moveVelocity(driveError*kP);
//        FrontRightDrive.moveVelocity(driveError*kP);
//        BackRightDrive.moveVelocity(driveError*kP);
//        driveError = targetTicks-((backLeftDrive.getPosition() + frontLeftDrive.getPosition() +  backRightDrive.getPosition() + frontRightDrive.getPosition())/4)
//    }
//}

//void PDDrive(double dist, double maxVoltage, double thresholdDist, double slaveThresholdAngle, int maxWait){
//
//    maxVoltage = std::min(maxVoltage, 11000.0);
//
//    //left drive is master
//    //right drive is slave
//    const double masterKp = 0.01;
//    const double masterKd = 0.001;
//    const double slaveKp = 0.005;
//    const double slaveKd = 0.0005;
//
//    const double masterScale = 50;
//    const double slaveScale = 10;
//
//    const double target = masterScale * dist;
//    const double masterThreshold = masterScale * thresholdDist;
//    const double slaveThreshold = slaveScale * slaveThresholdAngle;
//
//    leftEncoder.reset();
//    rightEncoder.reset();
//
//    double leftPosition = leftEncoder.controllerGet();
//    double rightPosition = rightEncoder.controllerGet();
//
//    double masterDerivative = 0;
//    double slaveDerivative = 0;
//
//    double masterError = target - leftPosition;
//    double slaveError = leftPosition - rightPosition;
//
//    int timer = 0;
//
//    while(masterError > masterThreshold || slaveError > slaveThreshold){
//        if(timer > maxWait) break;
//
//        leftPosition = leftEncoder.controllerGet();
//        rightPosition = rightEncoder.controllerGet();
//
//        double prevMasterError = masterError;
//        double prevSlaveError = slaveError;
//
//        masterError = target - leftPosition;
//        slaveError = leftPosition - rightPosition;
//
//        masterDerivative = masterError - prevMasterError;
//        slaveDerivative = slaveError - prevSlaveError;
//
//        double leftVoltage = std::max(-maxVoltage, std::min(maxVoltage, (masterError * masterKp) + (masterDerivative * masterKd)));
//        double rightVoltage = std::max(-12000, std::min(12000, leftVoltage + (slaveError * slaveKp) + (slaveDerivative * slaveKd)));
//
//        frontLeftDrive.moveVoltage(leftVoltage);
//        backLeftDrive.moveVoltage(leftVoltage);
//        frontRightDrive.moveVoltage(rightVoltage);
//        backRightDrive.moveVoltage(rightVoltage);
//
//        pros::delay(5);
//        timer += 5;
//    }
//
//}

//void pdTurn(double angle, double maxVoltage, int direction, double thresholdAngle, int maxWait){
//    maxVoltage = std::min(maxVoltage, 11000.0);
//
//    const double kp = 0.01;
//    const double kd = 0.001;
//
//    const double scale = 5.5;
//
//}

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