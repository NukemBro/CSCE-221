all: run-main

run-main: Parser.o Evaluator.o Main.o
	g++ -std=c++14 -o run-main Parser.o Evaluator.o Main.o

Main.o: Parser.h Evaluator.h RuntimeException.h
	g++ -std=c++14 -c Main.cpp

Evaluator.o: Evaluator.h Parser.h LinkedStack.h LinkedQueue.h TemplateDoublyLinkedList.h RuntimeException.h
	g++ -std=c++14 -c Evaluator.cpp

Parser.o: Parser.h LinkedStack.h LinkedQueue.h TemplateDoublyLinkedList.h RuntimeException.h
	g++ -std=c++14 -c Parser.cpp

clean:
	rm *.o run-main
