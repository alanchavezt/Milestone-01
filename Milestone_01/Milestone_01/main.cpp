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

#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

void Parse_Input_From_File(int command, int location) {

}

void Calculate_Operations() {
	
	const int MEMORY_SIZE = 99;
	int memory[MEMORY_SIZE];
	int accumulator;
	int result;

	int command, location;

	// Parse_Input_From_File(command, location)

	// Things will be calculated here

	//To determine which Command has been sent, and execute calculations. -Scott
	switch (command) {
	
	//Read
	case 10:
		break;
	
	//Write
	case 11:
		break;
	
	//Load
	case 20:
		break;
	
	//Store
	case 21
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
		else{
			result = 99999
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

class Instruction{
    int code;
    string name;
public:
    Instruction(int c, string n) : code(c), name(n){};
    Instruction(const Instruction &i) : code(i.code), name(i.name) { }
    
    void setCode(int c){
        this->code = c;
    }
    
    void setName(string n){
        this->name = n;
    }
    
    int getCode(){
        return code;
    }
    
    string getName(){
        return name;
    }
};


int main(int argc, const char * argv[]) 
{
    Calculate_Operations();
	
    vector<Instruction> *vecptr = new vector<Instruction>;
    vecptr->push_back(Instruction(10,"READ"));
    vecptr->push_back(Instruction(11,"WRITE"));
    vecptr->push_back(Instruction(20,"LOAD"));
    vecptr->push_back(Instruction(21,"STORE"));
    vecptr->push_back(Instruction(30,"ADD"));
    vecptr->push_back(Instruction(31,"SUB"));
    vecptr->push_back(Instruction(32,"DIV"));
    vecptr->push_back(Instruction(33,"MULT"));
    vecptr->push_back(Instruction(40,"BRANCH"));
    vecptr->push_back(Instruction(41,"BRANCHNEG"));
    vecptr->push_back(Instruction(42,"BRANCHZERO"));
    vecptr->push_back(Instruction(43,"HALT"));
    vecptr->push_back(Instruction(-99999,"Terminate"));

   
    unsigned long response = 0;
    bool menuQuit = false;
    
    while (menuQuit == false)
    {
        do
        {
            std::cout << "What action would you like to take?\n"<<endl;
            for (vector<Instruction>::iterator it = vecptr->begin() ; it != vecptr->end(); ++it){
                cout<<it->getCode()<< " - " << it->getName()<<endl;
            }
            cin >> response;
            cout << "\n";
        }
        while (response == -99999);
        
        switch (response)
        {
            case 10:
                std::cout << "Seasons of the Year was selected!\n\n";
                break;
                
            case 11:
                std::cout << "BINGO was selected!\n\n";
                break;
                
            case 20:
                std::cout << "(My Loop) was selected!\n\n";
                break;
                
            case 21:
                std::cout << "(My Loop) was selected!\n\n";
                break;
                
            case 30:
                std::cout << "(My Loop) was selected!\n\n";
                break;
            
            case 31:
                std::cout << "(My Loop) was selected!\n\n";
                break;
                
            case 32:
                std::cout << "(My Loop) was selected!\n\n";
                break;
                
            case 4:
                std::cout << "Exiting....\n";
                menuQuit = true;
                break;
                
            default:
                std::cout << "\n** Invalid Menu Selection!! **\n\n";
                break;
        }
    }
    
    return 0;
}
