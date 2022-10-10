#pragma once
#include <cinttypes>
#include <valarray>

std::valarray<double> Runge_Kutta_system_2_order(double x, std::valarray<double> v, double h, uint64_t step_num);

std::valarray<double> Runge_Kutta_system_4_order(double x, std::valarray<double> v, double h, uint64_t step_num);