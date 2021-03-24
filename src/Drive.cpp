//
// Created by Kevin Lou on 3/22/21.
//

#include "Drive.hpp"

Drive::Drive(const Motor &frontLeft, const Motor &frontRight, const Motor &backLeft, const Motor &backRight,
             const ADIEncoder &leftEncoder, const ADIEncoder &rightEncoder) : frontLeft(frontLeft),
                                                                              frontRight(frontRight),
                                                                              backLeft(backLeft), backRight(backRight),
                                                                              leftEncoder(leftEncoder),
                                                                              rightEncoder(rightEncoder) {
    masterKp = 50;
    masterKi = 0;
    masterKd = 0;
    masterThreshold = 10;

    slaveKp = 10;
    slaveKi = 0;
    slaveKd = 10;

    turnKp = 50;
    turnKi = 0;
    turnKd = 0;
    turnThreshold = 10;

    driveScale = 41.25;
    turnScale = 10;

    oldDriveScale = 26.5;
    oldTurnScale = 5.8;
    oldStrafeScale = 30;
}

void Drive::waitForMotors() {
    while(abs(frontLeft.get_target_position() - frontLeft.get_position()) > 1 ||
          abs(frontRight.get_target_position() - frontRight.get_position()) > 1 ||
          abs(backLeft.get_target_position() - backLeft.get_position()) > 1 ||
          abs(backRight.get_target_position() - backRight.get_position()) > 1){
        delay(5);
    }
}

void Drive::waitForMotors(int maxWait) {
    int timeWaited = 0;
    while(abs(frontLeft.get_target_position() - frontLeft.get_position()) > 1 ||
          abs(frontRight.get_target_position() - frontRight.get_position()) > 1 ||
          abs(backLeft.get_target_position() - backLeft.get_position()) > 1 ||
          abs(backRight.get_target_position() - backRight.get_position()) > 1){
        delay(5);
        timeWaited += 5;
        if(timeWaited > maxWait) break;
    }
}

double Drive::capVoltage(double voltage, double maxVoltage){
    if(voltage > maxVoltage) return maxVoltage;
    if(voltage < -maxVoltage) return -maxVoltage;
    return voltage;
}

void Drive::oldDrive(double dist, double speed){
    double motorTurn = dist * oldDriveScale;

    frontRight.move_relative(motorTurn, speed);
    backRight.move_relative(motorTurn, speed);
    frontLeft.move_relative(motorTurn, speed);
    backLeft.move_relative(motorTurn, speed);

    waitForMotors();
}

void Drive::oldDrive(double dist, double speed, int maxWait) {
    double motorTurn = dist * oldDriveScale;

    frontRight.move_relative(motorTurn, speed);
    backRight.move_relative(motorTurn, speed);
    frontLeft.move_relative(motorTurn, speed);
    backLeft.move_relative(motorTurn, speed);

    waitForMotors(maxWait);
}

void Drive::oldTurn(double angle, double speed, int direction) {
    double motorTurn = angle * oldTurnScale;

    if(direction == LEFT){
        frontRightDrive.move_relative(motorTurn, speed);
        backRightDrive.move_relative(motorTurn, speed);
        frontLeftDrive.move_relative(-motorTurn, speed);
        backLeftDrive.move_relative(-motorTurn, speed);
    }else if(direction == RIGHT){
        frontRightDrive.move_relative(-motorTurn, speed);
        backRightDrive.move_relative(-motorTurn, speed);
        frontLeftDrive.move_relative(motorTurn, speed);
        backLeftDrive.move_relative(motorTurn, speed);
    }

    waitForMotors();
}


void Drive::oldTurn(double angle, double speed, int direction, int maxWait) {
    double motorTurn = angle * oldTurnScale;

    if(direction == LEFT){
        frontRightDrive.move_relative(motorTurn, speed);
        backRightDrive.move_relative(motorTurn, speed);
        frontLeftDrive.move_relative(-motorTurn, speed);
        backLeftDrive.move_relative(-motorTurn, speed);
    }else if(direction == RIGHT){
        frontRightDrive.move_relative(-motorTurn, speed);
        backRightDrive.move_relative(-motorTurn, speed);
        frontLeftDrive.move_relative(motorTurn, speed);
        backLeftDrive.move_relative(motorTurn, speed);
    }

    waitForMotors(maxWait);
}

void Drive::oldStrafe(double dist, double speed, int direction) {
    double motorTurn = dist * oldStrafeScale;

    if(direction == LEFT){
        frontRightDrive.move_relative(motorTurn, speed);
        backRightDrive.move_relative(-motorTurn, speed);
        frontLeftDrive.move_relative(-motorTurn, speed);
        backLeftDrive.move_relative(motorTurn, speed);
    }else if(direction == RIGHT){
        frontRightDrive.move_relative(-motorTurn, speed);
        backRightDrive.move_relative(motorTurn, speed);
        frontLeftDrive.move_relative(motorTurn, speed);
        backLeftDrive.move_relative(-motorTurn, speed);
    }

    waitForMotors();
}

void Drive::oldStrafe(double dist, double speed, int direction, int maxWait) {
    double motorTurn = dist * oldStrafeScale;

    if(direction == LEFT){
        frontRightDrive.move_relative(motorTurn, speed);
        backRightDrive.move_relative(-motorTurn, speed);
        frontLeftDrive.move_relative(-motorTurn, speed);
        backLeftDrive.move_relative(motorTurn, speed);
    }else if(direction == RIGHT){
        frontRightDrive.move_relative(-motorTurn, speed);
        backRightDrive.move_relative(motorTurn, speed);
        frontLeftDrive.move_relative(motorTurn, speed);
        backLeftDrive.move_relative(-motorTurn, speed);
    }

    waitForMotors(maxWait);
}

void Drive::drive(double dist, double maxVoltage) {
    double target = dist * driveScale;

    leftEncoder.reset();
    rightEncoder.reset();

    double masterIntegral = 0;
    double masterDerivative = 0;

    double slaveIntegral = 0;
    double slaveDerivative = 0;

    double leftPosition = leftEncoder.get_value();
    double rightPosition = rightEncoder.get_value();

    double masterError = target - leftPosition;
    double slaveError = leftPosition - rightPosition;

    while(abs(masterError) > masterThreshold){
        leftPosition = leftEncoder.get_value();
        rightPosition = rightEncoder.get_value();

        double prevMasterError = masterError;
        double prevSlaveError = slaveError;

        masterError = target - leftPosition;
        slaveError = leftPosition - rightPosition;

        masterDerivative = masterError - prevMasterError;
        slaveDerivative = slaveError - prevSlaveError;

        masterIntegral += masterError;
        slaveIntegral += slaveIntegral;

        double leftVoltage = capVoltage(masterError * masterKp + masterIntegral * masterKi +
                                        masterDerivative * masterKd, maxVoltage);
        double rightVoltage = capVoltage(leftVoltage + slaveError * slaveKp +
                                         slaveIntegral * slaveKi + slaveDerivative * slaveKd, 12000);

        frontLeftDrive.move_voltage(leftVoltage);
        backLeftDrive.move_voltage(leftVoltage);
        frontRightDrive.move_voltage(rightVoltage);
        backRightDrive.move_voltage(rightVoltage);

        delay(5);
    }
}




