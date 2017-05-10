//============================================================================
// Copyright   : Grant Hruzek ©
//============================================================================

#include "my_string.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

// returns number of characters in string
int my_string::size() const {
	return sz;
}

// returns capacity of string
int my_string::capacity() const {
	if (cap < sz) {
		throw std::runtime_error("Memory Allocation Error!");
	}
	else {
		return cap;
	}
}

// checks if string is empty
bool my_string::empty() const {
	if (sz == 0) {
		return true;
	}
	else {
		return false;
	}
}

// returns the character at specified index without bounds checking
char my_string::operator[](int i) const {
	return ptr[i];
}

// returns the character at specified index with bounds checking
char my_string::at(int i) const {
	if (i >= 0 && i <= sz - 1) {
		return ptr[i];
	} else {
		throw std::out_of_range("Index out of Range");
	}
}

// inserts a string before index i
my_string& my_string::insert(int i, const my_string& s) {
	if (i >= 0 && i <= this->sz) {
		int total_size = this->sz + s.size();
		char *new_ptr = new char[total_size];
		for (int index = 0; index < i; ++index) {
			new_ptr[index] = ptr[index];
		}
		int index = i;
		int str = 0;
		while (index < i + s.sz) {
			new_ptr[index] = s[str];
			str++;
			index++;
			if (str > s.sz) {
				break;
			}
		}
		index = i + s.sz;
		str = i;
		while (index < total_size) {
			new_ptr[index] = ptr[str];
			str++;
			index++;
			if (str > this->sz) {
				break;
			}
		}
		delete[] ptr;
		ptr = new_ptr;
		this->sz = total_size;
		this->cap = this->cap + s.cap;
	}
	else {
		throw std::out_of_range("Index is out of range");
	}
	return *this;
}

// add operator to concatenate a specified string to my_string object
my_string& my_string::operator+=(const my_string& q) {
	int new_size = sz + q.size();
	while (new_size > this->cap) {
		resize();
	}
	for (int i = 0; i < q.size(); ++i) {
		ptr[i + sz] = q[i];
	}
	this->sz = new_size;
	return *this;
}

// add operator to append a single character to my_string object
my_string& my_string::operator+=(const char c) {
	int new_size = sz + 1;
	while (new_size > this->cap) {
		resize();
	}
	ptr[new_size - 1] = c;
	this->sz = new_size;
	return *this;
}

// default constructor
my_string::my_string() {
	ptr = new char[1];
	this->ptr[0] = '\0';
	this->sz = 0;
	this->cap = 1;
}

// constructor for allocating memory with n-capacity
my_string::my_string(int n) {
	if (n >= 0) {
		ptr = new char[n];
		cap = n;
	}
	else {
		throw std::out_of_range("Can not allocate negative bytes");
	}
}

// constructor for creating my_string object from C-sting (same size/cap)
my_string::my_string(const char* cstring) {
	int size = 0;
	while (cstring[size] != '\0') {
		size++;
	}
	ptr = new char[size];
	for (int i = 0; i < size; ++i)
	{
		ptr[i] = cstring[i];
	}
	cap = size;
	sz = size;
}

// copy constructor
my_string::my_string(const my_string& source) {
	this->ptr = new char[source.size()];
	for (int i = 0; i < source.size(); ++i) {
		ptr[i] = source.ptr[i];
	}
	this->sz = source.size();
	this->cap = source.capacity();
}

// destructor
my_string::~my_string() {}

// copy assignment
my_string& my_string::operator=(const my_string& other) {
	// check for self-assignment
	if (this != &other) {
		char *new_ptr = new char[other.capacity()];
		for (int i = 0; i < other.size(); ++i) {
			new_ptr[i] = other.ptr[i];
		}
		delete[] other.ptr;
		ptr = new_ptr;
		this->sz = other.size();
		this->cap = other.capacity();
	}
	return *this;
}

// helper resize function
void my_string::resize() {
	// conditional handles doubling capacity and the cap = 0 case
	if (this->cap > 0) {
		this->cap *= 2;
	}
	else {
		this->cap += 5;
	}
	char* new_ptr = new char[this->cap];
	for (int i = 0; i < this->sz; ++i) {
		new_ptr[i] = ptr[i];
	}
	delete[] ptr;
	ptr = new_ptr;
}

// an extra function that prints string for debugging purposes
void my_string::print() const {
	for (int i = 0; i < sz; ++i) {
		std::cout << this->at(i);
	}
	std::cout << std::endl;
	std::cout << "String size: " << this->size() << std::endl;
	std::cout << "String capacity: " << this->capacity() << std::endl;
	std::cout << std::endl;
}

// output operator
std::ostream& operator<<(std::ostream& os, const my_string& s) {
	for (int i = 0; i < s.size(); ++i) {
		os << s.at(i);
	}
	return os;
}

// input operator
std::istream& operator>>(std::istream& in, my_string& s) {
	char b[256] = "";
	in >> b;
	in.ignore(1, ' ');
	s += b;
	return in;
}
