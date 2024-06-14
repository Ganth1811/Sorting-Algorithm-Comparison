#include "program.h"

unordered_map<string, ArgValue> mode_map = {
	{"-a", ALGORITHM_MODE},
	{"-c", COMPARISON_MODE},
};

unordered_map<string, p_func> algos_map = {
	{"selection-sort", selectionSort},
	{"insertion-sort", insertionSort},
	{"bubble-sort", bubbleSort},
	{"heap-sort", heapSort},
	{"merge-sort", mergeSort},
	{"quick-sort", quickSort},
	{"radix-sort", radixSort}
};

unordered_map<string, ArgValue> order_map = {
	{"-rand", ORDER_RANDOM},
	{"-nsorted", ORDER_NSORTED},
	{"-sorted", ORDER_SORTED},
	{"-rev", ORDER_REVERSE},
};

unordered_map<string, ArgValue> output_map = {
	{"-time", OUT_TIME},
	{"-comp", OUT_COMPARISON},
	{"-both", OUT_BOTH}
};


//	Command 1:
//	[Execution file] -a [Algorithm] [Given input] [Output parameter(s)]
//	a.exe -a radix-sort input.txt -both

//	Command 2:
//	[Execution file] -a [Algorithm] [Input size] [Input order] [Output parameter(s)]
//	a.exe -a selection-sort 50 -rand -time

//	Command 3:
//	[Execution file] -a [Algorithm] [Input size] [Output parameter(s)]
//	a.exe -a binary-insertion-sort 70000 -comp

//	Command 4:
//	[Execution file] -c [Algorithm 1] [Algorithm 2] [Given input]
//	a.exe -c heap-sort merge-sort input.txt

//	Command 5:
//	[Execution file] -c [Algorithm 1] [Algorithm 2] [Input size] [Input order]
//	a.exe -c quick-sort merge-sort 100000 -nsorted


string getSortName(string argv) {
	string name = argv;
	size_t pos = name.find('-');
	while (pos != string::npos) {
		name.replace(pos, 1, 1, ' ');
		pos = name.find('-');
	}
	return name;
}

ProgramArguments processArguments(int argc, char** argv) {
	ProgramArguments program_args;

	int argv_idx = 1;

	// get mode
	if (mode_map.find(argv[argv_idx]) != mode_map.end()) {
		program_args.mode = mode_map[argv[argv_idx]];
	}
	argv_idx++;

	// get algorithm
	if (algos_map.find(string(argv[argv_idx])) != algos_map.end()) {
		program_args.n_sort_algos++;
		program_args.sort_algos[0] = algos_map[argv[argv_idx]];
		program_args.sort_name[0] = getSortName(argv[argv_idx]);
	}
	argv_idx++;

	// get second algorithm if it is comparison mode
	if (program_args.mode == COMPARISON_MODE) {
		if (algos_map.find(string(argv[argv_idx])) != algos_map.end()) {
			program_args.n_sort_algos++;
			program_args.sort_algos[1] = algos_map[argv[argv_idx]];
			program_args.sort_name[1] = getSortName(argv[argv_idx]);
		}
		argv_idx++;
	}

	// get input file or input size
	if (string(argv[argv_idx]).find(".txt") != string::npos) {	// is input file
		program_args.input_mode = INP_FILE;
		program_args.input_file = argv[argv_idx];
		if (program_args.mode == COMPARISON_MODE) {
			return program_args;
		}
	}
	else {
		program_args.input_mode = INP_GENERATED;
		program_args.input_size = stoi(string(argv[argv_idx]));
	}
	argv_idx++;

	// get input order
	if (order_map.find(argv[argv_idx]) != order_map.end()) {
		program_args.input_order = order_map[argv[argv_idx]];
		if (program_args.mode == COMPARISON_MODE) {
			return program_args;
		}
		argv_idx++;
	}

	// get output parameter
	if (output_map.find(argv[argv_idx]) != output_map.end()) {
		program_args.output_para = output_map[argv[argv_idx]];
	}
	return program_args;
}