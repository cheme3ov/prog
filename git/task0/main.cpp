#include "calculator.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
	
	if (argc < 2){
		std::cerr << "Not enought arguments" << '\n';
	}


	int a = stoi(argv[1]);
	int b = stoi(argv[3]);
	if(argv[2][0] == '+'){
		cerr << add(a,b) << endl;
		return 0;
	}
	if(argv[2][0] == 'x'){
		cerr << mult(a,b) << endl;;
		return 0;
	}

	return 0;
}
