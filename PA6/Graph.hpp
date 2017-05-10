//============================================================================
// Copyright   : Grant Hruzek ©
//============================================================================

#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>


#include "Vertex.hpp"

using namespace std;

class Graph {
public:
	vector<int> groupA;
	vector<int> groupB;
    vector<list<Edge>> adj_list; // adjacency list
    vector<Vertex> vertices;  // all vertices

	Graph() {} // default constructor
    void buildGraph(ifstream &in);  // build a graph from the adjacency list
    void displayGraph();  // display the graph
	bool checkBipartite(); // checks if graph is partitionable
	void BFS(int start, int end); // Breadth-First-Search

	// helper functions
	void printVector(const vector<int>& v);
	void getGroup(vector<int>& v);
	bool canSplit(vector<int>& v1, vector<int>& v2);
	bool checkGrouping(int start, int end);
};

#endif
