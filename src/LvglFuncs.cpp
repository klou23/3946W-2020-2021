#include "LvglFuncs.hpp"
#include "main.h"
#include "Globals.hpp"
#include "Initialize.hpp"
#include "Constants.hpp"

//Constants
const char *auton1Description = "1 ball";
const char *auton2Description = "2 balls";
const char *auton3Description = "3 balls";
const char *auton4Description = "support E";

//auton selection functions
lv_res_t setAutonRed(lv_obj_t *button){

    if(lv_btn_get_state(button) == LV_BTN_STYLE_PR || lv_btn_get_state(button) == LV_BTN_STYLE_REL){
        //keep toggled
        lv_btn_set_state(btnAutonRed, LV_BTN_STATE_TGL_REL);
    }

    //set auton color to red
    autonColor = AUTON_RED;

    //release blue button
    lv_btn_set_state(btnAutonBlue, LV_BTN_STATE_REL);

    return LV_RES_OK;
}

lv_res_t setAutonBlue(lv_obj_t *button){

    if(lv_btn_get_state(button) == LV_BTN_STATE_REL || lv_btn_get_state(button) == LV_BTN_STATE_PR){
        //keep toggled
        lv_btn_set_state(btnAutonBlue, LV_BTN_STATE_TGL_REL);
    }

    //set auton color to blue
    autonColor = AUTON_BLUE;

    //release red button
    lv_btn_set_state(btnAutonRed, LV_BTN_STATE_REL);

    return LV_RES_OK;
}

lv_res_t setAuton1(lv_obj_t *button){

    if(lv_btn_get_state(button) == LV_BTN_STATE_REL || lv_btn_get_state(button) == LV_BTN_STATE_PR){
        //keep toggled
        lv_btn_set_state(autonDescription, LV_BTN_STATE_TGL_REL);
    }

    //set auton num to 1
    autonNum = 1;

    //release other buttons
    lv_btn_set_state(btnAuton2, LV_BTN_STATE_REL);
    lv_btn_set_state(btnAuton3, LV_BTN_STATE_REL);
    lv_btn_set_state(btnAuton4, LV_BTN_STATE_REL);

    lv_label_set_text(autonDescription, auton1Description);
    lv_obj_align(autonDescription, NULL, LV_ALIGN_CENTER, 0, 50);

    return LV_RES_OK;
}

lv_res_t setAuton2(lv_obj_t *button){

    if(lv_btn_get_state(button) == LV_BTN_STATE_REL || lv_btn_get_state(button) == LV_BTN_STATE_PR){
        //keep toggled
        lv_btn_set_state(btnAuton2, LV_BTN_STATE_TGL_REL);
    }

    //set auton num to 2
    autonNum = 2;

    //release other buttons
    lv_btn_set_state(btnAuton1, LV_BTN_STATE_REL);
    lv_btn_set_state(btnAuton3, LV_BTN_STATE_REL);
    lv_btn_set_state(btnAuton4, LV_BTN_STATE_REL);

    lv_label_set_text(autonDescription, auton2Description);
    lv_obj_align(autonDescription, NULL, LV_ALIGN_CENTER, 0, 50);

    return LV_RES_OK;
}

lv_res_t setAuton3(lv_obj_t *button){

    if(lv_btn_get_state(button) == LV_BTN_STATE_REL || lv_btn_get_state(button) == LV_BTN_STATE_PR){
        //keep toggled
        lv_btn_set_state(btnAuton3, LV_BTN_STATE_TGL_REL);
    }

    //set auton num to 3
    autonNum = 3;

    //release other buttons
    lv_btn_set_state(btnAuton1, LV_BTN_STATE_REL);
    lv_btn_set_state(btnAuton2, LV_BTN_STATE_REL);
    lv_btn_set_state(btnAuton4, LV_BTN_STATE_REL);

    lv_label_set_text(autonDescription, auton3Description);
    lv_obj_align(autonDescription, NULL, LV_ALIGN_CENTER, 0, 50);

    return LV_RES_OK;
}

lv_res_t setAuton4(lv_obj_t *button){

    if(lv_btn_get_state(button) == LV_BTN_STATE_REL || lv_btn_get_state(button) == LV_BTN_STATE_PR){
        //keep toggled
        lv_btn_set_state(btnAuton4, LV_BTN_STATE_TGL_REL);
    }

    //set auton num to 4
    autonNum = 4;

    //release other buttons
    lv_btn_set_state(btnAuton1, LV_BTN_STATE_REL);
    lv_btn_set_state(btnAuton2, LV_BTN_STATE_REL);
    lv_btn_set_state(btnAuton3, LV_BTN_STATE_REL);

    lv_label_set_text(autonDescription, auton4Description);
    lv_obj_align(autonDescription, NULL, LV_ALIGN_CENTER, 0, 50);

    return LV_RES_OK;
}