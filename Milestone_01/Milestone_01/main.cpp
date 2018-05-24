#include <iostream>
using namespace std;

/*	I/O
		READ			10	read into memory
		Write			11
	Load/store operations
		LOAD			20	load from memory location into accumulator
		STORE			21
	Arithmetic operation
		ADD				30	number in memory location + number in accumulator (keep result in accumulator)
		SUB				31
		DIV				32
		MULT			33
	Control operations
		BRANCH			40	branch into specific location in memory
		BRANCHNEG		41
		BRANCHZERO		42
		HALT			43
	Debugging opreations
		MEMDUMP			print the memory image on the screen
		BREAK
		CONTINUE
	Terminate program	-99999
*/

void Parse_Input_From_File(int command, int location) {

}

void Calculate_Operations() {
	
	const int MEMORY_SIZE = 99;
	int memory[MEMORY_SIZE];
	int accumulator;
	int result;
	int inputToMemory, outputFromMemory;

	int command, location, branchLocation;

	// Parse_Input_From_File(command, location)

	// Things will be calculated here

	//To determine which Command has been sent, and execute calculations. -Scott
	switch (command) {
	
	//Read
	case 10:
		memory[location] = inputToMemory;
		break;
	
	//Write
	case 11:
		break;
	
	//Load
	case 20:
		accumulator = memory[location];
		break;
	
	//Store
	case 21:
		break;

	//Addition 
	case 30:
		result = accumulator + memory[location];
		break;

	//Subtraction 
	case 31:
		result = accumulator - memory[location];
		break;

	//Division 
	case 32:
		//Divisor can't be 0
		if (memory[location] != 0) {
			result = accumulator / memory[location];
		}
		else {
			result = 99999;
		}
		break;

	//Multiplication 
	case 33:
		result = accumulator * memory[location];
		break;
	
	//Branch
	case 40:
		break;
	
	//BranchNeg
	case 41:
		break;
	
	//BranchZero
	case 42:
		break;
	
	//Halt
	case 43:
		break;
	}
	//Cases for Memdump, break, continue? -Scott


	// Output_Data()
	
}



// Output_Data()

int main() {
	Calculate_Operations();
	return 0;
}