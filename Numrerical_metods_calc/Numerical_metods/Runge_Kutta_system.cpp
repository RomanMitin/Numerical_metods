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

std::valarray<double> Runge_Kutta_system_4_order(double x, std::valarray<double> v, double h, uint64_t step_num)
{
	double u = v[0];
	double y = v[1];

	double k11, k12, k13, k14, k21, k22, k23, k24;
	for (uint64_t i = 0; i < step_num; i++)
	{
		k11 = func1_sys(x, u, y);
		k21 = func2_sys(x, u, y);

		k12 = func1_sys(x + h / 2, u + h / 2 * k11, y + h / 2 * k21);
		k22 = func2_sys(x + h / 2, u + h / 2 * k11, y + h / 2 * k21);

		k13 = func1_sys(x + h / 2, u + h / 2 * k12, y + h / 2 * k22);
		k23 = func2_sys(x + h / 2, u + h / 2 * k12, y + h / 2 * k22);

		k14 = func1_sys(x + h, u + h * k13, y + h * k23);
		k24 = func2_sys(x + h, u + h * k13, y + h * k23);

		u += (k11 + 2 * k12 + 2 * k13 + k14) * h / 6;
		y += (k21 + 2 * k22 + 2 * k23 + k24) * h / 6;

		x += h;
	}

	return std::valarray<double>{ u, y };
}