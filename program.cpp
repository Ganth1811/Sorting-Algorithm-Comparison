#include "program.h"

unordered_map<string, ArgValue> mode_map = {
	{"-a", ALGORITHM_MODE},
	{"-c", COMPARISON_MODE},
};

unordered_map<string, p_func_comp> algos_comp_map = {
	{"selection-sort", selectionSort},
	{"insertion-sort", insertionSort},
	{"bubble-sort", bubbleSort},
	{"heap-sort", heapSort},
	{"merge-sort", mergeSort},
	{"quick-sort", quickSort},
	{"radix-sort", radixSort},
	{"shaker-sort", shakerSort},
	{"shell-sort", shellSort},
	{"counting-sort", countingSort},
	{"flash-sort", flashSort},
	{"optimized-bubble-sort", optimizedBubbleSort},
	{"binary-insertion-sort", binaryInsertionSort},
	{"randomized-quick-sort", randomizedQuickSort},
	{"median-quick-sort", medianQuickSort}
};

unordered_map<string, p_func_time> algos_time_map = {
	{"selection-sort", selectionSort},
	{"insertion-sort", insertionSort},
	{"bubble-sort", bubbleSort},
	{"heap-sort", heapSort},
	{"merge-sort", mergeSort},
	{"quick-sort", quickSort},
	{"radix-sort", radixSort},
	{"shaker-sort", shakerSort},
	{"shell-sort", shellSort},
	{"counting-sort", countingSort},
	{"flash-sort", flashSort},
	{"optimized-bubble-sort", optimizedBubbleSort},
	{"binary-insertion-sort", binaryInsertionSort},
	{"randomized-quick-sort", randomizedQuickSort},
	{"median-quick-sort", medianQuickSort}
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


//	Command 1: Run a sorting algorithm on the given input data.
//	[Execution file] -a [Algorithm] [Given input] [Output parameter(s)]
//	a.exe -a radix-sort input.txt -both

//	Command 2: Run a sorting algorithm on the data generated automatically with specified size and order.
//	[Execution file] -a [Algorithm] [Input size] [Input order] [Output parameter(s)]
//	a.exe -a selection-sort 50 -rand -time

//	Command 3: Run a sorting algorithm on ALL data arrangements of a specified size.
//	[Execution file] -a [Algorithm] [Input size] [Output parameter(s)]
//	a.exe -a binary-insertion-sort 70000 -comp

//	Command 4: Run two sorting algorithms on the given input.
//	[Execution file] -c [Algorithm 1] [Algorithm 2] [Given input]
//	a.exe -c heap-sort merge-sort input.txt

//	Command 5: Run two sorting algorithms on the data generated automatically.
//	[Execution file] -c [Algorithm 1] [Algorithm 2] [Input size] [Input order]
//	a.exe -c quick-sort merge-sort 100000 -nsorted


string getSortName(string argv) {
	string name = argv;
	size_t pos = name.find('-');
	while (pos != string::npos) {
		name.replace(pos, 1, 1, ' ');
		pos = name.find('-');
	}
	name[0] -= 32;
	return name;
}

string addComma(ull n) {
	string out = to_string(n);
	for(int i = out.length() - 3; i > 0; i-=3) {
		out.insert(i, 1, ',');
	}
	return out;
}

ProgramArguments processArguments(int argc, char** argv) {
	ProgramArguments prog_args;

	int argv_idx = 1;

	// get mode
	if (mode_map.find(argv[argv_idx]) != mode_map.end()) {
		prog_args.mode = mode_map[argv[argv_idx]];
	}
	argv_idx++;

	// get algorithm
	if (algos_comp_map.find(string(argv[argv_idx])) != algos_comp_map.end()) {
		prog_args.sort_funcs_comp[0] = algos_comp_map[argv[argv_idx]];
		prog_args.sort_funcs_time[0] = algos_time_map[argv[argv_idx]];
		prog_args.algo_name[0] = getSortName(argv[argv_idx]);
	}
	argv_idx++;

	// get second algorithm if it is comparison mode
	if (prog_args.mode == COMPARISON_MODE) {
		if (algos_comp_map.find(string(argv[argv_idx])) != algos_comp_map.end()) {
			prog_args.sort_funcs_comp[1] = algos_comp_map[argv[argv_idx]];
			prog_args.sort_funcs_time[1] = algos_time_map[argv[argv_idx]];
			prog_args.algo_name[1] = getSortName(argv[argv_idx]);
		}
		argv_idx++;
	}

	// get input file or input size
	if (string(argv[argv_idx]).find(".txt") != string::npos) {	// is input file
		prog_args.input_mode = INP_FILE;
		prog_args.input_file = argv[argv_idx];
		if (prog_args.mode == COMPARISON_MODE) {
			return prog_args;
		}
	}
	else {
		prog_args.input_mode = INP_GENERATED;
		prog_args.input_size = stoi(string(argv[argv_idx]));
	}
	argv_idx++;

	// get input order
	if (order_map.find(argv[argv_idx]) != order_map.end()) {
		prog_args.input_order = order_map[argv[argv_idx]];
		if (prog_args.mode == COMPARISON_MODE) {
			return prog_args;
		}
		argv_idx++;
	}

	// get output parameter
	if (output_map.find(argv[argv_idx]) != output_map.end()) {
		prog_args.output_para = output_map[argv[argv_idx]];
	}
	return prog_args;
}

vector<type> readFile(string input_file) {
	vector<type> v;
	int n = 0;
	int data;
	ifstream fin;
	fin.open(input_file);
	if (!fin.good()) return v;
	fin >> n;
	for (int i = 0; i < n; i++) {
		fin >> data;
		v.push_back(data);
	}
	fin.close();
	return v;
}

void writeFile(string output_file, vector<type> v) {
	int n = v.size();
	ofstream fout;
	fout.open(output_file);
	if (!fout.good()) return;
	fout << n << endl;
	for (int i = 0; i < n; i++) {
		fout << v[i] << ' ';
	}
	fout.close();
}

vector<type> generateDataSet(ArgValue input_order, int input_size) {
	vector<type> data_set;
	int *arr = new int[input_size];
	switch (input_order) {
		case ORDER_RANDOM:
			GenerateData(arr, input_size, 0);
			data_set = vector<type>(arr, arr + input_size);
			break;

		case ORDER_SORTED:
			GenerateData(arr, input_size, 1);
			data_set = vector<type>(arr, arr + input_size);
			break;

		case ORDER_REVERSE:
			GenerateData(arr, input_size, 2);
			data_set = vector<type>(arr, arr + input_size);
			break;

		case ORDER_NSORTED:
			GenerateData(arr, input_size, 3);
			data_set = vector<type>(arr, arr + input_size);
			break;
		
		default:
			break;
		}
	delete [] arr;
	return data_set;
}


void algorithmMode(ProgramArguments prog_args) {
	vector<type> original_data_set;
	vector<type> copy_data_set;
	ull comp_count;
	p_func_comp sort_func_comp = prog_args.sort_funcs_comp[0];
	p_func_time sort_func_time = prog_args.sort_funcs_time[0];

	cout << "Algorithm: " << prog_args.algo_name[0] << endl;

	if (prog_args.input_mode == INP_FILE) {		// input file, for command 1
		original_data_set = readFile(prog_args.input_file);
		comp_count = 0;

		cout << "Input file: " << prog_args.input_file << endl << endl;
		cout << "Input size: " << original_data_set.size() << endl;
		cout << "--------------------------" << endl;

		// run sort for counting time
		if (prog_args.output_para & OUT_TIME) {
			copy_data_set = original_data_set;
			auto start = chrono::high_resolution_clock::now();
			sort_func_time(copy_data_set);
			auto end = chrono::high_resolution_clock::now();
			std::chrono::duration<double> run_time = end - start;
			cout << "Running time: " << run_time.count() << "s" << endl;
		}
		// run sort for counting comparison
		if (prog_args.output_para & OUT_COMPARISON) {
			copy_data_set = original_data_set;
			sort_func_comp(copy_data_set, comp_count);
			cout << "Comparisons: " << addComma(comp_count) << endl;
		}

		// write sorted data
		writeFile("output.txt", copy_data_set);
	}

	else if (prog_args.input_mode == INP_GENERATED) {	// genarate input, for command 2 and 3
		cout << "Input size: " << prog_args.input_size << endl << endl;
		ArgValue order_types[4] = {ORDER_RANDOM, ORDER_NSORTED, ORDER_SORTED, ORDER_REVERSE};
		string order_names[4] = {"Randomized", "Nearly sorted", "Sorted", "Reversed"};

		for (int i = 0; i < 4; i++) {
			if (prog_args.input_order & order_types[i]) {	// the order type indicator bit is 1 in input_order
				cout << "Input order: " << order_names[i] << endl;
				cout << "--------------------------" << endl;
				original_data_set = generateDataSet(order_types[i], prog_args.input_size);
				comp_count = 0;

				// write data set
				if (prog_args.input_order == ORDER_ALL) writeFile(string("input_") + to_string(i+1) + string(".txt"), original_data_set);
				else writeFile("input.txt", original_data_set);

				// run sort for counting time
				if (prog_args.output_para & OUT_TIME) {
					copy_data_set = original_data_set;
					auto start = chrono::high_resolution_clock::now();
					sort_func_time(copy_data_set);
					auto end = chrono::high_resolution_clock::now();
					std::chrono::duration<double> run_time = end - start;
					cout << "Running time: " << run_time.count() << "s" << endl;
				}
				// run sort for counting comparison
				if (prog_args.output_para & OUT_COMPARISON) {
					copy_data_set = original_data_set;
					sort_func_comp(copy_data_set, comp_count);
					cout << "Comparisons: " << addComma(comp_count) << endl;
				}
				cout << endl;
				// write sorted data
				writeFile("output.txt", copy_data_set);
			}
		}
	}
}


void comparisonMode(ProgramArguments prog_args) {
	vector<type> original_data_set;		// store the original data set
	vector<type> copy_data_set;			// store a copy of the original data set for the sorting algorithm to sort it
	ull comp_count[2] {0};
	std::chrono::duration<double> run_time[2];

	cout << "Algorithm: " << prog_args.algo_name[0] << " | " << prog_args.algo_name[1] << endl;

	if (prog_args.input_mode == INP_FILE) {		// input file, for command 4
		original_data_set = readFile(prog_args.input_file);

		cout << "Input file: " << prog_args.input_file << endl << endl;
		cout << "Input size: " << original_data_set.size() << endl;
		cout << "--------------------------" << endl;

		// run sort for counting time
		for (int i = 0; i < 2; i++) {
			// run sort for counting time
			p_func_time sort_func_time = prog_args.sort_funcs_time[i];
			copy_data_set = original_data_set;
			auto start = chrono::high_resolution_clock::now();
			sort_func_time(copy_data_set);
			auto end = chrono::high_resolution_clock::now();
			run_time[i] = end - start;
		}
		cout << "Running time: " << run_time[0].count() << "s | " << run_time[1].count() << "s" << endl;

		// run sort for counting comparison
		for (int i = 0; i < 2; i++)  {
			p_func_comp sort_func_comp = prog_args.sort_funcs_comp[i];
			comp_count[i] = 0;
			copy_data_set = original_data_set;
			sort_func_comp(copy_data_set, comp_count[i]);
		}
		cout << "Comparisons: " << addComma(comp_count[0]) << " | " << addComma(comp_count[1]) << endl;
	}

	else if (prog_args.input_mode == INP_GENERATED) {	// genarate input, for command 5
		cout << "Input size: " << prog_args.input_size << endl << endl;
		ArgValue order_types[4] = {ORDER_RANDOM, ORDER_NSORTED, ORDER_SORTED, ORDER_REVERSE};
		string order_names[4] = {"Randomized", "Nearly sorted", "Sorted", "Reversed"};

		for (int i = 0; i < 4; i++) {
			if (prog_args.input_order & order_types[i]) {	// the order type indicator bit is 1 in input_order
				cout << "Input order: " << order_names[i] << endl;
				cout << "--------------------------" << endl;
				original_data_set = generateDataSet(order_types[i], prog_args.input_size);

				// write data set
				writeFile("input.txt", original_data_set);

				// run sort for counting time
				for (int i = 0; i < 2; i++) {
					// run sort for counting time
					p_func_time sort_func_time = prog_args.sort_funcs_time[i];
					copy_data_set = original_data_set;
					auto start = chrono::high_resolution_clock::now();
					sort_func_time(copy_data_set);
					auto end = chrono::high_resolution_clock::now();
					run_time[i] = end - start;
				}
				cout << "Running time: " << run_time[0].count() << "s | " << run_time[1].count() << "s" << endl;
				
				// run sort for counting comparison
				for (int i = 0; i < 2; i++)  {
					p_func_comp sort_func_comp = prog_args.sort_funcs_comp[i];
					comp_count[i] = 0;
					copy_data_set = original_data_set;
					sort_func_comp(copy_data_set, comp_count[i]);
				}
				cout << "Comparisons: " << addComma(comp_count[0]) << " | " << addComma(comp_count[1]) << endl;
				
				cout << endl;
				break;	// run 1 order only
			}
		}
	}
}

void runProgram(ProgramArguments prog_args) {
	if (prog_args.mode == ALGORITHM_MODE) {
		cout << "ALGORITHM MODE" << endl;
		algorithmMode(prog_args);
	}
	else if (prog_args.mode == COMPARISON_MODE) {
		cout << "COMPARISON MODE" << endl;
		comparisonMode(prog_args);
	}
	else {
		cout << "Invalid mode";
	}
}