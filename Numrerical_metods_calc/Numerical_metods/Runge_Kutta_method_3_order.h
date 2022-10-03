#pragma once
#include <cstdint>
#include "Global_data.h"

double euler_metod_2_order(double x0, double v0, double h, uint64_t num_step);

double Runge_Kutta_methods_3_order_step(double x0, double v0, double h, uint64_t num_step);

double Runge_Kutta_methods_4_order_step(double x0, double v0, double h, uint64_t num_step);
