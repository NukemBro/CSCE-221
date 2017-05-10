//============================================================================
// Copyright   : Grant Hruzek ©
//============================================================================
 
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "hash.h"

using namespace std;

// Default Constructor
HashTable::HashTable() {}

HashTable::~HashTable() {}

//insert function
void HashTable::insert(const int key, int value) {
	Node node(key, value);
	list<Node> list;
	list.push_back(node);
	table.push_back(list);
}

// search function
int HashTable::search(const int key) {
	int hash = (key % table.size());
	int init = hash;
	while (table.at(hash).front().getKey() != key) {
		hash = (hash + 1) % table.size();
		if (hash == init) {
			return -1;
		}
	}
	return table.at(hash).front().getValue();
}

// prints statistics about hash table
void HashTable::printStats() {
	int min = 0;
	int max = 0;
	int avg = 0;
	cout << "Statistics: " << endl;

	// get min
	for (int i = 0; i < table.size(); i++) {
		min = table.at(0).size();
		if (min > table.at(i).size()) {
			min = table.at(i).size();
		}
	}
	cout << "Min: " << min << endl;

	// get max
	for (int i = 0; i < table.size(); i++) {
		max = table.at(0).size();
		if (max < table.at(i).size()) {
			max = table.at(i).size();
		}
	}
	cout << "Max: " << max << endl;

	// get average
	for (int i = 0; i < table.size(); ++i) {
		avg += table.at(i).size();
	}
	avg = avg / table.size();
	cout << "Average: " << avg << endl;
}
