#pragma once
#include <cstdint>
#include <algorithm>
#include <vector>

#include "Global_data.h"

double get_final_v(double v, double v_check, double S_astr)
{
	return v;
	//return v + S_astr;
}

template<double (*metod_step)(double, double, double, uint64_t), uint32_t metod_rate>
std::vector<step_info_t> calc_result(const Global_data_t& global_data)
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

	double v_check;

	double h = global_data.start_step;

	double b = global_data.b;

	std::vector<step_info_t> step_info_vec;
	step_info_vec.reserve(static_cast<size_t>((b - x) / (h + 0.003)));


	while (step_count <= max_step && x < b)
	{
		step_info_t step_info;


		count_grow_by_step = 0;
		count_decrease_by_step = 0;

		step_count++;
		x = std::min(x + h, b);

		v = metod_step(x, v, h, 1);
		v_check = metod_step(x, v, h / 2, 2);

		S = (v_check - v) / ((1ull << metod_rate) - 1);

		while ((abs(S) > control_local_error_up))
		{
			h /= 2.0;
			count_grow_by_step++;


			v = metod_step(x, v, h, 1);
			v_check = metod_step(x, v, h / 2, 2);

			S = (v_check - v) / ((1ull << metod_rate) - 1);
		}
		double S_atr = S * (1ull << metod_rate);

		step_info.h = h;
		step_info.x = x;
		step_info.v = v;
		step_info.v_check = v_check;
		step_info.S_astr = S_atr;

		v = get_final_v(v, v_check, S_atr);

		step_info.v_final = v;

		if (abs(S) < control_local_error_down)
		{
			h *= 2;
			count_decrease_by_step++;
		}

		count_step_grow += count_grow_by_step;
		count_step_decrease += count_decrease_by_step;

		step_info.count_step_grow = count_grow_by_step;
		step_info.count_step_decrease = count_decrease_by_step;

		step_info_vec.emplace_back(step_info);
	}

	return step_info_vec;
}


