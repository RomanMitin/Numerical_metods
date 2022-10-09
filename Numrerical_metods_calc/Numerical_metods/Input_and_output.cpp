#include <iostream>
#include <iomanip>
#include <functional>
#include <valarray>
#include "calc_result.h"
#include "input_and_output.h"
#include "Runge_Kutta_method_3_order.h"
#include "Runge_Kutta_system.h"

std::function<double(double, double)> func;

std::function<double(double, double, double)> func1_sys = system1;
std::function<double(double, double, double)> func2_sys = system2;

bool has_test_func;
size_t dim;

std::istream& operator>>(std::istream& in, std::valarray<double>& arr)
{
	arr.resize(dim);
	for (int i = 0; i < dim; i++)
	{
		in >> arr[i];
	}

	return in;
}

int parce_input(std::ifstream& in, Global_data_t& global_data)
{
	int alg_num;

	in >> alg_num;

	if (alg_num == 8)
		dim = 2;
	else
		dim = 1;

	in >> global_data.a >> global_data.b >> global_data.v0 >> global_data.start_step;

	in >> global_data.max_steps >> global_data.e_gr;

	if (global_data.start_step <= 0)
	{
		std::cerr << "Start step cant be less or equal zero\n";
		exit(9);
	}

	if (in.eof())
	{
		std::cerr << "Not enoght data in input file\n";
		exit(1);
	}

	int func_num;
	in >> func_num;

	switch (func_num)
	{
	case 1:
		has_test_func = true;
		func = func1;
		break;
	case 2:
		func = func2;
		break;
	case 3:
		func = func3;
		break;
	default:
		std::cerr << "Wrong func number\n";
		exit(8);
		break;
	}

	int control_option;

	in >> control_option;

	switch (control_option)
	{
	case 1:
		
		if (in.eof())
		{
			std::cerr << "Not enoght data in input file, no control_local_error_up\n";
			exit(3);
		}
		else
			in >> global_data.control_local_error_up;

		if (global_data.control_local_error_up <= 0.0)
		{
			std::cerr << "Control local error up cant be less or equal zero\n";
			exit(7);
		}

		if (in.eof())
		{
			global_data.control_local_error_down = global_data.control_local_error_up / (1ull << (metod_rangs[alg_num] + 1));
		}
		else
		{
			in >> global_data.control_local_error_down;
		}
		
		if (global_data.control_local_error_down <= 0.0)
		{
			std::cerr << "Control local error down cant be less or equal zero\n";
			exit(8);
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
	
	auto l = [](int n) { return 0; };

	return alg_num;
}

std::vector<step_info_t> choose_metod_and_start(int algorinthm_num, const Global_data_t& global_data, Reference_t& ref)
{
	std::vector<step_info_t> res;

	switch (algorinthm_num)
	{
	case 2:
		res = calc_result<euler_metod_2_order, metod_rangs[2]>(global_data, ref);
		break;
	case 3:
		res = calc_result<Runge_Kutta_methods_3_order_step, metod_rangs[3]>(global_data, ref);
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
		res = calc_result<Runge_Kutta_methods_4_order_step, metod_rangs[7]>(global_data, ref);
		break;
	case 8:
		res = calc_result_system<2, Runge_Kutta_system_2_order, metod_rangs[8]>(global_data, ref);
		break;
	default:
		std::cerr << "Invalid metod number\n";
		exit(3);
		break;
	}

	return res;
}

constexpr int precision = 5;
constexpr int space_num = precision + 8;

std::ostream& operator<<(std::ostream& out, const std::valarray<double>& arr)
{
	if (arr.size() == 0)
		out << 0.0 << std::setw(space_num);
	
	for (int i = 0; i < arr.size(); i++)
	{
		out << arr[i] << std::setw(space_num);
	}

	return out;
}


void print_refernce(std::ostream& out, Reference_t& ref)
{
	out << std::setprecision(precision);

	out << "------------ REFERNCE ---------------\n\n";

	out << ref.x0 << '\t' << ref.u0 << '\n';
	out << ref.b << '\t' << ref.e_gr << '\n';
	out << ref.h0 << '\t' << ref.max_step << '\n';

	out << ref.control_local_error_up << '\t' << ref.control_local_error_down << '\n';
	out << ref.num_step << '\n';
	out << ref.diff_b << '\n';

	out << ref.x_end << '\t' << ref.v_end << '\n';

	out << ref.E_max.first << '\t' << ref.E_max.second << '\n';
	out << ref.S_max.first << '\t' << ref.S_max.second << '\n';
	out << ref.S_min.first << '\t' << ref.S_min.second << '\n';

	out << ref.count_step_decrease << '\t' << ref.count_step_grow << '\n';


	out << ref.h_max.first << '\t' << ref.h_max.second << '\n';
	out << ref.h_min.first << '\t' << ref.h_min.second << '\n';

	out << '\n' << "------------ END_REFERNCE ---------------\n\n";
}

void output_result(std::ostream& out, std::vector<step_info_t> res)
{

	out << std::setprecision(precision);


	out << "n" << std::setw(space_num);
	out << "h" << std::setw(space_num);
	out << "x" << std::setw(space_num);
	out << "v" << std::setw(space_num);
	if (res[0].v.size() == 2)
		out << "y" << std::setw(space_num);
	out << "v^" << std::setw(space_num);
	if (res[0].v.size() == 2)
		out << "y^" << std::setw(space_num);
	out << "S*" << std::setw(space_num);
	if (res[0].v.size() != 2)
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
		out << abs(res[i].S_astr) << std::setw(space_num);
		if (res[0].v.size() != 2)
			out << res[i].v_final << std::setw(space_num);
		out << res[i].u << std::setw(space_num);
		out << res[i].abs_error << std::setw(space_num);
		out << res[i].count_step_grow << std::setw(space_num);
		out << res[i].count_step_decrease << '\n';
	}
}