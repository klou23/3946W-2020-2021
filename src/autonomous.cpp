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
//    prog2();
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

//void prog2(){
//    //first goal (I)
//
//    flipOut();
//    primeBalls(120);
//    PDDrive(12,8000,0.3,1,2000);
//    primeBalls(0);
//    turnAngle(125,RIGHT,100);
//    PDDrive(20,8000,0.3,1,2000);
//    shoot(600);
//    pros::delay(1000);
//    shoot(0);
//
//    //second goal (H)
//    driveRev(22,100);
//    primeBalls(200);
//    turnAngle(156, RIGHT, 80);
//    PDDrive(31,10000,.6,1,2500);
//    primeBalls(0);
//    turnAngle(90,LEFT,100);
//    PDDrive(4,8000,.6,1,1000);
//    shoot(600);
//    pros::delay(1000);
//    primeBalls(0);
//
//    //Third Goal
//    revRollers(200);
//    driveRev(7,100);
//    turnAngle(90,RIGHT,100);
//    primeBalls(200);
//    PDDrive(30,12000,.3,1,4000);
//    turnAngle(45,LEFT,100);
//    PDDrive(12,8000,.3,1,2000);
//    shoot(600);
//    pros::delay(1000);
//    shoot(0);
//
//    //Fourth Goal
//    driveRev(6,100);
//    revRollers(200);
//    driveRev(6,100);
//    turnAngle(45,RIGHT,100);
//    strafeDist(30,RIGHT,100);
//    primeBalls(300);
//    PDDrive(8,12000,.3,1,2000);
//    driveRev(-10,100);
//    strafeDist(30,RIGHT,100);
//    primeBalls(0);
//    PDDrive(8,12000,.3,1,2000);
//    shoot(600);
//    pros::delay(1000);
//    shoot(0);
//
//    //Fifth Goal
//    driveRev(8,100);
//    strafeDist(30,RIGHT,100);
//    primeBalls(300);
//    PDDrive(8,12000,.3,1,2000);
//    driveRev(-10,100);
//}

void right_auton1() {
    //first goal
    rollers.flipOut();
    drive.drive(12, 8000);
    drive.turn(125, 8000, RIGHT);
    rollers.primeBalls(120);
    drive.drive(20, 8000, 2000);
    rollers.shoot(600, 1000, true);
    drive.drive(-10, 8000);
}

void right_auton2() {
    //first goal
    rollers.flipOut();
    drive.drive(12, 8000);
    drive.turn(125, 8000, RIGHT);
    rollers.primeBalls(120);
    drive.drive(20, 8000, 2000);
    rollers.shoot(600, 1000, true);
    drive.drive(-10, 8000);

    //second goal
    drive.turn(145, 8000, RIGHT);
    rollers.primeBalls(200, 1000, false);
    drive.drive(30, 10000);
    drive.turn(90, 6000, LEFT);
    drive.drive(3, 6000, 1000);
    rollers.shoot(600, 1000, true);
    drive.drive(-5, 8000);
}

void right_auton3() {
    //first goal
    rollers.flipOut();
    drive.drive(12, 8000);
    drive.turn(125, 8000, RIGHT);
    rollers.primeBalls(120);
    drive.drive(20, 8000, 2000);
    rollers.shoot(600, 1000, true);
    drive.drive(-10, 8000);

    //second goal
    drive.turn(145, 8000, RIGHT);
    rollers.primeBalls(200, 1000, false);
    drive.drive(30, 10000);
    drive.turn(90, 6000, LEFT);
    drive.drive(3, 6000, 1000);
    rollers.shoot(600, 1000, true);
    drive.drive(-5, 8000);

    //third goal
    drive.turn(80, 8000, RIGHT);
    rollers.primeBalls(100);
    drive.drive(35, 8000, 3000);
    rollers.shoot(600, 1000, true);
    drive.drive(-5, 8000);
}

void right_auton4() {

}

void left_auton1() {
    //first goal
    rollers.flipOut();
    drive.drive(12, 8000);
    drive.turn(125, 8000, LEFT);
    rollers.primeBalls(120);
    drive.drive(20, 8000, 2000);
    rollers.shoot(600, 1000, true);
    drive.drive(-10, 8000);
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
    drive.drive(12, 8000);
    rollers.stopAll();
    drive.turn(125, 8000, LEFT);
    drive.drive(20, 8000, 2000);
    rollers.shoot(600, 1000, true);
    drive.drive(-10, 8000);

    //second goal
    drive.turn(145, 8000, LEFT);
    rollers.primeBalls(200, 1000, false);
    drive.drive(30, 10000);
    drive.turn(90, 6000, RIGHT);
    drive.drive(5, 6000, 1000);
    rollers.shoot(600, 1000, true);
    drive.drive(-5, 8000);

    //third goal
    drive.turn(90, 8000, RIGHT);
    rollers.intake(600);
    drive.drive(36, 8000);
    rollers.stopRollers();
    drive.turn(45, 8000, LEFT);
    drive.drive(40, 8000, 2500);
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

    //fifth goal
    drive.turn(110, 8000, RIGHT);
    rollers.intake(600);
    drive.drive(55, 8000);
    rollers.stopRollers();
    drive.turn(60, 8000, LEFT);
    drive.drive(45, 7000, 2000);
    rollers.shoot(600, 1000, true);
    drive.drive(-5, 8000);
}
