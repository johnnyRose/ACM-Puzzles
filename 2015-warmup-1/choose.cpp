#include <iostream>

// calculates the binomial coefficient choose(n, k). 
// choose (n, k)    ==    n! / (k!(n - k)!)

// any value of n > 25 will overflow the long long data type
long long factorial(short n) {
	long long total = 1;
	for (short i = n; i > 1; --i) {
		total *= i;
	}
	
	return total;
}

// any value of n > 20 will overflow the long long data type
long long choose(short n, short k) {
	return factorial(n) / (factorial(k) * factorial(n - k));
}

// to run:      a n k     (n >= k >= 0)
int main(int argc, char* argv[]) {
	std::cout << choose(std::atoi(argv[1]), std::atoi(argv[2])) << std::endl;
}
