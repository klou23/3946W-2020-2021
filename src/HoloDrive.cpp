/**
 * @brief Represents a holonomic drive for controlling the drive in both
 * autonomous and driver control.
 * @details This class represents either an X-drive or a mecanum drive and
 * contains methods for drive control using odometry and pure pursuit for
 * autonomous and a method for controlling the drive during driver control.
 * @author Kevin Lou
 * @date 4/19/21
 */

#include "HoloDrive.hpp"

HoloDrive::HoloDrive(const Motor &frontLeft, const Motor &frontRight,
                     const Motor &backLeft, const Motor &backRight,
                     const Encoder &leftEncoder, const Encoder &rightEncoder,
                     const Encoder &backEncoder, const PID &xPid,
                     const PID &yPid, const PID &turnPid) : frontLeft
                     (frontLeft), frontRight(frontRight), backLeft(backLeft),
                     backRight(backRight), leftEncoder(leftEncoder),
                     rightEncoder(rightEncoder), backEncoder(backEncoder),
                     xPID(xPid), yPID(yPid), turnPID(turnPid) {

    robotX = 0;
    robotY = 0;
    robotTheta = 0;

}

void HoloDrive::setChassisInfo(double leftDist, double rightDist,
                               double backDist, double wheelDiam,
                               double lookAheadDist) {
    this->leftDist = leftDist;
    this->rightDist = rightDist;
    this->backDist = backDist;
    this->wheelDiam = wheelDiam;
    this->lookAheadDist = lookAheadDist;
}

void HoloDrive::setState(double x, double y, double theta) {
    robotX = x;
    robotY = y;
    robotTheta = theta;
}

void HoloDrive::stop() {
    frontLeft.move_velocity(0);
    frontRight.move_velocity(0);
    backLeft.move_velocity(0);
    backRight.move_velocity(0);
}

void HoloDrive::updatePosition() {
    //get encoder deltas
    double leftEncDelta = leftEncoder.getDelta();
    double rightEncDelta = rightEncoder.getDelta();
    double backEncDelta = backEncoder.getDelta();

    //get actual motion deltas
    double deltaLeft = leftEncDelta * (wheelDiam/2);
    double deltaRight = rightEncDelta * (wheelDiam/2);
    double deltaBack = backEncDelta * (wheelDiam/2);

    //find change in each direction
    double h;
    double h2;
    double deltaTheta = (deltaLeft - deltaRight) / (2*leftDist);
    if(deltaTheta != 0){
        double sinDT = sin(deltaTheta / 2.0);
        h = ((deltaRight / deltaTheta) + rightDist) * sinDT * 2.0;
        h2 = ((deltaBack / deltaTheta) + backDist) * sinDT * 2.0;
    }else{
        h = deltaRight;
        h2 = deltaBack;
    }

    //update position
    double avgOrientation = robotTheta + (-deltaTheta / 2.0);
    double cosAO = cos(-avgOrientation);
    double sinAO = sin(-avgOrientation);
    robotX += (h * cosAO) + (h2 * -sinAO);
    robotY += (h * sinAO) + (h2 * -sinAO);
    robotTheta -= deltaTheta;
}

void HoloDrive::driveTo(PathState p) {
    //get targets
    double targetX = p.getX();
    double targetY = p.getY();
    double targetTheta = p.isTurn() ? p.getTheta() : robotTheta;

    //start PID controllers
    xPID.start(targetX - robotX);
    yPID.start(targetY - robotY);
    turnPID.start(targetTheta - robotTheta);

    while(!xPID.targetReached() || !yPID.targetReached ||
          !turnPID.targetReached()){
        //update error
        xPID.update(targetX - robotX);
        yPID.update(targetY - robotY);
        turnPID.update(targetTheta - robotTheta);

        //get values
        double x = xPID.getOutput();
        double y = yPID.getOutput();
        double turn = turnPID.getOutput();

        //wait
        delay(1);
    }
}

void HoloDrive::driveTo(double x, double y) {
    PathState target(x, y);
    driveTo(target);
}

void HoloDrive::driveTo(double x, double y, double theta) {
    PathState target(x, y, theta);
    driveTo(target);
}

void HoloDrive::control(double x, double y, double turn) {
    double driveVels[] {0, 0, 0, 0};    // fl, fr, bl, br

    //forward and back
    for(int i = 0; i < 4; i++) driveVels[i] += y;

    //strafing
    driveVels[0] += x;
    driveVels[3] += x;
    driveVels[1] -= x;
    driveVels[2] -= x;

    //turning
    driveVels[0] += turn;
    driveVels[2] += turn;
    driveVels[1] -= turn;
    driveVels[3] -= turn;

    //cap
    double maxVel = driveVels[0]
    for(int i = 1; i < 4; i++){
        maxVel = max(max, driveVels[i]);
    }

    if(maxVel > 1){
        for(int i = 0; i < 4; i++){
            driveVels[i] /= maxVel;
        }
    }

    //convert percentages to rpm
    for(int i = 0; i < 4; i++){
        driveVels[i] *= 200;
    }

    //run motors
    frontLeft.move_velocity(driveVels[0]);
    frontRight.move_velocity(driveVels[1]);
    backLeft.move_velocity(driveVels[2]);
    backRight.move_velocity(driveVels[3]);
}







