#pragma once
#include <cstdint>
#include <limits>
#include <utility>

double test_func(double x, double C);
double func1(double x, double v);
double func2(double x, double v);
double func3(double x, double v);


struct Global_data_t
{
	double a, b, v0;

	double start_step;
	uint64_t max_steps;

	double e_gr; // for what?

	double control_local_error_up = std::numeric_limits<double>::infinity();
	double control_local_error_down = 0.0;
};

struct Reference_t
{
	double x0, u0;
	double b, e_gr;
	double h0, max_step;

	double control_local_error_up, control_local_error_down;

	uint64_t num_step;
	double diff_b;
	double x_end;
	double v_end;

	std::pair<double, double> E_max = { 0,0 };
	std::pair<double, double> S_max = { 0,0 };
	std::pair<double, double> S_min = { std::numeric_limits<double>::max(), 0 };

	uint32_t count_step_grow;
	uint32_t count_step_decrease;

	std::pair<double, double> h_max{ 0,0 }, h_min{ std::numeric_limits<double>::max(), 0 };
};

struct step_info_t
{
	double h = 0;
	double x, v;
	double v_check = 0;
	double S_astr = 0;
	double v_final = 0;

	double u = 0;
	double abs_error = 0;

	uint32_t count_step_grow = 0;
	uint32_t count_step_decrease = 0;
};