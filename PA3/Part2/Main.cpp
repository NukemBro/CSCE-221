//============================================================================
// Copyright   : Grant Hruzek ©
//============================================================================

#include "RuntimeException.h"
#include "Parser.h"
#include "Evaluator.h"
#include <iostream>
#include <cctype>
#include <string>
#include <sstream>

using namespace std;

int main() {
	char input;
	int option;
	bool loop = true;
	while (loop) {
		string USER_INPUT = "";
		cout << "Enter an infix equation terminated by the # character" << endl;
		cin >> USER_INPUT;
		
		Parser p(USER_INPUT);
		p.toPostfix();
		p.printInfix();
		p.printPostfix();

		Evaluator e(p);
		e.printValue();

		cout << "Would you like to try another equation? (Y/N)" << endl;
		cin >> input;
		if (input == 'Y') {
			loop = true;
		}
		else if (input == 'N') {
			loop = false;
			break;
		}
		else {
			cout << "Invalid option, Exiting..." << endl;
			break;
		}
		cout << "----------------------------------------------" << endl << endl;
	}
	return 0;  
}
