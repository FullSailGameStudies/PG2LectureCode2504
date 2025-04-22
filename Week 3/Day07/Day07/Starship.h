#pragma once
#include <string>
class Starship
{
	//shoot, thrust, rotate, hyperjump


	//access modifiers inside the class:
	//public: 
	//   all code can see it
	//protected: 
	//   my class (Starship) and all descendent class can see it
	//private:
	//	 ONLY my class (Starship) can see it
public:
	//
	//constructors (ctors)
	//	Purpose: to initialize the object (give values to the fields)
	//		IF you do not write one, the compiler will give you a default ctor
	//		default ctor means no parameters
	//		IF you write ANY ctor, the compiler's version is no longer available
	Starship() : //a default ctor (no params)
		//member initialization list 
		//happens before the { code }
		name_(""),
		rotation_(0)
	{
		//name_ = "";
		//rotation_ = 0;
	}
	Starship(const std::string& name, int rotation);



	void Shoot();//declaration

	//getters/setters (gatekeepers of the fields)
	//getters (accessors). return the fields
	//	usually public
	//	const methods
	const std::string& GetName() const
	{
		return name_;
	}
	float Rotation() const
	{
		return rotation_;
	}
	//setters (mutators)
	//	usually public
	//	usually void return type
	//	at least 1 parameter to change the field with
	//	CANNOT be const
	void SetName(const std::string& newName)
	{
		if (not newName.empty() && newName.size() < 32)
		{
			name_ = newName;
		}
	}
	void Rotation(float newRotation)
	{
		if (newRotation > 360)
			newRotation -= 360;
		else if (newRotation < -360)
			newRotation += 360;
		rotation_ = newRotation;
	}

protected:

private: //private is the default!

	std::string name_;

	//Fields: data (data members) of your class
	//generally, keep them PRIVATE!
	float rotation_; //_stricmp??  push_back 
	//m_fRotation m_rotation mRotation _rotation rotation_

	//mX  y_
	//type variable_name;

};

