//============================================================================
// Copyright   : Grant Hruzek ©
//============================================================================

#include "Graph.hpp"
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// Breadth-First-Search
void Graph::BFS(int start, int end) {
	list<int> queue;
	vector<int> path;
	int size = vertices.size();

	// initialize boolean array, set each vertex to unvisited
	bool *visited = new bool[size];
	for (int i = 0; i < size; ++i) {
		visited[i] = false;
	}

	// Mark the current node as visited and enqueue it
	// the starting node is the eldest parent, so set its parent to -1
	visited[start] = true;
	queue.push_back(start);
	vertices.at(start).setParent(-1);

	while (!queue.empty()) {
		start = queue.front();
		queue.pop_front();
		// Get neighboring vertices of the dequeued vertex
		// If neighboring vertices are not visited, enqueue them
		// set each vertices' parent so we can compute shortest path
		for (Edge e : adj_list.at(start)) {
			if (!visited[e.end - '0'])
			{
				visited[e.end - '0'] = true;
				queue.push_back(e.end - '0');
				vertices.at(e.end - '0').setParent(start);
			}
		}
	}
	// here we follow the parents of the current node to find shortest path starting
	// with the last node and ending at the eldest node which has a parent value of -1
	int i = end;
	path.push_back(end);
	while (vertices.at(i).parent != -1) {
		path.push_back(vertices.at(i).parent);
		i = vertices.at(i).parent;
	}
	reverse(path.begin(), path.end());
	cout << "Length of Shortest Path: " << path.size() - 1 << endl;
	cout << "Shortest Path: ";
	printVector(path);
}

// build a graph from the adjacency list
void Graph::buildGraph(ifstream &in) {
	string s;
	int node = 0;
	bool firstLine = true;
	while (!in.eof()) {
		getline(in, s);
		string::iterator end_pos = std::remove(s.begin(), s.end(), ' ');
		s.erase(end_pos, s.end());
		if (firstLine) {
			// first line contains # of vertices and edges in entire graph
			cout << "Vertices: " << s[0] << " " << "Edges: " << s[1] << endl;
			firstLine = false;
		}
		else {
			int i = 0;
			Vertex v(node);	// create vertex for current node
			vertices.push_back(v); // pushback vertex into vector of all vertices in graph
			while (s[i] != '-') {
				// create edges from current vertex to connected vertices and add them to vertex's edgelist
				v.edgeList.push_back(Edge(node, s[i], 1));
				// pushback each vertices' list of edges into vector of all lists of edges in graph
				i++;
			}
			adj_list.push_back(v.edgeList);
			node++;
		}
	}
}

// display the graph
void Graph::displayGraph() {
	ofstream output_file("output.data");
	for (int i = 0; i < vertices.size(); ++i) {
		// print to terminal
		cout << vertices.at(i) << ": ";
		cout << adj_list.at(i);
		cout << endl;

		// print to output data file
		output_file << vertices.at(i) << ": ";
		output_file << adj_list.at(i);
		output_file << endl;
	}
}

// partitions the graph
bool Graph::checkBipartite() {
	int i = 0;
	groupA.push_back(vertices.at(i).label);
	for (Edge v : adj_list.at(i)) {
		groupB.push_back(v.end - '0');
	}
	while (i < vertices.size() - 1) {
		// partition vertices
		vector<int>::iterator it;
		it = find(groupB.begin(), groupB.end(), vertices.at(i + 1).label);
		if (it != groupB.end()) {
			for (Edge v : adj_list.at(i + 1)) {
				groupA.push_back(v.end - '0');
			}
		}
		else {
			for (Edge v : adj_list.at(i + 1)) {
				groupB.push_back(v.end - '0');
			}
		}
		i++;
	}

	// Remove duplicate edges from sets to obtain possible splittable groups
	getGroup(groupA);
	getGroup(groupB);

	// check if groups are splittable
	if (canSplit(groupA, groupB)) {
		// print Group A
		cout << "Group A: ";
		printVector(groupA);

		// print Group B
		cout << "Group B: ";
		printVector(groupB);
		return true;
	}
	else {
		return false;
	}
}

// prints a vector
void Graph::printVector(const vector<int>& v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v.at(i) << " ";
	}
	cout << endl;
}

void Graph::getGroup(vector<int>& v) {
	std::sort(v.begin(), v.end());
	v.erase(std::unique(v.begin(), v.end()), v.end());
}

bool Graph::canSplit(vector<int>& v1, vector<int>& v2) {
	vector<int>::iterator it;
	for (int i = 0; i < v1.size(); ++i) {
		it = find(v2.begin(), v2.end(), v1.at(i));
		if (it != v2.end()) {
			return false;
		}
	}
	return true;
}

bool Graph::checkGrouping(int start, int end) {
	if (find(groupA.begin(), groupA.end(), start) != groupA.end()) {
		if (find(groupA.begin(), groupA.end(), end) != groupA.end()) {
			return true;
		}
		else { return false; }
	}
	else if (find(groupB.begin(), groupB.end(), start) != groupB.end()) {
		if (find(groupB.begin(), groupB.end(), end) != groupB.end()) {
			return true;
		}
		else { return false; }
	}
	else {
		return false;
	}
}