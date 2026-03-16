#include <iostream>

int main() {
	std::cout << "Enter a double value: ";
	double num1{};
	std::cin >> num1;

	std::cout << "Enter another double value: ";
	double num2{};
	std::cin >> num2;

	std::cout << "Enter an +, -, *, or /: ";
	char c{};
	std::cin >> c;

	if (c == '+') {
		std::cout << num1 << ' ' << c << ' ' << num2 << " is " << num1 + num2 << '\n';
	} else if (c == '-') {
		std::cout << num1 << ' ' << c << ' ' << num2 << " is " << num1 - num2 << '\n';
	} else if (c == '*') {
		std::cout << num1 << ' ' << c << ' ' << num2 << " is " << num1 * num2 << '\n';
	} else if (c == '/') {
		std::cout << num1 << ' ' << c << ' ' << num2 << " is " << num1 / num2 << '\n';
	}
	return 0;
}
