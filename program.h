#pragma once

#include <unordered_map>
#include <string>
#include "sorting_algorithm.h"

using namespace std;

#define ALGORITHM_MODE 1
#define COMPARISON_MODE 2

#define ORDER_RANDOM 11
#define ORDER_NSORTED 12
#define ORDER_SORTED 13
#define ORDER_REVERSE 14
#define ORDER_ALL 15

#define OUT_TIME 21
#define OUT_COMPARISON 22
#define OUT_BOTH 23

#define INP_FILE 31
#define INP_GENERATED 32

typedef void (*p_func)(vector<type>&);
typedef int ArgValue;

struct ProgramArguments{
	ArgValue mode = NULL;

	ArgValue input_mode = NULL;
	ArgValue input_size = 0;
	ArgValue input_order = ORDER_ALL;
	string input_file = "";

	ArgValue output_para = NULL;

	int n_sort_algos = 0;
	p_func sort_algos[2] = {nullptr};
	string sort_name[2] = {""};
};

ProgramArguments processArguments(int argc, char** argv);
void performSort