#include "main.h"

//declare controller and buttons used
Controller controller;
ControllerButton aButton(ControllerDigital::A);
ControllerButton bButton(ControllerDigital::A);

//declare motor
Motor motor1(-8);   //motor in port 8 and direction reversed

std::shared_ptr<OdomChassisController> drive = ChassisControllerBuilder()
    .withMotors(
		{-1, -2},	//left motors are 1 & 2 (both reversed)
		{3, 4}		//right motors are 3 & 4
	)
    .withDimensions(
		AbstractMotor::gearset::green,	//green gear cartridge
		{{4_in,							//4 inch wheel diameter
		11.5_in},						//11.5 inch wheelbase
		imev5GreenTPR * (1.0 / 1.0)}	//1:1 external gear ratio
	)
    .withSensors(
        ADIEncoder{'A', 'B'}, 		// left encoder in ADI ports A & B
        ADIEncoder{'C', 'D', true}, // right encoder in ADI ports C & D (reversed)
        ADIEncoder{'E', 'F'}  		// middle encoder in ADI ports E & F
    )
    // specify the tracking wheels diameter (2.75 in), track (7 in), and TPR (360)
    // specify the middle encoder distance (1 in) and diameter (2.75 in)
    .withOdometry(
		{{2.75_in,		//tracking wheels diameter is 2.75 in
		7_in,			//tracking wheel base is 7 in
		1_in,			//middle encoder distance is 1 in
		2.75_in},		//middle tracking wheel diameter is 2.75 in
		quadEncoderTPR}
	)
    .buildOdometry();



/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {

    //set position to (0,0)
    //set orientation to 0
    drive->setState({0_in, 0_in, 0_deg});

}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

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
    motor1::tarePosition();

    //move 10 deg clockwise at 200 rpm
    motor1::moveRelative(10, 200);

    //move to 10 deg (absolute) at 200 rpm
    motor1::moveAbsolute(10, 200);
}

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
	while (true) {
        //standard tank drive
        drive->getModel()->tank(controller.getAnalog(ControllerAnalog::leftY),
                                controller.getAnalog(ControllerAnalog::rightY));

        if(aButton.isPressed()){
            motor1.moveVelocity(200);
        }else if(bButton.isPressed()){
            motor1.moveVelocity(-200);
        }else{
            motor1.moveVelocity(0);
        }
        /**
        * Motor velocity is in rpm (100, 200, or 600 depending on motor
        * cartridge). moveVelocity is preferred over moveVoltage because
        * moveVelocity uses PID to ensure consistent speed
        */

		pros::delay(10);  //wait to save resources(prevent brain from frying)
	}
}
