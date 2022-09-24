#pragma once
#include <cstdint>
#include "Global_data.h"


double Runge_Kutta_methods_3_order_step(double x0, double v0, double h, uint64_t num_step);
