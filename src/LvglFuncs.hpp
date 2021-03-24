//
// Created by Kevin Lou on 3/21/21.
//

/**
 * @file
 */

#ifndef PROS_OKAPI_LVGLFUNCS_HPP
#define PROS_OKAPI_LVGLFUNCS_HPP

#include "Globals.hpp"

/**
 * Sets the red autonomous selection button to selected and the blue
 * autonomous selection button to unselected. Then sets the value of
 * autonColor to AUTON_RED
 *
 * @param button
 *          a pointer to the lvgl button that is calling the function
 * @return if the function finishes successfully, it returns LV_RES_OK
 */
lv_res_t setAutonRed(lv_obj_t *button);

/**
 * Sets the blue autonomous selection button to selected and the red
 * autonomous selection button to unselected. Then sets the value of
 * autonColor to AUTON_BLUE
 *
 * @param button
 *          a pointer to the lvgl button that is calling the function
 * @return  if the function finished successfully, it returns LV_RES_OK
 */
lv_res_t setAutonBlue(lv_obj_t *button);

/**
 * Sets the first autonomous selection button to selected and the
 * other three autonomous selection buttons to unselected. Then sets
 * the value of autonNum to 1. Then sets the auton description label
 * to the description for the first auton
 *
 * @param button
 *          a pointer to the lvgl button that is calling the function
 * @return  if the function finished successfully, it returns LV_RES_OK
 */
lv_res_t setAuton1(lv_obj_t *button);

/**
 * Sets the second autonomous selection button to selected and the
 * other three autonomous selection buttons to unselected. Then sets
 * the value of autonNum to 2. Then sets the auton description label
 * to the description for the second auton
 *
 * @param button
 *          a pointer to the lvgl button that is calling the function
 * @return  if the function finished successfully, it returns LV_RES_OK
 */
lv_res_t setAuton2(lv_obj_t *button);

/**
 * Sets the third autonomous selection button to selected and the
 * other three autonomous selection buttons to unselected. Then sets
 * the value of autonNum to 3. Then sets the auton description label
 * to the description for the third auton
 *
 * @param button
 *          a pointer to the lvgl button that is calling the function
 * @return  if the function finished successfully, it returns LV_RES_OK
 */
lv_res_t setAuton3(lv_obj_t *button);

/**
 * Sets the fourth autonomous selection button to selected and the
 * other three autonomous selection buttons to unselected. Then sets
 * the value of autonNum to 4. Then sets the auton description label
 * to the description for the fourth auton
 *
 * @param button
 *          a pointer to the lvgl button that is calling the function
 * @return  if the function finished successfully, it returns LV_RES_OK
 */
lv_res_t setAuton4(lv_obj_t *button);


#endif //PROS_OKAPI_LVGLFUNCS_HPP
