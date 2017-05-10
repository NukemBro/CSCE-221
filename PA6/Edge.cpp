//============================================================================
// Copyright   : Grant Hruzek ©
//============================================================================

#include "Edge.hpp"
#include <iostream>
#include <list>

using namespace std;

Edge::Edge(int start, int end, int weight) {
	this->start = start;
	this->end = end;
	this->weight = weight;
}

std::ostream& operator<<(std::ostream& out, list<Edge>& e)
{
	for (Edge v : e) {
		out << v.end - '0' << " ";
	}
	return out;
}
