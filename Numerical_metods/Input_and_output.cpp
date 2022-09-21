#include <iostream>
#include <iomanip>
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
	int precision = 8;
	int space_num = precision + 8;
	out << std::setprecision(precision);


	//out << "n\t\th\t\tx\t\tv\t\tv^\t\tS*\t\tv_fin\t\tu\t\terr\t\tmul_s\t\tdiv_s\n";
	out << "n" << std::setw(space_num);
	out << "h" << std::setw(space_num);
	out << "x" << std::setw(space_num);
	out << "v" << std::setw(space_num);
	out << "v^" << std::setw(space_num);
	out << "S*" << std::setw(space_num);
	out << "v_fin" << std::setw(space_num);
	out << "u" << std::setw(space_num);
	out << "err" << std::setw(space_num);
	out << "mul_s" << std::setw(space_num);
	out << "div_s" << std::setw(space_num);
	out << '\n';


	for (int i = 0; i < res.size(); i++)
	{
		out << i << std::setw(space_num);
		out << res[i].h << std::setw(space_num);
		out << res[i].x << std::setw(space_num);
		out << res[i].v << std::setw(space_num);
		out << res[i].v_check << std::setw(space_num);
		out << res[i].S_astr << std::setw(space_num);
		out << res[i].v_final << std::setw(space_num);
		out << res[i].u << std::setw(space_num);
		out << res[i].abs_error << std::setw(space_num);
		out << res[i].count_step_decrease << std::setw(space_num);
		out << res[i].count_step_grow << '\n';

	}
}