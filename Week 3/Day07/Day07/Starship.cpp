#include "Starship.h"

//Starship::Starship() : name_(""), rotation_(0)
//{
//}

Starship::Starship(const std::string& name, int rotation)
{
	SetName(name);
	Rotation(rotation);
}

void Starship::Shoot()
{
	//can we shoot? 
	// if so 
	//	take the current aiming vector
	//  create a new bullet object 
	//		with the aiming vector + speed as its direction
}
