//============================================================================
// Copyright   : Grant Hruzek ©
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <list>

class HashTable;

class Node {
private:
	int key; // UIN
	int value; // grade
	friend class HashTable;
public:
	Node(int k = 0, int v = 0 )
		: key(k), value(v) {}
	int getKey() const { return key; } // returns UIN
	int getValue() const { return value; } // returns grade
};

class HashTable {
private:
	std::vector<std::list<Node>> table;
public:
	HashTable();
	~HashTable(); // destructor
	void insert(const int key, int value);
	int search(const int key);
	void printStats();
};