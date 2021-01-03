#include "main.h"
#include "globals.hpp"

//create button no label
lv_obj_t * createButton(lv_obj_t * parent, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height){
    //create button
    lv_obj_t * button = lv_btn_create(parent, NULL);
    lv_obj_set_x(button, x);
    lv_obj_set_y(button, y);
    lv_obj_set_size(button, width, height);
    lv_btn_set_toggle(button, false);

    //return pointer
    return button;
}

//create button no label with style
lv_obj_t * createButtonWithStyle(lv_obj_t * parent, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height, lv_style_t *releasedStyle, lv_style_t *pressedStyle){
    //create button
    lv_obj_t * button = lv_btn_create(parent, NULL);
    lv_obj_set_x(button, x);
    lv_obj_set_y(button, y);
    lv_obj_set_size(button, width, height);
    lv_btn_set_toggle(button, false);

    //set style of button
    lv_btn_set_style(button, LV_BTN_STYLE_PR, pressedStyle);
    lv_btn_set_style(button, LV_BTN_STYLE_REL, releasedStyle);

    //return pointer
    return button;
}

//create button with label
lv_obj_t * createButton(lv_obj_t * parent, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height, const char * labelText){
    //create button
    lv_obj_t * button = lv_btn_create(parent, NULL);
    lv_obj_set_x(button, x);
    lv_obj_set_y(button, y);
    lv_obj_set_size(button, width, height);
    lv_btn_set_toggle(button, false);

    //add label as subcomponent
    lv_obj_t * label = lv_label_create(button, NULL);
    lv_label_set_text(label, labelText);
    lv_obj_align(label, NULL, LV_ALIGN_CENTER, 0, 0);

    //return pointer
    return button;
}

//create button with label with style
lv_obj_t * createButtonWithStyle(lv_obj_t * parent, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height, lv_style_t *releasedStyle, lv_style_t *pressedStyle, const char * labelText){
    //create button
    lv_obj_t * button = lv_btn_create(parent, NULL);
    lv_obj_set_x(button, x);
    lv_obj_set_y(button, y);
    lv_obj_set_size(button, width, height);
    lv_btn_set_toggle(button, false);

    //set style of button
    lv_btn_set_style(button, LV_BTN_STYLE_PR, pressedStyle);
    lv_btn_set_style(button, LV_BTN_STYLE_REL, pressedStyle);

    //add label as subcomponent
    lv_obj_t * label = lv_label_create(button, NULL);
    lv_label_set_text(label, labelText);
    lv_obj_align(label, NULL, LV_ALIGN_CENTER, 0, 0);

    //return pointer
    return button;
}

//create toggle button no label
lv_obj_t * createToggleButton(lv_obj_t * parent, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height){
    //create button
    lv_obj_t * button = lv_btn_create(parent, NULL);
    lv_obj_set_x(button, x);
    lv_obj_set_y(button, y);
    lv_obj_set_size(button, width, height);
    lv_btn_set_toggle(button, true);

    //return pointer
    return button;
}

//create toggle button no label with style
lv_obj_t * createToggleButtonWithStyle(lv_obj_t * parent, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height, lv_style_t *pressedStyle, lv_style_t *releasedStyle, lv_style_t *togglePressedStyle, lv_style_t *toggleReleasedStyle){
    //create button
    lv_obj_t * button = lv_btn_create(parent, NULL);
    lv_obj_set_x(button, x);
    lv_obj_set_y(button, y);
    lv_obj_set_size(button, width, height);
    lv_btn_set_toggle(button, true);

    //set style of button
    lv_btn_set_style(button, LV_BTN_STYLE_PR, pressedStyle);
    lv_btn_set_style(button, LV_BTN_STYLE_REL, releasedStyle);
    lv_btn_set_style(button, LV_BTN_STYLE_TGL_PR, togglePressedStyle);
    lv_btn_set_style(button, LV_BTN_STYLE_TGL_REL, toggleReleasedStyle);

    //return pointer
    return button;
}

//create toggle button with label
lv_obj_t * createToggleButton(lv_obj_t * parent, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height, const char * labelText){
    //create button
    lv_obj_t * button = lv_btn_create(parent, NULL);
    lv_obj_set_x(button, x);
    lv_obj_set_y(button, y);
    lv_obj_set_size(button, width, height);
    lv_btn_set_toggle(button, true);

    //add label as subcomponent
    lv_obj_t * label = lv_label_create(button, NULL);
    lv_label_set_text(label, labelText);
    lv_obj_align(label, NULL, LV_ALIGN_CENTER, 0, 0);

    //return pointer
    return button;
}

//create toggle button with style with label
lv_obj_t * createToggleButtonWithStyle(lv_obj_t * parent, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height, lv_style_t *pressedStyle, lv_style_t *releasedStyle, lv_style_t *togglePressedStyle, lv_style_t *toggleReleasedStyle, const char * labelText){
    //create button
    lv_obj_t * button = lv_btn_create(parent, NULL);
    lv_obj_set_x(button, x);
    lv_obj_set_y(button, y);
    lv_obj_set_size(button, width, height);
    lv_btn_set_toggle(button, true);

    //set style of button
    lv_btn_set_style(button, LV_BTN_STYLE_PR, pressedStyle);
    lv_btn_set_style(button, LV_BTN_STYLE_REL, releasedStyle);
    lv_btn_set_style(button, LV_BTN_STYLE_TGL_PR, togglePressedStyle);
    lv_btn_set_style(button, LV_BTN_STYLE_TGL_REL, toggleReleasedStyle);

    //add label as subcomponent
    lv_obj_t * label = lv_label_create(button, NULL);
    lv_label_set_text(label, labelText);
    lv_obj_align(label, NULL, LV_ALIGN_CENTER, 0, 0);

    //return pointer
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

//create button style
void createButtonStyle(lv_style_t * style, uint8_t bodyR, uint8_t bodyG, uint8_t bodyB, uint8_t borderR, uint8_t borderG, uint8_t borderB, int radius, int borderWeight, uint8_t textR, uint8_t textG, uint8_t textB){
    lv_style_copy(style, &lv_style_plain);
    style->body.main_color = LV_COLOR_MAKE(bodyR, bodyG, bodyB);
    style->body.grad_color = LV_COLOR_MAKE(bodyR, bodyG, bodyB);
    style->body.border.color = LV_COLOR_MAKE(borderR, borderG, borderB);
    style->body.border.width = borderWeight;
    style->body.radius = radius;
    style->text.color = LV_COLOR_MAKE(textR, textG, textB);
}
