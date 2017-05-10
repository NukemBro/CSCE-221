//============================================================================
// Copyright   : Grant Hruzek ©
//============================================================================

#include <regex>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "hash.h"

using namespace std;

int main() {
	ifstream input_file("input.csv");
	ifstream roster_file("roster.csv");
	ofstream output_file("output.csv");
	
	string s;
	regex getInput{ R"((.*)(?:,)(.*)(?:,)(.*)(?:,)(.*))" };
	regex getRoster{ R"((.*)(?:,)(.*)(?:,)(.*)(?:,))" };
	smatch input;
	smatch roster;

	HashTable table;
	
	cout << "UIN list input: " << endl;
	while(!input_file.eof()) {
		getline(input_file, s);
		if (regex_search(s, input, getInput)) {
			cout << input[1] << " " << input[2] << " " << input[3] << " " << input[4] << endl;
			int UIN = stoi(input[3]);
			int grade = stoi(input[4]);
			table.insert(UIN, grade);
		}
	}
	cout << endl;
	
	cout << "UIN list roster: " << endl;
	int count = 0;
	while(!roster_file.eof()) {
		getline(roster_file, s);
		if (regex_search(s, roster, getRoster)) {
			int UIN = stoi(roster[3]);
			cout << roster[1] << " " << roster[2] << " " << roster[3] << endl;
			if (table.search(UIN) == -1) {
				output_file << roster[1] << "," << roster[2] << "," << roster[3] << endl;
			}
			else {
				output_file << roster[1] << "," << roster[2] << "," << roster[3] << "," << table.search(UIN) << endl;
			}
		}
	}
	cout << endl;

	table.printStats();
	output_file.close();
	return 0;
}