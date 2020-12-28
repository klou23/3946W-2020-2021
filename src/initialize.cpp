#include "main.h"
#include "globals.hpp"

/********** Variables **********/
lv_obj_t * tabview;

/********** Tournament Template Functions **********/
void initialize() {
    //set position to (0,0) and orientation to 0
    drive->setState({0_in, 0_in, 0_deg});

    tabview = lv_tabview_create(lv_scr_act(), NULL);


}

void disabled() {}

void competition_initialize() {}

/********** UI Functions **********/
void createAutonSelectorTab(lv_obj_t * parent){
    //TODO: implement tab creator
}

void createMotorTempTab(lv_obj_t * parent){
    //TODO: implement tab creator
}

void createPIDAdjustedTb(lv_obj_t * parent){
    //TODO: implement tab creator
}
