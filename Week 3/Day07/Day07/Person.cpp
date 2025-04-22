#include "Person.h"
#include <iostream>

//Person::Person(const std::string& name, int age) : 
//	name_(name),
//	age_(age)
//{
//}

void Person::ItsMyBirthday()
{
	age_++;
	std::cout << "It's my birthday! I am " << age_ << " years old today!!";
	std::cout << " Let's have some cake/pie/ice-cream?\n";
}
