/**
 * @brief Represents a tracking encoder
 * @details Represents either an ADI Optical Shaft encoder or a V5 Rotation
 * Sensor. This class is created so that all of the odometry code works with
 * either type of encoder.
 * @author Kevin Lou
 * @date 4/14/21
 */

#ifndef ODOM_ENCODER_HPP
#define ODOM_ENCODER_HPP

#include "main.h"

class Encoder {
private:

    /**
     * ADI optical shaft encoder. Will be null if the encoder is initialized
     * with a v5 rotation sensor.
     */
    ADIEncoder opticalEncoder;

    /**
     * V5 rotation sensor. Will be null if the encoder is initialized with an
     * ADI optical shaft encoder.
     */
    Rotation rotationSensor;

    /**
     * Boolean representing the type of encoder. If true, the encoder is an
     * ADI sensor. If false, the encoder is a v5 rotation sensor.
     */
    bool encoderType;

    /**
     * The position of the encoder when it was last saved. Used to calculate
     * the change in encoder position
     */
    double savedPos;

public:
    /**
     * Creates a new instance of Encoder with an ADI encoder
     *
     * @param opticalEncoder
     *          The ADI encoder to be used
     */
    Encoder(const ADIEncoder &opticalEncoder);

    /**
     * Creates a new instance of Encoder with a v5 rotation sensor
     *
     * @param rotationSensor
     *          The v5 rotation sensor to be used
     */
    Encoder(const Rotation &rotationSensor);

    /**
     * Returns the position of whichever sensor the encoder is representing
     *
     * @return the sensor position in radians
     */
    double getPosition();

    /**
     * Resets the position of whichever sensor the encoder is representing to
     * zero.
     */
    void resetPosition();

    /**
     * Returns the difference in position from the last time the position was
     * saved of whichever sensor the encoder is representing
     *
     * @param savePos
     *          Whether or not to save the current position of the encoder.
     *          If true, the position will be saved. If false, the position
     *          won't be saved. Default is true.
     *
     * @return the change is sensor position in radians
     */
    double getDelta(bool savePos = true);

    /**
     * Saves the current position of whichever sensor the encoder is
     * representing
     */
    void savePosition();
};


#endif //ODOM_ENCODER_HPP
