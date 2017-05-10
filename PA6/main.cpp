//============================================================================
// Copyright   : Grant Hruzek ©
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
#include "Graph.hpp"


int main(int argc, const char * argv[]) {
    try{
        if (argc != 2) throw invalid_argument("Usage: ./main <file name>");
        ifstream in(argv[1]);
        if (!in) throw invalid_argument("Invalid file name or unable to open file.");
		int start = 0;
		int end = 0;
        Graph g;
        g.buildGraph(in);
		g.displayGraph();
		if (g.checkBipartite()) {
			int numVert = g.vertices.size() - 1;
			cout << "Input a start vertex: "; cin >> start;
			cout << "Input an end vertex: "; cin >> end;
			// checks for valid input regarding vertex labels
			if (start < 0 || start > numVert || end < 0 || end > numVert || start == end) {
				cout << "Invalid input vertices" << endl;
				return 0;
			}
			else {
				// if start and end share same group, compute SP, else terminate
				if (g.checkGrouping(start, end)) {
					g.BFS(start, end);
				}
				else {
					cout << "Start and End vertices not in same group" << endl;
					return 0;
				}
			}
		}
		else {
			cout << "A grouping is not possible" << endl;
			return 0;
		}
        return 0;
    }
    catch (exception& error){
        cerr << "Error: " << error.what() << endl;
    }
}

