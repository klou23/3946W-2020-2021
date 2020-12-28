#include "main.h"
#include "globals.hpp"

//create button with label
lv_obj_t * createButton(lv_obj_t * parent, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height, const char * labelText, bool toggleable = false){
    //create button
    lv_obj_t * button = lv_btn_create(parent, NULL);
    lv_obj_set_x(button, x);
    lv_obj_set_y(button, y);
    lv_obj_set_size(button, width, height);
    lv_btn_set_toggle(button, toggleable);

    //add label as subcomponent
    lv_obj_t * label = lv_label_create(button, NULL);
    lv_label_set_text(label, labelText);
    lv_obj_align(label, NULL, LV_ALIGN_CENTER, 0, 0);

    //return pointer;
    return button;
}

//create button no label
lv_obj_t * createButton(lv_obj_t * parent, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height, bool toggleable = false){
    lv_obj_t * button = lv_btn_create(parent, NULL);
    lv_obj_set_x(button, x);
    lv_obj_set_y(button, y);
    lv_obj_set_size(button, width, height);
    lv_btn_set_toggle(button, toggleable);

    return button;
}

lv_obj_t * createButtonWithStyle(lv_obj_t * parent, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height, const char * labelText, lv_style_t releasedStyle, lv_style_t pressedStyle, bool toggleable = false){
    //create button
    lv_obj_t * button = lv_btn_create(parent, NULL);
    lv_obj_set_x(button, x);
    lv_obj_set_y(button, y);
    lv_obj_set_size(button, width, height);
    lv_btn_set_toggle(button, toggleable);

    //add label as subcomponent
    lv_obj_t * label = lv_label_create(button, NULL);
    lv_label_set_text(label, labelText);
    lv_obj_align(label, NULL, LV_ALIGN_CENTER, 0, 0);

    //style button
    lv_btn_set_style(button, LV_BTN_STYLE_REL, &releasedStyle);
    lv_btn_set_style(button, LV_BTN_STATE_PR, &pressedStyle);
    lv_btn_set_style(button, LV_BTN_STATE_TGL_PR, &pressedStyle);
    lv_btn_set_style(button, LV_BTN_STATE_TGL_REL, &pressedStyle);

    //return pointer;
    return button;
}

lv_obj_t * createButtonWithStyle(lv_obj_t * parent, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height, lv_style_t releasedStyle, lv_style_t pressedStyle, bool toggleable = false){
    lv_obj_t * button = lv_btn_create(parent, NULL);
    lv_obj_set_x(button, x);
    lv_obj_set_y(button, y);
    lv_obj_set_size(button, width, height);
    lv_btn_set_toggle(button, toggleable);

    //style button
    lv_btn_set_style(button, LV_BTN_STYLE_REL, &releasedStyle);
    lv_btn_set_style(button, LV_BTN_STATE_PR, &pressedStyle);
    lv_btn_set_style(button, LV_BTN_STATE_TGL_PR, &pressedStyle);
    lv_btn_set_style(button, LV_BTN_STATE_TGL_REL, &pressedStyle);

    return button;
}

//create label
lv_obj_t * createLabel(lv_obj_t * parent, lv_coord_t x, lv_coord_t y, const char * text){
    lv_obj_t * label = lv_label_create(parent, NULL);
    lv_label_set_text(label, text);
    lv_obj_set_x(label, x);
    lv_obj_set_y(label, y);

    return label;
}
