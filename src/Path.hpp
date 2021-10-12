/**
 * @brief Represents a path for pure pursuit
 * @details Contains a deque of path states that are used to construct a pure
 * pursuit path. Also contains methods for finding where a robot should drive
 * to on the path.
 * @author Kevin Lou
 * @date 4/18/21
 */

#ifndef ODOM_PATH_HPP
#define ODOM_PATH_HPP

#include "main.h"
#include "PathState.hpp"

class Path {
private:
    deque<PathState> wayPoints;

    /**
      * Finds the intersection between a circle and a line segment
      *
      * @param x1
      *             X-coordinate of first line segment endpoint
      * @param y1
      *             Y-coordinate of first line segment endpoint
      * @param x2
      *             X-coordinate of seconds line segment endpoint
      * @param y2
      *             Y-coordinate of second line segment endpoint
      * @param h
      *             X-coordinate of center of circle
      * @param k
      *             Y-coordinate of center of circle
      * @param r
      *             Radius of circle
      * @return a list with all of the intersections
      */
    deque<PathState> intersection(double x1, double y1, double x2, double y2,
                                 double h, double k, double r);

public:
    /**
     * Creates a new instance of Path
     *
     * @param start
     *          The first state of the path
     */
    Path(PathState start);

    /**
     * Adds a waypoint to the path
     *
     * @param state
     *          The PathState to add to the path list
     */
    void addWaypoint(PathState state);

    /**
     * Adds a waypoint without heading to the path
     *
     * @param x
     *          X-coordinate of the waypoint
     * @param y
     *          Y-coordinate of the waypoint
     */
    void addWaypoint(double x, double y);

    /**
     * Adds a waypoint with heading to the path
     *
     * @param x
     *          X-coordinate of the waypoint
     * @param y
     *          Y-coordinate of the waypoint
     * @param theta
     *          Heading of the waypoint
     */
    void addWaypoint(double x, double y, double theta);

    /**
     * Gets the target for the drive to go to
     *
     * @warning Will result in undefined behavior if the path does get within
     * the lookahead distance of the robot
     *
     * @param x
     *          X-coordinate of the robot
     * @param y
     *          Y-coordinate of the robot
     * @param theta
     *          Heading of the robot
     * @param lookAheadDist
     *          Look-ahead distance of the robot
     * @param deletePrev
     *          Whether or not to delete the previous waypoint that have
     *          already been passed. Default is true
     * @return A PathState representing the new target for the robot
     */
    PathState getTarget(double x, double y, double theta,
                        double lookAheadDist, bool deletePrev = true);

    /**
     * Finds if the robot is done with this path
     *
     * @param x
     *          X-coordinate of the robot
     * @param y
     *          Y-coordinate of the robot
     * @param theta
     *          Heading of the robot
     * @return True if the robot is done with this path, false otherwise
     */
    bool done(double x, double y, double theta);
};


#endif //ODOM_PATH_HPP
