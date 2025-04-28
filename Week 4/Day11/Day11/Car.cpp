#include "Car.h"

std::string Car::vehicleInformation()
{
	return std::to_string(mModelYear) + " " + mMake + " " + mModel;
}

Car::Car(const std::string& carData, char delim)
{
	Deserialize(carData, delim);
}

void Car::Serialize(std::ostream& outStream, char delim) const
{
	outStream << mModelYear << delim << mMake << delim << mModel;
}

void Car::Deserialize(const std::string& carData, char delim)
{
	//getline
	std::stringstream carStream(carData);
	std::string data;
	std::getline(carStream, data, delim);
	mModelYear = std::stoi(data);

	std::getline(carStream, mMake, delim);
	std::getline(carStream, mModel, delim);
}
