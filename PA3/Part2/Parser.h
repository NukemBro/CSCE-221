//============================================================================
// Copyright   : Grant Hruzek ©
//============================================================================

#ifndef PARSER_H
#define PARSER_H

#include "LinkedStack.h"
#include "LinkedQueue.h"
#include "RuntimeException.h"
#include <math.h>
#include <string>
#include <vector>

class Parser {
private:
	string infix;
	bool pCheck(string s); // Checks for unmatching parenthesis
	int getOrder(char c); // gets priority of a operator
protected:
	// Queue for variable values
	LinkedQueue<double> varQueue;

	LinkedQueue<string> opQueue;
	LinkedStack<string> opStack;
public:
	// Constructor, handles exceptions
	Parser(std::string s) {
		if (!pCheck(s)) {
			cout << "Usage: " << endl;
			cout << "1. Equation must have matching parenthesis" << endl;
			cout << "2. Equation must be terminated by #" << endl;
			cout << "3. Equation variables must be uppercase" << endl;
			throw invalid_argument("Equation must have matching parenthesis, be terminated by #, and be all uppercase");
		}
		infix = s;
	}

	void toPostfix();
	void printInfix();
	void printPostfix();
	string getInfix() { return infix; }
	friend class Evaluator;
};

#endif
