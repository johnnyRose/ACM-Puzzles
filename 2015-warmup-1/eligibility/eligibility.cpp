#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

int main() {
	int numberOfCases;
	
	cin >> numberOfCases;
	
	vector<string> names;
	vector<string> dateBegans;
	vector<string> birthdays;
	vector<int> coursesTakens;
	
	for (int i = 0; i < numberOfCases; ++i) {
		string name;
		string dateBegan;
		string birthday;
		int coursesTaken;
		
		cin >> name >> dateBegan >> birthday >> coursesTaken;
		names.push_back(name);
		dateBegans.push_back(dateBegan);
		birthdays.push_back(birthday);
		coursesTakens.push_back(coursesTaken);
	}
	
	for (int i = 0; i < numberOfCases; ++i) {
		string yearBegan;
		string birthYear;
		
		for (int j = 0; j < 4; ++j) {
			yearBegan += dateBegans.at(i)[j];
			birthYear += birthdays.at(i)[j];
		}
		
		if (atoi(yearBegan.c_str()) >= 2010) {
			cout << names.at(i) << " eligible" << endl;
			continue;
		} 
		
		if (atoi(birthYear.c_str()) >= 1991) {
			cout << names.at(i) << " eligible" << endl;
			continue;
		} 
		
		if (coursesTakens[i] >= 41) {
			cout << names.at(i) << " ineligible" << endl;
			continue;
		} 
		
		cout << names.at(i) << " coach petitions" << endl;
	}
	
	exit(0);
}
