#include "FlyingCar.h"

std::string FlyingCar::vehicleInformation()
{
    //DECISION: do I EXTEND the base or FULLY-OVERRIDE the base?
    //extend: means we CALL the base method
    //fully-override: means we do NOT call the base method
    std::string baseInfo = Car::vehicleInformation();
    std::string flyingInfo = "\n\tMax Altitude: " + std::to_string(maxAltitude_) + "\t Altitude: " + std::to_string(altitude_);
    return baseInfo + flyingInfo;;
}
