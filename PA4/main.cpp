//============================================================================
// Copyright   : Grant Hruzek ©
//============================================================================

#include <iostream>
#include <string>
#include <regex>
#include <fstream>

using namespace std;

int main() {
	// ------------ Problem 1 --------------//
	regex patternA{ R"(\d\d)" };
	regex patternB{ R"(thanks)" };
	string to_searchA = "I would like the number 98"
		" to be found and printed, thanks.";
	smatch matchesA;
	regex_search(to_searchA, matchesA, patternA);
	cout << "Problem 1: " << endl;
	cout << matchesA[0] << endl;
	regex_search(to_searchA, matchesA, patternB);
	cout << matchesA[0] << endl;
	cout << endl;

	// ------------ Problem 2 --------------//
	regex patternC{ R"(<head>(.*)<title>.*<\/title>(.*)<\/head>)" };
	string to_searchB = "<html><head>Wow such a header <title>This is a title</title>"
		"So top</head>Much body</html>";
	smatch matchesB;
	regex_search(to_searchB, matchesB, patternC);
	cout << "Problem 2: " << endl;
	cout << matchesB[1] << endl;
	cout << matchesB[2] << endl;
	cout << endl;

	// ------------ Problem 3 --------------//
	ifstream file("stroustrup.txt");
	string s;
	regex patternD{ R"((?:<a href=")(.+)(\.ppt))" };
	smatch matches;
	cout << "Problem 3: " << endl;
	while (!file.eof()) {
		getline(file, s);
		if (regex_search(s, matches, patternD)) {
			cout << matches[1];
			cout << matches[2] << endl;
		}
	}
	return 0;
}
