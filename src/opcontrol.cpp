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



void opcontrol() {

    int motorTempTimer = 0;

	while (true) {
        //get controller values
        double leftX = masterController.getAnalog(ControllerAnalog::leftX);   //left right
        double leftY = masterController.getAnalog(ControllerAnalog::leftY);   //forward back
        double rightX = masterController.getAnalog(ControllerAnalog::rightX); //turning

        double partnerLeftY = partnerController.getAnalog(ControllerAnalog::leftY); //pooping joystick
        partnerLeftY = (partnerLeftY >= 0) ? partnerLeftY : -partnerLeftY;

        /**********Drive**********/
        double driveVels[] {0, 0, 0, 0}; // fl, fr, bl, br
        // forward and back
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

        //cap all driveVels at 1 and convert percentages to rpm
        //add quadratic control
        for(int i = 0; i < 4; i++){
            if(driveVels[i] > 1) driveVels[i] = 1;
            if(driveVels[i] < -1) driveVels[i] = -1;
            if(quadraticControl) {
                if(driveVels[i] < 0) driveVels[i] *= -1 * driveVels[i];
                else driveVels[i] *= driveVels[i];
            }
            driveVels[i] *= driveSpeed;
        }

        //run motors
        frontLeftDrive.moveVelocity(driveVels[0]);
        frontRightDrive.moveVelocity(driveVels[1]);
        backLeftDrive.moveVelocity(driveVels[2]);
        backRightDrive.moveVelocity(driveVels[3]);

        /**********Intake and manipulator**********/
        //set vels
        double rollerVels[] {0, 0, 0}; //intake, lower, upper

        if(masterA.isPressed()){
//            drive->setState({0_in, 0_in, 0_deg});
//            drive->driveToPoint({24_in, 0_in});
//            drive->setMoveThreshold(0.5_in);
//            drive->moveDistance(24_in);
        }

        if(masterL1.isPressed()) rollerVels[0] = rollerVels[1] = rollerVels[2] = 1;         //1,1,1
        else if(masterL2.isPressed()) rollerVels[0] = rollerVels[1] = 1;                    //1,1,0
        else if(masterR1.isPressed()) rollerVels[1] = 1;                                    //0,1,0
        else if(masterR2.isPressed()) rollerVels[1] = rollerVels[2] = 1;                    //0,1,1
        else if(partnerL1.isPressed()) rollerVels[0] = rollerVels[1] = rollerVels[2] = -1;  //-1,-1,-1
        else if(partnerL2.isPressed()) rollerVels[1] = rollerVels[2] = -1;                  //0,-1,-1
        else if(partnerR1.isPressed()) rollerVels[0] = 1;                                   //1,0,0
        else if(partnerR2.isPressed()) rollerVels[0] = -1;                                  //-1,0,0
        else if(partnerLeftY > 0.05){
            if(!partnerA.isPressed()) rollerVels[0] = 1;
            rollerVels[1] = partnerLeftY;
            rollerVels[2] = -partnerLeftY;
        }

//        for(int i = 0; i < 3; i++) driveVels[i] *= intakeSpeed;

        //run motors
        leftIntake.moveVelocity(rollerVels[0] * intakeSpeed);
        rightIntake.moveVelocity(rollerVels[0] * intakeSpeed);
        lowerManipulator.moveVelocity(rollerVels[1] * intakeSpeed);
        upperManipulator.moveVelocity(rollerVels[2] * intakeSpeed);

        /**********Motor Temp**********/
        motorTempTimer++;
        if(motorTempTimer >= 15){
            std::string motorNames[] = {"FL Drive", "FR Drive", "BL Drive", "BR Drive", "L Inake", "R Intake", "L Roller", "U Roller"};
            int motorTemps[8];

            motorTemps[0] = frontLeftDrive.getTemperature();
            motorTemps[1] = frontRightDrive.getTemperature();
            motorTemps[2] = backLeftDrive.getTemperature();
            motorTemps[3] = backRightDrive.getTemperature();
            motorTemps[4] = leftIntake.getTemperature();
            motorTemps[5] = rightIntake.getTemperature();
            motorTemps[6] = lowerManipulator.getTemperature();
            motorTemps[7] = upperManipulator.getTemperature();

            int highestTemp = 0;
            std::string hottestMotor = "";

            for(int i = 0; i < 8; i++){
                if(motorTemps[i] > highestTemp){
                    highestTemp = motorTemps[i];
                    hottestMotor = motorNames[i];
                }
            }

            std::cout << hottestMotor << " - " << highestTemp << "C";

            motorTempTimer = 0;
        }

		pros::delay(10);  //wait to save resources (prevent brain from frying)
	}
}
