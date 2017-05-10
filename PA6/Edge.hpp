//============================================================================
// Copyright   : Grant Hruzek ©
//============================================================================

#ifndef Edge_hpp
#define Edge_hpp

#include <stdio.h>
#include <iostream>
#include <list>

using namespace std;

class Edge {
public:
    // start vertex's label
    int start;
    // end vertex's label
    int end;
    // the weight of this edge
    int weight;

    Edge(int start, int end, int weight);
};

ostream& operator<<(ostream& out, list<Edge>& e);

#endif 
