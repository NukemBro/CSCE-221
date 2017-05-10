all: run-dll

run-dll: DoublyLinkedList.o Main.o
	c++ -std=c++11 DoublyLinkedList.o Main.o -o run-dll

DoublyLinkedList.o: DoublyLinkedList.cpp DoublyLinkedList.h
	c++ -std=c++11 -c DoublyLinkedList.cpp

Main.o: Main.cpp DoublyLinkedList.h
	c++ -std=c++11 -c Main.cpp

clean:
	rm -f *.o run-dll
