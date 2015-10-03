#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

bool moveX = false;
bool moveY = false;
bool increasing = false;
int currentX = 0;
int currentY = 0;

int getWidth(string input) {
	int i = 0;
	int width;
	string temp = "";
	
	while (input[i] != ' ') {
		temp += input[i];
		++i;
	}
	
	return atoi(temp.c_str());
}

int getHeight(string input) {
	int i = 0;
	int width;
	string temp = "";
	while (input[i] != ' ') {
		++i;
	}
	
	++i;
	
	while (i < input.length()) {
		temp += input[i];
		++i;
	}
	
	return atoi(temp.c_str());
}

vector<vector<string>> getHouses() {
	string line;
	vector<vector<string>> houses;
	ifstream file;
	file.open("fun.in");
	
	while (getline(file, line)) {
		if (line[0] == '0') {
			break;
		}
		
		int width;
		int height;
		
		if (isdigit(line[0])) {
			width = getWidth(line);
			height = getHeight(line);
		} else {
			vector<string> house;
			house.push_back(line);
			for (int i = 1; i < height; ++i) {
				getline(file, line);
				house.push_back(line.substr(0, width));
			}
			
			houses.push_back(house);
		}
	}
	
	return houses;
}

void setInitials(vector<string> house) {
	for (int j = 0; j < house.size(); ++j) {
		for (int k = 0; k < house.at(j).length(); ++k) {
			
			if (house.at(j)[k] == '*') {
				currentX = k;
				currentY = j;
				
				if (k == 0) {
					moveX = true;
					moveY = false;
					increasing = true;
				} else if (k == house.at(j).size() - 1) {
					moveX = true;
					moveY = false;
					increasing = false;
				} else if (j == 0) {
					moveX = false;
					moveY = true;
					increasing = true;
				} else {
					moveX = false;
					moveY = true;
					increasing = false;
				}
			}
		}
	}
}

void handleCollision(vector<string> house) {
	moveX = !moveX;
	moveY = !moveY;
	increasing = increasing ? house.at(currentY)[currentX] == '\\' : house.at(currentY)[currentX] == '/';
}

void printHouses(vector<vector<string>> houses) {
	for (int i = 0; i < houses.size(); ++i) {
		cout << "HOUSE " << i + 1 << "\n";
		for (int j = 0; j < houses.at(i).size(); ++j) {
			cout << houses.at(i).at(j) << "\n";
		}
	}
}

int main() {
	vector<vector<string>> houses = getHouses();
	
	for (int i = 0; i < houses.size(); ++i) {
		setInitials(houses.at(i));
		
		while (houses.at(i).at(currentY)[currentX] != 'x') {
			if (houses.at(i).at(currentY)[currentX] == '/' || houses.at(i).at(currentY)[currentX] == '\\') {
				handleCollision(houses.at(i));
			}
			
			int plusOrMinus = increasing ? 1 : -1;
			moveX ? currentX += plusOrMinus : currentY += plusOrMinus;
		}
		
		houses.at(i).at(currentY)[currentX] = '&';
	}
	
	printHouses(houses);
}
