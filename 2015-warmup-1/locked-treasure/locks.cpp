#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

vector<vector<int>> memory;

int pascal(int n, int i) {
	if (i == 1 || n < 2 || i == n + 1) {
		return 1;
	}
	
	int memVal = memory.at(n).at(i);
	if (memVal != 0) {
		return memVal;
	}
	
	int value = pascal(n - 1, i - 1) + pascal(n - 1, i);
	memory.at(n).at(i) = value;
	return value;
}

int main() {
	int tests;
	
	cin >> tests;
	vector<int> firsts;
	vector<int> seconds;
	
	for (int i = 0; i < 31; ++i) {
		vector<int> vec;
		memory.push_back(vec);
		for (int j = 0; j < 31; ++j) {
			memory.at(i).push_back(0);
		}
	}
	
	for (int i = 0; i < tests; ++i) {
		int first, second;
		cin >> first >> second;
		
		firsts.push_back(first);
		seconds.push_back(second);
	}
	
	for (int i = 0; i < tests; ++i) {
		cout << pascal(firsts.at(i), seconds.at(i)) << endl;
	}
	
	exit(0);
}
