#pragma once
#include <string>
class Person
{
public:
	//Person() : name_(""), age_(0) {}
	Person(const std::string& name, int age) :
		name_(""),
		age_(0)
	{
		Name(name);
		Age(age);
	}
	void ItsMyBirthday();//declaration

	std::string Name() const { return name_; }
	void Name(std::string newName)
	{
		if (!newName.empty() && newName.size() < 32)
		{
			name_ = newName;
		}
	}
	int Age() const { return age_; }
	void Age(int newAge)
	{
		if (newAge >= 0 && newAge <= 120)
		{
			age_ = newAge;
		}
	}
private:
	int age_;
	std::string name_;
};

