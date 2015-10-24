#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	
	int numberOfTasks, timeLimit;
	cin >> numberOfTasks >> timeLimit;
	int sum = 0;
	int counter = 0;
	
	for (int i = 0; i < numberOfTasks; ++i) {
		
		int taskTime = 0;
		cin >> taskTime;
		
		if (sum + taskTime > timeLimit) {
			cout << counter << endl;
			exit(0);
		} else {
			sum += taskTime;
			counter++;
		}
		
		if (sum == timeLimit) {
			cout << counter << endl;
			exit(0);
		}
		
	}
	
	cout << counter << endl;
}
