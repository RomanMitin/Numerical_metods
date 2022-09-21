#include <iostream>
#include <fstream>

#include "Global_data.h"
#include "input_and_output.h"


int main(int argc, char* argv[])
{
	std::cout << argc << '\n';

	Global_data_t global_data;

	parce_input(argc, argv, global_data);

	std::vector<step_info_t> res = choose_metod_and_start(argv, global_data);

	output_result(std::cout, res);

	return 0;
}