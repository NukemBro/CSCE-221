//============================================================================
// Copyright   : Grant Hruzek ©
//============================================================================
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <stdexcept>

using namespace std;

int main() {
	srand(time(0));
	int power, size;
	string order, infile = "input.txt";
	
	cout << "Enter a power of 10 to be output to file" << endl;
	cin >> power;
	
	size = pow(10.0, power);
	vector<int> v(size);
	
	cout << "Is the vector increasing, decreasing, or random?" << endl;
	cin >> order;
	
	if (order == "random") {
		for (int i = 0; i < v.size(); ++i) {
				v[i] = (rand() % 100000);
		}
	}
	else if (order == "increasing") {
		for (int i = 0; i < v.size(); ++i) {
				v[i] = i;
		}
	} 
	else if (order == "decreasing") {
		for (int i = 0; size >= 0; ++i) {
			v[i] = size;
			--size;
		}		
	} 
	else throw runtime_error("Invalid order");
	
	ofstream os;
	os.open(infile.c_str());
	
	os << v.size() << endl;
	for (int i = 0; i < v.size(); ++i) {
		os << v[i] << endl;
	}
	os.close();
}