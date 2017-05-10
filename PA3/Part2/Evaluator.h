//============================================================================
// Copyright   : Grant Hruzek ©
//============================================================================
#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "Parser.h"
#include "LinkedQueue.h"
#include "LinkedStack.h"
#include "RuntimeException.h"

class Evaluator {
public:
  // user-defined exceptions
  class DivisionByZeroException : public RuntimeException {
    public:
      DivisionByZeroException() : RuntimeException("Division by zero") {}
  };     
private:
	// Queue for variable values
	LinkedQueue<double> varQueue;

	LinkedQueue<string> postQueue;
	LinkedStack<string> valStack;
public:
	// constructor
	Evaluator(Parser& par);
	double getValue(); // returns the result of postfix evaluation
	void printValue(); // prints the result of postfix evaluation
	friend class Parser;
};

#endif
