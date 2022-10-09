#include <fstream>
#include <iostream>
#include "Global_data.h"

int main(int argc, char *argv[])
{
	
	if (argc < 2)
	{
		std::cerr << "No input file\n";
		exit(-1);
	}

	std::ifstream in_file(argv[1]);

	Global_data_t global_data;
	Reference_t ref;
	int alg_num;

	if (in_file.is_open())
	{
		alg_num = parce_input(in_file, global_data);
	}
	else
	{
		std::cerr << "Could not open file\n";
		exit(-2);
	}

	in_file.close();


	std::vector<step_info_t> res = choose_metod_and_start(alg_num, global_data, ref);


	print_refernce(std::cout, ref);
	output_result(std::cout, res);

	return 0;
}