#include <iostream>
#include <string>
#include <vector>
#include <iterator>

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



class Menu{
    int code;
    string name;
public:
    Menu(int c, string n) : code(c), name(n){};
    Menu(const Menu &m) : code(m.code), name(m.name) { }
    
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

void showMenu(vector<Menu> &v){
    for (vector<Menu>::iterator it = v.begin() ; it != v.end(); ++it){
        cout<<it->getCode()<< " - " << it->getName()<<endl;
    }
}

class Instruction{
    int operation;
    int operand;
public:
    Instruction(int opt, int opn) : operation(opt), operand(opn){};
    Instruction(const Instruction &i) : operation(i.operation), operand(i.operand) { }
    
    void setOperation(int opt){
        this->operation = opt;
    }
    
    void setOperand(int opn){
        this->operand = opn;
    }
    
    int getOperation(){
        return this->operation;
    }
    
    int getOperand(){
        return this->operand;
    }
};

void showMainMemory(vector<Instruction> &v){
    for (vector<Instruction>::iterator it = v.begin() ; it != v.end(); ++it){
        cout<< distance(v.begin(), it) << "\t" <<it->getOperation()<< " - " << it->getOperand()<<endl;
    }
}



int main(int argc, const char * argv[]) {
    
    Calculate_Operations();
	
	
	
    vector<Instruction> *mainMemory = new vector<Instruction>;
    vector<Menu> *vecptr = new vector<Menu>;
    vecptr->push_back(Menu(10,"READ"));
    vecptr->push_back(Menu(11,"WRITE"));
    vecptr->push_back(Menu(20,"LOAD"));
    vecptr->push_back(Menu(21,"STORE"));
    vecptr->push_back(Menu(30,"ADD"));
    vecptr->push_back(Menu(31,"SUB"));
    vecptr->push_back(Menu(32,"DIV"));
    vecptr->push_back(Menu(33,"MULT"));
    vecptr->push_back(Menu(40,"BRANCH"));
    vecptr->push_back(Menu(41,"BRANCHNEG"));
    vecptr->push_back(Menu(42,"BRANCHZERO"));
    vecptr->push_back(Menu(43,"HALT"));
    vecptr->push_back(Menu(-99999,"Terminate"));

    string input;
    int operation;
    int operand;
    long inst = 0;
    bool menuQuit = false;

    cout << "What action would you like to take?\n"<<endl;
    showMenu(*vecptr);
    
    while (menuQuit == false)
    {
        
        cin >> input;

        if(stoi(input) > 0){
            inst = stoi(input);
            input = to_string(inst);
            operation = stoi(input.substr (0,2));
            operand = stoi(input.substr (2,2));
            
            cout<<"input: "<< inst <<endl;
            cout<<"first: "<< operation <<endl;
            cout<<"last: "<< operand <<endl;

            if(any_of(vecptr->begin(), vecptr->end(), [operation](Menu i){return i.getCode() == operation;})){
                if(operand>= 0 && operand<100){
                    std::cout << "Pushing operation...\n";
                    mainMemory->push_back(Instruction(operation,operand));
                }
                
            }
        }
        else if(stoi(input) == -99999){
            std::cout << "Exiting....\n";
            menuQuit = true;
            
//            inst = stoi(input);
//            input = to_string(inst);
//            operation = stoi(input.substr (1,2));
//            operand = stoi(input.substr (3,2));
        }
        
        cout<<"instrucction"<<inst<<endl;

        
    }

    cout<<"\n*********Memory********\n";
    showMainMemory(*mainMemory);

    return 0;
}
