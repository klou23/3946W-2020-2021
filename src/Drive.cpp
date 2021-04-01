#include "Drive.hpp"
#include "main.h"
#include "Constants.hpp"

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
        frontRight.move_relative(motorTurn, speed);
        backRight.move_relative(motorTurn, speed);
        frontLeft.move_relative(-motorTurn, speed);
        backLeft.move_relative(-motorTurn, speed);
    }else if(direction == RIGHT){
        frontRight.move_relative(-motorTurn, speed);
        backRight.move_relative(-motorTurn, speed);
        frontLeft.move_relative(motorTurn, speed);
        backLeft.move_relative(motorTurn, speed);
    }

    waitForMotors();
}


void Drive::oldTurn(double angle, double speed, int direction, int maxWait) {
    double motorTurn = angle * oldTurnScale;

    if(direction == LEFT){
        frontRight.move_relative(motorTurn, speed);
        backRight.move_relative(motorTurn, speed);
        frontLeft.move_relative(-motorTurn, speed);
        backLeft.move_relative(-motorTurn, speed);
    }else if(direction == RIGHT){
        frontRight.move_relative(-motorTurn, speed);
        backRight.move_relative(-motorTurn, speed);
        frontLeft.move_relative(motorTurn, speed);
        backLeft.move_relative(motorTurn, speed);
    }

    waitForMotors(maxWait);
}

void Drive::oldStrafe(double dist, double speed, int direction) {
    double motorTurn = dist * oldStrafeScale;

    if(direction == LEFT){
        frontRight.move_relative(motorTurn, speed);
        backRight.move_relative(-motorTurn, speed);
        frontLeft.move_relative(-motorTurn, speed);
        backLeft.move_relative(motorTurn, speed);
    }else if(direction == RIGHT){
        frontRight.move_relative(-motorTurn, speed);
        backRight.move_relative(motorTurn, speed);
        frontLeft.move_relative(motorTurn, speed);
        backLeft.move_relative(-motorTurn, speed);
    }

    waitForMotors();
}

void Drive::oldStrafe(double dist, double speed, int direction, int maxWait) {
    double motorTurn = dist * oldStrafeScale;

    if(direction == LEFT){
        frontRight.move_relative(motorTurn, speed);
        backRight.move_relative(-motorTurn, speed);
        frontLeft.move_relative(-motorTurn, speed);
        backLeft.move_relative(motorTurn, speed);
    }else if(direction == RIGHT){
        frontRight.move_relative(-motorTurn, speed);
        backRight.move_relative(motorTurn, speed);
        frontLeft.move_relative(motorTurn, speed);
        backLeft.move_relative(-motorTurn, speed);
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

        frontLeft.move_voltage(leftVoltage);
        backLeft.move_voltage(leftVoltage);
        frontRight.move_voltage(rightVoltage);
        backRight.move_voltage(rightVoltage);

        delay(5);
    }
}

void Drive::drive(double dist, double maxVoltage, int maxWait) {
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

    int waitTime = 0;
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

        frontLeft.move_voltage(leftVoltage);
        backLeft.move_voltage(leftVoltage);
        frontRight.move_voltage(rightVoltage);
        backRight.move_voltage(rightVoltage);

        delay(5);
        waitTime += 5;
        if(waitTime > maxWait) break;
    }
}


void Drive::turn(double angle, double maxVoltage, int direction) {
    int target = angle * turnScale;
    if(direction == LEFT) target *= -1;

    leftEncoder.reset();
    rightEncoder.reset();

    double integral = 0;

    double derivative = 0;

    double position = leftEncoder.get_value();

    double error = target - position;

    while(abs(error) > turnThreshold){
        position = leftEncoder.get_value();

        double prevError = error;

        error = target - position;

        derivative = error - prevError;

        integral += error;

        double leftVoltage = capVoltage(error * turnKp + integral * turnKi + derivative * turnKd, 11000);
        double rightVoltage = -leftVoltage;

        frontLeft.move_voltage(leftVoltage);
        backLeft.move_voltage(leftVoltage);
        frontRight.move_voltage(rightVoltage);
        backRight.move_voltage(rightVoltage);

        delay(5);
    }
}

void Drive::turn(double angle, double maxVoltage, int direction, int maxWait) {
    int target = angle * turnScale;
    if(direction == LEFT) target *= -1;

    leftEncoder.reset();
    rightEncoder.reset();

    double integral = 0;

    double derivative = 0;

    double position = leftEncoder.get_value();

    double error = target - position;

    int waitTime = 0;
    while(abs(error) > turnThreshold){
        position = leftEncoder.get_value();

        double prevError = error;

        error = target - position;

        derivative = error - prevError;

        integral += error;

        double leftVoltage = capVoltage(error * turnKp + integral * turnKi + derivative * turnKd, 11000);
        double rightVoltage = -leftVoltage;

        frontLeft.move_voltage(leftVoltage);
        backLeft.move_voltage(leftVoltage);
        frontRight.move_voltage(rightVoltage);
        backRight.move_voltage(rightVoltage);

        delay(5);
        waitTime += 5;
        if(waitTime > maxWait) break;
    }


}

void Drive::driverControl(double leftX, double leftY, double rightX) {
    double driveVels[] {0, 0, 0, 0};    // fl, fr, bl, br

    //forward and back
    for(int i = 0; i < 4; i++) driveVels[i] += leftY;

    //strafing
    driveVels[0] += leftX;
    driveVels[3] += leftX;
    driveVels[1] -= leftX;
    driveVels[2] -= leftX;

    //turning
    driveVels[0] += rightX;
    driveVels[2] += rightX;
    driveVels[1] -= rightX;
    driveVels[3] -= rightX;

    for(int i = 0; i < 4; i++){
        //cap at 1
        if(driveVels[i] > 1) driveVels[i] = 1;
        if(driveVels[i] < -1) driveVels[i] = -1;

        //quadratic curve
        if(driveVels[i] < 0) driveVels[i] *= -1 * driveVels[i];
        else driveVels[i] *= driveVels[i];

        //convert percentages to rpm
        driveVels[i] *= 200;
    }

    //run motors
    frontLeft.move_velocity(driveVels[0]);
    frontRight.move_velocity(driveVels[1]);
    backLeft.move_velocity(driveVels[2]);
    backRight.move_velocity(driveVels[3]);
}

void Drive::driverControl(CustomController c) {
    double leftX = c.getLeftX();
    double leftY = c.getLeftY();
    double rightX = c.getRightX();

    driverControl(leftX, leftY, rightX);
}


