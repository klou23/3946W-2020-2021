#include "main.h"
#include "globals.hpp"
#include <cstdlib>

/********** Variables **********/
lv_obj_t *tabview;
//auton selector
lv_obj_t *btnAutonRed;
lv_obj_t *btnAutonBlue;
lv_obj_t *btnAuton1;
lv_obj_t *btnAuton2;
lv_obj_t *btnAuton3;
lv_obj_t *btnAuton4;
lv_obj_t *autonDescription;
//motor temp bars
lv_obj_t *frontLeftDriveTempBar;
lv_obj_t *frontRightDriveTempBar;
lv_obj_t *backLeftDriveTempBar;
lv_obj_t *backRightDriveTempBar;
lv_obj_t *lowerManipulatorTempBar;
lv_obj_t *upperManipulatorTempBar;
lv_obj_t *leftIntakeTempBar;
lv_obj_t *rightIntakeTempBar;
//motor temp labels
lv_obj_t *frontLeftDriveTempLabel;
lv_obj_t *frontRightDriveTempLabel;
lv_obj_t *backLeftDriveTempLabel;
lv_obj_t *backRightDriveTempLabel;
lv_obj_t *lowerManipulatorTempLabel;
lv_obj_t *upperManipulatorTempLabel;
lv_obj_t *leftIntakeTempLabel;
lv_obj_t *rightIntakeTempLabel;
//motor temp styles
lv_style_t *greenInnerStyle;
lv_style_t *orangeInnerStyle;
lv_style_t *yellowInnerStyle;
lv_style_t *redInnerStyle;

/********** UI Functions **********/

void createAutonSelectorTab(lv_obj_t *parent){
    /** DO NOT TOUCH, SPACING IS GOOD **/
    //create styles for red auton button
    lv_style_t *redReleasedStyle = (lv_style_t *)(malloc(sizeof(lv_style_t)));
    lv_style_t *redPressedStyle = (lv_style_t *)(malloc(sizeof(lv_style_t)));
    lv_style_t *redToggleReleasedStyle = (lv_style_t *)(malloc(sizeof(lv_style_t)));
    lv_style_t *redTogglePressedStyle = (lv_style_t *)(malloc(sizeof(lv_style_t)));
    createButtonStyle(redReleasedStyle, 230, 0, 0, 49, 48, 49, 0, 2, 255, 255, 255);
    createButtonStyle(redPressedStyle, 250, 20, 20, 49, 48, 49, 0, 2, 255, 255, 255);
    createButtonStyle(redToggleReleasedStyle, 230, 0, 0, 255, 255, 255, 0, 2, 255, 255, 255);
    createButtonStyle(redTogglePressedStyle, 250, 20, 20, 255, 255, 255, 0, 2, 255, 255, 255);

    //create red auton button
    btnAutonRed = createToggleButtonWithStyle(parent, 30, 0, 195, 50, redPressedStyle, redReleasedStyle, redTogglePressedStyle, redToggleReleasedStyle, "RED");
    lv_btn_set_action(btnAutonRed, LV_BTN_ACTION_CLICK, setAutonRed);

    //create styles for blue auton button
    lv_style_t *blueReleasedStyle = (lv_style_t *)(malloc(sizeof(lv_style_t)));
    lv_style_t *bluePressedStyle = (lv_style_t *)(malloc(sizeof(lv_style_t)));
    lv_style_t *blueToggleReleasedStyle = (lv_style_t *)(malloc(sizeof(lv_style_t)));
    lv_style_t *blueTogglePressedStyle = (lv_style_t *)(malloc(sizeof(lv_style_t)));
    createButtonStyle(blueReleasedStyle, 0, 0, 230, 49, 48, 49, 0, 2, 255, 255, 255);
    createButtonStyle(bluePressedStyle, 20, 20, 250, 49, 48, 49, 0, 2, 255, 255, 255);
    createButtonStyle(blueToggleReleasedStyle, 0, 0, 230, 255, 255, 255, 0, 2, 255, 255, 255);
    createButtonStyle(blueTogglePressedStyle, 20, 20, 250, 255, 255, 255, 0, 2, 255, 255, 255);

    //create blue auton button
    btnAutonBlue = createToggleButtonWithStyle(parent, 255, 20, 195, 50, bluePressedStyle, blueReleasedStyle, blueTogglePressedStyle, blueToggleReleasedStyle, "BLUE");
    lv_btn_set_action(btnAutonBlue, LV_BTN_ACTION_CLICK, setAutonBlue);

    //create styles for selection buttons
    lv_style_t *selectionReleasedStyle = (lv_style_t *)(malloc(sizeof(lv_style_t)));
    lv_style_t *selectionPressedStyle = (lv_style_t *)(malloc(sizeof(lv_style_t)));
    lv_style_t *selectionToggleReleasedStyle = (lv_style_t *)(malloc(sizeof(lv_style_t)));
    lv_style_t *selectionTogglePressedStyle = (lv_style_t *)(malloc(sizeof(lv_style_t)));
    createButtonStyle(selectionReleasedStyle, 125, 125, 125, 49, 48, 49, 0, 2, 255, 255, 255);
    createButtonStyle(selectionPressedStyle, 145, 145, 145, 49, 48, 49, 0, 2, 255, 255, 255);
    createButtonStyle(selectionTogglePressedStyle, 145, 145, 145, 255, 255, 255, 0, 2, 255, 255, 255);
    createButtonStyle(selectionToggleReleasedStyle, 125, 125, 125, 255, 255, 255, 0, 2, 255, 255, 255);

    //create auton selection buttons
    btnAuton1 = createToggleButtonWithStyle(parent, 11, 70, 107, 50, selectionPressedStyle, selectionReleasedStyle, selectionTogglePressedStyle, selectionToggleReleasedStyle, "Auton 1");
    btnAuton2 = createToggleButtonWithStyle(parent, 128, 70, 107, 50, selectionPressedStyle, selectionReleasedStyle, selectionTogglePressedStyle, selectionToggleReleasedStyle, "Auton 2");
    btnAuton3 = createToggleButtonWithStyle(parent, 245, 70, 107, 50, selectionPressedStyle, selectionReleasedStyle, selectionTogglePressedStyle, selectionToggleReleasedStyle, "Auton 3");
    btnAuton4 = createToggleButtonWithStyle(parent, 362, 70, 107, 50, selectionPressedStyle, selectionReleasedStyle, selectionTogglePressedStyle, selectionToggleReleasedStyle, "Auton 4");

    //set auton selection actions
    lv_btn_set_action(btnAuton1, LV_BTN_ACTION_CLICK, setAuton1);
    lv_btn_set_action(btnAuton2, LV_BTN_ACTION_CLICK, setAuton2);
    lv_btn_set_action(btnAuton3, LV_BTN_ACTION_CLICK, setAuton3);
    lv_btn_set_action(btnAuton4, LV_BTN_ACTION_CLICK, setAuton4);

    //create description label
    autonDescription = createLabel(parent, 10, 130, "No Auton Currently Selected");
    lv_obj_align(autonDescription, NULL, LV_ALIGN_CENTER, 0, 50);
}

void createMotorTempTab(lv_obj_t *parent){
    lv_style_t *outerStyle = (lv_style_t *)(malloc(sizeof(lv_style_t)));
    createBarOutsideStyle(outerStyle, 40, 90, 90, 90);

    greenInnerStyle = (lv_style_t *)(malloc(sizeof(lv_style_t)));
    yellowInnerStyle = (lv_style_t *)(malloc(sizeof(lv_style_t)));
    orangeInnerStyle = (lv_style_t *)(malloc(sizeof(lv_style_t)));
    redInnerStyle = (lv_style_t *)(malloc(sizeof(lv_style_t)));
    createBarInsideStyle(greenInnerStyle, 40, 51, 255, 51, 0);
    createBarInsideStyle(yellowInnerStyle, 40, 255, 255, 51, 0);
    createBarInsideStyle(orangeInnerStyle, 40, 255, 128, 0, 0);
    createBarInsideStyle(redInnerStyle, 40, 255, 0, 0, 0);

    frontLeftDriveTempBar = createBarWithStyle(parent, 10, 0, 225, 40, 15, 70, greenInnerStyle, outerStyle);
    frontRightDriveTempBar = createBarWithStyle(parent, 10, 45, 225, 40, 15, 70, greenInnerStyle, outerStyle);
    backLeftDriveTempBar = createBarWithStyle(parent, 10, 87, 225, 40, 15, 70, greenInnerStyle, outerStyle);
    backRightDriveTempBar = createBarWithStyle(parent, 10, 129, 225, 40, 15, 70, greenInnerStyle, outerStyle);
    lowerManipulatorTempBar = createBarWithStyle(parent, 245, 2, 225, 40, 15, 70, greenInnerStyle, outerStyle);
    upperManipulatorTempBar = createBarWithStyle(parent, 245, 63, 225, 40, 15, 70, greenInnerStyle, outerStyle);
    leftIntakeTempBar = createBarWithStyle(parent, 245, 106, 225, 40, 15, 70, greenInnerStyle, outerStyle);
    rightIntakeTempBar = createBarWithStyle(parent, 245, 149, 225, 40, 15, 70, greenInnerStyle, outerStyle);

    lv_bar_set_value(frontLeftDriveTempBar, 40);
    lv_bar_set_value(frontRightDriveTempBar, 40);
    lv_bar_set_value(backLeftDriveTempBar, 40);
    lv_bar_set_value(backRightDriveTempBar, 40);
    lv_bar_set_value(lowerManipulatorTempBar, 40);
    lv_bar_set_value(upperManipulatorTempBar, 40);
    lv_bar_set_value(leftIntakeTempBar, 40);
    lv_bar_set_value(rightIntakeTempBar, 40);


    frontRightDriveTempLabel = createLabel(parent, 20, 71, "#000000 Front Right Drive");
    frontLeftDriveTempLabel = createLabel(parent, 20, 26, "#000000 Front Left Drive");
    backLeftDriveTempLabel = createLabel(parent, 20, 116, "#000000 Back Left Drive");
    backRightDriveTempLabel = createLabel(parent, 20, 161, "#000000 Back Right Drive");
    lowerManipulatorTempLabel = createLabel(parent, 255, 26, "#000000 Lower Manipulator");
    upperManipulatorTempLabel = createLabel(parent, 255, 71, "#000000 Upper Manipulator");
    leftIntakeTempLabel = createLabel(parent, 255, 116, "#000000 Left Intake");
    rightIntakeTempLabel = createLabel(parent, 255, 161, "#000000 Right Intake");

}

void createPIDAdjusterTab(lv_obj_t *parent){
    //TODO: implement tab creator
}

/********** Tournament Template Functions **********/
void initialize() {
    //set position to (0,0) and orientation to 0
    drive->setState({0_in, 0_in, 0_deg});

    //create fonts


    //set UI theme
    lv_theme_t *theme = lv_theme_alien_init(200, NULL);
    lv_theme_set_current(theme);

    //create tabview with tabs
    tabview = lv_tabview_create(lv_scr_act(), NULL);
    createAutonSelectorTab(lv_tabview_add_tab(tabview, "Auton Selector"));
    createMotorTempTab(lv_tabview_add_tab(tabview, "Motor Temps"));
    lv_tabview_add_tab(tabview, "PID Tuner");
}


void disabled() {}

void competition_initialize() {}


