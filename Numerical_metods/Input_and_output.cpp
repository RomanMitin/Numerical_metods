#include <iostream>
#include "calc_result.h"
#include "input_and_output.h"
#include "Runge_Kutta_method_3_order.h"

int parce_input(std::ifstream& in, Global_data_t& global_data)
{
	int alg_num;

	in >> alg_num;

	in >> global_data.a >> global_data.b >> global_data.v0 >> global_data.start_step;

	in >> global_data.max_steps >> global_data.e_gr;

	if (in.eof())
	{
		std::cerr << "Not enoght data in input file\n";
		exit(1);
	}

	int control_option;

	in >> control_option;

	switch (control_option)
	{
	case 1:
		
		if ((in >> global_data.control_local_error_up).eof())
		{
			std::cerr << "Not enoght data in input file, no control_local_error_up\n";
			exit(3);
		}

		if ((in >> global_data.control_local_error_down).eof())
		{
			global_data.control_local_error_down = global_data.control_local_error_up / (1ull << (metod_rangs[alg_num] + 1));
		}
		

		break;
	case 2:
		if ((in >> global_data.control_local_error_up).eof())
		{
			std::cerr << "Not enoght data in input file, no control_local_error_up\n";
			exit(4);
		}
		break;
	case 3:
		break;
	default:
		std::cerr << "Invalid control option";
		exit(5);
		break;
	}

	return alg_num;
}

std::vector<step_info_t> choose_metod_and_start(int algorinthm_num, const Global_data_t& global_data)
{
	std::vector<step_info_t> res;

	switch (algorinthm_num)
	{
	case 2:
		std::cerr << "This metod does not supported now\n";
		exit(2);
		break;
	case 3:
		res = calc_result<Runge_Kutta_methods_3_order_step, metod_rangs[3]>(global_data);
		break;
	case 4:
		std::cerr << "This metod does not supported now\n";
		exit(2);
		break;
	case 5:
		std::cerr << "This metod does not supported now\n";
		exit(2);
		break;
	case 6:
		std::cerr << "This metod does not supported now\n";
		exit(2);
		break;
	case 7:
		std::cerr << "This metod does not supported now\n";
		exit(2);
		break;
	case 8:
		std::cerr << "This metod does not supported now\n";
		exit(2);
		break;
	default:
		std::cerr << "Invalid metod number\n";
		exit(3);
		break;
	}

	return res;
}


void output_result(std::ostream& out, std::vector<step_info_t> res)
{
	out << "n\th\tx\tv\tv_check\tS_astr\tv_final\tu\tabs_error\tcount_step_decrease\tcount_step_grow\n";

	for (int i = 0; i < res.size(); i++)
	{
		out << i << '\t';
		out << res[i].h << '\t';
		out << res[i].x << '\t';
		out << res[i].v << '\t';
		out << res[i].v_check << '\t';
		out << res[i].S_astr << '\t';
		out << res[i].v_final << '\t';
		out << res[i].u << '\t';
		out << res[i].abs_error << '\t';
		out << res[i].count_step_decrease << '\t';
		out << res[i].count_step_grow << '\t';

		out << '\n';
	}
}