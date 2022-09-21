#pragma once
#include <cstdint>
#include <limits>

double func(double x, double v);


struct Global_data_t
{
	double a, b, v0;

	double start_step;
	uint64_t max_steps;

	double e_gr; // for what?

	double control_local_error_up = std::numeric_limits<double>::infinity();
	double control_local_error_down = 0.0;
};

struct step_info_t
{
	double h;
	double x, v;
	double v_check;
	double S_astr;
	double v_final;

	double u;
	double abs_error;

	uint32_t count_step_grow;
	uint32_t count_step_decrease;
};