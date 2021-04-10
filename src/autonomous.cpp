#include "autonomous.hpp"
#include "main.h"
#include "Constants.hpp"
#include "Drive.hpp"
#include "Globals.hpp"
#include "Initialize.hpp"
#include "RobotConfig.hpp"
#include "Rollers.hpp"


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

void autonomous() {
    const bool selector = true;

    if(!selector){
        right_auton4();
    }

    if(autonColor == AUTON_RED){
        //left
        if(autonNum == 1){
            left_auton1();
        }else if(autonNum == 2){
            left_auton2();
        }else if(autonNum == 3){
            left_auton3();
        }else if(autonNum == 4){
            left_auton4();
        }
    }else if(autonColor == AUTON_BLUE){
        //right
        if(autonNum == 1){
            right_auton1();
        }else if(autonNum == 2){
            right_auton2();
        }else if(autonNum == 3){
            right_auton3();
        }else if(autonNum == 4){
            right_auton4();
        }
    }
}

void right_auton1() {
    //first goal
    rollers.flipOut();
    delay(500);
    rollers.primeBalls(600, 800, false);
    drive.drive(13, 11000, 1000);
    delay(500);
    drive.turn(132, 8000, RIGHT, 1500);
    rollers.primeBalls(200);
    drive.drive(22, 8000, 1500);
    rollers.stopAll();
    rollers.intake(400, 1500, false);
    rollers.shoot(600, 400, true);
    rollers.primeBalls(300,1200,false);
    drive.drive(-35, 11000, 1400);

    delay(500);
    drive.turn(75, 8000,LEFT, 1500);
    delay(1000);
    rollers.intake(600);

    drive.drive(38, 8000, 3500);
    rollers.intake(600, 1000, false);
    drive.drive(-5, 8000, 750);
    drive.drive(5, 8000, 750);
    rollers.shoot(600, 1000, true);
    drive.drive(-5, 8000);
}

void right_auton2() {
    //first goal
    rollers.flipOut();
    rollers.primeBalls(400, 700, false);
    drive.drive(13, 11000, 1000);
    drive.turn(135, 8000, RIGHT);
    rollers.primeBalls(200);
    drive.drive(21, 8000, 1500);
    rollers.stopAll();
    rollers.intake(400, 1500, false);
    rollers.shoot(600, 700, true);
    drive.drive(-25, 11000, 1400);

    //second goal
    rollers.primeBalls(350, 1500, false);
    drive.turn(135, 9000, RIGHT, 2000);
    drive.drive(33, 11000, 1500);
    drive.turn(85, 8000, LEFT,2000);
    drive.drive(5, 8000, 1000);
    rollers.shoot(600, 1000, true);
    drive.drive(-8, 11000, 750);
}

void right_auton3() {
    //first goal
    rollers.flipOut();
    rollers.primeBalls(300, 700, false);
    drive.drive(12, 11000, 1000);
    drive.turn(125, 8000, RIGHT);
    rollers.primeBalls(200);
    drive.drive(21, 8000, 1500);
    rollers.stopAll();
    rollers.intake(400, 1500, false);
    rollers.shoot(600, 750, true);
    drive.drive(-25, 11000, 1400);

    //second goal
    rollers.primeBalls(400, 1500, false);
    drive.turn(157, 9000, RIGHT);
    drive.drive(32, 11000, 1500);
    drive.turn(90, 8000, LEFT);
    drive.drive(5, 8000, 1000);
    rollers.shoot(600, 1000, true);
    drive.drive(-8, 11000, 750);

    //third goal
    drive.turn(90, 11000, RIGHT);
    drive.drive(43, 11000, 2000);
    drive.turn(40, 8000, LEFT);
    rollers.intake(600);
    rollers.shoot(600);
    drive.drive(42, 8000, 2500);
    rollers.shoot(600, 1000, true);
    drive.drive(-5, 8000);
}

void right_auton4() {
    rollers.flipOut();
    rollers.primeBalls(300, 1000, false);
    drive.drive(28, 8000, 2000);
    drive.turn(44, 8000, RIGHT, 2500);
    rollers.intake(600);
    drive.drive(29, 8000, 3500);
    rollers.intake(600, 800, false);
    drive.drive(-5, 8000, 750);
    drive.turn(10, 8000, RIGHT, 1000);
    drive.drive(5, 8000, 750);
    rollers.shoot(600, 3000, true);
    drive.drive(-5, 8000);
}

void left_auton1() {
    //first goal
    rollers.flipOut();
    rollers.primeBalls(400, 700, false);
    drive.drive(13, 11000, 1000);
    drive.turn(135, 8000, LEFT, 1500);
    rollers.primeBalls(200);
    drive.drive(21, 8000, 1500);
    rollers.stopAll();
    rollers.intake(400, 1500, false);
    rollers.shoot(600, 700, true);
    rollers.primeBalls(600,1200,false);
    drive.drive(-28, 11000, 1400);
}

void left_auton2() {
    //first goal
    rollers.flipOut();
    drive.drive(12, 8000);
    drive.turn(125, 8000, LEFT);
    rollers.primeBalls(120);
    drive.drive(20, 8000, 2000);
    rollers.shoot(600, 1000, true);
    drive.drive(-10, 8000);

    //second goal
    drive.turn(145, 8000, LEFT);
    rollers.primeBalls(200, 1000, false);
    drive.drive(30, 10000);
    drive.turn(90, 6000, RIGHT);
    drive.drive(3, 6000, 1000);
    rollers.shoot(600, 1000, true);
    drive.drive(-5, 8000);
}

void left_auton3() {
    //first goal
    rollers.flipOut();
    drive.drive(12, 8000);
    drive.turn(125, 8000, LEFT);
    rollers.primeBalls(120);
    drive.drive(20, 8000, 2000);
    rollers.shoot(600, 1000, true);
    drive.drive(-10, 8000);

    //second goal
    drive.turn(145, 8000, LEFT);
    rollers.primeBalls(200, 1000, false);
    drive.drive(30, 10000);
    drive.turn(90, 6000, RIGHT);
    drive.drive(3, 6000, 1000);
    rollers.shoot(600, 1000, true);
    drive.drive(-5, 8000);

    //third goal
    drive.turn(80, 8000, LEFT);
    rollers.primeBalls(100);
    drive.drive(35, 8000, 3000);
    rollers.shoot(600, 1000, true);
    drive.drive(-5, 8000);
}

void left_auton4() {

}

void prog1() {
    //first goal
    rollers.flipOut();
    rollers.primeBalls(120);
    drive.drive(12, 8000);
    rollers.stopAll();
    drive.turn(125, 8000, LEFT);
    drive.drive(20, 8000, 2000);
    rollers.shoot(600, 1000, true);
    drive.drive(-10, 8000);

    //second goal
    drive.turn(197, 8000, LEFT);
    rollers.poop(400);
    rollers.intake(600);
    drive.drive(107, 10000);
    drive.turn(28, 7000, LEFT);
    drive.drive(15, 5000);
    delay(500);
    drive.drive(-10, 8000);

    //third goal
    drive.turn(130, 8000, RIGHT);
    drive.drive(65, 8000);
    drive.turn(33, 7000, LEFT);
    drive.drive(10, 5000, 2000);
    delay(1000);
    drive.drive(-10, 7000);

    //fourth goal
    drive.turn(70, 8000, RIGHT);
    drive.drive(55, 8000);
    drive.turn(10, 7000, LEFT);
    drive.drive(10, 6000, 2000);
    delay(1000);
    drive.drive(-10, 6000);
    drive.drive(10, 6000, 2000);
    delay(1000);
    drive.drive(-10, 6000);
}

void prog2() {
    //first goal
    rollers.flipOut();
    rollers.primeBalls(120);
    drive.drive(12, 8000, 1000);
    rollers.stopAll();
    drive.turn(125, 8000, RIGHT);
    drive.drive(25, 8000, 1500);
    rollers.stopAll();
    rollers.shoot(600, 1000, true);
    drive.drive(-25, 8000, 2000);

    //second goal
    rollers.primeBalls(500, 1000, false);
    drive.turn(150, 10000, RIGHT);
    drive.drive(31, 10000, 1500);
    drive.turn(90, 6000, LEFT);
    drive.drive(8, 6000, 1000);
    rollers.shoot(600, 1000, true);
    rollers.extake(200, 500, false);
    drive.drive(-8, 8000, 750);

    //third goal
    drive.turn(88, 8000, RIGHT);
    rollers.primeBalls(600);
    drive.drive(43, 8000, 2000);
    rollers.stopAll();
    drive.turn(45, 8000, LEFT);
    drive.drive(42, 8000, 2500);
    rollers.shoot(600, 1000, true);
    drive.drive(-5, 8000);

    //fourth goal
    drive.turn(125, 8000, RIGHT);
    rollers.intake(600);
    drive.drive(50, 8000);
    rollers.stopRollers();
    drive.turn(90, 7000, LEFT);
    drive.drive(5, 7000, 1000);
    rollers.shoot(600, 1000, true);
    drive.drive(-5, 8000);

//    //fifth goal
//    drive.turn(110, 8000, RIGHT);
//    rollers.intake(600);
//    drive.drive(55, 8000);
//    rollers.stopRollers();
//    drive.turn(60, 8000, LEFT);
//    drive.drive(45, 7000, 2000);
//    rollers.shoot(600, 1000, true);
//    drive.drive(-5, 8000);
}
