#pragma once
#include <vector>
#include <fstream>

#include "Global_data.h"


// 
// algorithm_number a b v0 start_step max_step e_gr func_number control_option (control_local_error_up) (control_local_error_down)
//
// swith(argv[8])
// case 1: up and down control
// case 2: only up control
// case 3: without any control



// from metodichka( page 48 )
constexpr uint32_t metod_rangs[] = { 0, 1, 1, 2, 2 ,3, 3, 4 ,4 };

int parce_input(std::ifstream& in, Global_data_t& global_data);

std::vector<step_info_t> choose_metod_and_start(int algorinthm_num, const Global_data_t& global_data, Reference_t&);

void print_refernce(std::ostream&,Reference_t& ref);

void output_result(std::ostream&, std::vector<step_info_t>);