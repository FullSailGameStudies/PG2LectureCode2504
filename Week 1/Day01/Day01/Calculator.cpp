#include "Calculator.h"

//a DEFINITION of the method
int Calculator::minus(int number1, int number2)
{
	return number1 - number2;
}

bool Calculator::isEven(int numberToCheck)
{//the method block
	return numberToCheck % 2 == 0;
}

double Calculator::mult(double num, double factor)
{
	return num * factor;
}
