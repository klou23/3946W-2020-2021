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
    const bool selector = false;

    if(!selector){
        right_auton1();
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
//    rollers.flipOut();
//    delay(500);
//    rollers.primeBalls(350, 1000, false);
//    drive.drive(14, 8000, 1000);
//    delay(500);
//    drive.turn(127, 6000, RIGHT, 1500);
//    rollers.primeBalls(200);
//    drive.drive(20, 8000, 1000);
//    rollers.stopAll();
//    rollers.intake(400, 1500, false);
//    rollers.shoot(600, 500, true);
//    rollers.primeBalls(200, 750, false);
//    drive.drive(-35, 11000, 1400);
//
//    delay(500);
//    drive.turn(73, 8000,LEFT, 1500);
//    delay(1000);
//    rollers.intake(600);
//
//    drive.drive(41, 8000, 3500);
//    rollers.intake(600, 1000, false);
//    delay(500);
//    drive.drive(-5, 8000, 750);
//    drive.drive(5, 8000, 750);
//    rollers.stopRollers();
//    rollers.shoot(600, 1000, true);
//    drive.drive(-5, 8000);

    rollers.flipOutHood();
    rollers.shoot(600, 3000, true);
    drive.drive(-10, 8000);
    rollers.flipOut();
}

void right_auton2() {
    //first goal
    rollers.flipOut();
    delay(500);
    rollers.primeBalls(350, 1000, false);
    drive.drive(13, 6000, 1000);
    delay(500);
    drive.turn(127, 8000, RIGHT, 1500);
    rollers.primeBalls(200);
    drive.drive(20, 8000, 1000);
    rollers.stopAll();
    rollers.intake(400, 1500, false);
    rollers.shoot(600, 500, true);
    drive.drive(-25, 8000, 1400);

    //second goal
    delay(500);
    rollers.primeBalls(250, 1500, false);
    drive.turn(137, 6000, RIGHT, 2000);
    delay(500);
    rollers.primeBalls(250, 1000, false);
    drive.drive(33, 8000, 1500);
    delay(500);
    drive.turn(85, 8000, LEFT,2000);
    drive.drive(8, 8000, 1000);
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
    rollers.primeBalls(400, 1000, false);
    drive.drive(30, 8000, 2000);
    drive.turn(39, 6000, RIGHT, 4000);
    rollers.intake(600);
    drive.drive(28, 8000, 3500);
    rollers.intake(600, 800, false);
    drive.drive(-5, 8000, 750);
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
    delay(500);
    rollers.primeBalls(400, 1200, false);
    drive.drive(13, 8000, 1000);
    delay(500);
    drive.turn(127, 8000, RIGHT, 1500);
    drive.drive(20, 8000, 3000);
    rollers.stopAll();
    rollers.shoot(600, 1500, true);
    drive.drive(-10, 8000, 1400);
    rollers.poop(600);
    rollers.intake(600);

    //second goal
    drive.turn(179, 2000, RIGHT);
    rollers.poop(400);
    rollers.intake(600);
    drive.drive(100, 10000, 5000);
    drive.turn(20, 7000, LEFT);
    drive.drive(20, 5000, 2000);
    delay(500);
    drive.drive(-10, 8000, 1000);

    //third goal
    drive.turn(110, 8000, RIGHT);
    drive.drive(65, 8000, 3000);
    drive.turn(33, 7000, LEFT);
    drive.drive(10, 5000, 2000);
    delay(1000);
    drive.drive(-10, 7000);

    //fourth goal
    drive.turn(70, 8000, RIGHT);
    drive.drive(55, 8000, 5000);
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
