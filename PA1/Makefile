all: main.o my_string.o
	c++ -std=c++11 main.o my_string.o -o main
main.o: my_string.h main.cpp
	c++ -std=c++11 -g -c main.cpp
my_string.o: my_string.cpp my_string.h
	c++ -std=c++11 -g -c my_string.cpp my_string.h
clean:
	rm *.o main
