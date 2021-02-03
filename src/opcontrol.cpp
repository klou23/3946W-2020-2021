#include "main.h"
#include "globals.hpp"

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
[[noreturn]] void opcontrol() {

    //motor speeds
    const int driveSpeed = 200;
    const int intakeSpeed = 600;
    const int manipulatorSpeed = 600;

    //set motor brake modes
    frontLeftDrive.setBrakeMode(AbstractMotor::brakeMode::coast);
    frontRightDrive.setBrakeMode(AbstractMotor::brakeMode::coast);
    backLeftDrive.setBrakeMode(AbstractMotor::brakeMode::coast);
    backRightDrive.setBrakeMode(AbstractMotor::brakeMode::coast);
    leftIntake.setBrakeMode(AbstractMotor::brakeMode::brake);
    rightIntake.setBrakeMode(AbstractMotor::brakeMode::brake);
    lowerManipulator.setBrakeMode(AbstractMotor::brakeMode::hold);
    upperManipulator.setBrakeMode(AbstractMotor::brakeMode::hold);

	while (true) {
        //get controller values
        double leftX = controller.getAnalog(ControllerAnalog::leftX);   //left right
        double leftY = controller.getAnalog(ControllerAnalog::leftY);   //forward back
        double rightX = controller.getAnalog(ControllerAnalog::rightX); //turning
        double rightY = controller.getAnalog(ControllerAnalog::rightY); //useless?

        /**********Drive**********/
        double vels[] = {0,0,0,0}; // fl, fr, bl, br
        // forward and back
        for(int i = 0; i < 4; i++) vels[i] += leftY;

        //strafing
        vels[0] += leftX;
        vels[3] += leftX;
        vels[1] -= leftX;
        vels[2] -= leftX;

        //turning
        vels[0] += rightX;
        vels[2] += rightX;
        vels[1] -= rightX;
        vels[3] -= rightX;

        int x = 0;
        int y = 0;

        //cap all vels at 1 and convert percentages to rpm
        for(int i = 0; i < 4; i++){
            if(vels[i] > 1) vels[i] = 1;
            if(vels[i] < -1) vels[i] = -1;
            vels[i] *= driveSpeed;
        }

        //run motors
        frontLeftDrive.moveVelocity(vels[0]);
        frontRightDrive.moveVelocity(vels[1]);
        backLeftDrive.moveVelocity(vels[2]);
        backRightDrive.moveVelocity(vels[3]);

        /**********Intake and manipulator**********/
        int leftIntakeMotorVel = 0;
        int rightIntakeMotorVel = 0;
        int lowerManipulatorMotorVel = 0;
        int upperManipulatorMotorVel = 0;

        if(btnR1.isPressed()){
            leftIntakeMotorVel = 100;
            rightIntakeMotorVel = 100;
            lowerManipulatorMotorVel = 100;
            upperManipulatorMotorVel = 100;

            if(btnL1.isPressed()){
                upperManipulatorMotorVel = -100;
            }
        }else if(btnR2.isPressed()) {
            lowerManipulatorMotorVel = 100;
            upperManipulatorMotorVel = 100;
        }else if(btnL2.isPressed()) {
            leftIntakeMotorVel = 100;
            rightIntakeMotorVel = 100;
        }

        leftIntake.moveVelocity(leftIntakeMotorVel*0.01*intakeSpeed);
        rightIntake.moveVelocity(rightIntakeMotorVel*0.01*intakeSpeed);
        lowerManipulator.moveVelocity(lowerManipulatorMotorVel*0.01*manipulatorSpeed);
        upperManipulator.moveVelocity(upperManipulatorMotorVel*0.01*manipulatorSpeed);


		pros::delay(10);  //wait to save resources (prevent brain from frying)
	}
}
