#include "Global_data.h"
#include <cmath>

double f(double x)
{
	return (pow(x, 3) + 1) / (pow(x, 5) + 1);
}

double test_func(double x, double C)
{
	return C * exp(2 * x);
}

double func1(double x, double u)
{
	return 2 * u;
}

double func2(double x, double u)
{
	return f(x) * pow(u, 2) + u - pow(u, 3) * sin(10 * x);
}

double func3(double x, double u)
{
	return u * u - 2 * x * x;
}