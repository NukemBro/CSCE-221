//============================================================================
// Copyright   : Grant Hruzek ©
//============================================================================

#include "Parser.h"
#include <iostream>
#include <cctype>

using namespace std;

// infix to postfix logic
void Parser::toPostfix() {
	bool pop = true;
	int val;
	char var;
	if (infix.at(infix.length() - 1) != '#') {
		throw invalid_argument("infix notation does not end with # character");
	}
	else {
		opStack.push("#");
	}
	for (int i = 0; i < infix.length(); i++) {
		string s = "";
		s = infix[i];
		// check if char is a digit


		if (isdigit(infix[i])) {
			string getNums = "";
			getNums += infix[i];
			while (isdigit(infix[i + 1])) {
				getNums += infix[i + 1];
				++i;
			}
			opQueue.enqueue(getNums);
		}
		// check if char is a variable
		else if (isalpha(infix[i])) {
			cout << "Give a value for variable " << infix[i] << ":" << endl;
			cin >> val;
			varQueue.enqueue(val);
			opQueue.enqueue(to_string(val));
		}
		// check if char is an operator
		else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || 
				 infix[i] == '/' || infix[i] == '^') 
		{
			if (opStack.isEmpty()) {
				opStack.push(s);
			}
			// greater than precendence case comparing current char and top of stack
			else if (getOrder(infix[i]) > getOrder(opStack.top()[0])) {
				opStack.push(s);
			}
			// less than or equal to precendence case comparing current char and top of stack
			else if (getOrder(infix[i]) <= getOrder(opStack.top()[0])) {
				if (pop) {
					while (getOrder(infix[i]) <= getOrder(opStack.top()[0])) {
						opQueue.enqueue(opStack.top());
						opStack.pop();
					}
				}
				opStack.push(s);
			}
		}
		else if (infix[i] == '(') {
			// push t and do not pop until corresponding ')' is met
			pop = false;
			opStack.push(s);
		}
		else if (infix[i] == ')') {
			// pop opStack until corresponding '(' is met, then discard the '()' tokens
			pop = true;
			while (opStack.top()[0] != '(') {
				opQueue.enqueue(opStack.top());
				opStack.pop();
			}
			opStack.pop();
		}
		else if (infix[i] == '#') {
			break;
		}
		else {
			throw invalid_argument("Not a valid input character");
		}
	}
	// after all chars have been tokenized, empty the stack
	while (!opStack.isEmpty()) {
		opQueue.enqueue(opStack.top());
		opStack.pop();
	}
} 

// Checks for unmatching parenthesis, # token, and uppercase
bool Parser::pCheck(string s) {
	int left = 0;
	int right = 0;
	for (int i = 0; i < s.length(); ++i) {
		// throws exception if lower case letters are used in equation
		if ((int)s[i] >= 97 && (int)s[i] <= 122) {
			return false;
		}
		if (s[i] == '(') {
			left++;
		}
		if (s[i] == ')') {
			right++;
		}
	}
	// not terminated by # case
	if (s.at(s.length() - 1) != '#') {
		return false;
	}
	// uneven parenthesis case
	if (left != right) {
		return false;
	}
	// even parenthesis case
	else {
		return true;
	}
}

// gets priority of a operator
int Parser::getOrder(char c) {
	int order = 0;
	if (c == '+' || c == '-') {
		order = 1;
	}
	else if (c == '*' || c == '/') {
		order = 3;
	}
	else if (c == '^') {
		order = 6;
	}
	else if (c == '(') {
		order = 100;
	}
	else {
		order = 0;
	}
	return order;
}

// prints infix equation
void Parser::printInfix() {
	cout << "inFix: " << infix << endl;
}

//prints postfix equation
void Parser::printPostfix() {
	cout << "postFix: ";
	cout << opQueue;
	cout << endl;
}
