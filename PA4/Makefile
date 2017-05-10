all: run

run: main.o
	c++ -std=c++11 main.o -o main

main.o: main.cpp
	c++ -std=c++11 -c main.cpp

clean:
	rm -f *.o run
