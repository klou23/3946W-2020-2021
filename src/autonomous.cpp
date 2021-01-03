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
void autonomous() {

    //turn towards point (12_in, 12_in), then drive to point
    //don't drive backwards
    //stop 0 in away from the point
	drive->driveToPoint({12_in, 12_in}, false, 0_in);

    //move forward 10_in
    drive->moveDistance(10_in);

    //turn 45_deg
    drive->turnAngle(45_deg);

    //turn to face point(20_in, 20_in)
    drive->turnToPoint({20_in, 20_in});

    //turn to angle 45_deg (absolute)
    drive->turnToAngle(45_deg);

    /**
    * The functions driveToPoint, turnToPoint, and turnToAngle are preferred
    * over moveDistance and turnAngle because they use absolute positioning
    * instead of relative position, resulting in greater accuracy.
    */

    //sets current motor position as 0
    lowerManipulator.tarePosition();

    //move 10 deg clockwise at 200 rpm
    lowerManipulator.moveRelative(10, 200);

    //move to 10 deg (absolute) at 200 rpm
    lowerManipulator.moveAbsolute(10, 200);
}

void onePoint(){

}
