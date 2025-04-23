#pragma once
#include "Weapon.h"
class Pistol : public Weapon
{
public:

	Pistol(int range, int damage, int rounds, int magCapacity)
		: Weapon(range, damage), rounds_(0), magCapacity_(0)
	{
		Rounds(rounds);
		MagCapacity(magCapacity);
	}

	int Rounds() const { return rounds_; }
	void Rounds(int rounds)
	{
		if (rounds >= 0 && rounds <= magCapacity_)
			rounds_ = rounds;
	}
	int MagCapacity() const { return magCapacity_; }
	void MagCapacity(int newCapacity)
	{
		if (newCapacity > 0 && newCapacity < 50)
		{
			magCapacity_ = newCapacity;
			if (rounds_ > magCapacity_) rounds_ = magCapacity_;
		}
	}
private:
	int rounds_, magCapacity_;
};

