all: main

main: hash.o main.o
	g++ -std=c++14 -o main hash.o main.o

main.o: hash.h
	g++ -std=c++14 -c main.cpp

hash.o:
	g++ -std=c++14 -c hash.cpp
	
clean:
	rm *.o main
