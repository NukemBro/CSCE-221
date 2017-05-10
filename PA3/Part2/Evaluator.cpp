//============================================================================
// Copyright   : Grant Hruzek ©
//============================================================================
#include "Evaluator.h" 

using namespace std;

// Constructor
Evaluator::Evaluator(Parser& par) {
	postQueue = par.opQueue;
	varQueue = par.varQueue;
}

// returns mathematical value of equation
double Evaluator::getValue() {
	string temp = postQueue.dequeue();
	string var;
	while (!postQueue.isEmpty()) {
		if (isdigit(temp[0])) {
			valStack.push(temp);
		}
		else if (isalpha(temp[0])) {
			var = to_string(varQueue.dequeue());
			valStack.push(var);
		}
		else if (temp[0] == '#') {
			break;
		}
		else {
			double v1 = stod(valStack.pop());
			double v2 = stod(valStack.pop());
			string output;
			switch (temp[0]) {
			case '+':
				valStack.push(to_string(v1 + v2));
				break;
			case '-':
				valStack.push(to_string(v2 - v1));
				break;
			case '*':
				valStack.push(to_string(v1 * v2));
				break;
			case '/':
				if (v1 == 0) {
					cout << "Cannot divide by zero!" << endl;
					throw DivisionByZeroException();
				} else {
					valStack.push(to_string(v2 / v1));
				}
				break;
			case '^':
				valStack.push(to_string(pow(v2, v1)));
				break;
			default:
				throw invalid_argument("invalid input");
			}
		}
		temp = postQueue.dequeue();
	}
	return stod(valStack.top());
}

// prints value of postfix evaluation
void Evaluator::printValue() {
	cout << "postFix Value: " << getValue() << endl;
}
