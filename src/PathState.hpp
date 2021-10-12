/**
 * @brief Holds a state for the robot's drive.
 * @details Stores the drive state with three values: x, y, theta. Theta is
 * an optional value. This class can also be used as a point class.
 * @author Kevin Lou
 * @date 4/17/21
 */

#ifndef ODOM_PATHSTATE_HPP
#define ODOM_PATHSTATE_HPP


class PathState {

private:
    double x;
    double y;
    double theta;

    bool turn;

public:
    /**
     * Creates a new instance of PathState without turning
     *
     * @param x
     *          X-coordinate of state
     * @param y
     *          Y-coordinate of state
     */
    PathState(double x, double y);

    /**
     * Creates a new instance of PathState with turning
     *
     * @param x
     *          X-coordinate of state
     * @param y
     *          Y-coordinate of state
     * @param theta
     *          Heading of state
     */
    PathState(double x, double y, double theta);

    /**
     * Gets the x-coordinate of the state
     *
     * @return the x-coordinate
     */
    double getX() const;

    /**
     * Gets the y-coordinate of the state
     *
     * @return the y-coordinate
     */
    double getY() const;

    /**
     * Gets the heading of the state
     *
     * @return the heading of the state. If the state has no heading, returns 0
     */
    double getTheta() const;

    /**
     * Gets whether or not the state has a heading
     *
     * @return true if the state has a heading, false otherwise
     */
    bool isTurn() const;

};


#endif //ODOM_PATHSTATE_HPP
