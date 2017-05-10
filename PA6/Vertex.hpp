//============================================================================
// Copyright   : Grant Hruzek ©
//============================================================================

#ifndef Vertex_hpp
#define Vertex_hpp

#include <stdio.h>
#include <list>
#include <string>
#include <vector>
#include "Edge.hpp"

using namespace std;

class Vertex {
public:
    // the label of this vertex
	int label = 0;
    // using a linked-list to manage its edges which offers O(c) insertion
    list<Edge> edgeList;

	// parent node
	int parent = 0;

	Vertex() {}
    
	Vertex(int label);

	// sets node's parent
	void setParent(int parent);
};

ostream& operator<<(ostream& out, Vertex& v);

#endif
