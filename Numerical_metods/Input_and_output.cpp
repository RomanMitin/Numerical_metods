#include <iostream>
#include "calc_result.h"
#include "input_and_output.h"
#include "Runge_Kutta_method_3_order.h"

void parce_input(int argc, char* argv[], Global_data_t& global_data)
{
	if (argc < 9)
	{
		std::cerr << "Not enoght arguments, argc must be greater that 8\n";
		exit(1);
	}


	global_data.a = atof(argv[1]);
	global_data.b = atof(argv[2]);
	global_data.v0 = atof(argv[3]);
	global_data.start_step = atof(argv[4]);
	global_data.max_steps = atoll(argv[5]);
	global_data.e_gr = atof(argv[6]);

	switch (atoi(argv[8]))
	{
	case 1:
		if (argc >= 9)
		{
			global_data.control_local_error_up = atof(argv[9]);
			if (argc >= 10)
				global_data.control_local_error_down = atof(argv[10]);
			else
				global_data.control_local_error_down = global_data.control_local_error_up / (1ull << (metod_rangs[atoi(argv[7])] + 1));
		}
		else
		{
			std::cerr << "Not enoght arguments, their is no argv[9]\n";
			exit(4);
		}

		break;
	case 2:
		if (argc >= 9)
		{
			global_data.control_local_error_up = atof(argv[9]);
		}
		else
		{
			std::cerr << "Not enoght arguments, their is no argv[9]\n";
			exit(4);
		}
		break;
	case 3:
		break;
	default:
		std::cerr << "Invalid control option in argv[8]";
		exit(5);
		break;
	}


}

std::vector<step_info_t> choose_metod_and_start(char* argv[], const Global_data_t& global_data)
{
	std::vector<step_info_t> res;

	switch (atoi(argv[7]))
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
	out << "n\tx\tv\tv_check\tS_astr\tv_final\tu\tabs_error\tcount_step_decrease\tcount_step_grow\n";

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