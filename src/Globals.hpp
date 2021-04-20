/**
 * @file
 * @brief Allows for global variables and functions
 */

#ifndef PROS_OKAPI_GLOBALS_HPP
#define PROS_OKAPI_GLOBALS_HPP

#include "main.h"

/**
 * Stores the currently selected auton side.
 */
extern int autonColor;
/**
 * Stores the currently selected auton routine.
 */
extern int autonNum;

/**
 * Print the given string to the log on the brain screen
 *
 * @param s
 *          The string that will be printed to the brain
 */
void print(string s);

/**
 * Print the given int to the log on the brain screen
 *
 * @param s
 *          The int that will be printed to the brain
 */
void print(int s);

/**
 * Print the given string to the log on the brain screen with the specified color
 *
 * @param s
 *          The string that will be printed to the brain
 * @param color
 *          The string representing the hex value of the color of the text to
 *          be printed
 */
void printSpecial(string s, string color);

#endif //PROS_OKAPI_GLOBALS_HPP
