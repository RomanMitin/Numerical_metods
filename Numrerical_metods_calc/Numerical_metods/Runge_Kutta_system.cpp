#include "Runge_Kutta_system.h"
#include <functional>

// define it in input
extern std::function<double(double, double, double)> func1_sys;
extern std::function<double(double, double, double)> func2_sys;


std::valarray<double> Runge_Kutta_system_2_order(double x, std::valarray<double> v, double h, uint64_t step_num)
{
	double u = v[0];
	double y = v[1];

	double k11, k12, k21, k22;
	for (uint64_t i = 0; i < step_num; i++)
	{
		k11 = func1_sys(x, u, y);
		k21 = func2_sys(x, u, y);

		k12 = func1_sys(x + h, u + h * k11, y + h * k21);
		k22 = func2_sys(x + h, u + h * k11, y + h * k21);

		u += (k11 + k12) * h / 2;
		y += (k21 + k22) * h / 2;

		x += h;
	}

	return std::valarray<double>{ u,y };
}