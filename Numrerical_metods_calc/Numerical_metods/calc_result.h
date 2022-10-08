#pragma once
#include <cstdint>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>

#include "Global_data.h"

extern bool has_test_func;

double get_final_v(double v, double v_check, double S_astr);

void update_ref(Reference_t& ref, double E, double S, double h, double x);

template<double (*metod_step)(double, double, double, uint64_t), uint32_t metod_rate>
std::vector<step_info_t> calc_result(const Global_data_t& global_data, Reference_t& ref)
{
	uint64_t step_count = 0;
	uint32_t count_step_grow = 0;
	uint32_t count_step_decrease = 0;
	uint32_t count_grow_by_step = 0;
	uint32_t count_decrease_by_step = 0;

	double S;

	double control_local_error_up = global_data.control_local_error_up;
	double control_local_error_down = global_data.control_local_error_down;

	const uint64_t max_step = global_data.max_steps;

	double x = global_data.a;
	double v = global_data.v0;
	double u = 0;
	double C = v / test_func(x, 1);
	double v_tmp;


	double v_check;

	double h = global_data.start_step;

	double b = global_data.b;

	ref.x0 = x;
	ref.u0 = v;
	ref.b = b;

	ref.h0 = h;
	ref.b = b;
	ref.max_step = max_step;
	ref.e_gr = global_data.e_gr;
	ref.control_local_error_up = control_local_error_up;
	ref.control_local_error_down = control_local_error_down;


	std::vector<step_info_t> step_info_vec;
	step_info_vec.reserve(static_cast<size_t>((b - x) / (h + 0.003)));

	step_info_t tmp_first_step;

	tmp_first_step.x = x;
	tmp_first_step.v = v;

	if(has_test_func)
		tmp_first_step.u = test_func(x, C);

	step_info_vec.emplace_back(tmp_first_step);

	while (step_count <= max_step && x < b)
	{
		step_info_t step_info;

		if (x + h > b)
			h = b - x;

		count_grow_by_step = 0;
		count_decrease_by_step = 0;

		step_count++;

		v_tmp = metod_step(x, v, h, 1);
		v_check = metod_step(x, v, h / 2, 2);
		v = v_tmp;

		S = (v_check - v) / ((1ull << metod_rate) - 1);

		while ((abs(S) > control_local_error_up))
		{
			h /= 2.0;
			count_decrease_by_step++;
			

			v_tmp = metod_step(x, v, h, 1);
			v_check = metod_step(x, v, h / 2, 2);
			v = v_tmp;

			S = (v_check - v) / ((1ull << metod_rate) - 1);

		}
		double S_atr = S * (1ull << metod_rate);

		step_info.h = h;
		step_info.v = v;
		step_info.v_check = v_check;
		step_info.S_astr = S_atr;


		if (abs(S) < control_local_error_down)
		{
			count_grow_by_step++;
			h *= 2;
		}

		step_info.x = x;
		x += h;

		if (has_test_func)
		{
			u = test_func(x, C);
			step_info.u = u;
		}

		if (abs(v) > 1e+30)
		{
			std::cerr << "v is more that 1e+30\n\n";
			break;
		}

		update_ref(ref, v - u, S, h, x);

		v = get_final_v(v, v_check, S_atr);

		if (has_test_func)
			step_info.abs_error = v - u;
		step_info.v_final = v;

		count_step_grow += count_grow_by_step;
		count_step_decrease += count_decrease_by_step;

		step_info.count_step_grow = count_grow_by_step;
		step_info.count_step_decrease = count_decrease_by_step;

		step_info_vec.emplace_back(step_info);
	}


	ref.num_step = step_count;
	ref.diff_b = b - x;
	ref.x_end = x;
	ref.v_end = v;

	ref.count_step_grow = count_step_grow;
	ref.count_step_decrease = count_step_decrease;


	return step_info_vec;
}


