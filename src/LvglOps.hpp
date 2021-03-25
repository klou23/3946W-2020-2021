/**
 * @file
 * @brief Functions to be called by the UI
 */

#ifndef PROS_OKAPI_LVGLOPS_HPP
#define PROS_OKAPI_LVGLOPS_HPP

#include "Globals.hpp"

/**
 * Creates a new lvgl button
 *
 * @param parent
 *          a pointer to the parent window to create the button on
 * @param x
 *          the x position of top left corner of the button
 * @param y
 *          the y position of top left corner of the button
 * @param width
 *          the width of the button
 * @param height
 *          the height of the button
 * @return a pointer to the new lvgl button
 */
lv_obj_t * createButton(lv_obj_t * parent, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height);

/**
 * Creates a new lvgl button with the given styles
 *
 * @param parent
 *          a pointer to the parent window to create the button on
 * @param x
 *          the x position of top left corner of the button
 * @param y
 *          the y position of top left corner of the button
 * @param width
 *          the width of the button
 * @param height
 *          the height of the button
 * @param releasedStyle
 *          a style for the button when it is released
 * @param pressedStyle
 *          a style for the button when it is pressed
 * @return a pointer to the new lvgl button
 */
lv_obj_t * createButtonWithStyle(lv_obj_t * parent, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height, lv_style_t *releasedStyle, lv_style_t *pressedStyle);

/**
 * Creates a new lvgl button with the given labelText
 *
 * @param parent
 *          a pointer to the parent window to create the button on
 * @param x
 *          the x position of top left corner of the button
 * @param y
 *          the y position of top left corner of the button
 * @param width
 *          the width of the button
 * @param height
 *          the height of the button
 * @param labelText
 *          the text to be displayed on the button
 * @return a pointer to the new lvgl button
 */
lv_obj_t * createButton(lv_obj_t * parent, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height, const char * labelText);

/**
 * Creates a new lvgl button with the given labelText and styles
 *
 * @param parent
 *          a pointer to the parent window to create the button on
 * @param x
 *          the x position of top left corner of the button
 * @param y
 *          the y position of top left corner of the button
 * @param width
 *          the width of the button
 * @param height
 *          the height of the button
 * @param releasedStyle
 *          a style for the button when it is released
 * @param pressedStyle
 *          a style for the button when it is pressed
 * @param labelText
 *          the text to be displayed on the button
 * @return a pointer to the new lvgl button
 */
lv_obj_t * createButtonWithStyle(lv_obj_t * parent, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height, lv_style_t *releasedStyle, lv_style_t *pressedStyle, const char * labelText);

/**
 * Creates a new toggleable lvgl button
 *
 * @param parent
 *          a pointer to the parent window to create the button on
 * @param x
 *          the x position of top left corner of the button
 * @param y
 *          the y position of top left corner of the button
 * @param width
 *          the width of the button
 * @param height
 *          the height of the button
 * @return a pointer to the new lvgl button
 */
lv_obj_t * createToggleButton(lv_obj_t * parent, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height);

/**
 * Creates a new toggleable lvgl button with the given styles
 *
 * @param parent
 *          a pointer to the parent window to create the button on
 * @param x
 *          the x position of top left corner of the button
 * @param y
 *          the y position of top left corner of the button
 * @param width
 *          the width of the button
 * @param height
 *          the height of the button
 * @param pressedStyle
 *          a style for the button when it is pressed and not toggled
 * @param releasedStyle
 *          a style for the button when it is released and not toggled
 * @param togglePressedStyle
 *          a style for the button when it is pressed and toggled
 * @param toggleReleasedStyle
 *          a style for the button when it is released and toggled
 * @return a pointer to the new lvgl button
 */
lv_obj_t * createToggleButtonWithStyle(lv_obj_t * parent, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height, lv_style_t *pressedStyle, lv_style_t *releasedStyle, lv_style_t *togglePressedStyle, lv_style_t *toggleReleasedStyle);

/**
 * Creates a new toggleable lvgl button with the given labelText
 *
 * @param parent
 *          a pointer to the parent window to create the button on
 * @param x
 *          the x position of top left corner of the button
 * @param y
 *          the y position of top left corner of the button
 * @param width
 *          the width of the button
 * @param height
 *          the height of the button
 * @param labelText
 *          the text to be displayed on the button
 * @return a pointer to the new lvgl button
 */
lv_obj_t * createToggleButton(lv_obj_t * parent, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height, const char * labelText);

/**
 * Creates a new toggleable lvgl button with the given labelText and styles
 *
 * @param parent
 *          a pointer to the parent window to create the button on
 * @param x
 *          the x position of top left corner of the button
 * @param y
 *          the y position of top left corner of the button
 * @param width
 *          the width of the button
 * @param height
 *          the height of the button
 * @param pressedStyle
 *          a style for the button when it is pressed and not toggled
 * @param releasedStyle
 *          a style for the button when it is released and not toggled
 * @param togglePressedStyle
 *          a style for the button when it is pressed and toggled
 * @param toggleReleasedStyle
 *          a style for the button when it is released and toggled
 * @param labelText
 *          the text to be displayed on the button
 * @return a pointer to the new lvgl button
 */
lv_obj_t * createToggleButtonWithStyle(lv_obj_t * parent, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height, lv_style_t *pressedStyle, lv_style_t *releasedStyle, lv_style_t *togglePressedStyle, lv_style_t *toggleReleasedStyle, const char * labelText);

/**
 * Creates a new lvgl label
 *
 * @param parent
 *          a pointer to the parent window to create the label on
 * @param x
 *          the x position of the top left corner of the label
 * @param y
 *          the y position of the top left corner of the label
 * @param text
 *          the text to be displayed on the label
 * @return a pointer to the new lvgl label
 */
lv_obj_t * createLabel(lv_obj_t * parent, lv_coord_t x, lv_coord_t y, const char * text);

/**
 * Creates a new lvgl label with the given style
 *
 * @param parent
 *          a pointer to the parent window to create the label on
 * @param x
 *          the x position of the top left corner of the label
 * @param y
 *          the y position of the top left corner of the label
 * @param style
 *          the lvgl style for the label
 * @param text
 *          the text to be displayed on the label
 * @return a pointer to the new lvgl label
 */
lv_obj_t * createLabelWithStyle(lv_obj_t * parent, lv_coord_t x, lv_coord_t y, lv_style_t *style, const char * text);

/**
 * Creates a new lvgl style for a label
 *
 * @param style
 *          a pointer to where the style is stored
 * @param bodyR
 *          red value for the color of the button body
 * @param bodyG
 *          green value for the color of the button body
 * @param bodyB
 *          blue value for the color of the button body
 * @param borderR
 *          red value for the color of the button border
 * @param borderG
 *          green value for the color of the button border
 * @param borderB
 *          blue value for the color of the button border
 * @param radius
 *          radius of the rounded corners of the button
 * @param borderWeight
 *          weight of the border of the button
 * @param textR
 *          red value for the color of the text
 * @param textG
 *          green value for the color of the text
 * @param textB
 *          blue value for the color of the text
 */
void createButtonStyle(lv_style_t * style, uint8_t bodyR, uint8_t bodyG, uint8_t bodyB, uint8_t borderR, uint8_t borderG, uint8_t borderB, int radius, int borderWeight, uint8_t textR, uint8_t textG, uint8_t textB);

/**
 * Creates a new lvgl style for the outside of a bar
 *
 * @param style
 *          a pointer to where the style is stored
 * @param radius
 *          radius of the rounded corners of the bar
 * @param r
 *          red value for the outside of the bar
 * @param g
 *          green value for the outside of the bar
 * @param b
 *          blue value for the outside of the bar
 */
void createBarOutsideStyle(lv_style_t *style, int radius, uint8_t r, uint8_t g, uint8_t b);

/**
 * Creates a new lvgl style for the inside of a bar
 *
 * @param style
 *          a pointer to where the style is stored
 * @param radius
 *          radius of the rounder corners of the inside of the bar
 * @param r
 *          red value for the inside of the bar
 * @param g
 *          green value for the inside of the bar
 * @param b
 *          blue value for the inside of the bar
 * @param padding
 *          amount of space between inside and outside of the bar
 */
void createBarInsideStyle(lv_style_t *style, int radius, uint8_t r, uint8_t g, uint8_t b, int padding);

/**
 * Creates a new lvgl bar
 *
 * @param parent
 *          a pointer to the parent window to create the bar on
 * @param x
 *          the x position of the top left corner of the bar
 * @param y
 *          the y position of the top left corner of the bar
 * @param width
 *          the width of the bar
 * @param height
 *          the height of the bar
 * @param min
 *          the minimum value displayed in the bar
 * @param max
 *          the maximum value displayed in the bar
 * @return a pointer to the new lvgl bar
 */
lv_obj_t *createBar(lv_obj_t *parent, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height, int16_t min, int16_t max);

/**
 * Creates a new lvgl bar with the given styles
 *
 * @param parent
 *          a pointer to the parent window to create the bar on
 * @param x
 *          the x position of the top left corner of the bar
 * @param y
 *          the y position of the top left corner of the bar
 * @param width
 *          the width of the bar
 * @param height
 *          the height of the bar
 * @param min
 *          the minimum value displayed in the bar
 * @param max
 *          the maximum value displayed in the bar
 * @param innerStyle
 *          a style for the inside of the bar
 * @param outerStyle
 *          a style for the outside of the bar
 * @return a point to the new lvgl bar
 */
lv_obj_t *createBarWithStyle(lv_obj_t *parent, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height, int16_t min, int16_t max, lv_style_t *innerStyle, lv_style_t *outerStyle);

#endif //PROS_OKAPI_LVGLOPS_HPP
