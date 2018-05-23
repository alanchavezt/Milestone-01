#include <iostream>
using namespace std;

/*	I/O:
		READ		10	read into memory
		Write		11
	Load/store operations
		LOAD		20	load from memory location into accumulator
		STORE		21
	Arithmetic operation
		ADD			30	number in memory location + number in accumulator (keep result in accumulator)
		SUB			31
		DIV			32
		MULT		33
	Control operations
		BRANCH		40	branch into specific location in memory
		BRANCHNEG	41
		BRANCHZERO	42
		HALT		43
	Debugging opreations
		MEMDUMP			print the memory image on the screen
		BREAK
		CONTINUE
	Terminate		-99999
*/

void Parse_Input_From_File() {

}

void Calculate_Operations() {
	
	const int MEMORY_SIZE = 99;
	int memory[MEMORY_SIZE];
	int accumulator;
	int valueFromInput;
	int result;

	
}

void Output_Data() {

}

int main() {
	cout << "Hello World!" << endl;
	return 0;
}