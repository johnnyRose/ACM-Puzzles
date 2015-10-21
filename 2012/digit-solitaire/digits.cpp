// John Rosewicz
// digits.cpp
// http://www.icpc-midcentral.us/archives/2012/mcpc2012/digits/digits.html

#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

string to_string(int i) {
	stringstream ss;
	ss << i;
	return ss.str();
}

int main() {
	ifstream file("digits.in");
	string input;
	
	while (getline(file, input)) {
		input.erase(remove(input.begin(), input.end(), '\n'), input.end());
		input.erase(remove(input.begin(), input.end(), '\r'), input.end());
		
		if (input == "0") {
			return 0;
		}
		
		while (input.length() > 1) {
			cout << input << " ";
			int product = 1;
			
			for (int i = 0; i < input.length(); ++i) {
				product *= input[i] - '0'; // converts a char to an int
			}
			
			input = to_string(product);
		}
		
		cout << input << endl;
	}
}
