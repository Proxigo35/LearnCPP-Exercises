#include <iostream>

int main() {
	int number1;
	int number2;

	std::cout << "Enter an integer: ";
	std::cin >> number1;
	std::cout << "Enter another integer: ";
	std::cin >> number2;
	std::cout << number1 << " + " << number2 << " is " << number1 + number2 << ".\n";
	std::cout << number1 << " - " << number2 << " is " << number1 - number2 << ".\n";
}
