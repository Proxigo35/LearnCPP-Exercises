#include <iostream>

int main() {
	std::cout << "Enter a single character: ";
	char c{};
	std::cin >> c;
	int ascii{c};
	std::cout << "You entered '" << c << "', which has ASCII code " << ascii << ".\n";
	return 0;
}
