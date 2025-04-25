// Day09.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "Pistol.h"
#include "Knife.h"


class base
{
private:
	int mNum;
public:
	base(int num) : mNum(num)
	{

	}
	void print()
	{
		std::cout << "Hello base " << mNum << "\n";
	}
};

class derived : public base
{
private:
	std::string mStr;
public:
	derived(std::string str, int num) : base(num), mStr(str)
	{ }
};


class Car
{
public:
	Car(int year)
	{
		mModelYear = year;
		mNumberOfCarsMade++;
	}

	int mModelYear; //each car has its own model year variable
	static int mNumberOfCarsMade; //shared by ALL cars

	//static methods
	//do NOT have a 'this' parameter
	//therefore, static methods can ONLY access other static members
	//cannot access non-static members
	static void reporting()
	{
		//vehicleInfo();
		//std::cout << "Model year: " << mModelYear << "\n"; //ERROR! cannot access non-static members
		std::cout << "Number of cars made: " << mNumberOfCarsMade << "\n";
	}
	
	//non-static methods:
	//there's a hidden parameter called 'this'
	//can access both non-static AND static members
	void vehicleInfo()//Car* this) 
	{
		int n = 5;
		reporting();
		std::cout << "Model Year: " << mModelYear << "\n";
	}
};
//initialize explicitly using the class name scoping
int Car::mNumberOfCarsMade = 0;



int main()
{
	Pistol gun(50, 100, 10, 4);
	Knife stabby(3, 10, 36);
	std::vector<std::unique_ptr<Weapon>> backpack;
	Weapon wpn1 = gun;//copies ONLY the weapon parts
	//upcasting is ALWAYS safe
	//downcasting is NOT SAFE!
	backpack.push_back(std::make_unique<Weapon>(50, 100, 10, 4));//UPCASTING the pointer to a base pointer
	backpack.push_back(std::make_unique<Weapon>(3, 10, 36));
	for (auto& wpn : backpack)
	{
		wpn->showMe();
	}
	Car aCar(2018);
	Car gCar(2010);
	aCar.vehicleInfo();// &aCar);
	gCar.vehicleInfo();// &gCar);
	Car::reporting();

	Car* todaysRide = &aCar;
	std::cout << todaysRide->mModelYear << "\n";
	todaysRide->mModelYear++;
	std::cout << aCar.mModelYear << "\n";
	todaysRide = &gCar;
	std::cout << todaysRide->mModelYear << "\n";

	std::unique_ptr<Car> uptrCarMain;
	{
		std::unique_ptr<Car> uptrCar = std::make_unique<Car>(2025);
		uptrCarMain = std::move(uptrCar);//transfer ownership of the ptr
	}//unique_ptr auto-deletes when it goes out of scope

	int* hNum = nullptr;
	{
		//stack variables. deleted when the scope ends
		int num = 5;//non-pointer
		int* pNum = &num;
		int& num2 = num;
		std::cout << num << "\n" << num2 << "\n" << pNum << "\n";
		int num4 = 10;
		int* numPtr = pNum;
		numPtr = &num4;

		//*ptr to dereference it
		std::cout << *numPtr << "\n";

		//heap variables
		int* heapNum = new int(15);
		//for EVERY 'new' you need a corresponding 'delete'
		hNum = heapNum;
		delete heapNum;
	}//
	if (hNum != nullptr)
	{
		delete hNum;
	}

	/*
		╔════════════╗
		║ Unique_ptr ║
		╚════════════╝

		Using unique pointers w/ overridden methods


		╔═══════════╗
		║ UPCASTING ║ - casting a derived type variable to a base type variable
		╚═══════════╝

		This is ALWAYS safe.


		To maintain the original object, we need a pointer though. If not, then we're just calling the copy constructor of the base class and lose all the info of the derived.

		Unique pointers owns and manages an object through a pointer.
		std::unique_ptr<derived> pDerived = std::make_unique<derived>("Gotham", 5);


		You can upcast by using the base type in the unique_ptr.
		std::unique_ptr<base> pBase = std::make_unique<derived>("Gotham", 5);
		  OR
		std::unique_ptr<base> pBase = std::move(pDerived); https://learn.microsoft.com/en-us/cpp/standard-library/utility-functions?view=msvc-170&redirectedfrom=MSDN&f1url=%3FappId%3DDev16IDEF1%26l%3DEN-US%26k%3Dk(std%253A%253Amove)%3Bk(move)%3Bk(DevLang-C%252B%252B)%3Bk(TargetOS-Windows)%26rd%3Dtrue#move



		Lecture Code:
			use make_unique and unique_ptr to create a derived instance
			use std::move to upcast it to a base
	*/
	derived der1("Gotham", 1);
	base base1 = der1; //calls the assignment operator of base therefore you lose all the derived parts. base1 is JUST a base object.
	der1.print();
	std::cout << "\n";
	base1.print();



	/*
		╔*************╗
		║  CHALLENGE  ║
		╚*************╝

		Create a vector that holds unique pointers of Weapon.
		Create instances of Weapon and Pistol using make_unique.
		Add them to the vector.

		Loop over the vector and call showMe on each weapon.

	*/




	/*
		╔══════════════════╗
		║  Static Members  ║
		╚══════════════════╝

		When calling a non-static method on a class, you must use a variable of that class.
		That's because the variable is passed in as the 'this' parameter.

		Static methods do not have a 'this' parameter therefore you call them on the
		class name itself.

		That's also why static methods cannot access non-static members.

	*/
	Car myRide(1988);
	Car::reporting();
	myRide.vehicleInfo();//calling non-static methods. myRide is passed in for 'this'

	/*

		CHALLENGE:
		Add a static method to the Car class that returns an instance of the Car class.

	*/
}