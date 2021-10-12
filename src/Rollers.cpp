#include "Rollers.hpp"

Rollers::Rollers(const Motor &leftIntake, const Motor &rightIntake, const Motor &lowerManipulator,
                 const Motor &upperManipulator) : leftIntake(leftIntake), rightIntake(rightIntake),
                                                  lowerManipulator(lowerManipulator),
                                                  upperManipulator(upperManipulator) {}

void Rollers::stopRollers() {
    leftIntake.move_velocity(0);
    rightIntake.move_velocity(0);
}

void Rollers::stopManipulators() {
    lowerManipulator.move_velocity(0);
    upperManipulator.move_velocity(0);
}

void Rollers::stopAll() {
    leftIntake.move_velocity(0);
    rightIntake.move_velocity(0);
    lowerManipulator.move_velocity(0);
    upperManipulator.move_velocity(0);
}

void Rollers::intake(int vel) {
    leftIntake.move_velocity(vel);
    rightIntake.move_velocity(vel);
}

void Rollers::intake(int vel, int time, bool blocking) {
    leftIntake.move_velocity(vel);
    rightIntake.move_velocity(vel);

    if(blocking){
        delay(time);
        stopRollers();
    }else{
        Task task{[=] {
            delay(time);
            stopRollers();
        }};
    }
}

void Rollers::extake(int vel) {
    leftIntake.move_velocity(-vel);
    rightIntake.move_velocity(-vel);
}

void Rollers::extake(int vel, int time, bool blocking) {
    leftIntake.move_velocity(-vel);
    rightIntake.move_velocity(-vel);

    if(blocking){
        delay(time);
        stopRollers();
    }else{
        Task task{[=] {
           delay(time);
           stopRollers();
        }};
    }
}

void Rollers::shoot(int vel) {
    lowerManipulator.move_velocity(vel);
    upperManipulator.move_velocity(vel);
}

void Rollers::shoot(int vel, int time, bool blocking) {
    lowerManipulator.move_velocity(vel);
    upperManipulator.move_velocity(vel);

    if(blocking){
        delay(time);
        stopManipulators();
    }else{
        Task task{[=] {
            delay(time);
            stopManipulators();
        }};
    }
}

void Rollers::shootRev(int vel) {
    lowerManipulator.move_velocity(-vel);
    upperManipulator.move_velocity(-vel);
}

void Rollers::shootRev(int vel, int time, bool blocking) {
    lowerManipulator.move_velocity(-vel);
    upperManipulator.move_velocity(-vel);

    if(blocking){
        delay(time);
        stopManipulators();
    }else{
        Task task{[=] {
           delay(time);
           stopManipulators();
        }};
    }
}

void Rollers::poop(int vel) {
    lowerManipulator.move_velocity(vel);
    upperManipulator.move_velocity(-vel);
}

void Rollers::poop(int vel, int time, bool blocking) {
    lowerManipulator.move_velocity(vel);
    upperManipulator.move_velocity(-vel);

    if(blocking){
        delay(time);
        stopManipulators();
    }else{
        Task task{[=] {
            delay(time);
            stopManipulators();
        }};
    }
}

void Rollers::cycle(int vel) {
    leftIntake.move_velocity(vel);
    rightIntake.move_velocity(vel);
    lowerManipulator.move_velocity(vel);
    upperManipulator.move_velocity(vel);
}

void Rollers::cycle(int vel, int time, bool blocking) {
    leftIntake.move_velocity(vel);
    rightIntake.move_velocity(vel);
    lowerManipulator.move_velocity(vel);
    upperManipulator.move_velocity(vel);

    if(blocking){
        delay(time);
        stopManipulators();
    }else{
        Task task{[=] {
            delay(time);
            stopManipulators();
        }};
    }
}

void Rollers::cycleRev(int vel) {
    leftIntake.move_velocity(-vel);
    rightIntake.move_velocity(-vel);
    lowerManipulator.move_velocity(-vel);
    upperManipulator.move_velocity(-vel);
}

void Rollers::cycleRev(int vel, int time, bool blocking) {
    leftIntake.move_velocity(vel);
    rightIntake.move_velocity(vel);
    lowerManipulator.move_velocity(-vel);
    upperManipulator.move_velocity(-vel);

    if(blocking){
        delay(time);
        stopAll();
    }else{
        Task task{[=] {
            delay(time);
            stopAll();
        }};
    }
}

void Rollers::flipOutHood(){
    upperManipulator.move_velocity(-300);
    delay(500);
    stopAll();
}

void Rollers::flipOut() {
    extake(300);
    upperManipulator.move_velocity(-300);
    delay(500);
    stopAll();
}

void Rollers::primeBalls(int vel) {
    leftIntake.move_velocity(vel);
    rightIntake.move_velocity(vel);
    lowerManipulator.move_velocity(vel);
}

void Rollers::primeBalls(int vel, int time, bool blocking) {
    leftIntake.move_velocity(vel);
    rightIntake.move_velocity(vel);
    lowerManipulator.move_velocity(vel);
    if(blocking){
        delay(time);
        stopAll();
    }else{
        Task task{[=] {
           delay(time);
           stopAll();
        }};
    }
}

void Rollers::driverControl(CustomController master, CustomController partner) {
    double intakeVel = 0;
    double lowerManipulatorVel = 0;
    double upperManipulatorVel = 0;

    if(partner.pressed(BUTTON_A)){
        upperManipulatorVel = -0.75;
    }else if(master.pressed(BUTTON_R1)){
        intakeVel = 1;
        lowerManipulatorVel = 1;
        upperManipulatorVel = 1;
    }else if(master.pressed(BUTTON_L1)){
        lowerManipulatorVel = 1;
        upperManipulatorVel = 1;
    }else if(partner.pressed(BUTTON_L1)){
        intakeVel = -1;
        lowerManipulatorVel = -1;
        upperManipulatorVel = -1;
    }else if(partner.pressed(BUTTON_L2)){
        lowerManipulatorVel = -1;
        upperManipulatorVel = -1;
    }else if(partner.getLeftY() > 0.05){
        lowerManipulatorVel = partner.getLeftY();
        upperManipulatorVel = -partner.getLeftY();

        if(partner.pressed(BUTTON_R1)){
            intakeVel = 1;
        }else if(partner.pressed(BUTTON_R2)){
            intakeVel = -1;
        }
    }else if(partner.pressed(BUTTON_R1)){
        intakeVel = 1;
    }else if(partner.pressed(BUTTON_R2)){
        intakeVel = -1;
    }

    leftIntake.move_velocity(intakeVel * 600);
    rightIntake.move_velocity(intakeVel * 600);
    lowerManipulator.move_velocity(lowerManipulatorVel * 600);
    upperManipulator.move_velocity(upperManipulatorVel * 600);
}
