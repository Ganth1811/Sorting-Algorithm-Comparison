#pragma once

#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>
#include <chrono>
#include "sorting_algorithm.h"
#include "DataGenerator.h"

using namespace std;

#define DEFAULT 0

#define ALGORITHM_MODE 101
#define COMPARISON_MODE 102

#define INP_FILE 103
#define INP_GENERATED 104

#define ORDER_RANDOM 1 << 1
#define ORDER_NSORTED 1 << 2
#define ORDER_SORTED 1 << 3
#define ORDER_REVERSE 1 << 4
#define ORDER_ALL 	ORDER_RANDOM | ORDER_NSORTED | ORDER_SORTED | ORDER_REVERSE

#define OUT_TIME 1 << 5
#define OUT_COMPARISON 1 << 6
#define OUT_BOTH 	OUT_TIME | OUT_COMPARISON

typedef void (*p_func_comp)(vector<type>&, ull&);
typedef void (*p_func_time)(vector<type>&);
typedef int ArgValue;

struct ProgramArguments{
	ArgValue mode = DEFAULT;

	ArgValue input_mode = DEFAULT;
	int input_size = 0;
	ArgValue input_order = ORDER_ALL;
	string input_file = "";

	ArgValue output_para = DEFAULT;

	p_func_comp sort_funcs_comp[2] = {nullptr};
	p_func_time sort_funcs_time[2] = {nullptr};
	string algo_name[2] = {""};
};

ProgramArguments processArguments(int argc, char** argv);
void runProgram(ProgramArguments prog_args);

