//============================================================================
// Copyright   : Grant Hruzek ©
//============================================================================

#include "my_string.h"
#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
	try {
		cout << "Testing my_string class: \n";
		// declare a string v1 using a default constructor
		my_string v1;
		v1.print();
		// declare two strings: v2, v3 and initialize them with C-strings
		my_string v2("first");
		my_string v3("second");
		// append the strings v2 and v3 to v1 and separate them by a whitespace
		v1 += v2;
		v1 += ' ';
		v1 += v3;
		// display the string v1 using the overloaded operator <<
		cout << "v1 = " << v1 << endl;
		// display the size and capacity of the string v1
		cout << "v1 size = " << v1.size() << endl;
		cout << "v1 capacity = " << v1.capacity() << endl;

		// display the string v1 characters separated by space using the overloaded operator []
		cout << "v1 as [] characters:\n";
		for (int i = 0; i < v1.size(); i++) {
			cout << v1[i] << ' ';
		}
		// display the string v1 characters separated by space using the overloaded operator at()
		cout << "v1 as at() characters:\n";
		for (int i = 0; i < v1.size(); i++) {
			cout << v1.at(i) << ' ';
		}
		cout << endl << endl;

		// declare and create a string v4 by allocating 4 bytes
		// and then initialize it by appending one single character at a time
		{
			my_string v4(4);
			v4 += 'a';
			v4 += 'b';
			v4 += 'c';
			v4 += 'd';
			// display the size and capacity of the string v4
			cout << "v4 = " << v4 << endl;
			cout << "v4 size = " << v4.size() << endl;
			cout << "v4 capacity = " << v4.capacity() << endl;

			// check if the string v4 is empty
			const char* empty = v4.empty() ? "true" : "false";
			cout << "is v4 empty: " << empty << endl;
			cout << endl;
		}

		// declare a string v5 and initialize it with v1 using the copy constructor
		my_string v5(v1);
		// display the string v5
		cout << "v5 = " << v5 << endl;
		// create an auxiliary string v5a and insert it in v5 in places at positions 5 and 14
		my_string v5a("ly");
		cout << "v5.insert(5, \"ly\") and v5.insert(14, \"ly\"): \n";
		v5.insert(5, v5a);
		v5.insert(14, v5a);
		// display v5
		cout << "v5 = " << v5 << endl;
		cout << endl;

		// declare and create an empty string v6 and initialize it with an input stream
		// a whitespace terminates the input stream
		my_string v6;
		cout << "Enter a string:\n";
		cin >> v6;
		// display v6
		cout << "v6 = " << v6 << endl;

		// create v7 and initialize it to v6
		my_string v7(v6);
		// append v2
		v7 += v2;
		// insert a whitespace
		v7.insert(v6.size(), my_string(" "));
		cout << "v6 + \" \" + v2 = " << v7 << endl;

		// create v8 and initialize it with v6
		my_string v8(v6);
		// append the last character of v6
		v8 += v6[v6.size() - 1];
		// display v8
		cout << "v6 + last char of v6 = " << v8 << endl;
		cout << endl;
	}
	// catching an exception
	catch (const out_of_range& e) {
		cerr << "Out of range: " << e.what() << endl;
	}
	catch (...) {
		cerr << "Uncaught error: " << endl;
	}
	
	/* ------- ALTERNATE TESTING CASES ------------ */

	// my_string(-1); // should trigger an out_of_range exception
	char c = '!';
	my_string v1;
	cout << "Constructing an empty string:" << endl;
	v1.print();

	my_string s1(0); // n-byte allocation constructor
	cout << endl;

	my_string s2("Whata"); // c-string constuctor
	cout << "Constructing a string that reads \"Whata\": " << endl;
	s2.print();
	// cout << s2.at(5) << endl; // should trigger an out_of_range exception
	cout << endl;

	my_string s3("Burger"); // c-string constructor
	cout << "Constructing a string that reads \"Burger\": " << endl;
	s3.print();
	cout << endl;

	s2 += s3; // += operator for appending c-string
	cout << "Appending \"Whata\" and \"Burger\": " << endl;
	s2.print();

	my_string s4(s3); // copy constructor
	cout << "Using copy constructor, should print \"Burger\": " << endl;
	s4.print();
	s4 = s2; // copy assignment
	cout << "Using copy assignment, should print \"WhataBurger\": " << endl;
	s4.print();
	s4 += c; // += operator for appending char
	cout << "Using char add operator, should print \"WhataBurger!\": " << endl;
	s4.print(); // Should print "WhataBurger!"
	
	cout << "Appending \"WhataBurger!\" to an empty string, should print \"WhataBurger!\": " << endl;
	v1 += s4;
	v1.print();

	my_string s5("WhataBurger");
	my_string s6("Whata");
	my_string s7("!");
	// s5.insert(-1, s6); // will throw an out_of_range exception
	s5.insert(0, s6); // should produce "WhataWhataBurger" 
	s6.insert(5, s7); // should produce "Whata!"
	// s5.insert(15, s6); // will throw an out_of_range exception
	cout << "Inserting \"Whata\" into \"WhataBurger\" at the beginning: " << endl;
	s5.print();
	cout << "Inserting single character \"!\" into string \"Whata\" at the end: " << endl;
	s6.print();
	cout << endl;
	// system("pause"); // for VS
}
