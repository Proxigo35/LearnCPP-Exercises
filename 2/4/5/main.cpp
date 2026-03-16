#include <iostream>

int doubleNumber(int number) {
	return number * 2;
}

int main() {

	int number {};
	std::cin >> number;
	std::cout << doubleNumber(number);

	return 0;
}
