#pragma once
#include <vector>
#include <string>
class FullSailCourse
{
public:
	void GetGrades(std::vector<float>& grades) const;//declaration
	void PrintGrades(const std::vector<float>& grades) const;

private:
	std::string courseName = "pg2";//field of the class
};

