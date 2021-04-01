/**
 * @file
 * @brief Contains autonomous routines
 */

#ifndef PROS_OKAPI_AUTONOMOUS_HPP
#define PROS_OKAPI_AUTONOMOUS_HPP

#include "main.h"

/**
 * Runs the single score routine (starts on right)
 *
 * Does the following:
 * -# Flips out
 * -# Drives forward
 * -# Turns right to the goal
 * -# Drives up to the goal and intakes the ball in front of the goal
 * -# Shoots the preload into the goal
 * -# Drives backwards away from the goal
 */
void right_auton1();

/**
 * Runs the double score routine (starts on right)
 *
 * Does the following:
 * -# Flips out
 * -# Drives forward
 * -# Turns right to the goal
 * -# Drives up to the goal and intakes the ball in front of the goal
 * -# Shoots the preload into the goal
 * -# Drives backwards away from the goal
 * -# Turns right to the next goal
 * -# Drives up to the goal
 * -# Turns left to face the goal
 * -# Scores a ball in the goal
 * -# Drive backwards away from the goal
 */
void right_auton2();

/**
 * Runs the triple score routine (starts on right)
 *
  * Does the following:
 * -# Flips out
 * -# Drives forward
 * -# Turns right to the goal
 * -# Drives up to the goal and intakes the ball in front of the goal
 * -# Shoots the preload into the goal
 * -# Drives backwards away from the goal
 * -# Turns right to the next goal
 * -# Drives up to the goal
 * -# Scores a ball in the goal
 * -# Drive backwards away from the goal
 * -# Turns right to the third goal
 * -# Drive up to the third goal and intakes the ball in front of the goal
 * -# Scores that ball into the goal
 * -# Drives backwards away from the goal
 *
 * @note This auton can hit the alliance partner if they
 * don't get out of the way
 */
void right_auton3();

/**
 * No auton routine currently implemented
 */
void right_auton4();

/**
 * Runs the single score routine (starts on left)
 *
 * Does the following:
 * -# Flips out
 * -# Drives forward
 * -# Turns left to the goal
 * -# Drives up to the goal and intakes the ball in front of the goal
 * -# Shoots the preload into the goal
 * -# Drives backwards away from the goal
 */
void left_auton1();

/**
 * Runs the double score routine (starts on left)
 *
 * Does the following:
 * -# Flips out
 * -# Drives forward
 * -# Turns left to the goal
 * -# Drives up to the goal and intakes the ball in front of the goal
 * -# Shoots the preload into the goal
 * -# Drives backwards away from the goal
 * -# Turns left to the next goal
 * -# Drives up to the goal
 * -# Scores a ball in the goal
 * -# Drive backwards away from the goal
 */
void left_auton2();

/**
 * Runs the triple score routine (starts on left)
 *
 * Does the following:
 * -# Flips out
 * -# Drives forward
 * -# Turns left to the goal
 * -# Drives up to the goal and intakes the ball in front of the goal
 * -# Shoots the preload into the goal
 * -# Drives backwards away from the goal
 * -# Turns left to the next goal
 * -# Drives up to the goal
 * -# Scores a ball in the goal
 * -# Drives backwards away from the goal
 * -# Turns left to the third goal
 * -# Drive up to the third goal and intakes the ball in front of the goal
 * -# Scores that ball into the goal
 * -# Drives backwards away from the goal
 *
 * @note This auton can hit the alliance partner if they
 * don't get out of the way
 */
void left_auton3();

/**
 * No auton routine currently implemented
 */
void left_auton4();


/**
 * Runs the first programming routine
 *
 * Does the following:
 * -# Flips out
 * -# Drives forward and intakes the ball in front of the robot
 * -# Turns right towards the goal
 * -# Drives up to the goal
 * -# Shoots the preload into the goal
 * -# Drives backwards away from the goal
 * -# Turns right towards the goal on the other side of the field
 * -# Drives forward to the goal and poops any balls it encounters
 * -# Intakes the ball from the goal and poops it out
 * -# Backs up from the goal
 * -# Turns right towards the next edge goal
 * -# Drives forward to the goal and poops any balls it encounters
 * -# Intakes the ball from the goal and poops it out
 * -# Backs up from the goal
 * -# Turns right to the nearest corner goal
 * -# Drives forward to the goal
 * -# Intakes both balls from the goal and poops them out
 * -# Backs up from the goal
 */
void prog1();

/**
 * Runs the second programming routine
 *
 * Implementation to come
 */
void prog2();

#endif //PROS_OKAPI_AUTONOMOUS_HPP
