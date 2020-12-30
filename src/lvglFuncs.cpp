//
// Created by Kevin Lou on 12/28/20.
//

#include "main.h"
#include "globals.hpp"

//auton selection functions
lv_res_t setAutonRed(lv_obj_t * button){
    autonColor = RED;
    return LV_RES_OK;
}

lv_res_t setAutonBlue(lv_obj_t * button){
    autonColor = BLUE;
    return LV_RES_OK;
}

lv_res_t setAuton1(lv_obj_t * button){
    autonNum = 1;
    return LV_RES_OK;
}

lv_res_t setAuton2(lv_obj_t * button){
    autonNum = 2;
    return LV_RES_OK;
}

lv_res_t setAuton3(lv_obj_t * button){
    autonNum = 3;
    return LV_RES_OK;
}

lv_res_t setAuton4(lv_obj_t * button){
    autonNum = 4;
    return LV_RES_OK;
}