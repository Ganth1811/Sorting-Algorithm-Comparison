# include "program.h"


int main(int argc, char** argv) {
	ProgramArguments prog_args = processArguments(argc, argv);
	runProgram(prog_args);

	// unsigned long long comp_count = 0;
	// int n;
	// cin >> n;
	// int *arr = new int[n];
	// GenerateData(arr, n, 0);
	// vector<type> v(arr, arr + n);
	// radixSort(v, comp_count);
	// cout << comp_count;
	return 0;
}