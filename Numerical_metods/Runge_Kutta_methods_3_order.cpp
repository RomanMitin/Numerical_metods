#include "Runge_Kutta_method_3_order.h"

double Runge_Kutta_methods_3_order_step(double x0, double v0, double h, uint64_t num_step)
{
	double x = x0;
	double v = v0;

	double k1, k2;

	for (uint64_t i = 0; i < num_step; i++)
	{
		x += h;

		k1 = func(x, v);
		k2 = func(x + h, v + h * k1);
		
		v = v + h / 2 * (k1 + k2);
	}

	return v;
}