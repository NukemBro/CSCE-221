all: run-tddl

run-tddl: TemplateMain.o 
	c++ -std=c++11 TemplateMain.o -o run-tdll

TemplateMain.o: TemplateMain.cpp TemplateDoublyLinkedList.h
	c++ -std=c++11 -c TemplateMain.cpp

clean:
	rm -f *.o run-tdll
