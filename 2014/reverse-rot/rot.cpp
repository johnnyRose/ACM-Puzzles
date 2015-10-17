// John Rosewicz
// rot.cpp
// http://mcicpc.cs.atu.edu/archives/2014/mcpc2014/rot/rot.html

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_.";

int getRotation(string line) {
	string temp = "";
	int i = 0;
	
	while (line[i] != ' ') {
		temp += line[i];
		++i;
	}
	
	return atoi(temp.c_str());
}

int indexOf(char target) {
	for (int i = 0; i < chars.length(); ++i) {
		if (chars[i] == target) {
			return i;
		}
	}
	
	return -1;
}

string reverseString(string original) {
	string reversed = "";
	for (int i = original.length() - 1; i >= 0; --i) {
		reversed += original[i];
	}
	
	return reversed;
}

string getMessage(string line) {
	string message = "";
	int i = 0;
	
	while (line[i] != ' ') {
		++i;
	}
	
	++i;
	
	while (i < line.length()) {
		if (indexOf(line[i]) >= 0) {
			message += line[i];
		}
		
		++i;
	}
	
	return reverseString(message);
}

int main() {
	ifstream file;
	string line;
	
	file.open("rot.in");
	
	while (getline(file, line)) {
		if (line[0] == '0') {
			break;
		}
		
		int rotation = getRotation(line);
		string original = getMessage(line);
		string translated = "";
		for (int i = 0; i < original.length(); ++i) {
			translated += chars[(indexOf(original[i]) + rotation) % chars.size()];
		}
		
		cout << translated << "\n";
	}
}
