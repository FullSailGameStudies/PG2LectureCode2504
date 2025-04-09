#include "FullSailCourse.h"
#include <Console.h>

void FullSailCourse::GetGrades(std::vector<float>& grades) const
{
	//courseName = "PG1";
	//PrintGrades(grades);
	std::string someStr = "BatCave";
	for (int i = 0; i < 10; i++)
	{
		//% will divide by num and return the remainder
		grades.push_back(rand() % 101);// % num will result in 0-(num-1)
	}
}

// TODO: should this be a const method?
void FullSailCourse::PrintGrades(const std::vector<float>& grades) const
{
	Console::WriteLine("\n" + courseName + " 2504 Grades:");
	for (auto& grade : grades)
	{
		Console::WriteLine(grade);
	}
}
