#include "Car.h"

std::string Car::vehicleInformation()
{
	return std::to_string(mModelYear) + " " + mMake + " " + mModel;
}

void Car::Serialize(std::ostream& outStream, char delim) const
{
	outStream << mModelYear << delim << mMake << delim << mModel;
}
