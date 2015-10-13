// John Rosewicz
// quine.cpp
// http://mcicpc.cs.atu.edu/archives/2012/mcpc2012/quine/quine.html

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

void checkIfQuine(string line) {
	if (line[0] == '"') {
		string phrase = "\"";
		
		bool foundCloseQuotes = false;
		for (int i = 1; i < line.length(); ++i) {
			if (line[i] == '"') {
				phrase += '"';
				foundCloseQuotes = true;
				break;
			} else {
				phrase += line[i];
			}
		}
		
		if (foundCloseQuotes) {
			if (line[phrase.length()] == ' ') {
				string secondPart = line.substr(phrase.length() + 1, line.length());
				if ('"' + secondPart + '"' == phrase) {
					cout << "Quine(" << secondPart << ")" << endl;
					return;
				}
			}
		}
	} 
	
	cout << "not a quine" << endl;
}

int main() {
	ifstream file("quine.in");
	string line;
	
	while (getline(file, line) && line != "END\r") {
		line.erase(remove(line.begin(), line.end(), '\n'), line.end());
		line.erase(remove(line.begin(), line.end(), '\r'), line.end());
		
		if (line == "END") {
			return 0;
		} 
		
		checkIfQuine(line);
	}
}
