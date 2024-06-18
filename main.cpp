# include "program.h"

/*
	Command 1: Run a sorting algorithm on the given input data.
		[Execution file] -a [Algorithm] [Input file] [Output parameter(s)]
		main.exe -a radix-sort input.txt -both

	Command 2: Run a sorting algorithm on the data generated automatically with specified size and order.
		[Execution file] -a [Algorithm] [Input size] [Input order] [Output parameter(s)]
		main.exe -a selection-sort 50 -rand -time

	Command 3: Run a sorting algorithm on ALL data arrangements of a specified size.
		[Execution file] -a [Algorithm] [Input size] [Output parameter(s)]
		main.exe -a binary-insertion-sort 70000 -comp

	Command 4: Run two sorting algorithms on the given input.
		[Execution file] -c [Algorithm 1] [Algorithm 2] [Input file]
		main.exe -c heap-sort merge-sort input.txt

	Command 5: Run two sorting algorithms on the data generated automatically.
		[Execution file] -c [Algorithm 1] [Algorithm 2] [Input size] [Input order]
		main.exe -c quick-sort merge-sort 100000 -nsorted
*/

int main(int argc, char** argv) {
	string sort_name = argv[1];
	experimentMode(sort_name);
	return 0;
}