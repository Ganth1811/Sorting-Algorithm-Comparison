#include "program.h"

unordered_map<string, p_func1> algos1_map = {
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
	{"flash-sort", flashSort}
};

unordered_map<string, p_func2> algos2_map = {
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
	{"flash-sort", flashSort}
};

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



void experimentMode(string sort_name) {
	if (algos1_map.find(sort_name) == algos1_map.end()) return;

	ull comp_count = 0;
	std::chrono::duration<double> run_time;
	vector<type> data_set1, data_set2;
	ofstream fout;
	string file_name = "result\\" + sort_name + ".csv";

	ArgValue data_orders[] = {ORDER_RANDOM, ORDER_NSORTED, ORDER_SORTED, ORDER_REVERSE};
	string order_names[4] = {"Randomized", "Nearly sorted", "Sorted", "Reversed"};
	int data_sizes[] = {10000, 30000, 50000, 100000, 300000, 500000};

	p_func1 sort_algo1 = algos1_map[sort_name];
	p_func2 sort_algo2 = algos2_map[sort_name];

	fout.open(file_name, ios::app);
	fout << "Orders" << ',' << "Size" << ',' << "Run_time" << "," << "Comparison" << endl;
	fout.close();


	for (int i = 0; i < 4; i++) {
		for (int data_size : data_sizes) {
			for (int j = 0; j < 3; j++) {
				comp_count = 0;
				data_set1 = generateDataSet(data_orders[i], data_size);
				data_set2 = data_set1;

				// count comparison
				sort_algo1(data_set1, comp_count);

				// count time
				auto start = chrono::high_resolution_clock::now();
				sort_algo2(data_set2);
				auto end = chrono::high_resolution_clock::now();
				run_time = end - start;

				// write data
				fout.open(file_name, ios::app);
				fout << order_names[i] << ',' << data_size << ',' << run_time.count() << "," << comp_count << endl;
				fout.close();
			}
		}
	}
}