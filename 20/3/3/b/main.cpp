#include <iostream>

void printBinary(unsigned int num) {
	if (num > 1) printBinary(num / 2);
	std::cout << num % 2;
}

int main() {
	int num {};
	std::cout << "Enter an integer: ";
	std::cin >> num;
	printBinary(static_cast<unsigned int>(num));
	return 0;
}
