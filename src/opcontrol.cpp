#include "main.h"
#include "Globals.hpp"
#include "RobotConfig.hpp"

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

    std::string motorNames[] = {"FL Drive", "FR Drive", "BL Drive", "BR Drive", "L Intake", "R Intake",
                                "L Roller", "U Roller"};

    int motorWaitTimes[] = {0,0,0,0,0,0,0,0};
    int manualMotorWaitTime = 0;

    while(true){
        /***** Control *****/
        drive.driverControl(masterController);
        rollers.driverControl(masterController, partnerController);

        /***** Motor Temp Monitoring *****/
        int motorTemps[8];

        motorTemps[0] = frontLeftDrive.get_temperature();
        motorTemps[1] = frontRightDrive.get_temperature();
        motorTemps[2] = backLeftDrive.get_temperature();
        motorTemps[3] = backRightDrive.get_temperature();
        motorTemps[4] = leftIntake.get_temperature();
        motorTemps[5] = rightIntake.get_temperature();
        motorTemps[6] = lowerManipulator.get_temperature();
        motorTemps[7] = upperManipulator.get_temperature();

        //manual poll motorTemps
        if(manualMotorWaitTime == 0 && (masterController.pressed(BUTTON_X) || partnerController.pressed(BUTTON_X))){
            for(int i = 0; i < 8; i++){
                if(motorTemps[i] >= 65){
                    printSpecial(motorNames[i] + " - " + to_string(motorTemps[i]), PRINT_RED);
                }else if(motorTemps[i] >= 55){
                    printSpecial(motorNames[i] + " - " + to_string(motorTemps[i]), PRINT_ORANGE);
                }else if(motorTemps[i] >= 50){
                    printSpecial(motorNames[i] + " - " + to_string(motorTemps[i]), PRINT_YELLOW);
                }else{
                    printSpecial(motorNames[i] + " - " + to_string(motorTemps[i]), PRINT_GREEN);
                }
                motorWaitTimes[i] = 15000;
            }
            manualMotorWaitTime = 1000;
        }

        //auto motorTemp warnings
        for(int i = 0; i < 8; i++){
            if(motorWaitTimes[i] > 0) continue;

            if(motorTemps[i] >= 65){
                printSpecial(motorNames[i] + " - " + to_string(motorTemps[i]), PRINT_RED);
            }else if(motorTemps[i] >= 55){
                printSpecial(motorNames[i] + " - " + to_string(motorTemps[i]), PRINT_ORANGE);
            }else if(motorTemps[i] >= 50){
                printSpecial(motorNames[i] + " - " + to_string(motorTemps[i]), PRINT_YELLOW);
            }
            motorWaitTimes[i] = 15000;
        }

        //update wait times
        for(int i = 0; i < *(&motorWaitTimes + 1) - motorWaitTimes; i++){
            motorWaitTimes[i] = max(0, motorWaitTimes[i] - 5);
        }
        manualMotorWaitTime = max(0, manualMotorWaitTime - 5);

        /***** Save RAM *****/
        delay(5);
    }

}
