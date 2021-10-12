#include <algorithm>
/**
 * @brief Represents a tracking encoder
 * @details Represents either an ADI Optical Shaft encoder or a v5 rotation
 * sensor. This class is created so that all of the odometry code works with
 * either type of encoder.
 * @author Kevin Lou
 * @date 4/14/21
 */

#include "Encoder.hpp"
#include <cmath>

#define ADI true
#define v5 false

//defines v5 rotation sensor to a non-existent port
Encoder::Encoder(const ADIEncoder &opticalEncoder) :
        opticalEncoder(opticalEncoder), rotationSensor(22) {
    encoderType = ADI;
}

//defines the ADI optical encoder to non-existent ports
Encoder::Encoder(const Rotation &rotationSensor) :
        rotationSensor(rotationSensor), opticalEncoder(9,10) {
    encoderType = v5;
}

double Encoder::getPosition() {
    double returnVal = 0;
    if(encoderType == ADI){
        returnVal = opticalEncoder.get_value();
    }else if(encoderType == v5){
        // divide by 100 because rotationSensor returns in centi-degrees
        returnVal = rotationSensor.get_position()/((double) 100);
    }

    //convert returnVal to radians
    returnVal *= (180/M_PI);

    return returnVal;
}

void Encoder::resetPosition() {
    if(encoderType == ADI){
        opticalEncoder.reset();
    }else if(encoderType == v5){
        rotationSensor.reset_position();
    }
}

double Encoder::getDelta(bool savePos) {
    double currPos = getPosition();
    double delta = currPos - savedPos;

    if(savePos) savedPos = currPos;

    return delta;
}

void Encoder::savePosition() {
    savedPos = getPosition();
}

