#pragma once
#include "Car.h"
class FlyingCar : public Car
{
public:
	//the derived CTOR MUST CALL a base CTOR
	FlyingCar(int year, std::string make, std::string model, 
		      int maxAltitude, int altitude)
		: 
		//call the base CTOR here
		Car(year, make, model),
		maxAltitude_(maxAltitude), 
		altitude_(altitude)
	{
	}
	//override the virtual method
	std::string vehicleInformation() override;

private:
	//data
	int maxAltitude_, altitude_;

};

