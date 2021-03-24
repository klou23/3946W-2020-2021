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

void PDDrive(double dist, double maxVoltage, double thresholdDist, double slaveThresholdAngle, int maxWait){

    maxVoltage = std::min(maxVoltage, 11000.0);

    //left drive is master
    //right drive is slave
    const double masterKp = 50;
    const double masterKd = 0;
    const double slaveKp = 10;
    const double slaveKd = 10;

    const double masterScale = 41.25;
    const double slaveScale = 10;

    const double target = masterScale * dist;
    const double masterThreshold = masterScale * thresholdDist;
    const double slaveThreshold = slaveScale * slaveThresholdAngle;

    leftEncoder.reset();
    rightEncoder.reset();

    double leftPosition = leftEncoder.get_value();
    double rightPosition = rightEncoder.get_value();

    double masterDerivative = 0;
    double slaveDerivative = 0;

    double masterError = target - leftPosition;
    double slaveError = leftPosition - rightPosition;

    int timer = 0;

    while(std::abs(masterError) > masterThreshold || std::abs(slaveError) > slaveThreshold){
        if(timer > maxWait) break;

        leftPosition = leftEncoder.get_value();
        rightPosition = rightEncoder.get_value();

        double prevMasterError = masterError;
        double prevSlaveError = slaveError;

        masterError = target - leftPosition;
        slaveError = leftPosition - rightPosition;

        masterDerivative = masterError - prevMasterError;
        slaveDerivative = slaveError - prevSlaveError;

        double leftVoltage = std::max(-maxVoltage, std::min(maxVoltage, (masterError * masterKp) + (masterDerivative * masterKd)));
        double rightVoltage = std::max(-12000.0, std::min(12000.0, leftVoltage + (slaveError * slaveKp) + (slaveDerivative * slaveKd)));

        cout<<"left:"<<leftVoltage<<", right:"<<rightVoltage<<endl;

        frontLeftDrive.moveVoltage(leftVoltage);
        backLeftDrive.moveVoltage(leftVoltage);
        frontRightDrive.moveVoltage(rightVoltage);
        backRightDrive.moveVoltage(rightVoltage);

        pros::delay(5);
        timer += 5;
    }

}

void PDTurn(double angle, double maxVoltage, int direction, double thresholdAngle, int maxWait){
    maxVoltage = std::min(maxVoltage, 11000.0);

    const double kp = 150;
    const double kd = 1500;

    const double scale = 3.5;
    const double thresholdScale = 10;

    const double target = angle * scale;
    const double threshold = thresholdAngle * thresholdScale;

    double leftTarget = target;
    double rightTarget = -target;
    if(direction == LEFT){
        leftTarget*=-1;
        rightTarget*=-1;
    }

    leftEncoder.reset();
    rightEncoder.reset();

    cout << "leftTarget:" << leftTarget << ", rightTarget: " << rightTarget << endl;

    double leftError = leftTarget;
    double rightError = rightTarget;
    double leftPrevError = leftTarget;
    double rightPrevError = rightTarget;
    double leftDerivative = 0;
    double rightDerivative = 0;

    int timer = 0;
    while(std::abs(leftError) > threshold || std::abs(rightError) > threshold){

        if(timer > maxWait) break;

        double leftPos = leftEncoder.get_value();
        double rightPos = rightEncoder.get_value();

        leftPrevError = leftError;
        rightPrevError = rightError;

        leftError = leftTarget-leftPos;
        rightError = rightTarget-rightPos;

        leftDerivative = leftPrevError-leftError;
        rightDerivative = rightPrevError-rightError;

        double leftVoltage = std::max(-maxVoltage, std::min(maxVoltage, (leftError * kp) + (leftDerivative * kd)));
        double rightVoltage = std::max(-maxVoltage, std::min(maxVoltage, (rightError * kp) + (rightDerivative * kd)));

        cout<<"left:"<<leftVoltage<<", right:"<<rightVoltage<<endl;

        frontLeftDrive.moveVoltage(leftVoltage);
        backLeftDrive.moveVoltage(leftVoltage);
        frontRightDrive.moveVoltage(rightVoltage);
        backRightDrive.moveVoltage(rightVoltage);

        pros::delay(5);
        timer += 5;
    }

}

void shoot(int vel){
    lowerManipulator.moveVelocity(vel);
    upperManipulator.moveVelocity(vel);
}

void rollers(int vel){
    rightIntake.moveVelocity(vel);
    leftIntake.moveVelocity(vel);
}
void revRollers(int vel){
    rightIntake.setReversed(!rightIntake.isReversed());
    leftIntake.setReversed(!leftIntake.isReversed());
    rightIntake.moveVelocity(vel);
    leftIntake.moveVelocity(vel);
    rightIntake.setReversed(!rightIntake.isReversed());
    leftIntake.setReversed(!leftIntake.isReversed());
}
void primeBalls (int vel){
    rightIntake.moveVelocity(vel);
    leftIntake.moveVelocity(vel);
    lowerManipulator.moveVelocity(vel);
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

void flipOut(){
    leftIntake.moveVelocity(-300);
    rightIntake.moveVelocity(-300);
    pros::delay(500);
    leftIntake.moveVelocity(0);
    rightIntake.moveVelocity(0);
    upperManipulator.moveVelocity(-300);
    pros::delay(500);
    upperManipulator.moveVelocity(0);
}

void autonomous() {
    prog2();
}

//void singleScore(){
//    //hood flipout
//    flipOutHood();
//    //score first ball
//    shoot(600);
//    pros::delay(1500);
//    shoot(0);
//    driveRev(10, 50);
//    //flip out intake
//    rollers(-300);
//    pros::delay(500);
//    rollers(300);
//    pros::delay(500);
//    rollers(0);
//
//}

//void prog(){
//    //hood flipout
//    flipOutHood();
//    rollers(-600);
//    drive(8,80);
//    rollers(300);
//    turnAngle(140, RIGHT,100);
//    rollers(0);
//    drive(9.5,40,2000);
//    //score first ball
//    shoot(600);
//    pros::delay(5000);
//    shoot(0);
//    driveRev(10, 50);
//    //flip out intake
//
//    //drive to goal D
//    poop (600);
//    turnAngle(197, LEFT, 40);
//    drive(107, 100);
//
//    //turn to goal
//    turnAngle(28, LEFT, 50);
//
//    //get the ball out of the goal
//    drive(14.5, 25, 5000);
//    pros::delay(500);
//
//    //head towards goal B
//    driveRev(10,25);
//    turnAngle(130,RIGHT,50);
//    drive(65,100);
//
//    //descore
//    turnAngle(33,LEFT,50);
//    drive(10,25, 3000);
//    pros::delay(1000);
//    driveRev(10,25);
//
//    //drive towards goal C
//    turnAngle(70,RIGHT,50);
//    drive(55,100);
//
//    //descore
//    turnAngle(10, LEFT, 50);
//    drive(10, 50, 3000);
//    pros::delay(1000);
//    driveRev(10, 50);
//    drive(10, 50, 3000);
//    pros::delay(1000);
//    driveRev(10,100);
//
//    stop();
//}

void prog2(){
    //first goal (I)

    flipOut();
    primeBalls(120);
    PDDrive(12,8000,0.3,1,2000);
    primeBalls(0);
    turnAngle(125,RIGHT,100);
    PDDrive(20,8000,0.3,1,2000);
    shoot(600);
    pros::delay(1000);
    shoot(0);

    //second goal (H)
    driveRev(22,100);
    primeBalls(200);
    turnAngle(156, RIGHT, 80);
    PDDrive(31,10000,.6,1,2500);
    primeBalls(0);
    turnAngle(90,LEFT,100);
    PDDrive(4,8000,.6,1,1000);
    shoot(600);
    pros::delay(1000);
    primeBalls(0);

    //Third Goal
    revRollers(200);
    driveRev(7,100);
    turnAngle(90,RIGHT,100);
    primeBalls(200);
    PDDrive(30,12000,.3,1,4000);
    turnAngle(45,LEFT,100);
    PDDrive(12,8000,.3,1,2000);
    shoot(600);
    pros::delay(1000);
    shoot(0);

    //Fourth Goal
    driveRev(6,100);
    revRollers(200);
    driveRev(6,100);
    turnAngle(45,RIGHT,100);
    strafeDist(30,RIGHT,100);
    primeBalls(300);
    PDDrive(8,12000,.3,1,2000);
    driveRev(-10,100);
    strafeDist(30,RIGHT,100);
    primeBalls(0);
    PDDrive(8,12000,.3,1,2000);
    shoot(600);
    pros::delay(1000);
    shoot(0);

    //Fifth Goal
    driveRev(8,100);
    strafeDist(30,RIGHT,100);
    primeBalls(300);
    PDDrive(8,12000,.3,1,2000);
    driveRev(-10,100);













}