#pragma once
#include <vector>
#include <fstream>

#include "Global_data.h"

// argv[1] == a
// argv[2] == b
// argv[3] == v0
// argv[4] == start_step
// argv[5] == max_step
// argv[6] == e_gr
// 
// argv[7] == metod_to_call
//  
// swith(argv[8])
// case 1: up and down control
// case 2: only up control
// case 3: without any control
// 
// if need
// argv[9] == control_local_error_up 
// argv[10] == control_local_error_down


// from metodichka( page 48 )
constexpr uint32_t metod_rangs[] = { 0, 1, 1, 2, 2 ,3, 3, 4 ,4 };

void parce_input(int argc, char* argv[], Global_data_t& global_data);

std::vector<step_info_t> choose_metod_and_start(char* argv[], const Global_data_t& global_data);

void output_result(std::ostream&, std::vector<step_info_t>);