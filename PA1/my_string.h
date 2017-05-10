//============================================================================
// Copyright   : Grant Hruzek ©
//============================================================================

#ifndef MY_STRING
#define MY_STRING

#include <iostream>
#include <stdexcept>

class my_string {
private:
	char *ptr;
	int sz = 0;
	int cap = 0;

	// helper function
	void resize();

public:

	int size() const;
	int capacity() const;
	bool empty() const;
	char operator[](int i) const;
	char at(int i) const;
	my_string& insert(int i, const my_string& s);
	my_string& operator+=(const my_string& q);
	my_string& operator+=(const char c);
	my_string();
	my_string(int n);
	my_string(const char* cstring);
	my_string(const my_string& other);
	~my_string();
	my_string& operator=(const my_string& source);

	// extra function to quick print for debugging
	void print() const;
};

// output operator
std::ostream& operator<<(std::ostream& os, const my_string& s);

// input operator
std::istream& operator>>(std::istream& os, my_string& s);

#endif 


