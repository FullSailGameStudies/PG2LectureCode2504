#include "Knife.h"
#include <iostream>

void Knife::showMe()
{
	Weapon::showMe();
	std::cout << "length: " << length_ << "\n";
}
