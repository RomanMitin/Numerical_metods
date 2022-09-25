#include "Runge_Kutta_method_3_order.h"
#include <functional>


// define it in input
extern std::function<double(double, double)> func;

double Runge_Kutta_methods_3_order_step(double x0, double v0, double h, uint64_t num_step)
{
	double x = x0;
	double v = v0;

	double k1, k2;

	for (uint64_t i = 0; i < num_step; i++)
	{
		k1 = func(x, v);
		k2 = func(x + h, v + h * k1);
		
		v = v + h / 2 * (k1 + k2);

		x += h;
	}

	return v;
}

double Runge_Kutta_methods_4_order_step(double x0, double v0, double h, uint64_t num_step)
{
	double x = x0;
	double v = v0;

	double k1, k2, k3, k4;

	for (uint64_t i = 0; i < num_step; i++)
	{
		k1 = func(x, v);
		k2 = func(x + h / 2, v + h / 2 * k1);
		k3 = func(x + h / 2, v + h / 2 * k2);
		k4 = func(x + h, v + h * k3);

		v = v + h / 6 * (k1 + 2 * k2 + 2 * k3 + k4);

		x += h;
	}

	return v;
}