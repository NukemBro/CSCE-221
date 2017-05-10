//============================================================================
// Copyright   : Grant Hruzek ©
//============================================================================

#include "Vertex.hpp"

using namespace std;

Vertex::Vertex(int label) : label(label) {}

void Vertex::setParent(int parent) {
	this->parent = parent;
}

std::ostream& operator<<(std::ostream& out, Vertex& v)
{
	out << v.label;
	return out;
}