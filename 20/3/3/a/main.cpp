#include <iostream>

void printBinary(int num) {
	if (num <= 1) std::cout << '1';
	else {
		printBinary(num / 2);
		std::cout << num % 2;
	}
}

int main() {
	printBinary(148);
	return 0;
}
