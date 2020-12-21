#include "main.h"

//motor ports
const int frontLeftDrivePort = 1;
const int frontRightDrivePort = -2;
const int backLeftDrivePort = -3;
const int backRightDrivePort = 4;
const int leftIntakePort = 5;
const int rightIntakePort = 6;
const int lowerManipulatorPort = 7;
const int upperManipulatorPort = 8;

//declare controller and buttons
Controller controller;
ControllerButton btnL1(ControllerDigital::L1);
ControllerButton btnL2(ControllerDigital::L2);
ControllerButton btnR1(ControllerDigital::R1);
ControllerButton btnR2(ControllerDigital::R2);
ControllerButton btnUp(ControllerDigital::up);
ControllerButton btnDown(ControllerDigital::down);
ControllerButton btnLeft(ControllerDigital::left);
ControllerButton btnRight(ControllerDigital::right);
ControllerButton btnX(ControllerDigital::X);
ControllerButton btnB(ControllerDigital::B);
ControllerButton btnY(ControllerDigital::Y);
ControllerButton btnA(ControllerDigital::A);

//declare motors
Motor frontLeftDrive(frontLeftDrivePort);
Motor frontRightDrive(frontRightDrivePort);
Motor backLeftDrive(backLeftDrivePort);
Motor backRightDrive(backRightDrivePort);
Motor leftIntake(leftIntakePort);
Motor rightIntake(rightIntakePort);
Motor lowerManipulator(lowerManipulatorPort);
Motor upperManipulator(upperManipulatorPort);

//declare chassis controller
std::shared_ptr<OdomChassisController> drive = ChassisControllerBuilder()
    .withMotors(
		    1,        //Front left
            -2,       //Front right (reversed)
            -3,       //Back right (reversed)
            4         //Back left
    )
    .withGains(
      {0.001, 0, 0.0001},     //distance controller gains (kp, ki, kd)
      {0.001, 0, 0.0001}      //turn controller gains (kp, ki, kd);
    )
    .withSensors(
        ADIEncoder{'A', 'B'}, 		// left encoder in ADI ports A & B
        ADIEncoder{'C', 'D', true}, // right encoder in ADI ports C & D (reversed)
        ADIEncoder{'E', 'F'}  		// middle encoder in ADI ports E & F
    )
    .withDimensions(
        AbstractMotor::gearset::green,	//green gear cartridge
		{{4_in,							//4 inch tracking wheel diameter
		11.5_in},						//11.5 inch wheelbase
		imev5GreenTPR * (1.0 / 1.0)}	//1:1 external gear ratio
	)
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

    //set position to (0,0) and orientation to 0
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
    lowerManipulator.tarePosition();

    //move 10 deg clockwise at 200 rpm
    lowerManipulator.moveRelative(10, 200);

    //move to 10 deg (absolute) at 200 rpm
    lowerManipulator.moveAbsolute(10, 200);
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

    //motor speeds
    const int driveSpeed = 200;
    const int intakeSpeed = 600;
    const int manipulatorSpeed = 100;

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
        for(int i = 0; i < sizeof(vels); i++) vels[i] += leftY;

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

        //cap all vels at 1 and convert percentages to rpm
        for(int i = 0; i < sizeof(vels); i++){
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


		pros::delay(10);  //wait to save resources (prevent brain from frying)
	}
}
