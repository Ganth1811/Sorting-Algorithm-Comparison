# include "program.h"


int main(int argc, char** argv) {
	ProgramArguments prog_args = processArguments(argc, argv);
	runProgram(prog_args);
	return 0;
}