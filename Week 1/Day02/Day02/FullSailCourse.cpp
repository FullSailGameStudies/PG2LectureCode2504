#include "FullSailCourse.h"
#include <Console.h>

void FullSailCourse::GetGrades(std::vector<float>& grades)
{
	for (int i = 0; i < 10; i++)
	{
		//% will divide by num and return the remainder
		grades.push_back(rand() % 101);// % num will result in 0-(num-1)
	}
}

void FullSailCourse::PrintGrades(std::vector<float>& grades)
{
	Console::WriteLine("\nPG2 2504 Grades:");
	for (float& grade : grades)
	{
		Console::WriteLine(grade);
	}
}
